#include "ventewindow.h"
#include "ui_ventewindow.h"
#include "bienvenu.h"
#include "bienenudistr.h"

venteWindow::venteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::venteWindow)
{
    ui->setupUi(this);
     ui->tableVente->setModel(tmpventes.afficher());
}

venteWindow::~venteWindow()
{
    delete ui;
}

void venteWindow::on_pushButton_6_clicked()
{
    bienenuDistr *b=new bienenuDistr ();
  this->close() ;
  b->show();
}

void venteWindow::on_pushButton_clicked()
{
    QDate date= ui->dateEdit->date();
    int somme = tmpventes.calculer_somme(date);
    QString s = QString::number(somme);
    ui->lineEdit->setText(s);
}

void venteWindow::on_pushButton_4_clicked()
{
    int mois= ui->lineEdit_2->text().toInt();
    int somme = tmpventes.calculer_somme_mois(mois);
    QString s = QString::number(somme);
    ui->lineEdit_3->setText(s);
}

void venteWindow::on_pushButton_3_clicked()
{
     ui->tableVente->setModel(tmpventes.sortdate());
}

void venteWindow::on_pushButton_5_clicked()
{
    int mois= ui->lineEdit_4->text().toInt();
        int nbv = tmpventes.calculer_nbv_mois(mois);
        QString s = QString::number(nbv);
        ui->lineEdit_5->setText(s);
}
