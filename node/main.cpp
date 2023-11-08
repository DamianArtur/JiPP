#include <iostream>
#include "node.h"

using namespace std;

int main() {
    Node pk1(1,1); //tworzenie punktow
    Node pk2(0,0);

    cout << pointsDistance(pk1, pk2) << endl; //test funkcji zaprzyjaznionej

    return 0;
}