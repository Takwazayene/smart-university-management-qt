#include "note_menu.h"
#include "menu.h"
#include "connexion.h"
#include "QSqlQueryModel"
#include "QSqlQuery"


note_menu::note_menu()
{
    daate = "" ;
    note = 0 ;

}

note_menu::note_menu(QString daate , int note)
{
    this->daate=daate ;
    this->note=note ;
}

bool note_menu::ajouter_note_menu()
{
QSqlQuery query;
QString res= QString::number(note);
query.prepare("INSERT INTO note_menu (DAATE, NOTE ) "
                    "VALUES (:daate, :note)");
//query.bindValue(":id", res);
query.bindValue(":daate", daate);
query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel *note_menu::afficher_note_menu()
{QSqlQueryModel * model= new QSqlQueryModel();
 QString str="SELECT *FROM  note_menu";
model->setQuery(str);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("date"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("note"));


    return model;
}

  int note_menu ::calculer_note(QString daate)

  {
      QSqlQuery qry;
      qry.prepare("select * from note_menu where daate='"+daate+"'" );
     int notetot=0 ;
      int note2 ;
      int i =0 ;
      if(qry.exec())
       {

          while (qry.next())
            {
              note2  = qry.value(1).toInt();
               notetot = notetot+ note2 ;
               i++ ;
            }

  }
      notetot = notetot/i ;
      return notetot ;
}



bool note_menu:: incrementer_note(QString daate,int note)
  {

    QSqlQuery query;
    //QString res= QString::number(id);
     query.prepare("update NOTE_MENU set note='"+QString::number(note)+"' where daate='"+daate+"'");
    query.bindValue(":daate", daate);
     query.bindValue(":note", note);
    //query.bindValue(":id", res);
    return    query.exec();
   /* QSqlQuery query;
    QString res= daate;
    query.prepare("update note_menu set note='"+QString::number(note)+"'where daate="+daate);
    query.bindValue(":daate", res);
    return    query.exec();*/




  }

QSqlQueryModel * note_menu::afficher_caracteristique()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT COUNT(note) ,Trunc(SUM(note),2),Trunc(AVG(note),2) , MIN(note), MAX(note) From note_menu ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nb lignes"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Somme"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Moyenne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Min"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Max "));
        return model;



}

