#include "Node.h"
#include <math.h>
#include <iostream>

using namespace std;

Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}

double pointsDistance(Node a, Node b) {
    return sqrt(pow(b.x - a.x,2) + pow(b.y - a.y, 2));
}

// Do zadania z trojkatem
std::ostream &operator<<(std::ostream &lhs, const Node &rhs) {
    return lhs << "(" << rhs.x << ", " << rhs.y << ")";
}