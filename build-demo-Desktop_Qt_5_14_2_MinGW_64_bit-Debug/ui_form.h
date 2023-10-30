/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *classCode;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *searchText;
    QListView *questionList;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QCheckBox *checkBox;
    QPlainTextEdit *plainTextEdit_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(850, 832);
        horizontalLayout_5 = new QHBoxLayout(Form);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        classCode = new QLabel(Form);
        classCode->setObjectName(QString::fromUtf8("classCode"));

        horizontalLayout->addWidget(classCode);

        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        searchText = new QLineEdit(Form);
        searchText->setObjectName(QString::fromUtf8("searchText"));

        horizontalLayout_2->addWidget(searchText);


        verticalLayout_2->addLayout(horizontalLayout_2);

        questionList = new QListView(Form);
        questionList->setObjectName(QString::fromUtf8("questionList"));

        verticalLayout_2->addWidget(questionList);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(Form);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        plainTextEdit_2 = new QPlainTextEdit(Form);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));

        verticalLayout->addWidget(plainTextEdit_2);

        plainTextEdit_3 = new QPlainTextEdit(Form);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));

        verticalLayout->addWidget(plainTextEdit_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        checkBox = new QCheckBox(Form);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_3);

        plainTextEdit_4 = new QPlainTextEdit(Form);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));

        verticalLayout->addWidget(plainTextEdit_4);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_4);

#if QT_CONFIG(shortcut)
        classCode->setBuddy(comboBox);
        label->setBuddy(searchText);
        label_2->setBuddy(checkBox);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        classCode->setText(QCoreApplication::translate("Form", "\347\247\221\347\233\256\357\274\232 ", nullptr));
        label->setText(QCoreApplication::translate("Form", "\346\220\234\347\264\242\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        checkBox->setText(QCoreApplication::translate("Form", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
