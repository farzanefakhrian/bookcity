#ifndef REFERENCE_H
#define REFERENCE_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Reference;
}

class Reference : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reference(QWidget *parent = 0);
    ~Reference();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Reference *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // REFERENCE_H
