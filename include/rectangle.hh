#pragma once

#include "size.hh"
#include "vector.hh"
#include "matrix.hh"
#include <iostream>

class Rectangle{

private:    
    
    Vector coordinate[4];

public:

    Rectangle();
    Rectangle(Vector tmp[4]);
    friend std::ostream & operator << (std::ostream & strm, const Rectangle &rectangle);
    void rotate(Matrix matrix);
    void translation(Vector tmp);

};

Rectangle::Rectangle()
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = 0;
    }
}

std::ostream & operator << (std::ostream & strm, const Rectangle &rectangle)
{
    strm << rectangle.coordinate[0][0] << " " << rectangle.coordinate[0][1] << std::endl;
    strm << rectangle.coordinate[1][0] << " " << rectangle.coordinate[1][1] << std::endl;
    strm << rectangle.coordinate[2][0] << " " << rectangle.coordinate[2][1] << std::endl;
    strm << rectangle.coordinate[3][0] << " " << rectangle.coordinate[3][1] << std::endl;
    strm << rectangle.coordinate[0][0] << " " << rectangle.coordinate[0][1] << std::endl;
    return strm;
}

Rectangle::Rectangle(Vector tmp[4])
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = tmp[i];
    }
}

void Rectangle::rotate(Matrix matrix)
{
    for(int i = 0; i < 4; i++)
    {
        coordinate[i] = matrix * coordinate[i];
    }  
}

void Rectangle::translation(Vector tmp)
{
    
    for(int i = 0; i < 4; i++)
    {
       coordinate[i] = tmp + coordinate[i];
    }  
}