#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myqgraphicsview.h"
#include <QtCore/QtDebug>

using namespace std;
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

    this->myGV->setMaxtPoint(1);
    double r = 10;
    try{
        r= ui->lineEditRayonCircle->text().toDouble();
    } catch(exception *e){
        r = 10;
    }
    if(r ==0){
        r = 10;
    }
    this->myGV->setRayon(r);
    qDebug() <<"SET RAYON"<<r << ui->lineEditRayonCircle->text();
    this->myGV->updateModeCircle();
    ui->labelMode->setText("Mode Cercle ("+QString::number(r)+")");

}

void MainWindow::modeEllipse()
{
    this->myGV->setMaxtPoint(1);
    double rlon = 20;
    double rlar = 10;
    try{
        rlar  = ui->lineEditRlar->text().toDouble();
    } catch(exception *e){
        rlar = 10;
    }
    try{
        rlon  = ui->lineEditRlon->text().toDouble();
    } catch(exception *e){
        rlon = 20;
    }
    if(rlon ==0)
        rlon = 20;
    if(rlar ==0)
        rlar = 10;

    this->myGV->setRlar(rlar);
    this->myGV->setRlon(rlon);
    this->myGV->updateModeEllipse();
    ui->labelMode->setText("Mode Ellipse("+QString::number(rlon)+","+QString::number(rlar)+")");
}

void MainWindow::modeLine()
{
    this->myGV->setMaxtPoint(2);
    this->myGV->updateModeLine();
    ui->labelMode->setText("Mode Line");
}

void MainWindow::modePolygone()
{
    int r = 5;
    try{
        r= ui->lineEditPolygone->text().toInt();
    } catch(exception *e){
        r = 5;
    }
    if(r ==0){
        r = 5;
    }
    this->myGV->setMaxtPoint(r);
    myGV->setPolygonPoint(r);
    this->myGV->updateModePoly();
    ui->labelMode->setText("Mode Polygone("+QString::number(r)+" cote)");
}

