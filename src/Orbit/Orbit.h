#include <cmath>
#include <numeric>
#include </opt/homebrew/opt/eigen/include/eigen3/Eigen/Dense>

using namespace Eigen;

typedef Matrix<double,6,1> Vector6d;


/**
 * @class
 *
 */
class Orbit {

    private:
        const long double Earth_Radius = 6378;
        const long double Earth_mu = 398600;
        const long double J2 = 0.00108263;
        const std::string Start_Date = "29-Oct-2023 07:55:48.000";
        const std::string End_Date = "29-Oct-2023 12:55:48.000";
    
    public:

        static double SMA;
        static double e;
        static double i;
        static double RAAN;
        static double w;
        static double M;
        double h;
        double T;
        
        Vector6d ECI_state;
        Vector6d state;

        // Define the initial conditions from the uesr input
        void SetParameter(const double &arg_SMA, const double &arg_e, const double &arg_i,
                          const double &arg_RAAN, const double &arg_w,
                          const double &arg_M);
        
        // Equation of motion
        Vector6d EoM(Vector6d &x);

        void RungeKutta45(double dt, double T, Vector6d& x);

        void integrate();

        // ~Orbit();
};