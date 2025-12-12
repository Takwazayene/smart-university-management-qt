#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "menu.h"
#include <QMessageBox>
#include "bienvenu.h"
#include "note_menu.h"
menuWindow::menuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menuWindow)
{

    ui->setupUi(this);
     note_menu tmpmenu ;
    ui->tabMenu->setModel(tmpMenu.afficher()) ;
    ui->table_note->setModel(tmpmenu.afficher_caracteristique());


    QPixmap pi("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/f1.jpg");
    ui->label_menu->setPixmap(pi) ;
    QPixmap pi2("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/f3.jpg");
    ui->label_menu2_2->setPixmap(pi2) ;

   // QPixmap pix4("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/ff1.png");
   // ui->label_fleche->setPixmap(pix4) ;

   // QPixmap pix5("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/tof17.jpg");
   // ui->label_tof->setPixmap(pix5) ;

    QPixmap pix6("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/tof22.jpg");
    ui->label_toff->setPixmap(pix6) ;
}

menuWindow::~menuWindow()
{
    delete ui;
}

void menuWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    ui->lineEdit_id->setValidator( new QIntValidator(0, 99999999, this) );
    QString jours= ui->lineEdit_jours->text();
    QString repas= ui->lineEdit_repas->text();
    QString dessert = ui->lineEdit_dessert->text();
    QString daate = ui->dateEdit_date2->text();
   // int note = ui->lineEdit_note->text().toInt();
  Menu M (id,jours,repas,dessert,daate);
  bool test=M.ajouter();
  if(test)
{ui->tabMenu->setModel(tmpMenu.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Menu ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un menu"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void menuWindow::on_pushButton_chercherMenu_clicked()
{
    int id ;
     QSqlQueryModel *model ;
     id = ui->lineEdit_chercherMenu->text().toInt() ;
      model =tmpMenuu->chercher_menu (id);
      ui->tabMenu->show() ;
      ui->tabMenu->setModel(model);
}

void menuWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
     bool test=tmpMenu.supprimer(id);
     if(test)
     {ui->tabMenu->setModel(tmpMenu.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Supprimer un menu"),
                     QObject::tr("Menu supprimé.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Supprimer un menu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);



}


void menuWindow::on_pushButton_trierParId_clicked()
{
    ui->tabMenu->setModel( tmpMenu.sortid());
}

void menuWindow::on_pushButton_clicked()
{

    bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;
}


/*void menuWindow::on_pushButton_calculer_clicked()
{
    QString daate ;
        note_menu tmpmenu ;
        daate=ui->lineEdit->text() ;
        int somme ;
        somme =tmpmenu.calculer_note(daate);

      ui->label_13->setText(QString::number(somme)) ;

}*/

void menuWindow::on_pushButton_afficher_note_clicked()
{
    note_menu tmpmenu ;
    ui->table_note->setModel(tmpmenu.afficher_note_menu());//refresh
}

void menuWindow::on_lineEdit_chercherMenu_textChanged(const QString &arg1)
{
    int str;
    str=ui->lineEdit_chercherMenu->text().toInt();
       ui->tabMenu->setModel(tmpMenu.recherche_avance(arg1));
}


void menuWindow::on_lineEdit_chercherMenu_2_textChanged(const QString &arg2)
{
    int str;
    str=ui->lineEdit_chercherMenu_2->text().toInt();
       ui->tabMenu->setModel(tmpMenu.recherche_avance_repas(arg2));
}

void menuWindow::on_pushButton_modifier_menu_clicked()
{
    QString jours,repas;
    int id;
    id=ui->lineEdit_chercherMenu->text().toInt();
    jours =ui->lineEdit_nvjours->text();
    repas =ui->lineEdit_nvrepas->text();
    QString dessert=ui->lineEdit_nvdessert->text() ;
    QString daate = ui->dateEdit_nvdate->text();



    if (ui->lineEdit_chercherMenu->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR ","VEUILLEZ VERIFIER CHAMP identifiant !!!!") ;

    }
  else  if  (ui->lineEdit_nvjours->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR","VEUILLEZ VERIFIER CHAMP jours  !!!!") ;

    }
else    if (ui->lineEdit_nvrepas->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP repas!!!!") ;
    }
    else    if (ui->lineEdit_nvdessert->text().isEmpty())
        {

            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP dessert!!!!") ;
        }
    else    if (ui->dateEdit_nvdate->text().isEmpty())
        {

            QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP date!!!!") ;
        }
else{
    //int id = ui->lineEdit->text().toInt();
     bool test=tmpMenu.modifier_menu(id,jours,repas,dessert,daate);
     if(test)
     {ui->tabMenu->setModel(tmpMenu.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("Modifier un menu"),
                     QObject::tr("Menu modifié avec succées.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Modifier un menu"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void menuWindow::on_imprimer_menu_clicked()
{


         QDate dd;
         QString format ;
         QMessageBox msgBox;


         format = "dd.MM.yyyy";

         int id = ui->lineEdit_id->text().toInt();
         QString jours= ui->lineEdit_jours->text();
         QString repas= ui->lineEdit_repas->text();
         QString dessert = ui->lineEdit_dessert->text();
         QString daate = ui->dateEdit_date2->text();



        Menu *m=new  Menu(id,jours,repas,dessert,daate);

        if(m->imprimer_menu())

                {
            msgBox.setText(" fait");
            msgBox.exec();

                }
}



void menuWindow::on_pushButton_afficher_par_typpe_clicked()
{
    ui->tabMenu->setModel(tmpMenu.afficher_par_type()) ;

}

void menuWindow::on_pushButton_4_clicked()
{

    note_menu tmpmenu ;
    ui->table_note->setModel(tmpmenu.afficher_caracteristique());//refresh

}

void menuWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void menuWindow::on_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void menuWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
