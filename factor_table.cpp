#include "factor_table.h"
#include "ui_factor_table.h"
#include<QString>
#include<QString>
factor_table::factor_table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::factor_table)
{
    ui->setupUi(this);
   /* this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();
    this->model=new QSqlQueryModel();
    model->setQuery("select ID,name,num,price from ajnas");
    ui->tableView->setModel(model);*/
}

factor_table::~factor_table()
{   
    db.close();
    QSqlQuery query;
    query.exec("DELETE FROM factor WHERE");
    delete ui;
}

