#include "iranian_film.h"
#include "ui_iranian_film.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

iranian_film::iranian_film(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iranian_film)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'pf%'");
    ui->tableView->setModel(model);
}

iranian_film::~iranian_film()
{
    delete ui;
}
