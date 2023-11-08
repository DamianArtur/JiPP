#include <iostream>
#include <exception>
#include "csvLib.h"

using namespace std;

int main() {
    CSVData data;
    CSVLoader loader;

    try {
        data = loader.load("C:\\Users\\damia\\CLionProjects\\JiPP\\csvLib\\data.csv");
        data.print();
    } catch (CSVException exception) {
        cout << "Blad: " << exception.info() << endl;
    }
}