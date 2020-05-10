//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_DESSINATEUR_HPP
#define MODELH2OPROPRE_DESSINATEUR_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include "../../model/elements/atome.hpp"
#include "../../model/elements/moleculeH2O.hpp"
#include "../../model/elements/boite.hpp"

class Dessinateur {
private:
    static void dessine(const Atome& atm, sf::RenderWindow& window);
    static void dessine(const MoleculeH2O& mol, sf::RenderWindow& window);

public:
    static void dessine(const Boite& boite, sf::RenderWindow& window);
};


#endif //MODELH2OPROPRE_DESSINATEUR_HPP
