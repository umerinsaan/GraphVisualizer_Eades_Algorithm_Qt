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
    // initializeGraph();
}

void GraphWidget::updateGraphLayout(){
    // std::cout<<"SIZE = "<<this->nodes.size()<<std::endl;
    // if(this->nodes.size() < 2) return;
    if(this->isBalancing){
        applyRepulsiveForces();
        applyAttractiveForces();
        updateNodePositions();
    }

    update();
}

void GraphWidget::initializeGraph(){
    // Simple example graph (edges)
    // edges = {
    //     {0, 1}, {2, 3}, {1, 3}, {3, 7}, {5, 2},
    //     {4, 9}, {9, 1}, {10, 4}, {5, 6}, {8, 11},
    //     {12, 0}, {12, 7}, {13, 6}, {14, 0}, {9, 14},
    //     {8, 2}, {11, 9}, {10, 8}, {4, 3}, {5, 8},
    //     {13, 4}, {13, 7}, {11, 4},
    //     {16, 18}, {20, 23}, {19, 21}, {22, 27}, {24, 20},
    //     {26, 31}, {31, 21}, {32, 26}, {25, 28}, {30, 33},
    //     {34, 16}, {34, 27}, {35, 32}, {36, 16}, {31, 36},
    //     {30, 22}, {33, 26}, {35, 30}, {29, 28}, {24, 29},
    //     {34, 24}, {34, 27}, {33, 24}, {26, 25}, {28, 31},
    //     {35, 28}, {35, 29}, {33, 28}, {26, 29}, {28, 33},
    //     {39, 35}, {38, 32}, {37, 12}, {32, 19}, {23, 35},
    //     {38, 3}, {17,39} , {15,21} , {18,15}, {15,2}, {22,39},
    //     {37, 17}, {23,3} , {33,1} , {15,12}, {16,17}, {2,11},
    //     {12,4}, {18,1}, {13,5}, {32,7}, {27,6},{23,7},{20,14}, {37,10}
    // };
    // edges = {{0,1}};

    // edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};

    // Initialize node positions and values
    // for (int i = 0; i < numNodes; ++i) {
    //     nodes.emplace_back(rand() % width(), rand() % height(), i);
    // }
}

void GraphWidget::applyAttractiveForces(){
    // Apply attractive forces along edges
    if(nodes.size() < 2) return;
    for (const auto& edge : edges) {
        if(edge.second == -1) continue;
        QVector2D delta(nodes[edge.second].position - nodes[edge.first].position);
        double distance = delta.length();
        QVector2D force = attractiveForceConstant * delta / distance;
        nodes[edge.first].velocity += force.toPointF();
        nodes[edge.second].velocity -= force.toPointF();
    }
}


void GraphWidget::applyRepulsiveForces() {
    // Apply repulsive forces between all pairs of nodes
    if(nodes.size() < 2) return;
    for (auto i = nodes.begin(); i != nodes.end(); ++i) {
        for (auto j = std::next(i); j != nodes.end(); ++j) {
            QVector2D delta(i->second.position - j->second.position);
            double distance = delta.length();
            QVector2D force = repulsiveForceConstant * delta.normalized() / (distance * distance);
            i->second.velocity += force.toPointF();
            j->second.velocity -= force.toPointF();
        }
    }
}

void GraphWidget::updateNodePositions() {
    // Update node positions based on their velocities
    for (auto& it : nodes) {
        if(it.second.position.x() + it.second.velocity.x() < nodeRadius*2 || it.second.position.x() + it.second.velocity.x() > width()-nodeRadius*2){
            it.second.velocity.setX(-it.second.velocity.x());
        }
        if(it.second.position.y() + it.second.velocity.y() < nodeRadius*2 || it.second.position.y() + it.second.velocity.y() > height()-nodeRadius*2){
            it.second.velocity.setY(-it.second.velocity.y());
        }

        it.second.position += it.second.velocity;
        // Damping to prevent oscillations
        it.second.velocity *= dampingFactor;
    }
}

void GraphWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    // std::cout<<"MAP SIZE: "<<this->nodes.size()<<std::endl;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Draw edges
    painter.setPen(Qt::black);
    for (const auto& edge : edges) {
        // std::cout<<"WELLLLOOO"<<std::endl;
        if(this->nodes.size() < 2) break;

        if(edge.first == -1 || edge.second == -1) continue;

        painter.drawLine(nodes[edge.first].position, nodes[edge.second].position);

    }

    // Draw nodes
    for (const auto& it : nodes) {
        // Draw the circle
        painter.setBrush(Qt::blue);
        painter.drawEllipse(it.second.position, nodeRadius*2, nodeRadius*2);

        // Draw the numeric value in the center
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 12));
        // std::cout<<"HELLLO"<<std::endl;
        // std::cout<<"VAL = "<<it.second.value<<std::endl;
        painter.drawText(it.second.position.toPoint() - QPoint(5, -5), QString::number(it.second.value));
    }
}

