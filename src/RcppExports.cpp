// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// predict_tree
Rcpp::List predict_tree(Rcpp::List trees, arma::mat Xnew);
RcppExport SEXP _SpikySmoothTrees_predict_tree(SEXP treesSEXP, SEXP XnewSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type trees(treesSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xnew(XnewSEXP);
    rcpp_result_gen = Rcpp::wrap(predict_tree(trees, Xnew));
    return rcpp_result_gen;
END_RCPP
}
// singletree
Rcpp::List singletree(arma::vec y, arma::mat X, size_t depth, size_t max_depth, size_t Nmin, double tau, double sigma, double alpha, double beta);
RcppExport SEXP _SpikySmoothTrees_singletree(SEXP ySEXP, SEXP XSEXP, SEXP depthSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP tauSEXP, SEXP sigmaSEXP, SEXP alphaSEXP, SEXP betaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< size_t >::type depth(depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< double >::type sigma(sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    rcpp_result_gen = Rcpp::wrap(singletree(y, X, depth, max_depth, Nmin, tau, sigma, alpha, beta));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_adaptive_std
Rcpp::List train_forest_adaptive_std(Rcpp::NumericVector y, Rcpp::NumericMatrix X, Rcpp::NumericMatrix Xtest, size_t M, size_t L, size_t N_sweeps, arma::mat max_depth, size_t Nmin, size_t Ncutpoints, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu, bool parallel);
RcppExport SEXP _SpikySmoothTrees_train_forest_adaptive_std(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP NcutpointsSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP, SEXP parallelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< size_t >::type Ncutpoints(NcutpointsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    Rcpp::traits::input_parameter< bool >::type parallel(parallelSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_adaptive_std(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, Ncutpoints, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu, parallel));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_adaptive
Rcpp::List train_forest_adaptive(arma::mat y, arma::mat X, arma::mat Xtest, size_t M, size_t L, size_t N_sweeps, arma::mat max_depth, size_t Nmin, size_t Ncutpoints, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu, bool parallel);
RcppExport SEXP _SpikySmoothTrees_train_forest_adaptive(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP NcutpointsSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP, SEXP parallelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< size_t >::type Ncutpoints(NcutpointsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    Rcpp::traits::input_parameter< bool >::type parallel(parallelSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_adaptive(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, Ncutpoints, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu, parallel));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_root_std
Rcpp::List train_forest_root_std(Rcpp::NumericVector y, Rcpp::NumericMatrix X, Rcpp::NumericMatrix Xtest, size_t M, size_t L, size_t N_sweeps, Rcpp::IntegerMatrix max_depth, size_t Nmin, size_t Ncutpoints, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu, bool parallel);
RcppExport SEXP _SpikySmoothTrees_train_forest_root_std(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP NcutpointsSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP, SEXP parallelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type y(ySEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type X(XSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerMatrix >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< size_t >::type Ncutpoints(NcutpointsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    Rcpp::traits::input_parameter< bool >::type parallel(parallelSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_root_std(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, Ncutpoints, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu, parallel));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_root
Rcpp::List train_forest_root(arma::mat y, arma::mat X, arma::mat Xtest, size_t M, size_t L, size_t N_sweeps, arma::mat max_depth, size_t Nmin, size_t Ncutpoints, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu, bool parallel);
RcppExport SEXP _SpikySmoothTrees_train_forest_root(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP NcutpointsSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP, SEXP parallelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< size_t >::type Ncutpoints(NcutpointsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    Rcpp::traits::input_parameter< bool >::type parallel(parallelSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_root(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, Ncutpoints, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu, parallel));
    return rcpp_result_gen;
END_RCPP
}
// train_forest_std
Rcpp::List train_forest_std(Rcpp::NumericMatrix y_rcpp, Rcpp::NumericMatrix X_rcpp, Rcpp::NumericMatrix Xtest_rcpp, Rcpp::IntegerMatrix Xorder_rcpp, size_t M, size_t L, size_t N_sweeps, Rcpp::NumericMatrix max_depth_rcpp, size_t Nmin, size_t Ncutpoints, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu, bool parallel);
RcppExport SEXP _SpikySmoothTrees_train_forest_std(SEXP y_rcppSEXP, SEXP X_rcppSEXP, SEXP Xtest_rcppSEXP, SEXP Xorder_rcppSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depth_rcppSEXP, SEXP NminSEXP, SEXP NcutpointsSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP, SEXP parallelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type y_rcpp(y_rcppSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type X_rcpp(X_rcppSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type Xtest_rcpp(Xtest_rcppSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerMatrix >::type Xorder_rcpp(Xorder_rcppSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type max_depth_rcpp(max_depth_rcppSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< size_t >::type Ncutpoints(NcutpointsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    Rcpp::traits::input_parameter< bool >::type parallel(parallelSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest_std(y_rcpp, X_rcpp, Xtest_rcpp, Xorder_rcpp, M, L, N_sweeps, max_depth_rcpp, Nmin, Ncutpoints, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu, parallel));
    return rcpp_result_gen;
END_RCPP
}
// train_forest
Rcpp::List train_forest(arma::mat y, arma::mat X, arma::mat Xtest, size_t M, size_t L, size_t N_sweeps, arma::mat max_depth, size_t Nmin, double alpha, double beta, double tau, bool draw_sigma, double kap, double s, bool verbose, bool m_update_sigma, bool draw_mu);
RcppExport SEXP _SpikySmoothTrees_train_forest(SEXP ySEXP, SEXP XSEXP, SEXP XtestSEXP, SEXP MSEXP, SEXP LSEXP, SEXP N_sweepsSEXP, SEXP max_depthSEXP, SEXP NminSEXP, SEXP alphaSEXP, SEXP betaSEXP, SEXP tauSEXP, SEXP draw_sigmaSEXP, SEXP kapSEXP, SEXP sSEXP, SEXP verboseSEXP, SEXP m_update_sigmaSEXP, SEXP draw_muSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::mat >::type X(XSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type Xtest(XtestSEXP);
    Rcpp::traits::input_parameter< size_t >::type M(MSEXP);
    Rcpp::traits::input_parameter< size_t >::type L(LSEXP);
    Rcpp::traits::input_parameter< size_t >::type N_sweeps(N_sweepsSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type max_depth(max_depthSEXP);
    Rcpp::traits::input_parameter< size_t >::type Nmin(NminSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< double >::type tau(tauSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_sigma(draw_sigmaSEXP);
    Rcpp::traits::input_parameter< double >::type kap(kapSEXP);
    Rcpp::traits::input_parameter< double >::type s(sSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    Rcpp::traits::input_parameter< bool >::type m_update_sigma(m_update_sigmaSEXP);
    Rcpp::traits::input_parameter< bool >::type draw_mu(draw_muSEXP);
    rcpp_result_gen = Rcpp::wrap(train_forest(y, X, Xtest, M, L, N_sweeps, max_depth, Nmin, alpha, beta, tau, draw_sigma, kap, s, verbose, m_update_sigma, draw_mu));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_SpikySmoothTrees_predict_tree", (DL_FUNC) &_SpikySmoothTrees_predict_tree, 2},
    {"_SpikySmoothTrees_singletree", (DL_FUNC) &_SpikySmoothTrees_singletree, 9},
    {"_SpikySmoothTrees_train_forest_adaptive_std", (DL_FUNC) &_SpikySmoothTrees_train_forest_adaptive_std, 19},
    {"_SpikySmoothTrees_train_forest_adaptive", (DL_FUNC) &_SpikySmoothTrees_train_forest_adaptive, 19},
    {"_SpikySmoothTrees_train_forest_root_std", (DL_FUNC) &_SpikySmoothTrees_train_forest_root_std, 19},
    {"_SpikySmoothTrees_train_forest_root", (DL_FUNC) &_SpikySmoothTrees_train_forest_root, 19},
    {"_SpikySmoothTrees_train_forest_std", (DL_FUNC) &_SpikySmoothTrees_train_forest_std, 20},
    {"_SpikySmoothTrees_train_forest", (DL_FUNC) &_SpikySmoothTrees_train_forest, 17},
    {NULL, NULL, 0}
};

RcppExport void R_init_SpikySmoothTrees(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
