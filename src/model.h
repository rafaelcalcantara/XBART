
#ifndef model_h
#define model_h

#include "common.h"
#include "utility.h"
#include <memory>
#include "state.h"
#include "X_struct.h"
#include "cdf.h"

using namespace std;

class tree;

class Model
{

public:
    size_t dim_theta;

    size_t dim_suffstat;

    size_t dim_residual;

    size_t class_operating;

    /////////////////////////////////////
    //
    //  suff_stat_model and suff_stat_total
    //  are useless for NormalModel now
    //  They are still here because CLT class depends on them
    //  Delelte them later
    //
    /////////////////////////////////////
    std::vector<double> suff_stat_model;

    std::vector<double> suff_stat_total;

    double no_split_penality;

    // tree prior
    double alpha;

    double beta;

    Model(size_t dim_theta, size_t dim_suff)
    {
        this->dim_theta = dim_theta;
        this->dim_suffstat = dim_suff;
    };

    // Abstract functions
    virtual void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats) { return; };

    virtual void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf) { return; };

    virtual void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct) { return; };

    virtual void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat) { return; };

    virtual void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind) { return; };

    virtual void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side) { return; };

    virtual void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const { return; };

    virtual double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const { return 0.0; };

    // virtual double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const { return 0.0; };

    virtual void ini_residual_std(std::unique_ptr<State> &state) { return; };

    // virtual double predictFromTheta(const std::vector<double> &theta_vector) const { return 0.0; };

    virtual void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees) { return; };

    virtual Model *clone() { return nullptr; };

    // Getters and Setters
    // num classes
    size_t getNumClasses() const { return dim_theta; };

    void setNumClasses(size_t n_class) { dim_theta = n_class; };

    // dim suff stat
    size_t getDimSuffstat() const { return dim_suffstat; };

    void setDimSuffStat(size_t dim_suff) { dim_suffstat = dim_suff; };

    //penality
    double getNoSplitPenality()
    {
        return no_split_penality;
        ;
    };
    void setNoSplitPenality(double pen) { this->no_split_penality = pen; };

    virtual size_t get_class_operating() { return class_operating; };

    virtual void set_class_operating(size_t i)
    {
        class_operating = i;
        return;
    };
};

class NormalModel : public Model
{
public:
    size_t dim_suffstat = 3;

    // model prior
    // prior on sigma
    double kap;
    double s;
    double tau_kap;
    double tau_s;
    // prior on leaf parameter
    double tau; // might be updated if sampling tau
    double tau_mean; // copy of the original value
    bool sampling_tau;

    NormalModel(double kap, double s, double tau, double alpha, double beta, bool sampling_tau, double tau_kap, double tau_s) : Model(1, 3)
    {
        this->kap = kap;
        this->s = s;
        this->tau_kap = tau_kap;
        this->tau_s = tau_s;
        this->tau = tau;
        this->tau_mean = tau;
        this->alpha = alpha;
        this->beta = beta;
        this->dim_residual = 1;
        this->class_operating = 0;
        this->sampling_tau = sampling_tau;
    }

    NormalModel(double kap, double s, double tau, double alpha, double beta) : Model(1, 3)
    {
        this->kap = kap;
        this->s = s;
        this->tau = tau;
        this->tau_mean = tau;
        this->alpha = alpha;
        this->beta = beta;
        this->dim_residual = 1;
        this->class_operating = 0;
        this->sampling_tau = true;
    }

    NormalModel() : Model(1, 3) {}

    Model *clone() { return new NormalModel(*this); }

    void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats);

    void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf);

    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

    void update_tau(std::unique_ptr<State> &state, size_t tree_ind, size_t sweeps, vector<vector<tree>> & trees);

    void update_tau_per_forest(std::unique_ptr<State> &state, size_t sweeps, vector<vector<tree>> & trees);

    void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat);

    void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind);

    void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side);

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const;

    double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const;

    // double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const;

    void ini_residual_std(std::unique_ptr<State> &state);

    void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees);
};

