#include "s2flexxpdialog.h"
#include "ui_s2flexxpdialog.h"

#include <QtGui>
#include <QString>

S2FlexXPDialog::S2FlexXPDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S2FlexXPDialog)
{
    ui->setupUi(this);
    S2FXDConnectEvent();
}

S2FlexXPDialog::~S2FlexXPDialog()
{
    delete ui;
}

void S2FlexXPDialog::changeEvent(QEvent *e)
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

void S2FlexXPDialog::S2FlexXPDialogInit()
{

    s2FXDFreeXPLabel = s2FXDFreeXPLabelInit;
    ui->S2FlexDialSTRLabel->setText(QString::number(s2FXDStr));
    ui->S2FlexDialBODLabel->setText(QString::number(s2FXDBod));
    ui->S2FlexDialRFLLabel->setText(QString::number(s2FXDRfl));
    ui->S2FlexDialDEXLabel->setText(QString::number(s2FXDDex));
    ui->S2FlexDialINTLabel->setText(QString::number(s2FXDInt));
    ui->S2FlexDialWILLabel->setText(QString::number(s2FXDWil));
    ui->S2FlexDialCHALabel->setText(QString::number(s2FXDCha));
    ui->S2FlexDialEDGLabel->setText(QString::number(s2FXDEdg));
    ui->S2FlexDialComBoxSkills->addItems(s2FXDAllSkills);
    ui->S2FlexDialComBoxTraits->addItems(s2FXDAllTraits);

    ui->S2FlexDialSTRSpinBox->setValue(0);
    ui->S2FlexDialBODSpinBox->setValue(0);
    ui->S2FlexDialRFLSpinBox->setValue(0);
    ui->S2FlexDialDEXSpinBox->setValue(0);
    ui->S2FlexDialINTSpinBox->setValue(0);
    ui->S2FlexDialWILSpinBox->setValue(0);
    ui->S2FlexDialCHASpinBox->setValue(0);
    ui->S2FlexDialEDGSpinBox->setValue(0);
    ui->S2FlexDialSpinBoxTraits->setValue(0);
    ui->S2FlexDialSpinBoxSkills->setValue(0);
    s2FXDTraitsXPSwpInt =0 ;
    s2FXDTraitsXPSwp = ui->S2FlexDialComBoxTraits->currentText();
    s2FXDTraits.clear();

    s2FXDSkillsXPSwpInt =0 ;
    s2FXDSkillsXPSwp = ui->S2FlexDialComBoxSkills->currentText();
    s2FXDSkills.clear();
    s2FXDCharAttr.clear();

    ui->S2FlexDialComBoxTraits->setDisabled(false);
    ui->S2FlexDialSpinBoxTraits->setDisabled(false);
    ui->S2FlexDialTraitsTable->setDisabled(false);
    ui->S2FlexDialSTRSpinBox->setDisabled(false);
    ui->S2FlexDialBODSpinBox->setDisabled(false);
    ui->S2FlexDialRFLSpinBox->setDisabled(false);
    ui->S2FlexDialDEXSpinBox->setDisabled(false);
    ui->S2FlexDialINTSpinBox->setDisabled(false);
    ui->S2FlexDialWILSpinBox->setDisabled(false);
    ui->S2FlexDialCHASpinBox->setDisabled(false);
    ui->S2FlexDialEDGSpinBox->setDisabled(false);
    ui->S2FlexDialSpinBoxTraits->setDisabled(false);
    ui->S2FlexDialSpinBoxSkills->setDisabled(false);

    S2FXDChange();


}

