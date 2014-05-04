#ifndef FOREIGN_MUSIC_H
#define FOREIGN_MUSIC_H
#include<QtGui>
#include<QtSql>
#include<QtCore>
#include <QMainWindow>

namespace Ui {
class Foreign_music;
}

class Foreign_music : public QMainWindow
{
    Q_OBJECT

public:
    explicit Foreign_music(QWidget *parent = 0);
    ~Foreign_music();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Foreign_music *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // FOREIGN_MUSIC_H
