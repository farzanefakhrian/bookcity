#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"



login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);



    ui->lineEdit->setText("BookCity_Centeral_Store");
    ui->lineEdit_2->setText("roze_khub_miad");


}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "BookCity_Centeral_Store" && ui->lineEdit_2->text() == "roze_khub_miad" ) {

        MainWindow *win = new MainWindow();
        win->show();
        win->setWindowTitle("MainWindow");

        close() ;
}
}
