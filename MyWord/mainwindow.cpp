#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QComboBox>
#include <QFontDatabase>
#include <QCloseEvent>
#include <QFileDialog>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    QFontDatabase fontdb;
    //获取所有字体
    foreach(QString font, fontdb.families())
        ui->fontComboBox->addItem(font);
    //获取标准字体大小
    foreach(int fontsize, fontdb.standardSizes ())
        ui->sizeComboBox->addItem(QString::number(fontsize));
    //初始化控件内容
    ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(QString::number(QApplication::font().pointSize ()))) ;
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->resize(width(),height()-22);
    //刷新菜单
    refreshMenus();
    //信号槽   信号在子窗口激活时emit
    connect(ui->mdiArea,SIGNAL(subWindowActivated(QMdiSubWindow *)),this,SLOT(refreshMenus()));
    //QSignalMapper 一个集合，将一个信号以及重新emit（发送int、string 或者widget）,见 addSubWndListMenu 函数实现
    myWndMapper = new QSignalMapper(this);
    connect(myWndMapper,SIGNAL(mapped(QWidget *)),this,SLOT(setActiveSubWindow(QWidget *)));
    addSubWndListMenu();
    //aboutToShow 此信号发生在打开菜单前触发
    connect(ui->menu_W,SIGNAL(aboutToShow()),this,SLOT(addSubWndListMenu()));
    //设置成一个菜单项组，任一时刻只能触发一个菜单
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->leftAlignAction);
    alignGroup->addAction(ui->centerAction);
    alignGroup->addAction(ui->rightAlignAction);
    alignGroup->addAction(ui->justifyAction);
    ui->leftAlignAction->setChecked(true);
}

void MainWindow::docNew()
{
    MyChildWnd *childWnd = new MyChildWnd;
    ui->mdiArea->addSubWindow(childWnd);
    connect(childWnd,SIGNAL(copyAvailable(bool)),ui->cutAction,SLOT(setEnabled(bool)));
    connect(childWnd,SIGNAL(copyAvailable(bool)),ui->copyAction,SLOT(setEnabled(bool)));
    childWnd->newDoc();
    childWnd->show();
    formatEnabled();
}

void MainWindow::docOpen()
{
    QString docName = QFileDialog::getOpenFileName(this,tr("打开"),QString(),tr("HTML 文档(*.htm *.html);;所有文件(*.*)"));
    if(!docName.isEmpty()){
        QMdiSubWindow *exist = findChildWnd(docName);
        if(exist){
            ui->mdiArea->setActiveSubWindow(exist);
            return;
        }
        MyChildWnd *childwnd = new MyChildWnd;
        ui->mdiArea->addSubWindow(childwnd);
        connect(childwnd,SIGNAL(copyAvailable(bool)),ui->cutAction,SLOT(setEnabled(bool)));
        connect(childwnd,SIGNAL(copyAvailable(bool)),ui->copyAction,SLOT(setEnabled(bool)));
        if(childwnd->loadDoc(docName)){
            statusBar()->showMessage(tr("文档已打开"),2000);
            childwnd->show();
            formatEnabled();
        }else{
            childwnd->close();
        }
    }
}

void MainWindow::docSave()
{
    if(activateChildWnd()&&activateChildWnd()->saveDoc()){
        statusBar()->showMessage(tr("保存成功"),2000);
    }

}
void MainWindow::docSaveAs(){
    if(activateChildWnd()&&activateChildWnd()->saveAsDoc()){
        statusBar()->showMessage(tr("保存成功"),2000);
    }
}

QMdiSubWindow* MainWindow::findChildWnd(QString docName)
{
    QString canonicalFilePath = QFileInfo(docName).canonicalFilePath();
    for(QMdiSubWindow *s : ui->mdiArea->subWindowList()){
        MyChildWnd *mychildwnd = qobject_cast<MyChildWnd *>(s->widget());
        if(canonicalFilePath == mychildwnd->myCurDocPath){
            return s;
        }
    }
    return 0;
}


void MainWindow::on_aboutAction_triggered()
{
    QMessageBox::about(this,tr("关于"),tr("这是一个基于QT5实现的字处理软件\r\n具备类似 微软office word的功能。"));
}

void MainWindow::on_newAction_triggered()
{
    docNew();
}

void MainWindow::on_aboutQtAction_triggered()
{
    QMessageBox::aboutQt(NULL,"关于 Qt 5");
}

