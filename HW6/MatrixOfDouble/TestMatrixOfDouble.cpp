#include <iostream>
#include <random>
#include "MatrixOfDouble.h"

int main() {
    MatrixOfDouble m2by2A(2,2);
    for (size_t i = 0; i < m2by2A.numRows(); i++)
        m2by2A[i][i] = 1.0;
    cout << m2by2A << endl;
    //MatrixOfDouble m2by2B(2, 2, 7.2);
    MatrixOfDouble m0(2, 5);
    cout << "m0: " << endl << m0;
    MatrixOfDouble m1(2, 2, 5);
    cout << "m1: " << endl << m1;
    MatrixOfDouble m2(2, 3, 3);
    cout << "m2: " << endl << m2;
    MatrixOfDouble m3(m1 * m2);
    cout << "m3: " << endl << m3;
    const MatrixOfDouble m4(3, 2, 2);
    cout << "m4: " << endl << m4;
    cout << "m4[1][1]: " << m4[1][1] << endl;
    //m4[2][1] = 20; // This line should not compile.
    MatrixOfDouble m5(2, 2, 1);
    m5[0][0] = 10;
    cout << "m5[0][0]: " << m5[0][0] << endl;
    cout << "m5: " << endl << m5;
    MatrixOfDouble m6 = m4 * m5;
    cout << "m6[0][0]: " << m6[0][0] << endl;
    cout << "m6: " << endl << m6;
    //cout << "m4 + m5: " << endl << m4 + m5; // This line should not compile.
    //cout << "m4 * m6: " << endl << m4 * m6; // This line should not compile.
    cout << "m4 + m6: " << endl << m4 + m6;
    cout << "m6 += m4: " << endl << (m6 += m4);
    cout << "m6 -= m4: " << endl << (m6 -= m4);
    cout << "+m4:" << endl << +m4;
    cout << "-m4:" << endl << -m4;

    MatrixOfDouble mA(4, 3, .7);
    MatrixOfDouble mB(3, 6, .8);
    MatrixOfDouble mC(mA * mB);
    cout << "mC:" << endl << mC << endl;

    const MatrixOfDouble mD(mC);
    mC[0][0] = 4.2;  // Calling operator[], which returns double &
    cout << "mC[0][0]: " << mC[0][0] << endl;
    // mD[0][0] = 4.2; // Will not compile:  operator[] const returns a const double &
    cout << "mD[0][0]: " << mD[0][0] << endl; // Compiles fine.  But would not compile if we didn't have operator[] const
                                            // didn't have operator[] const (which returns const & double).
    return 0;
}
