#ifndef GESTION_H
#define GESTION_H

#include <QMainWindow>
#include "prod.h"

namespace Ui {
class gestion;
}

class gestion : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();

private slots:
    void on_pb_ajouter_clicked();

    void on_modifier_clicked();

    void on_chercheid_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_retour_clicked();

private:
    Ui::gestion *ui;
     Prod tmpP;
};

#endif // GESTION_H
