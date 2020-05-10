//
// Created by evamo on 09/05/2020.
//

#include "projecteur.hpp"

/*static*/ const Vector3D<double> Projecteur::proj_point(
        const Vector3D<double>& point3D,
        const MatriceProjection& matrice_proj){
    Matrix<double> m3D({
        {point3D.get_x(), point3D.get_y(), point3D.get_z(), 1.0}
    });
    Matrix<double> res = m3D * matrice_proj;
    double w = res.get_grid()[0][3];
    if (w != 0){
        return Vector3D<double>(res.get_grid()[0][0]/w,
                                res.get_grid()[0][1]/w,
                                res.get_grid()[0][2]/w);
    }
    return Vector3D<double>(res.get_grid()[0][0],
                            res.get_grid()[0][1],
                            res.get_grid()[0][2]);
}

/*static*/ const Atome Projecteur::proj_atome(
        const Atome& atome3D,
        const MatriceProjection& matrice_proj
){
    return Atome(
            proj_point(atome3D.get_pos(), matrice_proj),
            atome3D.get_type()
    );
}

/*static*/ const MoleculeH2O Projecteur::proj_mol(
        const MoleculeH2O& mol3D,
        const MatriceProjection& matrice_proj
){
    return MoleculeH2O(
            proj_atome(mol3D.get_O(), matrice_proj),
            proj_atome(mol3D.get_H1(), matrice_proj),
            proj_atome(mol3D.get_H2(), matrice_proj)
            );
}

/*static*/ const Boite Projecteur::proj_boite(
        const Boite& boite3D,
        const std::vector<int>& indices,
        const MatriceProjection& matrice_proj
){
    std::vector<MoleculeH2O> molecules2D;
    for (int ind : indices) {
        const MoleculeH2O& mol_courante = boite3D.get_molecule_i(ind);
        molecules2D.push_back(proj_mol(mol_courante, matrice_proj));
    }
    return Boite(molecules2D);
}