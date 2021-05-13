// MatrixOfDouble.h
// A class for representing matrices of doubles.
// - Jeff Ward

#ifndef MATRIXOFDOUBLE_MATRIXOFDOUBLE_H
#define MATRIXOFDOUBLE_MATRIXOFDOUBLE_H
#include <vector>
#include <iostream>
using namespace std;

class MatrixOfDouble {
private:
    vector<vector<double>> elts_;

public:
    size_t numRows() const;
    size_t numCols() const;
    MatrixOfDouble(size_t numRows, size_t numCols, double value = 0.0);
    vector<double> & operator[](size_t row);
    const vector<double> & operator[](size_t row) const;
    MatrixOfDouble operator+() const;// unary
    MatrixOfDouble operator-() const; // unary
    MatrixOfDouble & operator+=(const MatrixOfDouble & other);
    MatrixOfDouble & operator-=(const MatrixOfDouble & other);
    MatrixOfDouble operator+(const MatrixOfDouble & other) const; // binary
    MatrixOfDouble operator-(const MatrixOfDouble & other) const; // binary
    // standard matrix multiplication
    MatrixOfDouble operator*(const MatrixOfDouble & other) const; // binary
    void print(ostream & out) const;
};

//MatrixOfDouble operator+(MatrixOfDouble lhs, MatrixOfDouble rhs);
//MatrixOfDouble operator-(MatrixOfDouble lhs, MatrixOfDouble rhs);
//MatrixOfDouble operator*(MatrixOfDouble lhs, MatrixOfDouble rhs);
ostream & operator<<(ostream & out, const MatrixOfDouble & m);

#endif //MATRIXOFDOUBLE_MATRIXOFDOUBLE_H
