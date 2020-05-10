//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_BOITE_HPP
#define MODELH2OPROPRE_BOITE_HPP

#include <vector>
#include "moleculeH2O.hpp"


class Boite {
private:
    std::vector<MoleculeH2O> m_boite;
public:
    Boite(const std::vector<MoleculeH2O>& lst_mol) :
        m_boite(lst_mol){}
    Boite(){}
    virtual ~Boite(){}

    // Getter
    const MoleculeH2O& get_molecule_i(int i) const { return m_boite[i]; }
    const std::vector<MoleculeH2O>& get_molecules() const { return m_boite; }

    // Setter
    void set_molecule_i(const MoleculeH2O& mol, int i) { m_boite[i] = mol; }

    // Methods
    void affiche_molecule_i(int i) const { m_boite[i].affiche_molecule();  }
};


#endif //MODELH2OPROPRE_BOITE_HPP
