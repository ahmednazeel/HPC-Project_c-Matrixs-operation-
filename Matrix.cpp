#include "Matrix.h"
#include <stdexcept>
using namespace std;
// constructors to getting the data from the client 
Matrix::Matrix(int r, int c) : rows{r}, cols{c} 
{
    data.resize(rows,vector<double>(cols,0));
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


//  Helper Function ---------------------------------------------------------

// # Minor Matrix
Matrix Matrix::minorMatrix(int row, int col) const {
    Matrix result(rows-1, cols-1); 

    int r = 0; 
    for(size_t i =0; i < rows; i++) {
        if (i == row) continue;
        
        int c =0; 
        for (size_t j = 0; j < cols; j++)
        {
            if (j == col) continue;
            result.data[r][c] = data[i][j];
            c++;
        }
        r++;    
    }
    return result;
}
// # CoFactorMatrix Matrix
Matrix Matrix::coFactorMatrix() const {
    if(rows != cols) throw std::invalid_argument("Matrix must be square");
    
    Matrix cof(rows, cols);
    
    for(int i =0; i<rows; i++){
        for(int j = 0; j< cols; j++){
            Matrix minor = minorMatrix(i,j);
            double sign = ((i + j) % 2 ==0) ? 1 : -1;
            cof.data[i][j] = sign * minor.determinant();
        }
    }
    
    return cof;
}

//  Determinant (recursive)
double Matrix::determinant() const {
    
    if (rows != cols) throw std::invalid_argument("Matrix must be square");
    
    int n = rows;
    if (n == 1) return data[0][0];
    if (n == 2) return data[0][0] * data[1][1] - data[0][1] * data[1][0];

    double det = 0;
    for (int col = 0; col < n; col++) {
        Matrix minor = minorMatrix(0, col);
        det += (col % 2 == 0 ? 1 : -1) * data[0][col] * minor.determinant();
    }
    return det;
}

Matrix Matrix::inverse() const {
    double det = determinant();
    if (det == 0) throw std::runtime_error("Matrix is singular");

    Matrix cof = coFactorMatrix();
    Matrix adj = cof.transpose();
    Matrix inv(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inv.data[i][j] = adj.data[i][j] / det;
        }
    }
    return inv;
}

Matrix Matrix::identity(int n) {
    Matrix I(n, n);
    for (int i = 0; i < n; i++) {
        I.data[i][i] = 1;
    }
    return I;
}