#ifndef MODELH2OPROPRE_ATOME_HPP
#define MODELH2OPROPRE_ATOME_HPP


#include <string>
#include <iostream>
#include "../sdd/vector3d.hpp"


class Atome {
private:
    Vector3D<double> m_pos;
    std::string m_type;
public:
    Atome(const Vector3D<double>& pos, const std::string& type);
    ~Atome();

    // Getter
    const Vector3D<double>& get_pos() const { return m_pos; }
    const std::string& get_type() const { return m_type; }

    // Setter
    void set_pos(const Vector3D<double>& pos) { m_pos = pos; }
    void set_type(const std::string& type) { m_type = type; }

    // Methods
    void affiche_atome() const;
};


#endif //MODELH2OPROPRE_ATOME_HPP
