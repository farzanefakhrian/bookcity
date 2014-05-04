#ifndef FACTOR_H
#define FACTOR_H

#include <QMainWindow>
#include<QtGui>
#include<QtSql>
#include<QtCore>

namespace Ui {
class factor;
}

class factor : public QMainWindow
{
    Q_OBJECT

public:
    explicit factor(QWidget *parent = 0);
    ~factor();

private:
    Ui::factor *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // FACTOR_H
