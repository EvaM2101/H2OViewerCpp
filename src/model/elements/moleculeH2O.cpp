//
// Created by evamo on 09/05/2020.
//

#include "moleculeH2O.hpp"

MoleculeH2O::MoleculeH2O(
    const Atome& O,
    const Atome& H1,
    const Atome& H2
)   : m_atomes({O, H1, H2}) {}

void MoleculeH2O::affiche_molecule() const {
    for (int i = 0; i < 3; i++) m_atomes[i].affiche_atome();
}