class ProbitClass : public NormalModel
{
public:
    std::vector<double> z;
    std::vector<double> z_prev;

    double a = 0;
    double b = 1;


    ProbitClass(double kap, double s, double tau, double alpha, double beta, std::vector<double> &y_std) : NormalModel(kap, s, tau, alpha, beta)
    {
        this->z = std::vector<double>(y_std.size(), 0);
        this->z_prev = std::vector<double>(y_std.size(), 0);
        for(size_t i = 0; i < y_std.size(); i ++ ){
            this->z[i] = y_std[i];
        }
        return;
    }

    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const;
};

class CLTClass : public Model
{
private:
    //std::vector<double> suff_stat_total;

public:
    size_t dim_suffstat = 4;

    // model prior
    // prior on sigma
    double kap;
    double s;
    // prior on leaf parameter
    double tau;

    CLTClass(double kap, double s, double tau, double alpha, double beta) : Model(1, 4)
    {
        suff_stat_total.resize(dim_suffstat);
        this->kap = kap;
        this->s = s;
        this->tau = tau;
        this->alpha = alpha;
        this->beta = beta;
    }

    CLTClass() : Model(1, 4)
    {
        suff_stat_total.resize(dim_suffstat);
    }
    std::vector<double> total_fit; // Keep public to save copies
    std::vector<double> suff_stat_total;

    void suff_stat_fill(std::vector<double> &y_std, std::vector<size_t> &xorder)
    {
        // fill the suff_stat_model with a value
        // in function call, a = 0.0 to reset sufficient statistics vector
        // size_t n = xorder.size();
        size_t x_order_0 = xorder[0];
        double current_fit_val = total_fit[x_order_0];

        double psi = max(current_fit_val * (1 - current_fit_val), 0.15);
        Model::suff_stat_model[0] = y_std[x_order_0] / psi;
        Model::suff_stat_model[1] = 1 / psi;
        Model::suff_stat_model[2] = std::log(1 / psi);
        // Model::suff_stat_model[3] = pow(y_std[x_order_0], 2) / psi;
        return;
    }
    void incrementSuffStat() const { return; };

    using Model::samplePars;

    void samplePars(double y_mean, size_t N_Xorder, double sigma, std::mt19937 &generator, std::vector<double> &theta_vector, std::vector<double> &y_std, matrix<size_t> &Xorder, double &prob_leaf)
    {
        // Update params
        updateFullSuffStat(y_std, Xorder[0]);

        std::normal_distribution<double> normal_samp(0.0, 1.0);

        // test result should be theta
        theta_vector[0] = suff_stat_total[0] / (1.0 / tau + suff_stat_total[1]) + sqrt(1.0 / (1.0 / tau + suff_stat_total[1])) * normal_samp(generator); //Rcpp::rnorm(1, 0, 1)[0];//* as_scalar(arma::randn(1,1));

        // also update probability of leaf parameters
        prob_leaf = normal_density(theta_vector[0], y_mean * N_Xorder / pow(sigma, 2) / (1.0 / tau + N_Xorder / pow(sigma, 2)), 1.0 / (1.0 / tau + N_Xorder / pow(sigma, 2)), true);

        return;
    }

    using Model::state_sweep;

