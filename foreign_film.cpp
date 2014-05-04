#include "foreign_film.h"
#include "ui_foreign_film.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

foreign_film::foreign_film(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::foreign_film)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'ff%'");
    ui->tableView->setModel(model);
}

foreign_film::~foreign_film()
{
    delete ui;
}
