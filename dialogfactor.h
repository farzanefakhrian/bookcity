#ifndef DIALOGFACTOR_H
#define DIALOGFACTOR_H

#include <QDialog>
#include<QtGui>
#include<QtSql>
#include<QtCore>

namespace Ui {
class Dialogfactor;
}

class Dialogfactor : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogfactor(QWidget *parent = 0);
    ~Dialogfactor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_2_clicked();

private:
    Ui::Dialogfactor *ui;
    QSqlDatabase db;
    bool is_new_factor;
};

#endif // DIALOGFACTOR_H
