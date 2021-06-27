#pragma once
#include "scene_obj.hh"
#include "cuboid.hh"
#include "hex_prism.hh"
#include "matrix3d.hh"

class Drone: public Scene_Obj{
protected:
    Cuboid corps;
    Hex_prism rotors[4];
public:
    Drone();
    Drone(std::string corps_name, std::string rotor0_name,
             std::string rotor1_name, std::string rotor2_name, std::string rotor3_name,
             Vector3D mid, Matrix3D orientation);
    void translate(Vector3D trans_vec);
    void rotate(Matrix3D rot_matrix);
    void find_position();
    Hex_prism give_rotor(int index);
    Cuboid give_corps();
    std::string obstacle_type() override;
    void rotors_rotation(Matrix3D rot_matrix);
};