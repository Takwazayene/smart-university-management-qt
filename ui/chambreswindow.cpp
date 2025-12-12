#include "chambreswindow.h"
#include "ui_chambreswindow.h"
#include "bienvenufoyer.h"

chambresWindow::chambresWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chambresWindow)
{
    ui->setupUi(this);
}

chambresWindow::~chambresWindow()
{
    delete ui;
}

void chambresWindow::on_pushButton_chambre_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void chambresWindow::on_pushButton_store_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void chambresWindow::on_pushButton_retour_clicked()
{
    bienvenuFoyer *ff= new bienvenuFoyer();
    this->close();
    ff->show();
}

void chambresWindow::on_pushButton_lumiere_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}
