#include <cstdlib>
#include "area.h"

int main(int argc, char* argv[]) {
    if(argc == 2) { //wywolanie wersji dla kwadratu
        pole(atoi(argv[1]));
    } else if(argc == 3) { //wywolanie wersji dla prostokatu
        pole(atoi(argv[1]), atoi(argv[2]));
    } else if(argc == 4) { //wywolanie wersji dla trapezu
        pole(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    } else {
        print_help(); //wyswietlanie dokumentacji
    }
}