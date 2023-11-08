// wszystkie funkcje wymagaja kazdego z parametrow okreslnych w tresci zadan, nawet jesli nie sa one potrzebne (np. wyznaczniki i potegi obliczamy tylko dla macierzy kwadratowych)

#include <cmath>
#include "matrixLib.h"

int** allocateIntMatrix(int numberOfRows, int numberOfColumns) {

    int** newMatrix = new int*[numberOfRows];

    for(int i = 0; i < numberOfRows; i++) {
        newMatrix[i] = new int[numberOfColumns];
    }

    return newMatrix;
}

double** allocateDoubleMatrix(int numberOfRows, int numberOfColumns) {

    double** newMatrix = new double*[numberOfRows];

    for(int i = 0; i < numberOfRows; i++) {
        newMatrix[i] = new double[numberOfColumns];
    }

    return newMatrix;
}

void deallocateMatrix(int** matrix, int numberOfRows) {

    for(int i = 0; i < numberOfRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void deallocateMatrix(double** matrix, int numberOfRows) {

    for(int i = 0; i < numberOfRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void initializeMatrix(int** matrix, int numberOfRows, int numberOfColumns) { //funkcja inicjalizuje macierz typu int zerami (potrzebne w algorytmie mnozenia macierzy)

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrix[i][j] = 0;
        }
    }
}

void initializeMatrix(double** matrix, int numberOfRows, int numberOfColumns) {

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrix[i][j] = 0;
        }
    }
}

int** createIdentityIntMatrix(int size) { //funkcja tworzy macierz jednostkowa i zwraca wskaznik do niej (potrzebne w algorytmie podnoszenia do potegi)

    int** matrixResult = allocateIntMatrix(size, size);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j) matrixResult[i][j] = 1; //wartosci na przekatnej ustawiamy na 1
            else matrixResult[i][j] = 0; //wartosci poza przekatna ustawiamy na 0
        }
    }

    return matrixResult;
}

double** createIdentityDoubleMatrix(int size) {

    double** matrixResult = allocateDoubleMatrix(size, size);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(i == j) matrixResult[i][j] = 1;
            else matrixResult[i][j] = 0;
        }
    }

    return matrixResult;
}

int** copyMatrix(int** matrix, int numberOfRows, int numberOfColumns) { //funkcja kopiuje macierz i zwraca wskaznik do kopii (potrzebne w algorytmie potegowania)

    int** copy = allocateIntMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            copy[i][j] = matrix[i][j];
        }
    }

    return copy;
}

double** copyMatrix(double** matrix, int numberOfRows, int numberOfColumns) {

    double** copy = allocateDoubleMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            copy[i][j] = matrix[i][j];
        }
    }

    return copy;
}

int** addMatrix(int** matrixA, int** matrixB, int numberOfRows, int numberOfColumns) { //funkcja dodawania dwoch macierzy do siebie, zwraca wskaznik na wynik

    int** matrixResult = allocateIntMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return matrixResult;
}

double** addMatrix(double** matrixA, double** matrixB, int numberOfRows, int numberOfColumns) {

    double** matrixResult = allocateDoubleMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return matrixResult;
}

int** subtractMatrix(int** matrixA, int** matrixB, int numberOfRows, int numberOfColumns) { //funkcja odejmowania dwoch macierzy od siebie, zwraca wskaznik do wyniku

    int** matrixResult = allocateIntMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return matrixResult;
}

double** subtractMatrix(double** matrixA, double** matrixB, int numberOfRows, int numberOfColumns) {

    double** matrixResult = allocateDoubleMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    return matrixResult;
}

