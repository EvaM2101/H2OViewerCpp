//
// Created by evamo on 09/05/2020.
//

#include "selectionneur_molecules.hpp"
#include "../../model/constantes/constantes.hpp"

/*static*/ const std::vector<int> SelectionneurMolecules::select_indices(
        const Boite& boite_initiale,
        const Vector3D<double>& centre,
        const double rayon,
        const int nb_max_mol
){
    std::vector<int> lst;

    for (int i = 0; i < Constantes::NB_MOLECULES && lst.size() < nb_max_mol; i++){
        const MoleculeH2O& molecule_courante = boite_initiale.get_molecule_i(i);
        const Atome& atome_O = molecule_courante.get_O();
        const Vector3D<double>& pos_O = atome_O.get_pos();
        Vector3D<double> distance(
                centre.get_x() - pos_O.get_x(),
                centre.get_y() - pos_O.get_y(),
                centre.get_z() - pos_O.get_z()
        );
        if (distance.norme() < rayon){
            lst.push_back(i);
        }
    }
    return lst;
}