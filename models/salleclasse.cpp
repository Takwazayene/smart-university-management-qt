#include "salleclasse.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

salleClasse::salleClasse()
    {
    numero="";
    batiment="";
    volets=0;
    luminosite=0;
    effectif=0;
    }
    salleClasse::salleClasse(QString numero,QString batiment,int volets,int luminosite, int effectif)
    {
      this->numero=numero;
      this->batiment=batiment;
      this->volets=volets;
      this->luminosite=luminosite;
      this->effectif=effectif;
    }
    QString salleClasse::get_numero(){return  numero;}
    QString salleClasse::get_batiment(){return batiment;}
    int salleClasse::get_volets(){return  volets;}
    int salleClasse::get_luminosite(){return luminosite;}
    int salleClasse::get_effectif(){return effectif;}
    void salleClasse::set_numero(QString num){this->numero=num;}
    void salleClasse::set_batiment(QString bat){this->batiment=bat;}
    void salleClasse::set_volets(int vol){this->volets=vol;}
    void salleClasse::set_luminosite(int lum){this->luminosite=lum;}
    void salleClasse::set_effectif(int eff){this->effectif=eff;}
    bool salleClasse::ajouter()
    {
    QSqlQuery query;
    QString res= QString(numero);
    query.prepare("INSERT INTO Salle (numero, batiment, volets, luminosite, effectif) "
                        "VALUES (:numero, :batiment, :volets, :luminosite, :effectif)");
    query.bindValue(":numero", res);
    query.bindValue(":batiment", batiment);
    query.bindValue(":volets", volets);
    query.bindValue(":luminosite", luminosite);
    query.bindValue(":effectif", effectif);

    return    query.exec();
    }

    QSqlQueryModel * salleClasse::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Salle order by NUMERO Asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("batiment "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("volets"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("luminosite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("effectif"));
        return model;
    }

    bool salleClasse::supprimer(QString numero)
    {
    QSqlQuery query;
    QString res= QString(numero);
    query.prepare("Delete from Salle where numero = :numero ");
    query.bindValue(":numero", res);
    return    query.exec();
    }

    bool salleClasse::modifier(QString numero, int voletts, int luminos)
    {
        QSqlQuery query;
        query.prepare("UPDATE SALLE SET VOLETS=:voletm,  LUMINOSITE=:lumino WHERE NUMERO=:numero ");
        query.bindValue(":voletm", voletts);
        query.bindValue(":lumino", luminos);
        query.bindValue(":numero", numero);
        return    query.exec();
    }

    bool salleClasse::eteindre(int voletts, int luminos)
    {
        QSqlQuery query;
        query.prepare("UPDATE SALLE SET VOLETS=:voletm,  LUMINOSITE=:lumino");
        query.bindValue(":voletm", voletts);
        query.bindValue(":lumino", luminos);
        return    query.exec();

    }
