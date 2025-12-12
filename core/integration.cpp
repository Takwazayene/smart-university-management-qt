#include "integration.h"
#include "ui_integration.h"
#include "mainwindow.h"
#include "bienvenu.h"
#include "bienvenufoyer.h"
#include "bienvenuclasse.h"
#include "bienenudistr.h"

integration::integration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integration)
{
    ui->setupUi(this);
}

integration::~integration()
{
    delete ui;
}

void integration::on_pushButton_clicked()
{

    MainWindow  *w= new MainWindow();
    this->close() ;
    w->show() ;
}

void integration::on_pushButton_2_clicked()
{
    bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;
}

void integration::on_pushButton_foyer_clicked()
{
    bienvenuFoyer  *bf= new bienvenuFoyer();
    this->close() ;
    bf->show() ;

}

void integration::on_pushButton_3_clicked()
{
    bienvenuClasse *bc = new bienvenuClasse() ;
    this->close() ;
    bc->show() ;
}

void integration::on_pushButton_4_clicked()
{
 bienenuDistr *bd = new bienenuDistr () ;
 this-> close() ;
 bd->show() ;

}
