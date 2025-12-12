#ifndef PROD_H
#define PROD_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>



class Prod
{
    int id;
    QString username;
public:
    Prod();
    Prod(int,QString);
     Prod(int);
    QString getusername();
    int getid();
    bool ajouter();
    bool Modifier(int , QString);
    QSqlQueryModel * afficher();
    bool supprimer(int);
     QSqlQueryModel * sortid();

     QSqlQueryModel * sortusername();
     QSqlQueryModel * chercherid(int);

     QSqlQueryModel * chercherusername(QString);

     bool chercheridd();
     bool notifier();
     bool verifierEx(QString);
     bool verifierExid(int);


};

#endif // PROD_H
