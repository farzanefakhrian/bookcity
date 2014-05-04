#include "dialoghelp.h"
#include "ui_dialoghelp.h"

DialogHELP::DialogHELP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHELP)
{
    ui->setupUi(this);
}

DialogHELP::~DialogHELP()
{
    delete ui;
}
