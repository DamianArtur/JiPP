#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>
#include <mutex>

using namespace std;

class MyClass {
    
private:
    vector<vector<double>> matrix;

    double max;

    void findMaxInRow(size_t row) {

        for(auto &cell: matrix[row]) {
            if(max < cell) {
                max = cell;
            }
        }

    }

public:
    MyClass(unsigned short columns, unsigned short rows) {
        matrix.resize(rows);

        default_random_engine defEngine;
        uniform_real_distribution<double> intDistro(-2000,2000);

        for(auto &row: matrix) {
            row.resize(columns);

            for(auto &cell: row) {
                cell = intDistro(defEngine);
            }
        }
    }

    void printMatrix () {
        for(auto &row: matrix) {
            for(auto &cell: row) {
                cout << setw(10) << cell << "\t";
            }
            cout << endl;
        }
    }

    double findMax() {
        max = matrix[0][0];
        vector<thread> thTab;

        for(int i = 0; i < matrix.size(); ++i) {
            thTab.emplace_back(&MyClass::findMaxInRow, this, i);
        }

        for(int i = 0; i < matrix.size(); ++i) {
            thTab[i].join();
        }

        return max;
    }

};

int main() {
    MyClass mc(5, 10);
    mc.printMatrix();

    cout << mc.findMax() << endl;

    return 0;
}

