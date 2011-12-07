#include "s2advdialog.h"
#include "ui_s2advdialog.h"
#include <QtGui>

S2AdvDialog::S2AdvDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S2AdvDialog)
{
    ui->setupUi(this);

    s2AdvDialogAttr1.clear();
    s2AdvDialogLabel1.clear();
    s2AdvDialogSkills1 = 0;
    s2AdvDialogTraits1 = 0;


    s2AdvDialogAttr2.clear();
    s2AdvDialogLabel2.clear();
    s2AdvDialogSkills2 = 0;
    s2AdvDialogTraits2 = 0;

    s2AdvDialogAttr3.clear();
    s2AdvDialogLabel3.clear();
    s2AdvDialogSkills3 = 0;
    s2AdvDialogTraits3 = 0;
    S2AdvDialConnectEvent();

    s2AdvDialogAttr4.clear();
    s2AdvDialogLabel4.clear();
    s2AdvDialogSkills4 = 0;
    s2AdvDialogTraits4 = 0;

    s2AdvDialSkillsSwp1.clear();
    s2AdvDialTraitsSwp1.clear();

    s2AdvDialSkillsSwp2.clear();
    s2AdvDialTraitsSwp2.clear();

    s2AdvDialSkillsSwp3.clear();
    s2AdvDialTraitsSwp3.clear();

    s2AdvDialSkillsSwp4.clear();
    s2AdvDialTraitsSwp4.clear();

    ui->S2AdvDialComBox1->clear();
    ui->S2AdvDialComBox2->clear();
    ui->S2AdvDialComBox3->clear();
    ui->S2AdvDialComBox4->clear();

}

S2AdvDialog::~S2AdvDialog()
{
    delete ui;
}

void S2AdvDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void S2AdvDialog::S2AdvDialClearAll() {
    s2AdvDialSkills.clear();
    s2AdvDialogAttr1.clear();
    s2AdvDialogLabel1.clear();
    s2AdvDialogSkills1 = 0;
    s2AdvDialogTraits1 = 0;


    s2AdvDialogAttr2.clear();
    s2AdvDialogLabel2.clear();
    s2AdvDialogSkills2 = 0;
    s2AdvDialogTraits2 = 0;

    s2AdvDialogAttr3.clear();
    s2AdvDialogLabel3.clear();
    s2AdvDialogSkills3 = 0;
    s2AdvDialogTraits3 = 0;

    s2AdvDialogAttr4.clear();
    s2AdvDialogLabel4.clear();
    s2AdvDialogSkills4 = 0;
    s2AdvDialogTraits4 = 0;

    s2AdvDialSkillsSwp1.clear();
    s2AdvDialTraitsSwp1.clear();

    s2AdvDialSkillsSwp2.clear();
    s2AdvDialTraitsSwp2.clear();

    s2AdvDialSkillsSwp3.clear();
    s2AdvDialTraitsSwp3.clear();

    s2AdvDialSkillsSwp4.clear();
    s2AdvDialTraitsSwp4.clear();

    ui->S2AdvDialComBox1->clear();
    ui->S2AdvDialComBox2->clear();
    ui->S2AdvDialComBox3->clear();
    ui->S2AdvDialComBox4->clear();

}

void S2AdvDialog::S2AdvDialInit() {

    if (s2AdvDialogSkills1 != 0 || s2AdvDialogTraits1 != 0) {
        ui->S2AdvDialComBox1->addItems(s2AdvDialogAttr1);
        ui->S2AdvDialLabel1->setText(s2AdvDialogLabel1);
        ui->S2AdvDialComBox1->setEnabled(true);
    } else {
        ui->S2AdvDialComBox1->clear();
        ui->S2AdvDialLabel1->clear();
        ui->S2AdvDialComBox1->setEnabled(false);
    }

    if (s2AdvDialogSkills2 != 0 || s2AdvDialogTraits2 != 0) {
        ui->S2AdvDialComBox2->addItems(s2AdvDialogAttr2);
        ui->S2AdvDialLabel2->setText(s2AdvDialogLabel2);
        ui->S2AdvDialComBox2->setEnabled(true);
    } else {
        ui->S2AdvDialComBox2->clear();
        ui->S2AdvDialLabel2->clear();
        ui->S2AdvDialComBox2->setEnabled(false);
    }

    if (s2AdvDialogSkills3 != 0 || s2AdvDialogTraits3 != 0) {
        ui->S2AdvDialComBox3->addItems(s2AdvDialogAttr3);
        ui->S2AdvDialLabel3->setText(s2AdvDialogLabel3);
        ui->S2AdvDialComBox3->setEnabled(true);
    } else {
        ui->S2AdvDialComBox3->clear();
        ui->S2AdvDialLabel3->clear();
        ui->S2AdvDialComBox3->setEnabled(false);
    }

    if (s2AdvDialogSkills4 != 0 || s2AdvDialogTraits4 != 0) {
        ui->S2AdvDialComBox4->addItems(s2AdvDialogAttr4);
        ui->S2AdvDialLabel4->setText(s2AdvDialogLabel4);
        ui->S2AdvDialComBox4->setEnabled(true);
    } else {
        ui->S2AdvDialComBox4->clear();
        ui->S2AdvDialLabel4->clear();
        ui->S2AdvDialComBox4->setEnabled(false);
    }

    S2AdvDialElem1(ui->S2AdvDialComBox1->currentText());
    S2AdvDialElem2(ui->S2AdvDialComBox2->currentText());
    S2AdvDialElem3(ui->S2AdvDialComBox3->currentText());
    S2AdvDialElem4(ui->S2AdvDialComBox4->currentText());

}

