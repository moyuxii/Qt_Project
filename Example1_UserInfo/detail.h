#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>

class detail:public QWidget
{
    Q_OBJECT
public:
    detail(QWidget *parent=nullptr);

private:
   QGridLayout *mainLayout;

   QLabel *guo;
   QLabel *shen;
   QLabel *shi;
   QLabel *desc;

   QComboBox *guo_cb;
   QComboBox *shen_cb;

   QLineEdit *shi_lt;
   QLineEdit *desc_lt;

};

#endif // DETAIL_H
