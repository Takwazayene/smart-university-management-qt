#include "mailing.h"
#include "ui_mailing.h"
#include "bienvenu.h"
#include <QtGui>
#include <QtCore>

mailing::mailing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    QPixmap pixx("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/mail2.jpg");
     ui->label_background->setPixmap(pixx) ;

     QPixmap pix2("C:/Users/LENOVO/Desktop/2a6/projet/mon projet/mail10.png");
     ui->label_mail->setPixmap(pix2) ;

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

void mailing::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void mailing::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
mailing::~mailing()
{
    delete ui;
}

void mailing::on_pushButton_clicked()
{  bienvenu  *w= new bienvenu();
    this->close() ;
    w->show() ;

}
