#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "menu.h"


namespace Ui {
class menuWindow;
}

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private slots:
    void on_ajouter_clicked();

    void on_pushButton_chercherMenu_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_trierParJours_clicked();

    void on_pushButton_trierParId_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_calculer_clicked();

    void on_pushButton_afficher_note_clicked();

    void on_lineEdit_chercherMenu_textChanged(const QString &arg1);

    void on_pushButton_chercher_plat_clicked();

    void on_lineEdit_chercherMenu_2_textChanged(const QString &arg1);

    void on_pushButton_modifier_menu_clicked();

    void on_lineEdit_chercherMenu_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_2_clicked();

    void on_imprimer_menu_clicked();

    void on_pushButton_afficher_par_typpe_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::menuWindow *ui;
    Menu tmpMenu;
    Menu *tmpMenuu ;


};

#endif // MENUWINDOW_H
