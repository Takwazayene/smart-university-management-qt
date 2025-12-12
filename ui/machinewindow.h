#ifndef MACHINEWINDOW_H
#define MACHINEWINDOW_H

#include <QMainWindow>
#include "machine.h"
namespace Ui {
class machineWindow;
}

class machineWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit machineWindow(QWidget *parent = nullptr);
    ~machineWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::machineWindow *ui;
     machine tmpmachine;
};

#endif // MACHINEWINDOW_H
