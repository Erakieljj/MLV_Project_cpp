#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myqgraphicsview.h"
#include "fresque.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int waitingPoint = -1;
    MyQGraphicsView *myGV = new MyQGraphicsView();


private slots:
    void modeCircle();
    void modeEllipse();
    void modePolygone();
    void modeLine();

    void applyHomo();
    void applyRotation();
    void applyTranslation();

    void callServer();

};

#endif // MAINWINDOW_H
