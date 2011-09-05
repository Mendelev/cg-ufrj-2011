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
    connect(ui->actionGScale, SIGNAL(triggered()), this, SLOT(showGScale()));
    connect(ui->btnGScale, SIGNAL(clicked()), this, SLOT(toGScale()));

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
    ui->lblRatio->hide();

    ui->txtHeight->hide();
    ui->txtWidth->hide();
    ui->txtStartPointX->hide();
    ui->txtStartPointY->hide();
    ui->txtRatioA->hide();
    ui->txtRatioB->hide();

    ui->txtAlpha->hide();
    ui->lblAlpha->hide();
    ui->btnGScale->hide();

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
        QPoint realStartCrop = QPoint(e->pos().x() - ( ui->displayPaneArea->x()  + 2 ),e->pos().y() - ( ui->displayPaneArea->y() + 37 ));
        this->startCrop = realStartCrop;
        ui->txtStartPointX->insertPlainText(QString::number(realStartCrop.x()));
        ui->txtStartPointY->insertPlainText(QString::number(realStartCrop.y()));
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
    ui->txtRatioA->show();
    ui->txtRatioB->show();




    ui->lblHeight->show();
    ui->lblWidth->show();
    ui->lblRatio->show();


    ui->btnScaleImage->show();

    ui->txtAlpha->hide();
    ui->lblAlpha->hide();

}

void MainWindow::showGScale(){
    ui->txtAlpha->show();

    ui->lblAlpha->show();

    ui->btnGScale->show();

    ui->txtAlpha->setPlainText(QString::number(0));

}

void MainWindow::toGScale(){
    this->imgFilter = ImageFilter(this->mainImage->toImage(),ui->txtWidth->toPlainText().toInt(),ui->txtHeight->toPlainText().toInt(), ui->txtAlpha->toPlainText().toInt());
    this->imgFilter.transform();

}

void MainWindow::scaleImage(){

    this->imgResizer = ImageResizer(this->mainImage->toImage(),ui->txtWidth->toPlainText().toInt(),ui->txtHeight->toPlainText().toInt(),ui->txtRatioA->toPlainText().toInt(), ui->txtRatioB->toPlainText().toInt());
    this->imgResizer.transform();


}

void MainWindow::showCrop(){
    ui->lblHeight->show();
    ui->lblWidth->show();

    ui->txtHeight->show();
    ui->txtWidth->show();

    ui->btnCropImage->show();

    ui->txtStartPointX->show();
    ui->txtStartPointY->show();
    ui->lblStartPoint->show();

    ui->txtAlpha->hide();
    ui->lblAlpha->hide();
}

void MainWindow::cropImage(){


    int width = this->endCrop.x() - this->startCrop.x();
    int height = this->endCrop.y() - this->startCrop.y();

    QPoint startPoint = QPoint(ui->txtStartPointX->toPlainText().toInt(), ui->txtStartPointX->toPlainText().toInt());

    if(ui->txtHeight->toPlainText().toInt() != this->mainImage->height()){
        if(ui->txtWidth->toPlainText().toInt() != this->mainImage->width()){
            this->imgCropper = ImageCropper(this->mainImage->toImage(), ui->txtWidth->toPlainText().toInt(), ui->txtHeight->toPlainText().toInt(),startPoint);
        }
    }
    else{
        this->imgCropper = ImageCropper(this->mainImage->toImage(), width, height,this->startCrop);
    }


    this->imgCropper.transform();

}

void MainWindow::loadImage(){


   this->fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

   this->mainImage = new QPixmap(fileName);


    ui->txtWidth->setPlainText(QString::number(mainImage->width()));
    ui->txtHeight->setPlainText(QString::number(mainImage->height()));

    ui->txtRatioA->setPlainText(QString::number(0));
    ui->txtRatioB->setPlainText(QString::number(0));


    ui->displayPaneArea->resize(1200,650);

    ui->btnLoadImage->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,ui->btnLoadImage->y());
    ui->btnCropImage->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->btnCropImage->y());
    ui->btnScaleImage->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->btnScaleImage->y());

    ui->lblHeight->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->lblHeight->y());
    ui->lblWidth->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->lblWidth->y());
    ui->lblStartPoint->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->lblStartPoint->y());
    ui->lblRatio->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->lblRatio->y());
    ui->lblAlpha->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->lblRatio->y());

    ui->txtHeight->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->txtHeight->y());
    ui->txtWidth->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->txtWidth->y());
    ui->txtStartPointX->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->txtStartPointX->y());
    ui->txtStartPointY->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->txtStartPointY->y());

    ui->txtRatioA->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + 10,  ui->txtRatioA->y());
    ui->txtRatioB->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() + ui->txtRatioA->width() + 20 ,  ui->txtRatioB->y());

    ui->txtAlpha->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() ,  ui->txtAlpha->y());
    ui->btnGScale->move(ui->displayPaneArea->x()+ui->displayPaneArea->width() ,  ui->btnGScale->y());


   ui->displayPane->setPixmap(*mainImage);
}