    void state_sweep(size_t tree_ind, size_t M, std::vector<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const
    {
        size_t next_index = tree_ind + 1;
        if (next_index == M)
        {
            next_index = 0;
        }
        // residual_std = residual_std - predictions_std[tree_ind] + predictions_std[next_index];
        return;
    }

    void calcSuffStat_categorical(std::vector<double> &y, matrix<size_t> &Xorder, size_t &start, size_t &end, const size_t &var)
    {
        // calculate sufficient statistics for categorical variables

        // compute sum of y[Xorder[start:end, var]]
        size_t loop_count = 0;
        std::vector<size_t> &xorder_var = Xorder[var];
        // size_t n = xorder_var.size();
        double current_fit_val;
        double psi;
        double obs;
        size_t x_order_i;
        for (size_t i = start; i <= end; i++)
        {
            x_order_i = xorder_var[i];
            current_fit_val = total_fit[x_order_i];
            obs = y[x_order_i];

            psi = std::max(current_fit_val * (1 - current_fit_val), 0.15);
            Model::suff_stat_model[0] += obs / psi;
            Model::suff_stat_model[1] += 1 / psi;
            Model::suff_stat_model[2] += std::log(1 / psi);
            //Model::suff_stat_model[3] += pow(obs, 2) / psi;
            loop_count++;
        }
        return;
    }

    void calcSuffStat_continuous(std::vector<size_t> &xorder, std::vector<double> &y_std, std::vector<size_t> &candidate_index, size_t index, bool adaptive_cutpoint)
    {
        // calculate sufficient statistics for continuous variables
        // size_t n = xorder.size();
        double current_fit_val;
        double psi;
        double obs;
        size_t x_order_q;

        if (adaptive_cutpoint)
        {
            // initialize
            Model::suff_stat_model[0] = y_std[xorder[0]];

            // if use adaptive number of cutpoints, calculated based on vector candidate_index
            for (size_t q = candidate_index[index] + 1; q <= candidate_index[index + 1]; q++)
            {
                x_order_q = xorder[q];
                current_fit_val = total_fit[x_order_q];
                obs = y_std[x_order_q];

                //if (current_fit_val > 1.0 || current_fit_val < -1.0){obs = 0.0;}

                psi = std::max(current_fit_val * (1 - current_fit_val), 0.15);
                //psi = 0.15;
                Model::suff_stat_model[0] += obs / psi;
                Model::suff_stat_model[1] += 1 / psi;
                Model::suff_stat_model[2] += std::log(1 / psi);
                //Model::suff_stat_model[3] += pow(obs, 2) / psi;
            }
        }
        else
        {
            // use all data points as candidates
            current_fit_val = total_fit[xorder[index]];
            obs = y_std[xorder[index]];

            psi = std::max(current_fit_val * (1 - current_fit_val), 0.15);
            Model::suff_stat_model[0] += obs / psi;
            Model::suff_stat_model[1] += 1 / psi;
            Model::suff_stat_model[2] += std::log(1 / psi);
            //Model::suff_stat_model[3] += pow(obs, 2) / psi;
        }

        return;
    }

    void updateFullSuffStat(std::vector<double> &y_std, std::vector<size_t> &x_info)
    {
        size_t n = x_info.size();
        double current_fit_val;
        double psi;
        double obs;
        size_t x_order_i;
        for (size_t i = 0; i < n; i++)
        {
            x_order_i = x_info[i];
            current_fit_val = total_fit[x_order_i];
            obs = y_std[x_order_i];

            psi = std::max(current_fit_val * (1 - current_fit_val), 0.15);
            suff_stat_total[0] += obs / psi;
            suff_stat_total[1] += 1 / psi;
            suff_stat_total[2] += std::log(1 / psi);
            //suff_stat_total[3] += pow(obs, 2) / psi;
        }
        return;
    }

    using Model::likelihood;

    double likelihood(std::vector<double> &node_suff_stat, size_t N_left, bool left_side, std::unique_ptr<State> &state) const
    {
        // likelihood equation,
        // note the difference of left_side == true / false

        if (left_side)
        {
            return 0.5 * Model::suff_stat_model[2] + 0.5 * std::log((1 / tau) / ((1 / tau) + Model::suff_stat_model[1])) + 0.5 * tau / (1 + tau * Model::suff_stat_model[1]) * pow(Model::suff_stat_model[0], 2); //- 0.5 * Model::suff_stat_model[3];
            ;
        }
        else
        {
            return 0.5 * (suff_stat_total[2] - Model::suff_stat_model[2]) + 0.5 * std::log((1 / tau) / ((1 / tau) + (suff_stat_total[1] - Model::suff_stat_model[1]))) + 0.5 * tau / (1 + tau * (suff_stat_total[1] - Model::suff_stat_model[1])) * pow(suff_stat_total[0] - Model::suff_stat_model[0], 2); // - 0.5 * (suff_stat_total[3] - Model::suff_stat_model[3]);
        }
    }

    double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const
    {
        // the likelihood of no-split option is a bit different from others
        // because the sufficient statistics is y_sum here
        // write a separate function, more flexibility

        return 0.5 * (suff_stat_total[2]) + 0.5 * std::log((1 / tau) / ((1 / tau) + (suff_stat_total[1]))) + 0.5 * tau / (1 + tau * (suff_stat_total[1])) * pow(suff_stat_total[0], 2) - 0.5 * suff_stat_total[3];
        ;
    }

    double predictFromTheta(const std::vector<double> &theta_vector) const
    {
        return theta_vector[0];
    }

    Model *clone() { return new CLTClass(*this); }

    using Model::updateNodeSuffStat;

    virtual void updateNodeSuffStat(std::vector<double> &suff_stat, std::vector<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind)
    {
        suff_stat[0] += residual_std[Xorder_std[split_var][row_ind]];
        suff_stat[1] += pow(residual_std[Xorder_std[split_var][row_ind]], 2);
        return;
    }

    virtual void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side)
    {

        // in function split_xorder_std_categorical, for efficiency, the function only calculates suff stat of ONE child
        // this function calculate the other side based on parent and the other child

        if (compute_left_side)
        {
            rchild_suff_stat[0] = (parent_suff_stat[0] * N_parent - lchild_suff_stat[0]) / N_right;

            rchild_suff_stat[1] = parent_suff_stat[1] - lchild_suff_stat[1];

            lchild_suff_stat[0] = lchild_suff_stat[0] / N_left;

            rchild_suff_stat[2] = parent_suff_stat[2] - lchild_suff_stat[2];
        }
        else
        {
            lchild_suff_stat[0] = (parent_suff_stat[0] * N_parent - rchild_suff_stat[0]) / N_left;

            lchild_suff_stat[1] = parent_suff_stat[1] - rchild_suff_stat[1];

            rchild_suff_stat[0] = rchild_suff_stat[0] / N_right;

            lchild_suff_stat[2] = parent_suff_stat[2] - rchild_suff_stat[2];
        }
        return;
    }
};

