#include "s2clanfielddialog.h"
#include "ui_s2clanfielddialog.h"
#include "QtGui"

S2ClanFieldDialog::S2ClanFieldDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S2ClanFieldDialog)
{
    ui->setupUi(this);
    S2CFDConnectEvent();
    s2CFDRebateSum = 0;
}

S2ClanFieldDialog::~S2ClanFieldDialog()
{
    delete ui;
}


void S2ClanFieldDialog::S2CFDInit() {

    ui->S2CFDBasicComboBox->clear();
    ui->S2CFDAdvComboBox->clear();
    ui->S2CFDBasicComboBox->addItems(s2CFDBasicList);
    ui->S2CFDAdvComboBox->addItems(s2CFDAdvList);
    ui->S2CFDAdvLabel->setText(s2CFDClanAdvLabel + " field");
    ui->S2CFDAdvLabel->setFont(QFont("MS Shell Dlg 2", 8, QFont::Bold));
    s2CFDClanBasicSkills.clear();
    s2CFDClanAdvSkills.clear();
    advListPart1.clear();
    advListPart2.clear();
    advListPart3.clear();
    advListPart4.clear();
    advListPart5.clear();


    advListPart1 << "Artillery";
    advListPart2 << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles" << "Piloting/Air Vehicle";
    advListPart3 << "Gunnery/Land" << "Gunnery/Sea" << "Air Vehicle";
    advListPart4 << "Sensor Operations";
    advListPart5 << "Tactics/Land" << "Tactics/Air";

    S2CFDChange();
}

void S2ClanFieldDialog::S2CFDChange() {

    s2CFDRebateSum = s2CFDClanBasicRebateXP * s2CFDClanBasicSkills.count() + s2CFDClanAdvRebateXP * s2CFDClanAdvSkills.count();
     ui->S2CFDBasicFreeXP->setText(QString::number(s2CFDClanBasicXP - s2CFDClanBasicSkills.count() * s2CFDClanBasicStepXP));
     ui->S2CFDAdvFreeXP->setText(QString::number(s2CFDClanAdvXP - s2CFDClanAdvSkills.count() * s2CFDClanAdvStepXP));
     ui->S2CFDBasicRebateXP->setText(QString::number(s2CFDClanBasicRebateXP * s2CFDClanBasicSkills.count()));
      ui->S2CFDAdvRebateXP->setText(QString::number(s2CFDClanAdvRebateXP * s2CFDClanAdvSkills.count()));

      ui->S2CFDBasicFreeXP->setFont(QFont("MS Shell Dlg 2", 16, QFont::Bold));
      ui->S2CFDAdvFreeXP->setFont(QFont("MS Shell Dlg 2", 16, QFont::Bold));
      ui->S2CFDBasicRebateXP->setFont(QFont("MS Shell Dlg 2", 16, QFont::Bold));
       ui->S2CFDAdvRebateXP->setFont(QFont("MS Shell Dlg 2", 16, QFont::Bold));

       S2CFDPrintSkillsAdvTable();
       S2CFDPrintSkillsBasicTable();
}

void S2ClanFieldDialog::S2CFDConnectEvent() {
    connect(ui->S2CFDBasicComboBox, SIGNAL(activated(QString)), this, SLOT(S2CFDClanBasicCombBox(QString)));
    connect(ui->S2CFDAdvComboBox, SIGNAL(activated(QString)), this, SLOT(S2CFDClanAdvCombBox(QString)));

    connect(ui->S2CFDBasicTable, SIGNAL(cellClicked(int,int)), this, SLOT(S2CFDClanBasicTable(int,int)));
    connect(ui->S2CFDAdvTable, SIGNAL(cellClicked(int,int)), this, SLOT(S2CFDClanAdvTable(int,int)));
}

void S2ClanFieldDialog::S2CFDClanAdvCombBox(QString nameElem) {
    ui->S2CFDAdvComboBox->clear();


    s2CFDClanAdvSkills.append(qMakePair(nameElem, s2CFDClanAdvStepXP));
    if(s2CFDClanAdvLabel != "Cavalry") {
        for(int i =0; i < s2CFDAdvList.count(); i++) {
            if(s2CFDAdvList[i] == nameElem) {
                s2CFDAdvList.removeAt(i);
            }
        }
    } else {

        if(nameElem ==  "Artillery") {
            advListPart1.clear();
        }

        if(nameElem == "Driving/Ground Vehicles" || nameElem == "Driving/Rail Vehicles") {
            advListPart2.clear();
        }

        if(nameElem == "Driving/Sea Vehicles" || nameElem == "Piloting/Air Vehicle") {
            advListPart2.clear();
        }

        if(nameElem == "Gunnery/Land" || nameElem == "Gunnery/Sea") {
            advListPart3.clear();
        }

        if(nameElem ==  "Air Vehicle") {
            advListPart3.clear();
        }

        if(nameElem ==  "Sensor Operations") {
            advListPart4.clear();
        }

        if(nameElem == "Tactics/Land" || nameElem == "Tactics/Air") {
            advListPart5.clear();
        }
        s2CFDAdvList.clear();
        s2CFDAdvList << advListPart1 << advListPart2 << advListPart3 << advListPart4 << advListPart5;
    }

    ui->S2CFDAdvComboBox->addItems(s2CFDAdvList);
    S2CFDChange();
}

