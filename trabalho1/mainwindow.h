#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <iostream>
#include <imageresizer.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    QPixmap *mainImage;
    QString fileName;
    ImageResizer imgResizer;

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

public slots:
    void loadImage();
    void scaleImage();
    void startScaleMode();

};

#endif // MAINWINDOW_H
