#include "scene.hh"
#include "obstacleT1.hh"
#include "hex_prism.hh"


/**
 * @brief Konstruktor bezparametryczny klasy Scene
 * 
 */
Scene::Scene(){

    this->drone_R = 6.5;
    this->obstacle_size = 12;
    this->drone_index = 0;
    Matrix3D orientation = Matrix3D();
    Vector3D drone1_position = Vector3D(20, 20, 1);
    Vector3D drone2_position = Vector3D(100, 20, 1);
    std::shared_ptr<Drone> dron1 = std::make_shared<Drone>("../datasets/corps1.dat","../datasets/rotor01.dat", "../datasets/rotor11.dat",
                          "../datasets/rotor21.dat", "../datasets/rotor31.dat", drone1_position,orientation);                   

    std::shared_ptr<Drone> dron2 = std::make_shared<Drone>("../datasets/corps2.dat","../datasets/rotor02.dat", "../datasets/rotor12.dat",
                                                                    "../datasets/rotor22.dat", "../datasets/rotor32.dat", drone2_position,orientation);     //tworzenie listy dronow
    this->all_drones.push_back(dron1);
    this->all_drones.push_back(dron2);

    Vector3D position1 = Vector3D(70, 20, 1);
    Vector3D position2 = Vector3D(170, 150, 1);
    Vector3D position3 = Vector3D(40, 120, 1);
    Vector3D position4 = Vector3D(15, 90, 1);
    Vector3D position5 = Vector3D(120, 100, 1);
    Vector3D scale = Vector3D(1,1,1);


    this->all_obstacles.push_back(dron1);
    this->all_obstacles.push_back(dron2);
    this->all_obstacles.push_back(std::make_shared<ObstacleT1>(position1,"../datasets/obstacleT1.dat", "../datasets/obstacleT1_draw.dat", scale));
    this->all_obstacles.push_back(std::make_shared<ObstacleT2>(position2,"../datasets/obstacleT2.dat", "../datasets/obstacleT2_draw.dat", scale));
    this->all_obstacles.push_back(std::make_shared<ObstacleT3>(position3,"../datasets/obstacleT3.dat", "../datasets/obstacleT3_draw.dat", scale));
    this->all_obstacles.push_back(std::make_shared<ObstacleT2>(position4,"../datasets/obstacleT2.dat", "../datasets/obstacleT4_draw.dat", scale));
    this->all_obstacles.push_back(std::make_shared<ObstacleT3>(position5,"../datasets/obstacleT1.dat", "../datasets/obstacleT5_draw.dat", scale));

    for(int j = 0; j < 2; ++j){     //Ustawienia rysowania
        this->all_drones[j]->find_position();
        gnuplot.DodajNazwePliku(this->all_drones[j]->give_corps().Save_coordinates().c_str())
                .ZmienSposobRys(PzG::SR_Ciagly)
                .ZmienSzerokosc(2)
                .ZmienKolor(1);

        for(int i = 0; i<4; ++i){
            gnuplot.DodajNazwePliku(this->all_drones[j]->give_rotor(i).Save_coordinates().c_str())
                    .ZmienSposobRys(PzG::SR_Ciagly)
                    .ZmienSzerokosc(2)
                    .ZmienKolor(1);
        }
    }


    for(int i = 2; i < this->all_obstacles.size(); ++i){
        gnuplot.DodajNazwePliku(this->all_obstacles[i]->Save_coordinates().c_str())
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(2)
            .ZmienKolor(2);
    }

    std::ofstream strm;
    strm.open("../datasets/flight_route.dat");
    strm.close();
    gnuplot.DodajNazwePliku("../datasets/flight_route.dat")
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(2)
            .ZmienKolor(1);

    strm.open("../datasets/scene.dat");
    strm.close();
    gnuplot.DodajNazwePliku("../datasets/scene.dat")
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(1)
            .ZmienKolor(3);


    gnuplot.ZmienTrybRys(PzG::TR_3D);
    gnuplot.UstawZakresX((0), 200);
    gnuplot.UstawZakresY((0), 200);
    gnuplot.UstawZakresZ((-10), 40);
}


