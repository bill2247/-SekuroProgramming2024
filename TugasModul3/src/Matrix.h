#ifndef __MATRIX
#define __MATRIX

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

class Matrix {
private:
    vector<vector<float>> data;
    size_t rows;
    size_t cols;

public:
    // Constructor menerima input dalam bentuk array 2d
    Matrix(std::vector<std::vector<float>>);

    // Constructor menerima input banyaknya baris dan kolom
    Matrix(size_t, size_t);

    // Constructor yang dapat men-copy objek dengan class yang sama
    Matrix(Matrix&);

    // Operator overloading untuk penjumlahan matrix
    Matrix operator+(Matrix) const;

    // Operator overloading untuk pengurangan matrix
    Matrix operator-(Matrix) const ;

    // Operator overloading untuk perkalian matrix
    Matrix operator*(Matrix) const;
    
    // Menampilkan isi matrix
    void display() const;
};

#endif