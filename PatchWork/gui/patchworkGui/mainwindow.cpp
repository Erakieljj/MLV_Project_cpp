#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myqgraphicsview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->buttonLine,SIGNAL(clicked()),this,SLOT(modeLine()));
    connect(ui->buttonCircle,SIGNAL(clicked()),this,SLOT(modeCircle()));
    connect(ui->buttonEllipse,SIGNAL(clicked()),this,SLOT(modeEllipse()));
    connect(ui->buttonPolygone,SIGNAL(clicked()),this,SLOT(modePolygone()));
    ui->horizontalLayout->addWidget( this->myGV );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modeCircle()
{
    this->m = circle;
    this->myGV->setMaxtPoint(1);

}

void MainWindow::modeEllipse()
{
    this->m = ellipse;
    this->myGV->setMaxtPoint(1);
}

void MainWindow::modeLine()
{
    this->m = line;
    this->myGV->setMaxtPoint(2);
}

void MainWindow::modePolygone()
{
    this->m = polygone;
    this->myGV->setMaxtPoint(ui->lineEditPolygone->text().toInt());
}