void MainWindow::on_closeAction_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_closeAllAction_triggered()
{
    QMessageBox::StandardButton selectedBtn = QMessageBox::warning(this,tr("关闭所有窗口"),tr("确定吗？"),QMessageBox::Ok|QMessageBox::No);
    if(selectedBtn==QMessageBox::Ok){
        ui->mdiArea->closeAllSubWindows();
    }
}

void MainWindow::on_tileAction_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_cascadeAction_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_nextAction_triggered()
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_previousAction_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_openAction_triggered()
{
    docOpen();
}

void MainWindow::on_saveAction_triggered()
{
    docSave();
}

void MainWindow::on_saveAsAction_triggered()
{
    docSaveAs();
}

void MainWindow::on_undoAction_triggered()
{
    docUndo();
}

void MainWindow::on_redoAction_triggered(){
    docRedo();
}

void MainWindow::on_cutAction_triggered(){
    docCut();
}

void MainWindow::on_copyAction_triggered(){
    docCopy();
}

void MainWindow::on_pasteAction_triggered(){
    docPaste();
}

void MainWindow::on_boldAction_triggered()
{
    textBold();
}

void MainWindow::on_italicAction_triggered()
{
    textItalic();
}

void MainWindow::on_underlineAction_triggered()
{
    textUnderline();
}

void MainWindow::on_leftAlignAction_triggered()
{
    textAlign(ui->leftAlignAction);
}

void MainWindow::on_centerAction_triggered()
{
    textAlign(ui->centerAction);
}

void MainWindow::on_rightAlignAction_triggered(){
    textAlign(ui->rightAlignAction);
}

void MainWindow::on_justifyAction_triggered(){
    textAlign(ui->justifyAction);
}

void MainWindow::on_colorAction_triggered()
{
    textColor();
}

void MainWindow::on_fontComboBox_activated(const QString &arg1)
{
    textFamily(arg1);
}

void MainWindow::on_sizeComboBox_activated(const QString &arg1){
    textSize(arg1);
}

void MainWindow::docUndo(){
    if(activateChildWnd()){
        activateChildWnd()->undo();
    }
}


void MainWindow::docRedo(){
    if(activateChildWnd()){
        activateChildWnd()->redo();
    }
}


void MainWindow::docCut(){
    if(activateChildWnd()){
        activateChildWnd()->cut();
    }
}

void MainWindow::docCopy(){
    if(activateChildWnd()){
        activateChildWnd()->copy();
    }
}

