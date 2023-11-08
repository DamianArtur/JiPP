#include <iostream>
#include <cstring>
#include "matrixLib.h"

using namespace std;

bool selectDataType() { //funkcja wyboru typu danych przez uzytkownia (int czy double)

    string type;
    cout << "Czy Twoje macierze zawieraja liczby zmiennoprzecinkowe? [T/N]\n";
    cin >> type;

    if(type == "t" || type == "T" || type == "tak" || type == "Tak")
        return true;
    return false;
}

void printMatrix(int** matrix, int numberOfRows, int numberOfColumns, string text = "") {

    cout << text;
    cout << "----------------------------------- \n";
    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------- \n";
}

void printMatrix(double** matrix, int numberOfRows, int numberOfColumns, string text = "") {

    cout << text;
    cout << "----------------------------------- \n";
    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------- \n";
}

void printHelp() { //funkcja wyswietlania dokumentacji
    cout << "----------------------------------- \n";
    cout << "Dokumentacja progrmu \n";
    cout << "----------------------------------- \n";
    cout << "Wywolanie: matrixApp.exe [arg] \n";
    cout << "\nLista argumentow: \n";
    cout << "addMatrix - dodaje do siebie dwie macierze \n";
    cout << "subtractMatrix - odejmuje od siebie dwie macierze \n";
    cout << "multiplyMatrix - mnozy przez siebie dwie macierze \n";
    cout << "multiplyByScalar - mnozy macierz przez skalar \n";
    cout << "transpozeMatrix - znajduje macierz transponowana do zadanej \n";
    cout << "powerMatrix - podnosi macierz do zadanej potegi \n";
    cout << "determinantMatrix - znajduje wyznacznik macierzy \n";
    cout << "matrixIsDiagonal - sprawdza czy macierz jest diagonalna \n";
    cout << "sortRowsInMatrix - sortuje osobno kazdy wiersz macierzy \n";
    cout << "help - wyswietla te dokumentacje \n\n";
    cout << "Wczytywanie macierzy odbywa sie wierszami. Po wyswietleniu komunikatu podaj wszystkie elementy danego wiersza oddzielone spacjami i zatwierdz klawiszem [Enter]. \n";
}

