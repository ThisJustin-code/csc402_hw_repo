#include <vector>
#include <iostream>
#include "MatrixOfDouble.h"
using namespace std;

size_t MatrixOfDouble::numRows() const {
    return elts_.size();
}

size_t MatrixOfDouble::numCols() const {
    if (numRows() == 0)
        throw invalid_argument("MatrixOfDouble has no rows");
    return elts_[0].size();
}

MatrixOfDouble::MatrixOfDouble(size_t numRows, size_t numCols, double value) {
    elts_.resize(numRows);
    for (size_t i = 0; i < numRows; i++)
        elts_[i].resize(numCols, value);
}

vector<double> & MatrixOfDouble::operator[](size_t row) {
    return elts_[row];
}

const vector<double> & MatrixOfDouble::operator[](size_t row) const {
    return elts_[row];
}

MatrixOfDouble MatrixOfDouble::operator+() const { // unary
    return *this;
}

MatrixOfDouble MatrixOfDouble::operator-() const { // unary
    MatrixOfDouble returnVal = *this;
    for (size_t i = 0; i < elts_.size(); i++)
        for (size_t j = 0; j < elts_[i].size(); j++)
            returnVal[i][j] = -returnVal[i][j];
    return returnVal;
}

MatrixOfDouble & MatrixOfDouble::operator+=(const MatrixOfDouble & other) {
    if (numRows() != other.numRows())
        throw invalid_argument("Number of rows do not match");
    if (numCols() != other.numCols())
        throw invalid_argument("Number of cols do not match");
    for (size_t i = 0; i < elts_.size(); i++)
        for (size_t j = 0; j < elts_[i].size(); j++)
            elts_[i][j] += other[i][j];
    return *this;
}

MatrixOfDouble & MatrixOfDouble::operator-=(const MatrixOfDouble & other) {
    if (numRows() != other.numRows())
        throw invalid_argument("Number of rows do not match");
    if (numCols() != other.numCols())
        throw invalid_argument("Number of cols do not match");
    for (size_t i = 0; i < elts_.size(); i++)
        for (size_t j = 0; j < elts_[i].size(); j++)
            elts_[i][j] -= other[i][j];
    return *this;
}

MatrixOfDouble MatrixOfDouble::operator+(const MatrixOfDouble & other) const { // binary
    MatrixOfDouble returnVal = *this;
    returnVal += other;
    return returnVal;
}

MatrixOfDouble MatrixOfDouble::operator-(const MatrixOfDouble & other) const { // binary
    MatrixOfDouble returnVal = *this;
    returnVal -= other;
    return returnVal;
}

// standard matrix multiplication
MatrixOfDouble MatrixOfDouble::operator*(const MatrixOfDouble & other) const {
    if (numRows() == 0 || numCols() != other.numRows())
        throw invalid_argument("Number of rows do not match");
    MatrixOfDouble result(numRows(), other.numCols());
    for (size_t i = 0; i < numRows(); i++)
        for (size_t j = 0; j < other.numCols(); j++) {
            double inner = 0.0;
            for (size_t k = 0; k < numCols(); k++) {
                inner += elts_[i][k] * other[k][j];
            }
            result[i][j] = inner;
        }
    return result;
}

void MatrixOfDouble::print(ostream & out) const {
    for (size_t i = 0; i < numRows(); i++) {
        for (size_t j = 0; j < numCols(); j++) {
            out << " ";
            out << elts_[i][j];
        }
        out << endl;
    }
}

ostream & operator<<(ostream & out, const MatrixOfDouble & m) {
    m.print(out);
    return out;
}