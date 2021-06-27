#pragma once
#include "scene_obj.hh"

class ObstacleT3: public Scene_Obj{
public:
    ObstacleT3(Vector3D position, std::string read_ObT3, std::string save_ObT3, Vector3D _scale);
    void read_coordinates_from_file() override;
    void find_position() override;
    std::string obstacle_type() override;
};