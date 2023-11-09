#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawwidget.h"
#include <QToolButton>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createToolBar();
private:
    DrawWidget *drawWidget;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
public slots:
    void ShowStyle();
    void ShowColor();

};
#endif // MAINWINDOW_H
