#include "edgeinputdialog.h"

EdgeInputDialog::EdgeInputDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
    connectSignalsSlots();
}

void EdgeInputDialog::setupUI()
{
    labelVertexA = new QLabel("Vertex A:");
    labelVertexB = new QLabel("Vertex B:");

    lineEditVertexA = new QLineEdit;
    lineEditVertexB = new QLineEdit;

    buttonOK = new QPushButton("OK");
    buttonCancel = new QPushButton("Cancel");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelVertexA);
    mainLayout->addWidget(lineEditVertexA);
    mainLayout->addWidget(labelVertexB);
    mainLayout->addWidget(lineEditVertexB);
    mainLayout->addWidget(buttonOK);
    mainLayout->addWidget(buttonCancel);

    setLayout(mainLayout);
}

void EdgeInputDialog::connectSignalsSlots()
{
    connect(buttonOK, &QPushButton::clicked, this, &QDialog::accept);
    connect(buttonCancel, &QPushButton::clicked, this, &QDialog::reject);
}

QPair<int, int> EdgeInputDialog::getEdge() const
{
    bool ok1, ok2;
    int vertexA = lineEditVertexA->text().toInt(&ok1);
    int vertexB = lineEditVertexB->text().toInt(&ok2);

    // Check if conversion to integer was successful
    if (ok1 && ok2)
    {
        return qMakePair(vertexA, vertexB);
    }
    else
    {
        // Handle the case where the input is not valid integers
        // You may want to display an error message or take appropriate action.
        return qMakePair(-1, -1); // Return an invalid pair
    }
}
