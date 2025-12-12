#include "etudiantwindow.h"
#include "ui_etudiantwindow.h"
#include <QDebug>
#include "QSqlQuery"
#include <QString>
#include <QSqlQueryModel>
#include "abonneresto.h"
#include "menu.h"
#include "gestionabowindow.h"
#include "note_menu.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "bienvenu.h"
#include "ui_menuwindow.h"
#include "menuwindow.h"

etudiantWindow::etudiantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::etudiantWindow)

{
    ui->setupUi(this);


}

etudiantWindow::~etudiantWindow()
{
    delete ui;
}

void etudiantWindow::on_pushButton_clicked()
{
    int id ;
     QSqlQueryModel *model ;
      //abonneResto *et ;
     id = ui->lineEdit->text().toInt() ;
      model = et->chercher_etudiant (id);
      ui->tableEtudiant->show() ;
      ui->tableEtudiant->setModel(model);

}

void etudiantWindow::on_pushButton_affichermenu_clicked()
{
    QString daate;
     // Menu *tmpmenuu ;
     QSqlQueryModel *model ;
     daate = ui->lineEdit_inserezmenu->text() ;
      model =tmpmenuu->chercher_menu2 (daate);
      ui->tableView_menu2->show() ;
      ui->tableView_menu2->setModel(model);
}

void etudiantWindow::on_pushButton_notezmenu_clicked()
{
    QSqlQuery qry;
     QString daate;
     bool test;
     int note ,verif=0 , note2 ;
     int tott ;
      note_menu tmpmenu ;
    // gestionAboWindow *m ;
     daate = ui->lineEdit_inserezmenu->text() ;
     note2 = ui->spinBox_note->text().toInt() ;
     qry.prepare("select * from NOTE_MENU where daate='"+daate+"' " );
     if(qry.exec())
      {

         while (qry.next())
           {
              verif++ ;
              tott = qry.value(1).toInt();
              note = tott + note2 ;
           }
     }
    if(verif==0)
    {
     note_menu nm(daate,note2) ;
      test=nm.ajouter_note_menu();

    }
    else
    {
        // note_menu tmp_note_menu ;
          test=tmp_note_menu.incrementer_note(daate,note);

    }
      if(test)
    {
          //ui->table_note->setModel(tmpmenu.afficher_note_menu());//refresh
    QMessageBox::information(nullptr, QObject::tr("Noter menu"),
                      QObject::tr(" note  effectué , merci .\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Noter menu"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void etudiantWindow::on_pushButton_2_clicked()
{
      bienvenu *b=new bienvenu();
    this->close() ;
    b->show();
}

void etudiantWindow::on_imprimer_clicked()
{

}

void etudiantWindow::on_pushButton_3_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void etudiantWindow::on_pushButton_4_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}
