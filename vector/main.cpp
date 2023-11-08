#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    Vector v1(1, 1);
    Vector v2(2, 2);
    v1.print();
    v2.print();

    //sprawdzenie napisanych funkcji
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    double iloczyn = v1 * v2;
    Vector v5 = v1 * 2;
    Vector v6 = -v1;
    Vector v7 = 2 * v1;

    v3.print();
    v4.print();
    cout << "iloczyn: " << iloczyn << endl;
    if(v5 == v2) {
        cout << "Sa rowne" << endl;
    }
    v6.print();
    v7.print();

    cout << v7 << endl;
}