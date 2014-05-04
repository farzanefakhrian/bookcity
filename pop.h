#ifndef POP_H
#define POP_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class pop;
}

class pop : public QMainWindow
{
    Q_OBJECT

public:
    explicit pop(QWidget *parent = 0);
    ~pop();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pop *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // POP_H
