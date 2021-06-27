#include "drone.hh"

Drone::Drone(){

}


/**
 * @brief Konstruktor parametryczny klasy Drone
 * 
 * @param corps_name 
 * @param rotor0_name 
 * @param rotor1_name 
 * @param rotor2_name 
 * @param rotor3_name 
 * @param mid 
 * @param orientation 
 */
Drone::Drone(std::string corps_name, std::string rotor0_name,
             std::string rotor1_name, std::string rotor2_name, std::string rotor3_name,
             Vector3D mid, Matrix3D orientation){

    Vector3D move_up = Vector3D(0,0,1);
    this->corps = Cuboid(mid, corps_name,orientation);
    this->corps.find_position();
    Vector3D position_rotor = this->corps[3];
    position_rotor = position_rotor + move_up;
    this->rotors[0] = Hex_prism(position_rotor,rotor0_name,orientation);
    position_rotor = this->corps[2];
    position_rotor = position_rotor + move_up;
    this->rotors[1] = Hex_prism(position_rotor,rotor1_name,orientation);
    position_rotor = this->corps[6];
    position_rotor = position_rotor + move_up;
    this->rotors[2] = Hex_prism(position_rotor,rotor2_name,orientation);
    position_rotor = this->corps[7];
    position_rotor = position_rotor + move_up;
    this->rotors[3] = Hex_prism(position_rotor,rotor3_name,orientation);

    this->mid = this->corps.give_mid();
}


/**
 * @brief Translacja drona o wektor
 * 
 * @param trans_vec 
 */
void Drone::translate(Vector3D trans_vec){
    Vector3D tmp;
    tmp = this->mid + trans_vec;
    corps.set_mid(tmp);

    tmp = this->rotors[0].give_mid();
    tmp = tmp + trans_vec;
    rotors[0].set_mid(tmp);

    tmp = this->rotors[1].give_mid();
    tmp = tmp + trans_vec;
    rotors[1].set_mid(tmp);

    tmp = this->rotors[2].give_mid();
    tmp = tmp + trans_vec;
    rotors[2].set_mid(tmp);

    tmp = this->rotors[3].give_mid();
    tmp = tmp + trans_vec;
    rotors[3].set_mid(tmp);

}


/**
 * @brief Rotacja drona o zadany kat
 * 
 * @param rot_matrix 
 */
void Drone::rotate(Matrix3D rot_matrix){
    Matrix3D tmp;
    tmp = this->corps.give_orientation();
    tmp = rot_matrix * tmp;
    this->corps.set_orientation(tmp);

    tmp = this->rotors[0].give_orientation();
    tmp = rot_matrix * tmp;
    this->rotors[0].set_orientation(tmp);

    tmp = this->rotors[1].give_orientation();
    tmp = rot_matrix * tmp;
    this->rotors[1].set_orientation(tmp);

    tmp = this->rotors[2].give_orientation();
    tmp = rot_matrix * tmp;
    this->rotors[2].set_orientation(tmp);

    tmp = this->rotors[3].give_orientation();
    tmp = rot_matrix * tmp;
    this->rotors[3].set_orientation(tmp);


}


/**
 * @brief Szukanie wspolrzednych
 * 
 */
void Drone::find_position(){
    this->corps.find_position();
        for(int i = 0; i < 4; ++i){
            this->rotors[i].find_position(this->corps.give_mid());
        }
    this->mid = this->corps.give_mid();
}


/**
 * @brief Zwrocenie korpusu drona
 * 
 * @return Cuboid 
 */
Cuboid Drone::give_corps(){
    return corps;
}


/**
 * @brief Zwrocenie wybranego rotora drona
 * 
 * @param index 
 * @return Hex_prism 
 */
Hex_prism Drone::give_rotor(int index){
    return rotors[index];
}


/**
 * @brief Zwrocenie typu przeszkody
 * 
 * @return std::string 
 */
std::string Drone::obstacle_type(){
    return std::string("dron");
}


/**
 * @brief Realizuje rotacje rotorow drona
 * 
 * @param rot_matrix 
 */
void Drone::rotors_rotation(Matrix3D rot_matrix){
    Vector3D tmp;
    Vector3D position;
    Vector3D corps_position = this->corps.give_mid();

    for(int j = 0; j<4; ++j){
        this->rotors[j].read_coordinates_from_file();
        this->rotors[j].rotate(rot_matrix);
        position = this->rotors[j].give_mid();
        position = position - corps_position;
        this->rotors[j].translate(position);
        this->rotors[j].rotate(this->rotors[j].give_orientation());
        this->rotors[j].translate(this->corps.give_mid());
    }

}