#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QPushButton>

#include "graphwidget.h"
#include "nodeinputdialog.h"

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

private:
    Ui::MainWindow *ui;
    GraphWidget* graphWidget;
    QVBoxLayout* mainLayout;
    QWidget* myCentralWidget;
    QHBoxLayout* buttonsLayout;

    QPushButton* addNode_btn;
    QPushButton* addEdge_btn;
    QPushButton* deleteNode_btn;
    QPushButton* showDFS_btn;
    QPushButton* showBFS_btn;

    NodeInputDialog* nodeInputDialog;
};



#endif // MAINWINDOW_H
