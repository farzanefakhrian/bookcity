#ifndef TRADITIONAL_H
#define TRADITIONAL_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Traditional;
}

class Traditional : public QMainWindow
{
    Q_OBJECT

public:
    explicit Traditional(QWidget *parent = 0);
    ~Traditional();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Traditional *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // TRADITIONAL_H
