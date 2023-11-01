#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>
class Networkinformation:public QWidget
{
    Q_OBJECT
public:
    Networkinformation(QWidget *parent=nullptr);
    ~Networkinformation();
    void getHostinformation ();
public slots:
    void slotDetail();
private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;
};

#endif // NETWORKINFORMATION_H
