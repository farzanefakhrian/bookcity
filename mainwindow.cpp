#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "story.h"
#include "ui_story.h"
#include "poem.h"
#include "ui_poem.h"
#include "pop.h"
#include "ui_pop.h"
#include "child_adolescent.h"
#include "ui_child_adolescent.h"
#include "consolidated.h"
#include "ui_consolidated.h"
#include "foreign_music.h"
#include "ui_foreign_music.h"
#include "foreign_story.h"
#include "ui_foreign_story.h"
#include "reference.h"
#include "ui_reference.h"
#include "ui_traditional.h"
#include "traditional.h"
#include "ui_iranian_film.h"
#include "iranian_film.h"
#include "foreign_film.h"
#include "ui_foreign_film.h"
#include "dialogfactor.h"
#include "dialogkala.h"
#include  "dialoghelp.h"
#include "factor_table.h"
#include "ui_factor_table.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <qmessagebox.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    story *s1 = new story();
    s1->show();
    s1->setWindowTitle("story");
}

void MainWindow::on_action_2_triggered()
{
    poem *p1 = new poem();
    p1->show();
    p1->setWindowTitle("poem");

}

void MainWindow::on_action_4_triggered()
{
    Child_Adolescent *c1 = new Child_Adolescent();
    c1->show();
    c1->setWindowTitle("Child_Adolescent");
}


void MainWindow::on_action_6_triggered()
{
    Foreign_story *f_s =new Foreign_story();
    f_s->show();
    f_s->setWindowTitle("Foreign_story");

}

void MainWindow::on_action_9_triggered()
{
    Consolidated *con =new Consolidated();
    con->show();
    con->setWindowTitle("Consolidated");

}

void MainWindow::on_action_10_triggered()
{
    pop *p1 =new  pop();
    p1->show();
    p1->setWindowTitle("Pop");

}

void MainWindow::on_action_11_triggered()
{
    Traditional *trad =new  Traditional();
    trad->show();
    trad->setWindowTitle("Traditional");

}

void MainWindow::on_action_19_triggered()
{
    Foreign_music *fm =new  Foreign_music();
    fm->show();
    fm->setWindowTitle("Foreign_music");

}

void MainWindow::on_action_21_triggered()
{
    iranian_film *i_f =new  iranian_film();
    i_f->show();
    i_f->setWindowTitle("iranian_film");
}

void MainWindow::on_action_23_triggered()
{
    foreign_film *f_f =new  foreign_film();
    f_f->show();
    f_f->setWindowTitle("forein_film");
}

void MainWindow::on_action_7_triggered()
{
    Reference *ref =new  Reference();
    ref->show();
    ref->setWindowTitle("Reference");
}


void MainWindow::on_pushButton_clicked()
{
    Dialogfactor dfact;
    dfact.setModal(true);
    dfact.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialogkala dkala;
    dkala.setModal(true);
    dkala.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
   DialogHELP  dhelp;
   dhelp.setModal(true);
   dhelp.exec();
}

void MainWindow::on_pushButton_5_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

        db.setDatabaseName("D:\\sqlite\\bookshop.db");

    if(db.open())
    {
        QString sQuery="SELECT * FROM sold WHERE factor_ID = :factor_ID";
        QSqlQuery qrt;
        qrt.prepare(sQuery);
        int factor_ID = ui->lineEdit->text().toInt();
        qDebug()<<factor_ID;
        qrt.bindValue(":factor_ID",factor_ID);
        if(qrt.exec())
        {
            while(qrt.next())
            {
            }
        }
        this->model=new QSqlQueryModel();
        model->setQuery(qrt);
        ui->tableView->setModel(model);
       // this->close();

}
        ui->lineEdit->clear();

   // factor_table *fact = new factor_table();
   // fact->show();
   // fact->setWindowTitle("bills");
}
