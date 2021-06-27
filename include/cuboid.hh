#pragma once
#include "scene_obj.hh"
#include "matrix3d.hh"

class Cuboid: public Scene_Obj{
protected:
    Vector3D _coordinates[8];
public:
    Cuboid();
    Cuboid(Vector3D position, std::string cuboid_save, Matrix3D orientation);
    void read_coordinates_from_file();
    void find_position();
    void translate(Vector3D trans_vec);
    void rotate(Matrix3D rot_matrix);
    friend std::ostream & operator <<(std::ostream & x, Cuboid &cuboid);
    const Vector3D & operator[](int index) const;
    Vector3D & operator[](int index);
};