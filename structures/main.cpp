#include <iostream>
#include <string>

using namespace std;

struct samochod {
        string marka;
        string model;
        int rok_produkcji;
        string kolor;
        bool czy_sprawny;
};

int najnizszy_rok_produkcji(samochod samochody[], int rozmiar) {

    int min = INT_MAX;
    int indeks;

    for(int i = 0; i < rozmiar; i++) {
        if(samochody[i].rok_produkcji < min) {
            min = samochody[i].rok_produkcji;
            indeks = i;
        }
    }

    return indeks;
}

int suma_tej_samej_marki(samochod samochody[], int rozmiar, char* marka) {

    int licznik = 0;

    for(int i = 0; i < rozmiar; i++) {

        if(samochody[i].marka.compare(marka) == 0) licznik++;
    }

    return licznik;
}

int main() {

    samochod samochody[4] = {
            {"marka1", "model1", 2000, "czarny", true},
            {"marka2", "model2", 2001, "szary", false},
            {"marka1", "model3", 2002, "srebrny", false},
            {"marka3", "model4", 2003, "bialy", true}
    };

    for(int i = 0; i < 4; i++) {
        cout << samochody[i].marka << " " << samochody[i].model << " " << samochody[i].rok_produkcji << " " << samochody[i].kolor << " " << samochody[i].czy_sprawny << endl;
    }

    cout << "Jest: " << suma_tej_samej_marki(samochody, 4, "marka1") << " samochodow marki 'marka1'" << endl;
    cout << "Najnizszy rok produkcji ma samochod o indeksie " << najnizszy_rok_produkcji(samochody, 4) << endl;
}