void S2ClanFieldDialog::S2CFDClanBasicCombBox(QString nameElem) {

    ui->S2CFDBasicComboBox->clear();

    s2CFDClanBasicSkills.append(qMakePair(nameElem, s2CFDClanBasicStepXP));
    for(int i =0; i < s2CFDBasicList.count(); i++) {
        if(s2CFDBasicList[i] == nameElem) {
            s2CFDBasicList.removeAt(i);
        }
    }

    ui->S2CFDBasicComboBox->addItems(s2CFDBasicList);
    S2CFDChange();
}

void S2ClanFieldDialog::S2CFDPrintSkillsAdvTable() {
    ui->S2CFDAdvTable->clear();

    for(int sCount = 0 ; sCount < s2CFDClanAdvSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(s2CFDClanAdvSkills[sCount].first);
        ui->S2CFDAdvTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(s2CFDClanAdvSkills[sCount].second));
        ui->S2CFDAdvTable->setItem(sCount,1,newSValueItem);
    }

}

void S2ClanFieldDialog::S2CFDPrintSkillsBasicTable() {
    ui->S2CFDBasicTable->clear();

    for(int sCount = 0 ; sCount < s2CFDClanBasicSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(s2CFDClanBasicSkills[sCount].first);
        ui->S2CFDBasicTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(s2CFDClanBasicSkills[sCount].second));
        ui->S2CFDBasicTable->setItem(sCount,1,newSValueItem);
    }

}

void S2ClanFieldDialog::S2CFDClanBasicTable(int x, int) {

    QTableWidgetItem *skillName = new QTableWidgetItem;
    QTableWidgetItem *skillAttr = new QTableWidgetItem;
    skillName = ui->S2CFDBasicTable->item(x, 0);
    skillAttr = ui->S2CFDBasicTable->item(x, 1);

    if(skillName != 0x0) {
        ui->S2CFDBasicComboBox->clear();
        for(int i = 0; i < s2CFDClanBasicSkills.count(); ++i) {
            if(s2CFDClanBasicSkills[i].first == skillName->text()) {
                s2CFDClanBasicSkills.removeAt(i);
            }
        }
        s2CFDBasicList << skillName->text();
        ui->S2CFDBasicComboBox->addItems(s2CFDBasicList);
        S2CFDChange();
    }

}

void S2ClanFieldDialog::S2CFDClanAdvTable(int x, int) {
    QTableWidgetItem *skillName = new QTableWidgetItem;
    QTableWidgetItem *skillAttr = new QTableWidgetItem;
    skillName = ui->S2CFDAdvTable->item(x, 0);
    skillAttr = ui->S2CFDAdvTable->item(x, 1);

    if(skillName != 0x0) {
        ui->S2CFDAdvComboBox->clear();
        for(int i = 0; i < s2CFDClanAdvSkills.count(); ++i) {
            if(s2CFDClanAdvSkills[i].first == skillName->text()) {
                s2CFDClanAdvSkills.removeAt(i);
            }
        }
        if(s2CFDClanAdvLabel != "Cavalry") {

            s2CFDAdvList << skillName->text();

        } else {
            if(skillName->text() ==  "Artillery") {
                advListPart1 << "Artillery";
            }

            if(skillName->text() == "Driving/Ground Vehicles" || skillName->text() == "Driving/Rail Vehicles") {
                advListPart2 << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles" << "Piloting/Air Vehicle";
            }

            if(skillName->text() == "Driving/Sea Vehicles" || skillName->text() == "Piloting/Air Vehicle") {
                advListPart2 << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles" << "Piloting/Air Vehicle";
            }

            if(skillName->text() == "Gunnery/Land" || skillName->text() == "Gunnery/Sea") {
                advListPart3 << "Gunnery/Land" << "Gunnery/Sea" << "Air Vehicle";
            }

            if(skillName->text() ==  "Air Vehicle") {
                advListPart3 << "Gunnery/Land" << "Gunnery/Sea" << "Air Vehicle";
            }

            if(skillName->text() ==  "Sensor Operations") {
                advListPart4 << "Sensor Operations";
            }

            if(skillName->text() == "Tactics/Land" || skillName->text() == "Tactics/Air") {
                advListPart5 << "Tactics/Land" << "Tactics/Air";
            }
            s2CFDAdvList.clear();
            s2CFDAdvList << advListPart1 << advListPart2 << advListPart3 << advListPart4 << advListPart5;
        }


        ui->S2CFDAdvComboBox->addItems(s2CFDAdvList);
        S2CFDChange();
    }

}
