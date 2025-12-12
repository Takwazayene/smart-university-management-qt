#include "machine.h"
#include <QDebug>
machine::machine()
{
id=0;
bloc="";
quantite=0;
}
machine::machine(int id,QString bloc,int quantite)
{
  this->id=id;
  this->bloc=bloc;
  this->quantite=quantite;
}
QString machine::get_bloc(){return  bloc;}
int machine::get_quantite(){return quantite;}
int machine::get_id(){return  id;}

bool machine::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO machine (ID, BLOC, QUANTITE) "
                    "VALUES (:id, :bloc, :quantite)");
query.bindValue(":id", res);
query.bindValue(":bloc", bloc);
query.bindValue(":quantite", quantite);

return    query.exec();
}

QSqlQueryModel * machine::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from machine");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Bloc "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    return model;
}

bool machine::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from machine where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
