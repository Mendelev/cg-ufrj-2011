#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "imageresizer.h"
#include "imagecropper.h"

#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QRgb>
#include <QPoint>
#include <QMouseEvent>
#include <string>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->btnLoadImage,SIGNAL(clicked()),this,SLOT(loadImage()));
    connect(ui->btnScaleImage,SIGNAL(clicked()),this,SLOT(scaleImage()));
    connect(ui->btnCropImage,SIGNAL(clicked()),this,SLOT(cropImage()));
    connect(ui->actionCrop, SIGNAL(triggered()), this, SLOT(showCrop()));
    connect(ui->actionScale, SIGNAL(triggered()),this,SLOT(showScale()));
    ui->displayPaneArea->setWidget(ui->displayPane);

    hideEverything();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideEverything(){
    ui->btnCropImage->hide();
    ui->btnScaleImage->hide();

    ui->lblHeight->hide();
    ui->lblWidth->hide();
    ui->lblStartPoint->hide();

    ui->txtHeight->hide();
    ui->txtWidth->hide();
    ui->txtStartPoint->hide();
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

void MainWindow::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        QPoint realStartCrop = QPoint(e->pos().x(),e->pos().y() - 33);
        this->startCrop = realStartCrop;
        ui->txtStartPoint->insertPlainText("Glu, glu , IE IE!");
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        this->endCrop = e->pos();
    }
}

void MainWindow::showScale(){

    ui->txtHeight->show();
    ui->txtWidth->show();
    ui->lblHeight->show();
    ui->lblWidth->show();
    ui->btnScaleImage->show();
}

void MainWindow::scaleImage(){

    this->imgResizer = ImageResizer(this->mainImage->toImage(),ui->txtWidth->toPlainText().toInt(),ui->txtHeight->toPlainText().toInt());
    this->imgResizer.transform();


}

void MainWindow::showCrop(){
    ui->lblHeight->show();
    ui->lblWidth->show();

    ui->txtHeight->show();
    ui->txtWidth->show();

    ui->btnCropImage->show();

    ui->txtStartPoint->show();
    ui->lblStartPoint->show();
}

void MainWindow::cropImage(){


    int width = this->endCrop.x() - this->startCrop.x();
    int height = this->endCrop.y() - this->startCrop.y();
    this->imgCropper = ImageCropper(this->mainImage->toImage(), width, height,this->startCrop);
    this->imgCropper.transform();

}

void MainWindow::loadImage(){


   this->fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

   this->mainImage = new QPixmap(fileName);


    ui->txtWidth->setPlainText(QString::number(mainImage->width()));
    ui->txtHeight->setPlainText(QString::number(mainImage->height()));





   ui->displayPane->setPixmap(*mainImage);
}

