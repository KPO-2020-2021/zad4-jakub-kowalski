#include "hex_prism.hh"

Hex_prism::Hex_prism(){

}


/**
 * @brief Konstruktor parametryczny klasy Hex_prism
 * 
 * @param position 
 * @param hex_save 
 * @param orientation 
 */
Hex_prism::Hex_prism(Vector3D position, std::string hex_save, Matrix3D orientation){
    this->orientation = orientation;
    this->read_coordinates = "../datasets/hex_prism.dat";
    this->save_coordinates = hex_save;
    this->mid = position;
}


/**
 * @brief Realizuje rotacje graniastoslupa szeciokatnego o zadany kat
 * 
 * @param rot_matrix 
 */
void Hex_prism::rotate(Matrix3D rot_matrix){
    for(int i = 0; i < 12; i++)
        this->coordinates[i] = rot_matrix * this->coordinates[i];
}


/**
 * @brief Realizuje translacje graniastoslupa szeciokatnego o zadany kat
 * 
 * @param tmp 
 */
void Hex_prism::translate(Vector3D tmp){
    for(int i = 0; i < 12; i++)
        this->coordinates[i] = this->coordinates[i] + tmp;
}


/**
 * @brief Wczytuje wspolrzedne z pliku
 * 
 */
void Hex_prism::read_coordinates_from_file(){
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
 * @param corps_position 
 */
void Hex_prism::find_position(Vector3D corps_position){
    read_coordinates_from_file();

    for (int i = 0; i < 12; ++i){
        this->coordinates[i] = this->mid + this->coordinates[i];
    }
    for (int i = 0; i < 12; ++i){
        this->coordinates[i] = this->coordinates[i] - corps_position;
    }
    for (int i = 0; i < 12; ++i){
        this->coordinates[i] = this->orientation * this->coordinates[i];
    }
    for (int i = 0; i < 12; ++i){
        this->coordinates[i] = this->coordinates[i] + corps_position;
    }
}


/**
 * @brief Przeciazenie << dla Hex_prism
 * 
 * @param strm 
 * @param hex 
 * @return std::ostream& 
 */
std::ostream & operator <<(std::ostream & strm, Hex_prism &hex){
    strm << std::setprecision(10) << std::fixed;

    Vector3D tmp1 = hex[11];
    tmp1 = tmp1 - hex[8];
    tmp1 = tmp1 / 2;
    tmp1 = tmp1 + hex[8];

    Vector3D tmp2 = hex[5];
    tmp2 = tmp2 - hex[2];
    tmp2 = tmp2 / 2;
    tmp2 = tmp2 + hex[2];

    strm << tmp1 << std::endl;
    strm << hex[6] << std::endl;
    strm << hex[0] << std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[7]<< std::endl;
    strm << hex[1]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[8]<< std::endl;
    strm << hex[2]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[9]<< std::endl;
    strm << hex[3]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[10]<< std::endl;
    strm << hex[4]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[11]<< std::endl;
    strm << hex[5]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    strm << tmp1<< std::endl;
    strm << hex[6]<< std::endl;
    strm << hex[0]<< std::endl;
    strm << tmp2 << "\n#\n\n";

    return  strm;
}


/**
 * @brief Indeksowanie graniastoslupow szeciokatnych
 * 
 * @param index 
 * @return const Vector3D& 
 */
const Vector3D & Hex_prism::operator[](int index) const{

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
        case 8:
            return this->coordinates[8];
        case 9:
            return this->coordinates[9];
        case 10:
            return this->coordinates[10];
        case 11:
            return this->coordinates[11];

        default:
            std::cout <<"Error";
            throw std::exception();
    }
}


/**
 * @brief Indeksowanie graniastoslupow szeciokatnych
 * 
 * @param index 
 * @return Vector3D& 
 */
Vector3D & Hex_prism::operator[](int index){

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
        case 8:
            return this->coordinates[8];
        case 9:
            return this->coordinates[9];
        case 10:
            return this->coordinates[10];
        case 11:
            return this->coordinates[11];

        default:
            std::cout <<"Error";
            throw std::exception();
    }
}