void S2FlexXPDialog::S2FXDChange()
{
    s2FXDTraits = S2FXDClearZero(s2FXDTraits);
    s2FXDTraitsSwp.clear();
    s2FXDTraitsSwp = s2FXDTraitsInit;
    int countTraitsXp = 0;

    s2FXDSkills = S2FXDClearZero(s2FXDSkills);
    s2FXDSkillsSwp.clear();
    s2FXDSkillsSwp = s2FXDSkillsInit;
    int countSkillsXp = 0;
    for (int i = 0; i < s2FXDTraits.count(); i++) {
        S2FXDAddTraitsFinal(s2FXDTraits[i].first, s2FXDTraits[i].second);
        countTraitsXp += s2FXDTraits[i].second;
    }

    for (int i = 0; i < s2FXDSkills.count(); i++) {
        S2FXDAddSkillsFinal(s2FXDSkills[i].first, s2FXDSkills[i].second);
        countSkillsXp += s2FXDSkills[i].second;
    }

    s2FXDFreeXPLabel = s2FXDFreeXPLabelInit - countTraitsXp - countSkillsXp
                       - ui->S2FlexDialSTRSpinBox->value() -ui->S2FlexDialBODSpinBox->value() - ui->S2FlexDialRFLSpinBox->value()
                       - ui->S2FlexDialDEXSpinBox->value() - ui->S2FlexDialINTSpinBox->value() - ui->S2FlexDialWILSpinBox->value()
                       - ui->S2FlexDialCHASpinBox->value() - ui->S2FlexDialEDGSpinBox->value();

    S2FXDDisableAll();
    ui->S2FlexDialFreeXPLabel->setText(QString::number(s2FXDFreeXPLabel));
    ui->S2FlexDialFreeXPLabel->setFont(QFont("MS Shell Dlg 2", 16, QFont::Bold));

    ui->S2FlexDialSTRLabel->setText(QString::number(s2FXDStr + ui->S2FlexDialSTRSpinBox->value()));
    ui->S2FlexDialBODLabel->setText(QString::number(s2FXDBod + ui->S2FlexDialBODSpinBox->value()));
    ui->S2FlexDialRFLLabel->setText(QString::number(s2FXDRfl + ui->S2FlexDialRFLSpinBox->value()));
    ui->S2FlexDialDEXLabel->setText(QString::number(s2FXDDex + ui->S2FlexDialDEXSpinBox->value()));
    ui->S2FlexDialINTLabel->setText(QString::number(s2FXDInt + ui->S2FlexDialINTSpinBox->value()));
    ui->S2FlexDialWILLabel->setText(QString::number(s2FXDWil + ui->S2FlexDialWILSpinBox->value()));
    ui->S2FlexDialCHALabel->setText(QString::number(s2FXDCha + ui->S2FlexDialCHASpinBox->value()));
    ui->S2FlexDialEDGLabel->setText(QString::number(s2FXDEdg + ui->S2FlexDialEDGSpinBox->value()));


    S2FXDPrintSkillsTable();
    S2FXDPrintTraitsTable();
    ui->S2FlexDialSpinBoxTraits->setMaximum(200);
    S2FXDDisableElem(s2FXDNameChillHood);
}

void S2FlexXPDialog::S2FXDPrintSkillsTable() {
    ui->S2FlexDialSkillsTable->clear();
    ui->S2FlexDialSkillsTable->setRowCount(s2FXDSkillsSwp.count());
    for(int sCount = 0 ; sCount < s2FXDSkillsSwp.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(s2FXDSkillsSwp[sCount].first);
        newSNameItem->setToolTip(SkillDesc(s2FXDSkillsSwp[sCount].first));
        ui->S2FlexDialSkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(s2FXDSkillsSwp[sCount].second));
        ui->S2FlexDialSkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void S2FlexXPDialog::S2FXDPrintTraitsTable()
{
    ui->S2FlexDialTraitsTable->clear();
    ui->S2FlexDialTraitsTable->setRowCount(s2FXDTraitsSwp.count());
    for(int sCount = 0 ; sCount < s2FXDTraitsSwp.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(s2FXDTraitsSwp[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(s2FXDTraitsSwp[sCount].first));
        ui->S2FlexDialTraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(s2FXDTraitsSwp[sCount].second));
        ui->S2FlexDialTraitsTable->setItem(sCount,1,newSValueItem);
    }

}

void S2FlexXPDialog::S2FXDConnectEvent() {
    connect(ui->S2FlexDialSpinBoxTraits, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxTraitsChange(int)) );
    connect(ui->S2FlexDialTraitsTable, SIGNAL(cellClicked(int,int)), this, SLOT(S2FXDTraitTableActing(int)));
    connect(ui->S2FlexDialComBoxTraits, SIGNAL(activated(QString)), this, SLOT(S2FXDTraitsComBoxActing(QString)));

    connect(ui->S2FlexDialSpinBoxSkills, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxSkillsChange(int)) );
    connect(ui->S2FlexDialSkillsTable, SIGNAL(cellClicked(int,int)), this, SLOT(S2FXDSkillsTableActing(int)));
    connect(ui->S2FlexDialComBoxSkills, SIGNAL(activated(QString)), this, SLOT(S2FXDSkillsComBoxActing(QString)));

    connect(ui->S2FlexDialSTRSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxSTRChange(int)) );
    connect(ui->S2FlexDialBODSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxBODChange(int)) );
    connect(ui->S2FlexDialRFLSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxRFLChange(int)) );
    connect(ui->S2FlexDialDEXSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxDEXChange(int)) );
    connect(ui->S2FlexDialINTSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxINTChange(int)) );
    connect(ui->S2FlexDialWILSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxWILChange(int)) );
    connect(ui->S2FlexDialCHASpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxCHAChange(int)) );
    connect(ui->S2FlexDialEDGSpinBox, SIGNAL(valueChanged(int)), this, SLOT(S2FXDSpinBoxEDGChange(int)) );

    connect(ui->S2FlexDialPushButtonReset, SIGNAL(clicked()), this, SLOT(S2FlexXPDialogInit()));

}


