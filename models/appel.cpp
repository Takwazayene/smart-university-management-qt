#include "appel.h"
#include "ui_appel.h"
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <ctype.h>
#include "bienvenuclasse.h"

appel::appel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::appel)
{
    ui->setupUi(this);
}
void appel::set_nbetudiants(int nbetudiants)
{
    this->nbeleves=nbetudiants;
}
appel::~appel()
{
    delete ui;
}

/*void appel::on_pushButton_save_clicked()
{
    ui->textBrowser_presence->clear();
    QAbstractItemModel* model =ui->tab_absent->model();
    int absents=model->rowCount();
    int integer;
    for (integer=0; integer<absents; integer++)
    {
        int col=0;
        QModelIndex idx = model->index(integer, col);
        QString text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText(" ");

        col++;
        idx = model->index(integer, col);
        text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText("  ");

        col++;
        idx = model->index(integer, col);
        text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText(" ");
        ui->textBrowser_presence->insertPlainText(" \r\n ");
    }
    QString sDate = QDateTime::currentDateTime().toString("ddddddMMMM");
    QString texte=ui->textBrowser_presence->toPlainText();

        QFile file("Absences"+sDate+".txt");
        QDir::setCurrent("C:/Users/HP/Documents/Interface_1/Absences");
        file.setFileName("Absences"+sDate+".txt");
        QDir::setCurrent("C:/Users/HP/Documents/Interface_1/Absences");
        file.open(QIODevice::ReadOnly);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream out(&file);
        out << " Liste des absents: \r\n " +texte+" ";


        // optional, as QFile destructor will already do it:
        file.close();

        //this would normally start the event loop, but is not needed for this
        //minimal example:
        //return app.exec();
}*/

void appel::on_pushButton_save_clicked()
{
    ui->textBrowser_presence->clear();
    QAbstractItemModel* model =ui->tab_absent->model();
    int absents=model->rowCount();
    int integer;
    for (integer=0; integer<absents; integer++)
    {
        int col=0;
        QModelIndex idx = model->index(integer, col);
        QString text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText(" ");

        col++;
        idx = model->index(integer, col);
        text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText("  ");

        col++;
        idx = model->index(integer, col);
        text = model->data(idx).toString();
        ui->textBrowser_presence->insertPlainText(text);
        ui->textBrowser_presence->insertPlainText(" ");
        ui->textBrowser_presence->insertPlainText(" \r\n ");
    }
    QString sDate = QDateTime::currentDateTime().toString("ddddddMMMM");
    QString texte=ui->textBrowser_presence->toPlainText();

        QFile file("Absences"+sDate+".txt");
        QDir::setCurrent("C:/Users/asus/Desktop/yassine/Interface_1/Absences");
        file.setFileName("Absences"+sDate+".txt");
        QDir::setCurrent("C:/Users/asus/Desktop/yassine/Interface_1/Absences");
        file.open(QIODevice::ReadOnly);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream out(&file);
        out << " Liste des absents: \r\n " +texte+" ";


        // optional, as QFile destructor will already do it:
        file.close();

        //this would normally start the event loop, but is not needed for this
        //minimal example:
        //return app.exec();
}

void appel::on_pushButton_calcul_clicked()
{
    QAbstractItemModel* model =ui->tab_absent->model();
    int absents=model->rowCount();
    int total=nbeleves;
    float presence=((total-absents)/(float)total);
    ui->textBrowser_presence->setText(QString::number(presence*100));
}

void appel::on_pushButton_clicked()
{
    bienvenuClasse *b=new bienvenuClasse();
  this->close() ;
  b->show();
}
