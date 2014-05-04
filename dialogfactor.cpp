#include "dialogfactor.h"
#include "ui_dialogfactor.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <qmessagebox.h>
#include "factor.h"
#include "ui_factor.h"
Dialogfactor::Dialogfactor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogfactor)
{
    ui->setupUi(this);
     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("D:\\sqlite\\bookshop.db");
     is_new_factor = true;
}

Dialogfactor::~Dialogfactor()
{
    delete ui;
}

void Dialogfactor::on_pushButton_clicked()
{
    factor *fact = new factor();
    fact->show();
    fact->setWindowTitle("current_factor");
    close();
}

void Dialogfactor::on_pushButton_3_clicked()
{
    int price,ajnas_num;
    QString name = "";
    QString ID = ui->lineEdit->text();
    int num = ui->lineEdit_2->text().toInt();
        if(db.open())
        {
            QString sQuery_ajnas = "SELECT * FROM ajnas WHERE ID = :ID";
            QSqlQuery slct_query;
            slct_query.prepare(sQuery_ajnas);
            slct_query.bindValue(":ID",ID);
            if(slct_query.exec())
            {
                if(slct_query.next())
                {
                    name = slct_query.value(1).toString();
                    price = slct_query.value(3).toInt();
                    ajnas_num = slct_query.value(2).toInt()-num;
                    if((ajnas_num>=0) && (num>0)){
                        QString sQuery="INSERT INTO sold values(:ID,:name,:num,:price,:factor_ID)";
                        QSqlQuery qrt;
                        qrt.prepare(sQuery);
                        qrt.bindValue(":ID",ID);
                        qrt.bindValue(":num",num);
                        qrt.bindValue(":name",name);
                        qrt.bindValue(":price",price);
                        int factor_id;
                        QSqlQuery select_max_query;
                        if(select_max_query.exec("SELECT max(factor_ID) FROM sold"))
                        {
                            if(select_max_query.next())
                            {
                                factor_id =  select_max_query.value(0).toInt();
                                if(is_new_factor) factor_id++;
                                is_new_factor = false;

                            }
                        }
                        qrt.bindValue(":factor_ID",factor_id);
                        if(qrt.exec())
                        {
                           qDebug() <<"record insert";
                        }
                        else
                        {
                            qDebug()<<qrt.lastError();
                        }
                }
                    else{
                        QMessageBox msg;
                        msg.setText("this item is not available");
                        msg.setStandardButtons(QMessageBox::Ok);
                        msg.exec();
                        return;
                    }

                    }
                }
                else{
                    QMessageBox msg;
                    msg.setText("this item is not available");
                    msg.setStandardButtons(QMessageBox::Ok);
                    msg.exec();
                    return;
                }
            }

           /* QString sQuery="INSERT INTO sold values(:ID,:name,:num,:price,:factor_ID)";
            QSqlQuery qrt;
            qrt.prepare(sQuery);

            qrt.bindValue(":ID",ID);

            qrt.bindValue(":num",num);

            QString sQuery_ajnas = "SELECT * FROM ajnas WHERE ID = :ID";
            QSqlQuery slct_query;
            slct_query.prepare(sQuery_ajnas);
            slct_query.bindValue(":ID",ID);

            if(slct_query.exec())
            {
                if(slct_query.next())
                {
                    name = slct_query.value(1).toString();
                    price = slct_query.value(3).toInt();
                    ajnas_num = slct_query.value(2).toInt()-num;
                }
                else{
                    QMessageBox msg;
                    msg.setText("this item is not available");
                    msg.setStandardButtons(QMessageBox::Ok);
                    msg.exec();
                    return;
                }
            }

            qrt.bindValue(":name",name);
            qrt.bindValue(":price",price);
            int factor_id;
            QSqlQuery select_max_query;
            if(select_max_query.exec("SELECT max(factor_ID) FROM sold"))
            {
                if(select_max_query.next())
                {
                    factor_id =  select_max_query.value(0).toInt();
                    if(is_new_factor) factor_id++;
                    is_new_factor = false;

                }
            }
            qrt.bindValue(":factor_ID",factor_id);*/

            ui->lineEdit->clear();
            ui->lineEdit_2->clear();


            /*if(qrt.exec())
            {
               qDebug() <<"record insert";
            }
            else
            {
                qDebug()<<qrt.lastError();
            }
    }*/

    db.close();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    if(db.open())
    {
       QString sQuery="update ajnas set num=:num where ID=:ID ";
       QSqlQuery qrt;
       qrt.prepare(sQuery);
       qrt.bindValue(":ID",ID);
       qrt.bindValue(":num",ajnas_num);
       if(qrt.exec())
       {
          qDebug() <<"record insert";
       }
    }
       /* QString sq;
        QSqlQuery delQry;
        sq = "DELETE FROM ajans WHERE ID = :id ";
        delQry.prepare(sq);
        delQry.bindValue(":id",ID);
        QSqlQuery insQry;
        sq = "INSERT INTO ajans VALUES(:ID,:name,:num,:price)";
        insQry.prepare(sq);
        insQry.bindValue(":ID",ID);
        insQry.bindValue(":name",name);
        insQry.bindValue(":num",ajnas_num);
        insQry.bindValue(":price",price);

        delQry.exec();
        insQry.exec();
        qDebug()<<"DEL:"<<delQry.lastError();
        qDebug()<<"INS:"<<insQry.lastError();
    }*/
}


