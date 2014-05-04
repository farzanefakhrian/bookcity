#include "traditional.h"
#include "ui_traditional.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Traditional::Traditional(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Traditional)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'tb%'");
    ui->tableView->setModel(model);
}

Traditional::~Traditional()
{
    delete ui;
}