void MainWindow::docPaste(){
    if(activateChildWnd()){
        activateChildWnd()->paste();
    }
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    QTextCharFormat selected = activateChildWnd()->textCursor().charFormat();
    fmt.setFontWeight((selected.fontWeight()==QFont::Normal)?QFont::Bold : QFont::Normal);
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    QTextCharFormat selected = activateChildWnd()->textCursor().charFormat();
    fmt.setFontItalic(!selected.fontItalic());
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    QTextCharFormat selected = activateChildWnd()->textCursor().charFormat();
    fmt.setFontUnderline(!selected.fontUnderline());
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textAlign(QAction *act)
{
    if(activateChildWnd()){
        if(act == ui->leftAlignAction){
            activateChildWnd()->setAlignOfDocumentText(1);
        }else if(act == ui->centerAction){
            activateChildWnd()->setAlignOfDocumentText(2);
        }else if(act == ui->rightAlignAction){
            activateChildWnd()->setAlignOfDocumentText(3);
        }else if(act == ui->justifyAction){
            activateChildWnd()->setAlignOfDocumentText(4);
        }
    }
}

void MainWindow::textFamily(const QString &fmly)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(fmly);
    if(activateChildWnd()){
        activateChildWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textSize(const QString &ps){
    qreal pointSize = ps.toFloat();
    if(ps.toFloat()>0){
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);
        if(activateChildWnd()){
            activateChildWnd()->setFormatOnSelectedWord(fmt);
        }
    }
}

void MainWindow::textColor()
{
    if(activateChildWnd()){
        QColor color = QColorDialog::getColor(activateChildWnd()->textColor(),this);
        if(!color.isValid()){
            return;
        }
        QTextCharFormat fmt;
        fmt.setForeground(color);
        activateChildWnd()->setFormatOnSelectedWord(fmt);
        QPixmap pix(16,16);
        pix.fill(color);
        ui->colorAction->setIcon(pix);
    }
}

void MainWindow::refreshMenus()
{
    bool hasChild = (activateChildWnd() !=0);
    ui->saveAction->setEnabled(hasChild);
    ui->saveAsAction->setEnabled(hasChild);
    ui->printAction->setEnabled(hasChild);
    ui->printPreviewAction->setEnabled(hasChild);
    ui->pasteAction->setEnabled(hasChild);
    ui->closeAction->setEnabled(hasChild);
    ui->closeAllAction->setEnabled(hasChild);
    ui->tileAction->setEnabled(hasChild);
    ui->cascadeAction->setEnabled(hasChild);
    ui->nextAction->setEnabled(hasChild);
    ui->previousAction->setEnabled(hasChild);
    //当活跃窗口有文字游标选中
    bool hasSelect = (activateChildWnd() && activateChildWnd()->textCursor().hasSelection());
    ui->cutAction->setEnabled(hasSelect);
    ui->copyAction->setEnabled(hasSelect);
    ui->boldAction->setEnabled(hasSelect);
    ui->italicAction->setEnabled(hasSelect);
    ui->underlineAction->setEnabled(hasSelect);
    ui->leftAlignAction->setEnabled(hasSelect);
    ui->centerAction->setEnabled(hasSelect);
    ui->rightAlignAction->setEnabled(hasSelect);
    ui->justifyAction->setEnabled(hasSelect);
    ui->colorAction->setEnabled(hasSelect);
}

void MainWindow::addSubWndListMenu()
{
    ui->menu_W->clear();
    ui->menu_W->addAction(ui->closeAction);
    ui->menu_W->addAction(ui->closeAllAction);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->tileAction);
    ui->menu_W->addAction(ui->cascadeAction);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->nextAction);
    ui->menu_W->addAction(ui->previousAction);
    QList<QMdiSubWindow *> wnds = ui->mdiArea->subWindowList();
    if(!wnds.isEmpty()){
        ui->menu_W->addSeparator();
    }
    for(int i=0;i<wnds.size();i++){
        MyChildWnd *childwnd = qobject_cast<MyChildWnd *>(wnds.at(i)->widget());
        QString menuitem_text;
        if(i<9){
            menuitem_text=tr("%1 %2").arg(i+1).arg(childwnd->getCurDocName());

        }else{
            menuitem_text=tr("%1 %2").arg(i+1).arg(childwnd->getCurDocName());
        }
        QAction *menuitem_act = ui->menu_W->addAction(menuitem_text);
        menuitem_act->setCheckable(true);
        menuitem_act->setChecked(childwnd==activateChildWnd());
        connect(menuitem_act,SIGNAL(triggered()),myWndMapper,SLOT(map()));
        myWndMapper->setMapping(menuitem_act,wnds.at(i));
    }
    formatEnabled();
}

void MainWindow::setActiveSubWindow(QWidget *widget)
{
    QMdiSubWindow *actSubWnd = qobject_cast<QMdiSubWindow *>(widget);
    ui->mdiArea->setActiveSubWindow(actSubWnd);
}

MyChildWnd *MainWindow::activateChildWnd()
{
    if(QMdiSubWindow *actSubWnd = ui->mdiArea->activeSubWindow()){
        return qobject_cast<MyChildWnd *>(actSubWnd->widget());
    }else{
        return 0;
    }
}

void MainWindow::formatEnabled()
{
    ui->boldAction->setEnabled(true);
    ui->italicAction->setEnabled(true);
    ui->underlineAction->setEnabled(true);
    ui->leftAlignAction->setEnabled(true);
    ui->centerAction->setEnabled(true);
    ui->rightAlignAction->setEnabled(true);
    ui->justifyAction->setEnabled(true);
    ui->colorAction->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
//    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()){
        QMessageBox::StandardButton selectedBtn = QMessageBox::warning(this,tr("关闭所有窗口"),tr("确定吗？"),QMessageBox::Ok|QMessageBox::No);
        if(selectedBtn==QMessageBox::Ok){
            event->accept();
        }else{
            event->ignore();
        }
    }else{
       event->accept();
    }
}

//监听主窗口大小变化事件，控制mdiArea大小变化
void MainWindow::resizeEvent(QResizeEvent *event)
{
    ui->mdiArea->resize(width(),height()-22);
}
