#include "imgprocessor.h"
#include <QFileDialog>
#include <QTextStream>
ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);

    createActions();
    createMenus();
    createToolBars();
    if(img.load("image.png"))
    {
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

ImgProcessor::~ImgProcessor()
{
}

void ImgProcessor::createActions(){
    openFileAction = new QAction(QIcon("open.png"),"打开",this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip("打开一个文件");
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(ShowOpenFile()));

    newFileAction = new QAction(QIcon("new.png"),"新建",this);
    newFileAction->setShortcut(tr("Ctrl+N"));
    newFileAction->setStatusTip("新建一个文件");
    connect(newFileAction,SIGNAL(triggered()),this,SLOT(ShowNewFile()));

    exitAction = new QAction("退出",this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip("退出程序");
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    copyAction = new QAction(QIcon("copy.png"),"复制",this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip("复制文件");
    connect(copyAction,SIGNAL(triggered()),showWidget->text,SLOT(copy()));

    cutAction = new QAction(QIcon("cut.png"),"剪切",this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip("剪切文件");
    connect(cutAction,SIGNAL(triggered()),showWidget->text,SLOT(cut()));

    pasteAction = new QAction(QIcon("paste.png"),"粘贴",this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip("粘贴文件");
    connect(pasteAction,SIGNAL(triggered()),showWidget->text,SLOT(paste()));


    aboutAction = new QAction("关于",this);
    connect(aboutAction,SIGNAL(triggered()),showWidget->text,SLOT(QApplication::about()));

    PrintTextAction = new QAction(QIcon("printText.png"),"打印文本",this);
    PrintTextAction->setStatusTip("打印一个文本");

    PrintImageAction = new QAction(QIcon("printImage.png"),"打印图片",this);
    PrintImageAction->setStatusTip("打印一个图片");

    zoomInAction = new QAction(QIcon("zoomIn.png"),"放大",this);
    zoomInAction->setStatusTip("放大一个图片");
    connect(zoomInAction,SIGNAL(triggered()),this,SLOT(ShowZoomIn()));

    zoomOutAction = new QAction(QIcon("zoomOut.png"),"缩小",this);
    zoomOutAction->setStatusTip("缩小一个图片");
    connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(ShowZoomOut()));

    rotate90Action = new QAction(QIcon("rotate90.png"),"旋转90度",this);
    rotate90Action->setStatusTip("图片旋转90度");

    rotate180Action = new QAction(QIcon("rotate180.png"),"旋转180度",this);
    rotate180Action->setStatusTip("图片旋转180度");

    rotate270Action = new QAction(QIcon("rotate270.png"),"旋转270度",this);
    rotate270Action->setStatusTip("图片旋转270度");

    mirrorVerticalAction = new QAction(QIcon("mirrorVertical.png"),"纵向镜像",this);
    mirrorVerticalAction->setStatusTip("图片做纵向镜像");

    mirrorHorzontalAction = new QAction(QIcon("mirrorHorzontal.png"),"横向镜像",this);
    mirrorHorzontalAction->setStatusTip("图片做横向镜像");

    undoAction = new QAction(QIcon("undo.png"),"撤销",this);
    connect(undoAction,SIGNAL(triggered()),showWidget->text,SLOT(undo()));

    redoAction = new QAction(QIcon("redo.png"),"重做",this);
    connect(redoAction,SIGNAL(triggered()),showWidget->text,SLOT(redo()));
}



void ImgProcessor::createMenus(){
    fileMenu = menuBar()->addMenu("文件");
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    zoomMenu = menuBar()->addMenu("编辑");
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);

    rotateMenu = menuBar()->addMenu("旋转");
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    mirrorMenu = menuBar()->addMenu("镜像");
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorzontalAction);
}

void ImgProcessor::createToolBars(){
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(newFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);

    zoomTool = addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);
}

void ImgProcessor::ShowNewFile(){
    ImgProcessor *newImgProcessor =new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::ShowOpenFile(){
    fileName = QFileDialog::getOpenFileName(this,"select","/","TEXT File(*.txt)");
    if(!fileName.isEmpty()){
        if(showWidget->text->document()->isEmpty()){
            loadFile(fileName);
        }else{
            ImgProcessor *newImgProcessor = new ImgProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void ImgProcessor::loadFile(QString filename){
    printf("file name:%s\n",filename.data());
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream textStream(&file);
        while(!textStream.atEnd()){
            showWidget->text->append(textStream.readLine());
            printf("read line\n");
        }
        printf("end\n");
    }
}

void ImgProcessor::ShowZoomIn(){
    if(img.isNull()){
        return;
    }
    QMatrix matrix;
    matrix.scale(2,2);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowZoomOut(){
    if(img.isNull()){
        return;
    }
    QMatrix matrix;
    matrix.scale(0.5,0.5);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}
