#pragma once
#include "scene_obj.hh"

class ObstacleT1: public Scene_Obj{
public:
    ObstacleT1(Vector3D position, std::string read_ObT1, std::string save_ObT1, Vector3D _scale);
    void read_coordinates_from_file() override;
    void find_position() override;
    std::string obstacle_type() override;
};