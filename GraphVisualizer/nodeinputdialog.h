#ifndef NODEINPUTDIALOG_H
#define NODEINPUTDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class NodeInputDialog : public QDialog
{
    Q_OBJECT
public:
    NodeInputDialog(QWidget *parent = nullptr);

    QString getNodeValue() const;

private:
    QLineEdit *nodeValueLineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // NODEINPUTDIALOG_H
