#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
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
    this->deleteEdge_btn = new QPushButton("Delete edge");
    this->addNodes_btn = new QPushButton("Add nodes");

    this->buttonsLayout = new QHBoxLayout();

    this->attractiveForce_slider_layout = new QHBoxLayout;
    this->repulsiveForce_slider_layout = new QHBoxLayout;

    this->attractiveForce_slider = new QSlider(Qt::Horizontal);
    this->attractiveForce_slider->setMinimum(0);
    this->attractiveForce_slider->setMaximum(100);
    this->attractiveForce_slider->setValue(this->attractiveForce_slider_value);


    this->repulsiveForce_slider = new QSlider(Qt::Horizontal);
    this->repulsiveForce_slider->setMinimum(0);
    this->repulsiveForce_slider->setMaximum(100);
    this->repulsiveForce_slider->setValue(this->repulsiveForce_slider_value);

    this->attractiveForce_label = new QLabel("Attractive force");
    this->repulsiveForce_label = new QLabel("Repulsive Force");


    this->attractiveForce_slider_layout->addWidget(this->attractiveForce_label);
    this->attractiveForce_slider_layout->addWidget(this->attractiveForce_slider);


    this->repulsiveForce_slider_layout->addWidget(this->repulsiveForce_label);
    this->repulsiveForce_slider_layout->addWidget(this->repulsiveForce_slider);

    connect(this->attractiveForce_slider, &QSlider::valueChanged, this, &MainWindow::attractiveForce_slider_Handler);
    connect(this->repulsiveForce_slider, &QSlider::valueChanged, this, &MainWindow::repulsiveForce_slider_Handler);

    connect(this->addNode_btn, &QPushButton::clicked, this, &MainWindow::addNode_btn_Handler);
    connect(this->addEdge_btn, &QPushButton::clicked, this,&MainWindow::addEdge_btn_Handler);
    connect(this->deleteNode_btn,&QPushButton::clicked,this,&MainWindow::deleteNode_btn_Handler);
    connect(this->deleteEdge_btn, &QPushButton::clicked, this, &MainWindow::deleteEdge_btn_Handler);
    connect(this->addNodes_btn, &QPushButton::clicked, this , &MainWindow::addNodes_btn_Handler);

    this->buttonsLayout->addLayout(this->attractiveForce_slider_layout);

    this->buttonsLayout->addWidget(this->addNodes_btn);
    this->buttonsLayout->addWidget(this->addNode_btn);
    this->buttonsLayout->addWidget(this->addEdge_btn);
    this->buttonsLayout->addWidget(this->deleteNode_btn);
    this->buttonsLayout->addWidget(this->deleteEdge_btn);

    this->buttonsLayout->addLayout(this->repulsiveForce_slider_layout);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->nodeInputDialog = new NodeInputDialog(this);
    this->edgeInputDialog = new EdgeInputDialog(this);

    setCentralWidget(this->myCentralWidget);
}

void MainWindow::addNode_btn_Handler(){
    std::cout<<"ADD NODE CLICKED"<<std::endl;

    if(this->nodeInputDialog->exec() == QDialog::Accepted){
        bool isConverted;
        int nodeValue = nodeInputDialog->getNodeValue().toInt(&isConverted);
        std::cout<<"Entered node: "<<nodeValue<<std::endl;

        if(!isConverted){
            std::cout<<"CONVERSION QSTRING TO INT FAILED."<<std::endl;
            return;
        }
        this->graphWidget->addNode(nodeValue);
    }
}

void MainWindow::addEdge_btn_Handler(){
    std::cout<<"EDGE HANDLER CALLED"<<std::endl;

    if(this->edgeInputDialog->exec() == QDialog::Accepted){
        QPair<int,int> edge = this->edgeInputDialog->getEdge();


        if(edge.first == -1 || edge.second == -1){
            std::cout<<"INVALID VALUES FOR EDGE"<<std::endl;
            return;
        }

        if(edge.first == edge.second) return; // which means nodes are equal (self loop not allowed sorry.)

        std::cout<<"U = "<<edge.first<<" V = "<<edge.second<<std::endl;

        this->graphWidget->addEdge(edge);
    }

}

void MainWindow::deleteNode_btn_Handler(){
    if(this->nodeInputDialog->exec() == QDialog::Accepted){
        bool isConverted;
        int nodeValue = nodeInputDialog->getNodeValue().toInt(&isConverted);

        if(!isConverted){
            std::cout<<"CONVERSION QSTRING TO INT FAILED."<<std::endl;
            return;
        }

        this->graphWidget->deleteNode(nodeValue);
    }
}

void MainWindow::deleteEdge_btn_Handler()
{
    if(this->edgeInputDialog->exec() == QDialog::Accepted){
        QPair<int,int> edge = this->edgeInputDialog->getEdge();

        if(edge.first == -1 || edge.second == -1){
            std::cout<<"INVALID VALUES FOR EDGE"<<std::endl;
            return;
        }

        this->graphWidget->deleteEdge(edge);
    }
}

void MainWindow::addNodes_btn_Handler()
{
    if(this->nodeInputDialog->exec() == QDialog::Accepted){
        bool isConverted;
        int n = nodeInputDialog->getNodeValue().toInt(&isConverted);
        for(int i=0 ; i < n ; i++){
            for(int j=i+1 ; j<n ; j++){
                this->graphWidget->addEdge({i,j});
            }
        }
    }
}

void MainWindow::attractiveForce_slider_Handler(int finalVal)
{
    std::cout<<"ATTRACTIVE: "<<finalVal<<std::endl;
    int diff = finalVal - this->attractiveForce_slider_value;
    this->attractiveForce_slider_value = finalVal;
    double delta = 0.00275;

    this->graphWidget->attractiveForceConstant += diff*delta;
}

void MainWindow::repulsiveForce_slider_Handler(int finalVal)
{
    int diff = finalVal - this->repulsiveForce_slider_value;
    this->repulsiveForce_slider_value = finalVal;
    double delta = 75;

    this->graphWidget->repulsiveForceConstant += delta* diff;
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

    delete this->deleteEdge_btn;
    this->deleteEdge_btn = nullptr;

    delete this->buttonsLayout;
    this->buttonsLayout = nullptr;

    delete this->graphWidget;
    this->graphWidget = nullptr;

    delete this->mainLayout;
    this->mainLayout = nullptr;

    delete this->myCentralWidget;
    this->myCentralWidget = nullptr;
}
