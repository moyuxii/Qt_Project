#include "mychildwnd.h"
#include <QFileInfo>
#include <QTextCodec>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

MyChildWnd::MyChildWnd()
{
    setAttribute(Qt::WA_DeleteOnClose);
    beSaved=false;
}
//创建文档使用的是 newDoc()方法，它的功能逻辑如下：
//(1) 设置窗口编号。
//(2) 保存文档路径（给 myCurDocPath 赋值）。
//(3) 设置子窗口标题。
//(4) 将文档内容改变信号 contentsChanged() 关联至 docBeModified()槽函数，用千显示文档
//被修改的状态标识。
void MyChildWnd::newDoc()
{
    static int wndSeqNum = 1;
    myCurDocPath = tr("Word 文档 %1").arg(wndSeqNum++);
    setWindowTitle(myCurDocPath+"[*]"+tr("- MyWord"));
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));

}

QString MyChildWnd::getCurDocName()
{
    return QFileInfo(myCurDocPath).fileName();
}

bool MyChildWnd::loadDoc(const QString &docName)
{
    QFile file(docName);
    if(!file.open(QFile::ReadOnly)){
        return false;
    }
    QByteArray text = file.readAll();
    QTextCodec *text_codec = Qt::codecForHtml(text);
    QString str = text_codec->toUnicode(text);
    if(Qt::mightBeRichText(str)){
        this->setHtml(str);
    }else{
        str = QString::fromLocal8Bit(text);
        this->setPlainText(str);
    }
    setCurDoc(docName);
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));
    return true;
}

bool MyChildWnd::saveDoc()
{
    if(!beSaved){
        return saveAsDoc();
    }else{
        return saveDocOpt(myCurDocPath);
    }
}

bool MyChildWnd::saveAsDoc()
{
    QString docName = QFileDialog::getSaveFileName(this,tr("另存为"),myCurDocPath,tr("HTML 文档 (*.htm *html);;所有文件 (*.*)"));
    qDebug()<<docName;
    if(docName.isEmpty()){
        return false;
    }else{
        return saveDocOpt(docName);
    }
}

bool MyChildWnd::saveDocOpt(QString docName)
{
    if(!(docName.endsWith(".htm",Qt::CaseInsensitive)||docName.endsWith(".html",Qt::CaseInsensitive))){
        docName += ".html";
    }
    QTextDocumentWriter writer(docName);
    bool success = writer.write(this->document());
    if(success){
        setCurDoc(docName);
    }
    return success;
}

void MyChildWnd::setFormatOnSelectedWord(const QTextCharFormat &fmt)
{
    //获取文本游标
    QTextCursor tcursor = this->textCursor();
    if(!tcursor.hasSelection()){
        tcursor.select(QTextCursor::WordUnderCursor);
    }
    // 以下a和b操作从游标和文本控件角度对格式进行更新设置，且当有selection时，格式作用于selection部分
    tcursor.mergeCharFormat(fmt);   //（a）
    this->mergeCurrentCharFormat(fmt); //(b)
}

void MyChildWnd::setAlignOfDocumentText(int aligntype)
{
    switch(aligntype){
    case 1:
        this->setAlignment(Qt::AlignLeft|Qt::AlignAbsolute);
        break;
    case 2:
        this->setAlignment(Qt::AlignHCenter);
        break;
    case 3:
        this->setAlignment(Qt::AlignRight|Qt::AlignAbsolute);
        break;
    case 4:
        this->setAlignment(Qt::AlignJustify);
        break;
    }
}

void MyChildWnd::closeEvent(QCloseEvent *event)
{
    if(promptSave()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MyChildWnd::docBeModified()
{
    setWindowModified(document()->isModified());
}

void MyChildWnd::setCurDoc(const QString &docName)
{
    myCurDocPath = QFileInfo(docName).canonicalFilePath();
    qDebug()<<myCurDocPath;
    beSaved = true;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(getCurDocName()+"[*]");
}

bool MyChildWnd::promptSave()
{
    if(!document()->isModified()){
        return true;
    }
    QMessageBox::StandardButton result;
    result = QMessageBox::warning(this,tr("MyWord"),tr("文档 %1 已被更改，保存吗?").arg(getCurDocName()),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
    if(result == QMessageBox::Save){
        return saveDoc();
    }else if(result == QMessageBox::Cancel){
        return false;
    }
    return true;
}
