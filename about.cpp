#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->VerAbout->setText(ver);
}

About::~About()
{
    delete ui;
}

void About::InitAbout() {
    ui->VerAbout->setText(ver);
}

void About::on_buttonBox_accepted()
{
    close();
}
