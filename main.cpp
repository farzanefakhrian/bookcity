#include "login.h"
#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();



    return a.exec();
}
