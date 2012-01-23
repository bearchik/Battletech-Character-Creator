#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QString>
#include <QMessageBox>
#include <QMultiMap>

#define VERSION "BT Character Creator v.0.8.11"
#define SHORTVER "0.8.11"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(VERSION);
    preqdial = new PreqDialog;
    gmchrtool = new GMCharTools;
    ptrtablewin = new PrintTableWindow;
    chkver = new ChkVer(parent,SHORTVER);

    connect(preqdial, SIGNAL(accepted()), this, SLOT(preqDial()));
    connect(gmchrtool,SIGNAL(accepted()), this, SLOT(AddGmNum()));

    chkWiz = false;
//    xpMain = 5000;
//    wizardMod = 0;
    massChar = 0;
//    countCBills = 0;
    openFileName.first.clear();
    openFileName.second = false;
    ui->statusXPAttrMain->setText(QString::number(xpMain));
    ui->statusXPAttrMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    charNameMain = "Enter Character name";

    loadres = new LoadResurce;
    if( loadres->loadSkills() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open skills file!"));
    }

    if( loadres->loadTraits() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open traits file!"));
    }


    if( loadres->loadAffl() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open affilation file!"));
    }

    if( loadres->loadPhen() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open phenotype file!"));
    }

    if( loadres->loadEye() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open eyecolor file!"));
    }

    if( loadres->loadHair() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open haircolor file!"));
    }

    if( loadres->loadPlanets() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open planets file!"));
    }

    if( loadres->loadEquip() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open equip file!"));
    }

    if( loadres->loadWeapons() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open weapons file!"));
    }

    if(loadres->loadSkillsDesc() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open Skills Description file!"));
    }

    if(loadres->loadTraitsDesc() == false ) {
        QMessageBox::critical(this, tr("ERROR"),tr("Error open Traits Description file!"));
    }


    ui->AffilationMain->addItems(loadres->afflList);
    ui->PhenotypeMain->addItems(loadres->phenList);
    planetList = loadres->planetList;
    ui->HomePlanetMain->addItems(planetList);
    ui->EyeColorMain->addItems(loadres->eyeList);
    ui->HairColorMain->addItems(loadres->hairList);
    ui->CharNameMain->setText(charNameMain);

    skillsDescList = loadres->skillsDescList;
    traitsDescList = loadres->traitsDescList;

    namePlanetMain = ui->HomePlanetMain->currentText();

    PrintAllSkillsTable();
    PrintAllTraitsTable();
    PrintAllEquipTable("ALL");
    PrintAllWeaponTable("ALL");
    ui->PhenotypeMain->setDisabled(true);

    saveFlag = false;
    on_actionNew_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::PrintAllSkillsTable() {
    ui->SkillAllTableMain->clearSpans();
    ui->SkillAllTableMain->setRowCount(loadres->skillsList.count());

    for(int i = 0 ; i < loadres->skillsList.count() ; i++) {

        QStringList linkPart = loadres->skillsList[i].second.split("," ,QString::SkipEmptyParts);

        QTableWidgetItem *newSNameItem = new QTableWidgetItem(loadres->skillsList[i].first);
        newSNameItem->setToolTip(SkillDesc(loadres->skillsList[i].first));
        ui->SkillAllTableMain->setItem(i,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(linkPart[0]);
        ui->SkillAllTableMain->setItem(i,1,newSValueItem);
        newSValueItem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::PrintAllTraitsTable() {
    ui->TraitAllTableMain->clearSpans();
    ui->TraitAllTableMain->setRowCount(loadres->traitsList.count());

    for(int i = 0 ; i < loadres->traitsList.count() ; i++) {

        QTableWidgetItem *newSNameItem = new QTableWidgetItem(loadres->traitsList[i].first);
        newSNameItem->setToolTip(TraitsDesc(loadres->traitsList[i].first));
        ui->TraitAllTableMain->setItem(i,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(loadres->traitsList[i].second);
        ui->TraitAllTableMain->setItem(i,1,newSValueItem);
        newSValueItem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::PrintAllEquipTable(QString nameElem) {

    QStringList equipList;
    ui->EquipAllTableMain->clearContents();
    ui->EquipAllTableMain->setRowCount(0);

    int countRow = 0;


    if (nameElem == "ALL") {

        QMultiMap<QString, QStringList>::iterator i=loadres->equipList.begin();
        while (i != loadres->equipList.end()) {
            ui->EquipAllTableMain->setRowCount(++countRow);
            equipList.clear();
            equipList << i.value();
            QTableWidgetItem *newNameItem = new QTableWidgetItem(equipList[0]);
            ui->EquipAllTableMain->setItem(countRow-1,0,newNameItem);

            QTableWidgetItem *newBARItem = new QTableWidgetItem(equipList[4]);
            ui->EquipAllTableMain->setItem(countRow-1,1,newBARItem);
            newBARItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newCostItem = new QTableWidgetItem(equipList[1]);
            ui->EquipAllTableMain->setItem(countRow-1,2,newCostItem);
            newCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newMassItem = new QTableWidgetItem(equipList[2]);
            ui->EquipAllTableMain->setItem(countRow-1,3,newMassItem);
            newMassItem->setTextAlignment(Qt::AlignCenter);

            ++i;

        }

    } else {
        QMultiMap<QString, QStringList>::iterator i=loadres->equipList.find(nameElem);
        while (i != loadres->equipList.end() && i.key() == nameElem) {
            ui->EquipAllTableMain->setRowCount(++countRow);
            equipList.clear();
            equipList << i.value();
            QTableWidgetItem *newNameItem = new QTableWidgetItem(equipList[0]);
            ui->EquipAllTableMain->setItem(countRow-1,0,newNameItem);

            QTableWidgetItem *newBARItem = new QTableWidgetItem(equipList[4]);
            ui->EquipAllTableMain->setItem(countRow-1,1,newBARItem);
            newBARItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newCostItem = new QTableWidgetItem(equipList[1]);
            ui->EquipAllTableMain->setItem(countRow-1,2,newCostItem);
            newCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newMassItem = new QTableWidgetItem(equipList[2]);
            ui->EquipAllTableMain->setItem(countRow-1,3,newMassItem);
            newMassItem->setTextAlignment(Qt::AlignCenter);

            ++i;
        }
    }

}

void MainWindow::PrintAllWeaponTable(QString nameElem) {

    QStringList weaponList;
    ui->WeaponAllTableMain->clearContents();
    ui->WeaponAllTableMain->setRowCount(0);

    int countRow = 0;
    if (nameElem == "ALL") {
        QMultiMap<QString, QStringList>::iterator i=loadres->weaponsList.begin();
        while (i != loadres->weaponsList.end()) {
            ui->WeaponAllTableMain->setRowCount(++countRow);
            weaponList.clear();
            weaponList << i.value();
            QTableWidgetItem *newNameItem = new QTableWidgetItem(weaponList[1]);
            ui->WeaponAllTableMain->setItem(countRow-1,0,newNameItem);

            QTableWidgetItem *newBDItem = new QTableWidgetItem(weaponList[2]);
            ui->WeaponAllTableMain->setItem(countRow-1,1,newBDItem);
            newBDItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newCostItem = new QTableWidgetItem(weaponList[4]);
            ui->WeaponAllTableMain->setItem(countRow-1,2,newCostItem);
            newCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newRangeItem = new QTableWidgetItem(weaponList[3]);
            ui->WeaponAllTableMain->setItem(countRow-1,3,newRangeItem);
            newRangeItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newMassItem = new QTableWidgetItem(weaponList[5]);
            ui->WeaponAllTableMain->setItem(countRow-1,4,newMassItem);
            newMassItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newShotsItem = new QTableWidgetItem(weaponList[6]);
            ui->WeaponAllTableMain->setItem(countRow-1,5,newShotsItem);
            newShotsItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newAmmoCostItem = new QTableWidgetItem(weaponList[7]);
            ui->WeaponAllTableMain->setItem(countRow-1,6,newAmmoCostItem);
            newAmmoCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newAmmoMassItem = new QTableWidgetItem(weaponList[8]);
            ui->WeaponAllTableMain->setItem(countRow-1,7,newAmmoMassItem);
            newAmmoMassItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newSkillItem = new QTableWidgetItem(weaponList[0]);
            ui->WeaponAllTableMain->setItem(countRow-1,8,newSkillItem);
            newSkillItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newNotesItem = new QTableWidgetItem(weaponList[9]);
            ui->WeaponAllTableMain->setItem(countRow-1,9,newNotesItem);
            newNotesItem->setTextAlignment(Qt::AlignCenter);
            ++i;

        }
    } else {
        QMultiMap<QString, QStringList>::iterator i=loadres->weaponsList.find(nameElem);
        while (i != loadres->weaponsList.end() && i.key() == nameElem) {
            ui->WeaponAllTableMain->setRowCount(++countRow);
            weaponList.clear();
            weaponList << i.value();
            QTableWidgetItem *newNameItem = new QTableWidgetItem(weaponList[1]);
            ui->WeaponAllTableMain->setItem(countRow-1,0,newNameItem);

            QTableWidgetItem *newBDItem = new QTableWidgetItem(weaponList[2]);
            ui->WeaponAllTableMain->setItem(countRow-1,1,newBDItem);
            newBDItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newCostItem = new QTableWidgetItem(weaponList[4]);
            ui->WeaponAllTableMain->setItem(countRow-1,2,newCostItem);
            newCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newRangeItem = new QTableWidgetItem(weaponList[3]);
            ui->WeaponAllTableMain->setItem(countRow-1,3,newRangeItem);
            newRangeItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newMassItem = new QTableWidgetItem(weaponList[5]);
            ui->WeaponAllTableMain->setItem(countRow-1,4,newMassItem);
            newMassItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newShotsItem = new QTableWidgetItem(weaponList[6]);
            ui->WeaponAllTableMain->setItem(countRow-1,5,newShotsItem);
            newShotsItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newAmmoCostItem = new QTableWidgetItem(weaponList[7]);
            ui->WeaponAllTableMain->setItem(countRow-1,6,newAmmoCostItem);
            newAmmoCostItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newAmmoMassItem = new QTableWidgetItem(weaponList[8]);
            ui->WeaponAllTableMain->setItem(countRow-1,7,newAmmoMassItem);
            newAmmoMassItem->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *newSkillItem = new QTableWidgetItem(weaponList[0]);
            ui->WeaponAllTableMain->setItem(countRow-1,8,newSkillItem);
            newSkillItem->setTextAlignment(Qt::AlignCenter);
            ++i;
        }
    }
}

int MainWindow::MainInit() {

    on_actionNew_Wizard_triggered();

    ui->SkillAllTableMain->setColumnWidth(0,170);
    ui->SkillAllTableMain->setColumnWidth(1,50);

    ui->SkillChrTableMain->setColumnWidth(0,160);
    ui->SkillChrTableMain->setColumnWidth(1,60);
    ui->SkillChrTableMain->setColumnWidth(2,30);
    ui->SkillChrTableMain->setColumnWidth(3,35);
    ui->SkillChrTableMain->setColumnWidth(4,35);
    ui->SkillChrTableMain->setColumnWidth(5,35);

    ui->TraitAllTableMain->setColumnWidth(0,163);
    ui->TraitAllTableMain->setColumnWidth(1,57);

    ui->TraitChrTableMain->setColumnWidth(0,195);
    ui->TraitChrTableMain->setColumnWidth(1,60);
    ui->TraitChrTableMain->setColumnWidth(2,57);
    ui->TraitChrTableMain->setColumnWidth(3,35);

    ui->ScoreSTRMain->setAlignment(Qt::AlignCenter);
    ui->LinkSTRMain->setAlignment(Qt::AlignCenter);

    ui->ScoreBODMain->setAlignment(Qt::AlignCenter);
    ui->LinkBODMain->setAlignment(Qt::AlignCenter);

    ui->ScoreDEXMain->setAlignment(Qt::AlignCenter);
    ui->LinkDEXMain->setAlignment(Qt::AlignCenter);

    ui->ScoreRFLMain->setAlignment(Qt::AlignCenter);
    ui->LinkRFLMain->setAlignment(Qt::AlignCenter);

    ui->ScoreINTMain->setAlignment(Qt::AlignCenter);
    ui->LinkINTMain->setAlignment(Qt::AlignCenter);

    ui->ScoreWILMain->setAlignment(Qt::AlignCenter);
    ui->LinkWILMain->setAlignment(Qt::AlignCenter);

    ui->ScoreCHAMain->setAlignment(Qt::AlignCenter);
    ui->LinkCHAMain->setAlignment(Qt::AlignCenter);

    ui->ScoreEDGMain->setAlignment(Qt::AlignCenter);
    ui->LinkEDGMain->setAlignment(Qt::AlignCenter);

    ui->WalkMain->setAlignment(Qt::AlignCenter);
    ui->RunEvadeMain->setAlignment(Qt::AlignCenter);
    ui->SprintMain->setAlignment(Qt::AlignCenter);
    ui->ClimbMain->setAlignment(Qt::AlignCenter);
    ui->CrawlMain->setAlignment(Qt::AlignCenter);
    ui->SwimMain->setAlignment(Qt::AlignCenter);

    ui->MassEquipMain->setAlignment(Qt::AlignCenter);
    ui->MassWeaponMain->setAlignment(Qt::AlignCenter);

    return wz->exec();
}

void MainWindow::FinishWizard() {

    wz->PrereqStage();
//    переносим данные из визорда в калькулятор
    ageMain = wz->chr_dat->age;
    charNameMain = wz->chr_dat->charName;
    charAttrMain = wz->chr_dat->charAttr;
    charSkillsMain = wz->chr_dat->charSkills;
    charTraitsMain = wz->chr_dat->charTraits;
    affNameMain = wz->chr_dat->AffName;
    phenotypeMain = wz->chr_dat->phenotype;
    subAffNameMain = wz->chr_dat->subAffName;
    clanCastNameMain = wz->chr_dat->clanCastName;
    earlyChildNameMain = wz->chr_dat->earlyChildName;
    lateChildNameMain = wz->chr_dat->lateChildName;
    schoolNameMain = wz->chr_dat->schoolName;
    basicSchoolMain = wz->chr_dat->basicSchool;
    advSchoolMain = wz->chr_dat->advSchool;
    specSchoolMain = wz->chr_dat->specSchool;
    realLifeMain = wz->chr_dat->realLife;
    sexMain = wz->chr_dat->sex;
    hairMain = wz->chr_dat->hair;
    eyeMain = wz->chr_dat->eye;
    heightMain = wz->chr_dat->height;
    weightMain = wz->chr_dat->weight;

    preCharAttrMain = wz->chr_dat->preCharAttr;
    preCharSkillsMain = wz->chr_dat->preCharSkills;
    preCharTraitsMain = wz->chr_dat->preCharTraits;

// устанаваливаем параметры во все виджеты
    SetWigetValue();

    int xpProg = charAttrMain["STR"] + charAttrMain["BOD"] + charAttrMain["RFL"] + charAttrMain["DEX"] + charAttrMain["INT"]
                 + charAttrMain["WIL"] + charAttrMain["CHA"] + charAttrMain["EDG"] + SumSkillsXP() + SumTraitsXP();
    int XP;
    XP = xpMain - xpProg;
    wizardMod = XP - wz->chr_dat->xp;

    if (affNameMain.first != "Invading Clan" || affNameMain.first != "Homeworld Clan") {
        ui->PhenotypeMain->setEnabled(true);
    } else {
        ui->PhenotypeMain->setDisabled(true);
    }

    QString strNotes;

    strNotes = "-----Wizard Data-----\nAffilation: " + affNameMain.first + "\n"
            + "SubAffilation: " + subAffNameMain.first + "\n"
            + "Cast: " + clanCastNameMain.first + "\n"
            + "Early Childhood: " + earlyChildNameMain.first + "\n"
            + "Late Childhood: " + lateChildNameMain.first + "\n"
            + "School: " + schoolNameMain.first + "\n"
            + "Basic school: " + basicSchoolMain.first + "\n"
            + "Advanced school: " + advSchoolMain.first + "\n"
            + "Special school: " + specSchoolMain.first + "\n"
            + "Real Life: " + realLifeMain + "\n";

    ui->NotesMain->setText(strNotes);

    ChangeMain();


}

void MainWindow::SetWigetValue() {
    ui->CharNameMain->setText(charNameMain);
    ui->AgeMain->setValue(ageMain);

    ui->STRSpinBoxMain->setValue(charAttrMain["STR"]);
    ui->BODSpinBoxMain->setValue(charAttrMain["BOD"]);
    ui->RFLSpinBoxMain->setValue(charAttrMain["RFL"]);
    ui->DEXSpinBoxMain->setValue(charAttrMain["DEX"]);
    ui->INTSpinBoxMain->setValue(charAttrMain["INT"]);
    ui->WILSpinBoxMain->setValue(charAttrMain["WIL"]);
    ui->CHASpinBoxMain->setValue(charAttrMain["CHA"]);
    ui->EDGSpinBoxMain->setValue(charAttrMain["EDG"]);


    ui->AffilationMain->clear();
    ui->AffilationMain->addItems(CreateList(affNameMain.first, loadres->afflList));
    ui->SubAffilationMain->clear();
    ui->SubAffilationMain->addItems(CreateList(subAffNameMain.first, CreateSubAffList(ui->AffilationMain->currentText())));
    ui->PhenotypeMain->clear();
    ui->PhenotypeMain->addItems(CreateList(phenotypeMain, loadres->phenList));

    QStringList sexList;
    if(sexMain == "Male") {
        sexList << "Male" << "Female";
    } else {
        sexList << "Female" << "Male";
    }
    ui->SexMain->clear();
    ui->SexMain->addItems(sexList);

    ui->HairColorMain->clear();
    ui->HairColorMain->addItems(CreateList(hairMain, loadres->hairList));
    ui->EyeColorMain->clear();
    ui->EyeColorMain->addItems(CreateList(eyeMain, loadres->eyeList));
    ui->HeightMain->setValue(heightMain);
    ui->WeightMain->setValue(weightMain);

    PrintYouWeapon();

}

void MainWindow::CancelWizard() {
    wz->chr_dat->charAttr.clear();
    wz->chr_dat->charSkills.clear();
    wz->chr_dat->charTraits.clear();
    ui->STRSpinBoxMain->setValue(400);
    ui->BODSpinBoxMain->setValue(400);
    ui->RFLSpinBoxMain->setValue(400);
    ui->DEXSpinBoxMain->setValue(400);
    ui->INTSpinBoxMain->setValue(400);
    ui->WILSpinBoxMain->setValue(400);
    ui->CHASpinBoxMain->setValue(400);
    ui->EDGSpinBoxMain->setValue(400);
}


QStringList MainWindow::CreatPhenList(QString namePhen) {
    QStringList phenSwp;
    phenSwp.clear();

    for(int i = 0; i < loadres->phenList.count(); i++) {
        if (loadres->phenList[i] == namePhen) {
            phenSwp << namePhen;
        }
    }

    for(int i = 0; i < loadres->phenList.count(); i++) {
        if (loadres->phenList[i] != namePhen) {
            phenSwp << loadres->phenList[i];
        }
    }
    return phenSwp;
}

QStringList MainWindow::CreateList(QString nameElem, QStringList listElem) {
    QStringList elemSwp;
    elemSwp.clear();

    for(int i = 0; i < listElem.count(); i++) {
        if (listElem[i] == nameElem) {
            elemSwp << nameElem;
        }
    }

    for(int i = 0; i < listElem.count(); i++) {
        if (listElem[i] != nameElem) {
            elemSwp << listElem[i];
        }
    }


    return elemSwp;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (saveFlag != true) {
        QMessageBox msgBox;
        msgBox.setText("The character has been modified.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Save:
              on_actionSave_triggered();
              break;
          case QMessageBox::Discard:
              close();
              break;
          case QMessageBox::Cancel:
              event->ignore();
              break;
          default:
              // should never be reached
              break;
        }


    } else {
        event->accept();
    }
}

void MainWindow::on_actionNew_Wizard_triggered()
{
    if (chkWiz == true) {
        delete wz;
    }
    chkWiz = true;
    wz = new Wizard;
    wz->setWindowTitle(VERSION);
    wz->show();
    wz->raise();
    wz->activateWindow();
    connect(wz, SIGNAL(accepted()), this, SLOT(FinishWizard()));
    connect(wz->button(QWizard::CancelButton), SIGNAL(clicked()), this, SLOT(CancelWizard()));
}

// Function to calculate the statValue based on the statScore
int MainWindow::scoreStattoStatvalue(int number) {
    if (number < 100) {
                Statvalue = 1;
                }
        else {
            Statvalue = qFloor(number/100);
            }
    return Statvalue;

}

// Function to calculate the Linkmod based on the Statvalue
int MainWindow::StatvaluetoLinkmod(int number) {
    switch(number) {
        case 1:
            Linkmod = -2;
            break;
        case 2:
            Linkmod = -1;
            break;
        case 3:
            Linkmod = -1;
            break;
        case 4:
            default:
            Linkmod = 0;
            break;
        case 5:
            Linkmod = 0;
            break;
        case 6:
            Linkmod = 0;
            break;
        case 7:
            Linkmod = 1;
            break;
        case 8:
            Linkmod = 1;
            break;
        case 9:
            Linkmod = 1;
            break;
        case 10:
            Linkmod = 2;
    }
    return Linkmod;

}

//Function to calc the mass of the character from the STR score
double MainWindow::calcMassfromSTRscore(double STRscore) {
    if (STRscore < 100) {
        massChar = .1;
        }
        else {
            if (STRscore < 200) {
                massChar = 5.0;
            }
            else {
                if (STRscore < 300) {
                    massChar = 10.0;
                    }
                else {
                    if (STRscore < 400) {
                        massChar = 15.0;
                        }
                    else {
                        if (STRscore < 500) {
                            massChar = 20.0;
                            }
                        else {
                            if (STRscore < 600) {
                                massChar = 30.0;
                                }
                            else {
                                if (STRscore < 700) {
                                    massChar = 40.0;
                                    }
                                else {
                                    if (STRscore < 800) {
                                        massChar = 55.0;
                                        }
                                    else {
                                        if (STRscore < 900) {
                                            massChar = 70.0;
                                            }
                                        else {
                                            if (STRscore < 1000) {
                                                massChar = 85.0;
                                                }
                                            else {
                                                if (STRscore == 1000) {
                                                    massChar = 100.0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        return massChar;
}


//Simplified Code section below using the three functions created above
//Greatly reduced number of lines of code with straightforward function calls
void MainWindow::on_STRSpinBoxMain_valueChanged(int number)
{
    charAttrMain["STR"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);
    massChar = calcMassfromSTRscore(number);

    if (number < 100) {
        ui->STRSpinBoxMain->setValue(100);
    }
    ui->ScoreSTRMain->setText(QString::number(Statvalue));
    ui->LinkSTRMain->setText(QString::number(Linkmod));

    ChangeMain();
}

void MainWindow::on_BODSpinBoxMain_valueChanged(int number)
{
    charAttrMain["BOD"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->BODSpinBoxMain->setValue(100);
    }
    ui->ScoreBODMain->setText(QString::number(Statvalue));
    ui->LinkBODMain->setText(QString::number(Linkmod));

    ChangeMain();
}

void MainWindow::on_RFLSpinBoxMain_valueChanged(int number)
{
    charAttrMain["RFL"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->RFLSpinBoxMain->setValue(100);
    }
    ui->ScoreRFLMain->setText(QString::number(Statvalue));
    ui->LinkRFLMain->setText(QString::number(Linkmod));

    ChangeMain();
}

void MainWindow::on_DEXSpinBoxMain_valueChanged(int number)
{
    charAttrMain["DEX"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->DEXSpinBoxMain->setValue(100);
    }
    ui->ScoreDEXMain->setText(QString::number(Statvalue));
    ui->LinkDEXMain->setText(QString::number(Linkmod));
    ChangeMain();
}

void MainWindow::on_INTSpinBoxMain_valueChanged(int number)
{
    charAttrMain["INT"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->INTSpinBoxMain->setValue(100);
    }
    ui->ScoreINTMain->setText(QString::number(Statvalue));
    ui->LinkINTMain->setText(QString::number(Linkmod));
    ChangeMain();
}

void MainWindow::on_WILSpinBoxMain_valueChanged(int number )
{
    charAttrMain["WIL"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->WILSpinBoxMain->setValue(100);
    }
    ui->ScoreWILMain->setText(QString::number(Statvalue));
    ui->LinkWILMain->setText(QString::number(Linkmod));
    ChangeMain();
}

void MainWindow::on_CHASpinBoxMain_valueChanged(int number)
{
    charAttrMain["CHA"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->CHASpinBoxMain->setValue(100);
    }
    ui->ScoreCHAMain->setText(QString::number(Statvalue));
    ui->LinkCHAMain->setText(QString::number(Linkmod));
    ChangeMain();
}

void MainWindow::on_EDGSpinBoxMain_valueChanged(int number)
{
    charAttrMain["EDG"] = number;

    Statvalue = scoreStattoStatvalue(number);
    Linkmod = StatvaluetoLinkmod(Statvalue);

    if (number < 100) {
        ui->EDGSpinBoxMain->setValue(100);
    }
    ui->ScoreEDGMain->setText(QString::number(Statvalue));
    ui->LinkEDGMain->setText(QString::number(Linkmod));
    ChangeMain();
}

void MainWindow::titleRenam(bool chk) {
    QString ver = VERSION;
    saveFlag = chk;
    QString titl;
    if (saveFlag == false) {
        if (openFileName.first.isEmpty()) {
            titl = "newchar.btcc* - " + ver;
        } else {
            titl = openFileName.first + "* - " + ver;
        }
    } else {
        titl = openFileName.first + " - " + ver;
    }


    this->setWindowTitle(titl);
}


void MainWindow::ChangeMain() {

    titleRenam(false);
    int xpProg = charAttrMain["STR"] + charAttrMain["BOD"] + charAttrMain["RFL"] + charAttrMain["DEX"] + charAttrMain["INT"]
                 + charAttrMain["WIL"] + charAttrMain["CHA"] + charAttrMain["EDG"] + SumSkillsXP() + SumTraitsXP();
    int XP;
    XP = xpMain - xpProg - wizardMod;

    ui->STRSpinBoxMain->setValue(charAttrMain["STR"]);
    ui->BODSpinBoxMain->setValue(charAttrMain["BOD"]);
    ui->RFLSpinBoxMain->setValue(charAttrMain["RFL"]);
    ui->DEXSpinBoxMain->setValue(charAttrMain["DEX"]);
    ui->INTSpinBoxMain->setValue(charAttrMain["INT"]);
    ui->WILSpinBoxMain->setValue(charAttrMain["WIL"]);
    ui->CHASpinBoxMain->setValue(charAttrMain["CHA"]);
    ui->EDGSpinBoxMain->setValue(charAttrMain["EDG"]);

    ui->statusXPAttrMain->setText(QString::number(XP));
    ui->statusXPAttrMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    ui->statusXPSkillsMain->setText(QString::number(XP));
    ui->statusXPSkillsMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    ui->statusXPTraitsMain->setText(QString::number(XP));
    ui->statusXPTraitsMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    ui->FreeXPMain->setText(QString::number(XP));
    ui->CharNameMain->setText(charNameMain);

    ui->CountSkillsMain->setText(QString::number(charSkillsMain.count()));
    ui->CountSkillsMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    ui->CountTraitsMain->setText(QString::number(charTraitsMain.count()));
    ui->CountTraitsMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));

    int sumCBills = 0;

    for (int i = 0; i < charTraitsMain.count(); i++) {
        if (charTraitsMain[i].first == "Wealth") {
            sumCBills = CheckTraitLvl(charTraitsMain[i].first, charTraitsMain[i].second);
        }
    }
    cbills = CheckCBills(sumCBills) + countCBills;

    float massCharSwp = 0;

    for(int i = 0; i < equipChar.count(); i++) {
        cbills = cbills - QVariant(equipChar[i][1]).toInt();
        massCharSwp = massCharSwp + QVariant(equipChar[i][2]).toFloat();
    }


    for(int i =0; i < weaponChar.count(); i++) {
        cbills = cbills - QVariant(weaponChar[i][4]).toInt();
        massCharSwp = massCharSwp + QVariant(weaponChar[i][5]).toFloat();
    }


    ui->MassEquipMain->setText(QString::number(massChar-massCharSwp));
    ui->MassWeaponMain->setText(QString::number(massChar-massCharSwp));


    ui->CBillsMain->setText(QString::number(cbills));
    ui->cbillsEq->setText(QString::number(cbills));
    ui->cbillsEq->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    ui->cbillsWp->setText(QString::number(cbills));
    ui->cbillsWp->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));


    int walkVar = ui->ScoreSTRMain->text().toInt() + ui->ScoreRFLMain->text().toInt();
    ui->WalkMain->setText(QString::number(walkVar));

    int runSkill = 0;
    for (int i = 0; i < charSkillsMain.count(); i++) {
        if (charSkillsMain[i].first == "Running") {
            runSkill = CheckSkillLvl(charSkillsMain[i].second);
        }
    }

    int runVar = 10 + walkVar + runSkill;
    ui->RunEvadeMain->setText(QString::number(runVar));
    ui->SprintMain->setText(QString::number(runVar*2));

    double advWalkMainVar = walkVar / 2.0;
    int advWalkMainVarSwp = advWalkMainVar;
    if ( advWalkMainVar-advWalkMainVarSwp != 0) {
        advWalkMainVarSwp += 1;
    }

    int climbSkill = 0;
    for (int i = 0; i < charSkillsMain.count(); i++) {
        if (charSkillsMain[i].first == "Climbing") {
            climbSkill = CheckSkillLvl(charSkillsMain[i].second);
        }
    }

    ui->ClimbMain->setText(QString::number(advWalkMainVarSwp+climbSkill));

    advWalkMainVar = walkVar / 4.0;
    advWalkMainVarSwp = advWalkMainVar;
    if ( advWalkMainVar-advWalkMainVarSwp != 0) {
        advWalkMainVarSwp += 1;
    }


    ui->CrawlMain->setText(QString::number(advWalkMainVarSwp));

    int swimSkill=0;
    for (int i = 0; i < charSkillsMain.count(); i++) {
        if (charSkillsMain[i].first == "Climbing") {
            swimSkill = CheckSkillLvl(charSkillsMain[i].second);
        }

        if(charSkillsMain[i].first.split("/")[0] == "Language") {
            if (CheckSkillLvl(charSkillsMain[i].second) >= 4) {
                for( int j =0; j < charTraitsMain.count(); j++) {
                    if(charTraitsMain[j].first == "Illiterate") {
                        charTraitsMain.removeAt(j);
                    }
                }
            }
        }
    }

    ui->SwimMain->setText(QString::number(walkVar+swimSkill));

    PrintSkillsTable();
    PrintTraitsTable();

    PrintEquipTable();
    PrintWeaponTable();

    PrintAllYouEquip();
    prerqPrintTable();
}

int MainWindow::SumSkillsXP() {
    int sumXP = 0;

    for( int i = 0; i < charSkillsMain.count(); i++) {
        sumXP += charSkillsMain[i].second;
    }

    return sumXP;
}

int MainWindow::SumTraitsXP() {
    int sumXP = 0;

    for( int i = 0; i < charTraitsMain.count(); i++) {
        sumXP += charTraitsMain[i].second;
    }

    return sumXP;
}

void MainWindow::PrintSkillsTable() {
    ui->SkillChrTableMain->blockSignals(true);
    ui->SkillChrTableMain->clearSpans();
    qSort(charSkillsMain.begin(), charSkillsMain.end());
    ui->SkillChrTableMain->setRowCount(charSkillsMain.count());

    for(int i = 0 ; i < charSkillsMain.count() ; i++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(charSkillsMain[i].first);
        newSNameItem->setToolTip(SkillDesc(charSkillsMain[i].first));
        ui->SkillChrTableMain->setItem(i,0,newSNameItem);
        newSNameItem->setFlags(newSNameItem->flags() ^ Qt::ItemIsEditable);

        for(int j = 0 ; j < loadres->skillsList.count(); j++) {
            QStringList hardName = charSkillsMain[i].first.split("/");
            if (hardName.count() == 2) {
                if(hardName[0] == loadres->skillsList[j].first.split("/")[0]) {
                    QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);
                    if( linkPart.count() == 2) {
                        if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                            linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                        }
                        QTableWidgetItem *newLinkItem = new QTableWidgetItem(linkPart[0]);
                        ui->SkillChrTableMain->setItem(i,1,newLinkItem);
                        newLinkItem->setTextAlignment(Qt::AlignCenter);
                        newLinkItem->setFlags(newLinkItem->flags() ^ Qt::ItemIsEditable);

                        QTableWidgetItem *newTCItem = new QTableWidgetItem(linkPart[1]);
                        ui->SkillChrTableMain->setItem(i,2,newTCItem);
                        newTCItem->setTextAlignment(Qt::AlignCenter);
                        newTCItem->setFlags(newTCItem->flags() ^ Qt::ItemIsEditable);

                    }
                }
            } else {
                if(charSkillsMain[i].first == loadres->skillsList[j].first.split("/")[0]) {
                    QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                    if( linkPart.count() == 2) {
                        if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                            linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                        }

                        QTableWidgetItem *newLinkItem = new QTableWidgetItem(linkPart[0]);
                        ui->SkillChrTableMain->setItem(i,1,newLinkItem);
                        newLinkItem->setTextAlignment(Qt::AlignCenter);
                        newLinkItem->setFlags(newLinkItem->flags() ^ Qt::ItemIsEditable);

                        QTableWidgetItem *newTCItem = new QTableWidgetItem(linkPart[1]);
                        ui->SkillChrTableMain->setItem(i,2,newTCItem);
                        newTCItem->setTextAlignment(Qt::AlignCenter);
                        newTCItem->setFlags(newTCItem->flags() ^ Qt::ItemIsEditable);
                    }
                }
            }

        }

        QTableWidgetItem *newLVLItem = new QTableWidgetItem(QString::number(CheckSkillLvl(charSkillsMain[i].second)));
        ui->SkillChrTableMain->setItem(i,3,newLVLItem);
        newLVLItem->setTextAlignment(Qt::AlignCenter);
        newLVLItem->setFlags(newLVLItem->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *newXPItem = new QTableWidgetItem(QString::number(charSkillsMain[i].second));
        ui->SkillChrTableMain->setItem(i,4,newXPItem);
        newXPItem->setTextAlignment(Qt::AlignCenter);
//        newXPItem->setFlags(newXPItem->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *newPlusItem = new QTableWidgetItem("+");
        ui->SkillChrTableMain->setItem(i,5,newPlusItem);
        newPlusItem->setTextAlignment(Qt::AlignCenter);
        newPlusItem->setFlags(newXPItem->flags() ^ Qt::ItemIsEditable);
    }

    ui->SkillChrTableMain->blockSignals(false);
}

QStringList MainWindow::AdvTried(QString elem, int lvlSkill) {
    QStringList returnVar;
    returnVar.clear();
    if(elem == "Art" && lvlSkill > 3) {
        returnVar << "DEX+INT" << "9/CA";
    }

    if(elem == "Computers" && lvlSkill > 3) {
        returnVar << "DEX+INT" << "9/CA";
    }

    if(elem == "Interests" && lvlSkill > 3) {
        returnVar << "INT+WIL" << "9/CA";
    }

    if(elem == "Martial Arts" && lvlSkill > 3) {
        returnVar << "RFL+DEX" << "8/SA";
    }

    if(elem == "Melee Weapons" && lvlSkill > 3) {
        returnVar << "RFL+DEX" << "8/SA";
    }

    if(elem == "Prestidigitation" && lvlSkill > 3) {
        returnVar << "RFL+DEX" << "8/SA";
    }
    return returnVar;

}

void MainWindow::PrintTraitsTable() {
    ui->TraitChrTableMain->blockSignals(true);
    ui->TraitChrTableMain->clearSpans();
    qSort(charTraitsMain.begin(), charTraitsMain.end());
    ui->TraitChrTableMain->setRowCount(charTraitsMain.count());

    for(int i = 0 ; i < charTraitsMain.count() ; i++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(charTraitsMain[i].first);
        newSNameItem->setToolTip(TraitsDesc(charTraitsMain[i].first));
        ui->TraitChrTableMain->setItem(i,0,newSNameItem);
        newSNameItem->setFlags(newSNameItem->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *newLVLItem = new QTableWidgetItem(QString::number(CheckTraitLvl(charTraitsMain[i].first, charTraitsMain[i].second)));
        ui->TraitChrTableMain->setItem(i,1,newLVLItem);
        newLVLItem->setTextAlignment(Qt::AlignCenter);
        newLVLItem->setFlags(newLVLItem->flags() ^ Qt::ItemIsEditable);

        for(int j = 0 ; j < loadres->traitsList.count(); j++) {
            QStringList hardName = charTraitsMain[i].first.split("/");
            if ( hardName.count() == 2) {
                if(hardName[0] == loadres->traitsList[j].first) {
                    QTableWidgetItem *newPageItem = new QTableWidgetItem(loadres->traitsList[j].second);
                    ui->TraitChrTableMain->setItem(i,2,newPageItem);
                    newPageItem->setTextAlignment(Qt::AlignCenter);
                    newPageItem->setFlags(newPageItem->flags() ^ Qt::ItemIsEditable);
                }
            } else {
                if(charTraitsMain[i].first == loadres->traitsList[j].first) {
                    QTableWidgetItem *newPageItem = new QTableWidgetItem(loadres->traitsList[j].second);
                    ui->TraitChrTableMain->setItem(i,2,newPageItem);
                    newPageItem->setTextAlignment(Qt::AlignCenter);
                    newPageItem->setFlags(newPageItem->flags() ^ Qt::ItemIsEditable);
                }
            }
        }

        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(charTraitsMain[i].second));
        ui->TraitChrTableMain->setItem(i,3,newSValueItem);
        newSValueItem->setTextAlignment(Qt::AlignCenter);
    }
    ui->TraitChrTableMain->blockSignals(false);
}

void MainWindow::PrintEquipTable() {
    ui->EquipChrTableMain->clearSpans();
    ui->EquipChrTableMain->setRowCount(equipChar.count());
    for(int i = 0; i < equipChar.count(); i++) {
        QTableWidgetItem *newNameItem = new QTableWidgetItem(equipChar[i][0]);
        ui->EquipChrTableMain->setItem(i,0,newNameItem);

        QTableWidgetItem *newCountItem = new QTableWidgetItem(equipChar[i][6]);
        ui->EquipChrTableMain->setItem(i,1,newCountItem);
        newCountItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newBARItem = new QTableWidgetItem(equipChar[i][4]);
        ui->EquipChrTableMain->setItem(i,2,newBARItem);
        newBARItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newCostItem = new QTableWidgetItem(equipChar[i][1]);
        ui->EquipChrTableMain->setItem(i,3,newCostItem);
        newCostItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newMassItem = new QTableWidgetItem(equipChar[i][2]);
        ui->EquipChrTableMain->setItem(i,4,newMassItem);
        newMassItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newNotesItem = new QTableWidgetItem(equipChar[i][5]);
        ui->EquipChrTableMain->setItem(i,5,newNotesItem);
        newNotesItem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::PrintWeaponTable() {
    ui->WeaponChrTableMain->clearSpans();
    ui->WeaponChrTableMain->setRowCount(weaponChar.count());

    for(int i =0; i < weaponChar.count(); i++) {
        QTableWidgetItem *newNameItem = new QTableWidgetItem(weaponChar[i][1]);
        ui->WeaponChrTableMain->setItem(i,0,newNameItem);

        QTableWidgetItem *newCountItem = new QTableWidgetItem(weaponChar[i][10]);
        ui->WeaponChrTableMain->setItem(i,1,newCountItem);
        newCountItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newBDItem = new QTableWidgetItem(weaponChar[i][2]);
        ui->WeaponChrTableMain->setItem(i,2,newBDItem);
        newBDItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newCostItem = new QTableWidgetItem(weaponChar[i][4]);
        ui->WeaponChrTableMain->setItem(i,3,newCostItem);
        newCostItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newRangeItem = new QTableWidgetItem(weaponChar[i][3]);
        ui->WeaponChrTableMain->setItem(i,4,newRangeItem);
        newRangeItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newMassItem = new QTableWidgetItem(weaponChar[i][5]);
        ui->WeaponChrTableMain->setItem(i,5,newMassItem);
        newMassItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newShotsItem = new QTableWidgetItem(weaponChar[i][6]);
        ui->WeaponChrTableMain->setItem(i,6,newShotsItem);
        newShotsItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newSkillItem = new QTableWidgetItem(weaponChar[i][0]);
        ui->WeaponChrTableMain->setItem(i,7,newSkillItem);
        newSkillItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newNoteItem = new QTableWidgetItem(weaponChar[i][9]);
        ui->WeaponChrTableMain->setItem(i,8,newNoteItem);
        newNoteItem->setTextAlignment(Qt::AlignCenter);
    }

}

void MainWindow::PrintAllYouEquip() {
    ui->AllYouTable->clearSpans();
    ui->AllYouTable->setRowCount(equipChar.count() + weaponChar.count());

    int countTab = 0;

    for(int i = 0; i < weaponChar.count(); i++) {
        QTableWidgetItem *newNameItem = new QTableWidgetItem(weaponChar[i][1]);
        ui->AllYouTable->setItem(i,0,newNameItem);

        QTableWidgetItem *newBDItem = new QTableWidgetItem(weaponChar[i][2]);
        ui->AllYouTable->setItem(i,1,newBDItem);
        newBDItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newCountItem = new QTableWidgetItem(weaponChar[i][10]);
        ui->AllYouTable->setItem(i,2,newCountItem);
        newCountItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newMassItem = new QTableWidgetItem(weaponChar[i][5]);
        ui->AllYouTable->setItem(i,3,newMassItem);
        newMassItem->setTextAlignment(Qt::AlignCenter);

        if(weaponChar[i][0] != "None") {
            QTableWidgetItem *newLocItem = new QTableWidgetItem("Weapon");
            ui->AllYouTable->setItem(i,4,newLocItem);
            newLocItem->setTextAlignment(Qt::AlignCenter);
        } else {
            QTableWidgetItem *newLocItem = new QTableWidgetItem("Ammo");
            ui->AllYouTable->setItem(i,4,newLocItem);
            newLocItem->setTextAlignment(Qt::AlignCenter);
        }
        QTableWidgetItem *newNotesItem = new QTableWidgetItem(weaponChar[i][9]);
        ui->AllYouTable->setItem(i,5,newNotesItem);
        countTab = i+1;
    }

    for(int i =0; i < equipChar.count(); i++) {

        QTableWidgetItem *newNameItem = new QTableWidgetItem(equipChar[i][0]);
        ui->AllYouTable->setItem(i+countTab,0,newNameItem);

        QTableWidgetItem *newDefItem = new QTableWidgetItem(equipChar[i][4]);
        ui->AllYouTable->setItem(i+countTab,1,newDefItem);
        newDefItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newCountItem = new QTableWidgetItem(equipChar[i][6]);
        ui->AllYouTable->setItem(i+countTab,2,newCountItem);
        newCountItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newMassItem = new QTableWidgetItem(equipChar[i][2]);
        ui->AllYouTable->setItem(i+countTab,3,newMassItem);
        newMassItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newLocItem = new QTableWidgetItem(BodyLoc(equipChar[i][3]));
        ui->AllYouTable->setItem(i+countTab,4,newLocItem);
        newLocItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *newNoteItem = new QTableWidgetItem(equipChar[i][5]);
        ui->AllYouTable->setItem(i+countTab,5,newNoteItem);
    }
}

int MainWindow::CheckTraitLvl(QString nameTrait, int number) {

    int lvlValue;

    lvlValue = qFloor(number / 100);

//    if (number >= 0) {
//        if ( number < 100 ) {
//            lvlValue = 0;
//        }

//        if ( number >= 100 && number < 200 ) {
//            lvlValue= 1;
//        }

//        if ( number >= 200 && number < 300 ) {
//            lvlValue= 2;
//        }

//        if ( number >= 300 && number < 400 ) {
//            lvlValue= 3;
//        }

//        if ( number >= 400 && number < 500 ) {
//            lvlValue= 4;
//        }

//        if ( number >= 500 && number < 600 ) {
//            lvlValue= 5;
//        }

//        if ( number >= 600 && number < 700 ) {
//            lvlValue= 6;
//        }

//        if ( number >= 700 && number < 800 ) {
//            lvlValue= 7;
//        }

//        if ( number >= 800 && number < 900 ) {
//            lvlValue= 8;
//        }

//        if ( number >= 900 && number < 1000 ) {
//            lvlValue= 9;
//        }

//        if ( number >= 1000 ) {
//            lvlValue= 10;
//        }
//    } else {
//        if ( number > -100 ) {
//            lvlValue = 0;
//        }
//// TEST COMMIT COMMENT
//        if ( number <= -100 && number > -200 ) {
//            lvlValue= -1;
//        }

//        if ( number <= -200 && number > -300 ) {
//            lvlValue= -2;
//        }

//        if ( number <= -300 && number > -400 ) {
//            lvlValue= -3;
//        }

//        if ( number <= -400 && number > -500 ) {
//            lvlValue= -4;
//        }

//        if ( number <= -500 && number > -600 ) {
//            lvlValue= -5;
//        }

//        if ( number <= -600 && number > -700 ) {
//            lvlValue= -6;
//        }

//        if ( number <= -700 && number > -800 ) {
//            lvlValue= -7;
//        }

//        if ( number <= -800 && number > -900 ) {
//            lvlValue= -8;
//        }

//        if ( number <= -900 && number > -1000 ) {
//            lvlValue= -9;
//        }

//        if ( number <= -1000 ) {
//            lvlValue= -10;
//        }
//    }

    if(nameTrait == "Alternate ID") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "Animal Antipathy") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Animal Empathy") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Attractive") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "Bloodmark") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -5) {
            lvlValue = -5;
        }
    }

    if(nameTrait.contains("Citizenship") == true) {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "Combat Paralysis") {
        if(lvlValue > 0) {
            lvlValue = 1;
        }
        if(lvlValue < -4) {
            lvlValue = -4;
        }
    }

    if(nameTrait == "Combat Sense") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 4) {
            lvlValue = 4;
        }
    }

    if(nameTrait.contains("Compulsion") == true ) {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -5) {
            lvlValue = -5;
        }
    }

    if(nameTrait == "Connections") {
        if(lvlValue < 1) {
            lvlValue = 1;
        }
        if(lvlValue > 10) {
            lvlValue = 10;
        }
    }

    if(nameTrait == "Custom Vehicle") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 6) {
            lvlValue = 6;
        }
    }

    if(nameTrait == "Dark Secret") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -5) {
            lvlValue = -5;
        }
    }

    if(nameTrait == "Dependent") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -2) {
            lvlValue = -2;
        }
    }

    if(nameTrait == "Design Quirk") {
        if(lvlValue > 5) {
            lvlValue = 5;
        }
        if(lvlValue < -5) {
            lvlValue = -5;
        }
    }

    if(nameTrait == "Design Quirk/Rumble Seat") {
        lvlValue = 0;
    }

    if(nameTrait == "Enemy") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -10) {
            lvlValue = -10;
        }
    }

    if(nameTrait == "Equipped") {
        if(lvlValue < -1) {
            lvlValue = -1;
        }
        if(lvlValue > 8) {
            lvlValue = 8;
        }
    }

    if(nameTrait.contains("Exceptional Attribute") == true) {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "Extra Income") {
        if(lvlValue < -10) {
            lvlValue = -10;
        }
        if(lvlValue > 10) {
            lvlValue = 10;
        }
    }

    if(nameTrait == "Fast Learner") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 3) {
            lvlValue = 3;
        }
    }

    if(nameTrait == "Fit") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "G-Tolerance") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Glass Jaw") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -3) {
            lvlValue = -3;
        }
    }

    if(nameTrait == "Good Hearing") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Good Vision") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Gregarious") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Gremlins") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -3) {
            lvlValue = -3;
        }
    }

    if(nameTrait == "Handicap") {
        if(lvlValue < -5) {
            lvlValue = -5;
        }
        if(lvlValue > -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Illiterate") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Impatient") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Implant/Prosthetic") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 6) {
            lvlValue = 6;
        }
    }

    if(nameTrait == "In For Life") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -3) {
            lvlValue = -3;
        }
    }

    if(nameTrait == "Introvert") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Lost Limb") {
        if(lvlValue < -5) {
            lvlValue = -5;
        }
        if(lvlValue > -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Natural Aptitude") {
        if(lvlValue >= 3) {
            lvlValue = 3;
        } else {
           lvlValue = 0;
        }
        if(lvlValue >= 5) {
            lvlValue = 5;
        } else {
           lvlValue = 0;
        }
    }

    if(nameTrait == "Pain Resistance") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 3) {
            lvlValue = 3;
        }
    }

    if(nameTrait == "Patient") {
        if(lvlValue < 1) {
            lvlValue = 0;
        }
        if(lvlValue >= 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Phenotype") {
            lvlValue = 0;
    }

    if(nameTrait == "Poison Resistance") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 2) {
            lvlValue = 2;
        }
    }

    if(nameTrait == "Poor Hearing") {
        if(lvlValue < -5) {
            lvlValue = -5;
        }
        if(lvlValue > -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Poor Vision") {
        if(lvlValue < -9) {
            lvlValue = -9;
        }
        if(lvlValue > -2) {
            lvlValue = -2;
        }
    }

    if(nameTrait == "Property") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 10) {
            lvlValue = 10;
        }
    }

    if(nameTrait == "Rank") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 15) {
            lvlValue = 15;
        }
    }

    if(nameTrait == "Reputation") {
        if(lvlValue < -5) {
            lvlValue = -5;
        }
        if(lvlValue > 5) {
            lvlValue = 5;
        }
    }

    if(nameTrait == "Sixth Sense") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 4) {
            lvlValue = 4;
        }
    }

    if(nameTrait == "Slow Learner") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -3) {
            lvlValue = -3;
        }
    }

    if(nameTrait == "Tech Empathy") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 3) {
            lvlValue = 3;
        }
    }

    if(nameTrait == "Thick-Skinned") {
        if(lvlValue < 1) {
            lvlValue = 0;
        }
        if(lvlValue >= 1) {
            lvlValue = 1;
        }
    }

    if(nameTrait == "Thin-Skinned") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait.contains("Title") == true) {
        if(lvlValue < 3) {
            lvlValue = 3;
        }
        if(lvlValue > 10) {
            lvlValue = 10;
        }
    }

    if(nameTrait == "TDS") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Unattractive") {
        if(lvlValue > 0) {
            lvlValue = 0;
        }
        if(lvlValue < -1) {
            lvlValue = -1;
        }
    }

    if(nameTrait == "Unlucky") {
        if(lvlValue > -2) {
            lvlValue = 2;
        }
        if(lvlValue < -10) {
            lvlValue = -10;
        }
    }

    if(nameTrait == "Vehicle") {
        if(lvlValue < 0) {
            lvlValue = 0;
        }
        if(lvlValue > 12) {
            lvlValue = 12;
        }
    }

    if(nameTrait == "Wealth") {
        if(lvlValue < -1) {
            lvlValue = -1;
        }
        if(lvlValue > 10) {
            lvlValue = 10;
        }
    }


    return lvlValue;
}

