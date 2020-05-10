//
// Created by evamo on 09/05/2020.
//

#include "application.hpp"
#include "../model/constantes/constantes.hpp"

Application::Application(){
    m_window.create(
            sf::VideoMode(Constantes::LARGEUR_ECRAN,
                Constantes::HAUTEUR_ECRAN),
            "ModelH2O -- EvaM2101"
    );
}

void Application::run(){

    double dt = 0.;
    sf::Clock clock;
    while (m_window.isOpen())
    {
        dt = clock.restart().asSeconds();
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // update
        m_simul_manager.update(dt);

        m_window.clear();

        // draw
        m_simul_manager.draw(m_window);

        m_window.display();
    }
}
