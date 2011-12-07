#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

    QString ver;

    void InitAbout();

private:
    Ui::About *ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // ABOUT_H
