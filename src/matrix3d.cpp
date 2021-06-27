#include "matrix3d.hh"
#include "math.h"


/**
 * @brief Konstruktor bezparametryczny klasy Matrix3D, tworzy macierz obrotu wokol osi z
 * 
 */
Matrix3D::Matrix3D(){
    this->value[0][0] = 1;
    this->value[0][1] = 0;
    this->value[0][2] = 0;
    this->value[1][0] = 0;
    this->value[1][1] = 1;
    this->value[1][2] = 0;
    this->value[2][0] = 0;
    this->value[2][1] = 0;
    this->value[2][2] = 1;

}


/**
 * @brief Konstruktor parametryczny klasy Matrix3D, tworzy macierz rotacji
 * 
 * @param angle 
 * @param axis 
 */
Matrix3D::Matrix3D(double angle, char axis) {
    double angle_radians = (angle * M_PI) / 180;
    switch (axis) {
        case 'x':
            value[0][0] = 1;
            value[0][1] = 0;
            value[0][2] = 0;
            value[1][0] = 0;
            value[1][1] = cos(angle_radians);
            value[1][2] = -sin(angle_radians);
            value[2][0] = 0;
            value[2][1] = sin(angle_radians);
            value[2][2] = cos(angle_radians);
            break;

        case 'y':
            value[0][0] = cos(angle_radians);
            value[0][1] = 0;
            value[0][2] = sin(angle_radians);
            value[1][0] = 0;
            value[1][1] = 1;
            value[1][2] = 0;
            value[2][0] = -sin(angle_radians);
            value[2][1] = 0;
            value[2][2] = cos(angle_radians);
            break;

        case 'z':
            value[0][0] = cos(angle_radians);
            value[0][1] = -sin(angle_radians);
            value[0][2] = 0;
            value[1][0] = sin(angle_radians);
            value[1][1] = cos(angle_radians);
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


/**
 * @brief Przeciazenie operatora = dla klasy Matrix3D
 * 
 * @param matrix 
 * @return Matrix3D& 
 */
Matrix3D& Matrix3D::operator=(const Matrix3D matrix){
    for(int i = 0; i <3; ++i){
        for(int j = 0; j <3; ++j){
            this->value[i][j] = matrix.value[i][j];
        }
    }
    return *this;
}


/**
 * @brief Przeciazenie operatora = dla klasy Matrix3D
 * 
 * @param matrix 
 * @return Matrix3D& 
 */
Matrix3D& Matrix3D::operator=(const Matrix<3> matrix){
    for(int i = 0; i <3; ++i){
        for(int j = 0; j <3; ++j){
            this->value[i][j] = matrix.value[i][j];
        }
    }
    return *this;
}