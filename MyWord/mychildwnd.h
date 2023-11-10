#ifndef MYCHILDWND_H
#define MYCHILDWND_H

#include <QWidget>
#include <QTextEdit>

class MyChildWnd : public QTextEdit
{
    Q_OBJECT
public:
    MyChildWnd();
    QString myCurDocPath;
    void newDoc();
    QString getCurDocName();
    bool loadDoc(const QString &docName);
    bool saveDoc();
    bool saveAsDoc();
    bool saveDocOpt(QString docName);
    void setFormatOnSelectedWord(const QTextCharFormat &fmt);
    void setAlignOfDocumentText (int aligntype);
    void setParaStyle (int pstyle) ;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void docBeModified();
private:
    bool beSaved;
    void setCurDoc(const QString &docName);
    bool promptSave();
};

#endif // MYCHILDWND_H
