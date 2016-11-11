
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.12

#include <stan/model/model_header.hpp>

namespace model_schools_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

class model_schools : public prob_grad {
private:
    int J;
    vector<double> y;
    vector<double> sigma;
public:
    model_schools(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        typedef boost::ecuyer1988 rng_t;
        rng_t base_rng(0);  // 0 seed default
        ctor_body(context__, base_rng, pstream__);
    }

    template <class RNG>
    model_schools(stan::io::var_context& context__,
        RNG& base_rng__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, base_rng__, pstream__);
    }

    template <class RNG>
    void ctor_body(stan::io::var_context& context__,
                   RNG& base_rng__,
                   std::ostream* pstream__) {
        current_statement_begin__ = -1;

        static const char* function__ = "model_schools_namespace::model_schools";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        context__.validate_dims("data initialization", "J", "int", context__.to_vec());
        J = int(0);
        vals_i__ = context__.vals_i("J");
        pos__ = 0;
        J = vals_i__[pos__++];
        context__.validate_dims("data initialization", "y", "double", context__.to_vec(J));
        validate_non_negative_index("y", "J", J);
        y = std::vector<double>(J,double(0));
        vals_r__ = context__.vals_r("y");
        pos__ = 0;
        size_t y_limit_0__ = J;
        for (size_t i_0__ = 0; i_0__ < y_limit_0__; ++i_0__) {
            y[i_0__] = vals_r__[pos__++];
        }
        context__.validate_dims("data initialization", "sigma", "double", context__.to_vec(J));
        validate_non_negative_index("sigma", "J", J);
        sigma = std::vector<double>(J,double(0));
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0;
        size_t sigma_limit_0__ = J;
        for (size_t i_0__ = 0; i_0__ < sigma_limit_0__; ++i_0__) {
            sigma[i_0__] = vals_r__[pos__++];
        }

        // validate data
        check_greater_or_equal(function__,"J",J,0);
        for (int k0__ = 0; k0__ < J; ++k0__) {
            check_greater_or_equal(function__,"sigma[k0__]",sigma[k0__],0);
        }

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning


        // initialize transformed variables to avoid seg fault on val access

        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        ++num_params_r__;
        ++num_params_r__;
        num_params_r__ += J;
    }

    ~model_schools() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("mu")))
            throw std::runtime_error("variable mu missing");
        vals_r__ = context__.vals_r("mu");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu", "double", context__.to_vec());
        double mu(0);
        mu = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu: ") + e.what());
        }

        if (!(context__.contains_r("tau")))
            throw std::runtime_error("variable tau missing");
        vals_r__ = context__.vals_r("tau");
        pos__ = 0U;
        context__.validate_dims("initialization", "tau", "double", context__.to_vec());
        double tau(0);
        tau = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,tau);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable tau: ") + e.what());
        }

        if (!(context__.contains_r("eta")))
            throw std::runtime_error("variable eta missing");
        vals_r__ = context__.vals_r("eta");
        pos__ = 0U;
        context__.validate_dims("initialization", "eta", "double", context__.to_vec(J));
        std::vector<double> eta(J,double(0));
        for (int i0__ = 0U; i0__ < J; ++i0__)
            eta[i0__] = vals_r__[pos__++];
        for (int i0__ = 0U; i0__ < J; ++i0__)
            try {
            writer__.scalar_unconstrain(eta[i0__]);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable eta: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        T__ mu;
        (void) mu;  // dummy to suppress unused var warning
        if (jacobian__)
            mu = in__.scalar_constrain(lp__);
        else
            mu = in__.scalar_constrain();

        T__ tau;
        (void) tau;  // dummy to suppress unused var warning
        if (jacobian__)
            tau = in__.scalar_lb_constrain(0,lp__);
        else
            tau = in__.scalar_lb_constrain(0);

        vector<T__> eta;
        size_t dim_eta_0__ = J;
        eta.reserve(dim_eta_0__);
        for (size_t k_0__ = 0; k_0__ < dim_eta_0__; ++k_0__) {
            if (jacobian__)
                eta.push_back(in__.scalar_constrain(lp__));
            else
                eta.push_back(in__.scalar_constrain());
        }


        // transformed parameters
        vector<T__> theta(J);

        // initialize transformed variables to avoid seg fault on val access
        stan::math::fill(theta,DUMMY_VAR__);

        try {
            for (int j = 1; j <= J; ++j) {
                stan::math::assign(get_base1_lhs(theta,j,"theta",1), (mu + (tau * get_base1(eta,j,"eta",1))));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters
        for (int i0__ = 0; i0__ < J; ++i0__) {
            if (stan::math::is_uninitialized(theta[i0__])) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: theta" << '[' << i0__ << ']';
                throw std::runtime_error(msg__.str());
            }
        }

        const char* function__ = "validate transformed params";
        (void) function__;  // dummy to suppress unused var warning

        // model body
        try {
            lp_accum__.add(normal_log(eta,0,1));
            lp_accum__.add(normal_log(y,theta,sigma));
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu");
        names__.push_back("tau");
        names__.push_back("eta");
        names__.push_back("theta");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(J);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_schools_namespace::write_array";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        double mu = in__.scalar_constrain();
        double tau = in__.scalar_lb_constrain(0);
        vector<double> eta;
        size_t dim_eta_0__ = J;
        for (size_t k_0__ = 0; k_0__ < dim_eta_0__; ++k_0__) {
            eta.push_back(in__.scalar_constrain());
        }
        vars__.push_back(mu);
        vars__.push_back(tau);
        for (int k_0__ = 0; k_0__ < J; ++k_0__) {
            vars__.push_back(eta[k_0__]);
        }

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        vector<double> theta(J, 0.0);

        try {
            for (int j = 1; j <= J; ++j) {
                stan::math::assign(get_base1_lhs(theta,j,"theta",1), (mu + (tau * get_base1(eta,j,"eta",1))));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters

        // write transformed parameters
        for (int k_0__ = 0; k_0__ < J; ++k_0__) {
            vars__.push_back(theta[k_0__]);
        }

        if (!include_gqs__) return;
        // declare and define generated quantities

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning


        // initialize transformed variables to avoid seg fault on val access

        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_schools";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= J; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "eta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= J; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tau";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= J; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "eta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= J; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "theta" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

} // namespace




#endif
