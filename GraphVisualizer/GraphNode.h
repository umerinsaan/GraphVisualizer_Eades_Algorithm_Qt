#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include<QPointF>

class GraphNode {
public:
    GraphNode(int x, int y, int value) : position(x, y), velocity(0, 0), value(value) {}
    QPointF position;
    QPointF velocity;
    int value;

    GraphNode(){}
};

#endif // GRAPHNODE_H
