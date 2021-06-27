#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "exampleConfig.h"
#include "exampleConfig.h.in"
#include "scene.hh"

void show_menu();

int main() {

    Scene scene = Scene();
    char choice;
    int obstacle_index;
    int drone_choice;
    double angle;
    double obstacle_x, obstacle_y;
    double flight_length;
    char obstacle_type;
    std::string obstacle_name;
    
    do {
        show_menu();
        scene.draw_scene();
        std::cin >> choice;
        switch (choice){
        case 'c': 
        {
            std::cout << "Wybierz drona 1 lub 2" << std::endl;
            std::cin >> drone_choice;
                if (drone_choice == 1){
                    scene.draw_scene();
                    scene.set_index(0);
                }
                else if (drone_choice == 2){
                    scene.draw_scene();
                    scene.set_index(1);
                    }
                else
                    {std::cout << "Drony maja indeksy 1 lub 2! Wpisz poprawny indeks." << std::endl;}
            break;
        }

        case 'a': 
        {
            std::cout << "Podaj wspolrzedna x: ";
            std::cin >> obstacle_x;
            std::cout << "Podaj wspolrzedna y: ";
            std::cin >> obstacle_y;
            std::cout << "Typy przeszkod: " << std::endl;
            std::cout << "1 - PROSTOPADLOSCIAN" << std::endl;
            std::cout << "2 - OSTROSLUP" << std::endl;
            std::cout << "3 - GRANIASTOSLUP TROJKATNY" << std::endl << std::endl;
            std::cout << "Podaj typ przeszkody: " << std::endl;
            std::cin >> obstacle_type;
            std::cout << "Podaj nazwe przeszkody " << std::endl;
            std::cin >> obstacle_name;
            scene.add_obstacle(obstacle_x, obstacle_y, obstacle_type, obstacle_name);
            break;
        }

        case 'r': 
        {
            std::cout << "PRZESZKODY ZACZYNAJA SIE OD INDEKSU 2!" << std::endl << std::endl;
            std::cout << "Podaj indeks przeszkody, ktora chcesz usunac: ";
            std::cin >> obstacle_index;
            scene.remove_obstacle(obstacle_index);
            break;
        }

        case 'l': 
        {
            for(int i = 2; i < (int)scene.all_obstacles.size(); ++i){
                std::cout << i <<": "<< scene.all_obstacles[i]->obstacle_type() << " " << scene.all_obstacles[i]->give_mid() << std::endl;
            }
            break;
        }

        case 'f': 
        {
            std::cout << "Podaj dlugosc lotu: ";
            std::cin >> flight_length;
            std::cout << "Podaj kat, o jaki chcesz obrocic drona: \n";
            std::cin >> angle;
            scene.flight_animation(flight_length, angle);
            break;
        }

        case 'm': 
        {
            show_menu();
            break;
        }

        case 'v': 
        {
            Vector3D obstacle_position;
            std::cout << "Aktualna ilosc wektorow:" << obstacle_position.give_vectors_now() << std::endl;
            std::cout << "Ile bylo wektorow w ogole:" << obstacle_position.give_all_vectors() << std::endl;
            break;
        }

        case 'q':
        {
            std::cout << "Koniec dzialania programu." << std::endl;
        }

        default: 
            {break;}
        }
    }while(choice != 'q');
}


void show_menu(){
    std::cout << "Funkcje programu: " << std::endl;
    std::cout << "m - POKAZ MENU" << std::endl;
    std::cout << "c - WYBIERZ DRONA DO LOTU(DOMYSLNIE 0)" << std::endl;
    std::cout << "a - DODAJ KOLEJNA PRZESZKODE DO SCENY" << std::endl;
    std::cout << "r - USUN PRZESZKODE ZE SCENY" << std::endl;
    std::cout << "l - LISTA PRZESZKOD NA SCENIE" << std::endl;
    std::cout << "f - WYKONAJ LOT DRONEM O ZADANA DLUGOSC I KAT" << std::endl;
    std::cout << "v - POKAZ ILOSC WEKTOROW" << std::endl;
    std::cout << "q - WYJSCIE Z PROGRAMU" << std::endl;
    std::cout << "Twoj wybor: ";
}