//////////////////////////////////////////////////////////////////////////////////////
//
//
//  Multinomial logistic model
//
//
//////////////////////////////////////////////////////////////////////////////////////


class LogitModel : public Model
{
private:

    double LogitLIL(const vector<double> &suffstats) const
    {

        size_t c = dim_residual;

        //suffstats[0] .. suffstats[c-1]is count of y's in cat 0,...,c-1, i.e. r in proposal
        //suffstats[c] .. suffstats[2c-1] is sum of phi_i*(partial fit j)'s ie s in proposal

        double ret = 0;

        for (size_t j = 0; j < c; j++)
        {
            ret += -(tau_a + suffstats[j] ) * log(tau_b + suffstats[c + j]) + lgamma(tau_a + suffstats[j]);// - lgamma(suffstats[j] +1);
        }
        return ret;
    }


public:

    // prior on leaf parameter
    double tau_a, tau_b; //leaf parameter is ~ G(tau_a, tau_b). tau_a = 1/tau + 1/2, tau_b = 1/tau -> f(x)\sim N(0,tau) approx

    // Should these pointers live in model subclass or state subclass?
    std::vector<size_t> *y_size_t; // a y vector indicating response categories in 0,1,2,...,c-1
    std::vector<double> *phi;

    bool update_weight, update_tau; // option to update tau_a
    double weight, logloss; // pseudo replicates of observations
    double hmult, heps; // weight ~ Gamma(n, hmult * entropy + heps);

    LogitModel(int num_classes, double tau_a, double tau_b, double alpha, double beta, std::vector<size_t> *y_size_t, std::vector<double> *phi, double weight, bool update_weight, bool update_tau, double hmult, double heps) : Model(num_classes, 2*num_classes)
    {
        this->y_size_t = y_size_t;
        this->phi = phi;
        this->tau_a = tau_a;
        this->tau_b = tau_b;
        this->alpha = alpha;
        this->beta = beta;
        //what should this be?
        this->dim_residual = num_classes;

        this->update_weight = update_weight;
        this->update_tau = update_tau;
        this->weight = weight;
        this->hmult = hmult;
        this->heps = heps;
        this->logloss = 0;
    }

