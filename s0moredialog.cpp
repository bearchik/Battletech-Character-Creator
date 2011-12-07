#include "s0moredialog.h"
#include "ui_s0moredialog.h"
#include <QtGui>

S0MoreDialog::S0MoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S0MoreDialog)
{
    ui->setupUi(this);

    S0MoreDialogClear();

}

S0MoreDialog::~S0MoreDialog()
{
    delete ui;
}

void S0MoreDialog::S0MoreDialogClear() {

    s0MoreDialAttr.clear();
    s0MoreDialTraits.clear();
    s0MoreDialSkills.clear();

    s0MoreDialLabel1.clear();
    s0MoreDialDrop1.clear();
    s0Value1 = 0;

    s0MoreDialLabel2.clear();
    s0MoreDialDrop2.clear();
    s0Value2 = 0;

    s0MoreDialLabel3.clear();
    s0MoreDialDrop3.clear();
    s0Value3 = 0;

    s0MoreDialLabel4.clear();
    s0MoreDialDrop4.clear();
    s0Value4 = 0;

    ui->S0AdvDialLabel1->clear();
    ui->S0AdvDialComBox1->clear();
    ui->S0AdvDialLabel2->clear();
    ui->S0AdvDialComBox2->clear();
    ui->S0AdvDialLabel3->clear();
    ui->S0AdvDialComBox3->clear();
    ui->S0AdvDialLabel4->clear();
    ui->S0AdvDialComBox4->clear();

    swpNameSkill1.clear();
    swpNameSkill2.clear();
    swpNameSkill3.clear();
    swpNameSkill4.clear();

    swpNameTrait1.clear();
    swpNameTrait2.clear();
    swpNameTrait3.clear();
    swpNameTrait4.clear();

    swpNameAttr1.clear();
    swpNameAttr2.clear();
    swpNameAttr3.clear();
    swpNameAttr4.clear();

    S0PrintTable();
}

void S0MoreDialog::S0MoreDialogInit() {

    if(!s0MoreDialLabel1.isEmpty()) {
        ui->S0AdvDialComBox1->setEnabled(true);
        ui->S0AdvDialLabel1->setText(s0MoreDialLabel1);
        ui->S0AdvDialComBox1->addItems(s0MoreDialDrop1);

    } else {
        ui->S0AdvDialComBox1->setEnabled(false);
        s0MoreDialLabel1.clear();
        s0MoreDialDrop1.clear();
        s0Value1 = 0;
    }

    if(!s0MoreDialLabel2.isEmpty()) {
        ui->S0AdvDialComBox2->setEnabled(true);
        ui->S0AdvDialLabel2->setText(s0MoreDialLabel2);
        ui->S0AdvDialComBox2->addItems(s0MoreDialDrop2);
    } else {
        ui->S0AdvDialComBox2->setEnabled(false);
        s0MoreDialLabel2.clear();
        s0MoreDialDrop2.clear();
        s0Value2 = 0;
    }

    if(!s0MoreDialLabel3.isEmpty()) {
        ui->S0AdvDialComBox3->setEnabled(true);
        ui->S0AdvDialLabel3->setText(s0MoreDialLabel3);
        ui->S0AdvDialComBox3->addItems(s0MoreDialDrop3);
    } else {
        ui->S0AdvDialComBox3->setEnabled(false);
        s0MoreDialLabel3.clear();
        s0MoreDialDrop3.clear();
        s0Value3 = 0;
    }

    if(!s0MoreDialLabel4.isEmpty()) {
        ui->S0AdvDialComBox4->setEnabled(true);
        ui->S0AdvDialLabel4->setText(s0MoreDialLabel4);
        ui->S0AdvDialComBox4->addItems(s0MoreDialDrop4);
    } else {
        ui->S0AdvDialComBox4->setEnabled(false);
        s0MoreDialLabel4.clear();
        s0MoreDialDrop4.clear();
        s0Value4 = 0;
    }

//    if(s0affName == "FREE WORLDS LEAGUE (HOUSE MARIK)" && s0subAffName == "Other FWL Worlds") {

//    QStringList box1 = checkDifferent(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(), s0MoreDialDrop1);
//    ui->S0AdvDialComBox1->clear();
//    ui->S0AdvDialComBox1->addItems(box1);

//    QStringList box2 = checkDifferent(ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox1->currentText(), s0MoreDialDrop1);
//    ui->S0AdvDialComBox2->clear();
//    ui->S0AdvDialComBox2->addItems(box2);

    ui->S0AdvDialComBox1->setCurrentIndex(0);
    ui->S0AdvDialComBox2->setCurrentIndex(1);
    ui->S0AdvDialComBox3->setCurrentIndex(2);
    ui->S0AdvDialComBox4->setCurrentIndex(3);

//    }

    on_S0AdvDialComBox1_activated(ui->S0AdvDialComBox1->currentText());
    on_S0AdvDialComBox2_activated(ui->S0AdvDialComBox2->currentText());
    on_S0AdvDialComBox3_activated(ui->S0AdvDialComBox3->currentText());
    on_S0AdvDialComBox4_activated(ui->S0AdvDialComBox4->currentText());
}


