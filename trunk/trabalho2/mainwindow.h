#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <iostream>
#include <imageresizer.h>
#include <imagecropper.h>
#include <imagefilter.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    QPoint startCrop;
    QPoint endCrop;
    QPixmap *mainImage;
    QString fileName;
    ImageResizer imgResizer;
    ImageCropper imgCropper;
    ImageFilter imgFilter;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    void hideEverything();

public slots:
    void loadImage();
    void scaleImage();
    void cropImage();
    void showScale();
    void showCrop();
    void toGScale();

};

#endif // MAINWINDOW_H
