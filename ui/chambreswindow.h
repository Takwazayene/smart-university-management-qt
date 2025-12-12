#ifndef CHAMBRESWINDOW_H
#define CHAMBRESWINDOW_H

#include <QMainWindow>

namespace Ui {
class chambresWindow;
}

class chambresWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit chambresWindow(QWidget *parent = nullptr);
    ~chambresWindow();

private slots:
    void on_pushButton_chambre_clicked();

    void on_pushButton_store_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_lumiere_clicked();

private:
    Ui::chambresWindow *ui;
};

#endif // CHAMBRESWINDOW_H
