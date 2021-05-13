// Polynomial.h
// Class template for polynomials.
// -Jeff Ward

#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <complex>
using namespace std;

ostream & operator<<(ostream & out, const complex<double> & c) {
    out << "(" << c.real() << " + " << c.imag() << "i)";
    return out;
}

template <typename T>
class Polynomial {
private:
    vector<T> coeffs_;
    void normalize() {
        while (coeffs_.back() == T())
            coeffs_.pop_back();
        coeffs_.shrink_to_fit();  // optional
    }
public:
    int degree() const { return (int)coeffs_.size() - 1; }

    const T & coefficient(int i) const { return coeffs_[i]; }

    T & coefficient(int i) { return coeffs_[i]; }
    Polynomial operator+() const { // unary +
        return *this;
    }

    Polynomial operator-() const { // unary -
        Polynomial returnVal = *this;
        for (int i = 0; i < coeffs_.size(); i++)
            returnVal.coeffs_[i] = -returnVal.coeffs_[i];
        return returnVal;
    }

    const Polynomial & operator+=(const Polynomial & rhs) {
        int rhsSize = rhs.coeffs_.size();
        if (rhsSize > coeffs_.size())
            coeffs_.resize(rhsSize);
        for (int i = 0; i < rhsSize; i++)
            coeffs_[i] += rhs.coeffs_[i];
        normalize();
        return *this;
    }

    const Polynomial & operator-=(const Polynomial & rhs) {
        return *this += -rhs;
    }

    const Polynomial & operator*=(const Polynomial & rhs) {
        Polynomial returnVal;
        returnVal.coeffs_.resize(degree() + rhs.degree() + 1);
        for (int i = 0; i <= this->degree(); i++) {
            for (int j = 0; j <= rhs.degree(); j++)
                returnVal.coefficient(i + j) += coefficient(i) * rhs.coefficient(j);
        }
        *this = returnVal;
        return *this;
    }

    bool operator==(const Polynomial & rhs) {
        if (degree() != rhs.degree())
            return false;
        for (int i = 0; i <= degree(); i++)
            if (coeffs_[i] != rhs.coeffs_[i])
                return false;
        return true;
    }

    bool operator!=(const Polynomial & rhs) {
        return !(*this == rhs);
    }

    T eval(T x) const {
        T returnVal = 0.0;
        for (int i = degree(); i >= 0; i--)
            returnVal = returnVal * x + coefficient(i);
        return returnVal;
    }

    void print(ostream & out) const {
        const T ZERO = T();
        if (degree() == -1)
            out << ZERO;
        else {
            bool isFirstTerm = true;
            for (int i = degree(); i >= 0; i--) {
                if (coefficient(i) != ZERO) {
                    if (!isFirstTerm)
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

    void setCoefficient(const T & coeff, int exp) {
        if (degree() < exp)
            coeffs_.resize(exp + 1);
        coefficient(exp) = coeff;
    }
};  // Polynomial

// Math binary operators
template <typename  T> Polynomial<T> operator+(const Polynomial<T> & lhs, const Polynomial<T> & rhs) {
    Polynomial<T> result(lhs);
    result += rhs;
    return result;
}

template <typename  T> Polynomial<T> operator-(const Polynomial<T> & lhs, const Polynomial<T> & rhs) {
    Polynomial<T> result(lhs);
    result -= rhs;
    return result;
}

template <typename  T> Polynomial<T> operator*(const Polynomial<T> & lhs, const Polynomial<T> & rhs) {
    Polynomial<T> result(lhs);
    result *= rhs;
    return result;
}

// I/O
template <typename  T> ostream & operator<<(ostream & out, const Polynomial<T> & value) {
    value.print(out);
    return out;
}

//istream & operator>>(istream & in, Polynomial & value);

#endif //POLYNOMIAL_POLYNOMIAL_H