void S2AdvDialog::S2AdvDialClearZeroSkills() {
    QList<QPair<QString, int> > swapSkill = s2AdvDialSkills;
    int countSkill = s2AdvDialSkills.count();
    s2AdvDialSkills.clear();
    for (int i = 0; i < countSkill; i++) {
        if (swapSkill[i].second != 0) {
            s2AdvDialSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }
}

void S2AdvDialog::changeSkills(QString skillName, int skillXP)
{
    if (s2AdvDialSkills.count() == 0) {
        s2AdvDialSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName);
        if ( i != 100500 ) {
            i--;
            s2AdvDialSkills[i] = qMakePair(skillName, s2AdvDialSkills[i].second + skillXP );
        } else {
            s2AdvDialSkills.append(qMakePair(skillName, skillXP));
        }
    }
}

void S2AdvDialog::changeOther(QString skillName, int skillXP)
{
    s2AdvDialOther.clear();
    if(skillXP != 0 ) {
        s2AdvDialOther.append(qMakePair(skillName, skillXP));
    }
}

//ищем соответсвие скила
int S2AdvDialog::findSkill(QString fSkillName) {
    int b=0;
    for (int i = 0; i < s2AdvDialSkills.count(); i++) {
        b++;
        if (s2AdvDialSkills[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void S2AdvDialog::S2AdvDialConnectEvent() {
    connect(ui->S2AdvDialComBox1, SIGNAL(activated(QString)), this, SLOT(S2AdvDialElem1(QString)));
    connect(ui->S2AdvDialComBox2, SIGNAL(activated(QString)), this, SLOT(S2AdvDialElem2(QString)));
    connect(ui->S2AdvDialComBox3, SIGNAL(activated(QString)), this, SLOT(S2AdvDialElem3(QString)));
    connect(ui->S2AdvDialComBox4, SIGNAL(activated(QString)), this, SLOT(S2AdvDialElem4(QString)));
}

void S2AdvDialog::S2AdvDialElem1(QString nameElem) {
    if (s2AdvDialSkillsSwp1.isEmpty() != true) {
        changeSkills(s2AdvDialSkillsSwp1, -s2AdvDialogSkills1);
    }
    changeSkills(nameElem, s2AdvDialogSkills1);
    s2AdvDialSkillsSwp1 = nameElem;

    S2AdvDialClearZeroSkills();
    S2AdvDialPrintTable();
}

void S2AdvDialog::S2AdvDialElem2(QString nameElem) {
    if (s2AdvDialSkillsSwp2.isEmpty() != true) {
        changeSkills(s2AdvDialSkillsSwp2, -s2AdvDialogSkills2);
    }
    changeSkills(nameElem, s2AdvDialogSkills2);
    s2AdvDialSkillsSwp2 = nameElem;

    S2AdvDialClearZeroSkills();
    S2AdvDialPrintTable();
}

void S2AdvDialog::S2AdvDialElem3(QString nameElem) {
    if (s2AdvDialSkillsSwp3.isEmpty() != true) {
        changeSkills(s2AdvDialSkillsSwp3, -s2AdvDialogSkills3);
    }
    changeSkills(nameElem, s2AdvDialogSkills3);
    s2AdvDialSkillsSwp3 = nameElem;

    S2AdvDialClearZeroSkills();
    S2AdvDialPrintTable();
}

void S2AdvDialog::S2AdvDialElem4(QString nameElem) {

    changeOther(nameElem,s2AdvDialogSkills4);
    S2AdvDialClearZeroSkills();
    S2AdvDialPrintTable();
}

void S2AdvDialog::S2AdvDialPrintTable() {
    ui->S2AdvDialogTable->clear();

    QList<QPair<QString, int> > printList;
    if(s2AdvDialOther.isEmpty() != true ){
        printList = s2AdvDialSkills + s2AdvDialOther;
    } else {
        printList = s2AdvDialSkills;
    }


    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->S2AdvDialogTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->S2AdvDialogTable->setItem(sCount,1,newSValueItem);
    }

}