    LogitModel() : Model(2, 4) {}

    Model *clone() { return new LogitModel(*this); }

    void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats);

    void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf);

    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

    void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat);

    void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind);

    void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side);

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const;

    double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const;

    // double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const;

    void ini_residual_std(std::unique_ptr<State> &state);

    using Model::predict_std;
    void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees, std::vector<double> &output_vec);

    void predict_std_standalone(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees, std::vector<double> &output_vec, std::vector<size_t>& iteration, std::vector<size_t> &output_leaf_index);
};




class LogitModelSeparateTrees : public LogitModel
{
private:
    double LogitLIL(const vector<double> &suffstats) const
    {
        // double suff_stat_r = -suffstats[class_operating]; // sufficient statistics of all other classes
        // double suff_stat_s = -suffstats[class_operating + dim_residual];
        // for (size_t j = 0; j < dim_residual; j++)
        // {
        //     suff_stat_r += suffstats[j];
        //     suff_stat_s += suffstats[dim_residual + j];
        // }
        double ret = -(tau_a + suffstats[class_operating] ) * log(tau_b + suffstats[dim_residual + class_operating]) + lgamma(tau_a + suffstats[class_operating]);
        // ret += -(tau_a + suff_stat_r) * log(tau_b + suff_stat_s) + lgamma(tau_a + suff_stat_r);
        return ret;
    }

    void ini_class_count(std::vector<double> & class_count, double &pseudo_norm, const double num_classes)
    {
        class_count.resize(num_classes);
        std::fill(class_count.begin(), class_count.end(), 0.0);
        for(size_t i = 0; i < (*y_size_t).size(); i++)
        {
            class_count[(*y_size_t)[i]] += 1.0;
        }
        for (size_t i = 0; i < num_classes; i++)
        {
            class_count[i] = class_count[i] / (*y_size_t).size();
        }
        pseudo_norm = 0.0;
        for (size_t k = 0; k < class_count.size(); k++)
        {
            // pseudo_norm += lgamma(class_count[k] + 1);
            pseudo_norm = class_count[k] * (*y_size_t).size() * log(class_count[k]);
        }
        // cout << "class_count = " << class_count << endl;

    }

public:


    LogitModelSeparateTrees(int num_classes, double tau_a, double tau_b, double alpha, double beta, std::vector<size_t> *y_size_t, std::vector<double> *phi, double weight, bool update_weight, bool update_tau) : LogitModel(num_classes, tau_a, tau_b, alpha, beta, y_size_t, phi, weight, update_weight, update_tau, 1, 0.1) {}

    LogitModelSeparateTrees() : LogitModel() {}

    Model *clone() { return new LogitModelSeparateTrees(*this); }

    // void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats);

    void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf);

    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

    // void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat);

    // void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind);

    // void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side);

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const;

    double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const;

    // double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const;

    // void ini_residual_std(std::unique_ptr<State> &state);

    void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<vector<tree>>> &trees, std::vector<double> &output_vec);

    void predict_std_standalone(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<vector<tree>>> &trees, std::vector<double> &output_vec, std::vector<size_t>& iteration, double weight);


};

///

class hskNormalModel : public Model
{
public:
    size_t dim_suffstat = 2;

    // model prior
    // prior on sigma
    double kap;
    double s;
    double tau_kap;
    double tau_s;
    // prior on leaf parameter
    double tau; // might be updated if sampling tau
    double tau_mean; // copy of the original value
    bool sampling_tau;

    hskNormalModel(double kap, double s, double tau, double alpha, double beta, bool sampling_tau, double tau_kap, double tau_s) : Model(1, 2)
    {
        this->kap = kap;
        this->s = s;
        this->tau_kap = tau_kap;
        this->tau_s = tau_s;
        this->tau = tau;
        this->tau_mean = tau;
        this->alpha = alpha;
        this->beta = beta;
        this->dim_residual = 3;
        this->class_operating = 0;
        this->sampling_tau = sampling_tau;
    }