/**
 * @brief Rysowanie sceny
 * 
 */
void Scene::draw_scene(){
    std::ofstream strm;
    for(int i = 2; i < this->all_obstacles.size(); ++i) {
        this->all_obstacles[i]->find_position();
        strm.open(this->all_obstacles[i]->Save_coordinates());
        strm << *(all_obstacles[i]);
        strm.close();
    }

    for(int j = 0; j < 2; ++j){
        Cuboid cub;
        Hex_prism hex;
        strm.open(this->all_drones[j]->give_corps().Save_coordinates());
        cub = this->all_drones[j]->give_corps();
        strm << cub;
        strm.close();

        for(int i = 0; i<4;++i){
            strm.open(this->all_drones[j]->give_rotor(i).Save_coordinates());
            hex = this->all_drones[j]->give_rotor(i);
            strm << hex;
            strm.close();
        }
    }

    strm.open("../datasets/scene.dat");
    for(int i = 0; i <= 200; i+=10){
        for(int j = 0; j <= 200; j += 10){
            strm << j << " " << i+10 << " 0\n";
            strm << j << " " << i << " 0\n";
            if(j < 200){
                strm << "#\n\n";
            }
        }
        strm << 0 << " " << i << " 0\n#\n\n";
    }
    strm.close();

    gnuplot.Inicjalizuj();
    gnuplot.Rysuj();
}


/**
 * @brief Animacja drona, lot o zadana dlugosc pod zadanym katem
 * 
 * @param length 
 * @param angle 
 */
void Scene::flight_animation(double length, double angle){

    Vector3D flight_vec = Vector3D(length, 0 ,0);
    Matrix3D direction = Matrix3D(angle, 'z');
    flight_vec = direction * flight_vec;


    all_drones[this->drone_index]->rotate(direction);
    draw_scene();
    Vector3D tmp_vec;
    tmp_vec = flight_vec / flight_vec.length();
    std::ofstream strm;

    while(check_route(flight_vec)){
        save_flight_route(flight_vec, 20);
        flight_vec = flight_vec + tmp_vec;
        usleep(100);
        draw_scene();
    }

    save_flight_route(flight_vec, 20);

    fly_up(20);


    Vector3D animation_vec = tmp_vec;
    Matrix3D animation_matrix = Matrix3D(15, 'z');
    Matrix3D small_angle = Matrix3D(15,'z');

    while(animation_vec.length() < flight_vec.length()){
        all_drones[this->drone_index]->translate(tmp_vec);
        animation_vec = animation_vec + tmp_vec;
        usleep(50000);
        all_drones[this->drone_index]->find_position();
        draw_scene();


        for(int k = 0; k < 10; ++k) {
            this->all_drones[this->drone_index]->rotors_rotation(animation_matrix);
            animation_matrix = small_angle * animation_matrix;
            draw_scene();
            usleep(1000);
        }
    }


    fly_up(-20);

    strm.open("../datasets/flight_route.dat");
    strm.close();
}


/**
 * @brief Indeksowanie dronow z listy
 * 
 * @param index 
 */
void Scene::set_index(int index){
    this->drone_index = index;
}


/**
 * @brief Lot drona w pionie 
 * 
 * @param hight 
 */
void Scene::fly_up(double hight){
    Vector3D flight_vec = Vector3D(0,0,hight);
    Vector3D tmp_vec;
    tmp_vec = flight_vec / flight_vec.length();
    Vector3D animation_vec = tmp_vec;
    Matrix3D animation_matrix = Matrix3D(15, 'z');
    Matrix3D small_angle = Matrix3D(15,'z');

    while(animation_vec.length() < flight_vec.length()){
        all_drones[this->drone_index]->translate(tmp_vec);
        animation_vec = animation_vec + tmp_vec;
        usleep(50000);
        all_drones[this->drone_index]->find_position();
        draw_scene();

        /*ruch rotora*/
        for(int k = 0; k < 10; ++k) {
            this->all_drones[this->drone_index]->rotors_rotation(animation_matrix);
            animation_matrix = small_angle * animation_matrix;
            draw_scene();
            usleep(500);
        }
    }
}


