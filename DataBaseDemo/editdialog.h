#ifndef EDITDIALOG_H
#define EDITDIALOG_H
#include "ui_connectdlg.h"
#include <QDialogButtonBox>
#include <QSqlRelationalTableModel>
#include <QDomDocument>
#include <QFile>
class EditDialog:public QDialog
{
    Q_OBJECT
public:
    EditDialog(QSqlRelationalTableModel *cars, QSqlTableModel *factory,
    QDomDocument details, QFile *output, QWidget *parent= 0);
private slots:
    void revert();
    void submit();
private:
    int addNewCar(const QString &name, int factoryId);
    int addNewFactory(const QString &factory,const QString &address);
    void addAttribs(int carid, QStringList attribs);
    QDialogButtonBox *createButtons();
    QGroupBox *createInputWidgets();
    int findFactoryTd(const QString &factory);
    int generateCarId();
    int generateFactoryId();
    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;
    QDomDocument carDetails;
    QFile *outputFile;
    QLineEdit *factoryEditor;
    QLineEdit *addressEditor;
    QLineEdit *carEditor;
    QSpinBox *yearEditor;
    QLineEdit *attribEditor;
};

#endif // EDITDIALOG_H
