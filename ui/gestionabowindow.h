#ifndef GESTIONABOWINDOW_H
#define GESTIONABOWINDOW_H

#include <QMainWindow>
#include "abonneresto.h"

namespace Ui {
class gestionAboWindow;
}

class gestionAboWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestionAboWindow(QWidget *parent = nullptr);
    ~gestionAboWindow();

private slots:
    void on_Retour_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_calculernbrepresence_destroyed(QObject *arg1);

    void on_pushButton_calculernbrepresence_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_trier_id_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_etu_clicked();

    void on_pushButton_chercher_par_id_clicked();

    void on_lineEdit_chercher_id_textChanged(const QString &arg1);

    void on_modifier_etu_2_clicked();

    void on_pushButton_afficherAbonne_par_type_clicked();

    void on_pushButton_afficher_nbre_par_type_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_calculer_demipension_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_modifier_etu_3_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_calculernbrepresence_2_clicked();

    void on_pushButton_afficher_nbre_par_type_2_clicked();

    void on_pushButton_afficherAbonne_par_type_2_clicked();

    void on_pushButton_trier_id_2_clicked();

    void on_pb_ajouter_2_clicked();

    void on_lineEdit_chercher_id_2_textChanged(const QString &arg1);

private:
    Ui::gestionAboWindow *ui;
    abonneResto tmpabonne;
};

#endif // GESTIONABOWINDOW_H