void S0MoreDialog::S0PrintTable() {
    S0MoreDialClearZero();
    ui->S0AdvDialogTable->clear();

    QList<QPair<QString, int> > printList;

    printList = s0MoreDialAttr + s0MoreDialTraits + s0MoreDialSkills;

    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->S0AdvDialogTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->S0AdvDialogTable->setItem(sCount,1,newSValueItem);
    }

}

void S0MoreDialog::changeSkills(QString skillName, int skillXP)
{
    if (s0MoreDialSkills.count() == 0) {
        s0MoreDialSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s0MoreDialSkills);
        if ( i != 100500 ) {
            i--;
            s0MoreDialSkills[i] = qMakePair(skillName, s0MoreDialSkills[i].second + skillXP );
        } else {
            s0MoreDialSkills.append(qMakePair(skillName, skillXP));
        }
    }
}

void S0MoreDialog::changeTraits(QString skillName, int skillXP)
{
    if (s0MoreDialTraits.count() == 0) {
        s0MoreDialTraits.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s0MoreDialTraits);
        if ( i != 100500 ) {
            i--;
            s0MoreDialTraits[i] = qMakePair(skillName, s0MoreDialTraits[i].second + skillXP );
        } else {
            s0MoreDialTraits.append(qMakePair(skillName, skillXP));
        }
    }
}

void S0MoreDialog::changeAttr(QString skillName, int skillXP)
{
    if (s0MoreDialAttr.count() == 0) {
        s0MoreDialAttr.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s0MoreDialAttr);
        if ( i != 100500 ) {
            i--;
            s0MoreDialAttr[i] = qMakePair(skillName, s0MoreDialAttr[i].second + skillXP );
        } else {
            s0MoreDialAttr.append(qMakePair(skillName, skillXP));
        }
    }
}

int S0MoreDialog::findSkill(QString fSkillName, QList<QPair<QString, int> > nameList) {
    int b=0;
    for (int i = 0; i < nameList.count(); i++) {
        b++;
        if (nameList[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void S0MoreDialog::S0MoreDialClearZero() {
    QList<QPair<QString, int> > swapSkill = s0MoreDialSkills;
    s0MoreDialSkills.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s0MoreDialSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s0MoreDialTraits;
    s0MoreDialTraits.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s0MoreDialTraits.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s0MoreDialAttr;
    s0MoreDialAttr.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s0MoreDialAttr.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }
}

// s0MoreDialDrop1

QStringList S0MoreDialog::checkDifferent(QString elemLeft, QString elemRight, QStringList etalList) {

    QStringList swpList;
    swpList.clear();

    if(elemLeft == elemRight) {
        for(int i = 0; i < etalList.count(); i++) {
            if(etalList[i] != elemRight) {
               swpList << etalList[i];
            }
        }
    } else {
        swpList = etalList;
    }


    return swpList;
}

void S0MoreDialog::on_S0AdvDialComBox1_activated(QString nameElem)
{

    if(s0affName == "INVADING CLAN" || s0affName == "HOMEWORLD CLAN") {
        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s0Value1);
        }
        changeSkills(nameElem,s0Value1);
        swpNameSkill1 = nameElem;
    }

    if(s0affName == "INDEPENDENT") {

        if(s0Value1 != 0 ) {
            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
            }
            changeSkills(nameElem,s0Value1);
            swpNameSkill1 = nameElem;

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            QString nowElem = ui->S0AdvDialComBox2->currentText();
            ui->S0AdvDialComBox2->clear();
            ui->S0AdvDialComBox2->addItems(listBox);
            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox4->currentText());
            nowElem = ui->S0AdvDialComBox3->currentText();
            ui->S0AdvDialComBox3->clear();
            ui->S0AdvDialComBox3->addItems(listBox);
            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText());
            nowElem = ui->S0AdvDialComBox4->currentText();
            ui->S0AdvDialComBox4->clear();
            ui->S0AdvDialComBox4->addItems(listBox);
            ui->S0AdvDialComBox4->setCurrentIndex(ui->S0AdvDialComBox4->findText(nowElem));

        }