void GraphWidget::mousePressEvent(QMouseEvent* event){
    // std::cout<<"I AM WORKING"<<std::endl;
    if(event->button() == Qt::RightButton) return;


    for(auto& it : this->nodes){
        QPointF center = {it.second.position.x() + nodeRadius, it.second.position.y() + nodeRadius};

        double distance = QLineF(event->pos(), it.second.position.toPoint()).length();
        if (distance < nodeRadius) {
            // Call your function with the clicked node

            // std::cout<<"NODE CLICKED: "<<it.second.value<<std::endl;
            this->selectedNode = &it.second;
            this->offset = center - event->pos();

            break;  // Stop searching for other nodes
        }
    }

}

void GraphWidget::mouseMoveEvent(QMouseEvent* event){
    if(this->selectedNode){
        QPointF newPosition = event->pos() + offset;

        if (newPosition.x() - nodeRadius*2 < 0) {
            newPosition.setX(nodeRadius*2);
        } else if (newPosition.x() + nodeRadius*2 > width()) {
            newPosition.setX(width() - nodeRadius*2);
        }

        if (newPosition.y() - nodeRadius*2 < 0) {
            newPosition.setY(nodeRadius*2);
        } else if (newPosition.y() + nodeRadius*2 > height()) {
            newPosition.setY(height() - nodeRadius*2);
        }

        this->selectedNode->position = newPosition;
        update();
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent* event){
    Q_UNUSED(event);
    this->selectedNode = nullptr;
}

void GraphWidget::addNode(int val){
    if(this->nodes.find(val) != this->nodes.end()) return;
    this->nodes[val] = GraphNode(rand() % (width() - nodeRadius*2) , rand() % (height()-nodeRadius*2), val);
    this->edges.push_back({val,-1});
}

void GraphWidget::addEdge(QPair<int,int> edge){
    bool isUexists = false;
    bool isVexists = false;

    if(this->nodes.find(edge.first) != this->nodes.end()){
        isUexists = true;
    }
    else{
        this->nodes[edge.first] = GraphNode(rand() % (width() - nodeRadius*4) , rand() % (height()-nodeRadius*4), edge.first);
    }

    if(this->nodes.find(edge.second) != this->nodes.end()){
        isVexists = true;
    }
    else{
        this->nodes[edge.second] = GraphNode(rand() % (width() - nodeRadius*4) , rand() % (height()-nodeRadius*4), edge.second);
    }

    if(!isUexists && !isVexists){
        this->edges.push_back(edge);
        return;
    }

    if(isUexists){
        for(QPair<int,int>& e : this->edges){
            if(e.first == edge.first && e.second == -1) {
                e.second = edge.second;
                return;
            }

            if(e.second == edge.first && e.first == -1){
                e.first = edge.second;
                return;
            }
        }
    }

    if(isVexists){
        for(QPair<int,int>& e : this->edges){
            if(e.first == edge.second && e.second == -1) {
                e.second = edge.first;
                return;
            }

            if(e.second == edge.second && e.first == -1){
                e.first = edge.first;
                return;
            }
        }
    }

    this->edges.push_back(edge);
}


void GraphWidget::deleteNode(int val){
    if(val < 0){
        std::cout<<"NEGATIVE VALUE TO DELETE"<<std::endl;
        return;
    }

    auto it = this->nodes.find(val);

    if(it == this->nodes.end()) return;

    // this->nodes.erase(it);
    this->isBalancing = false;
    for(int i=0 ; i<this->edges.size() ; i++){
        if(this->edges[i].first == val){
            this->edges[i].first = -1;
        }
        else if(this->edges[i].second == val){
            this->edges[i].second = -1;
        }

        if(this->edges[i].first == -1 && this->edges[i].second == -1){
            this->edges.removeAt(i);
            i--;
        }
    }
    this->nodes.erase(it);
    this->isBalancing = true;
}

void GraphWidget::deleteEdge(QPair<int, int> edge)
{
    bool isUexists = this->nodes.find(edge.first) != this->nodes.end();
    bool isVexists = this->nodes.find(edge.second) != this->nodes.end();

    if(!isUexists && !isVexists) {
        std::cout<<"NODES DONT EXISTS IN GRAPH: "<<std::endl;
        return;
    }

    for(int i=0 ; i<this->edges.size() ; i++){
        if(this->edges[i].first == edge.first && this->edges[i].second == edge.second){
            this->edges.removeAt(i);
            return;
        }
        if(this->edges[i].first == edge.second && this->edges[i].second == edge.first){
            this->edges.removeAt(i);
            return;
        }
    }
}
