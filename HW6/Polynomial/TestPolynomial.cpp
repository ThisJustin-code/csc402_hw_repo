#include <iostream>
#include <iomanip>
#include <complex>
#include "Polynomial.h"
using namespace std;

int main() {
    cout << "Test Polynomial<double>" << endl;
    // Create the polynomial:  3x^4+x^2-8.1x+15
    Polynomial<double> polyDeg4;
    polyDeg4.setCoefficient(3, 4);
    polyDeg4.setCoefficient(1, 2);
    polyDeg4.setCoefficient(-8.1, 1);
    polyDeg4.setCoefficient(15, 0);
    cout << "polyDeg4: " << polyDeg4 << endl;
    // Create the polynomial:  2.3x^3+8.1x+3
    Polynomial<double> polyDeg3;
    polyDeg3.setCoefficient(2.3, 3);
    polyDeg3.setCoefficient(8.1, 1);
    polyDeg3.setCoefficient(3, 0);
    cout << "polyDeg3: " << polyDeg3 << endl;
    Polynomial<double> polyDeg7;
    polyDeg7 = polyDeg3 * polyDeg4;
    cout << "polyDeg7: " << polyDeg7 << endl;
    Polynomial<double> polyDeg7b(polyDeg3 * polyDeg4);
    cout << "polyDeg7b = " << polyDeg7b << endl;
    cout << "polyDeg7 == polyDeg7b: " << (polyDeg7 == polyDeg7b) <<endl;
    cout << std::setprecision(10); // Print out up to 10 digits
    double eval4 = polyDeg4.eval(3.7);
    cout << "polyDeg4.eval(3.7): " << eval4 << endl;
    double eval3 = polyDeg3.eval(3.7);
    cout << "polyDeg3.eval(3.7): " << eval3 << endl;
    double eval7 = polyDeg7.eval(3.7);
    cout << "polyDeg7.eval(3.7): "  << eval7 << endl;
    cout << "eval7 == eval3 * eval4: " << (eval7 == eval3 * eval4) << endl;

    cout << "Test Polynomial<int>" << endl;
    Polynomial<int> intPolyDeg2;
    intPolyDeg2.setCoefficient(1, 2);
    intPolyDeg2.setCoefficient(-2, 1);
    intPolyDeg2.setCoefficient(1, 0);
    cout << "intPolyDeg2: " << intPolyDeg2 << endl;
    Polynomial<int> intPolyDeg3;
    intPolyDeg3.setCoefficient(-2, 3);
    intPolyDeg3.setCoefficient(2, 2);
    intPolyDeg3.setCoefficient(4, 1);
    intPolyDeg3.setCoefficient(3, 0);
    cout << "intPolyDeg3: " << intPolyDeg3 << endl;
    Polynomial<int> intPolySum(intPolyDeg2 + intPolyDeg3);
    cout << "intPolySum: " << intPolySum << endl;
    cout << "intPolySum.eval(5): "  << intPolySum.eval(5) << endl;

    cout << "Test Polynomial<complex>" << endl;
    Polynomial<complex<double>> complexPoly;
    complexPoly.setCoefficient(complex<double>(2.4, 3.1), 3);
    complexPoly.setCoefficient(complex<double>(1.0, -2.2), 0);
    cout << "complexPoly: " << complexPoly << endl;
    cout << "complexPoly.eval(2+1.1i): "  << complexPoly.eval(complex<double>(2.0, 1.1)) << endl;
    return 0;
}