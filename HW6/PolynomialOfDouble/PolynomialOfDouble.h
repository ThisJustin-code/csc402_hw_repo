// PolynomialOfDouble.h
// A class to represent univariate polynomials whose coefficients
// and variable range over the doubles.
// - Jeff Ward

#ifndef POLYNOMIALOFDOUBLE_POLYNOMIALOFDOUBLE_H
#define POLYNOMIALOFDOUBLE_POLYNOMIALOFDOUBLE_H

#include <vector>
#include <iostream>
using namespace std;

class PolynomialOfDouble {
private:
    vector<double> coeffs_;
    void normalize();
public:
    int degree() const { return (int)coeffs_.size() - 1; }
    const double & coefficient(int i) const { return coeffs_[i]; }
    double & coefficient(int i) { return coeffs_[i]; }
    PolynomialOfDouble operator+() const; // unary +
    PolynomialOfDouble operator-() const; // unary -
    const PolynomialOfDouble & operator+=(const PolynomialOfDouble & rhs);
    const PolynomialOfDouble & operator-=(const PolynomialOfDouble & rhs);
    const PolynomialOfDouble & operator*=(const PolynomialOfDouble & rhs);
    bool operator==(const PolynomialOfDouble & rhs) const;
    bool operator!=(const PolynomialOfDouble & rhs) const;
    double eval(double x) const;
    void print(ostream &) const;
    void setCoefficient(double coeff, int exp);
};

// Math binary operators
PolynomialOfDouble operator+(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs);
PolynomialOfDouble operator-(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs);
PolynomialOfDouble operator*(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs);

// I/O
ostream & operator<<(ostream & out, const PolynomialOfDouble & value);
//istream & operator>>(istream & in, PolynomialOfDouble & value);

#endif //POLYNOMIALOFDOUBLE_POLYNOMIALOFDOUBLE_H
