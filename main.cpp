#include "Matrix.h"
#include "matrix.cpp"
#include <iostream>
#include <chrono>

int main() 
{
    // BunchMarking multiplication of large matrices
    Matrix M1(1000,1000);
    Matrix M2(1000,1000);
    // fill with some values O(N * N)
    for( int i =0; i<100; i++)
        for(int j =0; j<100; j++) {
            M1.set(i,j,i+j);
            M2.set(i,j,i+j);
        }
    ;
    auto start = std::chrono::high_resolution_clock::now();
    Matrix M3 = Matrix::multiply(M1, M2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    // Outputing the Time of The Multiplication Operation:
    std::cout << "Multiplication Of 1000*1000 took: "<< elapsed.count() << " Seconds\n";


    // BunchMarking the Determination Operation Time of 3 * 3 Matrices
    Matrix D(3,3);
    D.set(0,0,1); D.set(0,1,2); D.set(0,2,3);
    D.set(1,0,0); D.set(1,1,4); D.set(1,2,5);
    D.set(2,0,1); D.set(2,1,0); D.set(2,2,6);
    auto StartD = std::chrono::high_resolution_clock::now();
    double determinant_D = D.determinant();
    auto endD = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedDet = endD - StartD;
    std::cout << "Determinant of 3x3 took: " 
          << elapsedDet.count() << " seconds\n";
    return 0;


}