/**
 * @brief Zapis linii lotu drona
 * 
 * @param flight_vec 
 * @param hight 
 */
void Scene::save_flight_route(Vector3D &flight_vec, double hight){
    Vector3D vec1;
    Vector3D vec2;
    std::ofstream strm;

    strm.open("../datasets/flight_route.dat");
    vec1 = this->all_drones[this->drone_index]->give_corps().give_mid();
    strm << vec1 << std::endl;
    vec2 = Vector3D(0,0,hight);
    vec2 = vec2 + vec1;
    strm << vec2 << std::endl;
    vec2 = vec2 + flight_vec;
    strm << vec2 <<std::endl;
    vec1 = Vector3D(0,0,hight);
    vec2 = vec2 - vec1;
    strm << vec2 << std::endl;
    strm.close();
}


/**
 * @brief Dodawanie kolejnych przeszkod do sceny
 * 
 * @param x 
 * @param y 
 * @param type 
 * @param obstacle_name 
 */
void Scene::add_obstacle(double x, double y, char type, std::string obstacle_name){

    Vector3D position = Vector3D(x,y,1);
    Vector3D scale = Vector3D(1,1,1);
    obstacle_name = std::string("../datasets/") + obstacle_name + std::string(".dat");

    switch (type) {
        case '1':
            this->all_obstacles.push_back(std::make_shared<ObstacleT1>(position ,"../datasets/obstacleT1.dat", obstacle_name.c_str(), scale));
            break;
        case '2':
            this->all_obstacles.push_back(std::make_shared<ObstacleT2>(position ,"../datasets/obstacleT2.dat", obstacle_name.c_str(), scale));
            break;
        case '3':
            this->all_obstacles.push_back(std::make_shared<ObstacleT3>(position ,"../datasets/obstacleT3.dat", obstacle_name.c_str(), scale));
            break;;
        default:
            break;

    }

    std::ofstream strm;
    strm.open(obstacle_name);
    strm.close();
    gnuplot.DodajNazwePliku(this->all_obstacles.back()->Save_coordinates().c_str())
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(1)
            .ZmienKolor(1);

    this->all_obstacles.back()->find_position();
    draw_scene();

}


/**
 * @brief Usuwanie obiektow ze sceny
 * 
 * @param index 
 */
void Scene::remove_obstacle(int index){

    std::ofstream strm;

    switch (index) {
        case 0:         //Indeksy 0 oraz 1 sa przypisane do dronow, ktorych nie mozna usuwac
            throw std::exception();
            break;
        case 1:
            throw std::exception();
            break;
        default:
            strm.open(this->all_obstacles[index]->Save_coordinates());
            strm.close();
            break;
    }
    this->all_obstacles.erase(this->all_obstacles.begin() + index);
}


/**
 * @brief Sprawdzenie czy podczas lotu doszloby do kolizji
 * 
 * @param route 
 * @return true 
 * @return false 
 */
bool Scene::check_route(Vector3D &route){
    Vector3D new_position = this->all_drones[this->drone_index]->give_mid();
    new_position = new_position + route;


    for(int i = 0; i < this->all_obstacles.size(); ++i){
        if((abs(new_position[0] - this->all_obstacles[i]->give_mid()[0]) < this->drone_R + this->obstacle_size)&&
                (abs(new_position[1] - this->all_obstacles[i]->give_mid()[0]) < this->drone_R + this->obstacle_size)){
            return true;
        }
    }
    return false;
}

