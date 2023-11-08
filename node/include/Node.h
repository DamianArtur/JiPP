#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
    double x, y;

    friend double pointsDistance(Node a, Node b); //deklaracja przyjazni

public:
    Node();
    Node(double x, double y);

    void display();
    void updateValue(double x, double y);
    friend std::ostream &operator<<(std::ostream &lhs, const Node &rhs);
};

double pointsDistance(Node a, Node b);

#endif //NODE_H