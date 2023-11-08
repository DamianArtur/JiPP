#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "imaginary.h"

using namespace std;

Imaginary::Imaginary(double re, double im): re(re), im(im) {}

Imaginary::Imaginary(): re(0.0), im(0.0) {}

Imaginary::Imaginary(double re): re(re), im(0.0) {}

void Imaginary::print() {
    cout << re << " + " << im << "i" << endl;
}

//zwracanie czesci rzeczywistej liczby
double Imaginary::real() const {
    return re;
}

//zwracanie czesci urojonej liczby
double Imaginary::imag() const {
    return im;
}

//zwracanie modulu liczby
double Imaginary::abs() const {
    return sqrt(pow(re, 2) + pow(im, 2));
}

//zwracanie argumentu liczby
double Imaginary::arg() const {
    if(re == 0) {
        if(im == 0) {
            return 0;
        } else if(im > 0) {
            return M_PI / 2;
        } else {
            return -M_PI / 2;
        }
    } else if (re > 0) {
        return atan(im / re);
    } else {
        if(im >= 0) {
            return atan(im / re) + M_PI;
        } else {
            return atan(im / re) - M_PI;
        }
    }
}

//liczba przeciwna do danej liczby zespolonej
Imaginary Imaginary::operator-() const {
    return {-re, -im};
}

//sprzezenie liczby zespolonej
Imaginary Imaginary::operator~() const {
    return {re, -im};
}

//dodawanie liczb zespolonych
Imaginary Imaginary::operator+(const Imaginary &rhs) const {
    return {re + rhs.re, im + rhs.im};
}

Imaginary &Imaginary::operator+=(const Imaginary &rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

//odejmowanie liczb zespolonych
Imaginary Imaginary::operator-(const Imaginary &rhs) const {
    return {re - rhs.re, im - rhs.im};
}

Imaginary &Imaginary::operator-=(const Imaginary &rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

//mnozenie liczb zespolonych
Imaginary Imaginary::operator*(const Imaginary &rhs) const {
    return {re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re};
}

Imaginary &Imaginary::operator*=(const Imaginary &rhs) {
    double new_re = re * rhs.re - im * rhs.im;
    double new_im = re * rhs.im + im * rhs.re;
    re = new_re;
    im = new_im;
    return *this;
}

//dzielenie liczb zespolonych
Imaginary Imaginary::operator/(const Imaginary &rhs) const {
    return {(re*rhs.re + im*rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2)), (im*rhs.re - re*rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2))};
}

Imaginary &Imaginary::operator/=(const Imaginary &rhs) {
    double new_re = (re*rhs.re + im*rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
    double new_im = (im*rhs.re - re*rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
    re = new_re;
    im = new_im;
    return *this;
}

//porownywanie liczb zespolonych
bool Imaginary::operator==(const Imaginary &rhs) const {
    return re == rhs.re && im == rhs.im;
}

//przeciazenie operatora << do wyswietlania liczby zespolonej
std::ostream &operator<<(std::ostream &lhs, const Imaginary &rhs) {
    return lhs << rhs.re << " + " << rhs.im << "i";
}