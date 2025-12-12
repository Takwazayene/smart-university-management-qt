#ifndef MENU_H
#define MENU_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Menu
{public:
    Menu();
    Menu (int,QString,QString,QString,QString);
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
   bool supprimer(int);
    bool modifier_menu(int,QString,QString,QString,QString);

   QSqlQueryModel * chercher_menu(int);
   QSqlQueryModel * chercher_menu2(QString) ;
   QSqlQueryModel * chercher_plat(QString) ;
   QSqlQueryModel * sortid();
   QSqlQueryModel *recherche_avance(const QString &str);
   QSqlQueryModel *recherche_avance_repas(const QString &str);
   bool imprimer_menu() ;
   QSqlQueryModel * afficher_par_type() ;
 // QSqlQueryModel * afficher_caracteristique() ;
private:
    int id;
    QString jours;
    QString repas;
    QString dessert ;
    QString daate ;


    int note ;

};
#endif // MENU_H