int inputIntNumber(string text) {

    int ret;
    cout << text;
    while(!(cin >> ret)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return ret;
}

double inputDoubleNumber(string text) {

    double ret;
    cout << text;
    while(!(cin >> ret)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return ret;
}

int** inputIntMatrix(string text, int &numberOfRows, int &numberOfColumns) { //wczytywanie macierzy podanej przez uzytkownika

    cout << text;
    cout << "Podaj liczbe wierszy Twojej macierzy: ";
    while(!(cin >> numberOfRows)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Podaj liczbe kolumn Twojej macierzy: ";
    while(!(cin >> numberOfColumns)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }

    int** matrix = allocateIntMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        cout << "Wprowadz elementy wiersza numer " << i+1 << ": \n";
        for(int j = 0; j < numberOfColumns; j++) {
            while(!(cin >> matrix[i][j])) {
                cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
    }

    cout << "\nWprowadzono nastepujaca macierz: \n";
    printMatrix(matrix, numberOfRows, numberOfColumns);
    cout << "\n\n";

    return matrix;
}

double** inputDoubleMatrix(string text, int &numberOfRows, int &numberOfColumns) {

    cout << text;
    cout << "Podaj liczbe wierszy Twojej macierzy: ";
    while(!(cin >> numberOfRows)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    cout << "Podaj liczbe kolumn Twojej macierzy: ";
    while(!(cin >> numberOfColumns)) {
        cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
        cin.clear();
        cin.ignore(100, '\n');
    }

    double** matrix = allocateDoubleMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        cout << "Wprowadz elementy wiersza numer " << i+1 << ": \n";
        for(int j = 0; j < numberOfColumns; j++) {
            while(!(cin >> matrix[i][j])) {
                cout << "Wykryto niedozwolony znak! Sprobuj jeszcze raz: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
    }

    cout << "\nWprowadzono nastepujaca macierz: \n";
    printMatrix(matrix, numberOfRows, numberOfColumns);
    cout << "\n\n";

    return matrix;
}

int main(int argc, char* argv[]) {

    cout << "\tKalkulator macierzy\n-----------------------------------\n\n";

    if(argc < 2 || argc > 2) {
        cout << "Nieprawidlowa liczba argumentow! \n\n";
        printHelp();
        cout << "\nProgram zakonczony. \n";
        return 0;
    }

    string operation(argv[1]);

    if(operation == "addMatrix") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz A:\n", numberOfRowsA, numberOfColumnsA);
            double** matrixB = inputDoubleMatrix("Wprowadz macierz B:\n", numberOfRowsB, numberOfColumnsB);
            if(numberOfRowsA != numberOfRowsB || numberOfColumnsA != numberOfColumnsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            double** matrixResult = addMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsA, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        } else {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            int** matrixA = inputIntMatrix("Wprowadz macierz A:\n", numberOfRowsA, numberOfColumnsA);
            int** matrixB = inputIntMatrix("Wprowadz macierz B:\n", numberOfRowsB, numberOfColumnsB);
            if(numberOfRowsA != numberOfRowsB || numberOfColumnsA != numberOfColumnsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            int** matrixResult = addMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsA, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        }
    } else if(operation == "subtractMatrix") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz A:\n", numberOfRowsA, numberOfColumnsA);
            double** matrixB = inputDoubleMatrix("Wprowadz macierz B:\n", numberOfRowsB, numberOfColumnsB);
            if(numberOfRowsA != numberOfRowsB || numberOfColumnsA != numberOfColumnsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            double** matrixResult = subtractMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsA, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        } else {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            int** matrixA = inputIntMatrix("Wprowadz macierz A:\n", numberOfRowsA, numberOfColumnsA);
            int** matrixB = inputIntMatrix("Wprowadz macierz B:\n", numberOfRowsB, numberOfColumnsB);
            if(numberOfRowsA != numberOfRowsB || numberOfColumnsA != numberOfColumnsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            int** matrixResult = subtractMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsA, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        }
    } else if(operation == "multiplyMatrix") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz A: \n", numberOfRowsA, numberOfColumnsA);
            double** matrixB = inputDoubleMatrix("Wprowadz macierz A: \n", numberOfRowsB, numberOfColumnsB);
            if(numberOfColumnsA != numberOfRowsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            double** matrixResult = multiplyMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA, numberOfColumnsB);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsB, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        } else {
            int numberOfRowsA, numberOfColumnsA, numberOfRowsB, numberOfColumnsB;
            int** matrixA = inputIntMatrix("Wprowadz macierz A: \n", numberOfRowsA, numberOfColumnsA);
            int** matrixB = inputIntMatrix("Wprowadz macierz B: \n", numberOfRowsB, numberOfColumnsB);
            if(numberOfColumnsA != numberOfRowsB) {
                cout << "Rozmiary macierzy sa nieprawidlowe dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRowsA);
                deallocateMatrix(matrixB, numberOfRowsB);
                return 0;
            }
            int** matrixResult = multiplyMatrix(matrixA, matrixB, numberOfRowsA, numberOfColumnsA, numberOfColumnsB);
            printMatrix(matrixResult, numberOfRowsA, numberOfColumnsB, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRowsA);
            deallocateMatrix(matrixB, numberOfRowsB);
            deallocateMatrix(matrixResult, numberOfRowsA);
        }
    } else if(operation == "multiplyByScalar") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRows, numberOfColumns;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            double scalar = inputDoubleNumber("Wprowadz skalar \n");
            double** matrixResult = multiplyByScalar(matrixA, numberOfRows, numberOfColumns, scalar);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int** matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            int scalar = inputIntNumber("Wprowadz skalar \n");
            int** matrixResult = multiplyByScalar(matrixA, numberOfRows, numberOfColumns, scalar);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        }
    } else if(operation == "transpozeMatrix") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRows, numberOfColumns;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            double** matrixResult = transpozeMatrix(matrixA, numberOfRows, numberOfColumns);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int** matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            int** matrixResult = transpozeMatrix(matrixA, numberOfRows, numberOfColumns);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        }
    } else if(operation == "powerMatrix") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRows, numberOfColumns;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            int exponent = inputIntNumber("Wprowadz wykladnik potegi \n");
            double** matrixResult = powerMatrix(matrixA, numberOfRows, numberOfColumns, exponent);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int** matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            int exponent = inputIntNumber("Wprowadz wykladnik potegi \n");
            int** matrixResult = powerMatrix(matrixA, numberOfRows, numberOfColumns, exponent);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        }
    } else if(operation == "determinantMatrix" ) {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRows, numberOfColumns;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            cout << "Wyznacznik macierzy wynosi " << determinantMatrix(matrixA, numberOfRows, numberOfColumns) << endl;
            deallocateMatrix(matrixA, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int** matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            cout << "Wyznacznik macierzy wynosi " << determinantMatrix(matrixA, numberOfRows, numberOfColumns) << endl;
            deallocateMatrix(matrixA, numberOfRows);
        }
    } else if(operation == "matrixIsDiagonal") {
        bool floatNumbers = selectDataType();
        if(floatNumbers) {
            int numberOfRows, numberOfColumns;
            double** matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            if(matrixIsDiagonal(matrixA, numberOfRows, numberOfColumns))
                cout << "Macierz jest diagonalna. \n";
            else
                cout << "Macierz nie jest diagonalna. \n";
            deallocateMatrix(matrixA, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int** matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            if(numberOfRows != numberOfColumns) {
                cout << "Rozmiar macierzy jest nieprawidlowy dla tej operacji! \nProgram zakonczony.";
                deallocateMatrix(matrixA, numberOfRows);
                return 0;
            }
            if(matrixIsDiagonal(matrixA, numberOfRows, numberOfColumns))
                cout << "Macierz jest diagonalna \n";
            else
                cout << "Macierz nie jest diagonalna \n";
            deallocateMatrix(matrixA, numberOfRows);
        }
    } else if(operation == "sortRowsInMatrix") {
        bool floatNumbers = selectDataType();
        if (floatNumbers) {
            int numberOfRows, numberOfColumns;
            double **matrixA = inputDoubleMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            double **matrixResult = sortRowsInMatrix(matrixA, numberOfRows, numberOfColumns);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        } else {
            int numberOfRows, numberOfColumns;
            int **matrixA = inputIntMatrix("Wprowadz macierz \n", numberOfRows, numberOfColumns);
            int **matrixResult = sortRowsInMatrix(matrixA, numberOfRows, numberOfColumns);
            printMatrix(matrixResult, numberOfRows, numberOfColumns, "Wynik: \n");
            deallocateMatrix(matrixA, numberOfRows);
            deallocateMatrix(matrixResult, numberOfRows);
        }
    } else if(operation == "help") {
        printHelp();
    } else { //wyswietlanie dokumentacji dla niepoprawnego argumentu
        cout << "Nieprawidlowy argument! \n\n";
        printHelp();
    }

    cout << "\nProgram zakonczony. \n";
    return 0;
}