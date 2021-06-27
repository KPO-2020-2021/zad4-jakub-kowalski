#pragma once
#include "vector3d.hh"
#include "matrix3d.hh"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

class Scene_Obj{
protected:
    std::string read_coordinates;
    std::string save_coordinates;
    Vector3D coordinates[8];
    Vector3D mid;
    Matrix3D orientation;
    Vector3D scale;
public:
    Vector3D &operator [] (int index);
    const Vector3D &operator [] (int index) const;
    virtual void read_coordinates_from_file(){};
    virtual void find_position() {};
    virtual std::string obstacle_type(){return std::string("");};
    friend std::ostream &operator <<(std::ostream& strm, Scene_Obj &objekt);
    std::string Read_coordinates();
    std::string Save_coordinates();
    Vector3D give_mid();
    Matrix3D give_orientation();
    Vector3D give_scale();
    void set_orientation(Matrix3D matrix);
    void set_mid(Vector3D vector);
    void set_scale(Vector3D _scale);


};

