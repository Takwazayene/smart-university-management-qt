#include "classe.h"
#include "ui_classe.h"
#include "bienvenuclasse.h"
#include "etudiantclasse.h"
#include "appel.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
classe::classe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::classe)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->tabetudiant_2->setModel(tmpetudiant.afficher());
    ui->lineEdit_id_3->setInputMask("99999999");
    setFixedSize(1000,605);
}

classe::~classe()
{
    delete ui;
}

void classe::on_pushButton_salle_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void classe::on_pb_ajouter_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void classe::on_retour_clicked()
{
    bienvenuClasse *b = new bienvenuClasse () ;
    this->close() ;
    b->show();

}

void classe::on_pb_ajouter_2_clicked()
{

}

void classe::on_pb_ajouter_3_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
    QString username="username";
    int chambre=00;
    ui->lineEdit_id_3->clear();
    ui->lineEdit_nom_2->clear();
    ui->lineEdit_prenom_2->clear();
  etudiantClasse e(id,nom,prenom,username,chambre);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant_2->setModel(tmpetudiant.afficher());
      ui->textBrowser_historique->setText("Etudiant Ajouté.");
}
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
}


void classe::on_pb_supprimer_2_clicked()
{
    int compter=ui->tabetudiant_2->height();
    int id = ui->lineEdit_id_3->text().toInt();
    ui->lineEdit_id_3->clear();
    bool test=tmpetudiant.supprimer(id);
    if(test)
    {ui->tabetudiant_2->setModel(tmpetudiant.afficher());
        int count=ui->tabetudiant_2->size().height();
        if(compter==count)
        {
            ui->textBrowser_historique->setText("Suppression Réussie \n");
        }

    }
    else
    {QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void classe::on_pushButton_faire_appel_clicked()
{
    appel *a=new appel();
    a->set_nbetudiants(salletemp.get_effectif());
    a->show();
}

void classe::on_pb_ajouter_7_clicked()
{
     ui->tabetudiant_2->setModel(tmpetudiant.trier());
}

void classe::on_pushButton_2_clicked()
{
    ui->horizontalSlider->setSliderPosition(75);
}

void classe::on_pushButton_3_clicked()
{
      ui->horizontalSlider->setSliderPosition(0);
}

void classe::on_pushButton_5_clicked()
{

}


void classe::on_lineEdit_textEdited(const QString &arg1)
{
    ui->tabetudiant_2->setModel(tmpetudiant.rechercher(ui->lineEdit->text()));
}
