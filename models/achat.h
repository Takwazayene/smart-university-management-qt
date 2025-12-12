#ifndef ACHAT_H
#define ACHAT_H

#include <QMainWindow>
#include "produit.h"
#include "vente.h"
#include "arduino.h"

namespace Ui {
class achat;
}

class achat : public QMainWindow
{
    Q_OBJECT

public:
    explicit achat(QWidget *parent = nullptr);
    ~achat();

private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();
      void update_label();

private:
    Ui::achat *ui;
    produits tmpproduits;
    vente tmpventes;
    Arduino A;
       QByteArray data;
};

#endif // ACHAT_H
