#ifndef ARDUINOWINDOW_H
#define ARDUINOWINDOW_H

#include <QMainWindow>
#include "arduino.h"
namespace Ui {
class arduinoWindow;
}

class arduinoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit arduinoWindow(QWidget *parent = nullptr);
    ~arduinoWindow();

private slots:

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_clicked();   // bouton ON

    void on_pushButton_2_clicked(); // bouton OFF

    void on_pushButton_3_clicked(); // bouton +

    void on_pushButton_4_clicked(); // bouton -

    void on_ouvrir_porte_clicked();

private:
    Ui::arduinoWindow *ui;

    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire

};

#endif // ARDUINOWINDOW_H
