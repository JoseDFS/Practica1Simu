#include <vector>
#include <iostream>
#include "stdlib.h"
#include "math.h"
#include "math_tools.h"
#include "display_tools.h"

using namespace std;


typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void Inversa(Matrix M,Matrix &I);


int main(){
    Matrix matrix,inversa;

    zeroes(matrix,3);

    matrix.at(0).at(0) =2;matrix.at(0).at(1) =2;matrix.at(0).at(2) =3;
    matrix.at(1).at(0) =4;matrix.at(1).at(1) =5;matrix.at(1).at(2) =6;
    matrix.at(2).at(0) =7;matrix.at(2).at(1) =8;matrix.at(2).at(2) =9;

    if(determinant(matrix)==0){
        return EXIT_FAILURE;
    }
    Inversa(matrix,inversa);
    showMatrix(inversa);
    return 0;
}

void Inversa(Matrix M,Matrix &I){
    Matrix transpuesta,cof;
    cofactors(M,cof);
    transpose(cof,transpuesta);
    float det = determinant(M);
    productRealMatrix((1/det),transpuesta,I);
}
