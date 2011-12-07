#include "s1moredialog.h"
#include "ui_s1moredialog.h"
#include <QtGui>

S1MoreDialog::S1MoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S1MoreDialog)
{
    ui->setupUi(this);
}

S1MoreDialog::~S1MoreDialog()
{
    delete ui;
}

void S1MoreDialog::S1MoreDialogInit() {
    if(!s1MoreDialLabel1.isEmpty()) {
        ui->S1AdvDialComBox1->setEnabled(true);
        ui->S1AdvDialLabel1->setText(s1MoreDialLabel1);
        ui->S1AdvDialComBox1->addItems(s1MoreDialDrop1);

    } else {
        ui->S1AdvDialComBox1->setEnabled(false);
        s1MoreDialLabel1.clear();
        s1MoreDialDrop1.clear();
        s1Value1 = 0;
    }

    if(!s1MoreDialLabel2.isEmpty()) {
        ui->S1AdvDialComBox2->setEnabled(true);
        ui->S1AdvDialLabel2->setText(s1MoreDialLabel2);
        ui->S1AdvDialComBox2->addItems(s1MoreDialDrop2);
    } else {
        ui->S1AdvDialComBox2->setEnabled(false);
        s1MoreDialLabel2.clear();
        s1MoreDialDrop2.clear();
        s1Value2 = 0;
    }

    if(!s1MoreDialLabel3.isEmpty()) {
        ui->S1AdvDialComBox3->setEnabled(true);
        ui->S1AdvDialLabel3->setText(s1MoreDialLabel3);
        ui->S1AdvDialComBox3->addItems(s1MoreDialDrop3);
    } else {
        ui->S1AdvDialComBox3->setEnabled(false);
        s1MoreDialLabel3.clear();
        s1MoreDialDrop3.clear();
        s1Value3 = 0;
    }

    if(!s1MoreDialLabel4.isEmpty()) {
        ui->S1AdvDialComBox4->setEnabled(true);
        ui->S1AdvDialLabel4->setText(s1MoreDialLabel4);
        ui->S1AdvDialComBox4->addItems(s1MoreDialDrop4);
    } else {
        ui->S1AdvDialComBox4->setEnabled(false);
        s1MoreDialLabel4.clear();
        s1MoreDialDrop4.clear();
        s1Value4 = 0;
    }

    on_S1AdvDialComBox1_activated(ui->S1AdvDialComBox1->currentText());
    on_S1AdvDialComBox2_activated(ui->S1AdvDialComBox2->currentText());
    on_S1AdvDialComBox3_activated(ui->S1AdvDialComBox3->currentText());
    on_S1AdvDialComBox4_activated(ui->S1AdvDialComBox4->currentText());
}

void S1MoreDialog::S1PrintTable() {
    S1MoreDialClearZero();
    ui->S1AdvDialogTable->clear();

    QList<QPair<QString, int> > printList;

    printList = s1MoreDialAttr + s1MoreDialTraits + s1MoreDialSkills;

    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->S1AdvDialogTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->S1AdvDialogTable->setItem(sCount,1,newSValueItem);
    }
}

void S1MoreDialog::S1MoreDialogClear() {

    s1childName.clear();

    s1MoreDialAttr.clear();
    s1MoreDialTraits.clear();
    s1MoreDialSkills.clear();

    s1MoreDialLabel1.clear();
    s1MoreDialDrop1.clear();
    s1Value1 = 0;
    swpNameSkill1.clear();
    swpNameTrait1.clear();
    swpNameAttr1.clear();

    s1MoreDialLabel2.clear();
    s1MoreDialDrop2.clear();
    s1Value2 = 0;
    swpNameSkill2.clear();
    swpNameTrait2.clear();
    swpNameAttr2.clear();

    s1MoreDialLabel3.clear();
    s1MoreDialDrop3.clear();
    s1Value3 = 0;
    swpNameSkill3.clear();
    swpNameTrait3.clear();
    swpNameAttr3.clear();

    s1MoreDialLabel4.clear();
    s1MoreDialDrop4.clear();
    s1Value4 = 0;
    swpNameSkill4.clear();
    swpNameTrait4.clear();
    swpNameAttr4.clear();

    ui->S1AdvDialLabel1->clear();
    ui->S1AdvDialComBox1->clear();
    ui->S1AdvDialLabel2->clear();
    ui->S1AdvDialComBox2->clear();
    ui->S1AdvDialLabel3->clear();
    ui->S1AdvDialComBox3->clear();
    ui->S1AdvDialLabel4->clear();
    ui->S1AdvDialComBox4->clear();
}

void S1MoreDialog::changeSkills(QString skillName, int skillXP)
{
    if (s1MoreDialSkills.count() == 0) {
        s1MoreDialSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s1MoreDialSkills);
        if ( i != 100500 ) {
            i--;
            s1MoreDialSkills[i] = qMakePair(skillName, s1MoreDialSkills[i].second + skillXP );
        } else {
            s1MoreDialSkills.append(qMakePair(skillName, skillXP));
        }
    }
}

