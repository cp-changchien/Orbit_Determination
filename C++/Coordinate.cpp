#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>
#include </opt/homebrew/opt/eigen/include/eigen3/Eigen/Dense>

#include "Coordinate.h"


using namespace Eigen;


Vector3d Coordinate::P2ECI(){
    
    Matrix3d A_RAAN, A_i, A_w, P_ECI_Matrix; 
    A_RAAN << cos(RAAN),  sin(RAAN), 0, 
              -sin(RAAN), cos(RAAN), 0, 
              0, 0, 1;
    
    A_i << 1, 0, 0,
           0, cos(i), sin(i),
           0, -sin(i), cos(i);
    
    A_w << cos(w),  sin(w), 0,
           -sin(w), cos(w), 0,
           0, 0, 1;

    P_ECI_Matrix = (A_w * A_i * A_RAAN).transpose();

    Vector3d ECI_r, ECI_v;

    return ECI_r;
 }




Vector3d Coordinate::ECI2LVLH(Vector3d&ECI_r, Vector3d&ECI_v){
    
    Vector3d LV = ECI_r.normalized();

    Vector3d h = LV.cross(ECI_v);
    
    Vector3d orbit_normal = h.normalized();
    
    Vector3d LH = orbit_normal.cross(LV);

    ECI_LVLH << LV, LH, orbit_normal;

    LVLH_r = ECI_LVLH * ECI_r;
    LVLH_v = ECI_LVLH * ECI_v;
    
    return LVLH_r;
}





