#include "consolidated.h"
#include "ui_consolidated.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Consolidated::Consolidated(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Consolidated)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'cm%'");
    ui->tableView->setModel(model);
}

Consolidated::~Consolidated()
{
    delete ui;
}