    hskNormalModel(double kap, double s, double tau, double alpha, double beta) : Model(1, 2)
    {
        this->kap = kap;
        this->s = s;
        this->tau = tau;
        this->tau_mean = tau;
        this->alpha = alpha;
        this->beta = beta;
        this->dim_residual = 3;
        this->class_operating = 0;
        this->sampling_tau = true;
    }

    hskNormalModel() : Model(1, 2) {}

    Model *clone() { return new hskNormalModel(*this); }

    // redefined functions
    void ini_residual_std(std::unique_ptr<State> &state);

    void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat);

    void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats);

    void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf);

    //void update_tau(std::unique_ptr<State> &state, size_t tree_ind, size_t sweeps, vector<vector<tree>> & trees);

    //void update_tau_per_forest(std::unique_ptr<State> &state, size_t sweeps, vector<vector<tree>> & trees);

    void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind);

    void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side);

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::unique_ptr<X_struct> &x_struct) const;

    double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const;

    // double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const;

    void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees);

    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

};

///
// TODO: incorporate a_v and b_v appropriately
class logNormalModel : public Model
{
public:
    double kap;
    double s;
    double tau_a;
    double tau_b;
    double tau;

    logNormalModel(double tau_a, double tau_b, double kap, double s, double tau, double alpha, double beta) : Model(1, 2)
    {
        this->kap = kap;
        this->s = s;
        this->tau = tau;
        this->tau_a = tau_a;
        this->tau_b = tau_b;
        this->alpha = alpha;
        this->beta = beta;
        this->dim_residual = 1;

    }

    logNormalModel() : Model(1, 2) {}

    // redefined functions
    void ini_residual_std(std::unique_ptr<State> &state, matrix<double> &mean_residual_std, std::unique_ptr<X_struct> &x_struct);

    void initialize_root_suffstat(std::unique_ptr<State> &state, std::vector<double> &suff_stat);

    void updateNodeSuffStat(std::vector<double> &suff_stat, matrix<double> &residual_std, matrix<size_t> &Xorder_std, size_t &split_var, size_t row_ind);

    void incSuffStat(matrix<double> &residual_std, size_t index_next_obs, std::vector<double> &suffstats);

    void samplePars(std::unique_ptr<State> &state, std::vector<double> &suff_stat, std::vector<double> &theta_vector, double &prob_leaf);

    void calculateOtherSideSuffStat(std::vector<double> &parent_suff_stat, std::vector<double> &lchild_suff_stat, std::vector<double> &rchild_suff_stat, size_t &N_parent, size_t &N_left, size_t &N_right, bool &compute_left_side);

    double likelihood(std::vector<double> &temp_suff_stat, std::vector<double> &suff_stat_all, size_t N_left, bool left_side, bool no_split, std::unique_ptr<State> &state) const;

    void state_sweep(size_t tree_ind, size_t M, matrix<double> &residual_std, std::vector<double> &fit, std::unique_ptr<X_struct> &x_struct) const;

    // double likelihood_no_split(std::vector<double> &suff_stat, std::unique_ptr<State> &state) const;

    void predict_std(const double *Xtestpointer, size_t N_test, size_t p, size_t num_trees, size_t num_sweeps, matrix<double> &yhats_test_xinfo, vector<vector<tree>> &trees);

    //new functions added
    void update_sigmas(matrix<double> &mean_residual_std, std::vector<double> &fit);

    //unused
    void update_state(std::unique_ptr<State> &state, size_t tree_ind, std::unique_ptr<X_struct> &x_struct);

    //void update_tau(std::unique_ptr<State> &state, size_t tree_ind, size_t sweeps, vector<vector<tree>> & trees);

    //void update_tau_per_forest(std::unique_ptr<State> &state, size_t sweeps, vector<vector<tree>> & trees);
};

#endif
