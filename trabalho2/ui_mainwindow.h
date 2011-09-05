/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Sep 5 10:55:57 2011
**      by: Qt User Interface Compiler version 4.6.3
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
    QAction *actionScale;
    QAction *actionCrop;
    QAction *actionGScale;
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
    QPlainTextEdit *txtStartPointX;
    QLabel *lblStartPoint;
    QPlainTextEdit *txtStartPointY;
    QLabel *lblRatio;
    QPlainTextEdit *txtRatioA;
    QPlainTextEdit *txtRatioB;
    QLabel *lblAlpha;
    QPlainTextEdit *txtAlpha;
    QPushButton *btnGScale;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(703, 589);
        BotaoFecha = new QAction(MainWindow);
        BotaoFecha->setObjectName(QString::fromUtf8("BotaoFecha"));
        actionRand = new QAction(MainWindow);
        actionRand->setObjectName(QString::fromUtf8("actionRand"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName(QString::fromUtf8("actionScale"));
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QString::fromUtf8("actionCrop"));
        actionGScale = new QAction(MainWindow);
        actionGScale->setObjectName(QString::fromUtf8("actionGScale"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btnLoadImage = new QPushButton(centralWidget);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        btnLoadImage->setGeometry(QRect(470, 10, 111, 27));
        displayPane = new QLabel(centralWidget);
        displayPane->setObjectName(QString::fromUtf8("displayPane"));
        displayPane->setGeometry(QRect(0, 0, 66, 21));
        displayPane->setCursor(QCursor(Qt::ArrowCursor));
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
        btnScaleImage->setGeometry(QRect(480, 420, 92, 27));
        lblWidth = new QLabel(centralWidget);
        lblWidth->setObjectName(QString::fromUtf8("lblWidth"));
        lblWidth->setGeometry(QRect(480, 110, 59, 17));
        lblHeight = new QLabel(centralWidget);
        lblHeight->setObjectName(QString::fromUtf8("lblHeight"));
        lblHeight->setGeometry(QRect(480, 40, 59, 17));
        txtWidth = new QPlainTextEdit(centralWidget);
        txtWidth->setObjectName(QString::fromUtf8("txtWidth"));
        txtWidth->setGeometry(QRect(480, 130, 81, 41));
        txtHeight = new QPlainTextEdit(centralWidget);
        txtHeight->setObjectName(QString::fromUtf8("txtHeight"));
        txtHeight->setGeometry(QRect(480, 60, 81, 41));
        btnCropImage = new QPushButton(centralWidget);
        btnCropImage->setObjectName(QString::fromUtf8("btnCropImage"));
        btnCropImage->setGeometry(QRect(480, 380, 91, 31));
        txtStartPointX = new QPlainTextEdit(centralWidget);
        txtStartPointX->setObjectName(QString::fromUtf8("txtStartPointX"));
        txtStartPointX->setGeometry(QRect(480, 280, 91, 41));
        lblStartPoint = new QLabel(centralWidget);
        lblStartPoint->setObjectName(QString::fromUtf8("lblStartPoint"));
        lblStartPoint->setGeometry(QRect(480, 260, 91, 17));
        txtStartPointY = new QPlainTextEdit(centralWidget);
        txtStartPointY->setObjectName(QString::fromUtf8("txtStartPointY"));
        txtStartPointY->setGeometry(QRect(480, 330, 91, 41));
        lblRatio = new QLabel(centralWidget);
        lblRatio->setObjectName(QString::fromUtf8("lblRatio"));
        lblRatio->setGeometry(QRect(480, 180, 91, 17));
        txtRatioA = new QPlainTextEdit(centralWidget);
        txtRatioA->setObjectName(QString::fromUtf8("txtRatioA"));
        txtRatioA->setGeometry(QRect(480, 200, 31, 41));
        txtRatioB = new QPlainTextEdit(centralWidget);
        txtRatioB->setObjectName(QString::fromUtf8("txtRatioB"));
        txtRatioB->setGeometry(QRect(520, 200, 31, 41));
        lblAlpha = new QLabel(centralWidget);
        lblAlpha->setObjectName(QString::fromUtf8("lblAlpha"));
        lblAlpha->setGeometry(QRect(480, 40, 59, 17));
        txtAlpha = new QPlainTextEdit(centralWidget);
        txtAlpha->setObjectName(QString::fromUtf8("txtAlpha"));
        txtAlpha->setGeometry(QRect(480, 60, 81, 41));
        btnGScale = new QPushButton(centralWidget);
        btnGScale->setObjectName(QString::fromUtf8("btnGScale"));
        btnGScale->setGeometry(QRect(480, 110, 111, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 703, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuMenu->addAction(actionExit);
        menuMenu->addSeparator();
        menuEdit->addAction(actionScale);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCrop);
        menuEdit->addSeparator();
        menuEdit->addAction(actionGScale);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        BotaoFecha->setText(QApplication::translate("MainWindow", "fechar", 0, QApplication::UnicodeUTF8));
        actionRand->setText(QApplication::translate("MainWindow", "Rand", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionScale->setText(QApplication::translate("MainWindow", "Scale...", 0, QApplication::UnicodeUTF8));
        actionCrop->setText(QApplication::translate("MainWindow", "Crop...", 0, QApplication::UnicodeUTF8));
        actionGScale->setText(QApplication::translate("MainWindow", "Gray Scale...", 0, QApplication::UnicodeUTF8));
        btnLoadImage->setText(QApplication::translate("MainWindow", "Load Image...", 0, QApplication::UnicodeUTF8));
        displayPane->setText(QString());
        btnScaleImage->setText(QApplication::translate("MainWindow", "Scale...", 0, QApplication::UnicodeUTF8));
        lblWidth->setText(QApplication::translate("MainWindow", "Width:", 0, QApplication::UnicodeUTF8));
        lblHeight->setText(QApplication::translate("MainWindow", "Height:", 0, QApplication::UnicodeUTF8));
        btnCropImage->setText(QApplication::translate("MainWindow", "Crop...", 0, QApplication::UnicodeUTF8));
        lblStartPoint->setText(QApplication::translate("MainWindow", "Start Point:", 0, QApplication::UnicodeUTF8));
        lblRatio->setText(QApplication::translate("MainWindow", "Ratio:", 0, QApplication::UnicodeUTF8));
        lblAlpha->setText(QApplication::translate("MainWindow", "Alpha:", 0, QApplication::UnicodeUTF8));
        btnGScale->setText(QApplication::translate("MainWindow", "Go GrayScale...", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
