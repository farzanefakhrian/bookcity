#include "reference.h"
#include "ui_reference.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


Reference::Reference(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reference)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'rb%'");
    ui->tableView->setModel(model);
}

Reference::~Reference()
{
    delete ui;
}
