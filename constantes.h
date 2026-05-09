#include "Vecteur3D.h"
#pragma once
namespace phy{
    inline constexpr double pi = 3.14159265358979323846;
    inline const Vecteur3D g(0.0, 0.0, -9.81);
    inline constexpr double rho_air = 1.3;
    inline constexpr double rho_eau = 1e3;
    inline constexpr double eta_air = 1.8e-5 ;
    inline constexpr double eta_eau= 1.3e-3;
};
