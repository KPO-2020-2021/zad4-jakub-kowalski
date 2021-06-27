#include "scene_obj.hh"


/**
 * @brief Indeksowanie obiektow sceny
 * 
 * @param index 
 * @return Vector3D& 
 */
Vector3D &Scene_Obj::operator [] (int index){
    switch (index) {
        case 0:
            return this->coordinates[0];
        case 1:
            return this->coordinates[1];
        case 2:
            return this->coordinates[2];
        case 3:
            return this->coordinates[3];
        case 4:
            return this->coordinates[4];
        case 5:
            return this->coordinates[5];
        case 6:
            return this->coordinates[6];
        case 7:
            return this->coordinates[7];
        default:
            std::cout <<"Error";
            throw std::exception();

    }
}


/**
 * @brief Indeksowanie obiektow sceny
 * 
 * @param index 
 * @return const Vector3D& 
 */
const Vector3D &Scene_Obj::operator [] (int index) const{
    switch (index) {
        case 0:
            return this->coordinates[0];
        case 1:
            return this->coordinates[1];
        case 2:
            return this->coordinates[2];
        case 3:
            return this->coordinates[3];
        case 4:
            return this->coordinates[4];
        case 5:
            return this->coordinates[5];
        case 6:
            return this->coordinates[6];
        case 7:
            return this->coordinates[7];
        default:
            std::cout <<"Error";
            throw std::exception();

    }
}


/**
 * @brief Przeciazenie << dla Scene_Obj
 * 
 * @param strm 
 * @param scene_obj 
 * @return std::ostream& 
 */
std::ostream &operator <<(std::ostream &strm, Scene_Obj &scene_obj){
    strm << std::setprecision(10) << std::fixed;

    Vector3D tmp1 = scene_obj[2];
    tmp1 = tmp1 - scene_obj[0];
    tmp1 = tmp1 / 2;
    tmp1 = tmp1 + scene_obj[0];

    Vector3D tmp2 = scene_obj[6];
    tmp2 = tmp2 - scene_obj[4];
    tmp2 = tmp2 / 2;
    tmp2 = tmp2 + scene_obj[4];


    strm << tmp1 << std::endl;
    strm << scene_obj[2] << std::endl;
    strm << scene_obj[6] << std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << scene_obj[1]<< std::endl;
    strm << scene_obj[5]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << scene_obj[0]<< std::endl;
    strm << scene_obj[4]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << scene_obj[3]<< std::endl;
    strm << scene_obj[7]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << scene_obj[2]<< std::endl;
    strm << scene_obj[6]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    return strm;

}


/**
 * @brief Czyta wspolrzedne
 * 
 * @return std::string 
 */
std::string Scene_Obj::Read_coordinates(){
    return this->read_coordinates;
}


/**
 * @brief Zapisuje wspolrzedne;
 * 
 * @return std::string 
 */
std::string Scene_Obj::Save_coordinates(){
    return this->save_coordinates;
}


/**
 * @brief Zwraca srodek
 * 
 * @return Vector3D 
 */
Vector3D Scene_Obj::give_mid(){
    return this->mid;
}


/**
 * @brief Zwraca orientacje
 * 
 * @return Matrix3D 
 */
Matrix3D Scene_Obj::give_orientation(){
    return this->orientation;
}


/**
 * @brief Zwraca skale
 * 
 * @return Vector3D 
 */
Vector3D Scene_Obj::give_scale(){
    return this->scale;
}


/**
 * @brief Ustawia orientacje
 * 
 * @param matrix 
 */
void Scene_Obj::set_orientation(Matrix3D matrix){
    this->orientation = matrix;
}


/**
 * @brief Ustawia srodek
 * 
 * @param vector 
 */
void Scene_Obj::set_mid(Vector3D vector){
    this->mid = vector;
}


/**
 * @brief Ustawia skale
 * 
 * @param _scale 
 */
void Scene_Obj::set_scale(Vector3D _scale){
    this->scale = _scale;
}