void S1MoreDialog::changeTraits(QString skillName, int skillXP)
{
    if (s1MoreDialTraits.count() == 0) {
        s1MoreDialTraits.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s1MoreDialTraits);
        if ( i != 100500 ) {
            i--;
            s1MoreDialTraits[i] = qMakePair(skillName, s1MoreDialTraits[i].second + skillXP );
        } else {
            s1MoreDialTraits.append(qMakePair(skillName, skillXP));
        }
    }
}

void S1MoreDialog::changeAttr(QString skillName, int skillXP)
{
    if (s1MoreDialAttr.count() == 0) {
        s1MoreDialAttr.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s1MoreDialAttr);
        if ( i != 100500 ) {
            i--;
            s1MoreDialAttr[i] = qMakePair(skillName, s1MoreDialAttr[i].second + skillXP );
        } else {
            s1MoreDialAttr.append(qMakePair(skillName, skillXP));
        }
    }
}

int S1MoreDialog::findSkill(QString fSkillName, QList<QPair<QString, int> > nameList) {
    int b=0;
    for (int i = 0; i < nameList.count(); i++) {
        b++;
        if (nameList[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void S1MoreDialog::S1MoreDialClearZero() {
    QList<QPair<QString, int> > swapSkill = s1MoreDialSkills;
    s1MoreDialSkills.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s1MoreDialSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s1MoreDialTraits;
    s1MoreDialTraits.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s1MoreDialTraits.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s1MoreDialAttr;
    s1MoreDialAttr.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s1MoreDialAttr.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }
}

void S1MoreDialog::on_S1AdvDialComBox1_activated(QString nameElem)
{
    if(ui->S1AdvDialComBox1->currentIndex() < 8) {
        if(!swpNameTrait1.isEmpty()) {
            changeTraits(swpNameTrait1,-s1Value1);
            swpNameTrait1.clear();
        }

        if(!swpNameAttr1.isEmpty()) {
            changeAttr(swpNameAttr1,-s1Value1);
            swpNameAttr1.clear();
        }

        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s1Value1);
            swpNameSkill1.clear();
        }

        changeAttr(nameElem,s1Value1);
        swpNameAttr1 = nameElem;

    }


    if(ui->S1AdvDialComBox1->currentIndex() > 7 && ui->S1AdvDialComBox1->currentIndex() < 85) {
        if(!swpNameTrait1.isEmpty()) {
            changeTraits(swpNameTrait1,-s1Value1);
            swpNameTrait1.clear();
        }

        if(!swpNameAttr1.isEmpty()) {
            changeAttr(swpNameAttr1,-s1Value1);
            swpNameAttr1.clear();
        }

        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s1Value1);
            swpNameSkill1.clear();
        }

        changeTraits(nameElem,s1Value1);
        swpNameTrait1 = nameElem;
    }

    if(ui->S1AdvDialComBox1->currentIndex() > 84) {
        if(!swpNameTrait1.isEmpty()) {
            changeTraits(swpNameTrait1,-s1Value1);
            swpNameTrait1.clear();
        }

        if(!swpNameAttr1.isEmpty()) {
            changeAttr(swpNameAttr1,-s1Value1);
            swpNameAttr1.clear();
        }

        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s1Value1);
            swpNameSkill1.clear();
        }

        changeSkills(nameElem,s1Value1);
        swpNameSkill1 = nameElem;
    }

    S1PrintTable();
}

void S1MoreDialog::on_S1AdvDialComBox2_activated(QString nameElem)
{
    if(ui->S1AdvDialComBox2->currentIndex() < 8) {
        if(!swpNameTrait2.isEmpty()) {
            changeTraits(swpNameTrait2,-s1Value2);
            swpNameTrait2.clear();
        }

        if(!swpNameAttr2.isEmpty()) {
            changeAttr(swpNameAttr2,-s1Value2);
            swpNameAttr2.clear();
        }

        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s1Value2);
            swpNameSkill2.clear();
        }

        changeAttr(nameElem,s1Value2);
        swpNameAttr2 = nameElem;

    }


    if(ui->S1AdvDialComBox2->currentIndex() > 7 && ui->S1AdvDialComBox2->currentIndex() < 85) {
        if(!swpNameTrait2.isEmpty()) {
            changeTraits(swpNameTrait2,-s1Value2);
            swpNameTrait2.clear();
        }

        if(!swpNameAttr2.isEmpty()) {
            changeAttr(swpNameAttr2,-s1Value2);
            swpNameAttr2.clear();
        }

        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s1Value2);
            swpNameSkill2.clear();
        }

        changeTraits(nameElem,s1Value2);
        swpNameTrait2 = nameElem;
    }

    if(ui->S1AdvDialComBox2->currentIndex() > 84) {
        if(!swpNameTrait2.isEmpty()) {
            changeTraits(swpNameTrait2,-s1Value2);
            swpNameTrait2.clear();
        }

        if(!swpNameAttr2.isEmpty()) {
            changeAttr(swpNameAttr2,-s1Value2);
            swpNameAttr2.clear();
        }

        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s1Value2);
            swpNameSkill2.clear();
        }

        changeSkills(nameElem,s1Value2);
        swpNameSkill2 = nameElem;
    }

    S1PrintTable();
}

