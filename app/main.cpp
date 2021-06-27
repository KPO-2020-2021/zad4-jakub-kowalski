#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "example.h"
#include "exampleConfig.h.in"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 */

void ZapisDoStrumienia(std::ostream& StrmWy, Cuboid cuboid)

{
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << cuboid << std::endl; 
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisDoPliku(const char *sNazwaPliku, Cuboid cuboid)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisDoStrumienia(StrmPlikowy, cuboid);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

int main() {

double coordinate1[3] = {0, 0, 200};
double coordinate2[3] = {400, 0, 200};
double coordinate3[3] = {400, 300, 200};
double coordinate4[3] = {0, 300, 200};
double coordinate5[3] = {0, 300, 0};
double coordinate6[3] = {0, 0, 0};
double coordinate7[3] = {400, 0, 0};
double coordinate8[3] = {400, 300, 0};
Vector <3> coordinates[8] = {coordinate1, coordinate2, coordinate3, coordinate4, coordinate5, coordinate6, coordinate7, coordinate8};
Cuboid cuboid(coordinates);
std::cout << cuboid;

int choice;
PzG::LaczeDoGNUPlota  Lacze;
Lacze.DodajNazwePliku("cuboid.dat",PzG::RR_Ciagly,2);
Lacze.DodajNazwePliku("cuboid.dat",PzG::RR_Punktowy,2);
Lacze.ZmienTrybRys(PzG::TR_3D);
ZapisDoStrumienia(std::cout, cuboid);
if (!ZapisDoPliku("cuboid.dat",cuboid)) return 1;
Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

do{
  std::cout << "1. Translacja" << std::endl;
  std::cout << "2. Rotacja o zadany kat" << std::endl;
  std::cout << "3. Wyjscie" << std::endl;
  std::cout << "Podaj wybrana opcje:";
  std::cin >> choice;
  switch(choice)
  {
    case 1:
       {
       Vector <3> trans_vec;
       int x,y,z;
       std::cout << std::endl;
       std::cout << "Podaj wspolrzedna x wektora przesuniecia: ";
       std::cin >> x;
       std::cout << "Podaj wspolrzedna y wektora przesuniecia: ";
       std::cin >> y;
       std::cout << "Podaj wspolrzedna z wektora przesuniecia: ";
       std::cin >> z;
       trans_vec[0] = x;
       trans_vec[1] = y;
       trans_vec[2] = z;
       cuboid.translation(trans_vec);

       ZapisDoStrumienia(std::cout, cuboid);
       if (!ZapisDoPliku("cuboid.dat", cuboid)) return 1;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000,'\n');
    break;
        }
    
    case 2:
       {
       int angle, amount;
       char axis;
       std::cout << std::endl;
       std::cout << "Podaj kat obrotu w stopniach: ";
       std::cin >> angle;
       std::cout << std::endl;
       std::cout << "Podaj ilosc powtorzen obrotu o zadany kat: ";
       std::cin >> amount;
       std::cout << "Podaj os, wokol ktorej chcesz obrocic prostopadloscian: ";
       std::cin >> axis;
       Matrix <3> tmp;
       tmp.rotation_matrix(angle*amount, axis);
       cuboid.rotate(tmp);
       ZapisDoStrumienia(std::cout, cuboid);
       if (!ZapisDoPliku("cuboid.dat", cuboid)) return 1;
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000,'\n');      
       break;
       }

    case 3:
       {break;}
    
    default:
       {std::cout << std::endl << "Niepoprawna opcja" << std::endl;
       break;}
  }
}while(choice!=3);

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}