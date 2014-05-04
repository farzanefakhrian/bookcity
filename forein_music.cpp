#include "foreinmusic.h"
#include "ui_foreinmusic.h"

foreinmusic::foreinmusic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::foreinmusic)
{
    ui->setupUi(this);
}

foreinmusic::~foreinmusic()
{
    delete ui;
}
