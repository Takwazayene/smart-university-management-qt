#include "absent.h"

Absent::Absent()
{
id=0;
nom="";
prenom="";
}
Absent::Absent(int id,QString nom,QString prenom)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
}
QString Absent::get_nom(){return  nom;}
QString Absent::get_prenom(){return prenom;}
int Absent::get_id(){return  id;}

void Absent::set_id(int iden){this->id=iden;}
void Absent::set_nom(QString no){this->nom=no;}
void Absent::set_prenom(QString pren){this->prenom=pren;}

bool Absent::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Absent (ID, NOM, PRENOM) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * Absent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Absent order by nom asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

QSqlQueryModel * Absent::rechercher(QString name)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Absent where nom like '%"+name+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

QSqlQueryModel * Absent::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Absent order by prenom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
        return model;
}

bool Absent::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Absent where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

