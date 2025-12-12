#include "sallewindow.h"
#include "ui_sallewindow.h"
#include "QMessageBox"
salleWindow::salleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::salleWindow)
{
    ui->setupUi(this);
}

salleWindow::~salleWindow()
{
    delete ui;
}

void salleWindow::on_pb_ajouter_2_clicked()
{
    int compter=ui->tabsalles->height();
    QString numero = ui->lineEdit_numero_salle->text();
    ui->lineEdit_numero_salle->clear();
    bool test=tmpsalle.supprimer(numero);
    if(test)
    {ui->tabsalles->setModel(tmpsalle.afficher());
        int count=ui->tabsalles->size().height();
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
