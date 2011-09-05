/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Aug 18 02:22:55 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *BotaoFecha;
    QAction *actionRand;
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *btnLoadImage;
    QLabel *displayPane;
    QScrollArea *displayPaneArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *displayPaneLayout;
    QPushButton *btnScaleImage;
    QLabel *lblWidth;
    QLabel *lblHeight;
    QPlainTextEdit *txtWidth;
    QPlainTextEdit *txtHeight;
    QPushButton *btnCropImage;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        BotaoFecha = new QAction(MainWindow);
        BotaoFecha->setObjectName(QString::fromUtf8("BotaoFecha"));
        actionRand = new QAction(MainWindow);
        actionRand->setObjectName(QString::fromUtf8("actionRand"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnLoadImage = new QPushButton(centralWidget);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        btnLoadImage->setGeometry(QRect(470, 10, 111, 27));
        displayPane = new QLabel(centralWidget);
        displayPane->setObjectName(QString::fromUtf8("displayPane"));
        displayPane->setGeometry(QRect(0, 0, 66, 21));
        displayPaneArea = new QScrollArea(centralWidget);
        displayPaneArea->setObjectName(QString::fromUtf8("displayPaneArea"));
        displayPaneArea->setGeometry(QRect(0, 0, 451, 251));
        displayPaneArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 449, 249));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 160, 80));
        displayPaneLayout = new QGridLayout(gridLayoutWidget);
        displayPaneLayout->setSpacing(6);
        displayPaneLayout->setContentsMargins(11, 11, 11, 11);
        displayPaneLayout->setObjectName(QString::fromUtf8("displayPaneLayout"));
        displayPaneLayout->setContentsMargins(0, 0, 0, 0);
        displayPaneArea->setWidget(scrollAreaWidgetContents);
        btnScaleImage = new QPushButton(centralWidget);
        btnScaleImage->setObjectName(QString::fromUtf8("btnScaleImage"));
        btnScaleImage->setGeometry(QRect(470, 210, 92, 27));
        lblWidth = new QLabel(centralWidget);
        lblWidth->setObjectName(QString::fromUtf8("lblWidth"));
        lblWidth->setGeometry(QRect(470, 50, 59, 17));
        lblHeight = new QLabel(centralWidget);
        lblHeight->setObjectName(QString::fromUtf8("lblHeight"));
        lblHeight->setGeometry(QRect(470, 130, 59, 17));
        txtWidth = new QPlainTextEdit(centralWidget);
        txtWidth->setObjectName(QString::fromUtf8("txtWidth"));
        txtWidth->setGeometry(QRect(470, 80, 81, 41));
        txtHeight = new QPlainTextEdit(centralWidget);
        txtHeight->setObjectName(QString::fromUtf8("txtHeight"));
        txtHeight->setGeometry(QRect(470, 150, 81, 41));
        btnCropImage = new QPushButton(centralWidget);
        btnCropImage->setObjectName(QString::fromUtf8("btnCropImage"));
        btnCropImage->setGeometry(QRect(470, 250, 95, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 29));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionExit);
        menuMenu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        BotaoFecha->setText(QApplication::translate("MainWindow", "fechar", 0, QApplication::UnicodeUTF8));
        actionRand->setText(QApplication::translate("MainWindow", "Rand", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        btnLoadImage->setText(QApplication::translate("MainWindow", "Load Image...", 0, QApplication::UnicodeUTF8));
        displayPane->setText(QString());
        btnScaleImage->setText(QApplication::translate("MainWindow", "Scale...", 0, QApplication::UnicodeUTF8));
        lblWidth->setText(QApplication::translate("MainWindow", "Width:", 0, QApplication::UnicodeUTF8));
        lblHeight->setText(QApplication::translate("MainWindow", "Height:", 0, QApplication::UnicodeUTF8));
        btnCropImage->setText(QApplication::translate("MainWindow", "Crop...", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
