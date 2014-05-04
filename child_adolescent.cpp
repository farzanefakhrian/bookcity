#include "child_adolescent.h"
#include "ui_child_adolescent.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Child_Adolescent::Child_Adolescent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Child_Adolescent)
{
    ui->setupUi(this);
}

Child_Adolescent::~Child_Adolescent()
{
    delete ui;
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'ca%'");
    ui->tableView->setModel(model);
}
