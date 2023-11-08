#include <iostream>
#include <cstdlib>

using  namespace std;

template<typename T>
T my_min(T a, T b) {
    return a < b ? a : b;
}

template<typename T>
T my_max(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
void printArray(T *a, int size) {
    for(int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printMatrix(T **a, int columns, int rows) {
    for(int i = 0; i < rows; i++) {
        printArray(a[i], columns);
    }
}

template<typename T, int size>
class Array {
        private:
            T *arr;
        public:
            Array() {
                arr = new T[size];
            }
            ~Array() {
                delete[] arr;
            }
            T& operator[](const int rhs) {
                return arr[rhs];
            }
        };

template<typename T>
class Vector {
private:
    T *arr;
    int sizeOfArray;
    int sizeOfMemory;

    void reallocateArray(int newSize) {
        T* newArray = new T[newSize];
        int numberOfCopies = my_min(newSize, sizeOfArray);
        for(int i = 0; i < numberOfCopies; i++) {
            newArray[i] = arr[i];
        }
        sizeOfMemory = newSize;
        delete[] arr;
        arr = newArray;
    }

public:
    Vector() {
        arr = new T[1];
        sizeOfArray = 0;
        sizeOfMemory = 1;
    }
    Vector(int size) {
        arr = new T[size];
        sizeOfArray = size;
        sizeOfMemory = size;
    }
    ~Vector() {
        delete[] arr;
    }

    void push(T val) {
        if(sizeOfArray == sizeOfMemory) {
            reallocateArray(sizeOfArray + 1);
        }
        arr[sizeOfArray++] = val;
    }

    T pop() {
        if(sizeOfArray > 1) {
            return arr[--sizeOfArray];
        }
        return arr[0];
    }

    T *getPointer() {
        return arr;
    }

    T& operator[](const int rhs) {
        return arr[rhs];
    }

    int size() {
        return sizeOfArray;
    }
};

int main() {
    Vector<int> v(3);

    v[0] = 10;
    v[1] = 11;
    v[2] = 12;

    printArray(v.getPointer(), v.size());

    v.push(13);
    v.push(14);
    v.pop();

    printArray(v.getPointer(), v.size());
}