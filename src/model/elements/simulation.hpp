//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_SIMULATION_HPP
#define MODELH2OPROPRE_SIMULATION_HPP


#include <vector>
#include "boite.hpp"

class Simulation {
private:
    std::vector<Boite> m_simul;
public:
    Simulation(std::vector<Boite> boites) : m_simul(boites){}
    virtual ~Simulation(){}

    // Getter
    const Boite& get_boite_i(int i) const { return m_simul[i]; }
};


#endif //MODELH2OPROPRE_SIMULATION_HPP
