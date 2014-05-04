#ifndef CONSOLIDATED_H
#define CONSOLIDATED_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Consolidated;
}

class Consolidated : public QMainWindow
{
    Q_OBJECT

public:
    explicit Consolidated(QWidget *parent = 0);
    ~Consolidated();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Consolidated *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // CONSOLIDATED_H
