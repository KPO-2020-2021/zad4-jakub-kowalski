#include "cuboid.hh"

Cuboid::Cuboid(){

}


/**
 * @brief Konstruktor parametryczny klasy Cuboid
 * 
 * @param position 
 * @param cuboid_save 
 * @param orientation 
 */
Cuboid::Cuboid(Vector3D position, std::string cuboid_save, Matrix3D orientation){
    this->orientation = orientation;
    this->read_coordinates = "../datasets/cuboid.dat";
    this->save_coordinates = cuboid_save;
    this->mid = position;
}


/**
 * @brief Wczytuje wspolrzedne z pliku
 * 
 */
void Cuboid::read_coordinates_from_file(){
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
void Cuboid::find_position(){
    read_coordinates_from_file();
    for (int i = 0; i < 8; ++i){
        this->coordinates[i] = this->orientation * this->coordinates[i];
    }
    for (int i = 0; i < 8; ++i){
        this->coordinates[i] = this->mid + this->coordinates[i];
    }
}


/**
 * @brief Translacja prostopadloscinu o wektor
 * 
 * @param trans_vec 
 */
void Cuboid::translate(Vector3D trans_vec){
    for(int i = 0; i < 8; i++) {
        this->coordinates[i] = this->coordinates[i] + trans_vec;
    }
}


/**
 * @brief Rotacja prostopadloscianu o zadany kat
 * 
 * @param rot_matrix 
 */
void Cuboid::rotate(Matrix3D rot_matrix){
    for(int i = 0; i < 8; i++)
        this->coordinates[i] = rot_matrix * this->coordinates[i];
}


/**
 * @brief Przeciazenie << dla Cuboida
 * 
 * @param strm 
 * @param cuboid 
 * @return std::ostream& 
 */
std::ostream & operator <<(std::ostream & strm, Cuboid &cuboid){
    strm << std::setprecision(10) << std::fixed;

    Vector3D tmp1 = cuboid[2];
    tmp1 = tmp1 - cuboid[0];
    tmp1 = tmp1 / 2;
    tmp1 = tmp1 + cuboid[0];

    Vector3D tmp2 = cuboid[6];
    tmp2 = tmp2 - cuboid[4];
    tmp2 = tmp2 / 2;
    tmp2 = tmp2 + cuboid[4];


    strm << tmp1 << std::endl;
    strm << cuboid[2] << std::endl;
    strm << cuboid[6] << std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << cuboid[1]<< std::endl;
    strm << cuboid[5]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << cuboid[0]<< std::endl;
    strm << cuboid[4]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << cuboid[3]<< std::endl;
    strm << cuboid[7]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << cuboid[2]<< std::endl;
    strm << cuboid[6]<< std::endl;
    strm << tmp2 << "\n#\n\n";


    return strm;
}


/**
 * @brief Indeksowanie Cuboida
 * 
 * @param index 
 * @return const Vector3D& 
 */
const Vector3D & Cuboid::operator[](int index) const{
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
 * @brief Indeksowanie Cuboida
 * 
 * @param index 
 * @return Vector3D& 
 */
Vector3D & Cuboid::operator[](int index){

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
