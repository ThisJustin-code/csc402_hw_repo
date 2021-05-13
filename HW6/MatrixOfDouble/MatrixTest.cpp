#include <iostream>
#include <complex>
#include <string>
#include "Matrix.h"

using namespace std;

int main()
{
    cout << "Testing Matrix<int,_,_>" << endl;
    Matrix<int, 2, 5> m0;
    cout << "m0: " << endl << m0;
    Matrix<int, 2, 2> m1(5);
    cout << "m1: " << endl << m1;
    Matrix<int, 2, 2> m2(3);
    cout << "m2: " << endl << m2;
    Matrix<int, 2, 2> m3(m1 * m2);
    cout << "m3: " << endl << m3;
    const Matrix<int, 3, 2> m4(2);
    cout << "m4: " << endl << m4;
    cout << "m4[1][1]: " << m4[1][1] << endl;
    //m4(2,1) = 20; // This line should not compile.
    Matrix<int, 2, 2> m5(1);
    m5[0][0] = 10;
    cout << "m5[0][0]: " << m5[0][0] << endl;
    cout << "m5: " << endl << m5;
    Matrix<int, 3, 2> m6 = m4 * m5;
    cout << "m6[0][0]: " << m6[0][0] << endl;
    cout << "m6: " << endl << m6;
    //cout << "m4 + m5: " << endl << m4 + m5; // This line should not compile.
    //cout << "m4 * m6: " << endl << m4 * m6; // This line should not compile.
    cout << "m4 + m6: " << endl << m4 + m6;
    cout << "m6 += m4: " << endl << (m6 += m4);
    cout << "m6 -= m4: " << endl << (m6 -= m4);
    cout << "+m4:" << endl << +m4;
    cout << "-m4:" << endl << -m4;

    cout << endl << "Testing Matrix<double,_,_>" << endl;
    Matrix<double, 4, 3> mA(.7);
    cout << "mA:" << endl << mA;
    Matrix<double, 3, 8> mB(.8);
    cout << "mB:" << endl << mB;
    Matrix<double, 4, 8> mC(mA * mB);
    cout << "mC:" << endl << mC;

    cout << endl << "Testing Matrix<complex,_,_>" << endl;
    Matrix<complex<double>, 3, 4> mD(complex<double>(1.1, -2.1));
    cout << "mD:" << endl << mD;
    Matrix<complex<double>, 4, 2> mE(complex<double>(0.2, 3.5));
    cout << "mE:" << endl << mE;
    cout << "mD * mE:" << endl << (mD * mE);

    cout << endl << "Testing Matrix<string,_,_>" << endl;
    Matrix<string, 3, 4> m7("Hello");
    for (size_t i = 0; i < 3; i++)
        m7[i][i] = "   Hi";
    cout << "m7: " << endl << m7 << endl;
    Matrix<string, 4, 5> m8("Goodbye");
    //Matrix<string, 3, 5> m9(m7 * m8); // This line should not compile.
}