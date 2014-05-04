#ifndef DIALOGKALA_H
#define DIALOGKALA_H

#include <QDialog>

namespace Ui {
class Dialogkala;
}

class Dialogkala : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogkala(QWidget *parent = 0);
    ~Dialogkala();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogkala *ui;
};

#endif // DIALOGKALA_H
