#include "obstacleT3.hh"


/**
 * @brief Konstruktor parametryczny klasy ObstacleT2
 * 
 * @param position 
 * @param read_ObT3 
 * @param save_ObT3 
 * @param _scale 
 */
ObstacleT3::ObstacleT3(Vector3D position, std::string read_ObT3, std::string save_ObT3, Vector3D _scale)
{
    this->orientation = Matrix3D();
    this->mid = position;
    this->read_coordinates = read_ObT3;
    this->save_coordinates = save_ObT3;
    this->scale = _scale;

}


/**
 * @brief Wczytuje wspolrzedne z pliku
 * 
 */
void ObstacleT3::read_coordinates_from_file()
{

    std::ifstream file;
    std::string tmp;
    std::stringstream tmp_strm;
    int i = 0;
    file.open(this->read_coordinates);

    while (getline(file,tmp)){
        tmp_strm << tmp;
        tmp_strm >> this->coordinates[i];
        i++;
        tmp_strm = std::stringstream();
    }
    file.close();
}


/**
 * @brief Szuka wspolrzednych
 * 
 */
void ObstacleT3::find_position()
{
    read_coordinates_from_file();
    for (int i = 0; i < 8; ++i){
        this->coordinates[i] = this->orientation * (this->coordinates[i]);
    }
    for (int i = 0; i < 8; ++i){
        this->coordinates[i] = this->mid + this->coordinates[i];
    }
}


/**
 * @brief Zwraca typ przeszkody
 * 
 * @return std::string 
 */
std::string ObstacleT3::obstacle_type()
{
    return std::string("Obstacle3");
}