int MainWindow::CheckSkillLvl(int number) {
    int lvlValue;

    bool chkFastLearn = false;
    bool chkSlowLearn = false;

    for(int i = 0; i < charTraitsMain.count(); i++) {
        if(charTraitsMain[i].first == "Fast Learner") {
            if(charTraitsMain[i].second >= 300) {
                chkFastLearn = true;
            }

        }
    }

    for(int i = 0; i < charTraitsMain.count(); i++) {
        if(charTraitsMain[i].first == "Slow Learner") {
            if(charTraitsMain[i].second <= -300) {
                chkSlowLearn = true;
            }
        }
    }

    // Skill multiplier used to reduce lines of code.  The qFloor function was used because the float operation
    // with the int and double was not evaluating correctly.  The qFloor converts the double to an int so the comparison is valid
    Skillmultiplier = 1;
    if (chkFastLearn == true) {
        Skillmultiplier = Skillmultiplier - .2;
    }
    if (chkSlowLearn == true) {
        Skillmultiplier = Skillmultiplier + .2;
    }

    if (number < qFloor(30 * Skillmultiplier)){
        lvlValue = 0;
    }
    if (number >= qFloor(30 * Skillmultiplier) && number < qFloor(50 * Skillmultiplier)){
        lvlValue = 1;
    }
    if (number >= qFloor(50 * Skillmultiplier) && number < qFloor(80 * Skillmultiplier)){
        lvlValue = 2;
    }
    if (number >= qFloor(80 * Skillmultiplier) && number < qFloor(120 * Skillmultiplier)){
        lvlValue = 3;
    }
    if (number >= qFloor(120 * Skillmultiplier) && number < qFloor(170 * Skillmultiplier)){
        lvlValue = 4;
    }
    if (number >= qFloor(170 * Skillmultiplier) && number < qFloor(230 * Skillmultiplier)){
        lvlValue = 5;
    }
    if (number >= qFloor(230 * Skillmultiplier) && number < qFloor(300 * Skillmultiplier)){
        lvlValue = 6;
    }
    if (number >= qFloor(300 * Skillmultiplier) && number < qFloor(380 * Skillmultiplier)){
        lvlValue = 7;
    }
    if (number >= qFloor(380 * Skillmultiplier) && number < qFloor(470 * Skillmultiplier)){
        lvlValue = 8;
    }
    if (number >= qFloor(470 * Skillmultiplier) && number < qFloor(570 * Skillmultiplier)){
        lvlValue = 9;
    }
    if (number >= qFloor(570 * Skillmultiplier)){
        lvlValue = 10;
    }

    return lvlValue;
}

