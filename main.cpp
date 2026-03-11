#include "Matrix.h"
#include "matrix.cpp"
#include <iostream>
int main() 
{
    // return 0;
    Matrix A(2,2);
    A.set(0,0,4); 
    A.set(0,1,7);
    A.set(1,0,2);
    A.set(1,1,6);

    std::cout << "Matrix A:" << std::endl;
    A.print();

    std::cout << "Determinant of A: " << A.determinant() << std::endl;

    std::cout << "Inverse of A:" << std::endl;
    Matrix invA = A.inverse();
    invA.print();

    std::cout << "Identity Matrix (3x3):" << std::endl;
    Matrix I = Matrix::identity(3);
    I.print();

    return 0;


}