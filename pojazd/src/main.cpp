#include <iostream>
#include "Pojazd.h"

using namespace std;

int main() {

    Pojazd pojazd1("ABC 12456789", "pojazd1", 4, "marka1", "typ1", "v1.0");
    pojazd1.zmien_pasazera(0, "Jan Kowalski");
    pojazd1.zmien_pasazera(1, "Anna Nowak");
    Pojazd pojazd2 = pojazd1; //test konstruktora kopiującego
    pojazd2.setName("pojazd2");
    pojazd2.setMarka("marka2");
    pojazd2.setTyp("typ2");

    pojazd1.print();
    pojazd2.print();

    pojazd1.wypiszWersje(); //wyswietlanie wersji oprogramowania
    pojazd2.wypiszWersje();

    cout << "Aktualizacja oprogramowania ..." << endl;
    Pojazd::opublikujNoweOprogramowanie("v3.0");
    pojazd1.zaktualizujOprogramowanie();
    pojazd2.zaktualizujOprogramowanie();

    pojazd1.wypiszWersje(); //po aktualizacji
    pojazd2.wypiszWersje();
}