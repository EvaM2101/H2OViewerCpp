//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_CHARGEUR_MOLECULES_HPP
#define MODELH2OPROPRE_CHARGEUR_MOLECULES_HPP

#include <fstream>
#include "../../model/elements/atome.hpp"
#include "../../model/elements/moleculeH2O.hpp"
#include "../../model/elements/boite.hpp"
#include "../../model/elements/simulation.hpp"

class ChargeurSimulation {
private:
    static Atome charge_atome (std::ifstream& fichier, const std::string& type);
    static MoleculeH2O charge_molecule(std::ifstream& fichier);
    static Boite charge_boite(std::ifstream& fichier, int nb_mol);
public:
    static Simulation charge_simulation(const std::string& nom_fichier, int nb_mol, int nb_iter);
};


#endif //MODELH2OPROPRE_CHARGEUR_MOLECULES_HPP
