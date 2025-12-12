#include "bienvenufoyer.h"
#include "ui_bienvenufoyer.h"
#include "gestion.h"
#include "integration.h"
#include "ui_integration.h"
#include "chambreswindow.h"
#include "gestion.h"
bienvenuFoyer::bienvenuFoyer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienvenuFoyer)
{
    ui->setupUi(this);
}

bienvenuFoyer::~bienvenuFoyer()
{
    delete ui;
}

void bienvenuFoyer::on_pushButton_clicked()
{
    gestion  *g=   new gestion();
    this->close() ;
    g->show() ;
}

void bienvenuFoyer::on_pushButton_4_clicked()
{

    integration *it = new integration() ;
   this->close() ;
   it->show() ;
}



void bienvenuFoyer::on_pushButton_3_clicked()
{
    chambresWindow *ch= new chambresWindow();
    this->close();
    ch->show();
}

void bienvenuFoyer::on_pushButton_2_clicked()
{
    gestion *g= new  gestion();
    this->close();
    g->show();
}