int MainWindow::CheckCBills(int number) {
    int cbill;

    if ( number <= -1 ) {
        cbill = 100;
    }

    if ( number == 0 ) {
        cbill = 1000;
    }

    if ( number == 1 ) {
        cbill = 2500;
    }

    if ( number == 2 ) {
        cbill = 5000;
    }

    if ( number == 3 ) {
        cbill = 10000;
    }

    if ( number == 4 ) {
        cbill = 25000;
    }

    if ( number == 5 ) {
        cbill = 50000;
    }

    if ( number == 6 ) {
        cbill = 100000;
    }

    if ( number == 7 ) {
        cbill = 250000;
    }

    if ( number == 8 ) {
        cbill = 500000;
    }

    if ( number == 9 ) {
        cbill = 1000000;
    }

    if ( number == 10 ) {
        cbill = 2000000;
    }

    return cbill;
}


void MainWindow::on_SkillResetMain_clicked()
{
    charSkillsMain = wz->chr_dat->charSkills;
    PrintSkillsTable();
}

void MainWindow::on_TraitResetMain_clicked()
{
    charTraitsMain = wz->chr_dat->charTraits;
    PrintTraitsTable();
}

void MainWindow::on_PhenotypeMain_activated(QString namePhen)
{
    int STR = 800;
    int BOD = 800;
    int RFL = 800;
    int DEX = 800;
    int INT = 800;
    int WIL = 800;
    int CHA = 900;
    int EDG = 900;

    if(namePhen == "Phenotype/Aerospace") {
        STR = 700;
        BOD = 700;
        RFL = 900;
        DEX = 900;
        INT = 900;
        CHA = 800;
        EDG = 800;
    }

    if(namePhen == "Phenotype/Elemental") {
        STR = 900;
        BOD = 900;
        DEX = 700;
        WIL = 900;
        CHA = 800;
        EDG = 800;
    }

    if(namePhen == "Phenotype/MechWarrior") {
        DEX = 900;
        RFL = 900;
        EDG = 800;
    }

    ui->STRSpinBoxMain->setMaximum(STR);
    ui->BODSpinBoxMain->setMaximum(BOD);
    ui->RFLSpinBoxMain->setMaximum(RFL);
    ui->DEXSpinBoxMain->setMaximum(DEX);
    ui->INTSpinBoxMain->setMaximum(INT);
    ui->WILSpinBoxMain->setMaximum(WIL);
    ui->CHASpinBoxMain->setMaximum(CHA);
    ui->EDGSpinBoxMain->setMaximum(EDG);

    phenotypeMain = namePhen;

}

