#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QRgb>

using namespace std;

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

   QImage imageModel;
   QString fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

   QPixmap *mainImage = new QPixmap(fileName);
   imageModel = mainImage->toImage();

   int imgWidth = mainImage->width();
   int imgHeight= mainImage->height();

   QRgb imageMatrix[imgHeight][imgWidth];


   for(int i = 0; i < imgHeight; i++){
       for(int j = 0; j < imgWidth; j++){
           imageMatrix[i][j] = imageModel.pixel(i,j);
           qDebug() << "Pixel [" << i << ","<< j <<"] = " << imageModel.pixel(i,j) << endl;
       }
   }


   //qDebug() << "Loaded Image Size(W,H): (" << mainImage->width() << "," << mainImage->height()<< ")"<<endl;
   //qDebug() << "Loaded Image Size(W,H): (" << imgWidth << "," << imgHeight << ")"<<endl;

   //ui->displayPane->setPixmap(*mainImage);
   ui->displayPane->setPixmap(*mainImage);
}

