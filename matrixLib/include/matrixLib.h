#ifndef JiPP_MATRIXLIB_H
#define JiPP_MATRIXLIB_H

int** allocateIntMatrix(int numberOfRows, int numberOfColumns);
double** allocateDoubleMatrix(int numberOfRows, int numberOfColumns);

void deallocateMatrix(int** matrix, int numberOfRows);
void deallocateMatrix(double** matrix, int numberOfRows);

void initializeMatrix(int** matrix, int numberOfRows, int numberOfColumns);
void initializeMatrix(double** matrix, int numberOfRows, int numberOfColumns);

int** createIdentityIntMatrix(int size);
double** createIdentityDoubleMatrix(int size);

int** copyMatrix(int** matrix, int numberOfRows, int numberOfColumns);
double** copyMatrix(double** matrix, int numberOfRows, int numberOfColumns);



int** addMatrix(int** matrixA, int** matrixB, int numberOfRows, int numberOfColumns);
double** addMatrix(double** matrixA, double** matrixB, int numberOfRows, int numberOfColumns);

int** subtractMatrix(int** matrixA, int** matrixB, int numberOfRows, int numberOfColumns);
double** subtractMatrix(double** matrixA, double** matrixB, int numberOfRows, int numberOfColumns);

int** multiplyMatrix(int** matrixA, int** matrixB, int numberOfRowsA, int numberOfColumnsA, int numberOfColumnsB);
double** multiplyMatrix(double** matrixA, double** matrixB, int numberOfRowsA, int numberOfColumnsA, int numberOfColumnsB);

int** multiplyByScalar(int** matrixA, int numberOfRows, int numberOfColumns, int scalar);
double** multiplyByScalar(double** matrixA, int numberOfRows, int numberOfColumns, double scalar);

int** transpozeMatrix(int** matrixA, int numberOfRows, int numberOfColumns);
double** transpozeMatrix(double** matrixA, int numberOfRows, int numberOfColumns);

int** powerMatrix(int** matrixA, int numberOfRows, int numberOfColumns, unsigned int exponent);
double** powerMatrix(double** matrixA, int numberOfRows, int numberOfColumns, unsigned int exponent);

void findSubMatrix(int** matrix, int** tempMatrix, int a, int b, int size);
int determinantMatrix(int** matrixA, int numberOfRows, int numberOfColumns);
void findSubMatrix(double** matrix, double** tempMatrix, int a, int b, int size);
double determinantMatrix(double** matrixA, int numberOfRows, int numberOfColumns);

bool matrixIsDiagonal(int** matrixA, int numberOfRows, int numberOfColumns);
bool matrixIsDiagonal(double** matrixA, int numberOfRows, int numberOfColumns);

void swap(int &a, int &b);
void swap(double &a, double &b);

int* sortRow(int* array, int numberOfColumns);
double* sortRow(double* array, int numberOfColumns);

int** sortRowsInMatrix(int** matrixA, int numberOfRows, int numberOfColumns);
double** sortRowsInMatrix(double** matrixA, int numberOfRows, int numberOfColumns);

#endif //JiPP_MATRIXLIB_H