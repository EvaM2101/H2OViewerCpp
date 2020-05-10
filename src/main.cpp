#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "model/sdd/vector3d.hpp"
#include "model/elements/simulation.hpp"
#include "controller/chargeur/chargeur_molecules.hpp"
#include "model/constantes/constantes.hpp"
#include "model/sdd/matrix.hpp"
#include "model/projection/matrice_projection.hpp"
#include "view/application.hpp"

int main(int argc, char* argv[]) {



//    Simulation sim = ChargeurSimulation::charge_simulation(
//            Constantes::CHEMIN_DATA,
//            Constantes::NB_MOLECULES,
//            Constantes::NB_ITERATIONS
//            );
//    sim.get_boite_i(99).affiche_molecule_i(999);

//    MatriceProjection m;
//    std::cout << (std::string)m << std::endl;

    Application app;
    app.run();

    return 0;
}

