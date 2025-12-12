#include "etudiantclasse.h"

#include <QDebug>
etudiantClasse::etudiantClasse()
{
id=0;
nom="";
prenom="";
}
etudiantClasse::etudiantClasse(int id,QString nom,QString prenom,QString username,int chambre)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->username=username;
  this->chambre=chambre;
}
QString etudiantClasse::get_nom(){return  nom;}
QString etudiantClasse::get_prenom(){return prenom;}
int etudiantClasse::get_id(){return  id;}
QString etudiantClasse::get_username(){return username;}
int etudiantClasse::get_chambre(){return chambre;}

bool etudiantClasse::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString reschambre= QString::number(chambre);
query.prepare("INSERT INTO etudiant2 (ID, NOM, PRENOM, USERNAME, CHAMBRE) "
                    "VALUES (:id, :nom, :prenom, :username, :chambre)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":username", username);
query.bindValue(":chambre", reschambre);

return    query.exec();
}

QSqlQueryModel * etudiantClasse::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant order by nom asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Username"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Chambre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

QSqlQueryModel * etudiantClasse::rechercher(QString name)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from etudiant where nom like '%"+name+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Username"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Chambre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

QSqlQueryModel * etudiantClasse::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from etudiant order by prenom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Username"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Chambre"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
        return model;
}

bool etudiantClasse::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from etudiant where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

