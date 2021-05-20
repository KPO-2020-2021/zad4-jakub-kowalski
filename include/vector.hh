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

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template <int SIZE>
Vector<SIZE>::Vector() {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator + (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator - (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] - v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator * (const double &tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] *= tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator / (const double &tmp) {
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <int SIZE>
const double &Vector<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return tab[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <int SIZE>
double &Vector<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
