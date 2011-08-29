#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pBtn01,SIGNAL(clicked()),this,SLOT(conectar()));
    connect(ui->BotaoFecha,SIGNAL(triggered()),this,SLOT(close()));
   connect(ui->actionRand,SIGNAL(triggered()),this,SLOT(genRand()));
   connect(ui->pBtn01,SIGNAL(clicked()),this,SLOT(exibeImagem()));
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
void MainWindow::conectar(){
    ui->label->setText("foi");
}

void MainWindow::genRand(){
    srand(time(NULL));
    qDebug() << "Sorteio: " << rand();
}

void MainWindow::exibeImagem(){
   qDebug()<<" carrega imagem ";
   QString local = "teste.png";
   QPixmap *imagem = new QPixmap(local);
   ui->imagem->setPixmap(*imagem);
}

