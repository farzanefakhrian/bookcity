#include "story.h"
#include "ui_story.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

story::story(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::story)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'sb%'");
    ui->tableView->setModel(model);
}

story::~story()
{
    db.close();
    delete ui;
}
