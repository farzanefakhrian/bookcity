#ifndef FOREIGN_STORY_H
#define FOREIGN_STORY_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Foreign_story;
}

class Foreign_story : public QMainWindow
{
    Q_OBJECT

public:
    explicit Foreign_story(QWidget *parent = 0);
    ~Foreign_story();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Foreign_story *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // FOREIGN_STORY_H
