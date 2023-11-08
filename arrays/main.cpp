#include <iostream>
#include <ctime>
#include "arrays.h"

int main() {
    srand(time(NULL));
    std::cout << "Losowa liczba z zakresu <1,10>: " << randomNumber(1, 10) << std::endl; //testowanie funkcji randomNumber()

    int* arr = nullptr;
    arr = new int[10];
    for(int i = 0; i < 10; i++) {
        arr[i] = randomNumber(1,100);
    }

    std::cout << "Utworzona tablica: " << std::endl;
    for(int i = 0; i < 10; i ++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Najwieksza wartosc w tablicy to: " << max_value(arr, 10) << std::endl;

    std::cout << "Odwrocona tablica wyglada nastepujaco: " << std::endl;
    revert(arr, 10);
    for(int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;
}