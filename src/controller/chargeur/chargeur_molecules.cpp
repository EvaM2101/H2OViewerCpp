//
// Created by evamo on 09/05/2020.
//

#include "chargeur_molecules.hpp"

/*static*/ Atome ChargeurSimulation::charge_atome(std::ifstream& fichier, const std::string& type) {
    double x, y, z, poubelle;
    fichier >> x >> y >> z;
    for (int i = 0; i < 3; i++) fichier >> poubelle;
    Vector3D<double> pos(x, y, z);
    return Atome(pos, type);
}

/*static*/ MoleculeH2O ChargeurSimulation::charge_molecule(std::ifstream& fichier){
    Atome O = charge_atome(fichier, "O");
    Atome H1 = charge_atome(fichier, "H1");
    Atome H2 = charge_atome(fichier, "H2");
    return MoleculeH2O(O, H1, H2);
}

/*static*/ Boite ChargeurSimulation::charge_boite(std::ifstream& fichier, int nb_mol){
    std::vector<MoleculeH2O> lst_mol;
    for (int i = 0; i < nb_mol; i++) lst_mol.push_back(charge_molecule(fichier));
    return Boite(lst_mol);
}

/*static*/ Simulation ChargeurSimulation::charge_simulation(const std::string& nom_fichier, int nb_mol, int nb_iter){
    std::ifstream fichier(nom_fichier, std::ios::in); // in = lecture seule
    if (fichier.is_open()) {
        std::vector<Boite> boites;
        for (int i = 0; i < nb_iter; i++){
            boites.push_back(charge_boite(fichier, nb_mol));
        }
        fichier.close();
        return Simulation(boites);
    } else {
        std::cerr << "erreur fichier : "
                  << nom_fichier
                  << std::endl;
    }
}

