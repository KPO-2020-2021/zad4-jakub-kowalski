#include "vector3d.hh"
#include <cmath>

int Vector3D::vectors_now = 0;
int Vector3D::all_vectors = 0;

Vector3D::Vector3D() {
    all_vectors ++;
    vectors_now ++;
    this->tab[0] = 0;
    this->tab[1] = 0;
    this->tab[2] = 0;
}
Vector3D::Vector3D(double x, double y, double z) {
    all_vectors ++;
    vectors_now ++;
    this->tab[0] = x;
    this->tab[1] = y;
    this->tab[2] = z;
}

Vector3D::Vector3D(const Vector3D &vector){
    all_vectors ++;
    vectors_now ++;
    this->tab[0] = vector.tab[0];
    this->tab[1] = vector.tab[1];
    this->tab[2] = vector.tab[2];
}

Vector3D::~Vector3D() {
    vectors_now --;
}

Vector3D& Vector3D::operator=(const Vector3D vector){
    this->tab[0] = vector[0];
    this->tab[1] = vector[1];
    this->tab[2] = vector[2];
    return *this;
}
Vector3D& Vector3D::operator=(const Vector<3> vector){
    this->tab[0] = vector[0];
    this->tab[1] = vector[1];
    this->tab[2] = vector[2];
    return *this;
}

int Vector3D::give_all_vectors(){
    return all_vectors;
}

int Vector3D::give_vectors_now(){
    return vectors_now;
}

double Vector3D::length(){
    double dlg = sqrt(pow(tab[0],2) + pow(tab[1],2)+pow(tab[2],2));
    return dlg;
}