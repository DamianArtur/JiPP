#include <iostream>
#include "triangle.h"
#include "Node.h"

using namespace std;

Triangle::Triangle(Node a, Node b, Node c, string nazwa):
    a(a),
    b(b),
    c(c),
    name(name) {}

//Wyswietlanie danych o wierzcholkach trojkata
void Triangle::display() {
    cout << name << " " << a << " " << b << " " << c << endl;
}

//Obliczanie odleglosci miedzy dwoma wierzcholkami trojkata
double Triangle::distance(int firstPointIndex, int secondPointIndex) {
    Node arr[3] = {a, b, c};
    return pointsDistance(arr[firstPointIndex], arr[secondPointIndex]);
}

//Przeciazenie operatora <<
std::ostream &operator<<(std::ostream &lhs, const Triangle &rhs) {
    return lhs << rhs.name << " " << rhs.a << " " << rhs.b << " " << rhs.c;
}

//Zadanie 11
void showTriangleData(Triangle triangle) {
    triangle.display();
}

void showTriangleData(Triangle &triangle) {
    triangle.display();
}

void showTriangleData(Triangle *triangle) {
    triangle->display();
}