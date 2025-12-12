#ifndef BIENVENUFOYER_H
#define BIENVENUFOYER_H

#include <QMainWindow>

namespace Ui {
class bienvenuFoyer;
}

class bienvenuFoyer : public QMainWindow
{
    Q_OBJECT

public:
    explicit bienvenuFoyer(QWidget *parent = nullptr);
    ~bienvenuFoyer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bienvenuFoyer *ui;
};

#endif // BIENVENUFOYER_H
