//
// Created by wardj1 on 11/5/2020.
//

#include "PolynomialOfDouble.h"

void PolynomialOfDouble::normalize() {
    while (coeffs_.back() == 0.0)
        coeffs_.pop_back();
    coeffs_.shrink_to_fit();  // optional
}

PolynomialOfDouble PolynomialOfDouble::operator+() const {
    return *this;
}

PolynomialOfDouble PolynomialOfDouble::operator-() const {
    PolynomialOfDouble returnVal = *this;
    for (int i = 0; i < coeffs_.size(); i++)
        returnVal.coeffs_[i] = -returnVal.coeffs_[i];
    return returnVal;
}

const PolynomialOfDouble & PolynomialOfDouble::operator+=(const PolynomialOfDouble & rhs) {
    int rhsSize = rhs.coeffs_.size();
    if (rhsSize > coeffs_.size())
        coeffs_.resize(rhsSize);
    for (int i = 0; i < rhsSize; i++)
        coeffs_[i] += rhs.coeffs_[i];
    normalize();
    return *this;
}

const PolynomialOfDouble & PolynomialOfDouble::operator-=(const PolynomialOfDouble & rhs) {
    return *this += -rhs;
}

const PolynomialOfDouble & PolynomialOfDouble::operator*=(const PolynomialOfDouble & rhs) {
    PolynomialOfDouble returnVal;
    returnVal.coeffs_.resize(degree() + rhs.degree() + 1);
    for (int i = 0; i <= this->degree(); i++)
        for (int j = 0; j <= rhs.degree(); j++)
            returnVal.coefficient(i + j) += coefficient(i) * rhs.coefficient(j);
    returnVal.normalize();
    *this = returnVal;
    return *this;
}

bool PolynomialOfDouble::operator==(const PolynomialOfDouble & rhs) const {
    if (degree() != rhs.degree())
        return false;
    for (int i = 0; i <= degree(); i++)
        if (coeffs_[i] != rhs.coeffs_[i])
            return false;
    return true;
}

bool PolynomialOfDouble::operator!=(const PolynomialOfDouble & rhs) const {
    return !(*this == rhs);
}

double PolynomialOfDouble::eval(double x) const {
    double returnVal = 0.0;
    for (int i = degree(); i >= 0; i--)
        returnVal = returnVal * x + coefficient(i);
    return returnVal;
}

void PolynomialOfDouble::print(ostream & out) const {
    if (degree() == -1)
        out << 0.0;
    else {
        bool isFirstTerm = true;
        for (int i = degree(); i >= 0; i--) {
            if (coefficient(i) == 1.0) {
                if (!isFirstTerm) {
                    out << "+";
                }
                if (i > 1)
                    out << "x^" << i; // write out symbol 'x' and exponent
                else if (i == 1)
                    out << "x";       // write out symbol 'x'
                else
                    out << 1.0;
                isFirstTerm = false;
            }
            else if (coefficient(i) != 0.0) {
                if (!isFirstTerm && coefficient(i) > 0.0)
                    out << "+";
                out << coefficient(i);
                if (i > 1)
                    out << "x^" << i; // write out symbol 'x' and exponent
                else if (i == 1)
                    out << "x";       // write out symbol 'x'
                isFirstTerm = false;
            }
        }
    }
}

void PolynomialOfDouble::setCoefficient(double coeff, int exp) {
    if (degree() < exp)
        coeffs_.resize(exp + 1);
    coefficient(exp) = coeff;
}

ostream & operator<<(ostream & out, const PolynomialOfDouble & value) {
    value.print(out);
    return out;
}

PolynomialOfDouble operator+(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs) {
    PolynomialOfDouble result(lhs);
    result += rhs;
    return result;
}

PolynomialOfDouble operator-(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs) {
    PolynomialOfDouble result(lhs);
    result -= rhs;
    return result;
}

PolynomialOfDouble operator*(const PolynomialOfDouble & lhs, const PolynomialOfDouble & rhs) {
    PolynomialOfDouble result(lhs);
    result *= rhs;
    return result;
}

/*istream & operator>>(istream & in, PolynomialOfDouble & value) {
    // Non-trivial exercise:  Read in a value like "3x^4+x^2-8.1x+15" from the istream.
}*/

