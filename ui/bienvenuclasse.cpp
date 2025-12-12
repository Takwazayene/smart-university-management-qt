#include "bienvenuclasse.h"
#include "ui_bienvenuclasse.h"
//#include "etudiantclassewindow.h"
#include "etudiantclasse.h"
#include "integration.h"
#include "ui_integration.h"
#include "salleclasse.h"
#include "sallewindow.h"
#include "classe.h"
bienvenuClasse::bienvenuClasse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienvenuClasse)
{
    ui->setupUi(this);
}

bienvenuClasse::~bienvenuClasse()
{
    delete ui;
}



void bienvenuClasse::on_pushButton_3_clicked()
{

   integration *i = new integration() ;
   this->close() ;
   i->show() ;
}



void bienvenuClasse::on_pushButton_2_clicked()
{
    classe *c = new classe() ;
    this->close() ;
    c->show() ;

}
