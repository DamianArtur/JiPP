#ifndef CSVLIB_H
#define CSVLIB_H

#include <vector>
#include <string>

using namespace std;

class CSVData {
private:
    vector<vector<string>> data;
public:
    void addElement(int, string);
    void addRow();
    void print() const;
};

class CSVLoader {
public:
    CSVData load(string fileName);
};

class CSVException: public exception {
private:
    string message;
public:
    CSVException(string message) {
        this->message = message;
    }
    const string info() {
        return message;
    }
};

#endif //CSVLIB_H
