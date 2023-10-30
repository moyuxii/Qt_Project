#ifndef BASEINFO_H
#define BASEINFO_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>

class baseInfo : public QWidget
{
    Q_OBJECT

public:
    baseInfo(QWidget *parent = nullptr);
    ~baseInfo();

private:
    QLabel *userName;
    QLabel *name;
    QLabel *sex;
    QLabel *department;
    QLabel *old;
    QLabel *other;
    QLabel *picture;
    QLabel *describe;

    QComboBox *sex_cb;

    QLineEdit *userName_lt;
    QLineEdit *name_lt;
    QTextEdit *dept_lt;
    QLineEdit *old_lt;
    QTextEdit *desc_lt;

    QPushButton *update;

    QGridLayout *leftLayout;
    QGridLayout *rightLayout;
    QGridLayout *mainLayout;

};

#endif // BASEINFO_H
