#pragma once

#include <iostream>
template <int SIZE>
class Vector {

private:

    double tab[SIZE];     
    friend class Rectangle;
public:

    Vector();        

    Vector(double [SIZE]);

    template <int SIZE1>
    friend Vector <SIZE1> operator+(Vector <SIZE1> &Vec1, Vector <SIZE1> &Vec2);

    template <int SIZE1>
    friend Vector<SIZE1> operator-(Vector <SIZE1> &Vec1, Vector <SIZE1> &Vec2);

    template <int SIZE1>
    friend Vector<SIZE1> operator/(Vector <SIZE1> &Vec, const double &Num);

    template <int SIZE1>
    friend Vector<SIZE1> operator*(Vector <SIZE1> &Vec, const double &Num);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    friend class Vector3D;

};

template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector <SIZE> const &tmp);

template <int SIZE>
std::istream &operator >> (std::istream &in, Vector <SIZE> &tmp);


/**
 * @brief Konstruktor bezparametryczny klasy Vector
 * 
 * @tparam SIZE 
 */
template <int SIZE>
Vector <SIZE>::Vector() {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}


/**
 * @brief Konstruktor parametryczny klasy Vector
 * 
 * @tparam SIZE 
 * @param tmp 
 */
template <int SIZE>
Vector <SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = tmp[i];
    }
}


/**
 * @brief Realizuje operacje dodawania dwoch wektorow
 * 
 * @tparam SIZE1 
 * @param Vec1 
 * @param Vec2 
 * @return Vector <SIZE1> 
 */
template <int SIZE1>
Vector <SIZE1> operator+(Vector <SIZE1> &Vec1, Vector <SIZE1> &Vec2) {
    Vector <SIZE1> result;
    result[0] = (Vec1[0] + Vec2[0]);
    if (SIZE1 > 1) result[1] = (Vec1[1] + Vec2[1]);
    if (SIZE1 > 2) result[2] = (Vec1[2] + Vec2[2]);
    return result;
}


/**
 * @brief Realizuje operacje odejmowania dwoch wektorow
 * 
 * @tparam SIZE1 
 * @param Vec1 
 * @param Vec2 
 * @return Vector <SIZE1> 
 */
template <int SIZE1>
Vector <SIZE1> operator-(Vector <SIZE1> &Vec1, Vector <SIZE1> &Vec2) {
    Vector <SIZE1> result;
    result[0] = (Vec1[0] - Vec2[0]);
    if (SIZE1 > 1) result[1] = (Vec1[1] - Vec2[1]);
    if (SIZE1 > 2) result[2] = (Vec1[2] - Vec2[2]);
    return result;
}


/**
 * @brief Realizuje operacje mnozenia wektora przez skalar
 * 
 * @tparam SIZE1 
 * @param Vec 
 * @param Num 
 * @return Vector <SIZE1> 
 */
template <int SIZE1>
Vector <SIZE1> operator*(Vector <SIZE1> &Vec, const double &Num) {
    Vector <SIZE1> result;
    result[0] = (Vec[0] * Num);
    if (SIZE1 > 1) result[1] = (Vec[1] * Num);
    if (SIZE1 > 2) result[2] = (Vec[2] * Num);
    return result;
}


/**
 * @brief Realizuje operacje dzielenia wektora przez skalar
 * 
 * @tparam SIZE1 
 * @param Vec 
 * @param Num 
 * @return Vector <SIZE1> 
 */
template <int SIZE1>
Vector <SIZE1> operator/(Vector <SIZE1> &Vec, const double &Num) {
    if (Num == 0) {
        throw std::invalid_argument("division by zero");
    }
    Vector <SIZE1> result;
    result[0] = (Vec[0] / Num);
    if (SIZE1 > 1) result[1] = (Vec[1] / Num);
    if (SIZE1 > 2) result[2] = (Vec[2] / Num);
    return result;
}


/**
 * @brief Indeksowania wektora
 * 
 * @tparam SIZE1 
 * @param index 
 * @return const double& 
 */
template <int SIZE1>
const double &Vector <SIZE1>::operator [] (int index) const {
    if (index < 0 || index >= SIZE1) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return tab[index];
}


/**
 * @brief Indeksowanie wektora
 * 
 * @tparam SIZE 
 * @param index 
 * @return double& 
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/**
 * @brief Przeciazenie << dla wektora
 * 
 * @tparam SIZE 
 * @param out 
 * @param tmp 
 * @return std::ostream& 
 */
template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector <SIZE> const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << tmp[i];
        if(i == 0 || i == 1){
            out << " ";
        }
    }
    return out;
}


/**
 * @brief Przeciazenie >> dla wektora
 * 
 * @tparam SIZE 
 * @param in 
 * @param tmp 
 * @return std::istream& 
 */
template <int SIZE>
std::istream &operator >> (std::istream &in, Vector <SIZE> &tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    return in;
}