#pragma once
#include "scene_obj.hh"
#include "lacze_do_gnuplota.hh"
#include <memory>
#include <vector>
#include <fstream>
#include "unistd.h"
#include "drone.hh"
#include "obstacleT2.hh"
#include "obstacleT3.hh"

class Scene{
private:
    Drone drone;
    std::vector<std::shared_ptr<Drone>> all_drones;
    PzG::LaczeDoGNUPlota gnuplot;
    int drone_index;
    double drone_R;
    double obstacle_size;
public:
    std::vector<std::shared_ptr<Scene_Obj>> all_obstacles;
    Scene();
    void draw_scene();
    void set_index(int index);
    void flight_animation(double length, double angle);
    void fly_up(double hight);
    void save_flight_route(Vector3D &flight_vec, double hight);
    void add_obstacle(double x, double y, char type, std::string obstacle_name);
    void remove_obstacle(int index);
    bool check_route(Vector3D &route);
};
