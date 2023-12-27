#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->graphWidget = new GraphWidget();

    this->mainLayout = new QVBoxLayout(this);

    this->myCentralWidget = new QWidget;

    this->mainLayout->addWidget(this->graphWidget);

    this->myCentralWidget->setLayout(this->mainLayout);

    this->addNode_btn = new QPushButton("Add node");
    this->addEdge_btn = new QPushButton("Add edge");
    this->deleteNode_btn = new QPushButton("Delete node");
    this->showDFS_btn = new QPushButton("Show DFS");
    this->showBFS_btn = new QPushButton("Show BFS");

    this->buttonsLayout = new QHBoxLayout();

    this->buttonsLayout->addWidget(this->addNode_btn);
    connect(this->addNode_btn, &QPushButton::clicked, this, &MainWindow::addNode_btn_Handler);

    this->buttonsLayout->addWidget(this->addEdge_btn);
    this->buttonsLayout->addWidget(this->deleteNode_btn);
    this->buttonsLayout->addWidget(this->showDFS_btn);
    this->buttonsLayout->addWidget(this->showBFS_btn);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->nodeInputDialog = new NodeInputDialog(this);

    setCentralWidget(this->myCentralWidget);
}

void MainWindow::addNode_btn_Handler(){
    std::cout<<"ADD NODE CLICKED"<<std::endl;

    if(this->nodeInputDialog->exec() == QDialog::Accepted){
        QString nodeValue = nodeInputDialog->getNodeValue();
        std::cout<<"Entered node: "<<nodeValue.toStdString()<<std::endl;
    }
}



MainWindow::~MainWindow()
{
    delete this->ui;
    this->ui = nullptr;

    delete this->addNode_btn;
    this->addNode_btn = nullptr;

    delete this->addEdge_btn;
    this->addEdge_btn = nullptr;

    delete this->deleteNode_btn;
    this->deleteNode_btn = nullptr;

    delete this->showDFS_btn;
    this->showDFS_btn = nullptr;

    delete this->showBFS_btn;
    this->showBFS_btn = nullptr;

    delete this->buttonsLayout;
    this->buttonsLayout = nullptr;

    delete this->graphWidget;
    this->graphWidget = nullptr;

    delete this->mainLayout;
    this->mainLayout = nullptr;

    delete this->myCentralWidget;
    this->myCentralWidget = nullptr;
}

