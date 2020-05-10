//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_PROJECTEUR_HPP
#define MODELH2OPROPRE_PROJECTEUR_HPP


#include "../../model/elements/boite.hpp"
#include "../../model/projection/matrice_projection.hpp"

class Projecteur {
private:
    static const Vector3D<double> proj_point(
            const Vector3D<double>& point3D,
            const MatriceProjection& matrice_proj
    );
    static const Atome proj_atome(
            const Atome& atome3D,
            const MatriceProjection& matrice_proj
    );
    static const MoleculeH2O proj_mol(
            const MoleculeH2O& mol3D,
            const MatriceProjection& matrice_proj
    );
public:
    static const Boite proj_boite(
            const Boite& boite3D,
            const std::vector<int>& indices,
            const MatriceProjection& matrice_proj
    );
};


#endif //MODELH2OPROPRE_PROJECTEUR_HPP
