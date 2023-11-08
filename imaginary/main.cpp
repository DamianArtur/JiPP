#include <iostream>
#include "imaginary.h"

using namespace std;

int main() {
    //zadeklarowanie kilku przykladow
    Imaginary z1;
    Imaginary z2(2);
    Imaginary z3(1,2);

    //sprawdzenie dzialania zaimplementowanych funkcji
    cout << z3.imag() << endl;
    cout << z3.real() << endl;
    cout << z3.abs() << endl;
    cout << z3.arg() << endl;

    cout << -z3 << endl;
    cout << ~z3 << endl;

    Imaginary z4 = z2 + z3;
    z4 -= z3;
    Imaginary z5 = z2 - z3;
    z5 += z3;
    Imaginary z6 = z2 * z3;
    z6 /= z3;
    Imaginary z7 = z2 / z3;
    z7 *= z3;

    cout << z4 << endl;
    cout << z5 << endl;
    cout << z6 << endl;
    cout << z7 << endl;
}