//        if(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox1->currentText(), ui->S0AdvDialComBox2->itemText(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox2->currentText();
//            ui->S0AdvDialComBox2->clear();
//            ui->S0AdvDialComBox2->addItems(boxList);
//            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox1->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox1->currentText(), ui->S0AdvDialComBox3->itemText(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox1->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox3->currentText();
//            ui->S0AdvDialComBox3->clear();
//            ui->S0AdvDialComBox3->addItems(boxList);
//            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox4->findText(ui->S0AdvDialComBox1->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox1->currentText(), ui->S0AdvDialComBox4->itemText(ui->S0AdvDialComBox4->findText(ui->S0AdvDialComBox1->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox4->currentText();
//            ui->S0AdvDialComBox4->clear();
//            ui->S0AdvDialComBox4->addItems(boxList);
//            ui->S0AdvDialComBox4->setCurrentIndex(ui->S0AdvDialComBox4->findText(nowElem));
//        }
    }

    if(s0affName == "DEEP PERIPHERY") {
        if(ui->S0AdvDialComBox1->currentIndex() < 8) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeAttr(nameElem,s0Value1);
            swpNameAttr1 = nameElem;

        }


        if(ui->S0AdvDialComBox1->currentIndex() > 7 && ui->S0AdvDialComBox1->currentIndex() < 65) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeTraits(nameElem,s0Value1);
            swpNameTrait1 = nameElem;
        }

        if(ui->S0AdvDialComBox1->currentIndex() > 64) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeSkills(nameElem,s0Value1);
            swpNameSkill1 = nameElem;
        }


    }

    if(s0affName == "MAJOR PERIPHERY STATE") {
        if(ui->S0AdvDialComBox1->currentIndex() < 8) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeAttr(nameElem,s0Value1);
            swpNameAttr1 = nameElem;

        }

        if(ui->S0AdvDialComBox1->currentIndex() > 7 && ui->S0AdvDialComBox1->currentIndex() < 65) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeTraits(nameElem,s0Value1);
            swpNameTrait1 = nameElem;
        }

        if(ui->S0AdvDialComBox1->currentIndex() > 64) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }

            if(!swpNameSkill1.isEmpty()) {
                changeSkills(swpNameSkill1,-s0Value1);
                swpNameSkill1.clear();
            }

            changeSkills(nameElem,s0Value1);
            swpNameSkill1 = nameElem;
        }


    }

    if(s0affName == "MINOR PERIPHERY") {
        if(ui->S0AdvDialComBox1->currentIndex() < 8) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }


            changeAttr(nameElem,s0Value1);
            swpNameAttr1 = nameElem;

        }

        if(ui->S0AdvDialComBox1->currentIndex() > 7) {
            if(!swpNameTrait1.isEmpty()) {
                changeTraits(swpNameTrait1,-s0Value1);
                swpNameTrait1.clear();
            }

            if(!swpNameAttr1.isEmpty()) {
                changeAttr(swpNameAttr1,-s0Value1);
                swpNameAttr1.clear();
            }


            changeTraits(nameElem,s0Value1);
            swpNameTrait1 = nameElem;
        }
    }


    if(s0affName == "FREE WORLDS LEAGUE (HOUSE MARIK)" && s0subAffName == "Other FWL Worlds") {

        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s0Value1);
        }
        changeSkills(nameElem,s0Value1);
        swpNameSkill1 = nameElem;

        if(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText()) != -1) {
            QStringList boxList = checkDifferent(ui->S0AdvDialComBox1->currentText(), ui->S0AdvDialComBox2->itemText(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText())), s0MoreDialDrop1);
            QString nowElem = ui->S0AdvDialComBox2->currentText();
            ui->S0AdvDialComBox2->clear();
            ui->S0AdvDialComBox2->addItems(boxList);
            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));
        }

    }

    if(s0affName == "TERRAN" || s0subAffName == "Belter") {

        if(!swpNameSkill1.isEmpty()) {
            changeSkills(swpNameSkill1,-s0Value1);
        }
        changeSkills(nameElem,s0Value1);
        swpNameSkill1 = nameElem;


        if(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText()) != -1) {
            QStringList boxList = checkDifferent(ui->S0AdvDialComBox1->currentText(), ui->S0AdvDialComBox2->itemText(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox1->currentText())), s0MoreDialDrop1);
            QString nowElem = ui->S0AdvDialComBox2->currentText();
            ui->S0AdvDialComBox2->clear();
            ui->S0AdvDialComBox2->addItems(boxList);
            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));
        }

    }

    S0PrintTable();

}

