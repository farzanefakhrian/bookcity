#include "poem.h"
#include "ui_poem.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

poem::poem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::poem)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'pb%'");
    ui->tableView->setModel(model);
}

poem::~poem()
{
    delete ui;
}
