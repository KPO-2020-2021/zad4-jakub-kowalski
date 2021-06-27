#pragma once

#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
template <int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               

public:
    Matrix(double [SIZE][SIZE]);            

    Matrix();                               

    
    Vector <SIZE> operator * (Vector <SIZE> tmp);           

    template <int SIZE1>
    friend Matrix <SIZE1> operator * (Matrix <SIZE1> &tmp, Matrix <SIZE1> &tmp2);

    Matrix <SIZE> operator + (Matrix <SIZE> tmp);           

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    friend class Matrix3D;
    
};

template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix <SIZE> &mat);
template <int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix <SIZE> const &mat);


/**
 * @brief Konstruktor bezparametryczny klasy Matrix
 * 
 * @tparam SIZE 
 */
template <int SIZE>
Matrix <SIZE>::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j){
                value[i][j] = 1;
            }
            else{
                value[i][j] = 0;
            }

        }
    }
}


/**
 * @brief Konstruktor parametryczny klasy Vector
 * 
 * @tparam SIZE 
 * @param tmp 
 */
template <int SIZE>
Matrix <SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}


/**
 * @brief Realizuje mnozenie macierzy przez wektor
 * 
 * @tparam SIZE 
 * @param tmp 
 * @return Vector <SIZE> 
 */
template <int SIZE>
Vector <SIZE> Matrix<SIZE>::operator * (Vector <SIZE> tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/**
 * @brief Realizuje mnozenie dwoch macierzy
 * 
 * @tparam SIZE1 
 * @param tmp 
 * @param tmp2 
 * @return Matrix <SIZE1> 
 */
template <int SIZE1>
Matrix <SIZE1> operator * ( Matrix <SIZE1> &tmp, Matrix <SIZE1> &tmp2) {
    Matrix <SIZE1> result;
    for(int i = 0; i < SIZE1; i++){
        for(int j = 0; j < SIZE1; j++){
            result(i, j) = 0;
            for(int k = 0; k < SIZE1; k++){
                result(i, j) += tmp(i, k) * tmp2(k, j);
            }
        }
    }
    return result;
}


/**
 * @brief Indeksowanie macierzy
 * 
 * @tparam SIZE 
 * @param row 
 * @param column 
 * @return double& 
 */
template <int SIZE>
double &Matrix <SIZE>::operator()(unsigned int row, unsigned int column) {

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
 * @brief Indeksowanie macierzy
 * 
 * @tparam SIZE 
 * @param row 
 * @param column 
 * @return const double& 
 */
template <int SIZE>
const double &Matrix <SIZE>::operator () (unsigned int row, unsigned int column) const {            

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
 * @brief Realizuje dodawanie dwoch macierzy
 * 
 * @tparam SIZE 
 * @param tmp 
 * @return Matrix <SIZE> 
 */
template <int SIZE>
Matrix <SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/**
 * @brief Przeciazenie >> dla macierzy
 * 
 * @tparam SIZE 
 * @param in 
 * @param mat 
 * @return std::istream& 
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
 * @brief Przeciazenie << dla macierzy
 * 
 * @tparam SIZE 
 * @param out 
 * @param mat 
 * @return std::ostream& 
 */
template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " << mat(i, j) << " | "; 
        }
        std::cout << std::endl;
    }
    return out;
}


