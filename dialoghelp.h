#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QDialog>

namespace Ui {
class DialogHELP;
}

class DialogHELP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHELP(QWidget *parent = 0);
    ~DialogHELP();

private:
    Ui::DialogHELP *ui;
};

#endif // DIALOGHELP_H
