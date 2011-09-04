#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <iostream>
#include <imageresizer.h>

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

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;

public slots:
    void loadImage();
    void scaleImage();
    void cropImage();

};

#endif // MAINWINDOW_H
