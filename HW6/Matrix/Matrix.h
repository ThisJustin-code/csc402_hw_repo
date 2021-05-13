//
// Created by Justin Gallagher on 11/17/2020.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <vector>
#include <iostream>
using namespace std;

template<typename T, size_t rows, size_t cols>
class Matrix {
private:
    vector<vector<T>> elts_;
public:
    Matrix(const T & value = T()) {
        elts_.resize(rows);
        for (size_t i = 0; i < rows; i++) {
            elts_[i].resize(cols, value);
        }
    }
    vector<T> & operator[](size_t row) {
        return elts_[row];
    }
    const vector<T> & operator[](size_t row) const {
        return elts_[row];
    }
    Matrix operator+() const {
        return *this;
    }
    Matrix operator-() const {
        Matrix returnVal = *this;
        for (size_t i = 0; i < elts_.size(); i++) {
            for (size_t j = 0; j < elts_[i].size(); j++) {
                returnVal[i][j] = -returnVal[i][j];
            }
        }
        return returnVal;
    }
    Matrix & operator+=(const Matrix & other) {
        for (size_t i = 0; i < elts_.size(); i++) {
            for (size_t j = 0; j < elts_[i].size(); j++) {
                elts_[i][j] += other[i][j];
            }
        }
        return *this;
    }
    Matrix & operator-=(const Matrix & other) {
        for (size_t i = 0; i < elts_.size(); i++) {
            for (size_t j = 0; j < elts_[i].size(); j++) {
                elts_[i][j] -= other[i][j];
            }
        }
        return *this;
    }
    Matrix operator+(const Matrix & other) const {
        Matrix returnVal = *this;
        returnVal += other;
        return returnVal;
    }
    Matrix operator-(const Matrix & other) const {
        Matrix returnVal = *this;
        returnVal += other;
        return returnVal;
    }
    template<size_t otherCols>
    Matrix<T, rows, otherCols> operator*(const Matrix<T, cols, otherCols> & other) const {
        if (rows == 0) {
            throw invalid_argument("Number of rows do not match");
        }
        Matrix<T, rows, otherCols> result;
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < otherCols; j++) {
                T inner = 0;
                for (size_t k = 0; k < cols; k++){
                    inner += elts_[i][k] * other[k][j];
                }
                result[i][j] = inner;
            }
        }
        return result;
    } // binary

    void print(ostream & out) const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                out << " ";
                out << elts_[i][j];
            }
            out << endl;
        }
    }
};
template<typename T, size_t rows, size_t cols>
ostream & operator<<(ostream & out, const Matrix<T, rows, cols> & m) {
    m.print(out);
    return out;
}

#endif //MATRIX_MATRIX_H