void S0MoreDialog::on_S0AdvDialComBox2_activated(QString nameElem)
{

    if(s0affName == "INVADING CLAN" || s0affName == "HOMEWORLD CLAN") {
        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s0Value2);
        }
        changeSkills(nameElem,s0Value2);
        swpNameSkill2 = nameElem;
    }

    if(s0affName == "INDEPENDENT") {

        if(s0Value2 != 0 ) {
            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
            }
            changeSkills(nameElem,s0Value2);
            swpNameSkill2 = nameElem;

            checkListsBox(ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            QString nowElem = ui->S0AdvDialComBox1->currentText();
            ui->S0AdvDialComBox1->clear();
            ui->S0AdvDialComBox1->addItems(listBox);
            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));


            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox4->currentText());
            nowElem = ui->S0AdvDialComBox3->currentText();
            ui->S0AdvDialComBox3->clear();
            ui->S0AdvDialComBox3->addItems(listBox);
            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText());
            nowElem = ui->S0AdvDialComBox4->currentText();
            ui->S0AdvDialComBox4->clear();
            ui->S0AdvDialComBox4->addItems(listBox);
            ui->S0AdvDialComBox4->setCurrentIndex(ui->S0AdvDialComBox4->findText(nowElem));
        }


//        if(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox2->currentText(), ui->S0AdvDialComBox1->itemText(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox1->currentText();
//            ui->S0AdvDialComBox1->clear();
//            ui->S0AdvDialComBox1->addItems(boxList);
//            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox2->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox2->currentText(), ui->S0AdvDialComBox3->itemText(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox2->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox3->currentText();
//            ui->S0AdvDialComBox3->clear();
//            ui->S0AdvDialComBox3->addItems(boxList);
//            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox4->findText(ui->S0AdvDialComBox2->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox2->currentText(), ui->S0AdvDialComBox4->itemText(ui->S0AdvDialComBox4->findText(ui->S0AdvDialComBox2->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox4->currentText();
//            ui->S0AdvDialComBox4->clear();
//            ui->S0AdvDialComBox4->addItems(boxList);
//            ui->S0AdvDialComBox4->setCurrentIndex(ui->S0AdvDialComBox4->findText(nowElem));
//        }
    }

    if(s0affName == "DEEP PERIPHERY") {

        if(ui->S0AdvDialComBox2->currentIndex() < 8) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeAttr(nameElem,s0Value2);
            swpNameAttr2 = nameElem;

        }

        if(ui->S0AdvDialComBox2->currentIndex() > 7 && ui->S0AdvDialComBox2->currentIndex() < 65) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeTraits(nameElem,s0Value2);
            swpNameTrait2 = nameElem;
        }

        if(ui->S0AdvDialComBox2->currentIndex() > 64) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeSkills(nameElem,s0Value2);
            swpNameSkill2 = nameElem;
        }

    }

    if(s0affName == "MAJOR PERIPHERY STATE") {

        if(ui->S0AdvDialComBox2->currentIndex() < 8) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeAttr(nameElem,s0Value2);
            swpNameAttr2 = nameElem;

        }

        if(ui->S0AdvDialComBox2->currentIndex() > 7 && ui->S0AdvDialComBox2->currentIndex() < 65) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeTraits(nameElem,s0Value2);
            swpNameTrait2 = nameElem;
        }

        if(ui->S0AdvDialComBox2->currentIndex() > 64) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            if(!swpNameSkill2.isEmpty()) {
                changeSkills(swpNameSkill2,-s0Value2);
                swpNameSkill2.clear();
            }

            changeSkills(nameElem,s0Value2);
            swpNameSkill2 = nameElem;
        }

    }

    if(s0affName == "MINOR PERIPHERY") {
        if(ui->S0AdvDialComBox2->currentIndex() < 8) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            changeAttr(nameElem,s0Value2);
            swpNameAttr2 = nameElem;

        }

        if(ui->S0AdvDialComBox2->currentIndex() > 7) {
            if(!swpNameTrait2.isEmpty()) {
                changeTraits(swpNameTrait2,-s0Value2);
                swpNameTrait2.clear();
            }

            if(!swpNameAttr2.isEmpty()) {
                changeAttr(swpNameAttr2,-s0Value2);
                swpNameAttr2.clear();
            }

            changeTraits(nameElem,s0Value2);
            swpNameTrait2 = nameElem;
        }
    }



    if(s0affName == "FREE WORLDS LEAGUE (HOUSE MARIK)" && s0subAffName == "Other FWL Worlds") {

        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s0Value2);
        }
        changeSkills(nameElem,s0Value2);
        swpNameSkill2 = nameElem;

        if(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText()) != -1) {
            QStringList boxList = checkDifferent(ui->S0AdvDialComBox2->currentText(), ui->S0AdvDialComBox1->itemText(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText())), s0MoreDialDrop1);
            QString nowElem = ui->S0AdvDialComBox1->currentText();
            ui->S0AdvDialComBox1->clear();
            ui->S0AdvDialComBox1->addItems(boxList);
            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));
        }
    }

    if(s0affName == "TERRAN" && s0subAffName == "Belter") {

        if(!swpNameSkill2.isEmpty()) {
            changeSkills(swpNameSkill2,-s0Value2);
        }
        changeSkills(nameElem,s0Value2);
        swpNameSkill2 = nameElem;

        if(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText()) != -1) {
            QStringList boxList = checkDifferent(ui->S0AdvDialComBox2->currentText(), ui->S0AdvDialComBox1->itemText(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox2->currentText())), s0MoreDialDrop1);
            QString nowElem = ui->S0AdvDialComBox1->currentText();
            ui->S0AdvDialComBox1->clear();
            ui->S0AdvDialComBox1->addItems(boxList);
            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));
        }
    }

    S0PrintTable();

}

