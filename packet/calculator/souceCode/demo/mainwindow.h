#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGridLayout *p_layout;
    //定义文本显示
    QLineEdit *text;
    //定义数字按键
    QPushButton *number0;
    QPushButton *number1;
    QPushButton *number2;
    QPushButton *number3;
    QPushButton *number4;
    QPushButton *number5;
    QPushButton *number6;
    QPushButton *number7;
    QPushButton *number8;
    QPushButton *number9;
    QPushButton *point;
    //定义功能按键
    QPushButton *add;
    QPushButton *sub;
    QPushButton *mult;
    QPushButton *div;
    QPushButton *equals;
    QPushButton *toBlack;

signals:

public slots:
    void getResult();
    void onNumberClick(QAbstractButton *button);
    void onOperationClick(QAbstractButton *button);

private:
    int currentType;
    double preNumber;
    bool flag;


};
#endif // MAINWINDOW_H
