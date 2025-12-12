#ifndef SALLEWINDOW_H
#define SALLEWINDOW_H

#include <QMainWindow>
#include "salleclasse.h"

namespace Ui {
class salleWindow;
}

class salleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit salleWindow(QWidget *parent = nullptr);
    ~salleWindow();

private slots:
    void on_pb_ajouter_2_clicked();

private:
    Ui::salleWindow *ui;
    salleClasse tmpsalle;
};

#endif // SALLEWINDOW_H
