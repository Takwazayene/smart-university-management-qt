#ifndef VENTEWINDOW_H
#define VENTEWINDOW_H

#include <QMainWindow>
#include "vente.h"

namespace Ui {
class venteWindow;
}

class venteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit venteWindow(QWidget *parent = nullptr);
    ~venteWindow();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::venteWindow *ui;
     vente tmpventes;
};

#endif // VENTEWINDOW_H
