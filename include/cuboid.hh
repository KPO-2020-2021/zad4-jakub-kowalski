#pragma once

#include "vector.hh"
#include "matrix.hh"
#include <iostream>

class Cuboid{

private:    
    
    Vector <3> coordinate[8];

public:

    Cuboid();
    Cuboid(Vector <3> tmp[8]);
    friend std::ostream & operator << (std::ostream & strm, const Cuboid &cuboid);
    void rotate(Matrix <3> matrix);
    void translation(Vector <3> tmp);

};


/**
 * @brief Konstruktor klasy Cuboid
 * 
 * Argumenty:
 *      brak
 * Zwraca:
 *      Tablice wektorow wypelniona wartoscia 0.
 * 
 */
Cuboid::Cuboid()
{
    for(int i = 0; i < 8; i++)
    {
        coordinate[i] = 0;
    }
}

/**
 * @brief Konstruktor parametryczny klasy Cuboid
 * 
 * Argumenty:
 *      @param tmp 
 * Zwraca:
 *      Tablice wektorow wypelniona podanymi wartosciami.
 */
Cuboid::Cuboid(Vector <3> tmp[8])
{
    for(int i = 0; i < 8; i++)
    {
        coordinate[i] = tmp[i];
    }
}


/**
 * @brief Przeciazenie operatora <<
 * 
 * Argumenty:
 *      @param strm 
 *      @param cuboid 
 * Zwraca:
 *      @return std::ostream& 
 */
std::ostream & operator << (std::ostream & strm, const Cuboid &cuboid)
{
    strm << cuboid.coordinate[0][0] << " " << cuboid.coordinate[0][1] << " " << cuboid.coordinate[0][2] << std::endl;
    strm << cuboid.coordinate[1][0] << " " << cuboid.coordinate[1][1] << " " << cuboid.coordinate[1][2] << std::endl;
    strm << cuboid.coordinate[2][0] << " " << cuboid.coordinate[2][1] << " " << cuboid.coordinate[2][2] << std::endl;
    strm << cuboid.coordinate[3][0] << " " << cuboid.coordinate[3][1] << " " << cuboid.coordinate[3][2] << std::endl;   
    strm << cuboid.coordinate[4][0] << " " << cuboid.coordinate[4][1] << " " << cuboid.coordinate[4][2] << std::endl;
    strm << cuboid.coordinate[5][0] << " " << cuboid.coordinate[5][1] << " " << cuboid.coordinate[5][2] << std::endl;
    strm << cuboid.coordinate[6][0] << " " << cuboid.coordinate[6][1] << " " << cuboid.coordinate[6][2] << std::endl; 
    strm << cuboid.coordinate[7][0] << " " << cuboid.coordinate[7][1] << " " << cuboid.coordinate[7][2] << std::endl;
    strm << cuboid.coordinate[2][0] << " " << cuboid.coordinate[2][1] << " " << cuboid.coordinate[2][2] << std::endl;
    strm << cuboid.coordinate[1][0] << " " << cuboid.coordinate[1][1] << " " << cuboid.coordinate[1][2] << std::endl;
    strm << cuboid.coordinate[6][0] << " " << cuboid.coordinate[6][1] << " " << cuboid.coordinate[6][2] << std::endl; 
    strm << cuboid.coordinate[5][0] << " " << cuboid.coordinate[5][1] << " " << cuboid.coordinate[5][2] << std::endl;
    strm << cuboid.coordinate[0][0] << " " << cuboid.coordinate[0][1] << " " << cuboid.coordinate[0][2] << std::endl;
    strm << cuboid.coordinate[3][0] << " " << cuboid.coordinate[3][1] << " " << cuboid.coordinate[3][2] << std::endl;
    strm << cuboid.coordinate[4][0] << " " << cuboid.coordinate[4][1] << " " << cuboid.coordinate[4][2] << std::endl;
    strm << cuboid.coordinate[7][0] << " " << cuboid.coordinate[7][1] << " " << cuboid.coordinate[7][2] << std::endl;
    
    return strm;
}


/**
 * @brief Rotacja wokol osi
 * 
 * Argumenty:
 *      @param matrix 
 */
void Cuboid::rotate(Matrix <3> matrix)
{
    for(int i = 0; i < 8; i++)
    {
        coordinate[i] = matrix * coordinate[i];
    }  
}

/**
 * @brief Translacja 
 * 
 * Argumenty:
 *      @param tmp 
 */
void Cuboid::translation(Vector <3> tmp)
{
    
    for(int i = 0; i < 8; i++)
    {
       coordinate[i] = tmp + coordinate[i];
    }  
}