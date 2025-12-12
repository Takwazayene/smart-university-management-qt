#ifndef PRODUIT_H
#define PRODUIT_H

#include <QMainWindow>
#include "produits.h"

namespace Ui {
class produit;
}

class produit : public QMainWindow
{
    Q_OBJECT

public:
    explicit produit(QWidget *parent = nullptr);
    ~produit();

private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::produit *ui;
    produits tmpproduits;
};

#endif // PRODUIT_H
