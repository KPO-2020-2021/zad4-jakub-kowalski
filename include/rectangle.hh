#pragma once

#include "vector.hh"
#include "matrix.hh"
#include <iostream>

template <int SIZE>
class Cuboid{

private:    
    
    Vector coordinate[4];

public:

    Cuboid();
    Cuboid(Vector tmp[4]);
    friend std::ostream & operator << (std::ostream & strm, const Cuboid &cuboid);
    void rotate(Matrix matrix);
    void translation(Vector tmp);

};

template <int SIZE>
Cuboid<SIZE>::Cuboid()
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = 0;
    }
}

template <int SIZE>
std::ostream & operator << (std::ostream & strm, const Cuboid<SIZE> &cuboid)
{
    strm << rectangle.coordinate[0][0] << " " << rectangle.coordinate[0][1] << std::endl;
    strm << rectangle.coordinate[1][0] << " " << rectangle.coordinate[1][1] << std::endl;
    strm << rectangle.coordinate[2][0] << " " << rectangle.coordinate[2][1] << std::endl;
    strm << rectangle.coordinate[3][0] << " " << rectangle.coordinate[3][1] << std::endl;
    strm << rectangle.coordinate[0][0] << " " << rectangle.coordinate[0][1] << std::endl;
    return strm;
}

template <int SIZE>
Cuboid<SIZE>::Cuboid(Vector tmp[4])
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = tmp[i];
    }
}

template <int SIZE>
void Cuboid<SIZE>::rotate(Matrix matrix)
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = matrix * coordinate[i];
    }  
}

template <int SIZE>
void Cuboid<SIZE>::translation(Vector tmp)
{
    
    for(int i = 0; i < 4; i++)
    {
       coordinate[i] = tmp + coordinate[i];
    }  
}