#ifndef APPEL_H
#define APPEL_H

#include <QMainWindow>
#include "etudiantclasse.h"
#include "absent.h"

namespace Ui {
class appel;
}

class appel : public QMainWindow
{
    Q_OBJECT

public:
    explicit appel(QWidget *parent = nullptr);
      void set_nbetudiants(int);
    ~appel();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_calcul_clicked();

    void on_pushButton_clicked();

private:
    Ui::appel *ui;
    etudiantClasse temporaire;
    Absent absent;
    int nbeleves;
};

#endif // APPEL_H
