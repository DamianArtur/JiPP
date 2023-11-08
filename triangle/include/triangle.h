#include <iostream>
#include "Node.h"

#ifndef TRIANGLE_H
#define TRIANGLE_H

using namespace std;

class Triangle {

private:
    Node a, b, c;
    std::string name;

public:
    Triangle(Node, Node, Node, string);

    void Triangle::display();
    double distance(int firstPointIndex, int secondPointIndex);

    friend std::ostream &operator<<(std::ostream &lhs, const Triangle &rhs);
};

void showTriangleData(Triangle triangle);
void showTriangleData(Triangle &triangle);
void showTriangleData(Triangle *triangle);

#endif //TRIANGLE_H