void MainWindow::openFile(QString nameFile)
{
    on_actionNew_triggered();
    bool notes = false;
    openFileData.clear();
    QStringList sBuf;
    sBuf.clear();
    QString str;
    QString notesSwp;
    str.clear();
    QFile file(nameFile);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            str = stream.readLine();
            sBuf = str.split(":",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                openFileData.append(qMakePair(sBuf[0],sBuf[1]));
            }

            if (str == "</notes>") {
                notes = false;
            }

            if (notes == true) {
                ui->NotesMain->insertPlainText(str + "\n");
            }

            if (str == "<notes>") {
                notes = true;
            }

        }

        file.close();
    } else {
        QMessageBox::critical(this, tr("ERROR"),tr("Open error of the saved file!"));
    }  

    for(int i = 0; i < openFileData.count(); i++) {
        if(openFileData[i].first == "name") {
            charNameMain = openFileData[i].second;
        }

        if(openFileData[i].first == "aff") {
            affNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "subaff") {
            subAffNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "clancaste") {
            clanCastNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "earlychild") {
            earlyChildNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "latechild") {
            lateChildNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "schoolname") {
            schoolNameMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "basicschool") {
            basicSchoolMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "advschool") {
            advSchoolMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "specschool") {
            specSchoolMain.first = openFileData[i].second;
        }

        if(openFileData[i].first == "reallife") {
            realLifeMain = openFileData[i].second;
        }

        if(openFileData[i].first == "phenotype") {
            phenotypeMain = openFileData[i].second;
        }

        if(openFileData[i].first == "nameplanet") {
            namePlanetMain = openFileData[i].second;
        }

        if(openFileData[i].first == "sex") {
            sexMain = openFileData[i].second;
        }

        if(openFileData[i].first == "age") {
            ageMain = openFileData[i].second.toInt();
        }

        if(openFileData[i].first == "haircolor") {
            hairMain = openFileData[i].second;
        }

        if(openFileData[i].first == "eyecolor") {
            eyeMain = openFileData[i].second;
        }

        if(openFileData[i].first == "height") {
            heightMain = openFileData[i].second.toInt();
        }

        if(openFileData[i].first == "weight") {
            weightMain = openFileData[i].second.toInt();
        }

        if(openFileData[i].first == "gmxpmod") {
            wizardMod = openFileData[i].second.toInt();
        }

        if(openFileData[i].first == "cbillmod") {
            countCBills = openFileData[i].second.toInt();
        }

        if(openFileData[i].first == "attr") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                charAttrMain[sBuf[0]] = QVariant(sBuf[1]).toInt();
            }
        }

        if(openFileData[i].first == "equiploc") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                loc[sBuf[0]] = sBuf[1];
            }
        }

        if(openFileData[i].first == "skill") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
               charSkillsMain.append(qMakePair( sBuf[0],QVariant(sBuf[1]).toInt() ) );
            }
        }

        if(openFileData[i].first == "trait") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
               charTraitsMain.append(qMakePair( sBuf[0],QVariant(sBuf[1]).toInt() ) );
            }
        }

        if(openFileData[i].first == "preattr") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                preCharAttrMain[sBuf[0]] = QVariant(sBuf[1]).toInt();
            }
        }

        if(openFileData[i].first == "preskill") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
               preCharSkillsMain.append(qMakePair( sBuf[0],QVariant(sBuf[1]).toInt() ) );
            }
        }

        if(openFileData[i].first == "pretrait") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
               preCharTraitsMain.append(qMakePair( sBuf[0],QVariant(sBuf[1]).toInt() ) );
            }
        }

        if(openFileData[i].first == "equip") {
            sBuf = openFileData[i].second.split(";",QString::SkipEmptyParts);
            if (sBuf.count() == 7){
               equipChar.append(sBuf);
            }
        }

        if(openFileData[i].first == "weapon") {
            sBuf = openFileData[i].second.split(";",QString::SkipEmptyParts);
            if (sBuf.count() == 11){
               weaponChar.append(sBuf);
            }
        }

        if(openFileData[i].first == "chrweapon") {
            sBuf = openFileData[i].second.split("=",QString::SkipEmptyParts);
            if (sBuf.count() == 1){
                for (int i =0; i < weaponChar.count(); i++) {
                    if(weaponChar[i][1] == sBuf[0]) {
                        QStringList swpYouWeapon;
                        swpYouWeapon.clear();
                        swpYouWeapon << weaponChar[i][1] << weaponChar[i][2] << "1" << weaponChar[i][5] << "Weapon";
                        youWeapon.append(swpYouWeapon);
                    }
                }
            }
        }




    }

    SetWigetValue();

    ChangeMain();

    openFileName.first = nameFile;
    openFileName.second = true;


    QMapIterator <QString, QString> g(loc);
    while(g.hasNext()) {
        g.next();
        dropElem.clear();
        dropElem << g.value();
        AddInvElem(g.key());
    }

}


void MainWindow::saveFileAs(QString nameFile)
{
    QStringList prepSave = prepSaveFile();
    QFile file(nameFile);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);

        for (int i =0; i < prepSave.count(); i++) {
            stream << prepSave[i];
        }

        openFileName.first = nameFile;
        openFileName.second = true;
        titleRenam(true);

        file.close();
    } else {
        QMessageBox::critical(this, tr("ERROR"),tr("Error saving the file!"));
    }


}

QStringList  MainWindow::prepSaveFile() {
    QStringList saveData;
    QString strData;
    saveData.clear();

    strData = "name:" + charNameMain + "\n";
    saveData << strData;

    strData = "aff:" + affNameMain.first + "\n";
    saveData << strData;

    strData = "subaff:" + subAffNameMain.first + "\n";
    saveData << strData;

    strData = "clancaste:" + clanCastNameMain.first + "\n";
    saveData << strData;

    strData = "earlychild:" + earlyChildNameMain.first + "\n";
    saveData << strData;

    strData = "latechild:" + lateChildNameMain.first + "\n";
    saveData << strData;

    strData = "schoolname:" + schoolNameMain.first + "\n";
    saveData << strData;

    strData = "basicschool:" + basicSchoolMain.first + "\n";
    saveData << strData;

    strData = "advschool:" + advSchoolMain.first + "\n";
    saveData << strData;

    strData = "specschool:" + specSchoolMain.first + "\n";
    saveData << strData;

    strData = "reallife:" + realLifeMain + "\n";
    saveData << strData;

    strData = "phenotype:" + phenotypeMain + "\n";
    saveData << strData;

    strData = "nameplanet:" + namePlanetMain + "\n";
    saveData << strData;

    strData = "sex:" + sexMain + "\n";
    saveData << strData;

    strData = "age:" + QString::number(ageMain) + "\n";
    saveData << strData;

    strData = "haircolor:" + hairMain + "\n";
    saveData << strData;

    strData = "eyecolor:" + eyeMain + "\n";
    saveData << strData;

    strData = "height:" + QString::number(heightMain) + "\n";
    saveData << strData;

    strData = "weight:" + QString::number(weightMain) + "\n";
    saveData << strData;

    strData = "gmxpmod:" + QString::number(wizardMod) + "\n";
    saveData << strData;

    strData = "cbillmod:" + QString::number(countCBills) + "\n";
    saveData << strData;

    QMapIterator <QString, int> i(charAttrMain);
    while(i.hasNext()) {
        i.next();
        strData = "attr:" + i.key() + "=" + QString::number(i.value()) + "\n";
        saveData << strData;
    }

    for (int i = 0; i < charSkillsMain.count(); i++) {
        strData = "skill:" + charSkillsMain[i].first + "=" + QString::number(charSkillsMain[i].second) + "\n";
        saveData << strData;
    }

    for (int i = 0; i < charTraitsMain.count(); i++) {
        strData = "trait:" + charTraitsMain[i].first + "=" + QString::number(charTraitsMain[i].second) + "\n";
        saveData << strData;
    }

    for (int i = 0; i < equipChar.count(); i++ ) {
        strData = "equip:";
        saveData << strData;
        for(int j = 0; j < equipChar[i].count(); ++j ) {
            saveData << equipChar[i][j] << ";";
        }
        saveData.removeLast();
        saveData << "\n";
    }

    QMapIterator <QString, int> j(preCharAttrMain);
    while(j.hasNext()) {
        j.next();
        if(j.value() >0) {
            strData = "preattr:" + j.key() + "=" + QString::number(j.value()) + "\n";
            saveData << strData;
        }

    }

    for (int i = 0; i < preCharSkillsMain.count(); i++) {
        strData = "preskill:" + preCharSkillsMain[i].first + "=" + QString::number(preCharSkillsMain[i].second) + "\n";
        saveData << strData;
    }

    for (int i = 0; i < preCharTraitsMain.count(); i++) {
        strData = "pretrait:" + preCharTraitsMain[i].first + "=" + QString::number(preCharTraitsMain[i].second) + "\n";
        saveData << strData;
    }

    QMapIterator <QString, QString> g(loc);
    while(g.hasNext()) {
        g.next();
        if(g.value() >0) {
            strData = "equiploc:" + g.key() + "=" + g.value() + "\n";
            saveData << strData;
        }

    }


    for (int i = 0; i < weaponChar.count(); i++ ) {
        strData = "weapon:";
        saveData << strData;
        for(int j = 0; j < weaponChar[i].count(); j++) {
            saveData << weaponChar[i][j] << ";";
        }
        saveData.removeLast();
        saveData << "\n";
    }

    for(int i =0; i < youWeapon.count(); i++) {
        strData = "chrweapon:" + youWeapon[i][0] + "\n";
        saveData << strData;
    }

    saveData << "<notes>\n";
    saveData << ui->NotesMain->toPlainText();
    saveData << "\n</notes>\n";

    return saveData;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"*.btcc",tr("BattleTech Character(*.btcc)"));
    if (!fileName.isEmpty()) {
       openFile(fileName);
       openFileName.first = fileName;
       titleRenam(false);
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    if (openFileName.first.isEmpty() == true) {
        openFileName.first = "newchar.btcc";
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),openFileName.first,tr("BattleTech Character(*.btcc)"));
    if (!fileName.isEmpty()) {
        saveFileAs(fileName);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(openFileName.second == true) {
        saveFileAs(openFileName.first);
    } else {
        on_actionSave_As_triggered();
    }
}

void MainWindow::on_AffilationMain_activated(QString nameElem)
{
    affNameMain.first = nameElem;
    if (nameElem == "Invading Clan" || nameElem == "Homeworld Clan") {
        ui->PhenotypeMain->setEnabled(true);
    } else {
        ui->PhenotypeMain->setDisabled(true);
    }
    titleRenam(false);

    ui->SubAffilationMain->clear();
    ui->SubAffilationMain->addItems(CreateSubAffList(nameElem));

}

void MainWindow::on_HomePlanetMain_activated(QString nameElem)
{
    namePlanetMain = nameElem;
    titleRenam(false);
}


