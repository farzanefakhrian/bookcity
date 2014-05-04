#ifndef FOREIGN_FILM_H
#define FOREIGN_FILM_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class foreign_film;
}

class foreign_film : public QMainWindow
{
    Q_OBJECT

public:
    explicit foreign_film(QWidget *parent = 0);
    ~foreign_film();

private slots:
    void on_pushButton_clicked();

private:
    Ui::foreign_film *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // FOREIGN_FILM_H
