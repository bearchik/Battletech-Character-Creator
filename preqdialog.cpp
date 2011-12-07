#include "preqdialog.h"
#include "ui_preqdialog.h"
#include <QtGui>

PreqDialog::PreqDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreqDialog)
{
    ui->setupUi(this);
    preAttr.clear();
    preSkills.clear();
    preTraits.clear();
    earlyChild.clear();
}

PreqDialog::~PreqDialog()
{
    delete ui;
}

void PreqDialog::initPreDialog() {

    PrintTable();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);

    if(!preAttr.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }

    if(!preTraits.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }

    if(!preSkills.isEmpty()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }

    if(earlyChild == "Nobility" && realLife == "Covert Operations") {
        QMessageBox::information(this, tr("Prerequisites"),tr("Choose one: 500XP in Wealth, Title or Property and 150XP in Connections Trait or Leadership Skill"));
    } else {
        if(earlyChild == "White Collar" && realLife == "Covert Operations") {
            QMessageBox::information(this, tr("Prerequisites"),tr("Choose one: 300XP in Wealth or Property and 150XP in Connections Trait or Leadership Skill"));
        } else {
            if (earlyChild == "Nobility") {
               QMessageBox::information(this, tr("Prerequisites"),tr("Choose one: 500XP in Wealth , Title or Property."));
            }

            if (earlyChild == "White Collar") {
               QMessageBox::information(this, tr("Prerequisites"),tr("Choose one: 300XP in Wealth or Property."));
            }

            if (realLife == "Covert Operations") {
               QMessageBox::information(this, tr("Prerequisites"),tr("Choose one: 150XP in Connections Trait or Leadership Skill."));
            }
        }

    }





}

void PreqDialog::PrintTable()
{
    ui->preqListTable->clearSpans();
    QList<QPair<QString, int> > printList;

    QMapIterator <QString, int> i(preAttr);
    while(i.hasNext()) {
        i.next();
        printList.append(qMakePair(i.key(),i.value()));
    }

    printList = printList + preTraits + preSkills;


    ui->preqListTable->setRowCount(printList.count());

    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->preqListTable->setItem(sCount,0,newNameItem);
        QTableWidgetItem *newValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->preqListTable->setItem(sCount,1,newValueItem);
        newValueItem->setTextAlignment(Qt::AlignCenter);
    }
}



void PreqDialog::on_preqListTable_cellClicked(int row, int)
{
    QTableWidgetItem *elemName = new QTableWidgetItem;
    elemName = ui->preqListTable->item(row, 0);
    QTableWidgetItem *elemVar = new QTableWidgetItem;
    elemVar = ui->preqListTable->item(row, 1);

    if(elemName != 0x0) {

        if(earlyChild == "Nobility" && realLife == "Covert Operations") {
            NobChange(elemName->text());
            CovOpChange(elemName->text());
        } else {
            if(earlyChild == "White Collar" && realLife == "Covert Operations") {
                WhiteColChange(elemName->text());
                CovOpChange(elemName->text());
            } else {
                if(earlyChild == "Nobility") {
                    NobChange(elemName->text());
                }

                if(earlyChild == "White Collar") {
                    WhiteColChange(elemName->text());
                }

                if(realLife == "Covert Operations") {
                    CovOpChange(elemName->text());
                }
            }
        }

    }

    PrintTable();

}

void PreqDialog::NobChange(QString elemName) {
    for(int i =0; i < preTraits.size(); ++i) {
        if (elemName == "Wealth") {

            if(preTraits[i].first == "Title") {
                preTraits.removeAt(i);
            }
            if(preTraits[i].first == "Property") {
                preTraits.removeAt(i);
            }
        }

        if (elemName == "Title") {

            if(preTraits[i].first == "Wealth") {
                preTraits.removeAt(i);
            }
            if(preTraits[i].first == "Property") {
                preTraits.removeAt(i);
            }
        }

        if (elemName == "Property") {

            if(preTraits[i].first == "Title") {
                preTraits.removeAt(i);
            }

            if(preTraits[i].first == "Wealth") {
                preTraits.removeAt(i);
            }

        }

    }
}

void PreqDialog::WhiteColChange(QString elemName) {
    for(int i =0; i < preTraits.size(); ++i) {
        if (elemName == "Wealth") {
            if(preTraits[i].first == "Property") {
                preTraits.removeAt(i);
            }
        }

        if (elemName == "Property") {

            if(preTraits[i].first == "Wealth") {
                preTraits.removeAt(i);
            }

        }
    }
}

void PreqDialog::CovOpChange(QString elemName) {
    if (elemName == "Connections") {
        for(int i =0; i < preSkills.size(); ++i) {
            if(preSkills[i].first == "Leadership") {
                preSkills.removeAt(i);
            }
        }
    }

    if (elemName == "Leadership") {
        for(int i =0; i < preTraits.size(); ++i) {
            if(preTraits[i].first == "Connections") {
                preTraits.removeAt(i);
            }

        }
    }
}

