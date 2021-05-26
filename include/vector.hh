#pragma once

#include <iostream>

template <int SIZE>
class Vector {

private:

    double tab[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double[SIZE]);

    Vector operator + (const Vector <SIZE> &v);

    Vector operator - (const Vector <SIZE> &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

};

template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector <SIZE> const &tmp);

template <int SIZE>
std::istream &operator >> (std::istream &in, Vector <SIZE> &tmp);


/**
 * @brief Konstruktor klasy Vector
 * Argumenty:
 *      @tparam SIZE 
 * Zwraca:
 *      Wektor wypelniony wartosciami 0.
 */
template <int SIZE>
Vector<SIZE>::Vector() {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}


/**
 * @brief Konstruktor parametryczny klasy Vector
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca: 
 *      Macierz wypelniona podanymi wartosciami.
 */
template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = tmp[i];
    }
}


/**
 * @brief Dodawanie dwoch wektorow
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param v 
 * Zwraca: 
 *      @return Vector<SIZE> - suma wektorow
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator + (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] + v[i];
    }
    return result;
}


/**
 * @brief Odejmowanie dwoch wektorow
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param v 
 * Zwraca:
 *      @return Vector<SIZE> - roznica dwoch wektorow
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator - (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] - v[i];
    }
    return result;
}


/**
 * @brief Mnozenie wektora przez liczbe zmiennoprzecinkowa
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca:
 *      @return Vector<SIZE> - przemnozony wektor
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator * (const double &tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] *= tmp;
    }
    return result;
}


/**
 * @brief Dzielenie dwoch wektorow
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param tmp 
 * Zwraca:
 *      @return Vector<SIZE> - iloraz wektorow
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator / (const double &tmp) {
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] / tmp;
    }

    return result;
}


/**
 * @brief Funktor wektora
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param index 
 * Zwraca:
 *      Wartosc wektora w danym miejscu jako stala.
 * @return const double& 
 */
template <int SIZE>
const double &Vector<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return tab[index];
}


/**
 * @brief Funktor wektora
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param index 
 * Zwraca:
 *      @return double& - Wartosc wektora w danym miejscu.
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
}


/**
 * @brief Przeciazenie operatora <<
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param out 
 *      @param tmp 
 * Zwraca:
 *      @return std::ostream& 
 */
template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/**
 * @brief Przeciazenie operatora >>
 * 
 * Argumenty:
 *      @tparam SIZE 
 *      @param in 
 *      @param tmp 
 * Zwraca:
 *      @return std::istream& 
 */
template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
