#include "calc.h"

int main(int argc, char* argv[]) {

    if (argc < 2) { //gdy uzytkownik nie poda argumentow
        cout << "Nieprawidlowa liczba argumentow!" << endl << endl;
        show_help();
    } else {
        if (strcmp(argv[1], "add") == 0) { //wybranie opcji dodawanie
            add(atoi(argv[2]), atoi(argv[3]));
        } else if (strcmp(argv[1], "subtract") == 0) { //wybranie opcji odejmowanie
            subtract(atoi(argv[2]), atoi(argv[3]));
        } else if (strcmp(argv[1], "volume") == 0) { //wybranie opcji obliczania objetosci
            volume(atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]));
        } else if (strcmp(argv[1], "help") == 0) { //wybranie opcji wyswietlania dokumentacji
            show_help();
        } else {
            cout << "Nie ma takiej opcji!" << endl << endl; //gdy uzytkownik nie poda prawidlowego argumentu
            show_help();
        }
    }

    return 0;
}
