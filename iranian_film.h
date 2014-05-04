#ifndef IRANIAN_FILM_H
#define IRANIAN_FILM_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class iranian_film;
}

class iranian_film : public QMainWindow
{
    Q_OBJECT

public:
    explicit iranian_film(QWidget *parent = 0);
    ~iranian_film();

private slots:
    void on_pushButton_clicked();

private:
    Ui::iranian_film *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // IRANIAN_FILM_H
