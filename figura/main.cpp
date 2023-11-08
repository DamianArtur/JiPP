#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class Figura {

protected:
    string nazwa;
    string kolor;

public:
    virtual double getArea() = 0;
    virtual double getCircumference() = 0;
};

class Circle : public Figura {

private:
    double radius;

public:
    Circle(double radius)
    :
    radius(radius) {}

    virtual double getArea() {
        return M_PI * radius * radius;
    }

    virtual double getCircumference() {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Figura {

private:
    double a, b;

public:
    Rectangle(double a,double b)
    :
    a(a),
    b(b) {}

    virtual double getArea(){
        return a * b;
    }

    virtual double getCircumference(){
        return 2*a + 2*b;
    }
};

int main() {
    Figura *circle = new Circle(5);
    Figura *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}