#include "machinewindow.h"
#include "ui_machinewindow.h"
#include "machine.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include  "bienenudistr.h"
machineWindow::machineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::machineWindow)
{
    ui->setupUi(this);
    ui->tabetudiant->setModel(tmpmachine.afficher());
}

machineWindow::~machineWindow()
{
    delete ui;
}

void machineWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void machineWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void machineWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString bloc= ui->lineEdit_nom->text();
    int quantite= ui->lineEdit_prenom->text().toInt();
  machine m(id,bloc,quantite);
  bool test=m.ajouter();
  if(test)
{ui->tabetudiant->setModel(tmpmachine.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Distributeur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void machineWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test=tmpmachine.supprimer(id);
    if(test)
    {ui->tabetudiant->setModel(tmpmachine.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void machineWindow::on_pushButton_3_clicked()
{
    bienenuDistr *b=new bienenuDistr ();
  this->close() ;
  b->show();
}
