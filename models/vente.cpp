#include "vente.h"

#include <QDebug>
#include <QDateEdit>
#include <QMessageBox>
vente::vente()
{
idm=0;
reference=0;
nomp="";

frais=0;
}
vente::vente(int idm,int reference,int frais ,QString nomp,QDate date)
{
  this->idm=idm;
  this->reference=reference;
  this->nomp=nomp;
  this->date=date;
  this->frais=frais;
}
QString vente::get_nomp(){return  nomp;}
int vente::get_frais(){return frais;}
int vente::get_idm(){return  idm;}
int vente::get_reference(){return reference;}
//QString vente::get_date(){return date;}

bool vente::ajouter()
{
QSqlQuery query;
QString res= QString::number(idm);
query.prepare("INSERT INTO vente (ID, REFERENCE, NOMP , DATES , FRAIS) "
                    "VALUES (:idm, :reference ,:nomp, :date , :frais)");
query.bindValue(":idm", res);
query.bindValue(":reference", reference);
query.bindValue(":nomp",nomp);
query.bindValue(":date", date);
query.bindValue(":frais", frais);

return    query.exec();
}

QSqlQueryModel * vente::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from vente");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Frais"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Reference"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom produit"));

    return model;
}



QSqlQueryModel *vente::chercherdate(QDate date)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from produit where DATES= ? ");
    query.addBindValue(date);
    query.exec();


    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Frais"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom produit"));



  return model;
}

/*bool produits::verifierExid(int id)
{
    int i=0;

    QSqlQuery query;
    query.prepare("select * from produit where ID= ? ");
   query.addBindValue(id);
    if(query.exec())
    {while(query.next())
        {i++;}}

    if(i!=0)
        return true ;
    else
        return false;

}*/

QSqlQueryModel *vente::sortdate()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from vente ORDER BY DATES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Frais"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Reference"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom produit"));

    return model;
}

int  vente::calculer_somme(QDate date)

{
    QSqlQuery qry;
    qry.prepare("select * from vente where DATES= ?" );
    qry.addBindValue(date);
   int somme=0 ;
    int somme2 ;
    int i =0 ;
    if(qry.exec())
     {

        while (qry.next())
          {
            somme2  = qry.value(2).toInt();
             somme = somme + somme2 ;
             i++ ;
          }

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DATE"),
                    QObject::tr("Date non disponnible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    return somme ;
}
int  vente::calculer_somme_mois(int mois)

{
    QSqlQuery qry;
    qry.prepare("select * FROM vente where extract (month from sysdate)= ?" );
    qry.addBindValue(mois);
   int somme=0 ;
    int somme2 ;
    int i =0 ;
    if(qry.exec())
     {

        while (qry.next())
          {
            somme2  = qry.value(2).toInt();
             somme = somme + somme2 ;
             i++ ;
          }

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DATE"),
                    QObject::tr("Date non disponnible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    return somme ;
}


int  vente::calculer_nbv_mois(int mois)

{
    QSqlQuery qry;
    qry.prepare("select * FROM vente where extract (month from sysdate)= ?" );
    qry.addBindValue(mois);
    int i =0 ;
    if(qry.exec())
     {

        while (qry.next())
          {
             i++ ;
          }

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR DATE"),
                    QObject::tr("Date non disponnible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }

    return i ;
}
