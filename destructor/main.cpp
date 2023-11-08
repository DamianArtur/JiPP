#include <iostream>

using namespace std;

class Tablica {
public:
    int* arr;

    Tablica() {
        cout << "Wywolano konstruktor!" << endl;
        arr = new int[1024];
    }

    ~Tablica() {
        cout << "Wywolano destruktor!" << endl;
        delete[] arr;
    }
};

int main() {
    char c;

    Tablica* tablica;
    tablica = new Tablica;
    cout << "Pausa" << endl;
    cin >> c;
    delete tablica;
}