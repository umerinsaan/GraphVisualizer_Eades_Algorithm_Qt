#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
#include <QWidget>
#include <QVector2D>

#include "GraphNode.h"

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);
    QVector<GraphNode> nodes;

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
    int numNodes = 40;
    const double repulsiveForceConstant = 1000.0;
    const double attractiveForceConstant = 0.15;
    const double dampingFactor = 0.9;
    const int nodeRadius = 8;
    // QVector<GraphNode> nodes;
    QVector<QPair<int, int>> edges;
    GraphNode* selectedNode = nullptr;
    QPointF offset;
};

#endif // GRAPHWIDGET_H
