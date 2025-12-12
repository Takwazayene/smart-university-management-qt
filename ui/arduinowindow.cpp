#include "arduinowindow.h"
#include "ui_arduinowindow.h"
#include "bienvenu.h"

arduinoWindow::arduinoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arduinoWindow)
{
    ui->setupUi(this);
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

arduinoWindow::~arduinoWindow()
{
    delete ui;
}

void arduinoWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText(" en position 1 -> ouvert"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="2")

        ui->label_3->setText("en position 0 -> fermé");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void arduinoWindow::on_pushButton_clicked()   // implémentation du slot bouton on
{
   /* bienvenu *b=new bienvenu();
  this->close() ;
  b->show();*/
      A.write_to_arduino("1");   //envoyer 2 à arduino
}

void arduinoWindow::on_pushButton_2_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("2");  //envoyer 0 à arduino
}

void arduinoWindow::on_pushButton_3_clicked()  // implémentation du slot bouton +
{
   // A.write_to_arduino("1");   //envoyer 2 à arduino
    bienvenu *b=new bienvenu();
  this->close() ;
  b->show();
}

void arduinoWindow::on_pushButton_4_clicked() // implémentation du slot bouton -
{
    A.write_to_arduino("4");  //envoyer 3 à arduino
}


