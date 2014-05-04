#include "foriegn_film.h"
#include "ui_foriegn_film.h"

foriegn_film::foriegn_film(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::foriegn_film)
{
    ui->setupUi(this);
}

foriegn_film::~foriegn_film()
{
    delete ui;
}
