#include "exceptions.h"

void divide(int a, int b) {
    if(b == 0) {
        throw "Dzielenie przez 0!";
    } else if(a % b != 0) {
        throw "Dzielenie niecalkowitoliczbowe!";
    }

    std::cout << "Wynik dzielenia " << a << " / " << b << " to " << a/b << std::endl;
}

void convert(char text[]) {
    int number = 0;
    int i = 0;

    while(text[i] != '\0') {
        if (text[i] < 48 || text[i] > 57) {
            throw "Znak nie jest cyfra!";
        } else if(10*number + text[i] - '0' < 0) {
            throw "Liczba jest za duza";
        }

        number = 10*number + text[i] - '0';
        i++;
    }

    std::cout << "Wprowadziles liczbe: " << number << std::endl;
}