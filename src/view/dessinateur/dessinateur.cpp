//
// Created by evamo on 09/05/2020.
//

#include <SFML/Graphics.hpp>
#include "dessinateur.hpp"
#include "../../model/constantes/constantes.hpp"

void Dessinateur::dessine(const Atome& atm, sf::RenderWindow& window){
    double rayon_atome = Constantes::RAYON_H;
    if (atm.get_type() == "O") rayon_atome = Constantes::RAYON_O;



    const Vector3D<double>& pos = atm.get_pos();
    sf::Vector2f pos_aff(
            pos.get_x()*0.5*Constantes::LARGEUR_ECRAN,
            pos.get_y()*0.5*Constantes::HAUTEUR_ECRAN
    );

    sf::CircleShape shape(rayon_atome);
    shape.setPosition(pos_aff);
    shape.setOrigin(0.5, 0.5);
    if (atm.get_type() == "O") shape.setFillColor(sf::Color::Red);
    window.draw(shape);
}

void Dessinateur::dessine(const MoleculeH2O& mol, sf::RenderWindow& window){
    dessine(mol.get_O(), window);
    dessine(mol.get_H1(), window);
    dessine(mol.get_H2(), window);
}

void Dessinateur::dessine(const Boite& boite, sf::RenderWindow& window){
    for (const MoleculeH2O& mol : boite.get_molecules()){
        dessine(mol, window);
    }
}