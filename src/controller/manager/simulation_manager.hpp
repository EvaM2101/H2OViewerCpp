//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_SIMULATION_MANAGER_HPP
#define MODELH2OPROPRE_SIMULATION_MANAGER_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include "../../model/elements/simulation.hpp"
#include "../../model/projection/matrice_projection.hpp"

class SimulationManager {
private:
    /// Modèle :
    Simulation m_simulation;
    MatriceProjection m_matrice_proj;
    std::vector<int> m_selection;
    Boite m_vue;
    int m_iteration_courante;
    double m_dx, m_dy, m_dz;
    double m_chrono;
    bool m_temps_positif;
public:
    SimulationManager();


    // load
    static Simulation load_simulation();

    // update
    void update(double dt);
    const Boite translate_modele();
    const Boite update_modele_proj(const Boite& boite_modele);
    void update_clavier(double dt);
    void update_iteration(double dt);

    // draw
    void draw(sf::RenderWindow& window);
};


#endif //MODELH2OPROPRE_SIMULATION_MANAGER_HPP
