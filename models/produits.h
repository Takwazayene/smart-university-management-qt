#ifndef PRODUITS_H
#define PRODUITS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateEdit>
class produits
{public:
    produits();
    produits(int,int,QString,int,int,QDate);
    QString get_nom();
    int get_quantite();
    int get_id();
    int get_ref();
    bool ajouter();
    int get_prix();
    QDate get_datex();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * chercherid(int);
    bool verifierExid(int);
    QSqlQueryModel * sortid();
    QSqlQueryModel * sortprix();
    bool modifier(int,int,int,int);
    bool verifierExdex();
    QSqlQueryModel * sortquant();

private:
    QString nomp;
    int id,quantite,reference,prix;
    QDate datex;
};

#endif // PRODUITS_H
