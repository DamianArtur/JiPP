#include <iostream>
#include "pointers.h"

int main() {
    //Zad1 -------------------------------------------------------------------
    int a, b;
    double mean;
    int* ptr_a = nullptr, * ptr_b = nullptr;
    double* ptr_mean = &mean;

    std::cout << "Podaj dwie liczby calkowite: " << std::endl;

    std::cin >> a;
    std::cin >> b;

    ptr_a = &a;
    ptr_b = &b;

    find_mean(ptr_a, ptr_b, ptr_mean);

    std::cout << "Srednia z " << *ptr_a << " i " << *ptr_b << " to " << *ptr_mean << std::endl;

    //Zad2 -------------------------------------------------------------------

    int* arr = nullptr;
    arr = new int[10];
    std::cout << "Podaj 10 elementow tablicy: " << std::endl;

    int* copy_ptr = arr;
    for(int i = 0; i < 10; i++) {
        std::cin >> *copy_ptr;
        copy_ptr++;
    }

    std::cout << "Wypisuje elementy wieksze od zera: " << std::endl;

    copy_ptr = arr;
    for(int i = 0; i < 10; i++) {
        if(*copy_ptr > 0)
            std::cout << *copy_ptr << " ";
        copy_ptr++;
    }
    std::cout << std::endl;

    //Zad3 -------------------------------------------------------------------

    int j, k, l;
    std::cout << "Podaj trzy liczby: ";
    std::cin >> j >> k >> l;

    sort(&j, &k, &l);

    std::cout << "Twoje liczby posortowane: " << j << " " << k << " " << l << std::endl;

    //Zad4 -------------------------------------------------------------------

    int x = 2;
    int y = 0;
    int* ptr = &y;

    std::cout << "Przed wywolaniem funkcji set(): " << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    set(x, ptr);

    std::cout << "Po wywolaniem funkcji set(): " << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
}