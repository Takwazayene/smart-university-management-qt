#ifndef ETUDIANTCLASSE_H
#define ETUDIANTCLASSE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class etudiantClasse
{public:
    etudiantClasse();
    etudiantClasse(int,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_username();
    int get_id();
    int get_chambre();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(QString nom);
    QSqlQueryModel * trier();

    bool supprimer(int);
private:
    QString nom,prenom,username;
    int id, chambre;

};

#endif // ETUDIANTCLASSE_H
