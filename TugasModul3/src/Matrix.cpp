#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(std::vector<std::vector<float>> input){
    data = input;
    rows = input.size();
    cols = input[0].size();
};

// Constructor menerima input banyaknya baris dan kolom
Matrix::Matrix(size_t rows, size_t cols){
    this->rows = rows;
    this->cols = cols;
    data = vector<vector<float>>(rows, vector<float>(cols, 0.0));
};

// Constructor yang dapat men-copy objek dengan class yang sama
Matrix::Matrix(Matrix& other){
    data = other.data;
    rows = other.rows;
    cols = other.cols;
}

// Operator overloading untuk penjumlahan matrix
Matrix Matrix::operator+(Matrix other) const {
    if (Matrix::rows != other.rows || cols != other.cols) {
        cerr << "The matrix dimension is not valid!\n";
        return Matrix(1, 1);  // Return 1x1 matrix with value 0
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

// Operator overloading untuk pengurangan matrix
Matrix Matrix::operator-(Matrix other) const {
    if (rows != other.rows || cols != other.cols) {
        cerr << "The matrix dimension is not valid!\n";
        return Matrix(1, 1);  // Return 1x1 matrix with value 0
    }

    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

// Operator overloading untuk perkalian matrix
Matrix Matrix::operator*(Matrix other) const {
    if (cols != other.rows) {
        cerr << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second.\n";
        return Matrix(1, 1);  // Return 1x1 matrix with value 0
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            for (size_t k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

// Menampilkan isi matrix
void Matrix::display() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << data[i][j] << ' ';
        }
        cout << '\n';
    }
}