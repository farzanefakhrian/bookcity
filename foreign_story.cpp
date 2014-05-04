#include "foreign_story.h"
#include "ui_foreign_story.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Foreign_story::Foreign_story(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Foreign_story)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'fs%'");
    ui->tableView->setModel(model);
}

Foreign_story::~Foreign_story()
{
    delete ui;
}
