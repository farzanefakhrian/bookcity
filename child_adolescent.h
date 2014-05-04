#ifndef CHILD_ADOLESCENT_H
#define CHILD_ADOLESCENT_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Child_Adolescent;
}

class Child_Adolescent : public QMainWindow
{
    Q_OBJECT

public:
    explicit Child_Adolescent(QWidget *parent = 0);
    ~Child_Adolescent();

private slots:
    void on_pushButton_clicked();

    //void on_tableWidget_clicked(const QModelIndex &index);

    //void on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous);

private:
    Ui::Child_Adolescent *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // CHILD_ADOLESCENT_H
