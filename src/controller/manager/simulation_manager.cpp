//
// Created by evamo on 09/05/2020.
//

#include <SFML/Window/Keyboard.hpp>
#include "simulation_manager.hpp"
#include "../chargeur/chargeur_molecules.hpp"
#include "../../model/constantes/constantes.hpp"
#include "../selectionneur/selectionneur_molecules.hpp"
#include "../projecteur/projecteur.hpp"
#include "../../view/dessinateur/dessinateur.hpp"

SimulationManager::SimulationManager() :
    m_simulation(load_simulation()),
    m_selection(SelectionneurMolecules::select_indices(
            m_simulation.get_boite_i(0),
            Vector3D<double>(0,0,0),
            3.86,
            10
    )),
    m_iteration_courante(0),
    m_dx(20.0), m_dy(20.0), m_dz(20.0),
    m_chrono(0),
    m_temps_positif(true)
    {}

/*static*/ Simulation SimulationManager::load_simulation(){
    return ChargeurSimulation::charge_simulation(
            Constantes::CHEMIN_DATA,
            Constantes::NB_MOLECULES,
            Constantes::NB_ITERATIONS
            );
}

// update
void SimulationManager::update(double dt){
    update_iteration(dt);
    update_clavier(dt);
    Boite boite_translatee = translate_modele();
    Boite boite_projetee = update_modele_proj(boite_translatee);
    m_vue = boite_projetee;
}

const Boite SimulationManager::translate_modele(){
    Boite res = m_simulation.get_boite_i(m_iteration_courante);
    for (int ind : m_selection){
        MoleculeH2O mol_courante = res.get_molecule_i(ind);
        Atome O_courant = mol_courante.get_O();
        Atome H1_courant = mol_courante.get_H1();
        Atome H2_courant = mol_courante.get_H2();
        Vector3D<double> dv(m_dx, m_dy, m_dz);

        O_courant.set_pos(O_courant.get_pos() + dv);
        H1_courant.set_pos(H1_courant.get_pos() + dv);
        H2_courant.set_pos(H2_courant.get_pos() + dv);

        mol_courante.set_O(O_courant);
        mol_courante.set_H1(H1_courant);
        mol_courante.set_H2(H2_courant);

        res.set_molecule_i(mol_courante, ind);
    }
    return res;
}

const Boite SimulationManager::update_modele_proj(const Boite& boite_modele){
    return Boite(Projecteur::proj_boite(
            boite_modele,
            m_selection,
            m_matrice_proj)
    );
}

void SimulationManager::update_clavier(double dt) {
    double facteur = 50.0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_dx += dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        m_dx -= dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        m_dy -= dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_dy += dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_dz += dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_dz -= dt * facteur;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_dx = 20.0;
        m_dy = 20.0;
        m_dz = 20.0;
    }
}

void SimulationManager::update_iteration(double dt){
    m_chrono += dt;

    if (m_chrono > Constantes::DELTA_TIME){
        if (m_temps_positif){
            m_iteration_courante++;
        } else{
            m_iteration_courante--;
        }
        m_chrono = 0.0;
    }

    if (m_iteration_courante >= Constantes::NB_ITERATIONS - 1){
        m_temps_positif = false;
    }
    if (m_iteration_courante == 0){
        m_temps_positif = true;
    }


}

// draw
void SimulationManager::draw(sf::RenderWindow& window){

    // Projection


    // Affichage SFML
    Dessinateur::dessine(m_vue, window);
}