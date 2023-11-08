#include "exceptions.h"

int main() {

    //Zad1----------------------------------------------------

    int a, b;

    std::cout << "Podaj dwie liczby calkowite: ";
    std::cin >> a >> b;

    try {
        divide(a, b); //wywolanie funkcji dzielenia a / b
    } catch(const char* msg) {
        std::cout << "Blad!: " << msg << std::endl;
    }

    //Zad2----------------------------------------------------

    char text[256];
    std::cout << "Wprowadz liczbe: " << std::endl;
    std::cin >> text; //wczytanie tekstu do skonwertowania
    try {
        convert(text); //wywolanie funkcji konwertowania
    } catch (const char* msg) {
        std::cout << "Blad!: " << msg << std::endl;
    }
}