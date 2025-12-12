#ifndef ABSENT_H
#define ABSENT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Absent
{public:
    Absent();
    Absent(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString nom);
    QSqlQueryModel * trier();

    bool supprimer(int);
private:
    QString nom,prenom;
    int id;
};

#endif // ABSENT_H