void S2FlexXPDialog::S2FXDTraitTableActing(int x){
    QTableWidgetItem *traitsName = new QTableWidgetItem;
    QTableWidgetItem *traitsAttr = new QTableWidgetItem;
    traitsName = ui->S2FlexDialTraitsTable->item(x, 0);
    traitsAttr = ui->S2FlexDialTraitsTable->item(x, 1);

    if(traitsName != 0x0) {
        s2FXDAllTraitsSwp.clear();
        ui->S2FlexDialComBoxTraits->clear();
        ui->S2FlexDialSpinBoxTraits->setMaximum(200);

        s2FXDAllTraitsSwp << traitsName->text() << s2FXDAllTraits;
        ui->S2FlexDialComBoxTraits->addItems(s2FXDAllTraitsSwp);
        if (S2FXDFind(traitsName->text(),s2FXDTraits) != 100500) {
            ui->S2FlexDialSpinBoxTraits->setValue(s2FXDTraits[S2FXDFind(traitsName->text(),s2FXDTraits)-1].second);
        } else {
            ui->S2FlexDialSpinBoxTraits->setValue(0);
        }
    }


//    S2FXDDisableElem(s2FXDNameChillHood);
}

void S2FlexXPDialog::S2FXDSkillsTableActing(int x){
    QTableWidgetItem *skillsName = new QTableWidgetItem;
    QTableWidgetItem *skillsAttr = new QTableWidgetItem;
    skillsName = ui->S2FlexDialSkillsTable->item(x, 0);
    skillsAttr = ui->S2FlexDialSkillsTable->item(x, 1);

    if(skillsName != 0x0) {
        s2FXDAllSkillsSwp.clear();
        ui->S2FlexDialComBoxSkills->clear();
        ui->S2FlexDialSpinBoxSkills->setMaximum(35);

        s2FXDAllSkillsSwp << skillsName->text() << s2FXDAllSkills;
        ui->S2FlexDialComBoxSkills->addItems(s2FXDAllSkillsSwp);
        if (S2FXDFind(skillsName->text(),s2FXDSkills) != 100500) {
            ui->S2FlexDialSpinBoxSkills->setValue(s2FXDSkills[S2FXDFind(skillsName->text(),s2FXDSkills)-1].second);
        } else {
            ui->S2FlexDialSpinBoxSkills->setValue(0);
        }
    }

}

void S2FlexXPDialog::S2FXDSpinBoxTraitsChange(int number) {
    S2FXDAddTraits(ui->S2FlexDialComBoxTraits->currentText(), number);
    S2FXDChange();

    if (s2FXDFreeXPLabel <  0) {
        ui->S2FlexDialSpinBoxTraits->setValue(0);
        S2FXDAddTraits(ui->S2FlexDialComBoxTraits->currentText(), 0);
    }

    if (s2FXDFreeXPLabel > s2FXDFreeXPLabelInit) {
        ui->S2FlexDialSpinBoxTraits->setValue(0);
    }


    S2FXDChange();

}

