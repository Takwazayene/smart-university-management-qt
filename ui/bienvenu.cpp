#include "bienvenu.h"
#include "ui_bienvenu.h"
#include "gestionabowindow.h"
#include "menu.h"
#include "ui_menuwindow.h"
#include "menuwindow.h"
#include "etudiantwindow.h"
#include "integration.h"
#include "statistique.h"
#include "ui_statistique.h"
#include "mailing.h"
#include "ui_mailing.h"
#include "arduinowindow.h"


bienvenu::bienvenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienvenu)
{
    ui->setupUi(this);
}

bienvenu::~bienvenu()
{
    delete ui;
}

void bienvenu::on_pushButton_5_clicked()
{
    gestionAboWindow *w =new gestionAboWindow();
    this->close() ;
    w->show();
}

void bienvenu::on_pushButton_6_clicked()
{
    menuWindow *m=new menuWindow();
    this->close() ;
    m->show();
}

void bienvenu::on_pushButton_7_clicked()
{
    etudiantWindow *e=new  etudiantWindow();
    this->close() ;
    e->show();
}

void bienvenu::on_pushButton_clicked()
{

    integration *i = new integration() ;
   this->close() ;
   i->show() ;
}

void bienvenu::on_pushButton_2_clicked()
{
   statistique *s = new  statistique() ;
   this->close() ;
   s->show() ;
}

void bienvenu::on_pushButton_mailing_clicked()
{
    mailing *m = new mailing() ;
    this->close() ;
    m->show() ;
}

void bienvenu::on_pushButton_3_clicked()
{
    arduinoWindow *ar = new arduinoWindow() ;
    this->close() ;
    ar->show() ;
}
