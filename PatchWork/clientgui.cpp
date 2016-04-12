#include "clientgui.h"
#include "ui_clientgui.h"

ClientGui::ClientGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientGui)
{
    ui->setupUi(this);
}

ClientGui::~ClientGui()
{
    delete ui;
}
