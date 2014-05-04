#include "factor.h"
#include "ui_factor.h"
#include <QMessageBox>
#include <QDebug>
factor::factor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::factor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    int last_factor_id;

    QSqlQuery select_max_query;
    if(select_max_query.exec("SELECT max(factor_ID) FROM sold"))
    {
        if(select_max_query.next())
        {
            last_factor_id =  select_max_query.value(0).toInt();

        }
    }
    QSqlQuery select_factor_query;
    select_factor_query.prepare("SELECT ID,name,num,price,factor_ID,num*price as total_price FROM sold where factor_ID=:factor_ID");

    select_factor_query.bindValue(":factor_ID",last_factor_id);
    if(select_factor_query.exec())
    {
        while(select_factor_query.next())
        {
        }
    }
    else
    {
        qDebug()<<select_factor_query.lastError();
    }
    this->model=new QSqlQueryModel();
    model->setQuery(select_factor_query);
    ui->tableView->setModel(model);
    this->close();


}

factor::~factor()
{
    delete ui;
}
