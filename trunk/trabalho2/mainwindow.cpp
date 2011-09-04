#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "imageresizer.h"

#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QRgb>
#include <string>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    connect(ui->btnLoadImage,SIGNAL(clicked()),this,SLOT(loadImage()));
    connect(ui->btnScaleImage,SIGNAL(clicked()),this,SLOT(scaleImage()));

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

void MainWindow::scaleImage(){

    this->imgResizer = ImageResizer(this->mainImage->toImage(),ui->txtWidth->text().toInt(),ui->txtHeight->text().toInt());
    this->imgResizer.transform();


}

void MainWindow::loadImage(){


   this->fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

   this->mainImage = new QPixmap(fileName);

   ui->txtWidth->setText(QString(mainImage->width()));
   ui->txtHeight->setText(QString(mainImage->height()));

   //QRgb imageMatrix[imgHeight][imgWidth];


//   for(int i = 0; i < imgHeight; i++){
//       for(int j = 0; j < imgWidth; j++){
//           imageMatrix[i][j] = imageModel.pixel(i,j);
//           qDebug() << "Pixel [" << i << ","<< j <<"] = " << imageModel.pixel(i,j) << endl;
//       }
//   }


   //qDebug() << "Loaded Image Size(W,H): (" << mainImage->width() << "," << mainImage->height()<< ")"<<endl;
   //qDebug() << "Loaded Image Size(W,H): (" << imgWidth << "," << imgHeight << ")"<<endl;

   //ui->displayPane->setPixmap(*mainImage);
   ui->displayPane->setPixmap(*mainImage);
}

