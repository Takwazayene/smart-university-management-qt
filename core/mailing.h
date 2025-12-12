#ifndef MAILING_H
#define MAILING_H

#include <QMainWindow>
#include "Smtp.h"
#include <QtWidgets/QMessageBox>

namespace Ui {
class mailing;
}

class mailing : public QMainWindow
{
    Q_OBJECT

public:
    explicit mailing(QWidget *parent = nullptr);
    ~mailing();

private slots:
    void sendMail();
    void mailSent(QString);

    void on_sendBtn_clicked();


    void on_pushButton_clicked();

private:
    Ui::mailing *ui;
};

#endif // MAILING_H
