#ifndef BIENVENUCLASSE_H
#define BIENVENUCLASSE_H

#include <QMainWindow>

namespace Ui {
class bienvenuClasse;
}

class bienvenuClasse : public QMainWindow
{
    Q_OBJECT

public:
    explicit bienvenuClasse(QWidget *parent = nullptr);
    ~bienvenuClasse();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bienvenuClasse *ui;
};

#endif // BIENVENUCLASSE_H
