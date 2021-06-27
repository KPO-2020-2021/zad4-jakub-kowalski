#pragma once
#include "matrix.hh"
class Matrix3D: public Matrix<3>{
public:
    Matrix3D();
    Matrix3D(double angle, char axis);
    Matrix3D& operator=(const Matrix3D matrix);
    Matrix3D& operator=(const Matrix<3> matrix);
};

