#pragma once
#include "scene_obj.hh"

class ObstacleT2: public Scene_Obj{
public:
    ObstacleT2(Vector3D position, std::string read_ObT2, std::string save_ObT2, Vector3D _scale);
    void read_coordinates_from_file() override;
    void find_position() override;
    std::string obstacle_type() override;
};