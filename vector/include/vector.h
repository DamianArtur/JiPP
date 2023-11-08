#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    double x, y;

public:
    Vector(void);
    Vector(double x, double y);
    void print(void);
    double length(void);

    Vector operator+(const Vector &rhs) const;
    Vector &operator+=(const Vector &rhs);
    Vector operator-(const Vector &rhs) const;
    Vector &operator-=(const Vector &rhs);
    Vector operator-() const;
    double operator*(const Vector &rhs) const;
    Vector operator*(const double rhs) const;
    bool operator==(const Vector &rhs) const;
    friend Vector operator*(const double &lhs, const Vector &rhs);
    friend std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);

};

#endif //VECTOR_H