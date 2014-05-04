#include "pop.h"
#include "ui_pop.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


pop::pop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pop)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'pm%'");
    ui->tableView->setModel(model);
}

pop::~pop()
{
    delete ui;
}
