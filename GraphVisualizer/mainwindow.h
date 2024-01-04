#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QSlider>

#include "graphwidget.h"
#include "nodeinputdialog.h"
#include "edgeinputdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addNode_btn_Handler();
    void addEdge_btn_Handler();
    void deleteNode_btn_Handler();
    void deleteEdge_btn_Handler();
    void addNodes_btn_Handler();

    void attractiveForce_slider_Handler(int finalVal);
    void repulsiveForce_slider_Handler(int finalVal);

private:
    Ui::MainWindow *ui;
    GraphWidget* graphWidget;
    QVBoxLayout* mainLayout;
    QWidget* myCentralWidget;
    QHBoxLayout* buttonsLayout;

    QPushButton* addNode_btn;
    QPushButton* addEdge_btn;
    QPushButton* deleteNode_btn;
    QPushButton* deleteEdge_btn;
    QPushButton* addNodes_btn;

    QSlider* attractiveForce_slider;
    QSlider* repulsiveForce_slider;

    QLabel* attractiveForce_label;
    QLabel* repulsiveForce_label;

    QHBoxLayout* attractiveForce_slider_layout;
    QHBoxLayout* repulsiveForce_slider_layout;

    NodeInputDialog* nodeInputDialog;
    EdgeInputDialog* edgeInputDialog;

    int initialPercentage_slider = 1;

    int attractiveForce_slider_value = 1;
    int repulsiveForce_slider_value = 1;
};

#endif // MAINWINDOW_H
