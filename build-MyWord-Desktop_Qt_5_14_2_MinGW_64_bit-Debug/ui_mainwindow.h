/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *printAction;
    QAction *printPreviewAction;
    QAction *exitaAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *boldAction;
    QAction *italicAction;
    QAction *underlineAction;
    QAction *leftAlignAction;
    QAction *centerAction;
    QAction *rightAlignAction;
    QAction *justifyAction;
    QAction *colorAction;
    QAction *closeAction;
    QAction *closeAllAction;
    QAction *tileAction;
    QAction *cascadeAction;
    QAction *nextAction;
    QAction *previousAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QWidget *centralwidget;
    QComboBox *sizeComboBox;
    QComboBox *fontComboBox;
    QComboBox *comboBox;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_D;
    QMenu *menu;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1116, 600);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QString::fromUtf8("newAction"));
        newAction->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-ImageProcessor-Desktop_Qt_5_14_2_MinGW_64_bit-Debug/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QString::fromUtf8("saveAsAction"));
        printAction = new QAction(MainWindow);
        printAction->setObjectName(QString::fromUtf8("printAction"));
        printPreviewAction = new QAction(MainWindow);
        printPreviewAction->setObjectName(QString::fromUtf8("printPreviewAction"));
        exitaAction = new QAction(MainWindow);
        exitaAction->setObjectName(QString::fromUtf8("exitaAction"));
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QString::fromUtf8("undoAction"));
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QString::fromUtf8("redoAction"));
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QString::fromUtf8("cutAction"));
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QString::fromUtf8("copyAction"));
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QString::fromUtf8("pasteAction"));
        boldAction = new QAction(MainWindow);
        boldAction->setObjectName(QString::fromUtf8("boldAction"));
        boldAction->setCheckable(false);
        italicAction = new QAction(MainWindow);
        italicAction->setObjectName(QString::fromUtf8("italicAction"));
        underlineAction = new QAction(MainWindow);
        underlineAction->setObjectName(QString::fromUtf8("underlineAction"));
        leftAlignAction = new QAction(MainWindow);
        leftAlignAction->setObjectName(QString::fromUtf8("leftAlignAction"));
        centerAction = new QAction(MainWindow);
        centerAction->setObjectName(QString::fromUtf8("centerAction"));
        rightAlignAction = new QAction(MainWindow);
        rightAlignAction->setObjectName(QString::fromUtf8("rightAlignAction"));
        justifyAction = new QAction(MainWindow);
        justifyAction->setObjectName(QString::fromUtf8("justifyAction"));
        colorAction = new QAction(MainWindow);
        colorAction->setObjectName(QString::fromUtf8("colorAction"));
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QString::fromUtf8("closeAction"));
        closeAllAction = new QAction(MainWindow);
        closeAllAction->setObjectName(QString::fromUtf8("closeAllAction"));
        tileAction = new QAction(MainWindow);
        tileAction->setObjectName(QString::fromUtf8("tileAction"));
        cascadeAction = new QAction(MainWindow);
        cascadeAction->setObjectName(QString::fromUtf8("cascadeAction"));
        nextAction = new QAction(MainWindow);
        nextAction->setObjectName(QString::fromUtf8("nextAction"));
        previousAction = new QAction(MainWindow);
        previousAction->setObjectName(QString::fromUtf8("previousAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        aboutQtAction = new QAction(MainWindow);
        aboutQtAction->setObjectName(QString::fromUtf8("aboutQtAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizeComboBox = new QComboBox(centralwidget);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(280, 0, 69, 22));
        fontComboBox = new QComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(80, 0, 201, 22));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 81, 22));
        comboBox->setAutoFillBackground(false);
        comboBox->setFrame(true);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 20, 820, 395));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 23));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_O = new QMenu(menubar);
        menu_O->setObjectName(QString::fromUtf8("menu_O"));
        menu_D = new QMenu(menu_O);
        menu_D->setObjectName(QString::fromUtf8("menu_D"));
        menu = new QMenu(menu_O);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_W = new QMenu(menubar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(newAction);
        menu_F->addAction(openAction);
        menu_F->addSeparator();
        menu_F->addAction(saveAction);
        menu_F->addAction(saveAsAction);
        menu_F->addSeparator();
        menu_F->addAction(printAction);
        menu_F->addAction(printPreviewAction);
        menu_F->addSeparator();
        menu_F->addAction(exitaAction);
        menu_E->addAction(undoAction);
        menu_E->addAction(redoAction);
        menu_E->addAction(cutAction);
        menu_E->addAction(copyAction);
        menu_E->addAction(pasteAction);
        menu_O->addAction(menu_D->menuAction());
        menu_O->addAction(menu->menuAction());
        menu_O->addAction(colorAction);
        menu_D->addAction(boldAction);
        menu_D->addAction(italicAction);
        menu_D->addAction(underlineAction);
        menu->addAction(leftAlignAction);
        menu->addAction(centerAction);
        menu->addAction(rightAlignAction);
        menu->addAction(justifyAction);
        menu_W->addAction(closeAction);
        menu_W->addAction(closeAllAction);
        menu_W->addAction(tileAction);
        menu_W->addAction(cascadeAction);
        menu_W->addAction(nextAction);
        menu_W->addAction(previousAction);
        menu_H->addAction(aboutAction);
        menu_H->addAction(aboutQtAction);
        toolBar->addAction(newAction);
        toolBar->addAction(openAction);
        toolBar->addAction(saveAction);
        toolBar->addAction(printAction);
        toolBar->addSeparator();
        toolBar->addAction(undoAction);
        toolBar->addAction(redoAction);
        toolBar->addAction(cutAction);
        toolBar->addAction(copyAction);
        toolBar->addAction(pasteAction);
        toolBar->addSeparator();
        toolBar->addAction(boldAction);
        toolBar->addAction(italicAction);
        toolBar->addAction(underlineAction);
        toolBar->addSeparator();
        toolBar->addAction(leftAlignAction);
        toolBar->addAction(centerAction);
        toolBar->addAction(rightAlignAction);
        toolBar->addAction(justifyAction);
        toolBar->addSeparator();
        toolBar->addAction(colorAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#if QT_CONFIG(statustip)
        newAction->setStatusTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252\346\226\260\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        newAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        openAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(shortcut)
        openAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAction->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(shortcut)
        saveAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAsAction->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)", nullptr));
        printAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260(P)", nullptr));
#if QT_CONFIG(shortcut)
        printAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        printPreviewAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210", nullptr));
        exitaAction->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(X)", nullptr));
        undoAction->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(U)", nullptr));
#if QT_CONFIG(shortcut)
        undoAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redoAction->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232(R)", nullptr));
#if QT_CONFIG(shortcut)
        redoAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        cutAction->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207(T)", nullptr));
#if QT_CONFIG(shortcut)
        cutAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        copyAction->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#if QT_CONFIG(shortcut)
        copyAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        pasteAction->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(P)", nullptr));
#if QT_CONFIG(shortcut)
        pasteAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        boldAction->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227(B)", nullptr));
#if QT_CONFIG(shortcut)
        boldAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        italicAction->setText(QCoreApplication::translate("MainWindow", "\345\200\276\346\226\234(I)", nullptr));
#if QT_CONFIG(shortcut)
        italicAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        underlineAction->setText(QCoreApplication::translate("MainWindow", "\344\270\213\347\224\273\347\272\277(U)", nullptr));
#if QT_CONFIG(shortcut)
        underlineAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        leftAlignAction->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220(L)", nullptr));
#if QT_CONFIG(shortcut)
        leftAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        centerAction->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255(E)", nullptr));
#if QT_CONFIG(shortcut)
        centerAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        rightAlignAction->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220(R)", nullptr));
#if QT_CONFIG(shortcut)
        rightAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        justifyAction->setText(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220(J)", nullptr));
#if QT_CONFIG(shortcut)
        justifyAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_CONFIG(shortcut)
        colorAction->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262(C)", nullptr));
        closeAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255(O)", nullptr));
        closeAllAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(A)", nullptr));
        tileAction->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272(T)", nullptr));
        cascadeAction->setText(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240(C)", nullptr));
        nextAction->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(X)", nullptr));
#if QT_CONFIG(shortcut)
        nextAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        previousAction->setText(QCoreApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252(V)", nullptr));
#if QT_CONFIG(shortcut)
        previousAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        aboutAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", nullptr));
        aboutQtAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216Qt 5(Q)", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206", nullptr));

        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(O)", nullptr));
        menu_D->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(D)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\256\265\350\220\275", nullptr));
        menu_W->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243(W)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
