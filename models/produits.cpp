#include "produits.h"
#include <QDebug>
#include <QDateEdit>
produits::produits()
{
id=0;
nomp="";
quantite=0;
reference=0;
prix=0;
}
produits::produits(int id,int reference ,QString nomp,int quantite,int prix,QDate datex)
{
  this->id=id;
  this->reference=reference;
  this->nomp=nomp;
  this->quantite=quantite;
  this->prix=prix;
  this->datex=datex;
}
QString produits::get_nom(){return  nomp;}
int produits::get_quantite(){return quantite;}
int produits::get_id(){return  id;}
int produits::get_ref(){return reference;}
int produits::get_prix(){return prix;}
QDate produits::get_datex(){return datex;}

bool produits::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO produit (ID, REFERENCE, NOMP, QUANTITE , PRIX, DATE_EXPIRE) "
                    "VALUES (:id, :reference ,:nomp, :quantite, :prix, :datex)");
query.bindValue(":id", res);
query.bindValue(":reference", reference);
query.bindValue(":nomp",nomp);
query.bindValue(":quantite", quantite);
query.bindValue(":prix", prix);
query.bindValue(":datex", datex);

return    query.exec();
}

QSqlQueryModel * produits::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom produit "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date expiration"));


    return model;
}

bool produits::supprimer(int reff)
{
QSqlQuery query;
QString res= QString::number(reff);
query.prepare("Delete from produit where REFERENCE = :reference ");
query.bindValue(":reference", res);
return    query.exec();
}

QSqlQueryModel *produits::chercherid(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from produit where ID= ? ");
    query.addBindValue(id);
    query.exec();


    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom produit "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date expiration"));



  return model;
}

bool produits::verifierExid(int id)
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

}

QSqlQueryModel *produits::sortprix()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from produit ORDER BY PRIX");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom produit "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date expiration"));
    return model;
}
bool produits::modifier( int idm , int quantite,int ref,int prix)
{
    QSqlQuery query;
    QString res=QString::number(ref);
    query.prepare(" UPDATE produit SET ID=:idm , QUANTITE=:quantite ,PRIX=:prix where REFERENCE=:reference ");
    query.bindValue(":reference",res);
    query.bindValue(":quantite",quantite);
    query.bindValue(":idm",idm);
    query.bindValue(":prix",prix);



    return query.exec();

}

bool produits::verifierExdex()
{
    int i=0;

    QSqlQuery query;
    query.prepare("SELECT * FROM vente where sysdate >dates");
    if(query.exec())
    {while(query.next())
        {i++;}}

    if(i!=0)
        return true ;
    else
        return false;

}

QSqlQueryModel *produits::sortquant()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from produit ORDER BY QUANTITE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Reference "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom produit "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date expiration"));
    return model;
}

