#include "foreign_music.h"
#include "ui_foreign_music.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Foreign_music::Foreign_music(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Foreign_music)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tableView);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:\\sqlite\\bookshop.db");
    db.open();

    this->model=new QSqlQueryModel();
    model->setQuery("select * from ajnas where ID like'fm%'");
    ui->tableView->setModel(model);
}

Foreign_music::~Foreign_music()
{
    delete ui;
}
