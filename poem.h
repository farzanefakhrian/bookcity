#ifndef POEM_H
#define POEM_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class poem;
}

class poem : public QMainWindow
{
    Q_OBJECT

public:
    explicit poem(QWidget *parent = 0);
    ~poem();

private slots:
    void on_pushButton_clicked();

private:
    Ui::poem *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // POEM_H
