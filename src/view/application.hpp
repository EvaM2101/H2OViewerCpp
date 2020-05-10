//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_APPLICATION_HPP
#define MODELH2OPROPRE_APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "../controller/manager/simulation_manager.hpp"

class Application {
private:
    sf::RenderWindow m_window;
    SimulationManager m_simul_manager;
public:
    Application();
    virtual ~Application() {}

    void run();
};


#endif //MODELH2OPROPRE_APPLICATION_HPP
