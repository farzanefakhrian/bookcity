#ifndef STORY_H
#define STORY_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class story;
}

class story : public QMainWindow
{
    Q_OBJECT

public:
    explicit story(QWidget *parent = 0);
    ~story();

private slots:
    void on_pushButton_clicked();

private:
    Ui::story *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // STORY_H
