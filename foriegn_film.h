#ifndef FORIEGN_FILM_H
#define FORIEGN_FILM_H

#include <QMainWindow>

namespace Ui {
class foriegn_film;
}

class foriegn_film : public QMainWindow
{
    Q_OBJECT

public:
    explicit foriegn_film(QWidget *parent = 0);
    ~foriegn_film();

private:
    Ui::foriegn_film *ui;
};

#endif // FORIEGN_FILM_H
