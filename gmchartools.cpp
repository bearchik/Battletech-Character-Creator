#include "gmchartools.h"
#include "ui_gmchartools.h"
#include <QRegExp>
#include <QtGui>

GMCharTools::GMCharTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GMCharTools)
{
    ui->setupUi(this);

    addCBills = 0;
    addXP = 0;

//    QRegExp regExp("[0-9]{0,}[.][0-9]{1,2}");
    QRegExp regExp("[0-9]{0,}");
    ui->ToMoneyAddGm->setValidator(new QRegExpValidator(regExp,this));
    ui->FromMoneyAddGm->setValidator(new QRegExpValidator(regExp,this));
    QRegExp regExpXP("[0-9]{0,}");
    ui->XPAddGM->setValidator(new QRegExpValidator(regExpXP,this));

//    double a = 12345.12;
//    double b = 54321.12;
//    double c;

//    c = a*b;

//    QString str;
//    str = QVariant(c).toString();

//    qDebug() << str;
}

GMCharTools::~GMCharTools()
{
    delete ui;
}

void GMCharTools::on_ToMoneyAddGm_textEdited(QString textString)
{
    bool ok;

    if(ui->FromValuteGm->currentText() == ui->ToValuteGm->currentText()) {
        ui->FromMoneyAddGm->setText(QString::number(textString.toFloat(&ok)));
    }
}

void GMCharTools::on_FromMoneyAddGm_textEdited(QString textString)
{
    addCBills = textString.toInt();
}

void GMCharTools::on_XPAddGM_textEdited(QString textString)
{
    addXP = textString.toInt();
}
