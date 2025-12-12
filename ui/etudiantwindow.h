#ifndef ETUDIANTWINDOW_H
#define ETUDIANTWINDOW_H

#include <QMainWindow>
#include "note_menu.h"
#include "menu.h"
#include "abonneresto.h"
namespace Ui {
class etudiantWindow;
}

class etudiantWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit etudiantWindow(QWidget *parent = nullptr);
    ~etudiantWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_affichermenu_clicked();

    void on_pushButton_notezmenu_clicked();

    void on_pushButton_2_clicked();

    void on_imprimer_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::etudiantWindow *ui;
    note_menu tmp_note_menu ;
    Menu *tmpmenuu ;
    abonneResto *et ;

};

#endif // ETUDIANTWINDOW_H
