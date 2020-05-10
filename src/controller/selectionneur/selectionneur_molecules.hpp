//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_SELECTIONNEUR_MOLECULES_HPP
#define MODELH2OPROPRE_SELECTIONNEUR_MOLECULES_HPP


#include "../../model/elements/simulation.hpp"

class SelectionneurMolecules {
public:
    static const std::vector<int> select_indices(
            const Boite& boite_initiale,
            const Vector3D<double>& centre,
            const double rayon,
            const int nb_max_mol
    );
};


#endif //MODELH2OPROPRE_SELECTIONNEUR_MOLECULES_HPP
