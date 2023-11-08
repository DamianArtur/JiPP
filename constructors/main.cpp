#include <iostream>
#include <cmath>

using namespace std;

class Punkt {
public:
    int x;
    int y;

    Punkt(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double odleglosc(Punkt punkt2) {
        return sqrt(pow((x - punkt2.x),2) + pow((y - punkt2.y),2));
    }
};

class Figura {
public:
    int liczba_wierzcholkow;
    int* tablica;

    Figura(int liczba_wierzholkow) {
        liczba_wierzcholkow = liczba_wierzcholkow;
        tablica = new int[liczba_wierzcholkow];
    }
};

int main() {
    int x1, y1, x2, y2;

    cout << "Podaj wspolrzedne pierwszego punktu: ";
    cin >> x1 >> y1;
    cout << "Podaj wspolrzedne drugiego punktu: ";
    cin >> x2 >> y2;

    Punkt punkt1(x1, y1);
    Punkt punkt2(x2, y2);

    cout << "Odleglosc miedzy punktami to " << punkt1.odleglosc(punkt2) << endl;
}