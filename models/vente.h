#ifndef VENTE_H
#define VENTE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateEdit>
class vente
{public:
    vente();
    vente(int,int,int,QString,QDate);
    QString get_date();
    QString get_nomp();
    int get_reference();
    int get_frais();
    int get_idm();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel *chercherdate(QDate);
    int calculer_somme(QDate);
    QSqlQueryModel *sortdate();
    int  calculer_somme_mois(int);
    int  calculer_nbv_mois(int);

private:
    QString nomp;
    int idm,frais,reference;
    QDate date;
};
#endif // VENTE_H
