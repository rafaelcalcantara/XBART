#ifndef GUARD_node_data_h
#define GUARD_node_data_h

#include <ctime>
#include "common.h"
#include "utility.h"
#include <chrono>
#include "fit_info.h"

struct NodeData
{
    // strcuct of data at each specific node, including Xorder for continuous variable and X_counts for categorical variable
public:
    // continuous variables
    xinfo_sizet Xorder_std;
    size_t N_Xorder;

    // categorical variables
    std::vector<size_t> X_counts;
    std::vector<size_t> X_num_unique;

    NodeData(size_t N_Xorder, size_t p, size_t N_X_counts, size_t p_categorical)
    {
        // initialize everything, prespecify size of X_counts and X_num_unique
        ini_xinfo_sizet(Xorder_std, N_Xorder, p);

        X_counts = std::vector<size_t>(N_X_counts);

        X_num_unique = std::vector<size_t>(p_categorical);

        return;
    }

    NodeData(size_t N_Xorder, size_t p, const double *Xpointer, std::unique_ptr<FitInfo> &fit_info)
    {
        // initialize Xorder_std with prespecify size
        // count X_counts and X_num_unique from data
        // Use for initialize NodeData for ROOT node
        ini_xinfo_sizet(Xorder_std, N_Xorder, p);

        X_num_unique = std::vector<size_t>(fit_info->p_categorical);

        this->ini_categorical_var(Xpointer, fit_info);

        return;
    }

    void ini_categorical_var(const double *Xpointer, std::unique_ptr<FitInfo> &fit_info)
    {
        size_t total_points = 0;
        size_t N = Xorder_std[0].size();
        size_t p = Xorder_std.size();
        double current_value = 0.0;
        size_t count_unique = 0;
        size_t N_unique;
        fit_info->variable_ind[0] = 0;

        for (size_t i = fit_info->p_continuous; i < fit_info->p; i++)
        {
            // only loop over categorical variables
            // suppose p = (p_continuous, p_categorical)
            // index starts from p_continuous
            this->X_counts.push_back(1);
            current_value = *(Xpointer + i * N + this->Xorder_std[i][0]);
            fit_info->X_values.push_back(current_value);
            count_unique = 1;

            for (size_t j = 1; j < N; j++)
            {
                if (*(Xpointer + i * N + this->Xorder_std[i][j]) == current_value)
                {
                    this->X_counts[total_points]++;
                }
                else
                {
                    current_value = *(Xpointer + i * N + this->Xorder_std[i][j]);
                    fit_info->X_values.push_back(current_value);
                    this->X_counts.push_back(1);
                    count_unique++;
                    total_points++;
                }
            }
            fit_info->variable_ind[i + 1 - fit_info->p_continuous] = count_unique + fit_info->variable_ind[i - fit_info->p_continuous];
            this->X_num_unique[i - fit_info->p_continuous] = count_unique;
            total_points++;
        }
        return;
    }
};

#endif
