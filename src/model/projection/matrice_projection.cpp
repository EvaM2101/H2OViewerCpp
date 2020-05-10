//
// Created by evamo on 09/05/2020.
//

#include "matrice_projection.hpp"

MatriceProjection::MatriceProjection() : Matrix<double>(4,4) {
    const double a = Constantes::HAUTEUR_ECRAN / Constantes::LARGEUR_ECRAN;
    const double f = 1.0 / std::tan((0.5 * Constantes::ANGLE_VUE) * 3.14159 / 180.0);
    const double q = Constantes::Z_FAR / (Constantes::Z_FAR - Constantes::Z_NEAR);

    set_element_ij(0, 0, a * f);
    set_element_ij(1, 1, f);
    set_element_ij(2, 2, q);
    set_element_ij(3, 2, -Constantes::Z_NEAR * q);
    set_element_ij(2, 3, 1.0);
}