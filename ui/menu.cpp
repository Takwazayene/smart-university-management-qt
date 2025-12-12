#include "menu.h"
#include "connexion.h"
#include<QTextDocument>
#include<QPrintDialog>
 #include<QFile>
 #include<QPrinter>
 #include<QTextCodec>
#include <QDebug>

Menu::Menu()
{
id=0;
jours="";
repas="";
dessert="";
daate = "" ;
//note=0;
}
Menu::Menu(int id,QString jours,QString repas ,QString dessert,QString daate)
{
  this->id=id;
  this->jours=jours;
  this->repas=repas;
  this->dessert=dessert;
   this->daate=daate ;
 // this->note= note ;
}


bool Menu::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO menu (ID, JOURS, REPAS,DESSERT, DAATE) "
                    "VALUES (:id, :jours, :repas, :dessert, :daate)");
query.bindValue(":id", res);
query.bindValue(":jours", jours);
query.bindValue(":repas", repas);
query.bindValue(":dessert", dessert);
query.bindValue(":daate", daate);
//query.bindValue(":note", note);

return    query.exec();
}

QSqlQueryModel * Menu::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from menu");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Jours "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("repas"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Dessert "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date "));
//model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
    return model;
}

bool Menu::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from menu where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

QSqlQueryModel *Menu::chercher_menu(int id)
{
QSqlQueryModel *model= new QSqlQueryModel();
QString str ;
//Connexion Conn;
//Conn.ouvrirConnexion();
//Conn.openBD();
if(id== NULL){
    str="SELECT * FROM  menu";
}

     str="select * from menu where ID ="+QString::number(id);
    model->setQuery(str);
//Conn.fermerConnexion() ;
    return model;
}

QSqlQueryModel *Menu ::chercher_menu2 (QString daate)
{
    QSqlQueryModel *model= new QSqlQueryModel();
     QString str="select * from menu where daate ='"+daate+"'";
     model->setQuery(str);
     return model;
}

QSqlQueryModel *Menu::sortid()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from menu ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("jours"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("repas"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("dessert"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

    return model;
}

QSqlQueryModel *Menu ::chercher_plat(QString repas)
{
    QSqlQueryModel *model= new QSqlQueryModel();
     QString str="select * from menu where repas ='"+repas+"'";
     model->setQuery(str);
     return model;

}

QSqlQueryModel * Menu::recherche_avance(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from menu where(ID LIKE '"+str+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("jours "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("repas"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("dessert"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

    return model;
}

QSqlQueryModel * Menu::recherche_avance_repas(const QString &str)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from menu where(repas LIKE '"+str+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("jours "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("repas"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("dessert"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("date"));

    return model;
}


bool Menu:: modifier_menu(int id , QString jours , QString repas , QString dessert , QString daate)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update menu set id='"+QString::number(id)+"', jours='"+jours+"', repas='"+repas+"', dessert='"+dessert+"', daate='"+daate+"' where id="+QString::number(id));
    query.bindValue(":id", res);
    return    query.exec();


}


bool Menu::imprimer_menu()
{//QString format = "dd.MM.yyyy";
   // QString ch=date_reclamation.toString(format);




    QFile file("menu.txt");
             if (!file.open(QIODevice::ReadWrite))
                 return 0;

           QTextStream flux(&file);

           // On choisit le codec correspondant au jeu de caract�re que l'on souhaite ; ici, UTF-8

           flux.setCodec(QTextCodec::codecForName("ISO-8859-1"));


           // �criture des diff�rentes lignes dans le fichier
           flux << "                 Identifiant menu:    " << id << endl;
           flux << "       Jours:    " <<jours<< endl;
           flux <<"        Repas :  " << repas<<endl;
           flux <<"      Dessert : " << dessert<<endl;
           flux <<"      Date  : " << daate << endl;




           flux <<"        SOTUPA.com" << endl;

             QPrinter printer;
           flux.seek(0);

           // Lecture du fichier et stockage dans un QString :
           QString text = file.readAll();

           // Initialisation de document avec le texte simple :
           QTextDocument document(text);

           // Cr�ation du QPrintDialog pour le printer :
           QPrintDialog *dialog = new QPrintDialog(&printer);

           // Si l'utilisateur a fait "Accepter" :
           if (dialog->exec() == QDialog::Accepted)
           {
               // On imprime :
               document.print(&printer);
           }
}

QSqlQueryModel * Menu::afficher_par_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select Row_number()  over ( partition by jours order by  jours asc )  , id , jours, repas, dessert , daate from menu ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Row"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Jours "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("repas"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Dessert "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date "));
    //model->setHeaderData(4, Qt::Horizontal, QObject::tr("Note"));
        return model;
}


/*QSqlQueryModel * Menu::afficher_caracteristique()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT COUNT(note) ,Trunc(SUM(note),2),Trunc(AVG(note),2) , MIN(note), MAX(note) From note_menu ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nb lignes"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Somme"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Moyenne"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Min"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Max "));
        return model;



}*/
