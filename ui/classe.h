#ifndef CLASSE_H
#define CLASSE_H

#include <QMainWindow>
#include "etudiantclasse.h"
#include "salleclasse.h"


namespace Ui {
class classe;
}

class classe : public QMainWindow
{
    Q_OBJECT

public:
    explicit classe(QWidget *parent = nullptr);
    ~classe();

private slots:
    void on_pushButton_salle_clicked();

    void on_pb_ajouter_4_clicked();

    void on_retour_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_faire_appel_clicked();

    void on_pb_ajouter_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::classe *ui;
    etudiantClasse tmpetudiant;
    salleClasse salletemp ;

};

#endif // CLASSE_H
