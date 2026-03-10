#include "Matrix.h"
#include "matrix.cpp"
#include <iostream>
int main() 
{
    Matrix a(2,2);
    Matrix b(2,2);

    // Fill A
    a.set(0,0,1); 
    a.set(0,1,2);
    a.set(1,0,3);
    a.set(1,1,4);
    // Fill B
    b.set(0,0,5); 
    b.set(0,1,6);
    b.set(1,0,7);
    b.set(1,1,8);
    cout << "Matrix A: \n";
    a.print();
    cout << "Matrix B: \n";
    b.print();
    Matrix c = Matrix::multiply(a, b);
    cout << "Result (A * B): \n";
    c.print();
    Matrix D = a.add(b);
    cout << "Result (A + B):\n"; 
    D.print();
    Matrix T = a.transpose();
    std::cout << "Transpose of A:\n";
    T.print();

    return 0;
}