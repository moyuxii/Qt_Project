#ifndef CONTACT_H
#define CONTACT_H

#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QCheckBox>
#include <QWidget>
class contact:public QWidget
{
    Q_OBJECT
public:
    contact(QWidget *parent=nullptr);
    ~contact();
private:
    QLabel *email;
    QLabel *address;
    QLabel *code;
    QLabel *mobilePhone;
    QLabel *busPhone;

    QLineEdit *email_lt;
    QLineEdit *address_lt;
    QLineEdit *code_lt;
    QLineEdit *mobile_lt;
    QLineEdit *bus_lt;

    QCheckBox *flag;

    QGridLayout *mainLayout;

};

#endif // CONTACT_H
