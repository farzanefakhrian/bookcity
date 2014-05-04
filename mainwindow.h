#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QtGui>
#include<QtCore>
#include<QtSql>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_4_triggered();

    void on_action_6_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_19_triggered();

    void on_action_21_triggered();

    void on_action_23_triggered();

    void on_action_7_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
