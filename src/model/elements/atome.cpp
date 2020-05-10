
#include "atome.hpp"

Atome::Atome(const Vector3D<double>& pos, const std::string& type) :
    m_pos(pos), m_type(type) {}
Atome::~Atome() {}

void Atome::affiche_atome() const {
    std::cout << m_type << " : " << m_pos << std::endl;
}