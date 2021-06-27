#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "cuboid.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.


TEST_CASE("Test konstruktora bezparametrycznego dla Vector'a") {
    
    Vector<3> wektor_bezparam;
    wektor_bezparam = Vector<3>();

   CHECK(wektor_bezparam[0]==0);
}

TEST_CASE("Test konstruktora parametrycznego dla Vector'a") {
    
    Vector<3> wektor_param;
    double tmp[3];
    tmp[0]={21};
    tmp[1]={37};
    tmp[2]={42};
    wektor_param = Vector<3>(tmp);
   CHECK(wektor_param[2]==42);
}

TEST_CASE("Test dodawania dwoch wektorow") {
    
    Vector<3> wynik, wektor, wektor2;
    wektor[0]=2; wektor[1]=1; wektor[2]=4;
    wektor2[0]=3; wektor2[1]=7; wektor2[2]=2;
    wynik=wektor+wektor2;
   CHECK(wynik[0]==(5));
   CHECK(wynik[1]==(8));
   CHECK(wynik[2]==(6));
}
TEST_CASE("Test odejmowania dwoch wektorow") {
    
    Vector<3> wynik, wektor, wektor2;
    wektor[0]=2; wektor[1]=1; wektor[2]=4;
    wektor2[0]=3; wektor2[1]=7; wektor2[2]=2;
    wynik=wektor-wektor2;
   CHECK(wynik[0]==(-1));
   CHECK(wynik[1]==(-6));
   CHECK(wynik[2]==(2));
}
TEST_CASE("Test konstruktora bezparametrycznego dla Macierzy") {
    
    Matrix<3> macierz_bezparam;
    macierz_bezparam = Matrix<3>();

   CHECK(macierz_bezparam(0,0)==0);
}

TEST_CASE("Test konstruktora parametrycznego dla Macierzy") {
    
    Matrix<3> macierz_param;
    double tmp[3][3];
    tmp[0][0]={77};
    tmp[0][1]={33};
    tmp[0][2]={11};
    tmp[1][0]={69};
    tmp[1][1]={37};
    tmp[1][2]={21};
    tmp[2][0]={20};
    tmp[2][1]={37};
    tmp[2][2]={22};

    macierz_param = Matrix<3>(tmp);
   CHECK(macierz_param(1,0)==69);
}

TEST_CASE("Test mnozenia macierzy przez wektor") {
    Vector<3> wektor, wynik;
    wektor[0]=0;
    wektor[1]=0;
    wektor[2]=0;
    Matrix<3> macierz;
    macierz(0,0) = 1;
    macierz(0,1) = 2;
    macierz(0,2) = 3;
    macierz(1,0) = 4;
    macierz(1,1) = 1;
    macierz(1,2) = 2;
    macierz(2,0) = 3;
    macierz(2,1) = 4;
    macierz(2,2) = 4;

    wynik=macierz*wektor;
   CHECK(wynik[1]==0);
}