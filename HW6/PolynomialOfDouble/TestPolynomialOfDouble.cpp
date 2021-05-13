#include <iostream>
#include <iomanip>
#include "PolynomialOfDouble.h"
using namespace std;

int main() {
    // Create the polynomial:  3x^4+x^2-8.1x+15
    PolynomialOfDouble polyDeg4;
    polyDeg4.setCoefficient(3, 4);
    polyDeg4.setCoefficient(1, 2);
    polyDeg4.setCoefficient(-8.1, 1);
    polyDeg4.setCoefficient(15, 0);
    cout << "polyDeg4: " << polyDeg4 << endl;
    // Create the polynomial:  2.3x^3+8.1x+3
    PolynomialOfDouble polyDeg3;
    polyDeg3.setCoefficient(2.3, 3);
    polyDeg3.setCoefficient(8.1, 1);
    polyDeg3.setCoefficient(3, 0);
    cout << "polyDeg3: " << polyDeg3 << endl;
    // Create the product of the two polynomials
    PolynomialOfDouble polyDeg7;
    polyDeg7 = polyDeg3 * polyDeg4;
    cout << "polyDeg7: " << polyDeg7 << endl;
    // Create the product using a different syntax
    PolynomialOfDouble polyDeg7b(polyDeg3 * polyDeg4);
    cout << "polyDeg7b: " << polyDeg7b << endl;
    // Check that the two products match
    cout << "polyDeg7 == polyDeg7b: " << (polyDeg7 == polyDeg7b) <<endl;
    cout << std::setprecision(10); // Print out up to 10 digits
    // Check that the product of the evaluation results is the same as the evaluation result of the product
    // (which is a homomorphism property:  p(3.7) * q(3.7) = (p * q)(3.7))
    double eval4 = polyDeg4.eval(3.7);
    cout << "polyDeg4.eval(3.7): " << eval4 << endl;
    double eval3 = polyDeg3.eval(3.7);
    cout << "polyDeg3.eval(3.7): " << eval3 << endl;
    double eval7 = polyDeg7.eval(3.7);
    cout << "polyDeg7.eval(3.7): "  << eval7 << endl;
    cout << "eval7 == eval3 * eval4: " << (eval7 == eval3 * eval4) << endl;
    return 0;
}
