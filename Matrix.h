
#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <iostream>
using namespace std;


// Class bluePrint
class Matrix {
    public:
        // constructors to getting the data from the client 
        Matrix(int r, int c);
        // Getters (Accessors)
        int getRows() const; 
        int getCols() const; 
        // Element Setter (SetElement) 
        void set(int r, int c, int value);
        int get(int r, int c) const;
        // Print Matrix
        void print() const; 
        //  Add Matrix
        Matrix add( const Matrix &other) const;
        //  Transpose Matrix
        Matrix transpose() const;
        // multiply 2 matrixes
        static Matrix multiply ( const Matrix& A,const Matrix& B);
        // Stage 2 methods
        Matrix minorMatrix(int row, int col) const;
        Matrix coFactorMatrix() const;
        double determinant() const;
        Matrix inverse() const;
        static Matrix identity(int n);

    private:
        int rows{0}, cols{0};
        vector<vector<double>> data;
};

#endif