int** multiplyMatrix(int** matrixA, int** matrixB, int numberOfRowsA, int numberOfColumnsA, int numberOfColumnsB) { //funkcja mnozenia dwoch macierzy przez siebie, zwraca wskaznik na wynik

    int** resultMatrix = allocateIntMatrix(numberOfRowsA, numberOfColumnsB);
    initializeMatrix(resultMatrix, numberOfRowsA, numberOfColumnsB); //inicjalizacja zerami

    for(int i = 0; i < numberOfRowsA; i++) {
        for(int j = 0; j < numberOfColumnsB; j++) {
            for(int k = 0; k < numberOfColumnsA; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return resultMatrix;
}

double** multiplyMatrix(double** matrixA, double** matrixB, int numberOfRowsA, int numberOfColumnsA, int numberOfColumnsB) {

    double** resultMatrix = allocateDoubleMatrix(numberOfRowsA, numberOfColumnsB);
    initializeMatrix(resultMatrix, numberOfRowsA, numberOfColumnsB);

    for(int i = 0; i < numberOfRowsA; i++) {
        for(int j = 0; j < numberOfColumnsB; j++) {
            for(int k = 0; k < numberOfColumnsA; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return resultMatrix;
}

int** multiplyByScalar(int** matrixA, int numberOfRows, int numberOfColumns, int scalar) { //funkcja mnozenia macierzy przez skalar, zwraca wskaznik do wyniku

    int** matrixResult = allocateIntMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] * scalar;
        }
    }

    return matrixResult;
}

double** multiplyByScalar(double** matrixA, int numberOfRows, int numberOfColumns, double scalar) {

    double** matrixResult = allocateDoubleMatrix(numberOfRows, numberOfColumns);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[i][j] = matrixA[i][j] * scalar;
        }
    }

    return matrixResult;
}

int** transpozeMatrix(int** matrixA, int numberOfRows, int numberOfColumns) { //funkcja transponowania macierzy, zwraca wskaznik do wyniku

    int** matrixResult = allocateIntMatrix(numberOfColumns, numberOfRows);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[j][i] = matrixA[i][j];
        }
    }

    return matrixResult;
}

double** transpozeMatrix(double** matrixA, int numberOfRows, int numberOfColumns) {

    double** matrixResult = allocateDoubleMatrix(numberOfColumns, numberOfRows);

    for(int i = 0; i < numberOfRows; i++) {
        for(int j = 0; j < numberOfColumns; j++) {
            matrixResult[j][i] = matrixA[i][j];
        }
    }

    return matrixResult;
}

int** powerMatrix(int** matrixA, int numberOfRows, int numberOfColumns, unsigned int exponent) { //funkcja podnoszenia macierzy do potegi, zwraca wskaznik do wyniku

    if(exponent == 0) { //jezeli podnosimy do zerowej potegi...

        return createIdentityIntMatrix(numberOfRows); //...wynikiem jest macierz jednostkowa

    } else if(exponent == 1) { //jezeli podnosimy do pierwszej potegi...

        return copyMatrix(matrixA, numberOfRows, numberOfColumns); //...zwracamy ta sama macierz

    } else {

        int** matrixResult = copyMatrix(matrixA, numberOfRows, numberOfColumns); //tworzenie kopii (pierwsza potega)
        for(int i = 1; i < exponent; i++) {
            int** matrixResultTemp = multiplyMatrix(matrixResult, matrixA, numberOfRows, numberOfColumns, numberOfColumns);
            deallocateMatrix(matrixResult, numberOfRows);
            matrixResult = matrixResultTemp;
        }

        return matrixResult;

    }
}

double** powerMatrix(double** matrixA, int numberOfRows, int numberOfColumns, unsigned int exponent) {

    if(exponent == 0) {

        return createIdentityDoubleMatrix(numberOfRows);

    } else if(exponent == 1) {

        return copyMatrix(matrixA, numberOfRows, numberOfColumns);

    } else {

        double** matrixResult = copyMatrix(matrixA, numberOfRows, numberOfColumns);
        for(int i = 1; i < exponent; i++) {
            double** matrixResultTemp = multiplyMatrix(matrixResult, matrixA, numberOfRows, numberOfColumns, numberOfColumns);
            deallocateMatrix(matrixResult, numberOfRows);
            matrixResult = matrixResultTemp;
        }

        return matrixResult;

    }
}