void MainWindow::on_SexMain_activated(QString nameElem)
{
    sexMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_HeightMain_valueChanged(int nameElem)
{
    heightMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_WeightMain_valueChanged(int nameElem)
{
    weightMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_HairColorMain_activated(QString nameElem)
{
    hairMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_EyeColorMain_activated(QString nameElem)
{
    eyeMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_AgeMain_valueChanged(int nameElem)
{
    ageMain = nameElem;
    titleRenam(false);
}

void MainWindow::on_CharNameMain_editingFinished()
{
    charNameMain = ui->CharNameMain->text();
    titleRenam(false);
}

void MainWindow::changeSkills(QString skillName, int skillXP)
{
    if (charSkillsMain.count() == 0) {
        charSkillsMain.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, charSkillsMain);
        if ( i != 100500 ) {
            i--;
            charSkillsMain[i] = qMakePair(skillName, charSkillsMain[i].second + skillXP );
        } else {
            charSkillsMain.append(qMakePair(skillName, skillXP));
        }
    }
}

void MainWindow::changeTraits(QString skillName, int skillXP)
{
    if (charTraitsMain.count() == 0) {
        charTraitsMain.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, charTraitsMain);
        if ( i != 100500 ) {
            i--;
            charTraitsMain[i] = qMakePair(skillName, charTraitsMain[i].second + skillXP );
        } else {
            charTraitsMain.append(qMakePair(skillName, skillXP));
        }
    }
}

int MainWindow::findSkill(QString fSkillName, QList<QPair<QString, int> > nameList) {
    int b=0;
    for (int i = 0; i < nameList.count(); i++) {
        b++;
        if (nameList[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}


void MainWindow::on_SkillAllTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillAllTableMain->item(row, 0);

    if(skillName != 0x0) {
        changeSkills(skillName->text(),1);
    }

    ChangeMain();
}


void MainWindow::on_SkillChrTableMain_cellDoubleClicked(int row, int cel)
{
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillChrTableMain->item(row, 0);
    if (cel == 4) {
        ui->SkillChrTableMain->editItem( ui->SkillChrTableMain->item(row, cel));
    } else {
        if (cel == 5){
            if(skillName != 0x0) {
                changeSkills(skillName->text(),1);
            }
        } else {
            if(skillName != 0x0) {
                changeSkills(skillName->text(),-1);
            }
        }

    }


    ChangeMain();
}

void MainWindow::on_SkillAddMain_clicked()
{
    int row = ui->SkillAllTableMain->currentRow();
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillAllTableMain->item(row, 0);
    if(skillName != 0x0) {
        changeSkills(skillName->text(),10);
    }

    ChangeMain();

}

void MainWindow::on_SkillDelMain_clicked()
{
    int row = ui->SkillChrTableMain->currentRow();
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillChrTableMain->item(row, 0);
    if(skillName != 0x0) {
        changeSkills(skillName->text(),-10);
    }

    ChangeMain();
}

void MainWindow::on_TraitAllTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitAllTableMain->item(row, 0);

        if(traitName != 0x0) {
            changeTraits(traitName->text(),1);
        }

    ChangeMain();
}

void MainWindow::on_TraitChrTableMain_cellDoubleClicked(int row, int cel)
{
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitChrTableMain->item(row, 0);

    if (cel == 3) {
        ui->TraitChrTableMain->editItem( ui->TraitChrTableMain->item(row, cel));
    } else {
        if(traitName != 0x0) {
            changeTraits(traitName->text(),-1);
        }
    }
    ChangeMain();
}

void MainWindow::on_TraitAddMain_clicked()
{
    int row = ui->TraitAllTableMain->currentRow();
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitAllTableMain->item(row, 0);
    if(traitName != 0x0) {
        changeTraits(traitName->text(),10);
    }

    ChangeMain();
}

void MainWindow::on_TraitlDelMain_clicked()
{
    int row = ui->TraitChrTableMain->currentRow();
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitChrTableMain->item(row, 0);
    if(traitName != 0x0) {
        changeTraits(traitName->text(),-10);
    }

    ChangeMain();
}

void MainWindow::on_actionNew_triggered()
{
    chkWiz = false;

    openFileName.first.clear();
    openFileName.second = false;
    ui->statusXPAttrMain->setText(QString::number(xpMain));
    ui->statusXPAttrMain->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    xpMain = 5000;
    ageMain = 21;
    countCBills = 0;
    wizardMod = 0;
    //charNameMain = "Enter Charachter name";
    affNameMain.first.clear();
    affNameMain.second = 0;
    subAffNameMain.first.clear();
    subAffNameMain.second = 0;
    clanCastNameMain.first.clear();
    clanCastNameMain.second = 0;
    earlyChildNameMain.first.clear();
    earlyChildNameMain.second = 0;
    lateChildNameMain.first.clear();
    lateChildNameMain.second = 0;
    schoolNameMain.first.clear();
    schoolNameMain.second = 0;
    basicSchoolMain.first.clear();
    basicSchoolMain.second = 0;
    advSchoolMain.first.clear();
    advSchoolMain.second = 0;
    specSchoolMain.first.clear();
    specSchoolMain.second = 0;
    realLifeMain.clear();
    phenotypeMain.clear();
    planetList.clear();
    namePlanetMain.clear();
    sexMain.clear();
    hairMain.clear();
    eyeMain.clear();
    heightMain = 175;
    weightMain = 80;

    charSkillsMain.clear();
    charTraitsMain.clear();
    charAttrMain.clear();
    charAttrMain["STR"] = 100;
    charAttrMain["BOD"] = 100;
    charAttrMain["RFL"] = 100;
    charAttrMain["DEX"] = 100;
    charAttrMain["INT"] = 100;
    charAttrMain["WIL"] = 100;
    charAttrMain["CHA"] = 100;
    charAttrMain["EDG"] = 100;

    equipChar.clear();
    weaponChar.clear();
    youWeapon.clear();



    ui->AffilationMain->addItems(loadres->afflList);
    ui->SubAffilationMain->addItems(CreateSubAffList(ui->AffilationMain->currentText()));
    ui->PhenotypeMain->addItems(loadres->phenList);
    planetList = loadres->planetList;
    ui->HomePlanetMain->clear();
    ui->HomePlanetMain->addItems(planetList);
    ui->EyeColorMain->addItems(loadres->eyeList);
    ui->HairColorMain->addItems(loadres->hairList);
    //ui->CharNameMain->setText(charNameMain);

    SetWigetValue();
    QStringList sexList;
    sexList << "Male" << "Female";

    ui->SexMain->clear();
    ui->SexMain->addItems(sexList);

    ui->NotesMain->clear();

    preCharAttrMain.clear();
    preCharSkillsMain.clear();
    preCharTraitsMain.clear();

    dropElem.clear();
    loc.clear();

    ui->HeadListMain->clear();
    ui->HeadListMain->setToolTip("Head");
    ui->HeadListMain->addItem("Head");
    ui->BodyListMain->clear();
    ui->BodyListMain->setToolTip("Torso");
    ui->BodyListMain->addItem("Torso");
    ui->ArmLeftListMain->clear();
    ui->ArmLeftListMain->setToolTip("Arm");
    ui->ArmLeftListMain->addItem("Arm");
    ui->ArmRightListMain->clear();
    ui->ArmRightListMain->setToolTip("Arm");
    ui->ArmRightListMain->addItem("Arm");
    ui->HandLeftListMain->clear();
    ui->HandLeftListMain->setToolTip("Hand");
    ui->HandLeftListMain->addItem("Hand");
    ui->HandRightListMain->clear();
    ui->HandRightListMain->setToolTip("Hand");
    ui->HandRightListMain->addItem("Hand");
    ui->LegsListMain->clear();
    ui->LegsListMain->setToolTip("Legs");
    ui->LegsListMain->addItem("Legs");
    ui->FeetsListMain->clear();
    ui->FeetsListMain->setToolTip("Feets");
    ui->FeetsListMain->addItem("Feets");


    PrintYouWeapon();
    ChangeMain();
}


void MainWindow::on_EquipType_activated(QString nameElem)
{
    if (nameElem == "ALL") {
        PrintAllEquipTable(nameElem);
    }

    if(nameElem == "Personal Armor") {
        PrintAllEquipTable("persarmor");
    }

    if(nameElem == "Combat Armor") {
        PrintAllEquipTable("combatarmor");
    }

    if(nameElem == "(F)Standart Armor") {
        PrintAllEquipTable("fstandarmor");
    }

    if(nameElem == "Mechwarrior Kits") {
        PrintAllEquipTable("mechkit");
    }

    if(nameElem == "Special Combat Kits") {
        PrintAllEquipTable("speccombkit");
    }

    if(nameElem == "Exotic Armor") {
        PrintAllEquipTable("exotarmor");
    }

    if(nameElem == "Hostile Environment") {
        PrintAllEquipTable("hostenv");
    }

    if(nameElem == "Stealth Gear") {
        PrintAllEquipTable("shtirlitc");
    }

    if(nameElem == "Non-Combat Attire") {
        PrintAllEquipTable("nocombat");
    }

    if(nameElem == "Communications") {
        PrintAllEquipTable("commun");
    }

    if(nameElem == "Audio/Video/Trideo") {
        PrintAllEquipTable("avt");
    }

    if(nameElem == "Computers") {
        PrintAllEquipTable("comp");
    }

    if(nameElem == "Survellance Gear") {
        PrintAllEquipTable("survgear");
    }

    if(nameElem == "Optics") {
        PrintAllEquipTable("optics");
    }

    if(nameElem == "Remote Sensors") {
        PrintAllEquipTable("remsens");
    }

    if(nameElem == "Power Pack") {
        PrintAllEquipTable("cptpower");
    }

    if(nameElem == "Rechargers") {
        PrintAllEquipTable("rechar");
    }

    if(nameElem == "Espionage Gear & Security Systems") {
        PrintAllEquipTable("espsec");
    }

    if(nameElem == "Repair & Salvage") {
        PrintAllEquipTable("repsal");
    }

    if(nameElem == "Miscellaneous Gear") {
        PrintAllEquipTable("miscgear");
    }

    if(nameElem == "Medical") {
        PrintAllEquipTable("medic");
    }

}

void MainWindow::on_EquipAllTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *equipName = new QTableWidgetItem;
    equipName = ui->EquipAllTableMain->item(row, 0);
    QStringList equipList;

    if(equipName != 0x0) {
        QMultiMap<QString, QStringList>::iterator i=loadres->equipList.begin();
        while (i != loadres->equipList.end()) {
            equipList.clear();
            equipList << i.value();
            if( equipList[0] == equipName->text()) {
                AddEquip(equipList);
            }
            ++i;
        }
    }

    ChangeMain();

}


void MainWindow::AddEquip(QStringList nameElem) {

    int countPos=0;
    int countEquip;
    int costEquip;
    float massEquip;
    for(int i =0; i < equipChar.count(); i++) {
        if(equipChar[i][0] == nameElem[0]){
            countPos = i+1;
        }
    }

    if( countPos == 0 ) {
        nameElem << QString::number(1);
        equipChar.append(nameElem);
    } else {
        --countPos;
        countEquip = QVariant(equipChar[countPos][6]).toInt()+1;
        costEquip = QVariant(nameElem[1]).toInt() * countEquip;
        massEquip = QVariant(nameElem[2]).toFloat() * countEquip;
        equipChar.replace(countPos, nameElem << QString::number(countEquip));
        equipChar[countPos][1] = QString::number(costEquip);
        equipChar[countPos][2] = QString::number(massEquip);
    }
}

void MainWindow::on_EquipChrTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *equipName = new QTableWidgetItem;
    equipName = ui->EquipChrTableMain->item(row, 0);

    if(equipName != 0x0) {
        DelEquip(equipName->text());
    }
    ChangeMain();
}

void MainWindow::DelEquip(QString nameElem) {

    int countPos=0;
    int countEquip;
    int costEquip;
    float massEquip;
    for(int i =0; i < equipChar.count(); i++) {
        if(equipChar[i][0] == nameElem){
            countPos = i;
        }
    }

    costEquip = QVariant(equipChar[countPos][1]).toInt() / QVariant(equipChar[countPos][6]).toInt();
    massEquip = QVariant(equipChar[countPos][2]).toFloat() / QVariant(equipChar[countPos][6]).toFloat();
    countEquip = QVariant(equipChar[countPos][6]).toInt()-1;

    costEquip = costEquip * countEquip;
    massEquip = massEquip * countEquip;

    equipChar[countPos][6] = QString::number(countEquip);
    equipChar[countPos][1] = QString::number(costEquip);
    equipChar[countPos][2] = QString::number(massEquip);

    if(countEquip == 0) {
        QMapIterator <QString, QString> h(loc);
        while(h.hasNext()) {
            h.next();
            if(equipChar[countPos][0] == h.value()) {
                EraseLocation(h.key());
            }
        }

        equipChar.remove(countPos);
    }

}

void MainWindow::on_WeaponType_activated(QString nameElem)
{
    if (nameElem == "ALL") {
        PrintAllWeaponTable("ALL");
    }

    if (nameElem == "Archaic Melee") {
        PrintAllWeaponTable("archmelee");
    }

    if (nameElem == "Archaic Range") {
        PrintAllWeaponTable("archrange");
    }

    if (nameElem == "Modern Melee") {
        PrintAllWeaponTable("modermelee");
    }

    if (nameElem == "Ballistic") {
        PrintAllWeaponTable("balistic");
    }

    if (nameElem == "Energy") {
        PrintAllWeaponTable("energy");
    }

    if (nameElem == "Flechette") {
        PrintAllWeaponTable("flechet");
    }

    if (nameElem == "Gauss") {
        PrintAllWeaponTable("gaus");
    }

    if (nameElem == "Gyrojet") {
        PrintAllWeaponTable("gyrojet");
    }

    if (nameElem == "Miscellaneous Ranged") {
        PrintAllWeaponTable("miscrange");
    }

    if (nameElem == "Machine Gun") {
        PrintAllWeaponTable("arnigun");
    }

    if (nameElem == "Grenade Launchers & Mortars") {
        PrintAllWeaponTable("grenlaunch");
    }

    if (nameElem == "Missile Launchers") {
        PrintAllWeaponTable("misslaunch");
    }

    if (nameElem == "Recoilless Rifles") {
        PrintAllWeaponTable("recrifle");
    }

    if (nameElem == "Support Energy") {
        PrintAllWeaponTable("supenergy");
    }

    if (nameElem == "Support Gauss") {
        PrintAllWeaponTable("supgauss");
    }

    if (nameElem == "Standard Explosives") {
        PrintAllWeaponTable("stdexpl");
    }

    if (nameElem == "Demolitions") {
        PrintAllWeaponTable("bigbadaboom");
    }

    if (nameElem == "Weapons Accessories") {
        PrintAllWeaponTable("weaponaccess");
    }

}

void MainWindow::on_WeaponAllTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *weaponName = new QTableWidgetItem;
    weaponName = ui->WeaponAllTableMain->item(row, 0);
    QStringList weaponList;

    if(weaponName != 0x0) {
        QMultiMap<QString, QStringList>::iterator i=loadres->weaponsList.begin();
        while (i != loadres->weaponsList.end()) {
            weaponList.clear();
            weaponList << i.value();
            if( weaponList[1] == weaponName->text()) {
                AddWeapon(weaponList);
            }
            ++i;
        }
    }

    ChangeMain();

}

void MainWindow::AddWeapon(QStringList nameElem) {
    int countPos=0;
    int countWeapon;
    int costWeapon;
    float massWeapon;
    for(int i =0; i < weaponChar.count(); i++) {
        if(weaponChar[i][1] == nameElem[1]){
            countPos = i+1;
        }
    }

    if( countPos == 0 ) {
        nameElem << QString::number(1);
        weaponChar.append(nameElem);
    } else {
        --countPos;
        countWeapon = QVariant(weaponChar[countPos][10]).toInt()+1;
        costWeapon = QVariant(nameElem[4]).toInt() * countWeapon;
        massWeapon = QVariant(nameElem[5]).toFloat() * countWeapon;
        weaponChar.replace(countPos, nameElem << QString::number(countWeapon));
        weaponChar[countPos][4] = QString::number(costWeapon);
        weaponChar[countPos][5] = QString::number(massWeapon);
    }

}

void MainWindow::on_WeaponChrTableMain_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *weaponName = new QTableWidgetItem;
    weaponName = ui->WeaponChrTableMain->item(row, 0);

    if(weaponName != 0x0) {
        DelWeapon(weaponName->text());
        for(int i =0; i < youWeapon.count(); i++) {
            if(youWeapon[i][0] == weaponName->text()) {
                youWeapon.remove(i);
            }
        }
    }
    PrintYouWeapon();
    ChangeMain();
}

void MainWindow::DelWeapon(QString nameElem) {
    int countPos=0;
    int countWeapon;
    int costWeapon;
    float massWeapon;
    for(int i =0; i < weaponChar.count(); i++) {
        if(weaponChar[i][1] == nameElem){
            countPos = i;
        }
    }

    costWeapon = QVariant(weaponChar[countPos][4]).toInt() / QVariant(weaponChar[countPos][10]).toInt();
    massWeapon = QVariant(weaponChar[countPos][5]).toFloat() / QVariant(weaponChar[countPos][10]).toFloat();

    countWeapon = QVariant(weaponChar[countPos][10]).toInt()-1;
    costWeapon = costWeapon * countWeapon;
    massWeapon = massWeapon * countWeapon;
    weaponChar[countPos][10] = QString::number(countWeapon);
    weaponChar[countPos][4] = QString::number(costWeapon);
    weaponChar[countPos][5] = QString::number(massWeapon);

    if(countWeapon == 0) {
        weaponChar.remove(countPos);
    }

}

void MainWindow::on_AddAmmoMain_clicked()
{
    int countWeapon;
    int costWeapon;
    float massWeapon;

    int row = ui->WeaponChrTableMain->currentRow();
    QTableWidgetItem *weaponName = new QTableWidgetItem;
    weaponName = ui->WeaponChrTableMain->item(row, 0);

    if(weaponName != 0x0) {
        QString nameAmmo;
        nameAmmo = "\\_Ammo " + weaponName->text();
        QStringList weaponAmmo;
        weaponAmmo.clear();

        int weaponCountPos;

        for(int i = 0; i < weaponChar.count(); i++) {
            if (weaponChar[i][1] == weaponName->text()) {
                weaponCountPos = i;
            }
        }



        QStringList ammo = weaponChar[weaponCountPos][6].split(" ");
//        if(ammo[1] == "PPS") {
//            nameAmmo = "Power Pack";
//        }

        if(weaponChar[weaponCountPos][7] != "0" && weaponChar[weaponCountPos][0] != "None") {

            int ammoCountPos = 0;

            for(int i = 0; i < weaponChar.count(); i++) {
                if(weaponChar[i][1] == nameAmmo) {
                    ammoCountPos = i + 1;
                }
            }


            if( ammoCountPos == 0 ) {
                if(ammo.count() > 1) {
                    if(ammo[1] == "PPS") {
                        nameAmmo = "Power Pack";
                        weaponAmmo << "None" << nameAmmo << "0" << "0" << weaponChar[weaponCountPos][7] << weaponChar[weaponCountPos][8] << "20 PP" << "2" << "0.14" << "None" << "1";
                    } else {
                        weaponAmmo << "None" << nameAmmo << "0" << "0" << weaponChar[weaponCountPos][7] << weaponChar[weaponCountPos][8] << weaponChar[weaponCountPos][6] << "2" << "0.14" << "None" << "1";
                    }
                } else {
                    weaponAmmo << "None" << nameAmmo << "0" << "0" << weaponChar[weaponCountPos][7] << weaponChar[weaponCountPos][8] << weaponChar[weaponCountPos][6] << "2" << "0.14" << "None" << "1";
                }

                weaponChar.insert(weaponCountPos + 1, weaponAmmo);
            } else {
                --ammoCountPos;
                countWeapon = QVariant(weaponChar[ammoCountPos][10]).toInt()+1;
                costWeapon = QVariant(weaponChar[weaponCountPos][7]).toInt() * countWeapon;
                massWeapon = QVariant(weaponChar[weaponCountPos][8]).toFloat() * countWeapon;
                weaponChar[ammoCountPos][10] = QString::number(countWeapon);
                weaponChar[ammoCountPos][4] = QString::number(costWeapon);
                weaponChar[ammoCountPos][5] = QString::number(massWeapon);
            }

        }

        ChangeMain();
    }


}

void MainWindow::on_actionCheck_Wizard_triggered()
{

    preqdial->show();
    preqdial->raise();
    preqdial->activateWindow();

    CheckPrereq();

    preqdial->initPreDialog();

}

void MainWindow::preqDial() {

    if(!preqdial->preAttr.isEmpty()) {
        QMapIterator <QString, int> i(preqdial->preAttr);
        while(i.hasNext()) {
            i.next();
            charAttrMain[i.key()] = i.value();
        }
    }


    bool chk = false;

    if(!preqdial->preTraits.isEmpty()) {
        for(int i = 0; i < preqdial->preTraits.count(); i++) {
            for(int j = 0; j < charTraitsMain.count(); j++) {
                if(charTraitsMain[j].first == preqdial->preTraits[i].first) {
                    charTraitsMain[j].second = preqdial->preTraits[i].second;
                    chk = true;
                }
            }
            if(chk != true) {
                charTraitsMain.append(preqdial->preTraits[i]);
            }
            chk = false;
        }

    }


    if(!preqdial->preSkills.isEmpty()) {
        for(int i = 0; i < preqdial->preSkills.count(); i++) {
            for(int j = 0; j < charSkillsMain.count(); j++) {
                if(charSkillsMain[j].first == preqdial->preSkills[i].first) {
                    charSkillsMain[j].second = preqdial->preSkills[i].second;
                    chk = true;
                }
            }
            if(chk != true) {
                charSkillsMain.append(preqdial->preSkills[i]);
            }
            chk = false;

        }

    }

    ChangeMain();

}

bool MainWindow::CheckPrereq() {
    preqdial->preAttr.clear();
    preqdial->preSkills.clear();
    preqdial->preTraits.clear();


    bool check = false;

    if(preCharAttrMain["STR"] > charAttrMain["STR"]) {
        preqdial->preAttr["STR"] = preCharAttrMain["STR"];
    }

    if(preCharAttrMain["BOD"] > charAttrMain["BOD"]) {
        preqdial->preAttr["BOD"] = preCharAttrMain["BOD"];
    }

    if(preCharAttrMain["RFL"] > charAttrMain["RFL"]) {
        preqdial->preAttr["RFL"] = preCharAttrMain["RFL"];
    }

    if(preCharAttrMain["DEX"] > charAttrMain["DEX"]) {
        preqdial->preAttr["DEX"] = preCharAttrMain["DEX"];
    }

    if(preCharAttrMain["INT"] > charAttrMain["INT"]) {
        preqdial->preAttr["INT"] = preCharAttrMain["INT"];
    }

    if(preCharAttrMain["WIL"] > charAttrMain["WIL"]) {
        preqdial->preAttr["WIL"] = preCharAttrMain["WIL"];
    }

    if(preCharAttrMain["CHA"] > charAttrMain["CHA"]) {
        preqdial->preAttr["CHA"] = preCharAttrMain["CHA"];
    }

    if(preCharAttrMain["EDG"] > charAttrMain["EDG"]) {
        preqdial->preAttr["EDG"] = preCharAttrMain["EDG"];
    }


    bool chk = false;
    for(int i = 0; i < preCharSkillsMain.count(); i++) {
        for(int j = 0; j < charSkillsMain.count(); j++) {
            if (charSkillsMain[j].first == preCharSkillsMain[i].first) {
                if (charSkillsMain[j].second < preCharSkillsMain[i].second) {
                    preqdial->preSkills.append(qMakePair(preCharSkillsMain[i].first, preCharSkillsMain[i].second));
                }
                chk = true;
            }
        }
        if( chk == false) {
            preqdial->preSkills.append(qMakePair(preCharSkillsMain[i].first, preCharSkillsMain[i].second));
        }

        chk = false;
    }


    for(int i = 0; i < preCharTraitsMain.count(); i++) {
        for(int j = 0; j < charTraitsMain.count(); j++) {
            if (charTraitsMain[j].first == preCharTraitsMain[i].first) {
                if (charTraitsMain[j].second < preCharTraitsMain[i].second) {
                    preqdial->preTraits.append(qMakePair(preCharTraitsMain[i].first, preCharTraitsMain[i].second));
                }
                chk = true;
            }
        }
        if( chk == false) {
            preqdial->preTraits.append(qMakePair(preCharTraitsMain[i].first, preCharTraitsMain[i].second));
        }
        chk = false;
    }

    if(earlyChildNameMain.first == "Nobility") {
        for(int i = 0; i < charTraitsMain.size(); i++) {
            if (charTraitsMain[i].first == "Wealth" && charTraitsMain[i].second >= 500) {
                preqdial->preTraits.clear();
            }

            if (charTraitsMain[i].first == "Title" && charTraitsMain[i].second >= 500) {
                preqdial->preTraits.clear();
            }

            if (charTraitsMain[i].first == "Property" && charTraitsMain[i].second >= 500) {
                preqdial->preTraits.clear();
            }
        }
    }

    if(earlyChildNameMain.first == "White Collar") {
        for(int i = 0; i < charTraitsMain.size(); i++) {
            if (charTraitsMain[i].first == "Wealth" && charTraitsMain[i].second >= 300) {
                preqdial->preTraits.clear();
            }

            if (charTraitsMain[i].first == "Property" && charTraitsMain[i].second >= 300) {
                preqdial->preTraits.clear();
            }
        }
    }

    if(realLifeMain == "Covert Operations") {
        for(int i = 0; i < charTraitsMain.size(); i++) {
            if (charTraitsMain[i].first == "Connections" && charTraitsMain[i].second >= 150) {
                preqdial->preTraits.clear();
                preqdial->preSkills.clear();
            }

            if (charSkillsMain[i].first == "Leadership" && charSkillsMain[i].second >= 150) {
                preqdial->preTraits.clear();
                preqdial->preSkills.clear();
            }
        }
    }

    preqdial->earlyChild = earlyChildNameMain.first;
    preqdial->realLife = realLifeMain;

    if (!preqdial->preAttr.isEmpty()) {
        check = true;
    }

    if (!preqdial->preTraits.isEmpty()) {
        check = true;
    }

    if (!preqdial->preSkills.isEmpty()) {
        check = true;
    }

    return check;
}


