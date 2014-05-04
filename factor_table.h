#ifndef FACTOR_TABLE_H
#define FACTOR_TABLE_H

#include <QMainWindow>
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QString>

namespace Ui {
class factor_table;
}

class factor_table : public QMainWindow
{
    Q_OBJECT

public:
    explicit factor_table(QWidget *parent = 0);
    ~factor_table();

private slots:
    void on_pushButton_clicked();

private:
    Ui::factor_table *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // FACTOR_TABLE_H
