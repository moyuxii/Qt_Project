/********************************************************************************
** Form generated from reading UI file 'connectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDLG_H
#define UI_CONNECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QSqlConnectionDialogUi
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *connCroupBox;
    QGridLayout *gridLayout;
    QLabel *textLabel2;
    QComboBox *comboDriver;
    QLabel *textLabel3;
    QLineEdit *editDatabase;
    QLabel *textLabel4;
    QLineEdit *editUsemame;
    QLabel *textLabel4_2;
    QLineEdit *editPassword;
    QLabel *textLabel5;
    QLineEdit *editHostname;
    QLabel *textLabel5_2;
    QSpinBox *portSpinBox;
    QLabel *status_label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *QSqlConnectionDialogUi)
    {
        if (QSqlConnectionDialogUi->objectName().isEmpty())
            QSqlConnectionDialogUi->setObjectName(QString::fromUtf8("QSqlConnectionDialogUi"));
        QSqlConnectionDialogUi->resize(350, 251);
        verticalLayout = new QVBoxLayout(QSqlConnectionDialogUi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        connCroupBox = new QGroupBox(QSqlConnectionDialogUi);
        connCroupBox->setObjectName(QString::fromUtf8("connCroupBox"));
        gridLayout = new QGridLayout(connCroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textLabel2 = new QLabel(connCroupBox);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));

        gridLayout->addWidget(textLabel2, 0, 0, 1, 1);

        comboDriver = new QComboBox(connCroupBox);
        comboDriver->setObjectName(QString::fromUtf8("comboDriver"));
        comboDriver->setFrame(true);

        gridLayout->addWidget(comboDriver, 0, 1, 1, 1);

        textLabel3 = new QLabel(connCroupBox);
        textLabel3->setObjectName(QString::fromUtf8("textLabel3"));

        gridLayout->addWidget(textLabel3, 1, 0, 1, 1);

        editDatabase = new QLineEdit(connCroupBox);
        editDatabase->setObjectName(QString::fromUtf8("editDatabase"));

        gridLayout->addWidget(editDatabase, 1, 1, 1, 1);

        textLabel4 = new QLabel(connCroupBox);
        textLabel4->setObjectName(QString::fromUtf8("textLabel4"));

        gridLayout->addWidget(textLabel4, 2, 0, 1, 1);

        editUsemame = new QLineEdit(connCroupBox);
        editUsemame->setObjectName(QString::fromUtf8("editUsemame"));

        gridLayout->addWidget(editUsemame, 2, 1, 1, 1);

        textLabel4_2 = new QLabel(connCroupBox);
        textLabel4_2->setObjectName(QString::fromUtf8("textLabel4_2"));

        gridLayout->addWidget(textLabel4_2, 3, 0, 1, 1);

        editPassword = new QLineEdit(connCroupBox);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));

        gridLayout->addWidget(editPassword, 3, 1, 1, 1);

        textLabel5 = new QLabel(connCroupBox);
        textLabel5->setObjectName(QString::fromUtf8("textLabel5"));

        gridLayout->addWidget(textLabel5, 4, 0, 1, 1);

        editHostname = new QLineEdit(connCroupBox);
        editHostname->setObjectName(QString::fromUtf8("editHostname"));

        gridLayout->addWidget(editHostname, 4, 1, 1, 1);

        textLabel5_2 = new QLabel(connCroupBox);
        textLabel5_2->setObjectName(QString::fromUtf8("textLabel5_2"));

        gridLayout->addWidget(textLabel5_2, 5, 0, 1, 1);

        portSpinBox = new QSpinBox(connCroupBox);
        portSpinBox->setObjectName(QString::fromUtf8("portSpinBox"));

        gridLayout->addWidget(portSpinBox, 5, 1, 1, 1);


        verticalLayout->addWidget(connCroupBox);

        status_label = new QLabel(QSqlConnectionDialogUi);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setFrameShape(QFrame::Panel);

        verticalLayout->addWidget(status_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(QSqlConnectionDialogUi);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(QSqlConnectionDialogUi);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

#if QT_CONFIG(shortcut)
        textLabel2->setBuddy(comboDriver);
        textLabel3->setBuddy(editDatabase);
        textLabel4->setBuddy(editUsemame);
        textLabel4_2->setBuddy(editPassword);
        textLabel5->setBuddy(editHostname);
        textLabel5_2->setBuddy(portSpinBox);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QSqlConnectionDialogUi);

        QMetaObject::connectSlotsByName(QSqlConnectionDialogUi);
    } // setupUi

    void retranslateUi(QDialog *QSqlConnectionDialogUi)
    {
        QSqlConnectionDialogUi->setWindowTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "Dialog", nullptr));
        connCroupBox->setTitle(QCoreApplication::translate("QSqlConnectionDialogUi", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        textLabel2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\351\251\261\345\212\250:", nullptr));
        textLabel3->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\346\225\260\346\215\256\345\272\223\345\220\215:", nullptr));
        textLabel4->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\224\250\346\210\267\345\220\215:", nullptr));
        textLabel4_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\345\257\206\347\240\201:", nullptr));
        textLabel5->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\344\270\273\346\234\272\345\220\215:", nullptr));
        textLabel5_2->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\253\257\345\217\243:", nullptr));
        status_label->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\347\212\266\346\200\201", nullptr));
        okButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\350\277\236\346\216\245", nullptr));
        cancelButton->setText(QCoreApplication::translate("QSqlConnectionDialogUi", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QSqlConnectionDialogUi: public Ui_QSqlConnectionDialogUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDLG_H
