#include "produit.h"
#include "ui_produit.h"
#include "bienenudistr.h"
#include "produits.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

produit::produit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::produit)
{
    ui->setupUi(this);
    ui->tabproduits->setModel(tmpproduits.afficher());
}

produit::~produit()
{
    delete ui;
}

void produit::on_pushButton_ajouter_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void produit::on_pushButton_afficher_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void produit::on_pushButton_retour_clicked()
{
    bienenuDistr *b=new bienenuDistr ();
  this->close() ;
  b->show();
}

void produit::on_pushButton_2_clicked()
{
    int id = ui->lineEdit->text().toInt();
    int reference= ui->lineEdit_2->text().toInt();
    QString nomp= ui->lineEdit_3->text();
    int quantite= ui->lineEdit_4->text().toInt();
    int prix=ui->lineEdit_10->text().toInt();
    QDate datex=ui->dateEdit->date();
  produits p(id,reference,nomp,quantite,prix,datex);
  bool test=p.ajouter();
  if(test)
{ui->tabproduits->setModel(tmpproduits.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void produit::on_pushButton_6_clicked()
{
    ui->tabproduits->setModel(tmpproduits.sortprix());
}

void produit::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_9->text().toInt();
    if(tmpproduits.verifierExid(id)==false)
    {QMessageBox::warning(this,"ERREUR","ID n'existe pas");}
    else
   ui->tabproduits->setModel(tmpproduits.chercherid(id));
}

void produit::on_pushButton_4_clicked()
{
    int ref = ui->lineEdit_5->text().toInt();
    bool test=tmpproduits.supprimer(ref);
    if(test)
    {ui->tabproduits->setModel(tmpproduits.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void produit::on_pushButton_3_clicked()
{
    QString nomp;
    int idm;
    int quantite,ref,prix;
    idm=ui->lineEdit_7->text().toInt();
    quantite=ui->lineEdit_8->text().toInt();
    ref=ui->lineEdit_6->text().toInt();
    prix=ui->lineEdit_11->text().toInt();
    if (ui->lineEdit_7->text().isEmpty())
    {

        QMessageBox::information(this," EREURE ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

    }
  else   if (ui->lineEdit_8->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR ","VEUILLEZ VERIFIER CHAMP quantite  !!!!") ;

    }
else    if (ui->lineEdit_6->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP reference!!!!") ;
    }
    else    if (ui->lineEdit_11->text().isEmpty())
        {

            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        }
else{
    //int id = ui->lineEdit->text().toInt();
     bool test=tmpproduits.modifier(idm,quantite,ref,prix);
     if(test)
     {ui->tabproduits->setModel(tmpproduits.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                     QObject::tr("produit modifié.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void produit::on_pushButton_7_clicked()
{
    ui->tabproduits->setModel(tmpproduits.sortquant());
}
