#include "Matrix.h"
#include <stdexcept>
using namespace std;
// constructors to getting the data from the client 
Matrix::Matrix(int r, int c) : rows{r}, cols{c} 
{
    data.resize(rows,vector<int>(cols,0));
}

// Getters (Accessors) --------------------------------------------------------
int Matrix::getRows() const {return rows;}
int Matrix::getCols() const {return cols;}


// Element Setter (SetElement) --------------------------------------------------------
void Matrix::set(int r, int c, int value) { data[r][c] = value;};

// Element Getter or bringer --------------------------------------------------------
int Matrix::get(int r, int c) const {return data[r][c];}

// Print Matrix --------------------------------------------------------
void Matrix::print() const {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) cout << data[i][j] << " ";
        cout << "\n";
    }
}


// Multiply Two Matrixes --------------------------------------------------------
Matrix Matrix::multiply (const Matrix & A, const Matrix & B) {
    if( A.getCols() != B.getRows()) 
        throw invalid_argument("Matrix Dimensions Don't Match For Multiplication");
    Matrix C(A.getRows(), B.getCols());
    // 1'loop Matrix A Rows 
    for ( int i =0; i < A.getRows(); i++){
        // 2'loop Matrix B Columns
        for ( int j = 0; j < B.getCols(); j++) {
            int sum =0; 
            // 3'loop Matrix A Columns
            for (int k =0; k < A.getCols(); k++){
                sum += A.get(i, k) * B.get(k,j);
            }
            C.set(i, j, sum);
        }
    }  
    return C;
} 

// addition --------------------------------------------------------
Matrix Matrix::add(const Matrix& other) const {
    if (rows != other.getRows() || cols != other.getCols()) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.set(i, j, this->get(i, j) + other.get(i, j));
        }
    }

    return result;
}

// Transpose --------------------------------------------------------

Matrix Matrix::transpose() const {
    Matrix result(cols, rows); // Note :- Dimensions Swapping
    for(int i =0; i < rows; i++){
        for(int j = 0; j < cols; j++) result.set(j,i,this -> get(i,j));
    }
    return result;
}