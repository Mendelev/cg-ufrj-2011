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
    connect(ui->actionScale, SIGNAL(triggered()),this,SLOT(startScaleMode()));
    connect(ui->btnLoadImage,SIGNAL(clicked()),this,SLOT(loadImage()));
    connect(ui->btnScaleImage,SIGNAL(clicked()),this,SLOT(scaleImage()));


    ui->displayPaneArea->setWidget(ui->displayPane);

    //Hide all the Scale Specific QWidgets
    ui->btnScaleImage->hide();
    ui->txtHeight->hide();
    ui->txtWidth->hide();
    ui->lblHeight->hide();
    ui->lblWidth->hide();
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

void MainWindow::startScaleMode(){

    //Show all the Scale Specific QWidgets
    ui->lblHeight->show();
    ui->lblWidth->show();
    ui->txtHeight->show();
    ui->txtWidth->show();
    ui->btnScaleImage->show();
}

void MainWindow::scaleImage(){

    this->imgResizer = ImageResizer(this->mainImage->toImage(),ui->txtWidth->text().toInt(),ui->txtHeight->text().toInt());
    this->imgResizer.transform();
}

void MainWindow::loadImage(){

    int imgHeight;
    int imgWidth;
    QImage imageModel;

    this->fileName = QFileDialog::getOpenFileName(this,tr("Open Fire"),"",tr("Files (*.*)"));

    this->mainImage = new QPixmap(fileName);

    imageModel = this->mainImage->toImage();
    imgHeight = this->mainImage->height();
    imgWidth = this->mainImage->width();

    ui->txtHeight->setText(QString::number(imgHeight));
    ui->txtWidth->setText(QString::number(imgWidth));

   ui->displayPane->setPixmap(*mainImage);


}

