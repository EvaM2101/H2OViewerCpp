#pragma once

#ifndef MODELH2OPROPRE_VECTOR3D_HPP
#define MODELH2OPROPRE_VECTOR3D_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

template <typename T>
class Vector3D {

private:
    T m_x, m_y, m_z;
public:
    Vector3D(const T& x, const T& y, const T& z);
    virtual ~Vector3D();

    // Getter
    const T& get_x() const { return m_x; }
    const T& get_y() const { return m_y; }
    const T& get_z() const { return m_z; }

    // Setter
    void set_x(const T& x) { m_x = x; }
    void set_y(const T& y) { m_y = y; }
    void set_z(const T& z) { m_z = z; }

    // Methods
    double norme() const;// { return 0;}

    // Surcharge d'operateur
private:
    Vector3D<T> somme(const Vector3D<T>& opd) const; // opd = operant de droite
    double prod_scalaire(const Vector3D<T>& opd) const;
public:
    const Vector3D<T> operator + (const Vector3D<T>& opd) const { return somme(opd); }
    const double operator * (const Vector3D<T>& opd) const { return prod_scalaire(opd); }
    virtual operator std::string () const {
        std::ostringstream oss;
        oss << "("  << m_x <<
                ", " << m_y <<
                ", " << m_z <<
                ")";
        return oss.str();
    }
};

// region operateur <<

template <typename T>
extern std::ostream& operator << (std::ostream& os, const Vector3D<T>& vec) {
    return os << (std::string) vec;
}
// endregion

// region constructeur et destructeur

template <typename T>
Vector3D<T>::Vector3D(const T& x, const T& y, const T& z) : m_x(x), m_y(y), m_z(z) {}
template <typename T>
/*virtual*/Vector3D<T>::~Vector3D() {}
// endregion

// region methodes norme

template <typename T>
double Vector3D<T>::norme() const {
    return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

//endregion

// region fonctions pour surcharge d'operateur

template <typename T>
Vector3D<T> Vector3D<T>::somme(const Vector3D<T>& opd) const {
    T x = m_x + opd.get_x(),
      y = m_y + opd.get_y(),
      z = m_z + opd.get_z();
    return Vector3D<T> (x, y, z);
}

template <typename T>
double Vector3D<T>::prod_scalaire(const Vector3D<T>& opd) const {
    return m_x*opd.m_x + m_y*opd.m_y + m_z*opd.m_z;
}

// endregion

#endif //MODELH2OPROPRE_VECTOR3D_HPP