void MainWindow::on_actionPrint_triggered()
{
    if(charSkillsMain.count() > 67) {
        QMessageBox::warning(this, tr("WARNING"),tr("The sheet contains in itself only 67 skills which it is possible to print. Delete the superfluous!"));
    }

    if(charTraitsMain.count() > 30) {
        QMessageBox::warning(this, tr("WARNING"),tr("The sheet contains in itself only 30 traits which it is possible to print. Delete the superfluous!"));
    }

    if (!CheckPrereq()) {
        if(ui->statusXPAttrMain->text().toInt() >= 0) {
            if(ui->cbillsEq->text().toInt() >= 0) {
                PrintSheet();
            } else {
                QMessageBox::warning(this, tr("WARNING"),tr("You money have less than zero. That there was a possibility to print sheet, it is necessary for you to have money more or equal to zero. If you have more money - use GM Tools."));
            }

        } else {
            QMessageBox::warning(this, tr("WARNING"),tr("You XP have less than zero. That there was a possibility to print sheet, it is necessary for you to have XP more or equal to zero. If you have more XP - use GM Tools."));
        }
    } else {
        on_actionCheck_Wizard_triggered();
    }



}



void MainWindow::on_actionAbout_triggered()
{
    about = new About;
    about->ver = SHORTVER;
    about->InitAbout();
    about->show();
    about->raise();
    about->activateWindow();
    about->exec();

}

void MainWindow::on_DeleteSkillMain_clicked()
{
    int row = ui->SkillChrTableMain->currentRow();
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillChrTableMain->item(row, 0);

    QList<QPair<QString, int> > charSkillsMainSwp;
    charSkillsMainSwp.clear();

    if(skillName != 0x0) {
        for(int i = 0; i < charSkillsMain.count(); i++) {
            if(skillName->text() != charSkillsMain[i].first) {
                charSkillsMainSwp.append(qMakePair(charSkillsMain[i].first,charSkillsMain[i].second));
            }
        }
        charSkillsMain = charSkillsMainSwp;
    }



    ChangeMain();
}

void MainWindow::on_DeleteTraitsMain_clicked()
{
    int row = ui->TraitChrTableMain->currentRow();
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitChrTableMain->item(row, 0);

    QList<QPair<QString, int> > charTraitsMainSwp;
    charTraitsMainSwp.clear();

    if(traitName != 0x0) {
        for(int i = 0; i < charTraitsMain.count(); i++) {
            if(traitName->text() != charTraitsMain[i].first) {
                charTraitsMainSwp.append(qMakePair(charTraitsMain[i].first,charTraitsMain[i].second));
            }
        }
        charTraitsMain = charTraitsMainSwp;
    }

    ChangeMain();
}

void MainWindow::PrintSheet() {
    int charNumber = QDateTime::currentDateTime().toTime_t();

    QPrintDialog printDialog(&printer, this);

    printer.setPaperSize(QPrinter::Letter);
    printer.setOrientation(QPrinter::Portrait);

//    QPrintPreviewDialog printDialog(&printer, this);

    if(printDialog.exec()) {

        QImage img;
        img.load(":/img/top_page_sheet_pic.png");
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
        painter.setFont(QFont("Arial",30, QFont::StyleNormal));
        painter.drawText(300,578,img.height(), img.width(),0,charNameMain);
        painter.drawText(340,645,img.height(), img.width(),0,QString::number(heightMain));
        painter.drawText(1000,645,img.height(), img.width(),0,QString::number(weightMain));
        painter.setFont(QFont("Arial",20, QFont::StyleNormal));
        painter.drawText(1550,650,img.height(), img.width(),0,ui->AffilationMain->currentText() + " / " + ui->SubAffilationMain->currentText());
        painter.setFont(QFont("Arial",30, QFont::StyleNormal));
        painter.drawText(320,712,img.height(), img.width(),0,ui->HairColorMain->currentText());
        painter.drawText(960,712,img.height(), img.width(),0,ui->EyeColorMain->currentText());

        painter.drawText(490,968,img.height(), img.width(),0,ui->ScoreSTRMain->text());
        painter.drawText(745,968,img.height(), img.width(),0,ui->LinkSTRMain->text());
        painter.drawText(995,968,img.height(), img.width(),0,QString::number(ui->STRSpinBoxMain->value()));

        painter.drawText(490,1018,img.height(), img.width(),0,ui->ScoreBODMain->text());
        painter.drawText(745,1018,img.height(), img.width(),0,ui->LinkBODMain->text());
        painter.drawText(995,1018,img.height(), img.width(),0,QString::number(ui->BODSpinBoxMain->value()));

        painter.drawText(490,1065,img.height(), img.width(),0,ui->ScoreRFLMain->text());
        painter.drawText(745,1065,img.height(), img.width(),0,ui->LinkRFLMain->text());
        painter.drawText(995,1065,img.height(), img.width(),0,QString::number(ui->RFLSpinBoxMain->value()));

        painter.drawText(490,1112,img.height(), img.width(),0,ui->ScoreDEXMain->text());
        painter.drawText(745,1112,img.height(), img.width(),0,ui->LinkDEXMain->text());
        painter.drawText(995,1112,img.height(), img.width(),0,QString::number(ui->DEXSpinBoxMain->value()));

        painter.drawText(490,1161,img.height(), img.width(),0,ui->ScoreINTMain->text());
        painter.drawText(745,1161,img.height(), img.width(),0,ui->LinkINTMain->text());
        painter.drawText(995,1161,img.height(), img.width(),0,QString::number(ui->INTSpinBoxMain->value()));

        painter.drawText(490,1209,img.height(), img.width(),0,ui->ScoreWILMain->text());
        painter.drawText(745,1209,img.height(), img.width(),0,ui->LinkWILMain->text());
        painter.drawText(995,1209,img.height(), img.width(),0,QString::number(ui->WILSpinBoxMain->value()));

        painter.drawText(490,1257,img.height(), img.width(),0,ui->ScoreCHAMain->text());
        painter.drawText(745,1257,img.height(), img.width(),0,ui->LinkCHAMain->text());
        painter.drawText(995,1257,img.height(), img.width(),0,QString::number(ui->CHASpinBoxMain->value()));

        painter.drawText(490,1305,img.height(), img.width(),0,ui->ScoreEDGMain->text());
        painter.drawText(745,1305,img.height(), img.width(),0,ui->LinkEDGMain->text());
        painter.drawText(995,1305,img.height(), img.width(),0,QString::number(ui->EDGSpinBoxMain->value()));

        painter.drawText(1535,1243,img.height(), img.width(),0,ui->WalkMain->text());
        painter.drawText(1525,1303,img.height(), img.width(),0,ui->RunEvadeMain->text());
        painter.drawText(1525,1363,img.height(), img.width(),0,ui->SprintMain->text());

        painter.drawText(2085,1243,img.height(), img.width(),0,ui->ClimbMain->text());
        painter.drawText(2085,1303,img.height(), img.width(),0,ui->CrawlMain->text());
        painter.drawText(2085,1363,img.height(), img.width(),0,ui->SwimMain->text());


        int yTraits = 1498;
        for(int i =0; i < charTraitsMain.count(); i++) {
            yTraits += 54;
            if(i <= 7) {
                painter.drawText(150, yTraits, img.height(), img.width(),0,charTraitsMain[i].first);
                painter.drawText(715, yTraits, img.height(), img.width(),0,QString::number(CheckTraitLvl(charTraitsMain[i].first, charTraitsMain[i].second)));

                for(int j = 0 ; j < loadres->traitsList.count(); j++) {

                    QStringList hardName = charTraitsMain[i].first.split("/");
                    if ( hardName.count() == 2) {
                        if(hardName[0] == loadres->traitsList[j].first) {
                            painter.drawText(825, yTraits, img.height(), img.width(),0, loadres->traitsList[j].second);
                        }
                    } else {
                        if(charTraitsMain[i].first == loadres->traitsList[j].first) {
                            painter.drawText(825, yTraits, img.height(), img.width(),0, loadres->traitsList[j].second);
                        }
                    }

                }

                painter.drawText(1010, yTraits, img.height(), img.width(),0,QString::number(charTraitsMain[i].second));
            }
        }

        int ySkillsFirst = 2107;
        int ySkillsSecond = 2107;

        for(int i = 0; i < charSkillsMain.count(); i++) {
            if(i <= 14) {
                ySkillsFirst += 68;
                painter.drawText(150, ySkillsFirst, img.height(), img.width(),0,charSkillsMain[i].first);
                painter.drawText(718, ySkillsFirst, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[i].second)));

                for(int j = 0 ; j < loadres->skillsList.count(); j++) {
                    QStringList hardName = charSkillsMain[i].first.split("/");
                    if (hardName.count() == 2) {
                        if(hardName[0] == loadres->skillsList[j].first.split("/")[0]) {
                            QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                            if( linkPart.count() == 2) {
                                if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                                    linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                                }
                                painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                painter.drawText(800, ySkillsFirst, img.height(), img.width(),0,linkPart[0]);
                                painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                if(tnc.count() == 2) {
                                    painter.drawText(955, ySkillsFirst, img.height(), img.width(),0,tnc[0]);
                                    painter.drawText(1036, ySkillsFirst, img.height(), img.width(),0,tnc[1]);
                                }

                            }
                        }
                    } else {
                        if(charSkillsMain[i].first == loadres->skillsList[j].first) {
                            QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                            if( linkPart.count() == 2) {
                                if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                                    linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                                }
                                painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                painter.drawText(800, ySkillsFirst, img.height(), img.width(),0,linkPart[0]);
                                painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                if(tnc.count() == 2) {
                                    painter.drawText(955, ySkillsFirst, img.height(), img.width(),0,tnc[0]);
                                    painter.drawText(1036, ySkillsFirst, img.height(), img.width(),0,tnc[1]);
                                }

                            }
                        }
                    }


                }

                painter.drawText(1115, ySkillsFirst, img.height(), img.width(),0,QString::number(charSkillsMain[i].second));
            }

            if (i > 14 && i <= 29){
                ySkillsSecond += 68;
                painter.drawText(1280, ySkillsSecond, img.height(), img.width(),0,charSkillsMain[i].first);
                painter.drawText(1848, ySkillsSecond, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[i].second)));

                for(int j = 0 ; j < loadres->skillsList.count(); j++) {
                    QStringList hardName = charSkillsMain[i].first.split("/");
                    if (hardName.count() == 2) {
                        if(hardName[0] == loadres->skillsList[j].first.split("/")[0]) {
                            QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                            if( linkPart.count() == 2) {
                                painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                painter.drawText(1930, ySkillsSecond, img.height(), img.width(),0,linkPart[0]);
                                painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                if(tnc.count() == 2) {
                                    painter.drawText(2085, ySkillsSecond, img.height(), img.width(),0,tnc[0]);
                                    painter.drawText(2166, ySkillsSecond, img.height(), img.width(),0,tnc[1]);
                                }

                            }
                        }
                    } else {
                        if(charSkillsMain[i].first == loadres->skillsList[j].first) {
                            QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                            if( linkPart.count() == 2) {
                                painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                painter.drawText(1930, ySkillsSecond, img.height(), img.width(),0,linkPart[0]);
                                painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                if(tnc.count() == 2) {
                                    painter.drawText(2085, ySkillsSecond, img.height(), img.width(),0,tnc[0]);
                                    painter.drawText(2166, ySkillsSecond, img.height(), img.width(),0,tnc[1]);
                                }

                            }
                        }
                    }

                }

                painter.drawText(2245, ySkillsSecond, img.height(), img.width(),0,QString::number(charSkillsMain[i].second));
            }

        }

        QMapIterator <QString, QString> g(loc);
        while(g.hasNext()) {
            g.next();
            if( g.key() == "Torso" ) {
                QStringList armor = g.value().split("/",QString::SkipEmptyParts);
                painter.drawText(1320, 1473, img.height(), img.width(),0,armor[0]);
                painter.drawText(1770, 1473, img.height(), img.width(),0,armor[1]);
                for( int i = 0; i < equipChar.count(); i++) {
                    if(g.value() == equipChar[i][0]) {
                        QStringList defence = equipChar[i][4].split("/",QString::SkipEmptyParts);
                        painter.drawText(2105, 1473, img.height(), img.width(),0,defence[0]);
                        painter.drawText(2163, 1473, img.height(), img.width(),0,defence[1]);
                        painter.drawText(2218, 1473, img.height(), img.width(),0,defence[2]);
                        painter.drawText(2275, 1473, img.height(), img.width(),0,defence[3]);
                    }
                }
            }

            if( g.key() == "Head" ) {
                QStringList armor = g.value().split("/",QString::SkipEmptyParts);
                painter.drawText(1220, 1540, img.height(), img.width(),0,armor[0]);
                painter.drawText(1770, 1540, img.height(), img.width(),0,armor[1]);
                painter.drawText(1560, 1540, img.height(), img.width(),0,"Head");
                for( int i = 0; i < equipChar.count(); i++) {
                    if(g.value() == equipChar[i][0]) {
                        QStringList defence = equipChar[i][4].split("/",QString::SkipEmptyParts);
                        painter.drawText(2105, 1540, img.height(), img.width(),0,defence[0]);
                        painter.drawText(2163, 1540, img.height(), img.width(),0,defence[1]);
                        painter.drawText(2218, 1540, img.height(), img.width(),0,defence[2]);
                        painter.drawText(2275, 1540, img.height(), img.width(),0,defence[3]);
                    }
                }
            }

            if( g.key() == "Arms" ) {
                QStringList armor = g.value().split("/",QString::SkipEmptyParts);
                painter.drawText(1220, 1605, img.height(), img.width(),0,armor[0]);
                painter.drawText(1770, 1605, img.height(), img.width(),0,armor[1]);
                painter.drawText(1560, 1605, img.height(), img.width(),0,"Arms");
                for( int i = 0; i < equipChar.count(); i++) {
                    if(g.value() == equipChar[i][0]) {
                        QStringList defence = equipChar[i][4].split("/",QString::SkipEmptyParts);
                        painter.drawText(2105, 1605, img.height(), img.width(),0,defence[0]);
                        painter.drawText(2163, 1605, img.height(), img.width(),0,defence[1]);
                        painter.drawText(2218, 1605, img.height(), img.width(),0,defence[2]);
                        painter.drawText(2275, 1605, img.height(), img.width(),0,defence[3]);
                    }
                }
            }

            if( g.key() == "Legs" ) {
                QStringList armor = g.value().split("/",QString::SkipEmptyParts);
                painter.drawText(1220, 1670, img.height(), img.width(),0,armor[0]);
                painter.drawText(1770, 1670, img.height(), img.width(),0,armor[1]);
                painter.drawText(1560, 1670, img.height(), img.width(),0,"Legs");
                for( int i = 0; i < equipChar.count(); i++) {
                    if(g.value() == equipChar[i][0]) {
                        QStringList defence = equipChar[i][4].split("/",QString::SkipEmptyParts);
                        painter.drawText(2105, 1670, img.height(), img.width(),0,defence[0]);
                        painter.drawText(2163, 1670, img.height(), img.width(),0,defence[1]);
                        painter.drawText(2218, 1670, img.height(), img.width(),0,defence[2]);
                        painter.drawText(2275, 1670, img.height(), img.width(),0,defence[3]);
                    }
                }
            }

        }

        int unarmDmg = ui->ScoreSTRMain->text().toInt() / 4;
        float ostatok = ui->ScoreSTRMain->text().toInt() / 4.0 - unarmDmg;
        if(ostatok > 0) {
            unarmDmg = unarmDmg + 1;
        }

        painter.drawText(1540, 1790, img.height(), img.width(),0,"0");
        painter.drawText(1630, 1790, img.height(), img.width(),0,QString::number(unarmDmg));

        for(int i = 0; i < charSkillsMain.count(); i++) {
            if(charSkillsMain[0].first == "Martial Arts") {
                painter.drawText(1490, 1790, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[i].second)));
            } else {
                painter.drawText(1490, 1790, img.height(), img.width(),0,"0");
            }
        }



