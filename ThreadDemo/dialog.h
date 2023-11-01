#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
class Dialog:public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent=nullptr);
    ~Dialog();
private:
    QLabel *label1;
    QLabel *label2;
    QPushButton *quitBtn;

};

#endif // DIALOG_H
