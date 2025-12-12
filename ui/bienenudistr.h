#ifndef BIENENUDISTR_H
#define BIENENUDISTR_H

#include <QMainWindow>
#include "produits.h"

namespace Ui {
class bienenuDistr;
}

class bienenuDistr : public QMainWindow
{
    Q_OBJECT

public:
    explicit bienenuDistr(QWidget *parent = nullptr);
    ~bienenuDistr();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::bienenuDistr *ui;
      produits tmpproduits;
};

#endif // BIENENUDISTR_H
