#pragma once
#include "vector.hh"

class Vector3D: public Vector<3>{
private:
    static int all_vectors;
    static int vectors_now;
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D &vector);
    ~Vector3D();
    Vector3D& operator=(const Vector3D vektor);
    Vector3D& operator=(const Vector<3> vektor);
    static int give_all_vectors();
    static int give_vectors_now();
    double length();

};
