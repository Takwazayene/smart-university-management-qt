#include "prod.h"
#include  <QString>



Prod::Prod()
{
 id = 0 ;
 username = "" ;
}

Prod::Prod(int a,QString b)
{
    id=a;
    username=b;



}

Prod::Prod(int a)
{
    id=a;

}

QString Prod::getusername(){return username ;}
int Prod::getid(){return id;}


bool Prod::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO ABONNEFOYER (ID, USERNAME)"
                  "VALUES (:id, :username)");
    query.bindValue(":id",res);
    query.bindValue(":username",username);



    return query.exec();
}

bool Prod::Modifier(int id , QString username)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare(" update ABONNEFOYER set id='"+QString::number(id)+"',username='"+username+"' where id="+QString::number(id));
    query.bindValue(":id",res);
   // query.bindValue(":username",username);



    return query.exec();


    /*QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("update etudiant set ID='"+QString::number(id)+"', nom='"+nom+"', prenom='"+prenom+"' where id="+QString::number(id));
    query.bindValue(":id", res);
    return    query.exec();*/

}


QSqlQueryModel *Prod:: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from ABONNEFOYER");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("USERNAME"));
    //model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));

    return model;
}
bool Prod:: supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("delete   from ABONNEFOYER where ID=:id");
    query.addBindValue(id);

    return query.exec();
}



QSqlQueryModel *Prod::sortid()
{


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from ABONNEFOYER ORDER BY ID");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("USERNAME"));
   // model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));

    return model;
}




QSqlQueryModel *Prod::sortusername()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from ABONNEFOYER ORDER BY TYPE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("USERNAME"));
    //model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));

    return model;
}


QSqlQueryModel *Prod::chercherid(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from ABONNEFOYER where ID= ? ");
    query.addBindValue(id);
    query.exec();


    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("USERNAME"));
    //model->setHeaderData(3,Qt::Horizontal,QObject::tr("CHAMBRE"));


  return model;
}


QSqlQueryModel *Prod::chercherusername(QString username)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from ABONNEFOYER where USERNAME= ? ");
    query.addBindValue(username);
    query.exec();


    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("username"));
    //model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOMBRE"));



  return model;
}


bool Prod::verifierEx(QString username)
{
    int i=0;

    QSqlQuery query;
    query.prepare("select * from ABONNEFOYER where USERNAME= ? ");
   query.addBindValue(username);
    if(query.exec())
    {while(query.next())
        {i++;}}

    if(i!=0)
        return true ;
    else
        return false;
}

bool Prod::verifierExid(int id)
{
    int i=0;

    QSqlQuery query;
    query.prepare("select * from ABONNEFOYER where ID= ? ");
   query.addBindValue(id);
    if(query.exec())
    {while(query.next())
        {i++;}}

    if(i!=0)
        return true ;
    else
        return false;

}


bool Prod::notifier()
{
    int i=0 ;
    QSqlQuery query;
    query.prepare("select * from PRODUTI where NOMBRE=5");
    if(query.exec())
    {while (query.next())
        {i++;}
    }
    if(i!=0)
    return true;
    else
        return false;

}
