#include "bienenudistr.h"
#include "ui_bienenudistr.h"
#include "machinewindow.h"
#include "produit.h"
#include "ventewindow.h"
#include "achat.h"
#include "produits.h"
bienenuDistr::bienenuDistr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bienenuDistr)
{
    ui->setupUi(this);
    bool test=tmpproduits.verifierExdex();
       // QPixmap pixx("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/integration/projet_alpha/projet_alphaimg/notification.png");
       // ui->label_2->setPixmap(pixx) ;
        if(test)
        {
            QPixmap pixx("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/integration/projet_alpha/projet_alpha/img/notification.png");
            ui->label_2->setPixmap(pixx) ;

        }
}

bienenuDistr::~bienenuDistr()
{
    delete ui;
}

void bienenuDistr::on_pushButton_clicked()
{
   machineWindow *m=new machineWindow ();
  this->close() ;
  m->show();
}

void bienenuDistr::on_pushButton_2_clicked()
{
    produit *p=new produit ();
  this->close() ;
  p->show();
}

void bienenuDistr::on_pushButton_3_clicked()
{
    venteWindow *v=new venteWindow ();
  this->close() ;
  v->show();

}

void bienenuDistr::on_pushButton_5_clicked()
{
    achat *a=new achat();
  this->close() ;
  a->show();
}
