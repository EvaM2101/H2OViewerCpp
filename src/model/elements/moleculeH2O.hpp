//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_MOLECULEH2O_HPP
#define MODELH2OPROPRE_MOLECULEH2O_HPP

#include <vector>
#include "atome.hpp"


class MoleculeH2O {
private:
    std::vector<Atome> m_atomes;
public:
    MoleculeH2O(const Atome& O, const Atome& H1, const Atome& H2);
    virtual ~MoleculeH2O() {}

    // Getter
    const Atome& get_O() const { return m_atomes[0]; }
    const Atome& get_H1() const { return m_atomes[1]; }
    const Atome& get_H2() const { return m_atomes[2]; }

    // Setter
    void set_O(const Atome& O) { m_atomes[0] = O; }
    void set_H1(const Atome& O) { m_atomes[1] = O; }
    void set_H2(const Atome& O) { m_atomes[2] = O; }

    // Methods
    void affiche_molecule() const;
};


#endif //MODELH2OPROPRE_MOLECULEH2O_HPP