void S0MoreDialog::on_S0AdvDialComBox3_activated(QString nameElem)
{
    if(s0affName == "INDEPENDENT") {

        if(s0Value3 != 0 ) {
            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
            }
            changeSkills(nameElem,s0Value3);
            swpNameSkill3 = nameElem;

            checkListsBox(ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            QString nowElem = ui->S0AdvDialComBox1->currentText();
            ui->S0AdvDialComBox1->clear();
            ui->S0AdvDialComBox1->addItems(listBox);
            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            nowElem = ui->S0AdvDialComBox2->currentText();
            ui->S0AdvDialComBox2->clear();
            ui->S0AdvDialComBox2->addItems(listBox);
            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText());
            nowElem = ui->S0AdvDialComBox4->currentText();
            ui->S0AdvDialComBox4->clear();
            ui->S0AdvDialComBox4->addItems(listBox);
            ui->S0AdvDialComBox4->setCurrentIndex(ui->S0AdvDialComBox4->findText(nowElem));
        }

    }

    if(s0affName == "DEEP PERIPHERY") {
        if(ui->S0AdvDialComBox3->currentIndex() < 8) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeAttr(nameElem,s0Value3);
            swpNameAttr3 = nameElem;

        }

        if(ui->S0AdvDialComBox3->currentIndex() > 7 && ui->S0AdvDialComBox3->currentIndex() < 65) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeTraits(nameElem,s0Value3);
            swpNameTrait3 = nameElem;
        }

        if(ui->S0AdvDialComBox3->currentIndex() > 64) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeSkills(nameElem,s0Value3);
            swpNameSkill3 = nameElem;
        }


    }

    if(s0affName == "MAJOR PERIPHERY STATE") {
        if(ui->S0AdvDialComBox3->currentIndex() < 8) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeAttr(nameElem,s0Value3);
            swpNameAttr3 = nameElem;

        }

        if(ui->S0AdvDialComBox3->currentIndex() > 7 && ui->S0AdvDialComBox3->currentIndex() < 65) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeTraits(nameElem,s0Value3);
            swpNameTrait3 = nameElem;
        }

        if(ui->S0AdvDialComBox3->currentIndex() > 64) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            if(!swpNameSkill3.isEmpty()) {
                changeSkills(swpNameSkill3,-s0Value3);
                swpNameSkill3.clear();
            }

            changeSkills(nameElem,s0Value3);
            swpNameSkill3 = nameElem;
        }


    }

    if(s0affName == "MINOR PERIPHERY") {
        if(ui->S0AdvDialComBox3->currentIndex() < 8) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            changeAttr(nameElem,s0Value3);
            swpNameAttr3 = nameElem;

        }

        if(ui->S0AdvDialComBox3->currentIndex() > 7) {
            if(!swpNameTrait3.isEmpty()) {
                changeTraits(swpNameTrait3,-s0Value3);
                swpNameTrait3.clear();
            }

            if(!swpNameAttr3.isEmpty()) {
                changeAttr(swpNameAttr3,-s0Value3);
                swpNameAttr3.clear();
            }

            changeTraits(nameElem,s0Value3);
            swpNameTrait3 = nameElem;
        }
    }
