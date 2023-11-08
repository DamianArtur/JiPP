#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

void Vector::print() {
    cout << "x: " << x << ", y: " << y << endl;
}

//obliczanie dlugosci wektora
double Vector::length() {
    return sqrt(x * x + y * y);
}

//dodawanie wektorow
Vector Vector::operator+(const Vector &rhs) const {
    return {x + rhs.x, y + rhs.y};
}

Vector &Vector::operator+=(const Vector &rhs) {
    x = x + rhs.x;
    y = y + rhs.y;
    return *this;
}

//odejmowanie wektorow
Vector Vector::operator-(const Vector &rhs) const {
    return {x - rhs.x, y - rhs.y};
}

Vector &Vector::operator-=(const Vector &rhs) {
    x = x - rhs.x;
    y = y - rhs.y;
    return *this;
}

//wektor przeciwny
Vector Vector::operator-() const {
    return {-x, -y};
}

//iloczyn skalarny wektorow
double Vector::operator*(const Vector &rhs) const {
    return x * rhs.x + y * rhs.y;
}

//mnozenia wektora przez skalar
Vector Vector::operator*(const double rhs) const {
    return {rhs * x, rhs * y};
}

//porownywanie wektorow
bool Vector::operator==(const Vector &rhs) const {
    return x == rhs.x && y  == rhs.y;
}

//mnozenie przez skalar z lewej strony
Vector operator*(const double &lhs, const Vector &rhs) {
    return {lhs * rhs.x, lhs * rhs.y};
}

//przeciazenie operatora <<
std::ostream &operator<<(std::ostream &lhs, const Vector &rhs) {
    return lhs << "x: " << rhs.x << ", y: " << rhs.y;
}