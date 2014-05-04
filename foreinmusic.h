#ifndef FOREINMUSIC_H
#define FOREINMUSIC_H

#include <QMainWindow>

namespace Ui {
class foreinmusic;
}

class foreinmusic : public QMainWindow
{
    Q_OBJECT

public:
    explicit foreinmusic(QWidget *parent = 0);
    ~foreinmusic();

private:
    Ui::foreinmusic *ui;
};

#endif // FOREINMUSIC_H
