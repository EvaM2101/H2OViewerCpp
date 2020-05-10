//
// Created by evamo on 09/05/2020.
//

#ifndef MODELH2OPROPRE_MATRIX_HPP
#define MODELH2OPROPRE_MATRIX_HPP

#include <vector>
#include <string>
#include <sstream>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> m_grid;
public:
    Matrix(int l, int c) :Matrix(l, c, T()) {}
    Matrix(int l, int c, const T& val) : m_grid(l) {
        for (int i = 0; i < l; i++) {
            m_grid[i] = std::vector<T>(c, val);
        }
    }
    Matrix(const std::vector<std::vector<T>>& grid) : m_grid (grid) {};
    virtual ~Matrix(){}

    // Getter
    const std::vector<std::vector<T>>& get_grid() const { return m_grid; }
    const T& get_element_ij(int i, int j) const { return m_grid[i][j]; }
    int get_nb_lines() const { return m_grid.size(); }
    int get_nb_columns() const { return m_grid[0].size(); }

    // Setter
    void set_element_ij(int i, int j, const T& val) { m_grid[i][j] = val; }

    // Methods
    const Matrix<T> multiply(const Matrix<T>& opd) const {
        int l_opd = opd.get_nb_lines();
        int c_opd = opd.get_nb_columns();
        int l_opg = get_nb_lines();
        int c_opg = get_nb_columns();
        if (l_opd != c_opg){
            throw std::string("Erreur taille multiplication matrices");
        }
        Matrix<T> res(l_opg, c_opd);
        for (int i = 0; i < l_opg; i++) {
            for (int j = 0; j < c_opd; j++) {
                for (int k = 0; k < l_opd; k++){
                    res.m_grid[i][j] += m_grid[i][k]*opd.m_grid[k][j];
                }
            }
        }
        return res;
    }
    const Matrix<T> operator * (const Matrix<T>& opd) const {
        return multiply(opd);
    }
    operator std::string() const {
        std::ostringstream oss;
        oss << "matrice : " << std::endl;
        for (int i = 0; i < get_nb_lines(); i++){
            for (int j = 0; j < get_nb_columns(); j++){
                oss << m_grid[i][j] << " ";
            }
            oss << std::endl;
        }
        return oss.str();
    }
};


#endif //MODELH2OPROPRE_MATRIX_HPP
