#ifndef COMPLEX_H
#define COMPLEX_H

class Imaginary {

private:
    double re, im;

public:

    Imaginary(double re, double im);
    Imaginary(double re);
    Imaginary();

    void print();
    double real() const;
    double imag() const;
    double abs() const;
    double arg() const;

    Imaginary operator-() const;
    Imaginary operator~() const;
    Imaginary operator+(const Imaginary &rhs) const;
    Imaginary &operator+=(const Imaginary &rhs);
    Imaginary operator-(const Imaginary &rhs) const;
    Imaginary &operator-=(const Imaginary &rhs);
    Imaginary operator*(const Imaginary &rhs) const;
    Imaginary &operator*=(const Imaginary &rhs);
    Imaginary operator/(const Imaginary &rhs) const;
    Imaginary &operator/=(const Imaginary &rhs);
    bool operator==(const Imaginary &rhs) const;
    friend std::ostream &operator<<(std::ostream &lhs, const Imaginary &rhs);

};

#endif //COMPLEX_H