#ifndef MACHINE_H
#define MACHINE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class machine
{public:
    machine();
    machine(int,QString,int);
    QString get_bloc();
    int get_quantite();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString bloc;
    int id,quantite;
};

#endif // MACHINE_H
