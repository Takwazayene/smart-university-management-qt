#ifndef NOTE_MENU_H
#define NOTE_MENU_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "menu.h"
#include "menuwindow.h"

class note_menu
{
public:
    note_menu();
    note_menu(QString , int);
   bool ajouter_note_menu ();
   QSqlQueryModel * afficher_note_menu () ;
  int calculer_note(QString) ;
   bool incrementer_note(QString,int) ;
   QSqlQueryModel * afficher_caracteristique() ;

private :
    int id ,note;
    QString daate ;
};

#endif // NOTE_MENU_H
