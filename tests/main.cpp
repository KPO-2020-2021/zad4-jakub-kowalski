#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "cuboid.hh"
#include "matrix.hh"

TEST_CASE("Konstruktor Vector()") {

Vector<3> vector;
vector = Vector<3>();

CHECK(vector[2]==0);
}

TEST_CASE("Konstruktor Vector(double tmp[SIZE])") {

Vector<3> vector;
double tmp[3];
tmp[0] = 1;
tmp[1] = 2;
tmp[2] = 3;
vector = Vector<3>(tmp);

CHECK(vector[2]==3);
}

TEST_CASE("Dodawanie wektorow") {

Vector<3> vector1, vector2, result;
vector1[0] = 5;
vector1[1] = 4;
vector1[2] = 1;
vector2[0] = 4;
vector2[1] = 3;
vector2[2] = 1;
result[0] = 0;
result[1] = 0;
result[2] = 0;
result = vector1 + vector2;

CHECK(result[0] == 9);
CHECK(result[1] == 7);
CHECK(result[2] == 2);
}

TEST_CASE("Odejmowanie wektorow") {

Vector<3> vector1, vector2, result;
vector1[0] = 5;
vector1[1] = 4;
vector1[2] = 3;
vector2[0] = 4;
vector2[1] = 3;
vector2[2] = 2;
result[0] = 0;
result[1] = 0;
result[1] = 0;
result = vector1 - vector2;

CHECK(result[0] == 1);
CHECK(result[1] == 1);
CHECK(result[2] == 1);
}

TEST_CASE("Konstruktor Matrix()") {

Matrix<3> matrix;
matrix = Matrix<3>();

CHECK(matrix(1,1) == 0);
}

TEST_CASE("Konstruktor Matrix(double [SIZE][SIZE])") {

Matrix<3> matrix;
double tmp[3][3];
tmp[0][0] = 2;
tmp[0][1] = 3;
tmp[0][2] = 5;
tmp[1][0] = 4;
tmp[1][1] = 2;
tmp[1][2] = 3;
tmp[2][0] = 5;
tmp[2][1] = 4;
tmp[2][2] = 4;
matrix = Matrix<3>(tmp);

CHECK(matrix(0,0) == 2);
CHECK(matrix(1,1) == 2);
CHECK(matrix(2,2) == 4);
}

TEST_CASE("Macierz razy wektor") {

Matrix<3> matrix;
matrix(0,0) = 2;
matrix(0,1) = 1;
matrix(0,2) = 3;
matrix(1,0) = 7;
matrix(1,1) = 2;
matrix(1,2) = 1;
matrix(2,0) = 3;
matrix(2,1) = 7;
matrix(2,2) = 2;

Vector<3> vector, result;
vector[0] = 1;
vector[1] = 1;
vector[2] = 1;

result = matrix * vector;

CHECK(result[1] == 10);
CHECK(result[2] == 12);
CHECK(result[3] == 0);
}

TEST_CASE("Macierz obrotu") {

Matrix<3> matrix;
char axis = 'x';
float angle_degrees = 90;
matrix.rotation_matrix(angle_degrees, axis);

CHECK(matrix(0,0) == 1);
CHECK(matrix(1,0) == 0);
CHECK(matrix(2,1) == 1);
}