//        int countWeapon=0;
        int yWeapon = 1790;
        for(int i = 0; i < youWeapon.count(); i++) {

            yWeapon+=60;
            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
            painter.drawText(1220, yWeapon, img.height(), img.width(),0,youWeapon[i][0]);
            painter.setFont(QFont("Arial",30, QFont::StyleNormal));

            QStringList damage = youWeapon[i][1].split("/",QString::SkipEmptyParts);
            painter.drawText(1540, yWeapon, img.height(), img.width(),0,damage[0]);
            painter.drawText(1630, yWeapon, img.height(), img.width(),0,damage[1]);

            for(int j=0; j < weaponChar.count(); j++) {
                if(youWeapon[i][0] == weaponChar[j][1] ) {
                    QStringList range = weaponChar[j][3].split("/",QString::SkipEmptyParts);
                    if (range.count() == 1) {
                        if(range[0] == "STR+DEX") {
                            int rangeSTRDEX = ui->ScoreSTRMain->text().toInt() + ui->ScoreDEXMain->text().toInt();
                            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                            painter.drawText(1720, yWeapon, img.height(), img.width(),0,QString::number(rangeSTRDEX));
                            painter.drawText(1772, yWeapon, img.height(), img.width(),0,QString::number(rangeSTRDEX*2));
                            painter.drawText(1830, yWeapon, img.height(), img.width(),0,QString::number(rangeSTRDEX*3));
                            painter.drawText(1881, yWeapon, img.height(), img.width(),0,QString::number(rangeSTRDEX*4));
                            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
                        } else {
                            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                            painter.drawText(1720, yWeapon, img.height(), img.width(),0,range[0]);
                            painter.drawText(1772, yWeapon, img.height(), img.width(),0,range[0]);
                            painter.drawText(1830, yWeapon, img.height(), img.width(),0,range[0]);
                            painter.drawText(1881, yWeapon, img.height(), img.width(),0,range[0]);
                            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
                        }

                    }

                    if (range.count() == 4) {
                        painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                        painter.drawText(1720, yWeapon, img.height(), img.width(),0,range[0]);
                        painter.drawText(1772, yWeapon, img.height(), img.width(),0,range[1]);
                        painter.drawText(1830, yWeapon, img.height(), img.width(),0,range[2]);
                        painter.drawText(1881, yWeapon, img.height(), img.width(),0,range[3]);
                        painter.setFont(QFont("Arial",30, QFont::StyleNormal));
                    }

                    for(int h = 0; h < charSkillsMain.count(); h++) {
                        if(charSkillsMain[h].first == weaponChar[j][0]) {
                            painter.drawText(1490, yWeapon, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[h].second)));
                        }
                    }

                    painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                    painter.drawText(1975, yWeapon, img.height(), img.width(),0,weaponChar[j][6]);

                    painter.drawText(2080, yWeapon, img.height(), img.width(),0,weaponChar[j][9]);
                    painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                }

            }


        }

        int countHP = ui->ScoreBODMain->text().toInt() * 2;

        if(countHP <= 20) {
            countHP= 20 - countHP;
            float xHP = 2333;
            for(int i = 0; i < countHP; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 966, img.height(), img.width(),0,"x");
            }
            xHP = 2333;
            for (int i = 0; i < 20; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 1000, img.height(), img.width(),0,"x");
            }
        } else {
            countHP= 40 - countHP;
            float xHP = 2333;
            for(int i = 0; i < countHP; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 1000, img.height(), img.width(),0,"x");
            }

        }

        countHP = ui->ScoreWILMain->text().toInt() * 2;

        if(countHP <= 20) {
            countHP= 20 - countHP;
            float xHP = 2333;
            for(int i = 0; i < countHP; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 1047, img.height(), img.width(),0,"x");
            }
            xHP = 2333;
            for (int i = 0; i < 20; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 1081, img.height(), img.width(),0,"x");
            }
        } else {
            countHP= 40 - countHP;
            float xHP = 2333;
            for(int i = 0; i < countHP; i++) {
                xHP=xHP-37.7;
                painter.drawText(xHP, 1081, img.height(), img.width(),0,"x");
            }

        }

        QString verStr;
        verStr = "Character created by Battletech Character Creator v.";
        verStr += SHORTVER;
        verStr += " - http://bthub.net";

        painter.drawText(600, 3300, img.height(), img.width(),0,verStr);
        QString charVer;
        charVer = "Char# ";
        charVer = charVer + QString::number(charNumber);
        painter.setFont(QFont("Arial",20, QFont::StyleNormal));
        painter.drawText(1670, 435, img.height(), img.width(),0,charVer);
        painter.setFont(QFont("Arial",30, QFont::StyleNormal));

        printer.newPage();

        img.load(":/img/back_page_sheet_pic.png");

        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);

        painter.drawText(520,640,img.height(), img.width(),0,earlyChildNameMain.first);
        painter.drawText(520,695,img.height(), img.width(),0,lateChildNameMain.first);
        painter.drawText(200,750,img.height(), img.width(),0,"School: " + schoolNameMain.first);
        painter.drawText(200,810,img.height(), img.width(),0,"Basic school: " + basicSchoolMain.first);
        painter.drawText(200,870,img.height(), img.width(),0,"Advanced school: " + advSchoolMain.first);
        painter.drawText(200,925,img.height(), img.width(),0,"Special school: " + specSchoolMain.first);
        painter.drawText(200,980,img.height(), img.width(),0,"Real Life: " + realLifeMain);

        yWeapon = 1352;
        int count = 0;
        for (int i = 0; i < weaponChar.count(); i++ ) {
            if (count <= 15) {
                yWeapon+=54;
                painter.drawText(200, yWeapon, img.height(), img.width(),0,weaponChar[i][10] + " x " + weaponChar[i][1]);
                painter.drawText(1220, yWeapon, img.height(), img.width(),0,"Dmg: " + weaponChar[i][2] + ", Ammo: " + weaponChar[i][6] + ", Range: " + weaponChar[i][3] + ", Weight: " + weaponChar[i][5]) ;
                count++;
            }
        }


        bool chkPrintEq = false;
        for (int i = 0; i < equipChar.count(); i++ ) {

            if (count <= 15) {
                yWeapon+=54;
                int xEquip = 0;
                int printCount = 0;
                QMapIterator <QString, QString> g(loc);
                while(g.hasNext()) {
                    g.next();
                    if(g.value() == equipChar[i][0]) {
                        if( printCount == 0 ) {
                            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                            painter.drawText(860, yWeapon+10, img.height(), img.width(),0, g.key());
                            painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                            painter.drawText(200, yWeapon, img.height(), img.width(),0, equipChar[i][6] + " x " +equipChar[i][0]);
                            painter.drawText(1220, yWeapon, img.height(), img.width(),0, "Def: " + equipChar[i][4] + ", Weigth: " + equipChar[i][2] + ", " + equipChar[i][5]);
                        } else {
                            xEquip += 70;
                            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                            painter.drawText(860 + xEquip, yWeapon+10, img.height(), img.width(),0,"," + g.key());
                            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
                        }
                        chkPrintEq = true;
                        printCount += 1;
                    }
                }
                if (chkPrintEq != true) {
                    painter.drawText(200, yWeapon, img.height(), img.width(),0, equipChar[i][6] + " x " +equipChar[i][0]);
                    painter.drawText(1220, yWeapon, img.height(), img.width(),0, "Def: " + equipChar[i][4] + ", Weigth: " + equipChar[i][2] + ", " + equipChar[i][5]);
                }
                count++;
                chkPrintEq = false;
            }
        }
        painter.drawText(300,2297,img.height(), img.width(),0,QString::number(cbills));
        painter.drawText(600, 3300, img.height(), img.width(),0,verStr);
        painter.setFont(QFont("Arial",20, QFont::StyleNormal));
        painter.drawText(1670, 435, img.height(), img.width(),0,charVer);
        painter.setFont(QFont("Arial",30, QFont::StyleNormal));

        if(charTraitsMain.count() > 8 || charSkillsMain.count() > 30) {
            printer.newPage();
            img.load(":/img/additional_page_sheet_pic.png");

            size.scale(rect.size(), Qt::KeepAspectRatio);
            painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
            painter.setWindow(img.rect());
            painter.drawImage(0,0,img);

            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
            painter.drawText(300,578,img.height(), img.width(),0,charNameMain);
            painter.drawText(340,645,img.height(), img.width(),0,QString::number(heightMain));
            painter.drawText(1000,645,img.height(), img.width(),0,QString::number(weightMain));
            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
            painter.drawText(1550,650,img.height(), img.width(),0,ui->AffilationMain->currentText() + " / " + ui->SubAffilationMain->currentText());
            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
            painter.drawText(320,712,img.height(), img.width(),0,ui->HairColorMain->currentText());
            painter.drawText(960,712,img.height(), img.width(),0,ui->EyeColorMain->currentText());

            int yTraitsFirst = 912;
            int yTraitsSecond = yTraitsFirst;
            for(int i =0; i < charTraitsMain.count(); i++) {
                if(i > 7 && i <= 21) {
                    yTraitsFirst += 54;
                    painter.drawText(150, yTraitsFirst, img.height(), img.width(),0,charTraitsMain[i].first);
                    painter.drawText(780, yTraitsFirst, img.height(), img.width(),0,QString::number(CheckTraitLvl(charTraitsMain[i].first, charTraitsMain[i].second)));

                    for(int j = 0 ; j < loadres->traitsList.count(); j++) {

                        QStringList hardName = charTraitsMain[i].first.split("/");
                        if ( hardName.count() == 2) {
                            if(hardName[0] == loadres->traitsList[j].first) {
                                painter.drawText(880, yTraitsFirst, img.height(), img.width(),0, loadres->traitsList[j].second);
                            }
                        } else {
                            if(charTraitsMain[i].first == loadres->traitsList[j].first) {
                                painter.drawText(880, yTraitsFirst, img.height(), img.width(),0, loadres->traitsList[j].second);
                            }
                        }

                    }

                    painter.drawText(1080, yTraitsFirst, img.height(), img.width(),0,QString::number(charTraitsMain[i].second));
                }
                else if(i > 21 && i <= 35) {
                    yTraitsSecond += 54;
                    painter.drawText(1275, yTraitsSecond, img.height(), img.width(),0,charTraitsMain[i].first);
                    painter.drawText(1930, yTraitsSecond, img.height(), img.width(),0,QString::number(CheckTraitLvl(charTraitsMain[i].first, charTraitsMain[i].second)));

                    for(int j = 0 ; j < loadres->traitsList.count(); j++) {

                        QStringList hardName = charTraitsMain[i].first.split("/");
                        if ( hardName.count() == 2) {
                            if(hardName[0] == loadres->traitsList[j].first) {
                                painter.drawText(2030, yTraitsSecond, img.height(), img.width(),0, loadres->traitsList[j].second);
                            }
                        } else {
                            if(charTraitsMain[i].first == loadres->traitsList[j].first) {
                                painter.drawText(2030, yTraitsSecond, img.height(), img.width(),0, loadres->traitsList[j].second);
                            }
                        }

                    }

                    painter.drawText(2230, yTraitsSecond, img.height(), img.width(),0,QString::number(charTraitsMain[i].second));
                }
            }

            int ySkillsFirst = 1841;
            int ySkillsSecond = 1841;

            for(int i = 0; i < charSkillsMain.count(); i++) {
                if(i >= 30 && i <= 48) {
                    ySkillsFirst += 68;
                    painter.drawText(150, ySkillsFirst, img.height(), img.width(),0,charSkillsMain[i].first);
                    painter.drawText(718, ySkillsFirst, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[i].second)));

                    for(int j = 0 ; j < loadres->skillsList.count(); j++) {
                        QStringList hardName = charSkillsMain[i].first.split("/");
                        if (hardName.count() == 2) {
                            if(hardName[0] == loadres->skillsList[j].first.split("/")[0]) {
                                QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                                if( linkPart.count() == 2) {
                                    if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                                        linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                                    }
                                    painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                    painter.drawText(800, ySkillsFirst, img.height(), img.width(),0,linkPart[0]);
                                    painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                    QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                    if(tnc.count() == 2) {
                                        painter.drawText(955, ySkillsFirst, img.height(), img.width(),0,tnc[0]);
                                        painter.drawText(1036, ySkillsFirst, img.height(), img.width(),0,tnc[1]);
                                    }

                                }
                            }
                        } else {
                            if(charSkillsMain[i].first == loadres->skillsList[j].first) {
                                QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                                if( linkPart.count() == 2) {
                                    if(!AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second)).isEmpty() ) {
                                        linkPart = AdvTried(charSkillsMain[i].first, CheckSkillLvl(charSkillsMain[i].second));
                                    }
                                    painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                    painter.drawText(800, ySkillsFirst, img.height(), img.width(),0,linkPart[0]);
                                    painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                    QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                    if(tnc.count() == 2) {
                                        painter.drawText(955, ySkillsFirst, img.height(), img.width(),0,tnc[0]);
                                        painter.drawText(1036, ySkillsFirst, img.height(), img.width(),0,tnc[1]);
                                    }

                                }
                            }
                        }


                    }

                    painter.drawText(1115, ySkillsFirst, img.height(), img.width(),0,QString::number(charSkillsMain[i].second));
                }

                if (i >= 49 && i <= 67){
                    ySkillsSecond += 68;
                    painter.drawText(1280, ySkillsSecond, img.height(), img.width(),0,charSkillsMain[i].first);
                    painter.drawText(1848, ySkillsSecond, img.height(), img.width(),0,QString::number(CheckSkillLvl(charSkillsMain[i].second)));

                    for(int j = 0 ; j < loadres->skillsList.count(); j++) {
                        QStringList hardName = charSkillsMain[i].first.split("/");
                        if (hardName.count() == 2) {
                            if(hardName[0] == loadres->skillsList[j].first.split("/")[0]) {
                                QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                                if( linkPart.count() == 2) {
                                    painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                    painter.drawText(1930, ySkillsSecond, img.height(), img.width(),0,linkPart[0]);
                                    painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                    QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                    if(tnc.count() == 2) {
                                        painter.drawText(2085, ySkillsSecond, img.height(), img.width(),0,tnc[0]);
                                        painter.drawText(2166, ySkillsSecond, img.height(), img.width(),0,tnc[1]);
                                    }

                                }
                            }
                        } else {
                            if(charSkillsMain[i].first == loadres->skillsList[j].first) {
                                QStringList linkPart = loadres->skillsList[j].second.split("," ,QString::SkipEmptyParts);

                                if( linkPart.count() == 2) {
                                    painter.setFont(QFont("Arial",20, QFont::StyleNormal));
                                    painter.drawText(1930, ySkillsSecond, img.height(), img.width(),0,linkPart[0]);
                                    painter.setFont(QFont("Arial",30, QFont::StyleNormal));

                                    QStringList tnc = linkPart[1].split("/" ,QString::SkipEmptyParts);

                                    if(tnc.count() == 2) {
                                        painter.drawText(2085, ySkillsSecond, img.height(), img.width(),0,tnc[0]);
                                        painter.drawText(2166, ySkillsSecond, img.height(), img.width(),0,tnc[1]);
                                    }

                                }
                            }
                        }

                    }

                    painter.drawText(2245, ySkillsSecond, img.height(), img.width(),0,QString::number(charSkillsMain[i].second));
                }

            }


            painter.drawText(600, 3300, img.height(), img.width(),0,verStr);
            painter.setFont(QFont("Arial",20, QFont::StyleNormal));
            painter.drawText(1670, 435, img.height(), img.width(),0,charVer);
            painter.setFont(QFont("Arial",30, QFont::StyleNormal));
        }

    }



}

void MainWindow::on_actionAdd_C_Bills_triggered()
{
    gmchrtool->show();
    gmchrtool->raise();
    gmchrtool->activateWindow();
    gmchrtool->exec();
}

void MainWindow::AddGmNum() {
    countCBills += gmchrtool->addCBills;
    xpMain += gmchrtool->addXP;

    ChangeMain();
}

void MainWindow::on_HeadListMain_itemChanged(QListWidgetItem*)
{
    ui->HeadListMain->clear();
    AddInvElem(dropElem[4]);

}

