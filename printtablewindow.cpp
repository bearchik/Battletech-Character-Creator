#include "printtablewindow.h"
#include "ui_printtablewindow.h"
#include <QtGui>

PrintTableWindow::PrintTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintTableWindow)
{
    ui->setupUi(this);
}

PrintTableWindow::~PrintTableWindow()
{
    delete ui;
}

void PrintTableWindow::on_buttonBox_accepted()
{

    if (ui->CombatTable->isChecked() || ui->DamageTable->isChecked() || ui->ActionsTable->isChecked() || ui->MovementTable->isChecked()) {
        QPrintDialog printDialog(&printer, this);

        printer.setPaperSize(QPrinter::Letter);
        printer.setOrientation(QPrinter::Portrait);
        bool prntCheck = false;

        QString verStr;
        verStr = "Printed from Battletech Character Creator v.";
        verStr += shortver;
        verStr += " - http://bthub.net";


        if(printDialog.exec()) {
            QImage img;
            QPainter painter(&printer);
            QRect rect = painter.viewport();
            QSize size = img.size();
            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
            if(ui->CombatTable->isChecked()) {
                if (prntCheck) {
                    printer.newPage();
                }
                img.load(":/img/table_combat.png");
                size.scale(rect.size(), Qt::KeepAspectRatio);
                painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
                painter.setWindow(img.rect());
                painter.drawImage(0,0,img);
                prntCheck = true;

                painter.drawText(700, 3250, img.height(), img.width(),0,verStr);
            }

            if(ui->DamageTable->isChecked()) {
                if (prntCheck) {
                    printer.newPage();
                }
                img.load(":/img/table_damage.png");
                size.scale(rect.size(), Qt::KeepAspectRatio);
                painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
                painter.setWindow(img.rect());
                painter.drawImage(0,0,img);
                prntCheck = true;

                painter.drawText(700, 3250, img.height(), img.width(),0,verStr);
            }

            if(ui->ActionsTable->isChecked()) {
                if (prntCheck) {
                    printer.newPage();
                }
                img.load(":/img/table_actions.png");
                size.scale(rect.size(), Qt::KeepAspectRatio);
                painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
                painter.setWindow(img.rect());
                painter.drawImage(0,0,img);
                prntCheck = true;


                painter.drawText(700, 3250, img.height(), img.width(),0,verStr);
            }

            if(ui->MovementTable->isChecked()) {
                if (prntCheck) {
                    printer.newPage();
                }
                img.load(":/img/table_movemet.png");
                size.scale(rect.size(), Qt::KeepAspectRatio);
                painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
                painter.setWindow(img.rect());
                painter.drawImage(0,0,img);
                prntCheck = true;

                painter.drawText(700, 3250, img.height(), img.width(),0,verStr);
            }
        }
    }

}
