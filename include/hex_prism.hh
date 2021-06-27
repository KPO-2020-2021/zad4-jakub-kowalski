#pragma once

#include "matrix.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include "scene_obj.hh"

class Hex_prism: public Scene_Obj {
protected:
    Vector3D coordinates[12];
public:
    Hex_prism();
    Hex_prism(Vector3D position, std::string hex_save, Matrix3D orientation);
    void rotate(Matrix3D rot_matrix);
    void translate(Vector3D trans_vec);
    void read_coordinates_from_file();
    void find_position(Vector3D corps_position);
    friend std::ostream & operator <<(std::ostream & x, Hex_prism &hex);
    const Vector3D & operator[](int index) const;
    Vector3D & operator[](int index);
    void set_position(Vector3D position);
};