void MainWindow::on_BodyListMain_itemChanged(QListWidgetItem* )
{
    ui->BodyListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_ArmLeftListMain_itemChanged(QListWidgetItem* )
{
    ui->ArmLeftListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_ArmRightListMain_itemChanged(QListWidgetItem* )
{
    ui->ArmRightListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_HandLeftListMain_itemChanged(QListWidgetItem* )
{
    ui->HandLeftListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_HandRightListMain_itemChanged(QListWidgetItem* )
{
    ui->HandRightListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_LegsListMain_itemChanged(QListWidgetItem* )
{
    ui->LegsListMain->clear();
    AddInvElem(dropElem[4]);
}

void MainWindow::on_FeetsListMain_itemChanged(QListWidgetItem* )
{
    ui->FeetsListMain->clear();
    AddInvElem(dropElem[4]);
}

QString MainWindow::BodyLoc(QString nameElem) {
    QString returnName;

    if(nameElem == "H") {
        returnName = "Head";
    }

    if(nameElem == "T") {
        returnName = "Torso";
    }

    if(nameElem == "TA") {
        returnName = "Torso,Arms";
    }

    if(nameElem == "TAL") {
        returnName = "Torso,Arms,Legs";
    }

    if(nameElem == "TAH") {
        returnName = "Torso,Arms,Head";
    }

    if(nameElem == "TOR") {
        returnName = "Torso or Legs";
    }

    if(nameElem == "HAN") {
        returnName = "Hands";
    }

    if(nameElem == "L") {
        returnName = "Legs";
    }

    if(nameElem == "F") {
        returnName = "Feet";
    }

    if(nameElem == "FUL") {
        returnName = "Full";
    }

    if (nameElem.isEmpty()) {
        returnName = "none";
    }

    return returnName;
}

void MainWindow::on_AllYouTable_cellDoubleClicked(int row, int)
{
    QTableWidgetItem *name = ui->AllYouTable->item(row,0);
    QTableWidgetItem *dmg = ui->AllYouTable->item(row,1);
    QTableWidgetItem *count = ui->AllYouTable->item(row,2);
    QTableWidgetItem *mass = ui->AllYouTable->item(row,3);
    QTableWidgetItem *locWeapon = ui->AllYouTable->item(row,4);
    if(locWeapon != 0x0) {
        if(locWeapon->text() == "Weapon") {
            if(youWeapon.count() < 3) {

                int countWeap=0;
                for(int i=0; i < youWeapon.count(); i++) {
                    if(youWeapon[i][0] == name->text()) {
                       countWeap++;
                    }
                }

                if(countWeap < count->text().toInt()) {
                    QStringList tableLine;
                    tableLine.clear();
                    tableLine << name->text() << dmg->text() << "1" << mass->text() << locWeapon->text();

                    youWeapon.append(tableLine);
                }

            }
        }
    }
    PrintYouWeapon();
}

void MainWindow::on_ItselfAllYouTable_cellDoubleClicked(int row, int)
{
    youWeapon.remove(row);
    PrintYouWeapon();
}

void MainWindow::PrintYouWeapon() {
    ui->ItselfAllYouTable->clearSpans();
    ui->ItselfAllYouTable->setRowCount(youWeapon.count());

    for(int i=0; i < youWeapon.count(); i++) {
        QTableWidgetItem *name = new QTableWidgetItem(youWeapon[i][0]);
        ui->ItselfAllYouTable->setItem(i,0,name);

        QTableWidgetItem *dmg = new QTableWidgetItem(youWeapon[i][1]);
        ui->ItselfAllYouTable->setItem(i,1,dmg);
        dmg->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *count = new QTableWidgetItem(youWeapon[i][2]);
        ui->ItselfAllYouTable->setItem(i,2,count);
        count->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *mass = new QTableWidgetItem(youWeapon[i][3]);
        ui->ItselfAllYouTable->setItem(i,3,mass);
        mass->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *locWeapon = new QTableWidgetItem(youWeapon[i][4]);
        ui->ItselfAllYouTable->setItem(i,4,locWeapon);
        locWeapon->setTextAlignment(Qt::AlignCenter);

    }

}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {

    ui->ItselfAllYouTable->setDragDropMode(QTableWidget::NoDragDrop);
    ui->HeadListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->BodyListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->ArmLeftListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->ArmRightListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->HandLeftListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->HandRightListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->LegsListMain->setDragDropMode(QListWidget::NoDragDrop);
    ui->FeetsListMain->setDragDropMode(QListWidget::NoDragDrop);

    if(event->mimeData()->hasFormat("application/x-qabstractitemmodeldatalist")) {
        QByteArray encoded = event->mimeData()->data("application/x-qabstractitemmodeldatalist");
        QDataStream stream(&encoded, QIODevice::ReadOnly);

        QMap<int,  QVariant> roleDataMap;

        dropElem.clear();
        while (!stream.atEnd())
        {

            int row, col;
            stream >> row >> col >> roleDataMap;

            /* do something with the data */

            dropElem << roleDataMap.value(0).toString();
        }
        //        nameText = list[0];

        if(dropElem[4] == "Head") {
            ui->HeadListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Torso") {
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Torso,Arms") {
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmRightListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Torso,Arms,Legs") {
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmRightListMain->setDragDropMode(QListWidget::DropOnly);
            ui->LegsListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Torso,Arms,Head") {
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmRightListMain->setDragDropMode(QListWidget::DropOnly);
            ui->HeadListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Torso or Legs") {
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
            ui->LegsListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Hands") {
            ui->HandLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->HandRightListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Legs") {
            ui->LegsListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Feet") {
            ui->FeetsListMain->setDragDropMode(QListWidget::DropOnly);
        }

        if(dropElem[4] == "Full") {
            ui->HeadListMain->setDragDropMode(QListWidget::DropOnly);
            ui->BodyListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->ArmRightListMain->setDragDropMode(QListWidget::DropOnly);
            ui->HandLeftListMain->setDragDropMode(QListWidget::DropOnly);
            ui->HandRightListMain->setDragDropMode(QListWidget::DropOnly);
            ui->LegsListMain->setDragDropMode(QListWidget::DropOnly);
            ui->FeetsListMain->setDragDropMode(QListWidget::DropOnly);
        }

    }

}


QString MainWindow::InventToolTip(QString nameElem) {

    QString textToolTip;

    for(int i = 0; i < equipChar.count(); i++) {
        if(equipChar[i][0] == nameElem) {
            QStringList cutNameList = equipChar[i][0].split("/");
            if (cutNameList.count() == 2) {
                textToolTip = "Class: " + cutNameList[0] + "\nName: " + cutNameList[1] + "\nBar: " + equipChar[i][4] + "\nWeght: " + equipChar[i][2];
            } else {
                textToolTip = "Class: " + equipChar[i][0] + "\nName: " + equipChar[i][0] + "\nBar: " + equipChar[i][4] + "\nWeght: " + equipChar[i][2];
            }


        }
    }

    return textToolTip;
}

void MainWindow::AddInvElem(QString nameElem) {

    QStringList cutNameList = dropElem[0].split("/");
    QString cutName;
    if (cutNameList.count() == 2) {
        cutName = cutNameList[1];
    } else {
        cutName = dropElem[0];
    }

    cutLocList.clear();
    cutLocList = nameElem.split(",");

    for(int i =0; i < cutLocList.count(); i++) {
        EraseLocation(cutLocList[i]);
    }

    for(int i =0; i < cutLocList.count(); i++) {

        loc[cutLocList[i]] = dropElem[0];

        if (cutLocList[i] == "Head") {
            ui->HeadListMain->clear();
            ui->HeadListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HeadListMain->addItem(cutName);
        }

        if (cutLocList[i] == "Torso") {
            ui->BodyListMain->clear();
            ui->BodyListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->BodyListMain->addItem(cutName);
        }

        if (cutLocList[i] == "Arms") {
            ui->ArmLeftListMain->clear();
            ui->ArmLeftListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->ArmLeftListMain->addItem(cutName);
            ui->ArmRightListMain->clear();
            ui->ArmRightListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->ArmRightListMain->addItem(cutName);
        }

        if (cutLocList[i] == "Hands") {
            ui->HandLeftListMain->clear();
            ui->HandLeftListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HandLeftListMain->addItem(cutName);
            ui->HandRightListMain->clear();
            ui->HandRightListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HandRightListMain->addItem(cutName);
        }

        if (cutLocList[i] == "Legs") {
            ui->LegsListMain->clear();
            ui->LegsListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->LegsListMain->addItem(cutName);

        }

        if (cutLocList[i] == "Feet") {
            ui->FeetsListMain->clear();
            ui->FeetsListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->FeetsListMain->addItem(cutName);
        }

        if (cutLocList[i] == "Full") {
            ui->HeadListMain->clear();
            ui->HeadListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HeadListMain->addItem(cutName);
            ui->BodyListMain->clear();
            ui->BodyListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->BodyListMain->addItem(cutName);
            ui->ArmLeftListMain->clear();
            ui->ArmLeftListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->ArmLeftListMain->addItem(cutName);
            ui->ArmRightListMain->clear();
            ui->ArmRightListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->ArmRightListMain->addItem(cutName);
            ui->HandLeftListMain->clear();
            ui->HandLeftListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HandLeftListMain->addItem(cutName);
            ui->HandRightListMain->clear();
            ui->HandRightListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->HandRightListMain->addItem(cutName);
            ui->LegsListMain->clear();
            ui->LegsListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->LegsListMain->addItem(cutName);
            ui->FeetsListMain->clear();
            ui->FeetsListMain->setToolTip(InventToolTip(dropElem[0]));
            ui->FeetsListMain->addItem(cutName);
        }

    }
}

void MainWindow::EraseLocation(QString name) {

    QString swploc;
    swploc.clear();
    QStringList eraseLoc;
    eraseLoc.clear();

    QMapIterator <QString, QString> h(loc);
    while(h.hasNext()) {
        h.next();
        if(h.key() == name) {
            swploc = h.value();
        }
    }

    QMapIterator <QString, QString> g(loc);
    while(g.hasNext()) {
        g.next();
        if(g.value() == swploc) {
            eraseLoc << g.key();
        }
    }

    for(int i = 0; i < eraseLoc.count(); i++) {
        if(eraseLoc[i] == "Head") {
            ui->HeadListMain->clear();
            ui->HeadListMain->setToolTip("Head");
            ui->HeadListMain->addItem("Head");
            loc["Head"] = "Head";
        }

        if (eraseLoc[i] == "Torso") {
            ui->BodyListMain->clear();
            ui->BodyListMain->setToolTip("Torso");
            ui->BodyListMain->addItem("Torso");
            loc["Torso"] = "Torso";
        }

        if (eraseLoc[i] == "Arms") {
            ui->ArmLeftListMain->clear();
            ui->ArmLeftListMain->setToolTip("Arm");
            ui->ArmLeftListMain->addItem("Arm");
            ui->ArmRightListMain->clear();
            ui->ArmRightListMain->setToolTip("Arm");
            ui->ArmRightListMain->addItem("Arm");
            loc["Arms"] = "Arms";
        }

        if (eraseLoc[i] == "Hands") {
            ui->HandLeftListMain->clear();
            ui->HandLeftListMain->setToolTip("Hand");
            ui->HandLeftListMain->addItem("Hand");
            ui->HandRightListMain->clear();
            ui->HandRightListMain->setToolTip("Hand");
            ui->HandRightListMain->addItem("Hand");
            loc["Hands"] = "Hands";
        }

        if (eraseLoc[i] == "Legs") {
            ui->LegsListMain->clear();
            ui->LegsListMain->setToolTip("Legs");
            ui->LegsListMain->addItem("Legs");
            loc["Legs"] = "Legs";
        }

        if (eraseLoc[i] == "Feet") {
            ui->FeetsListMain->clear();
            ui->FeetsListMain->setToolTip("Feet");
            ui->FeetsListMain->addItem("Feet");
            loc["Feet"] = "Feet";
        }

        if (eraseLoc[i] == "Full") {
            ui->HeadListMain->clear();
            ui->HeadListMain->setToolTip("Head");
            ui->HeadListMain->addItem("Head");
            ui->BodyListMain->clear();
            ui->BodyListMain->setToolTip("Torso");
            ui->BodyListMain->addItem("Torso");
            ui->ArmLeftListMain->clear();
            ui->ArmLeftListMain->setToolTip("Arm");
            ui->ArmLeftListMain->addItem("Arm");
            ui->ArmRightListMain->clear();
            ui->ArmRightListMain->setToolTip("Arm");
            ui->ArmRightListMain->addItem("Arm");
            ui->HandLeftListMain->clear();
            ui->HandLeftListMain->setToolTip("Hand");
            ui->HandLeftListMain->addItem("Hand");
            ui->HandRightListMain->clear();
            ui->HandRightListMain->setToolTip("Hand");
            ui->HandRightListMain->addItem("Hand");
            ui->LegsListMain->clear();
            ui->LegsListMain->setToolTip("Legs");
            ui->LegsListMain->addItem("Legs");
            ui->FeetsListMain->clear();
            ui->FeetsListMain->setToolTip("Feets");
            ui->FeetsListMain->addItem("Feets");
        }



    }
}


void MainWindow::on_HeadListMain_doubleClicked(QModelIndex index)
{
//    ui->HeadListMain->clear();
    EraseLocation("Head");
}

void MainWindow::on_BodyListMain_doubleClicked(QModelIndex index)
{
//    ui->BodyListMain->clear();
    EraseLocation("Torso");
}

void MainWindow::on_ArmLeftListMain_doubleClicked(QModelIndex index)
{
//    ui->ArmLeftListMain->clear();
    EraseLocation("Arms");
}

void MainWindow::on_ArmRightListMain_doubleClicked(QModelIndex index)
{
//    ui->ArmLeftListMain->clear();
    EraseLocation("Arms");
}

void MainWindow::on_LegsListMain_doubleClicked(QModelIndex index)
{
//    ui->LegsListMain->clear();
    EraseLocation("Legs");
}

void MainWindow::on_HandLeftListMain_doubleClicked(QModelIndex index)
{
//    ui->HandLeftListMain->clear();
    EraseLocation("Hands");
}

void MainWindow::on_HandRightListMain_doubleClicked(QModelIndex index)
{
//    ui->HandLeftListMain->clear();
    EraseLocation("Hands");
}

void MainWindow::on_FeetsListMain_doubleClicked(QModelIndex index)
{
//    ui->FeetsListMain->clear();
    EraseLocation("Feets");
}



void MainWindow::on_SkillChrTableMain_cellClicked(int row, int)
{
    QTableWidgetItem *skillName = new QTableWidgetItem;
    skillName = ui->SkillChrTableMain->item(row, 0);

    if(skillName != 0x0) {
        QTableWidgetItem *selectName = new QTableWidgetItem;
        ui->SkillAllTableMain->clearSelection();
        if(!ui->SkillAllTableMain->findItems(skillName->text().split("/")[0], Qt::MatchContains).isEmpty()) {
            selectName = ui->SkillAllTableMain->findItems(skillName->text().split("/")[0], Qt::MatchContains)[0];
            ui->SkillAllTableMain->setCurrentItem(selectName);
        }

    }
}

void MainWindow::on_TraitChrTableMain_cellClicked(int row, int)
{
    QTableWidgetItem *traitName = new QTableWidgetItem;
    traitName = ui->TraitChrTableMain->item(row, 0);

    if(traitName != 0x0) {
        QTableWidgetItem *selectName = new QTableWidgetItem;
        ui->TraitAllTableMain->clearSelection();
        if(!ui->TraitAllTableMain->findItems(traitName->text().split("/")[0], Qt::MatchContains).isEmpty()) {
            selectName = ui->TraitAllTableMain->findItems(traitName->text().split("/")[0], Qt::MatchContains)[0];
            ui->TraitAllTableMain->setCurrentItem(selectName);
        }

    }
}


QStringList MainWindow::CreateSubAffList(QString nameElem) {
    QStringList subAffList;
    if(nameElem == "Federated Suns") {
        subAffList << "None" << "Capellan March" << "Crucis March"
                << "Draconis March" << "Outback";
    }

    if(nameElem == "Cappelan Confederation") {
        subAffList << "None" << "Capellan Commonality" << "Liao Commonality"
                << "Sian Commonality" << "St. Ives Commonality"
                << "Victoria Commonality";
    }

    if(nameElem == "Draconis Combine") {
        subAffList << "None" << "Azami" << "Benjamin District"
                << "Dieron District" << "New Samarkand (Galedon) District"
                << "Pesht District";
    }

    if(nameElem == "Free Worlds League") {
        subAffList << "None" << "Marik Commonwealth" << "Principality of Regulus"
                << "Duchy of Oriente" << "Duchy of Andurien"
                << "Other FWL Worlds";
    }

    if(nameElem == "Lyran Alliance") {
        subAffList << "None" << "Alarion Province" << "Bolan Province"
                << "Coventry Province" << "Donegal Province"
                << "Skye Province";
    }

    if(nameElem == "Free Rasalhague Republic") {
            subAffList << "None" << "Clan War Expatriate" << "Ghost Bear Dominion";
    }

    if(nameElem == "Minor Periphery") {
        subAffList << "None" << "Fiefdom of Randis" << "Franklin Fiefs"
                << "Mica Majority" << "Niops Association"
                << "Rim Collection";
    }

    if(nameElem == "Major Periphery State") {
        subAffList << "None" << "Circinus Federation" << "Magistracy of Canopus"
                << "Marian Hegemony" << "Outworlds Alliance"
                << "Taurian Concordat";
    }

    if(nameElem == "Deep Periphery") {
        subAffList << "None" << "Hanseatic League" << "Castilian Principalities"
                << "Umayyad Caliphate" << "JarnFolk";
    }

    if(nameElem == "Invading Clan") {
        subAffList << "None" << "Diamond Shark" << "Ghost Bear" << "Hell's Horses"
                << "Jade Falcon" << "Nova Cat" << "Snow Raven" << "Wolf";
    }

    if(nameElem == "Homeworld Clan") {
        subAffList << "None" << "Blood Spirit" << "Cloud Cobra" << "Coyote"
                << "Fire Mandrill" << "Goliath Scorpion"
                << "Ice Hellion" << "Star Adder" << "Steel Viper";
    }

    if(nameElem == "Terran") {
        subAffList << "None" << "Belter" << "Lunar Citizen" << "Martian Citizen"
                << "Outer System Citizen" << "Terran Citizen"
                << "Venusian Citizen";
    }

    if(nameElem == "Independent") {
        subAffList << "None" << "Antallos" << "Astrokaszy" << "Generic"
                << "Mercenary" << "Pirate" << "Spacer"
                << "Tortuga";
    }



    return subAffList;
}


void MainWindow::prerqPrintTable()
{
    CheckPrereq();
//    preqdial->initPreDialog();
    ui->preqListTable->clearSpans();
    QList<QPair<QString, int> > printList;

    QMapIterator <QString, int> i(preqdial->preAttr);
    while(i.hasNext()) {
        i.next();
        printList.append(qMakePair(i.key(),i.value()));
    }

    printList = printList + preqdial->preTraits + preqdial->preSkills;


    ui->preqListTable->setRowCount(printList.count());

    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->preqListTable->setItem(sCount,0,newNameItem);
        QTableWidgetItem *newValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->preqListTable->setItem(sCount,1,newValueItem);
        newValueItem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::on_pushButton_clicked()
{
    preqdial->show();
    preqdial->raise();
    preqdial->activateWindow();

    CheckPrereq();

    preqdial->initPreDialog();

}

void MainWindow::on_SkillChrTableMain_cellChanged(int row, int column)
{
    if(column == 4) {
        QTableWidgetItem *skillName = ui->SkillChrTableMain->item(row,0);
        QTableWidgetItem *xp = ui->SkillChrTableMain->item(row,4);
        for(int i =0; i< charSkillsMain.count(); i++) {
            if(charSkillsMain[i].first == skillName->text()) {
                charSkillsMain[i].second = 0;
            }
        }
        changeSkills(skillName->text(),xp->text().toInt());
        ChangeMain();
    }
}

void MainWindow::on_TraitChrTableMain_cellChanged(int row, int column)
{
    if(column == 3) {
        QTableWidgetItem *traitName = ui->TraitChrTableMain->item(row,0);
        QTableWidgetItem *xp = ui->TraitChrTableMain->item(row,3);
        for(int i =0; i< charTraitsMain.count(); i++) {
            if(charTraitsMain[i].first == traitName->text()) {
                charTraitsMain[i].second = 0;
            }
        }
        changeTraits(traitName->text(),xp->text().toInt());
        ChangeMain();
    }
}

void MainWindow::on_actionPrint_Tables_triggered()
{
    ptrtablewin->shortver = SHORTVER;
    ptrtablewin->show();
    ptrtablewin->raise();
    ptrtablewin->activateWindow();
    ptrtablewin->exec();
}

QString MainWindow::SkillDesc(QString nameSkill) {
    QString description;

    if (skillsDescList.contains(nameSkill)){
        description = skillsDescList.value(nameSkill);
    } else {
        QStringList nameSkillswp = nameSkill.split("/" ,QString::SkipEmptyParts);
        description = skillsDescList.value(nameSkillswp[0]);
    }

    return description;
}

QString MainWindow::TraitsDesc(QString nameTraits) {

    QString description;

    if (traitsDescList.contains(nameTraits)){
        description = traitsDescList.value(nameTraits);
    } else {
        QStringList nameTraitswp = nameTraits.split("/" ,QString::SkipEmptyParts);
        description = traitsDescList.value(nameTraitswp[0]);
    }

    return description;
}
