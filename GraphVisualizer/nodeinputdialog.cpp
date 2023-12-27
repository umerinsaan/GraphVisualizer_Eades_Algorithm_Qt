#include "nodeinputdialog.h"

NodeInputDialog::NodeInputDialog(QWidget *parent)
    : QDialog(parent)
{
    nodeValueLineEdit = new QLineEdit(this);

    okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

    cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(nodeValueLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

QString NodeInputDialog::getNodeValue() const
{
    return nodeValueLineEdit->text();
}