void S2FlexXPDialog::S2FXDSpinBoxSkillsChange(int number) {
    S2FXDAddSkills(ui->S2FlexDialComBoxSkills->currentText(), number);
     S2FXDChange();

     if (s2FXDFreeXPLabel <  0) {
         ui->S2FlexDialSpinBoxSkills->setValue(0);
         S2FXDAddSkills(ui->S2FlexDialComBoxSkills->currentText(), 0);
     }

    if (s2FXDFreeXPLabel > s2FXDFreeXPLabelInit) {
        ui->S2FlexDialSpinBoxSkills->setValue(0);
    }

    S2FXDChange();
}

void S2FlexXPDialog::S2FXDSpinBoxSTRChange(int number) {
    s2FXDCharAttr["STR"] = number;
    S2FXDChange();
    if (s2FXDFreeXPLabel < 0) {
       ui->S2FlexDialSTRSpinBox->setValue(0);
        S2FXDChange();
    }


}

void S2FlexXPDialog::S2FXDSpinBoxBODChange(int number) {
    s2FXDCharAttr["BOD"] = number;

    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
       ui->S2FlexDialBODSpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxRFLChange(int number) {
    s2FXDCharAttr["RFL"] = number;
    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialRFLSpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxDEXChange(int number) {
    s2FXDCharAttr["DEX"] = number;

    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialDEXSpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxINTChange(int number) {
    s2FXDCharAttr["INT"] = number;
    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialINTSpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxWILChange(int number) {
    s2FXDCharAttr["WIL"] = number;
    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialWILSpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxCHAChange(int number) {
    s2FXDCharAttr["CHA"] = number;
    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialCHASpinBox->setValue(0);
        S2FXDChange();
    }
}

void S2FlexXPDialog::S2FXDSpinBoxEDGChange(int number) {
    s2FXDCharAttr["EDG"] = number;
    S2FXDChange();

    if (s2FXDFreeXPLabel < 0) {
        ui->S2FlexDialEDGSpinBox->setValue(0);
        S2FXDChange();
    }
}


void S2FlexXPDialog::S2FXDDisableAll() {

    if ( s2FXDFreeXPLabel == 0) {

        ui->S2FlexDialSpinBoxTraits->setMaximum(ui->S2FlexDialSpinBoxTraits->value());
        ui->S2FlexDialSpinBoxSkills->setMaximum(ui->S2FlexDialSpinBoxSkills->value());

        ui->S2FlexDialSTRSpinBox->setMaximum(ui->S2FlexDialSTRSpinBox->value());
        ui->S2FlexDialBODSpinBox->setMaximum(ui->S2FlexDialBODSpinBox->value());
        ui->S2FlexDialRFLSpinBox->setMaximum(ui->S2FlexDialRFLSpinBox->value());
        ui->S2FlexDialDEXSpinBox->setMaximum(ui->S2FlexDialDEXSpinBox->value());
        ui->S2FlexDialINTSpinBox->setMaximum(ui->S2FlexDialINTSpinBox->value());
        ui->S2FlexDialWILSpinBox->setMaximum(ui->S2FlexDialWILSpinBox->value());
        ui->S2FlexDialCHASpinBox->setMaximum(ui->S2FlexDialCHASpinBox->value());
        ui->S2FlexDialEDGSpinBox->setMaximum(ui->S2FlexDialEDGSpinBox->value());
    } else {
        ui->S2FlexDialSpinBoxTraits->setMaximum(200);
        ui->S2FlexDialSpinBoxSkills->setMaximum(35);

        ui->S2FlexDialSTRSpinBox->setMaximum(200);
        ui->S2FlexDialBODSpinBox->setMaximum(200);
        ui->S2FlexDialRFLSpinBox->setMaximum(200);
        ui->S2FlexDialDEXSpinBox->setMaximum(200);
        ui->S2FlexDialINTSpinBox->setMaximum(200);
        ui->S2FlexDialWILSpinBox->setMaximum(200);
        ui->S2FlexDialCHASpinBox->setMaximum(200);
        ui->S2FlexDialEDGSpinBox->setMaximum(200);
    }
}

void S2FlexXPDialog::S2FXDTraitsComBoxActing(QString)
{
        ui->S2FlexDialSpinBoxTraits->setValue(0);
}

void S2FlexXPDialog::S2FXDSkillsComBoxActing(QString nameSkill)
{
    bool chksub = false;
    for (int i =0; i< s2FXSubSkillList.count(); i++) {
        if (s2FXSubSkillList.contains(nameSkill)){
            chksub = true;
        }
    }
    if(chksub) {
        subpanel = new SubSkillPanel;
        connect(subpanel, SIGNAL(accepted()), this, SLOT(S2FXDSubpanelAcceptButton()));
        subpanel->SubSkillList = s2FXSubSkillList;
        subpanel->SubSkillPanelInit(nameSkill);
        subpanel->show();
        subpanel->raise();
        subpanel->activateWindow();
    }
}

void S2FlexXPDialog::S2FXDSubpanelAcceptButton() {
    QString fullSubskill = ui->S2FlexDialComBoxSkills->currentText() + "/" + subpanel->sspSubSkillName;
    QStringList swapSkillList;
    swapSkillList.clear();
    swapSkillList = s2FXDAllSkills;
    swapSkillList.insert(0,fullSubskill);
    ui->S2FlexDialComBoxSkills->clear();
    ui->S2FlexDialComBoxSkills->addItems(swapSkillList);
    delete subpanel;
}

//изменяем трейтцы
void S2FlexXPDialog::S2FXDAddTraits(QString traitsName, int traitsXP)
{
    if (s2FXDTraits.count() == 0) {
        s2FXDTraits.append(qMakePair(traitsName, traitsXP));
    } else {
        int i = S2FXDFind(traitsName, s2FXDTraits);
        if ( i != 100500 ) {
            i--;
            s2FXDTraits[i] = qMakePair(traitsName, traitsXP);
        } else {
            s2FXDTraits.append(qMakePair(traitsName, traitsXP));
        }
    }
}

void S2FlexXPDialog::S2FXDAddTraitsFinal(QString traitsName, int traitsXP)
{
    if (s2FXDTraitsSwp.count() == 0) {
        s2FXDTraitsSwp.append(qMakePair(traitsName, traitsXP));
    } else {
        int i = S2FXDFind(traitsName, s2FXDTraitsSwp);
        if ( i != 100500 ) {
            i--;
            s2FXDTraitsSwp[i] = qMakePair(traitsName,  s2FXDTraitsSwp[i].second + traitsXP);
        } else {
            s2FXDTraitsSwp.append(qMakePair(traitsName, traitsXP));
        }
    }
}

//изменяем skils
void S2FlexXPDialog::S2FXDAddSkills(QString skillsName, int skillsXP)
{
    if (s2FXDSkills.count() == 0) {
        s2FXDSkills.append(qMakePair(skillsName, skillsXP));
    } else {
        int i = S2FXDFind(skillsName, s2FXDSkills);
        if ( i != 100500 ) {
            i--;
            s2FXDSkills[i] = qMakePair(skillsName,  skillsXP);
        } else {
            s2FXDSkills.append(qMakePair(skillsName, skillsXP));
        }
    }
}

void S2FlexXPDialog::S2FXDAddSkillsFinal(QString skillsName, int skillsXP)
{
    if (s2FXDSkillsSwp.count() == 0) {
        s2FXDSkillsSwp.append(qMakePair(skillsName, skillsXP));
    } else {
        int i = S2FXDFind(skillsName, s2FXDSkillsSwp);
        if ( i != 100500 ) {
            i--;
            s2FXDSkillsSwp[i] = qMakePair(skillsName,  s2FXDSkillsSwp[i].second + skillsXP);
        } else {
            s2FXDSkillsSwp.append(qMakePair(skillsName, skillsXP));
        }
    }
}

//ищем соответсвие
int S2FlexXPDialog::S2FXDFind(QString fTraitsName, QList<QPair<QString, int> > traitList) {
    int b=0;
    for (int i = 0; i < traitList.count(); i++) {
        b++;
        if (traitList[i].first == fTraitsName ) {
            return b;
        }
    }
    return 100500; //magic number
}

// чистим нулевые скилы
QList<QPair<QString, int> > S2FlexXPDialog::S2FXDClearZero(QList<QPair<QString, int> > listName)
{
    QList<QPair<QString, int> > swapList = listName;
    listName.clear();
    for (int i = 0; i < swapList.count(); i++) {
        if (swapList[i].second != 0) {
            listName.append(qMakePair(swapList[i].first, swapList[i].second));
        }
    }
    return listName;
}

void S2FlexXPDialog::S2FXDDisableElem(QString nameChilld) {
    if(nameChilld == "Military School") {
        ui->S2FlexDialComBoxTraits->setDisabled(true);
        ui->S2FlexDialSpinBoxTraits->setDisabled(true);
        ui->S2FlexDialTraitsTable->setDisabled(true);
        ui->S2FlexDialSTRSpinBox->setDisabled(true);
        ui->S2FlexDialBODSpinBox->setDisabled(true);
        ui->S2FlexDialRFLSpinBox->setDisabled(true);
        ui->S2FlexDialDEXSpinBox->setDisabled(true);
        ui->S2FlexDialINTSpinBox->setDisabled(true);
        ui->S2FlexDialWILSpinBox->setDisabled(true);
        ui->S2FlexDialCHASpinBox->setDisabled(true);
        ui->S2FlexDialEDGSpinBox->setDisabled(true);
        ui->S2FlexDialSpinBoxTraits->setDisabled(true);
//        ui->S2FlexDialSpinBoxSkills->setDisabled(true);
    }

    if(nameChilld == "Preparatory School") {
        int countXP = 0;
        for(int i = 0; i < s2FXDTraits.count(); ++i ) {
           countXP += s2FXDTraits[i].second;
        }
        if (countXP == 80) {
            ui->S2FlexDialSpinBoxTraits->setMaximum(ui->S2FlexDialSpinBoxTraits->value());
        }
    }

    if(nameChilld == "Spacer Family") {
        int countXP = 0;
        for(int i = 0; i < s2FXDSkills.count(); ++i ) {
           countXP += s2FXDSkills[i].second;
        }
        if (countXP == 100) {
            ui->S2FlexDialSpinBoxSkills->setMaximum(ui->S2FlexDialSpinBoxSkills->value());
        }
    }

    if(nameChilld == "Agitator") {
        ui->S2FlexDialSTRSpinBox->setMaximum(50);
        ui->S2FlexDialBODSpinBox->setMaximum(50);
        ui->S2FlexDialRFLSpinBox->setMaximum(50);
        ui->S2FlexDialDEXSpinBox->setMaximum(50);
        ui->S2FlexDialINTSpinBox->setMaximum(50);
        ui->S2FlexDialWILSpinBox->setMaximum(50);
        ui->S2FlexDialCHASpinBox->setMaximum(50);
        ui->S2FlexDialEDGSpinBox->setMaximum(50);
    }

    if(nameChilld == "Ne'er-Do-Well") {
        ui->S2FlexDialComBoxTraits->setDisabled(true);
        ui->S2FlexDialSpinBoxTraits->setDisabled(true);
        ui->S2FlexDialTraitsTable->setDisabled(true);
    }

}


QString S2FlexXPDialog::SkillDesc(QString nameSkill) {
    QString description;

    if (skillsDescList.contains(nameSkill)){
        description = skillsDescList.value(nameSkill);
    } else {
        QStringList nameSkillswp = nameSkill.split("/" ,QString::SkipEmptyParts);
        description = skillsDescList.value(nameSkillswp[0]);
    }

    return description;
}

QString S2FlexXPDialog::TraitsDesc(QString nameTraits) {

    QString description;

    if (traitsDescList.contains(nameTraits)){
        description = traitsDescList.value(nameTraits);
    } else {
        QStringList nameTraitswp = nameTraits.split("/" ,QString::SkipEmptyParts);
        description = traitsDescList.value(nameTraitswp[0]);
    }

    return description;
}
