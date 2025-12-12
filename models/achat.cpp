#include "achat.h"
#include "ui_achat.h"
#include "vente.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
#include <QDateEdit>
#include "bienenudistr.h"
#include "produits.h"
#include "arduino.h"
achat::achat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::achat)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpproduits.afficher());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).

}

achat::~achat()
{
    delete ui;
}

void achat::on_pushButton_clicked()
{
    int idm=ui->lineEdit->text().toInt();
    int reference=ui->lineEdit_2->text().toInt();
    int frais=ui->lineEdit_4->text().toInt();
    QString nomp= ui->lineEdit_3->text();
    QDate date= ui->dateEdit->date();

  vente v(idm,reference,frais,nomp,date);
  bool test=v.ajouter();
  if(test)
{//ui->tableVente->setModel(tmpventes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employer"),
                  QObject::tr("employer ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employer"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void achat::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from produit where ID='"+val+"' or REFERENCE='"+val+"' or NOMP='"+val+"' or QUANTITE='"+val+"' or PRIX='"+val+"'  ");

    if(query.exec())
    {

        while(query.next())
        {
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(4).toString());

        }
    }
}

void achat::on_pushButton_3_clicked()
{
    bienenuDistr *b=new bienenuDistr();
  this->close() ;
  b->show();
}

void achat::update_label()
{
    data=A.read_from_arduino();

    if(data=="3")

        ui->label_ard->setText("produit de reference numero 2 est vendu"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
}