//    if(!swpNameSkill3.isEmpty()) {
//        changeSkills(swpNameSkill3,-s0Value3);
//    }
//    changeSkills(nameElem,s0Value3);
//    swpNameSkill3 = nameElem;

    S0PrintTable();
}

void S0MoreDialog::on_S0AdvDialComBox4_activated(QString nameElem)
{
    if(s0affName == "INDEPENDENT") {

        if(s0Value4 != 0 ) {
            if(!swpNameSkill4.isEmpty()) {
                changeSkills(swpNameSkill4,-s0Value4);
            }

            changeSkills(nameElem,s0Value4);
            swpNameSkill4 = nameElem;

            checkListsBox(ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            QString nowElem = ui->S0AdvDialComBox1->currentText();
            ui->S0AdvDialComBox1->clear();
            ui->S0AdvDialComBox1->addItems(listBox);
            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox3->currentText(),ui->S0AdvDialComBox4->currentText());
            nowElem = ui->S0AdvDialComBox2->currentText();
            ui->S0AdvDialComBox2->clear();
            ui->S0AdvDialComBox2->addItems(listBox);
            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));

            checkListsBox(ui->S0AdvDialComBox1->currentText(),ui->S0AdvDialComBox2->currentText(),ui->S0AdvDialComBox4->currentText());
            nowElem = ui->S0AdvDialComBox3->currentText();
            ui->S0AdvDialComBox3->clear();
            ui->S0AdvDialComBox3->addItems(listBox);
            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));
        }



//        if(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox4->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox4->currentText(), ui->S0AdvDialComBox1->itemText(ui->S0AdvDialComBox1->findText(ui->S0AdvDialComBox4->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox1->currentText();
//            ui->S0AdvDialComBox1->clear();
//            ui->S0AdvDialComBox1->addItems(boxList);
//            ui->S0AdvDialComBox1->setCurrentIndex(ui->S0AdvDialComBox1->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox4->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox4->currentText(), ui->S0AdvDialComBox3->itemText(ui->S0AdvDialComBox3->findText(ui->S0AdvDialComBox4->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox3->currentText();
//            ui->S0AdvDialComBox3->clear();
//            ui->S0AdvDialComBox3->addItems(boxList);
//            ui->S0AdvDialComBox3->setCurrentIndex(ui->S0AdvDialComBox3->findText(nowElem));
//        }

