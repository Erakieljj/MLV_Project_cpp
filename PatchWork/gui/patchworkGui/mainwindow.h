#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqgraphicsview.h"


namespace Ui {
class MainWindow;
}

enum mode { circle, polygone,ellipse,line,none };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int waitingPoint = -1;
    mode m = none;
    MyQGraphicsView *myGV = new MyQGraphicsView();

private slots:
    void modeCircle();
    void modeEllipse();
    void modePolygone();
    void modeLine();

};

#endif // MAINWINDOW_H