void S1MoreDialog::on_S1AdvDialComBox3_activated(QString nameElem)
{
    if(ui->S1AdvDialComBox3->currentIndex() < 8) {
        if(!swpNameTrait3.isEmpty()) {
            changeTraits(swpNameTrait3,-s1Value3);
            swpNameTrait3.clear();
        }

        if(!swpNameAttr3.isEmpty()) {
            changeAttr(swpNameAttr3,-s1Value3);
            swpNameAttr3.clear();
        }

        if(!swpNameSkill3.isEmpty()) {
            changeSkills(swpNameSkill3,-s1Value3);
            swpNameSkill3.clear();
        }

        changeAttr(nameElem,s1Value3);
        swpNameAttr3 = nameElem;

    }


    if(ui->S1AdvDialComBox3->currentIndex() > 7 && ui->S1AdvDialComBox3->currentIndex() < 85) {
        if(!swpNameTrait3.isEmpty()) {
            changeTraits(swpNameTrait3,-s1Value3);
            swpNameTrait3.clear();
        }

        if(!swpNameAttr3.isEmpty()) {
            changeAttr(swpNameAttr3,-s1Value3);
            swpNameAttr3.clear();
        }

        if(!swpNameSkill3.isEmpty()) {
            changeSkills(swpNameSkill3,-s1Value3);
            swpNameSkill3.clear();
        }

        changeTraits(nameElem,s1Value3);
        swpNameTrait3 = nameElem;
    }

    if(ui->S1AdvDialComBox3->currentIndex() > 84) {
        if(!swpNameTrait3.isEmpty()) {
            changeTraits(swpNameTrait3,-s1Value3);
            swpNameTrait3.clear();
        }

        if(!swpNameAttr3.isEmpty()) {
            changeAttr(swpNameAttr3,-s1Value3);
            swpNameAttr3.clear();
        }

        if(!swpNameSkill3.isEmpty()) {
            changeSkills(swpNameSkill3,-s1Value3);
            swpNameSkill3.clear();
        }

        changeSkills(nameElem,s1Value3);
        swpNameSkill3 = nameElem;
    }

    S1PrintTable();
}

void S1MoreDialog::on_S1AdvDialComBox4_activated(QString nameElem)
{
    if(ui->S1AdvDialComBox4->currentIndex() < 8) {
        if(!swpNameTrait4.isEmpty()) {
            changeTraits(swpNameTrait4,-s1Value4);
            swpNameTrait4.clear();
        }

        if(!swpNameAttr4.isEmpty()) {
            changeAttr(swpNameAttr4,-s1Value4);
            swpNameAttr4.clear();
        }

        if(!swpNameSkill4.isEmpty()) {
            changeSkills(swpNameSkill4,-s1Value4);
            swpNameSkill4.clear();
        }

        changeAttr(nameElem,s1Value4);
        swpNameAttr4 = nameElem;

    }


    if(ui->S1AdvDialComBox4->currentIndex() > 7 && ui->S1AdvDialComBox4->currentIndex() < 85) {
        if(!swpNameTrait4.isEmpty()) {
            changeTraits(swpNameTrait4,-s1Value4);
            swpNameTrait4.clear();
        }

        if(!swpNameAttr4.isEmpty()) {
            changeAttr(swpNameAttr4,-s1Value4);
            swpNameAttr4.clear();
        }

        if(!swpNameSkill4.isEmpty()) {
            changeSkills(swpNameSkill4,-s1Value4);
            swpNameSkill4.clear();
        }

        changeTraits(nameElem,s1Value4);
        swpNameTrait4 = nameElem;
    }

    if(ui->S1AdvDialComBox4->currentIndex() > 84) {
        if(!swpNameTrait4.isEmpty()) {
            changeTraits(swpNameTrait4,-s1Value4);
            swpNameTrait4.clear();
        }

        if(!swpNameAttr4.isEmpty()) {
            changeAttr(swpNameAttr4,-s1Value4);
            swpNameAttr4.clear();
        }

        if(!swpNameSkill4.isEmpty()) {
            changeSkills(swpNameSkill4,-s1Value4);
            swpNameSkill4.clear();
        }

        changeSkills(nameElem,s1Value4);
        swpNameSkill4 = nameElem;
    }

    S1PrintTable();
}