void createSubMatrix(int** matrix, int** tempMatrix, int deletedColumn, int size) { //funkcja tworzenia podmacierzy (metoda rozwiniecia Laplace'a)

    int x = 0, y = 0; //wspolrzedne w tworzonej podmacierzy

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != deletedColumn) { //pomijanie "skreslonych" kolumny i wiersza
                tempMatrix[x][y++] = matrix[i][j];
                if (y == size - 1) {
                    y = 0;
                    x++;
                }
            }
        }
    }
}

int determinantMatrix(int** matrixA, int numberOfRows, int numberOfColumns) { //funkcja zwracajaca wyznacznik macierzy

    if(numberOfRows == 1) return matrixA[0][0]; //przypadek macierzy 1x1

    if(numberOfRows == 2) return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0]; //przypadek macierzy 2x2

    int** tempMatrix = allocateIntMatrix(numberOfRows, numberOfColumns);
    int result = 0, sign = 1;

    for(int i = 0; i < numberOfRows; i++) {
        createSubMatrix(matrixA, tempMatrix, i, numberOfRows); //tworzenie podmacierzy dla kolejnych elementow pierwszego wiersza
        result += sign * matrixA[0][i] * determinantMatrix(tempMatrix, numberOfRows-1, numberOfColumns-1);
        sign *= -1;
    }

    return result;
}

void createSubMatrix(double** matrix, double** tempMatrix, int deletedColumn, int size) {

    int x = 0, y = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != 0 && j != deletedColumn) {
                tempMatrix[x][y++] = matrix[i][j];
                if (y == size - 1) {
                    y = 0;
                    x++;
                }
            }
        }
    }
}

double determinantMatrix(double** matrixA, int numberOfRows, int numberOfColumns) {

    if(numberOfRows == 1) return matrixA[0][0];

    if(numberOfRows == 2) return matrixA[0][0] * matrixA[1][1] - matrixA[0][1] * matrixA[1][0];

    double** tempMatrix = allocateDoubleMatrix(numberOfRows, numberOfColumns);
    double result = 0;
    int sign = 1;

    for(int i = 0; i < numberOfRows; i++) {
        createSubMatrix(matrixA, tempMatrix, i, numberOfRows);
        result += sign * matrixA[0][i] * determinantMatrix(tempMatrix, numberOfRows-1, numberOfColumns-1);
        sign *= -1;
    }

    return result;
}

bool matrixIsDiagonal(int** matrixA, int numberOfRows, int numberOfColumns) { //funkcja zwracajaca informacje czy macierz jest diagonalna

    for(int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            if (i != j && matrixA[i][j] != 0) return false;
        }
    }

    return true;
}

bool matrixIsDiagonal(double** matrixA, int numberOfRows, int numberOfColumns) {

    const double epsilon = 1e-12;

    for(int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            if (i != j && std::abs(matrixA[i][j]) > epsilon) return false;
        }
    }

    return true;
}

void swap(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}

void swap(double &a, double &b) {

    double temp = a;
    a = b;
    b = temp;
}

int* sortRow(int* array, int numberOfColumns) { //funkcja sortowania wiersza macierzy

    for(int i = 0; i < numberOfColumns; i++) {
        for(int j = i+1; j < numberOfColumns; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }

    return array;
}

double* sortRow(double* array, int numberOfColumns) {

    for(int i = 0; i < numberOfColumns; i++) {
        for(int j = i+1; j < numberOfColumns; j++) {
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }

    return array;
}

int** sortRowsInMatrix(int** matrixA, int numberOfRows, int numberOfColumns) { //funkcja sortowania wszystkich wierszy danej macierzy

    for(int i = 0; i < numberOfRows; i++) {
        sortRow(matrixA[i], numberOfColumns);
    }

    return matrixA;
}

double** sortRowsInMatrix(double** matrixA, int numberOfRows, int numberOfColumns) { //odpowiednik powyzszej funkcji dla danych double

    for(int i = 0; i < numberOfRows; i++) {
        sortRow(matrixA[i], numberOfColumns);
    }

    return matrixA;
}