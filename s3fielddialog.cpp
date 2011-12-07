#include "s3fielddialog.h"
#include "ui_s3fielddialog.h"
#include <QtGui>

S3FieldDialog::S3FieldDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S3FieldDialog)
{
    ui->setupUi(this);

    S3FieldDialConnectEvent();
    carField = new CarierFields;
}

S3FieldDialog::~S3FieldDialog()
{
    delete ui;
}

void S3FieldDialog::S3FieldDialConnectEvent(){
    connect(ui->S3FieldDialComBox1, SIGNAL(activated(QString)), this, SLOT(S3FieldDialElem1(QString)));
    connect(ui->S3FieldDialComBox2, SIGNAL(activated(QString)), this, SLOT(S3FieldDialElem2(QString)));
    connect(ui->S3FieldDialComBox3, SIGNAL(activated(QString)), this, SLOT(S3FieldDialElem3(QString)));
    connect(ui->S3FieldDialComBox4, SIGNAL(activated(QString)), this, SLOT(S3FieldDialElem4(QString)));
}

void S3FieldDialog::S3FieldDialRezet() {
    ui->S3FieldDialComBox1->setEnabled(false);
    ui->S3FieldDialComBox2->setEnabled(false);
    ui->S3FieldDialComBox3->setEnabled(false);
    ui->S3FieldDialComBox4->setEnabled(false);

    ui->S3FieldDialComBox1->clear();
    ui->S3FieldDialComBox2->clear();
    ui->S3FieldDialComBox3->clear();
    ui->S3FieldDialComBox4->clear();

    ui->S3FieldDialLabel1->clear();
    ui->S3FieldDialLabel2->clear();
    ui->S3FieldDialLabel3->clear();
    ui->S3FieldDialLabel4->clear();

    s3FieldDialSkillsSwp1.clear();
    s3FieldDialSkillsSwp2.clear();
    s3FieldDialSkillsSwp3.clear();
    s3FieldDialSkillsSwp4.clear();
    s3FieldDialSkills.clear();
}

void S3FieldDialog::S3FieldDialElem1(QString nameElem) {
    if (s3FieldDialSkillsSwp1.isEmpty() != true) {
        S3FieldDialChangeSkills(s3FieldDialSkillsSwp1, -30);
    }
    S3FieldDialChangeSkills(nameElem, 30);
    s3FieldDialSkillsSwp1 = nameElem;

    S3FieldDialClearZeroSkills();
    S3FieldDialPrintTable();
}

void S3FieldDialog::S3FieldDialElem2(QString nameElem) {
    if (s3FieldDialSkillsSwp2.isEmpty() != true) {
        S3FieldDialChangeSkills(s3FieldDialSkillsSwp2, -30);
    }
    S3FieldDialChangeSkills(nameElem, 30);
    s3FieldDialSkillsSwp2 = nameElem;

    S3FieldDialClearZeroSkills();
    S3FieldDialPrintTable();
}

void S3FieldDialog::S3FieldDialElem3(QString nameElem) {
    if (s3FieldDialSkillsSwp3.isEmpty() != true) {
        S3FieldDialChangeSkills(s3FieldDialSkillsSwp3, -30);
    }
    S3FieldDialChangeSkills(nameElem, 30);
    s3FieldDialSkillsSwp3 = nameElem;

    S3FieldDialClearZeroSkills();
    S3FieldDialPrintTable();
}

void S3FieldDialog::S3FieldDialElem4(QString nameElem) {
    if (s3FieldDialSkillsSwp4.isEmpty() != true) {
        S3FieldDialChangeSkills(s3FieldDialSkillsSwp4, -30);
    }
    S3FieldDialChangeSkills(nameElem, 30);
    s3FieldDialSkillsSwp4 = nameElem;

    S3FieldDialClearZeroSkills();
    S3FieldDialPrintTable();
}

void S3FieldDialog::S3FieldDialClearZeroSkills() {
    QList<QPair<QString, int> > swapSkill = s3FieldDialSkills;
    int countSkill = s3FieldDialSkills.count();
    s3FieldDialSkills.clear();
    for (int i = 0; i < countSkill; i++) {
        if (swapSkill[i].second != 0) {
            s3FieldDialSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }
}

void S3FieldDialog::S3FieldDialChangeSkills(QString skillName, int skillXP)
{
    if (s3FieldDialSkills.count() == 0) {
        s3FieldDialSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = S3FieldDialFindSkill(skillName);
        if ( i != 100500 ) {
            i--;
            s3FieldDialSkills[i] = qMakePair(skillName, s3FieldDialSkills[i].second + skillXP );
        } else {
            s3FieldDialSkills.append(qMakePair(skillName, skillXP));
        }
    }
}

//ищем соответсвие скила
int S3FieldDialog::S3FieldDialFindSkill(QString fSkillName) {
    int b=0;
    for (int i = 0; i < s3FieldDialSkills.count(); i++) {
        b++;
        if (s3FieldDialSkills[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void S3FieldDialog::S3FieldDialInit(QString nameAny, QString affProt) {


    s3FieldDialAffProt = affProt;
    switch(s3FieldDialCountSkill) {
    case 1:
        ui->S3FieldDialComBox1->setEnabled(true);
        ui->S3FieldDialComBox1->addItems(carField->FieldDialSearch(nameAny));
        ui->S3FieldDialLabel1->setText(nameAny);
        S3FieldDialElem1(ui->S3FieldDialComBox1->currentText());
        break;
    case 2:
        ui->S3FieldDialComBox2->setEnabled(true);
        ui->S3FieldDialComBox2->addItems(carField->FieldDialSearch(nameAny));
        ui->S3FieldDialLabel2->setText(nameAny);
        S3FieldDialElem2(ui->S3FieldDialComBox2->currentText());
        break;
    case 3:
        ui->S3FieldDialComBox3->setEnabled(true);
        ui->S3FieldDialComBox3->addItems(carField->FieldDialSearch(nameAny));
        ui->S3FieldDialLabel3->setText(nameAny);
        S3FieldDialElem3(ui->S3FieldDialComBox3->currentText());
        break;
    case 4:
        ui->S3FieldDialComBox4->setEnabled(true);
        ui->S3FieldDialComBox4->addItems(carField->FieldDialSearch(nameAny));
        ui->S3FieldDialLabel4->setText(nameAny);
        S3FieldDialElem4(ui->S3FieldDialComBox4->currentText());
        break;
    default:
        qDebug() << "ERROR!";
        break;

    }
}


void S3FieldDialog::S3FieldDialPrintTable() {
    ui->S3FieldDialTable->clear();


    for(int sCount = 0 ; sCount < s3FieldDialSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(s3FieldDialSkills[sCount].first);
        ui->S3FieldDialTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(s3FieldDialSkills[sCount].second));
        ui->S3FieldDialTable->setItem(sCount,1,newSValueItem);
    }

}
