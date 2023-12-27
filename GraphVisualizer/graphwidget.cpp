#include "graphwidget.h"
#include <QPainter>
#include <QTimer>
#include <iostream>
#include <QMouseEvent>
GraphWidget::GraphWidget(QWidget *parent)
    : QWidget{parent}
{
    // Set up a timer to update the graph layout
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GraphWidget::updateGraphLayout);
    timer->start(16); // Update every 16 milliseconds (about 60 frames per second)
    // this->edges = edges;
    // this->nodes = nodes;
    // this->numNodes = nodes.size();
    // this->setStyleSheet("background-color: blue;");
    initializeGraph();
}

void GraphWidget::updateGraphLayout(){
    applyRepulsiveForces();
    applyAttractiveForces();
    updateNodePositions();
    update();
}

void GraphWidget::initializeGraph(){
    // Simple example graph (edges)
    edges = {
        {0, 1}, {2, 3}, {1, 3}, {3, 7}, {5, 2},
        {4, 9}, {9, 1}, {10, 4}, {5, 6}, {8, 11},
        {12, 0}, {12, 7}, {13, 6}, {14, 0}, {9, 14},
        {8, 2}, {11, 9}, {10, 8}, {4, 3}, {5, 8},
        {13, 4}, {13, 7}, {11, 4},
        {16, 18}, {20, 23}, {19, 21}, {22, 27}, {24, 20},
        {26, 31}, {31, 21}, {32, 26}, {25, 28}, {30, 33},
        {34, 16}, {34, 27}, {35, 32}, {36, 16}, {31, 36},
        {30, 22}, {33, 26}, {35, 30}, {29, 28}, {24, 29},
        {34, 24}, {34, 27}, {33, 24}, {26, 25}, {28, 31},
        {35, 28}, {35, 29}, {33, 28}, {26, 29}, {28, 33},
        {39, 35}, {38, 32}, {37, 12}, {32, 19}, {23, 35},
        {38, 3}, {17,39} , {15,21} , {18,15}, {15,2}, {22,39},
        {37, 17}, {23,3} , {33,1} , {15,12}, {16,17}, {2,11},
        {12,4}, {18,1}, {13,5}, {32,7}, {27,6},{23,7},{20,14}, {37,10}
    };
    // edges = {{0,1}};

    // edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};

    // Initialize node positions and values
    for (int i = 0; i < numNodes; ++i) {
        nodes.emplace_back(rand() % width(), rand() % height(), i);
    }
}

void GraphWidget::applyAttractiveForces(){
    // Apply attractive forces along edges
    for (const auto& edge : edges) {
        QVector2D delta(nodes[edge.second].position - nodes[edge.first].position);
        double distance = delta.length();
        QVector2D force = attractiveForceConstant * delta / distance;
        nodes[edge.first].velocity += force.toPointF();
        nodes[edge.second].velocity -= force.toPointF();
    }
}


void GraphWidget::applyRepulsiveForces() {
    // Apply repulsive forces between all pairs of nodes
    for (int i = 0; i < numNodes; ++i) {
        for (int j = i + 1; j < numNodes; ++j) {
            QVector2D delta(nodes[i].position - nodes[j].position);
            double distance = delta.length();
            QVector2D force = repulsiveForceConstant * delta.normalized() / (distance * distance);
            nodes[i].velocity += force.toPointF();
            nodes[j].velocity -= force.toPointF();
        }
    }
}

void GraphWidget::updateNodePositions() {
    // Update node positions based on their velocities
    for (auto& node : nodes) {
        if(node.position.x() + node.velocity.x() < nodeRadius*2 || node.position.x() + node.velocity.x() > width()-nodeRadius*2){
            node.velocity.setX(-node.velocity.x());
        }
        if(node.position.y() + node.velocity.y() < nodeRadius*2 || node.position.y() + node.velocity.y() > height()-nodeRadius*2){
            node.velocity.setY(-node.velocity.y());
        }

        node.position += node.velocity;
        // Damping to prevent oscillations
        node.velocity *= dampingFactor;
    }
}

void GraphWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw edges
    painter.setPen(Qt::black);
    for (const auto& edge : edges) {
        painter.drawLine(nodes[edge.first].position, nodes[edge.second].position);
    }

    // Draw nodes
    for (const auto& node : nodes) {
        // Draw the circle
        painter.setBrush(Qt::blue);
        painter.drawEllipse(node.position, nodeRadius*2, nodeRadius*2);

        // Draw the numeric value in the center
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 12));
        painter.drawText(node.position.toPoint() - QPoint(5, -5), QString::number(node.value));
    }
}

void GraphWidget::mousePressEvent(QMouseEvent* event){
    std::cout<<"I AM WORKING"<<std::endl;
    if(event->button() == Qt::RightButton) return;


    for(GraphNode& node : this->nodes){
        QPointF center = {node.position.x() + nodeRadius, node.position.y() + nodeRadius};

        double distance = QLineF(event->pos(), node.position.toPoint()).length();
        if (distance < nodeRadius) {
            // Call your function with the clicked node

            std::cout<<"NODE CLICKED: "<<node.value<<std::endl;
            this->selectedNode = &node;
            this->offset = center - event->pos();

            break;  // Stop searching for other nodes
        }
    }

}

void GraphWidget::mouseMoveEvent(QMouseEvent* event){
    if(this->selectedNode){
        this->selectedNode->position = event->pos() + offset;
        update();
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent* event){
    Q_UNUSED(event);
    this->selectedNode = nullptr;
}
