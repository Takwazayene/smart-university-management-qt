#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>

#include"connection.h"
#include <QWidget>
#include"qcustomplot.h"
#include <QDialog>
namespace Ui {
class statistique;
}

class statistique : public QWidget
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = 0);
    ~statistique();
    void makePolt();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::statistique *ui;
};

#endif // STATISTIQUE_H
