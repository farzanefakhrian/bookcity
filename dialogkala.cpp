#include "dialogkala.h"
#include "ui_dialogkala.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <qmessagebox.h>
Dialogkala::Dialogkala(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogkala)
{
    ui->setupUi(this);
}

Dialogkala::~Dialogkala()
{
    delete ui;
}

void Dialogkala::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        db.setDatabaseName("D:\\sqlite\\bookshop.db");

        if(db.open())
        {

            QString sQuery="INSERT INTO ajnas values(:first,:second,:third,:last)";
            QSqlQuery qrt;
            qrt.prepare(sQuery);
            //QSqlQuery qry;
            QString ID = ui->lineEdit->text();
            qrt.bindValue(":first",ID);
            QString name = ui->lineEdit_2->text();
            qrt.bindValue(":second",name);
            int count = ui->lineEdit_3->text().toInt();
            qrt.bindValue(":third",count);
            int price = ui->lineEdit_4->text().toInt();
            qrt.bindValue(":last",price);
            if(qrt.exec())
            {
               qDebug() <<"record insert";
            }

           /* if(qry.exec("SELECT * FROM [ajnas]"))
            {
                while(qry.next())
                {
                   qDebug ()<<qry.value(0).toString();
                }
            }
            else
            {
                 qDebug() <<"Error1"<<db.lastError().text();
            }
            qDebug() <<"closing...";
            db.close();


        }
        else
        {
            qDebug() <<"Error"<<db.lastError().text();

        }
   this->close();
   QMessageBox msg;
   msg.setText("HOORAY");
   msg.setStandardButtons(QMessageBox::Ok);
   msg.exec();*/
}
        close();
}
