#include "calc.h"

void show_help() {
    cout << "Simple calculator" << endl;
    cout << "sipleCalc [nazwa dzialania]" << endl << endl;
    cout << "Dzialania:" << endl;
    cout << "add [a] [b]" << endl;
    cout << "\tDodawanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "subtract [a] [b]" << endl;
    cout << "\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych." << endl;
    cout << "volume [a] [b] [h] [H]" << endl;
    cout << "\tObliczanie objetosci graniastoslupa prostego o podstawie trapezu" << endl;
    cout << "\t[H] - wys. graniastoslupa, [h] - wys. trapezu, [a] i [b] - boki trapezu" << endl;
    cout << "help" << endl;
    cout << "\tWyswietlanie tej dokumentacji" << endl << endl;
}

void add(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
}

void subtract(int a, int b) {
    cout << a << " - " << b << " = " << a - b << endl;
}

void volume(double a, double b, double h, double H) { //funkcja obliczania objetosci graniastoslupa
    cout << "Objetosc graniastoslupa o podstawie trapezu o podanych rozmiarach wynosi: " << (a + b) * h * H / 2 << endl;
}