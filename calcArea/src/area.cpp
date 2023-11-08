#include <iostream>

void pole(int a) { //wersja funkcji dla pola kwadratu
    std::cout << "Pole kwadratu wynosi: " << a * a << std::endl;
}

void pole(int a, int b) { //wersja funkcji dla pola prostokatu
    std::cout << "Pole prostokata wynosi: " << a * b << std::endl;
}

void pole(int a, int b, int h) { //wersja funkcji dla trapezu
    std::cout << "Pole trapezu wynosi: " << (a+b)*h/2 << std::endl;
}

void print_help() { //wyswietlanie dokumentacji
    std::cout << "Program oblicza pole figury" << std::endl;
    std::cout << "calcArea [a]" << std::endl;
    std::cout << "\t oblicza pole kwadratu" << std::endl;
    std::cout << "calcArea [a] [b]" << std::endl;
    std::cout << "\t oblicza pole prostokatu" << std::endl;
    std::cout << "calcArea [a] [b] [h]" << std::endl;
    std::cout << "\t oblicza pole trapezu" << std::endl;
}