//        if(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox4->currentText()) != -1) {
//            QStringList boxList = checkDifferent(ui->S0AdvDialComBox4->currentText(), ui->S0AdvDialComBox2->itemText(ui->S0AdvDialComBox2->findText(ui->S0AdvDialComBox4->currentText())), s0MoreDialDrop1);
//            QString nowElem = ui->S0AdvDialComBox2->currentText();
//            ui->S0AdvDialComBox2->clear();
//            ui->S0AdvDialComBox2->addItems(boxList);
//            ui->S0AdvDialComBox2->setCurrentIndex(ui->S0AdvDialComBox2->findText(nowElem));
//        }
    }

    if(s0affName == "FREE WORLDS LEAGUE (HOUSE MARIK)" && s0subAffName == "Other FWL Worlds") {
        if(ui->S0AdvDialComBox4->currentIndex() < 8) {
            if(!swpNameSkill4.isEmpty()) {
                changeSkills(swpNameSkill4,-s0Value4);
                swpNameSkill4.clear();
            }

            if(!swpNameTrait4.isEmpty()) {
                changeTraits(swpNameTrait4,-s0Value4);
                swpNameTrait4.clear();
            }

            if(!swpNameAttr4.isEmpty()) {
                changeAttr(swpNameAttr4,-s0Value4);
                swpNameAttr4.clear();
            }

            changeAttr(nameElem,s0Value4);
            swpNameAttr4 = nameElem;

        }

        if(ui->S0AdvDialComBox4->currentIndex() > 7 && ui->S0AdvDialComBox4->currentIndex() <= 63) {
            if(!swpNameSkill4.isEmpty()) {
                changeSkills(swpNameSkill4,-s0Value4);
                swpNameSkill4.clear();
            }

            if(!swpNameTrait4.isEmpty()) {
                changeTraits(swpNameTrait4,-s0Value4);
                swpNameTrait4.clear();
            }

            if(!swpNameAttr4.isEmpty()) {
                changeAttr(swpNameAttr4,-s0Value4);
                swpNameAttr4.clear();
            }

            changeTraits(nameElem,s0Value4);
            swpNameTrait4 = nameElem;
        }

        if(ui->S0AdvDialComBox4->currentIndex() > 63) {
            if(!swpNameSkill4.isEmpty()) {
                changeSkills(swpNameSkill4,-s0Value4);
                swpNameSkill4.clear();
            }

            if(!swpNameTrait4.isEmpty()) {
                changeTraits(swpNameTrait4,-s0Value4);
                swpNameTrait4.clear();
            }

            if(!swpNameAttr4.isEmpty()) {
                changeAttr(swpNameAttr4,-s0Value4);
                swpNameAttr4.clear();
            }

            changeSkills(nameElem,s0Value4);
            swpNameSkill4 = nameElem;
        }
    }



    S0PrintTable();
}

void S0MoreDialog::checkListsBox(QString nameElem1, QString nameElem2, QString nameElem3) {

    listBox = s0MoreDialDrop1;
    int countRemove;

    if (!nameElem1.isEmpty()) {
        for(int i =0; i < listBox.count(); i++) {
            if(listBox[i] == nameElem1 ) {
                countRemove = i;
            }
        }

        listBox.removeAt(countRemove);
    }

    if (!nameElem2.isEmpty()) {
        for(int i =0; i < listBox.count(); i++) {
            if(listBox[i] == nameElem2 ) {
                countRemove = i;
            }
        }

        listBox.removeAt(countRemove);
    }

    if (!nameElem3.isEmpty()) {
        for(int i =0; i < listBox.count(); i++) {
            if(listBox[i] == nameElem3 ) {
                countRemove = i;
            }
        }

        listBox.removeAt(countRemove);
    }
}
