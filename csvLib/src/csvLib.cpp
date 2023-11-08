#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "csvLib.h"

using namespace std;

CSVData CSVLoader::load(string fileName) {

    char delimiter;
    cout << "Wybierz separator: ";
    cin >> delimiter;

    CSVData data;
    ifstream file(fileName);

    if(file.is_open()) {

        int row = 0;
        data.addRow();
        char buffer[1024];
        int i = 0;
        char character;
        bool isQuotations = false;

        while(!file.eof()) {

            file.get(character);

            if (character == delimiter) {
                if (isQuotations) {
                    buffer[i] = character;
                    i++;
                } else {
                    buffer[i] = '\0';
                    data.addElement(row, string(buffer));
                    i = 0;
                }
            } else if (character == '\n') {
                buffer[i] = '\0';
                data.addElement(row, string(buffer));
                data.addRow();
                row++;
                i = 0;
            } else if (character == '"') {
                if (isQuotations) {
                    isQuotations = false;
                } else {
                    isQuotations = true;
                }
            } else {
                buffer[i] = character;
                i++;
            }
        }

        buffer[i] = '\0';
        data.addElement(row, string(buffer));

    } else {
        throw CSVException("Nie mozna otworzyc pliku!");
    }

    return data;
}

void CSVData::addElement(int row, const string element) {
    data[row].push_back(element);
}

void CSVData::addRow() {
    data.push_back(vector<string>());
}

void CSVData::print() const {
    for(int i = 0; i < data.size(); i++) {
        for(int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}