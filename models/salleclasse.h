#ifndef SALLECLASSE_H
#define SALLECLASSE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPixmap>

class salleClasse
{
public:
    salleClasse();
    salleClasse(QString,QString,int, int, int);
    QString get_numero();
    QString get_batiment();
    int get_volets();
    int get_luminosite();
    int get_effectif();
    void set_numero(QString);
    void set_batiment(QString);
    void set_volets(int);
    void set_luminosite(int);
    void set_effectif(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString, int, int);
    bool eteindre(int, int);
private:
    QString numero,batiment;
    int volets,luminosite,effectif;
};

#endif // SALLECLASSE_H
