#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui->btnLoadImage,SIGNAL(clicked()),this,SLOT(loadImage()));

    ui->displayPaneArea->setWidget(ui->displayPane);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }

}

void MainWindow::loadImage(){
   QString fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

   QPixmap *mainImage = new QPixmap(fileName);

   qDebug() << "Loaded Image Size(W,H): (" << mainImage->width() << "," << mainImage->height()<< ")"<<endl;
   //imageMatrix = QByteArray()
   ui->displayPane->setPixmap(*mainImage);
}

