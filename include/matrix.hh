#pragma once

#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>

template <int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector <SIZE> operator * (Vector <SIZE> tmp);           // Operator mnożenia przez wektor

    Matrix <SIZE> operator + (Matrix <SIZE> tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    void rotation_matrix(double angle_degrees, char axis = 'z');

    void identity_matrix(Matrix <SIZE> tmp);
};

template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix <SIZE> &mat);

template <int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix <SIZE> const &mat);


/**
 * @brief Konstruktor klasy Matrix
 * 
 * Argumenty:
 *      @tparam SIZE 
 * Zwraca:
 *      Macierz wypelniona wartosciami 0.
 */
template <int SIZE>
Matrix<SIZE>::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = 0;
        }
    }
}


/**
 * @brief Konstruktor parametryczny klasy Matrix
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca:
 *      Macierz wypelniona podanymi wartosciami.
 */
template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}


/**
 * @brief Mnozenie macierzy przez wektor
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca:
 *      @return Vector<SIZE> - wymnozony wektor
 */
template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator * (Vector<SIZE> tmp) {
    Vector <SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    std::cout << result;
    return result;
}


/**
 * @brief Funktor macierzy
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param row 
 *      @param column 
 * Zwraca:
 *      @return double& - wartosc macierzy w danym miejscu
 */
template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/**
 * @brief Funktor macierzy
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param row 
 *      @param column 
 * Zwraca:
 *      @return const double& - wartosc macierzy jako stala
 */
template <int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/**
 * @brief Przeciazenie dodawania macierzy
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca:
 *      @return Matrix<SIZE> - suma dwoch macierzy
 */
template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/**
 * @brief Przeciazenie operatora >>
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param in 
 *      @param mat 
 * Zwraca:
 *      @return std::istream& 
 */
template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/**
 * @brief Przeciazenie operatora <<
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param out 
 *      @param mat 
 * Zwraca:
 *      @return std::ostream& 
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/**
 * @brief Tworzy macierz rotacji 
 * 
 * Argumenty: 
 *      @tparam SIZE 
 *      @param angle_degrees 
 *      @param axis 
 */
template <int SIZE>
void Matrix<SIZE>::rotation_matrix(double angle_degrees, char axis)
{
    double angle_radians = angle_degrees * M_PI / 180;
    double sinx = sin(angle_radians);
    double cosx = cos(angle_radians);

    if (SIZE == 2)
    {
        value[0][0] = cosx;
        value[0][1] = -sinx;
        value[1][0] = sinx;
        value[1][1] = cosx;
    }

    if (SIZE == 3)
    {
        switch(axis)
        {
            case 'x':
            value[0][0] = 1;
            value[0][1] = 0;
            value[0][2] = 0;
            value[1][0] = 0;
            value[1][1] = cosx;
            value[1][2] = -sinx;
            value[2][0] = 0;
            value[2][1] = sinx;
            value[2][2] = cosx;
            break;

            case 'y':
            value[0][0] = cosx;
            value[0][1] = 0;
            value[0][2] = sinx;
            value[1][0] = 0;
            value[1][1] = 1;
            value[1][2] = 0;
            value[2][0] = -sinx;
            value[2][1] = 0;
            value[2][2] = cosx;
            break;

            case 'z':
            value[0][0] = cosx;
            value[0][1] = -sinx;
            value[0][2] = 0;
            value[1][0] = sinx;
            value[1][1] = cosx;
            value[1][2] = 0;
            value[2][0] = 0;
            value[2][1] = 0;
            value[2][2] = 1;
            break;

            default:
            std::cout << "Niepoprawna os" << std::endl;
            break;
        }
    }

}