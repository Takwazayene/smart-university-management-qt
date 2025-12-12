#include "gestion.h"
#include "ui_gestion.h"
#include "prod.h"
#include "bienvenufoyer.h"
#include "ui_bienvenufoyer.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

gestion::gestion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
}

gestion::~gestion()
{
    delete ui;
}

void gestion::on_pb_ajouter_clicked()
{
    int id = ui->id->text().toInt();
    QString username= ui->username->text();
    //int nombreLampes= ui->nombreLampes->text().toInt();//
  Prod p(id,username);
  bool test=p.ajouter();
  if(test)
{
      ui->tabproduit->setModel(tmpP.afficher());


QMessageBox::information(nullptr, QObject::tr("Ajouter un Produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void gestion::on_modifier_clicked()
{
    int id = ui->idm->text().toInt();
    QString username= ui->typem->text();

   // Prod p(id,username);
  bool test=tmpP.Modifier(id , username);
  if(test)
{
      ui->tabproduit->setModel(tmpP.afficher());
QMessageBox::information(nullptr, QObject::tr("Modifier un Produit"),
                  QObject::tr("Produit Modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un Produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_chercheid_clicked()
{

    int id = ui->cid->text().toInt();
    if(tmpP.verifierExid(id)==false)
    {QMessageBox::warning(this,"ERREUR","ID n'existe pas");}
    else
   ui->tabproduit2->setModel(tmpP.chercherid(id));

}

void gestion::on_pb_supprimer_clicked()
{
    int id = ui->ids->text().toInt();
    bool test=tmpP.supprimer(id);
    if(test)
    {
        ui->tabproduit->setModel(tmpP.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_pushButton_clicked()
{
    Prod p;
    bool a= tmpP.notifier();
    if(a==true){QMessageBox::warning(this,"System","Low quantity");}
}

/*void gestion::on_pushButton_2_clicked()
{
    bienvenuFoyer *bf = new bienvenuFoyer () ;
    bf->show() ;
    this->close() ;

}*/

void gestion::on_pushButton_retour_clicked()
{

    bienvenuFoyer *bf = new bienvenuFoyer () ;
    bf->show() ;
    this->close() ;
}
