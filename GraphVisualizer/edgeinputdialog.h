#ifndef EDGEINPUTDIALOG_H
#define EDGEINPUTDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPair>

class EdgeInputDialog : public QDialog
{
    Q_OBJECT
public:
    EdgeInputDialog(QWidget* parent = nullptr);

    QPair<int,int> getEdge() const;
private:
    QLabel *labelVertexA;
    QLabel *labelVertexB;
    QLineEdit *lineEditVertexA;
    QLineEdit *lineEditVertexB;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUI();
    void connectSignalsSlots();

};

#endif // EDGEINPUTDIALOG_H
