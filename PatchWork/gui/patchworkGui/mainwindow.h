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
    /**
     * @brief myGV graphics view
     */
    MyQGraphicsView *myGV;


private slots:
    /**
     * @brief modeCircle change mode
     */
    void modeCircle();
    /**
     * @brief modeEllipse change mode
     */
    void modeEllipse();
    /**
     * @brief modePolygone change mode
     */
    void modePolygone();
    /**
     * @brief modeLine change mode
     */
    void modeLine();

    /**
     * @brief applyHomo call homothetie
     */
    void applyHomo();
    /**
     * @brief applyRotation call rotation
     */
    void applyRotation();
    /**
     * @brief applyTranslation call Translation
     */
    void applyTranslation();

    /**
     * @brief callServer call server
     */
    void callServer();

    void openFile();

    void applyReset();

};

#endif // MAINWINDOW_H
