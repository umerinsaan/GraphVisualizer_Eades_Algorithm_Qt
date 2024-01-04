#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
#include <QWidget>
#include <QVector2D>
#include <unordered_map>
#include "GraphNode.h"

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);
    // QVector<GraphNode> nodes;
    std::unordered_map<int ,GraphNode> nodes;
    QVector<QPair<int, int>> edges;

    void addNode(int val);
    void addEdge(QPair<int,int> edge);
    void deleteNode(int val);
    void deleteEdge(QPair<int,int> edge);

    bool ShouldBalance()const {return this->isBalancing;}

    double repulsiveForceConstant = 1000.0;
    double attractiveForceConstant = 0.15;
signals:

private slots:
    void updateGraphLayout();
    void initializeGraph();
    void applyAttractiveForces();
    void applyRepulsiveForces();
    void updateNodePositions();
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

protected:
    void paintEvent(QPaintEvent* event) override;
private:
    QTimer* timer;
    int numNodes = 0;
    const double dampingFactor = 0.9;
    const int nodeRadius = 9;
    // QVector<GraphNode> nodes;
    // QVector<QPair<int, int>> edges;
    GraphNode* selectedNode = nullptr;
    QPointF offset;
    bool isBalancing = true;
};

#endif // GRAPHWIDGET_H
