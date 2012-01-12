#include "wizard.h"
#include "s2flexxpdialog.h"
#include "ui_wizard.h"
#include <QList>
#include <QPair>
#include <QtGui>
#include <QMap>


Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{

    ui->setupUi(this);
    ui->charNameLine->selectAll();
    txt_res = new Text_Resurce; //     
    chr_dat = new CharData; //     

    s0moredial = new S0MoreDialog(this);
    s1moredial = new S1MoreDialog(this);
    s2advdial = new S2AdvDialog(this); //      
    s2fxpdialog = new S2FlexXPDialog(this); //   FlexXP
    s2clanfield = new  S2ClanFieldDialog(this);
    s3fielddial = new S3FieldDialog;
    s4advdial = new S4AdvDial;
    carField = new CarierFields;
    loadres = new LoadResurce;

    QPushButton* button = new QPushButton();
    button->setText("< Back");
    button->setEnabled(false);
    this->setButton( QWizard::BackButton, button);

    if( loadres->loadEye() == false ) {
        qDebug() << "error open eyecolor file!";
    }

    if( loadres->loadHair() == false ) {
        qDebug() << "error open haircolor file!";
    }

    if(loadres->loadCareer() == false ) {
        qDebug() << "error open career file!";
    }

    if(loadres->loadSubSkill() == false ) {
        qDebug() << "error open subskill file!";
    }

    if(loadres->loadSkillsDesc() == false ) {
        qDebug() << "error open Skills Desc file!";
    }

    if(loadres->loadTraitsDesc() == false ) {
        qDebug() << "error open Skills Desc file!";
    }

    subSkillList = loadres->subSkillList;
    txt_res->subSkillList = subSkillList;
    skillsDescList = loadres->skillsDescList;
    traitsDescList = loadres->traitsDescList;
    s2fxpdialog->skillsDescList = skillsDescList;
    s2fxpdialog->traitsDescList = traitsDescList;


    ui->EyeComboBox->clear();
    ui->EyeComboBox->addItems(loadres->eyeList);

    ui->HairComboBox->clear();
    ui->HairComboBox->addItems(loadres->hairList);

    careerList = loadres->careerList;

    delete loadres;

    hideGUIElem();  //     STAGE0
    connectEvent(); //     STAGE0
    S1ConnectEvent(); //     STAGE1
    S2ConnectEvent(); //     STAGE2
    S3ConnectEvent(); //     STAGE3
    S4ConnectEvent(); //     STAGE4

    on_HairComboBox_activated(ui->HairComboBox->currentText());
    on_EyeComboBox_activated(ui->EyeComboBox->currentText());
    on_HeightSpinBox_valueChanged(ui->HeightSpinBox->value());
    on_WeightSpinBox_valueChanged(ui->WeightSpinBox->value());
    on_SexComboBox_activated(ui->SexComboBox->currentText());
    chr_dat->phenotype = "Phenotype/Normal Human";


}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::changeEvent(QEvent *e)
{
    QWizard::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void Wizard::MainWizard() {
    switch(this->currentId()) {
    case 1:
        changeAff(0);
        break;
    case 2:
        Stage1Main();
        break;
    case 3:
        Stage2Main();
        break;
    case 4:
        Stage3Main();
        break;
    case 5:
        Stage4Main();
        if(chr_dat->schoolName.first.isEmpty()) {

            QMessageBox msgBox;
            msgBox.setText("<b>Skip STAGE3?</b>");
            msgBox.setInformativeText("Do you want to skip STAGE3?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            msgBox.setIcon(QMessageBox::Question);
            int ret = msgBox.exec();

            switch (ret) {
            case QMessageBox::Yes:

                break;
            case QMessageBox::No:
                this->back();
                break;
            default:
                // should never be reached
                break;
            }
        }
        break;
    }
}


void Wizard::BackChange() {
    switch(this->currentId()) {
    case 1:
        S1RemoveOldParam();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        change();

        break;
    case 2:
        S2RemoveOldParam();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S1Change();
        break;
    case 3:
        S3RemoveOldParam();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S2Change();
        break;
    case 4:
        S4RemoveOldParam();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S3Change();
    }
}

void Wizard::back() {
    QMessageBox msgBox;
    msgBox.setText("<b>You are sure?</b>");
    msgBox.setInformativeText("If you change your stage module, all selections you have already made for any later stages are lost. Do you want to continue?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);
    QSpacerItem* horizontalSpacer = new QSpacerItem(500, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)msgBox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Yes:
        QWizard::back();
        BackChange();


        break;
    case QMessageBox::No:

        break;
    default:
        // should never be reached
        break;
    }


}


//    
void Wizard::connectEvent() {
    connect(ui->charNameLine, SIGNAL(editingFinished()), this, SLOT(change())); //  
    connect(ui->Aff_ComBox, SIGNAL(activated(int)),this, SLOT(changeAff(int)));
    connect(ui->lang_ZStage_ComboBox, SIGNAL(activated(QString)), this, SLOT(changeStartLang(QString)));
    connect(ui->groupComWoB, SIGNAL(clicked(bool)), this, SLOT(changeComsBox(bool)));
    connect(ui->ComBoxTried, SIGNAL(activated(QString)), this, SLOT(changeAffElem1(QString)));
    connect(ui->ComBoxFor, SIGNAL(activated(QString)), this, SLOT(changeAffElem2(QString)));
    connect(ui->Sub_Aff_ComBox, SIGNAL(activated(int)), this, SLOT(changeSubAffil(int)));
    connect(ui->ComstarRadButton, SIGNAL(toggled(bool)),this, SLOT(changeCom(bool)));
    connect(ui->WoBRadButton, SIGNAL(toggled(bool)),this, SLOT(changeWoB(bool)));
    connect(ui->ComBoxSubAff1, SIGNAL(activated(QString)), this, SLOT(changeElem1(QString)));
    connect(ui->ComBoxSubAff2, SIGNAL(activated(QString)), this, SLOT(changeElem2(QString)));
    connect(ui->ComBoxSubAff3, SIGNAL(activated(QString)), this, SLOT(changeElem3(QString)));
//    connect(ui->ComBoxSubAff4, SIGNAL(activated(QString)), this, SLOT(changeElem4(QString)));
    connect(ui->comBoxComWoB, SIGNAL(activated(QString)), this, SLOT(changeWobComBox(QString)));
    connect(this->button(QWizard::NextButton), SIGNAL(clicked()), this, SLOT(MainWizard()));
//    connect(this->button(Wizard::BackButton), SIGNAL(clicked()), this, SLOT(BackChange()));
//    connect(this->button(QWizard::FinishButton),SIGNAL(pressed()), this, SLOT(FinishWizard()));
//    connect(this, SIGNAL(accepted()), this,SLOT(FinishWizard()));
    connect(s0moredial, SIGNAL(accepted()), this, SLOT(S0AdvDialAccept()));
    connect(s0moredial, SIGNAL(rejected()), this, SLOT(S0AdvDialCancel()));
}

void Wizard::accept() {

    if(chr_dat->realLife.isEmpty()) {

        QMessageBox msgBox;
        msgBox.setText("<b>Skip STAGE4?</b>");
        msgBox.setInformativeText("Do you want to skip STAGE4?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setIcon(QMessageBox::Question);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Yes:
            QWizard::accept();
            break;
        case QMessageBox::No:

            break;
        default:
            // should never be reached
            break;
        }
    } else {
        QWizard::accept();
    }
}

void Wizard::PrereqStage() {

    QMapIterator <QString, int> s0(txt_res->s0PreAttr);
    while(s0.hasNext()) {
        s0.next();
        if (chr_dat->preCharAttr.value(s0.key()) < s0.value() ) {
            chr_dat->preCharAttr[s0.key()] = s0.value();
        }
    }

    QMapIterator <QString, int> s1(stage1->s1PreAttr);
    while(s1.hasNext()) {
        s1.next();
        if (chr_dat->preCharAttr.value(s1.key()) < s1.value() ) {
            chr_dat->preCharAttr[s1.key()] = s1.value();
        }
    }

    QMapIterator <QString, int> s2(stage2->s2PreAttr);
    while(s2.hasNext()) {
        s2.next();
        if (chr_dat->preCharAttr.value(s2.key()) < s2.value() ) {
            chr_dat->preCharAttr[s2.key()] = s2.value();
        }
    }

    QMapIterator <QString, int> s3(stage3->s3PreAttr);
    while(s3.hasNext()) {
        s3.next();
        if (chr_dat->preCharAttr.value(s3.key()) < s3.value() ) {
            chr_dat->preCharAttr[s3.key()] = s3.value();
        }
    }

    QMapIterator <QString, int> s4(stage4->s4PreAttr);
    while(s4.hasNext()) {
        s4.next();
        if (chr_dat->preCharAttr.value(s4.key()) < s4.value() ) {
            chr_dat->preCharAttr[s4.key()] = s4.value();
        }
    }


    chr_dat->preCharTraits.append(txt_res->s0PreTraits);
    chr_dat->preCharTraits.append(stage1->s1PreTraits);
    chr_dat->preCharTraits.append(stage2->s2PreTraits);
    chr_dat->preCharTraits.append(stage3->s3PreTraits);
    if(!chr_dat->realLife.isEmpty()) {
        chr_dat->preCharTraits.append(stage4->s4PreTraits);
    }


    QList<QPair<QString, int> > preSwpTraits;
    preSwpTraits = chr_dat->preCharTraits;
    chr_dat->preCharTraits.clear();

    for(int i = 0; i < preSwpTraits.count(); i++) {
        bool chk = false;
        int traitCount =0;
        for(int j = 0; j < chr_dat->preCharTraits.count(); j++ ) {
            if(preSwpTraits[i].first == chr_dat->preCharTraits[j].first ) {
                chk = true;
                ++traitCount;
            }
        }

        if(chk != true) {
            chr_dat->preCharTraits.append(preSwpTraits[i]);
        } else {
            if(preSwpTraits[i].second > chr_dat->preCharTraits[traitCount-1].second) {
                chr_dat->preCharTraits[traitCount-1].second = preSwpTraits[i].second;
            }

        }
    }


    chr_dat->preCharSkills.append(txt_res->s0PreSkills);
    chr_dat->preCharSkills.append(stage1->s1PreSkills);
    chr_dat->preCharSkills.append(stage2->s2PreSkills);
    chr_dat->preCharSkills.append(stage3->s3PreSkills);
    if(!chr_dat->realLife.isEmpty()) {
        chr_dat->preCharSkills.append(stage4->s4PreSkills);
    }
    QList<QPair<QString, int> > preSwpSkills;

    preSwpSkills = chr_dat->preCharSkills;
    chr_dat->preCharSkills.clear();


    for(int i = 0; i < preSwpSkills.count(); i++) {
        bool chk = false;
        int skillCount =0;
        for(int j = 0; j < chr_dat->preCharSkills.count(); j++ ) {
            if(preSwpSkills[i].first == chr_dat->preCharSkills[j].first ) {
                chk = true;
                ++skillCount;
            }
        }

        if(chk != true) {
            chr_dat->preCharSkills.append(preSwpSkills[i]);
        } else {
            if(preSwpSkills[i].second > chr_dat->preCharSkills[skillCount-1].second) {
                chr_dat->preCharSkills[skillCount-1].second = preSwpSkills[i].second;
            }

        }
    }


}

//!!!!!!!!!!!!--------------------STAGE0------------------------!!!!!!!!!!!!//

void Wizard::on_S0MoreButton_clicked()
{
    if(!s0moredial->s0MoreDialAttr.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialAttr.count(); i++) {
            chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] = chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] - s0moredial->s0MoreDialAttr[i].second;
        }
    }

    if(!s0moredial->s0MoreDialSkills.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialSkills.count(); i++) {
            chr_dat->changeSkills(s0moredial->s0MoreDialSkills[i].first, -s0moredial->s0MoreDialSkills[i].second);
        }
    }

    if(!s0moredial->s0MoreDialTraits.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialTraits.count(); i++) {
            chr_dat->changeTraits(s0moredial->s0MoreDialTraits[i].first, -s0moredial->s0MoreDialTraits[i].second);
        }
    }


    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    change();

    s0moredial->S0MoreDialogClear();

    s0moredial->s0affName = ui->Aff_ComBox->currentText();
    s0moredial->s0subAffName = ui->Sub_Aff_ComBox->currentText();

    s0moredial->s0MoreDialLabel1 = txt_res->subAffElem1LabelMore;
    s0moredial->s0MoreDialDrop1 = txt_res->subAffElem1More;
    s0moredial->s0Value1 = txt_res->affSkillsElem1More;

    s0moredial->s0MoreDialLabel2 = txt_res->subAffElem2LabelMore;
    s0moredial->s0MoreDialDrop2 = txt_res->subAffElem2More;
    s0moredial->s0Value2 = txt_res->affSkillsElem2More;

    s0moredial->s0MoreDialLabel3 = txt_res->subAffElem3LabelMore;
    s0moredial->s0MoreDialDrop3 = txt_res->subAffElem3More;
    s0moredial->s0Value3 = txt_res->affSkillsElem3More;

    s0moredial->s0MoreDialLabel4 = txt_res->subAffElem4LabelMore;
    s0moredial->s0MoreDialDrop4 = txt_res->subAffElem4More;
    s0moredial->s0Value4 = txt_res->affSkillsElem4More;

    s0moredial->S0MoreDialogInit();

    s0moredial->show();
    s0moredial->raise();
    s0moredial->activateWindow();
}

void Wizard::S0AdvDialAccept() {

    for(int i = 0; i < s0moredial->s0MoreDialAttr.count(); i++) {
        chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] = chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] + s0moredial->s0MoreDialAttr[i].second;
    }

    for(int i = 0; i < s0moredial->s0MoreDialSkills.count(); i++) {
        chr_dat->changeSkills(s0moredial->s0MoreDialSkills[i].first, s0moredial->s0MoreDialSkills[i].second);
    }

    for(int i = 0; i < s0moredial->s0MoreDialTraits.count(); i++) {
        chr_dat->changeTraits(s0moredial->s0MoreDialTraits[i].first, s0moredial->s0MoreDialTraits[i].second);
    }

    change();
}

void Wizard::S0AdvDialCancel() {
    s0moredial->s0MoreDialAttr.clear();
    s0moredial->s0MoreDialSkills.clear();
    s0moredial->s0MoreDialTraits.clear();
}

void Wizard::hideGUIElem()
{
        ui->ComBoxTried->setEnabled(false);
        ui->ComBoxFor->setEnabled(false);
        ui->ComBoxSubAff1->setEnabled(false);
        ui->ComBoxSubAff2->setEnabled(false);
        ui->ComBoxSubAff3->setEnabled(false);
//        ui->ComBoxSubAff4->setEnabled(false);
        ui->SubAffaddlabel1->clear();
        ui->SubAffaddlabel2->clear();
        ui->SubAffaddlabel3->clear();
//        ui->SubAffaddlabel4->clear();
        ui->ComstarRadButton->setEnabled(false);
        ui->WoBRadButton->setEnabled(false);
}

void Wizard::unchekRadButton()
{
    if ( ui->ComstarRadButton->isChecked() == true ) {
        ui->ComstarRadButton->setAutoExclusive(false);
        ui->ComstarRadButton->setChecked(false);
        ui->ComstarRadButton->setAutoExclusive(true);
    }

    if (ui->WoBRadButton->isChecked() == true) {
        ui->WoBRadButton->setAutoExclusive(false);
        ui->WoBRadButton->setChecked(false);
        ui->WoBRadButton->setAutoExclusive(true);
    }

}

void Wizard::change() {

    chr_dat->charName = ui->charNameLine->text();
    ui->groupBoxStage0->setTitle("Your Character: " + chr_dat->charName);

    // 
    ui->attrStrLabel->setText("<b>STR:</b> " + QString::number(chr_dat->charAttr.value("STR")));
    ui->attrBodLabel->setText("<b>BOD:</b> " + QString::number(chr_dat->charAttr.value("BOD")));
    ui->attrRflLabel->setText("<b>RFL:</b> " + QString::number(chr_dat->charAttr.value("RFL")));
    ui->attrDexLabel->setText("<b>DEX:</b> " + QString::number(chr_dat->charAttr.value("DEX")));
    ui->attrIntLabel->setText("<b>INT:</b>  " + QString::number(chr_dat->charAttr.value("INT")));
    ui->attrWilLabel->setText("<b>WIL:</b> " + QString::number(chr_dat->charAttr.value("WIL")));
    ui->attrChaLabel->setText("<b>CHA:</b> " + QString::number(chr_dat->charAttr.value("CHA")));
    ui->attrEdgLabel->setText("<b>EDG:</b> " + QString::number(chr_dat->charAttr.value("EDG")));
    // 

    printSkillTable();
    printTraitsTable();

}



//    XP
void Wizard::changeXP(int cXP, bool direct)
{
    if ( direct == true ) {
        chr_dat->xp = chr_dat->xp - cXP;
    } else {
        chr_dat->xp = chr_dat->xp + cXP;
    }
//    QString strXP = QString::number(chr_dat->xp);
    ui->statusXP->setText(QString::number(chr_dat->xp));
    ui->statusXP->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
}

//    STAGE: 0
void Wizard::changeAff(int subPos)
{
    chr_dat->clanCastName.first = "For Clans Only";
//    chr_dat = new CharData; //     
    ui->ComBoxTried->setDisabled(false);
    ui->ComBoxFor->setDisabled(false);
    ui->groupComWoB->setChecked(false);
    ui->ComstarRadButton->setEnabled(false);
    ui->WoBRadButton->setEnabled(false);
    ui->ComBoxSubAff1->setDisabled(true);
    ui->ComBoxSubAff2->setDisabled(true);
    ui->ComBoxSubAff3->setDisabled(true);
    ui->S0MoreButton->setDisabled(true);
//    ui->ComBoxSubAff4->setDisabled(true);
    ui->ComBoxSubAff1->clear();
    ui->ComBoxSubAff2->clear();
    ui->ComBoxSubAff3->clear();
//    ui->ComBoxSubAff4->clear();

    swpAffSkillsElem1.clear();
    swpAffSkillsElem1Int = 0;
    swpAffTraitsElem1.clear();
    swpAffTraitsElem1Int = 0;

    swpAffSkillsElem2.clear();
    swpAffSkillsElem2Int = 0;
    swpAffTraitsElem2.clear();
    swpAffTraitsElem2Int = 0;

    swpAffSkillsElem3.clear();
    swpAffSkillsElem3Int = 0;
    swpAffTraitsElem3.clear();
    swpAffTraitsElem3Int = 0;

//    swpAffSkillsElem4.clear();
//    swpAffSkillsElem4Int = 0;
//    swpAffTraitsElem4.clear();
//    swpAffTraitsElem4Int = 0;

    swpFXAttr.clear();
    swpComElem.clear();

    if(!s0moredial->s0MoreDialAttr.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialAttr.count(); i++) {
            chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] = chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] - s0moredial->s0MoreDialAttr[i].second;
        }
        s0moredial->s0MoreDialAttr.clear();
    }

    if(!s0moredial->s0MoreDialSkills.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialSkills.count(); i++) {
            chr_dat->changeSkills(s0moredial->s0MoreDialSkills[i].first, -s0moredial->s0MoreDialSkills[i].second);
        }
        s0moredial->s0MoreDialSkills.clear();
    }

    if(!s0moredial->s0MoreDialTraits.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialTraits.count(); i++) {
            chr_dat->changeTraits(s0moredial->s0MoreDialTraits[i].first, -s0moredial->s0MoreDialTraits[i].second);
        }
        s0moredial->s0MoreDialTraits.clear();
    }

    unchekRadButton();
    chr_dat->clearChar(); //    
    ui->Sub_Aff_ComBox->clear(); //    SubAff
    ui->lang_ZStage_ComboBox->clear(); //    Language
    ui->SubAffaddlabel1->clear();
    ui->SubAffaddlabel2->clear();
    ui->SubAffaddlabel3->clear();

    txt_res->rSubAff(subPos); //   
    ui->Sub_Aff_ComBox->addItems(txt_res->subAffList); //   
    ui->Aff_ComBox->setToolTip(txt_res->toolTipAff); //  
    ui->Over_Aff_editText->setText(txt_res->ower_Affil);
    ui->lang_ZStage_ComboBox->addItems(txt_res->listLang); //  
    ui->lang_ZStage_ComboBox->insertSeparator(1);
    addAffElem(subPos);
    addAfillTraits();
    addAfillSkill();
    initStartLang(txt_res->listLang);
    changeXP(txt_res->xpCostModule,true);
    txt_res->affAttr.clear();
    txt_res->affSkills.clear();
    txt_res->affTraits.clear();
    change();

    chr_dat->AffName.first = ui->Aff_ComBox->currentText();
    chr_dat->AffName.second = ui->Aff_ComBox->currentIndex();
}

//  
void Wizard::changeStartLang(QString str) {
    chr_dat->changeSkills(str, 20);
    chr_dat->changeSkills(swpLang, -20);
    int posNullLang=0;
    posNullLang = chr_dat->findSkill(swpLang)-1;
    if (chr_dat->charSkills[posNullLang].second <= 0) {
        chr_dat->charSkills.removeAt(posNullLang);
        ui->SkillsTable->clear();
    }
    swpLang = str;
    change();
}

//    
void Wizard::initStartLang(QStringList lLang)
{
    QString strswap;
    strswap = lLang[0];
    swpLang = strswap;
    chr_dat->changeSkills(swpLang, 20);

    if (txt_res->elem1XPTraits != 0) {
        chr_dat->changeTraits(ui->ComBoxTried->currentText(),txt_res->elem1XPTraits);
        swpElem1Traits = ui->ComBoxTried->currentText();
    }
    if (txt_res->elem1XPSkills != 0) {
        chr_dat->changeSkills(ui->ComBoxTried->currentText(),txt_res->elem1XPSkills);
        swpElem1Skills = ui->ComBoxTried->currentText();
    }

    if (txt_res->elem2XPTraits != 0) {
        chr_dat->changeTraits(ui->ComBoxFor->currentText(),txt_res->elem2XPTraits);
        swpElem2Traits = ui->ComBoxFor->currentText();
    }
    if (txt_res->elem2XPSkills != 0) {
        chr_dat->changeSkills(ui->ComBoxFor->currentText(),txt_res->elem2XPSkills);
        swpElem2Skills = ui->ComBoxFor->currentText();
    }
    changeXP(calculateXP(),true); //        XP
}



//changeAffElem1
void Wizard::changeAffElem1(QString str) {


    ui->ComBoxSubAff3->clear();
//    ui->ComBoxSubAff4->clear();

    if(ui->Aff_ComBox->currentIndex() == 9 || ui->Aff_ComBox->currentIndex() == 10) {

        if( ui->Sub_Aff_ComBox->currentText() == "Goliath Scorpion" && ui->ComBoxTried->currentIndex() == 4) {
            ui->lang_ZStage_ComboBox->clear();
            txt_res->listLang << "Language/Goliath Scorpion Battle Language";
            ui->lang_ZStage_ComboBox->addItems(txt_res->listLang);
            ui->lang_ZStage_ComboBox->insertSeparator(1);
        }

        removeOldParamCast();
        if(!s0moredial->s0MoreDialAttr.isEmpty()) {
            for(int i = 0; i < s0moredial->s0MoreDialAttr.count(); i++) {
                chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] = chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] - s0moredial->s0MoreDialAttr[i].second;
            }
            s0moredial->s0MoreDialAttr.clear();
        }

        if(!s0moredial->s0MoreDialSkills.isEmpty()) {
            for(int i = 0; i < s0moredial->s0MoreDialSkills.count(); i++) {
                chr_dat->changeSkills(s0moredial->s0MoreDialSkills[i].first, -s0moredial->s0MoreDialSkills[i].second);
            }
            s0moredial->s0MoreDialSkills.clear();
        }

        if(!s0moredial->s0MoreDialTraits.isEmpty()) {
            for(int i = 0; i < s0moredial->s0MoreDialTraits.count(); i++) {
                chr_dat->changeTraits(s0moredial->s0MoreDialTraits[i].first, -s0moredial->s0MoreDialTraits[i].second);
            }
            s0moredial->s0MoreDialTraits.clear();
        }

        txt_res->clanCaste(str);

        if(!txt_res->subAffElem1LabelMore.isEmpty()) {
            ui->S0MoreButton->setDisabled(false);
        } else {
            ui->S0MoreButton->setDisabled(true);
        }

        QMapIterator <QString, int> i(txt_res->affAttrCast);
        while(i.hasNext()) {
            i.next();
            chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] + i.value();
        }

        int swapCount = txt_res->affSkillsCast.count();
        for(int sCount = 0 ; sCount < swapCount ; sCount++) {
            chr_dat->changeSkills(txt_res->affSkillsCast[sCount].first,txt_res->affSkillsCast[sCount].second);

        }
        swapCount = txt_res->affTraitsCast.count();
        for(int sCount = 0 ; sCount < swapCount ; sCount++) {
            chr_dat->changeTraits(txt_res->affTraitsCast[sCount].first,txt_res->affTraitsCast[sCount].second);
        }

        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();

        if( txt_res->subAffElem3.count() != 0) {
            ui->ComBoxSubAff3->setEnabled(true);
            ui->SubAffaddlabel3->setText(txt_res->subAffElem3Label);
            ui->ComBoxSubAff3->addItems(txt_res->subAffElem3);
        } else {
            ui->ComBoxSubAff3->setEnabled(false);
            ui->ComBoxSubAff3->clear();
            ui->SubAffaddlabel3->clear();
        }
//        if( txt_res->subAffElem4.count() != 0) {
//            ui->ComBoxSubAff4->setEnabled(true);
//            ui->SubAffaddlabel4->setText(txt_res->subAffElem4Label);
//            ui->ComBoxSubAff4->addItems(txt_res->subAffElem4);
//        } else {
//            ui->ComBoxSubAff4->setEnabled(false);
//            ui->ComBoxSubAff4->clear();
//            ui->SubAffaddlabel4->clear();
//        }
        changeElem3main(ui->ComBoxSubAff3->currentText());
//        changeElem4(ui->ComBoxSubAff4->currentText());
        chr_dat->clanCastName.first = ui->ComBoxTried->currentText();
        chr_dat->clanCastName.second = ui->ComBoxTried->currentIndex();
    } else {
        if (txt_res->elem1XPSkills != 0) {
            chr_dat->changeSkills(str, txt_res->elem1XPSkills);
            chr_dat->changeSkills(swpElem1Skills, -txt_res->elem1XPSkills);
            int posNullLang = chr_dat->findSkill(swpElem1Skills)-1;
            if (chr_dat->charSkills[posNullLang].second == 0) {
                chr_dat->charSkills.removeAt(posNullLang);
                ui->SkillsTable->clear();
            }
            swpElem1Skills = str;
        }


        if (txt_res->elem1XPTraits != 0) {
            chr_dat->changeTraits(str, txt_res->elem1XPTraits);
            chr_dat->changeTraits(swpElem1Traits, -txt_res->elem1XPTraits);
            int posNullLang = chr_dat->findTraits(swpElem1Traits)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
            swpElem1Traits = str;
        }
        if(ui->Aff_ComBox->currentIndex() == 11) {
            ++txt_res->countElem2;
            if(txt_res->countElem2 == 2) {
                ui->ComBoxTried->setDisabled(true);

            }

            for (int i =0; i < txt_res->affElem2.size(); i++) {
                if (txt_res->affElem2.at(i) == str) {
                    txt_res->affElem2.removeAt(i);
                    ui->ComBoxTried->clear();
                    ui->ComBoxTried->addItems(txt_res->affElem2);
                }
            }
            chr_dat->charAttr[str] = chr_dat->charAttr.value(str) + 50;

        }

    }
    change();
}

//changeAffElem2
void Wizard::changeAffElem2(QString str)
{
    if (txt_res->elem2XPSkills != 0) {
        chr_dat->changeSkills(str, txt_res->elem2XPSkills);
        chr_dat->changeSkills(swpElem2Skills, -txt_res->elem2XPSkills);
        int posNullLang = chr_dat->findSkill(swpElem2Skills)-1;
        if (chr_dat->charSkills[posNullLang].second == 0) {
            chr_dat->charSkills.removeAt(posNullLang);
            ui->SkillsTable->clear();
        }
        swpElem2Skills = str;
    }


    if (txt_res->elem2XPTraits != 0) {
        chr_dat->changeTraits(str, txt_res->elem2XPTraits);
        chr_dat->changeTraits(swpElem1Traits, -txt_res->elem2XPTraits);
        int posNullLang = chr_dat->findTraits(swpElem1Traits)-1;
        if (chr_dat->charTraits[posNullLang].second == 0) {
            chr_dat->charTraits.removeAt(posNullLang);
            ui->TraitsTable->clear();
        }
        swpElem2Traits = str;
    }
    if(ui->Aff_ComBox->currentIndex() == 11) {
        ++txt_res->countElem1;
        txt_res->swpLang << str;
        if(txt_res->countElem1 == 2) {
            ui->ComBoxFor->setDisabled(true);

            if (ui->Sub_Aff_ComBox->currentIndex() == 3 || ui->Sub_Aff_ComBox->currentIndex() == 6) {
                ui->ComBoxSubAff1->clear();
                txt_res->subAffElem1.clear();
                txt_res->subAffElem1 = txt_res->swpLang;
                ui->ComBoxSubAff1->setEnabled(true);
                ui->ComBoxSubAff1->addItems(txt_res->subAffElem1);
                changeElem1main(ui->ComBoxSubAff1->currentText());

            }
        }
        for (int i =0; i < txt_res->affElem1.size(); i++) {
            if (txt_res->affElem1.at(i) == str) {
                txt_res->affElem1.removeAt(i);
                ui->ComBoxFor->clear();
                ui->ComBoxFor->addItems(txt_res->affElem1);
            }
        }
        chr_dat->changeSkills(str, 15);
    }

    if (ui->Aff_ComBox->currentIndex() == 10 && ui->Sub_Aff_ComBox->currentIndex() == 4) {
        ++txt_res->countFMAttr;
        if (txt_res->countFMAttr == 1 ) {
            chr_dat->charAttr[str] += 75;
            ui->Affl_Add_Label_2->setText("-20 XP to any other Attribute");

            for (int i =0; i < txt_res->affElem2.size(); i++) {
                if (txt_res->affElem2.at(i) == str) {
                    txt_res->affElem2.removeAt(i);
                    ui->ComBoxFor->clear();
                }
            }
            ui->ComBoxFor->addItems(txt_res->affElem2);
        }

        if (txt_res->countFMAttr == 2) {
            chr_dat->charAttr[str] -= 20;
            ui->ComBoxFor->setEnabled(false);
        }
        swpFMAttr << str;

    }
    change();
}



//  
void Wizard::printSkillTable() {
    ui->SkillsTable->clear();
    qSort(chr_dat->charSkills.begin(),chr_dat->charSkills.end());
    ui->SkillsTable->setRowCount(chr_dat->charSkills.count());


    for(int sCount = 0 ; sCount < chr_dat->charSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charSkills[sCount].first);
        newSNameItem->setToolTip(SkillDesc(chr_dat->charSkills[sCount].first));
        ui->SkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charSkills[sCount].second));
        ui->SkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::printTraitsTable()
{
    ui->TraitsTable->clear();
    qSort(chr_dat->charTraits.begin(), chr_dat->charTraits.end());
    ui->TraitsTable->setRowCount(chr_dat->charTraits.count());

    for(int sCount = 0 ; sCount < chr_dat->charTraits.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charTraits[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(chr_dat->charTraits[sCount].first));
        ui->TraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charTraits[sCount].second));
        ui->TraitsTable->setItem(sCount,1,newSValueItem);
    }

}

//  XP
int Wizard::calculateXP()
{
    int XPcount = 0;
    // 
    QMapIterator <QString, int> i(chr_dat->charAttr);
    while(i.hasNext()) {
        i.next();
        XPcount = XPcount + i.value();
    }
// 
    for(int i =0; i < chr_dat->charSkills.count(); i++){
        XPcount = XPcount + chr_dat->charSkills[i].second;
    }
// 
    for(int i =0; i < chr_dat->charTraits.count(); i++){
        XPcount = XPcount + chr_dat->charTraits[i].second;
    }
    addAffilAttr();
    return 850;
}

void Wizard::addAffilAttr() {
//    changeXP(txt_res->xpCostModule,true);
    QMapIterator <QString, int> i(txt_res->affAttr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] + i.value();
    }
}

void Wizard::addAfillSkill()
{
    int swapCount = txt_res->affSkills.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(txt_res->affSkills[sCount].first,txt_res->affSkills[sCount].second);

    }
}

void Wizard::addAfillTraits()
{
    int swapCount = txt_res->affTraits.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeTraits(txt_res->affTraits[sCount].first,txt_res->affTraits[sCount].second);
    }
}

//    /
void Wizard::changeComsBox(bool chk)
{
    if (chk == true) {
        txt_res->swapChar();
        ui->ComstarRadButton->setEnabled(true);
        ui->WoBRadButton->setEnabled(true);

        txt_res->comstarAttr(chk);
        addAfillTraits();
        addAfillSkill();
        change();
        txt_res->restoreChar();
    } else {
        if(swpComElem.isEmpty() != true) {
            chr_dat->changeSkills(swpComElem, -txt_res->comElemInt);
            chr_dat->clearZeroSkills();
            swpComElem.clear();
        }
        unchekRadButton();
        txt_res->swapChar();
        ui->ComstarRadButton->setEnabled(false);
        ui->WoBRadButton->setEnabled(false);
        txt_res->comstarAttr(chk);
        addAfillTraits();
        addAfillSkill();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        change();
        txt_res->restoreChar();
    }
    changeXP(txt_res->xpCostModule,true);
}

void Wizard::changeCom(bool chkRadBut)
{
    chr_dat->comChk = true;
    chr_dat->wobChk = false;
    ui->comBoxComWoB->clear();
    ui->comBoxComWoB->addItems(txt_res->comElem);

    if ( chkRadBut == true) {
        changeWobComBox(ui->comBoxComWoB->currentText());
        txt_res->swapChar();
        ui->comBoxComWoB->setEnabled(true);
        txt_res->comstarSub(chkRadBut);
        addAffilAttr();
        addAfillTraits();
        addAfillSkill();
        txt_res->restoreChar();
    } else {
        txt_res->swapChar();
        ui->comBoxComWoB->setEnabled(false);
        txt_res->comstarSub(chkRadBut);
        addAffilAttr();
        addAfillTraits();
        addAfillSkill();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        txt_res->restoreChar();
    }
    change();



}

void Wizard::changeWoB(bool chkRadBut)
{
    chr_dat->comChk = false;
    chr_dat->wobChk = true;
    ui->comBoxComWoB->clear();
    ui->comBoxComWoB->addItems(txt_res->comElem);


    if ( chkRadBut == true) {
        changeWobComBox(ui->comBoxComWoB->currentText());
        txt_res->swapChar();
        ui->comBoxComWoB->setEnabled(true);
        txt_res->WoBSub(chkRadBut);
        addAffilAttr();
        addAfillTraits();
        addAfillSkill();
        txt_res->restoreChar();
    } else {
        txt_res->swapChar();
        ui->comBoxComWoB->setEnabled(false);
        txt_res->WoBSub(chkRadBut);
        addAffilAttr();
        addAfillTraits();
        addAfillSkill();
        chr_dat->clearZeroSkills();
        chr_dat->clearZeroTraits();
        txt_res->restoreChar();
    }
    change();



}

//  ,  
void Wizard::addAffElem(int posAff)
{
    ui->Affl_Add_Label->clear();
    ui->Affl_Add_Label_2->clear();
    ui->ComBoxTried->clear();
    ui->ComBoxFor->clear();
    ui->ComBoxTried->setEnabled(false);
    ui->ComBoxFor->setEnabled(false);
    ui->ComBoxTried->setEditable(false);
    ui->ComBoxFor->setEditable(false);
    switch(posAff) {
    case 0:
        ui->Affl_Add_Label->setText("Choose Natural Aptitude");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 1:
        ui->Affl_Add_Label->setText("Add Language");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 2:
        ui->Affl_Add_Label->setText("Choose one");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 3:
        ui->Affl_Add_Label->setText("Add Language");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        ui->Affl_Add_Label_2->setText("Arts");
        ui->ComBoxFor->setEnabled(true);
        ui->ComBoxFor->addItems(txt_res->affElem2);
//        ui->ComBoxFor->setEditable(true);
        break;
    case 4:
        ui->Affl_Add_Label->setText("Choose one");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 5:
        ui->Affl_Add_Label->setText("Interest");
        ui->ComBoxTried->setEnabled(true);
//        ui->ComBoxTried->setEditable(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 9:
        ui->Affl_Add_Label->setText("Castes");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 10:
        ui->Affl_Add_Label->setText("Castes");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);
        break;
    case 11:
        ui->Affl_Add_Label->setText("+50 XP each to any two Attributes");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem2);
        ui->Affl_Add_Label_2->setText("+15 XP to any two other Language");
        ui->ComBoxFor->setEnabled(true);
//        ui->ComBoxFor->setEditable(true);
        ui->ComBoxFor->addItems(txt_res->affElem1);
    default:
        break;
    }

}

//     
void Wizard::changeSubAffil(int subAffPos)
{

//    ui->ComBoxFor->setEnabled(false);
//    ui->Affl_Add_Label_2->clear();
    clearAdvSwap();
    swpAdvTraitElem.clear();
    removeOldParam();
    removeOldParamCast();
    txt_res->subAffAttr(ui->Aff_ComBox->currentIndex(), subAffPos);
    addAffilAttr();
    addAfillSkill();
    addAfillTraits();
    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    ui->ComBoxSubAff1->clear();
    ui->ComBoxSubAff2->clear();
    ui->ComBoxSubAff3->clear();
//    ui->ComBoxSubAff4->clear();
    ui->lang_ZStage_ComboBox->clear();

    if(!s0moredial->s0MoreDialAttr.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialAttr.count(); i++) {
            chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] = chr_dat->charAttr[s0moredial->s0MoreDialAttr[i].first] - s0moredial->s0MoreDialAttr[i].second;
        }
        s0moredial->s0MoreDialAttr.clear();
    }


    if(!s0moredial->s0MoreDialSkills.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialSkills.count(); i++) {
            chr_dat->changeSkills(s0moredial->s0MoreDialSkills[i].first, -s0moredial->s0MoreDialSkills[i].second);
        }
        s0moredial->s0MoreDialSkills.clear();
    }

    if(!s0moredial->s0MoreDialTraits.isEmpty()) {
        for(int i = 0; i < s0moredial->s0MoreDialTraits.count(); i++) {
            chr_dat->changeTraits(s0moredial->s0MoreDialTraits[i].first, -s0moredial->s0MoreDialTraits[i].second);
        }
        s0moredial->s0MoreDialTraits.clear();
    }

    ui->lang_ZStage_ComboBox->addItems(txt_res->listLang);
    ui->lang_ZStage_ComboBox->insertSeparator(1);
    changeStartLang(txt_res->listLang[0]);
    if( txt_res->subAffElem1.count() != 0) {
        ui->ComBoxSubAff1->setEnabled(true);
        ui->SubAffaddlabel1->setText(txt_res->subAffElem1Label);
        ui->ComBoxSubAff1->addItems(txt_res->subAffElem1);
    } else {
        ui->ComBoxSubAff1->setEnabled(false);
        ui->ComBoxSubAff1->clear();
        ui->SubAffaddlabel1->clear();
    }


    if( txt_res->subAffElem2.count() != 0) {
        ui->ComBoxSubAff2->setEnabled(true);
        ui->SubAffaddlabel2->setText(txt_res->subAffElem2Label);
        ui->ComBoxSubAff2->addItems(txt_res->subAffElem2);
    } else {
        ui->ComBoxSubAff2->setEnabled(false);
        ui->ComBoxSubAff2->clear();
        ui->SubAffaddlabel2->clear();
    }


    if( txt_res->subAffElem3.count() != 0) {
        ui->ComBoxSubAff3->setEnabled(true);
        ui->SubAffaddlabel3->setText(txt_res->subAffElem3Label);
        ui->ComBoxSubAff3->addItems(txt_res->subAffElem3);
    } else {
        ui->ComBoxSubAff3->setEnabled(false);
        ui->ComBoxSubAff3->clear();
        ui->SubAffaddlabel3->clear();
    }

//    if( txt_res->subAffElem4.count() != 0) {
//        ui->ComBoxSubAff4->setEnabled(true);
//        ui->SubAffaddlabel4->setText(txt_res->subAffElem4Label);
//        ui->ComBoxSubAff4->addItems(txt_res->subAffElem4);
//    } else {
//        ui->ComBoxSubAff4->setEnabled(false);
//        ui->ComBoxSubAff4->clear();
//        ui->SubAffaddlabel4->clear();
//    }

    if(ui->Aff_ComBox->currentIndex() == 9 || ui->Aff_ComBox->currentIndex() == 10) {
        ui->ComBoxTried->clear();
        ui->Affl_Add_Label->setText("Castes");
        ui->ComBoxTried->setEnabled(true);
        ui->ComBoxTried->addItems(txt_res->affElem1);

    }

    if(ui->Aff_ComBox->currentIndex() == 10 && subAffPos == 4) {
        ui->Affl_Add_Label_2->setText("+75 XP to any Attribute");
        ui->ComBoxFor->setEnabled(true);
        ui->ComBoxFor->addItems(txt_res->affElem2);
    }
    if(ui->Aff_ComBox->currentIndex() == 11 && subAffPos == 3) {
        ui->ComBoxSubAff1->setEnabled(false);
    }

    if(ui->Aff_ComBox->currentIndex() == 11 && subAffPos == 6) {
        ui->ComBoxSubAff1->setEnabled(false);
    }


    change();
    ui->ComBoxSubAff1->setCurrentIndex(0);
    ui->ComBoxSubAff2->setCurrentIndex(1);
    ui->ComBoxSubAff3->setCurrentIndex(2);
//    ui->ComBoxSubAff4->setCurrentIndex(3);

    changeElem1(ui->ComBoxSubAff1->currentText());
    changeElem2(ui->ComBoxSubAff2->currentText());
    changeElem3(ui->ComBoxSubAff3->currentText());
//    changeElem4(ui->ComBoxSubAff4->currentText());
//    changeElem1main(ui->ComBoxSubAff1->currentText());
//    changeElem2main(ui->ComBoxSubAff2->currentText());
//    changeElem3main(ui->ComBoxSubAff3->currentText());
//    changeElem4(ui->ComBoxSubAff4->currentText());
    chr_dat->subAffName.first = ui->Sub_Aff_ComBox->currentText();
    chr_dat->subAffName.second = ui->Sub_Aff_ComBox->currentIndex();
    if(!txt_res->subAffElem1LabelMore.isEmpty()) {
        ui->S0MoreButton->setDisabled(false);
    } else {
        ui->S0MoreButton->setDisabled(true);
    }

}

void Wizard::removeOldParam()
{

    QMapIterator <QString, int> i(txt_res->affAttr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
    }


    int swapCount = txt_res->affSkills.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(txt_res->affSkills[sCount].first,-txt_res->affSkills[sCount].second);
    }
    int swapCount2 = txt_res->affTraits.count();
    for(int sCount = 0 ; sCount < swapCount2 ; sCount++) {
        chr_dat->changeTraits(txt_res->affTraits[sCount].first,-txt_res->affTraits[sCount].second);
    }
}

void Wizard::removeOldParamCast() {

    QMapIterator <QString, int> g(txt_res->affAttrCast);
    while(g.hasNext()) {
        g.next();
        chr_dat->charAttr[g.key()] = chr_dat->charAttr[g.key()] - g.value();
    }
    int swapCount = txt_res->affSkillsCast.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(txt_res->affSkillsCast[sCount].first,-txt_res->affSkillsCast[sCount].second);
    }
    int swapCount2 = txt_res->affTraitsCast.count();
    for(int sCount = 0 ; sCount < swapCount2 ; sCount++) {
        chr_dat->changeTraits(txt_res->affTraitsCast[sCount].first,-txt_res->affTraitsCast[sCount].second);
    }
    txt_res->affAttrCast.clear();
    txt_res->affSkillsCast.clear();
    txt_res->affTraitsCast.clear();
}

// 1   
void Wizard::changeElem1(QString nameElem1) {
    switch(ui->Aff_ComBox->currentIndex()) {
    case 3:
        if(ui->Sub_Aff_ComBox->currentIndex() == 5) {
            chr_dat->changeTraits(nameElem1, txt_res->affTraitsElem1);
            if(swpAffTraitsElem1.isEmpty() != true) {
                chr_dat->changeTraits(swpAffTraitsElem1, -swpAffTraitsElem1Int);
                int posNullLang = chr_dat->findTraits(swpAffTraitsElem1)-1;
                if (chr_dat->charTraits[posNullLang].second == 0) {
                    chr_dat->charTraits.removeAt(posNullLang);
                    ui->TraitsTable->clear();
                }
            }

            swpAffTraitsElem1 = nameElem1;
            swpAffTraitsElem1Int = txt_res->affTraitsElem1;
            if (ui->ComBoxSubAff1->currentText() == "Implant/Prosthetic") {
                if (txt_res->countElem1 == 0) {
                    txt_res->countElem1 = 1;
                    QString tmpName = "Reputation";
                    int tmpXP = -100;
                    chr_dat->changeTraits("Reputation", -100);
                    swpAdvTraitElem.append(qMakePair(tmpName, tmpXP));
                }
            } else {
                if(txt_res->countElem1 != 0) {
                    chr_dat->changeTraits("Reputation", 100);
                    chr_dat->clearZeroTraits();
                    txt_res->countElem1 = 0;
                }
            }
        }  else {
            changeElem1main(nameElem1);
        }
        break;
//    case 6:
//        if (ui->Sub_Aff_ComBox->currentIndex() == 5) {
//            changeAffSkill(nameElem1, 2);
//        } else {
//            changeElem1main(nameElem1);
//        }
//        break;
//        case 7:
//        if (ui->Sub_Aff_ComBox->currentIndex() == 1) {
//            changeAffSkill(nameElem1, 3);
//        } else {
//            changeElem1main(nameElem1);
//        }
//        break;
        case 9:
        if (ui->Sub_Aff_ComBox->currentIndex() == 7) {
            changeElem1main(nameElem1);

            if(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff1->currentText(), ui->ComBoxSubAff2->itemText(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff2->currentText();
                ui->ComBoxSubAff2->clear();
                ui->ComBoxSubAff2->addItems(boxList);
                ui->ComBoxSubAff2->setCurrentIndex(ui->ComBoxSubAff2->findText(nowElem));
            }

        } else {
            changeElem1main(nameElem1);
        }        
        break;
    case 10:
        if (ui->Sub_Aff_ComBox->currentIndex() == 4) {
            changeElem1main(nameElem1);

            if(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff1->currentText(), ui->ComBoxSubAff2->itemText(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff2->currentText();
                ui->ComBoxSubAff2->clear();
                ui->ComBoxSubAff2->addItems(boxList);
                ui->ComBoxSubAff2->setCurrentIndex(ui->ComBoxSubAff2->findText(nowElem));
            }

        } else {
            changeElem1main(nameElem1);
        }
        break;
        case 11:
        if (ui->Sub_Aff_ComBox->currentIndex() == 1 || ui->Sub_Aff_ComBox->currentIndex() == 4) {

            changeElem1main(nameElem1);

            if(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff1->currentText(), ui->ComBoxSubAff2->itemText(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff2->currentText();
                ui->ComBoxSubAff2->clear();
                ui->ComBoxSubAff2->addItems(boxList);
                ui->ComBoxSubAff2->setCurrentIndex(ui->ComBoxSubAff2->findText(nowElem));
            }

        } else {
            changeElem1main(nameElem1);
        }
        break;
        case 12:
        switch (ui->Sub_Aff_ComBox->currentIndex()) {
        case 1:
            changeElem1main(nameElem1);

            if(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff1->currentText(), ui->ComBoxSubAff2->itemText(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff2->currentText();
                ui->ComBoxSubAff2->clear();
                ui->ComBoxSubAff2->addItems(boxList);
                ui->ComBoxSubAff2->setCurrentIndex(ui->ComBoxSubAff2->findText(nowElem));
            }
//            changeAffSkill(nameElem1, 2);
            break;
        case 2:
            changeElem1main(nameElem1);

            if(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff1->currentText(), ui->ComBoxSubAff2->itemText(ui->ComBoxSubAff2->findText(ui->ComBoxSubAff1->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff2->currentText();
                ui->ComBoxSubAff2->clear();
                ui->ComBoxSubAff2->addItems(boxList);
                ui->ComBoxSubAff2->setCurrentIndex(ui->ComBoxSubAff2->findText(nowElem));
            }
            break;
//        case 3:
//            changeAffSkill(nameElem1, 4);
//            break;
//        case 5:
//            changeAffSkill(nameElem1, 3);
//            break;
//        case 7:
//            changeAffSkill(nameElem1, 3);
//            break;
        default:
            changeElem1main(nameElem1);
            break;
        }

        break;
    default:
        changeElem1main(nameElem1);
        break;
    }
    
    chr_dat->clearZeroTraits();
    chr_dat->clearZeroSkills();
    
    change();
}

void Wizard::changeElem1main(QString nameElem1) {
    //  
    if (txt_res->affSkillsElem1 != 0) {
        chr_dat->changeSkills(nameElem1, txt_res->affSkillsElem1);
        if(swpAffSkillsElem1.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem1, -swpAffSkillsElem1Int);
            chr_dat->clearZeroSkills();
        }

        swpAffSkillsElem1 = nameElem1;
        swpAffSkillsElem1Int = txt_res->affSkillsElem1;
    } else {
        if(swpAffSkillsElem1.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem1, -swpAffSkillsElem1Int);
            chr_dat->clearZeroSkills();
            swpAffSkillsElem1.clear();
            swpAffSkillsElem1Int = 0;
        }
    }

    // 
    if (txt_res->affTraitsElem1 != 0) {
        chr_dat->changeTraits(nameElem1, txt_res->affTraitsElem1);
        if(swpAffTraitsElem1.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem1, -swpAffTraitsElem1Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem1)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
        }

        swpAffTraitsElem1 = nameElem1;
        swpAffTraitsElem1Int = txt_res->affTraitsElem1;
    } else {
        if(swpAffTraitsElem1.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem1, -swpAffTraitsElem1Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem1)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
            swpAffTraitsElem1.clear();
            swpAffTraitsElem1Int = 0;
        }
    }
}

// 2   
void Wizard::changeElem2(QString nameElem2) {
    switch(ui->Aff_ComBox->currentIndex()) {
    case 9:
        if (ui->Sub_Aff_ComBox->currentIndex() == 7) {
            changeElem2main(nameElem2);

            if(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff2->currentText(), ui->ComBoxSubAff1->itemText(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff1->currentText();
                ui->ComBoxSubAff1->clear();
                ui->ComBoxSubAff1->addItems(boxList);
                ui->ComBoxSubAff1->setCurrentIndex(ui->ComBoxSubAff1->findText(nowElem));
            }

        }

        break;
    case 10:
        if (ui->Sub_Aff_ComBox->currentIndex() == 4) {
            changeElem2main(nameElem2);

            if(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff2->currentText(), ui->ComBoxSubAff1->itemText(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff1->currentText();
                ui->ComBoxSubAff1->clear();
                ui->ComBoxSubAff1->addItems(boxList);
                ui->ComBoxSubAff1->setCurrentIndex(ui->ComBoxSubAff1->findText(nowElem));
            }


//            if(txt_res->subCountElem2 == 0 ) {
//                chr_dat->changeSkills(swpAffSkillsElem2, -swpAffSkillsElem2Int);
//                chr_dat->clearZeroSkills();
//                swpAffSkillsElem2.clear();
//                swpAffSkillsElem2Int = 0;
//            }
//            ++txt_res->subCountElem2;

//            if(txt_res->subCountElem2 == 2) {
//                ui->ComBoxSubAff2->setDisabled(true);
//                txt_res->subCountElem2 = 0;
//            }
//            chr_dat->changeSkills(nameElem2, txt_res->affSkillsElem2); //
//            swpAdvSkillElem.append(qMakePair(nameElem2, txt_res->affSkillsElem2)); //

//            for (int i =0; i < txt_res->subAffElem2.size(); i++) {
//                if (txt_res->subAffElem2.at(i) == nameElem2) {
//                    txt_res->subAffElem2.removeAt(i);
//                    ui->ComBoxSubAff2->clear();
//                    ui->ComBoxSubAff2->addItems(txt_res->subAffElem2);
//                }
//            }
        } else {
            changeElem2main(nameElem2);
        }
        break;
        case 11:
        if (ui->Sub_Aff_ComBox->currentIndex() == 1 || ui->Sub_Aff_ComBox->currentIndex() == 4 ) {

            changeElem2main(nameElem2);

            if(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff2->currentText(), ui->ComBoxSubAff1->itemText(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff1->currentText();
                ui->ComBoxSubAff1->clear();
                ui->ComBoxSubAff1->addItems(boxList);
                ui->ComBoxSubAff1->setCurrentIndex(ui->ComBoxSubAff1->findText(nowElem));
            }

        } else {
            changeElem2main(nameElem2);
        }
        break;
        case 12:
        switch (ui->Sub_Aff_ComBox->currentIndex()) {
        case 1:
            changeElem2main(nameElem2);

            if(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff2->currentText(), ui->ComBoxSubAff1->itemText(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff1->currentText();
                ui->ComBoxSubAff1->clear();
                ui->ComBoxSubAff1->addItems(boxList);
                ui->ComBoxSubAff1->setCurrentIndex(ui->ComBoxSubAff1->findText(nowElem));
            }
            break;
        case 2:
            changeElem2main(nameElem2);

            if(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText()) != -1) {
                QStringList boxList = s0moredial->checkDifferent(ui->ComBoxSubAff2->currentText(), ui->ComBoxSubAff1->itemText(ui->ComBoxSubAff1->findText(ui->ComBoxSubAff2->currentText())), txt_res->subAffElem1);
                QString nowElem = ui->ComBoxSubAff1->currentText();
                ui->ComBoxSubAff1->clear();
                ui->ComBoxSubAff1->addItems(boxList);
                ui->ComBoxSubAff1->setCurrentIndex(ui->ComBoxSubAff1->findText(nowElem));
            }

            break;


        }

        break;
    default:
        changeElem2main(nameElem2);
        break;
    }

    chr_dat->clearZeroTraits();
    chr_dat->clearZeroSkills();
    change();
}

void Wizard::changeElem2main(QString nameElem2) {
    //  
    if (txt_res->affSkillsElem2 != 0) {
        chr_dat->changeSkills(nameElem2, txt_res->affSkillsElem2);
        if(swpAffSkillsElem2.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem2, -swpAffSkillsElem2Int);
            int posNullLang = chr_dat->findSkill(swpAffSkillsElem2)-1;
            if (chr_dat->charSkills[posNullLang].second == 0) {
                chr_dat->charSkills.removeAt(posNullLang);
                ui->SkillsTable->clear();
            }
        }

        swpAffSkillsElem2 = nameElem2;
        swpAffSkillsElem2Int = txt_res->affSkillsElem2;
    } else {
        if(swpAffSkillsElem2.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem2, -swpAffSkillsElem2Int);
            int posNullLang = chr_dat->findSkill(swpAffSkillsElem2)-1;
            if (chr_dat->charSkills[posNullLang].second == 0) {
                chr_dat->charSkills.removeAt(posNullLang);
                ui->SkillsTable->clear();
            }
            swpAffSkillsElem2.clear();
            swpAffSkillsElem2Int = 0;
        }
    }

    // 
    if (txt_res->affTraitsElem2 != 0) {
        chr_dat->changeTraits(nameElem2, txt_res->affTraitsElem2);
        if(swpAffTraitsElem2.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem2, -swpAffTraitsElem2Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem2)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
        }

        swpAffTraitsElem2 = nameElem2;
        swpAffTraitsElem2Int = txt_res->affTraitsElem2;
    } else {
        if(swpAffTraitsElem2.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem2, -swpAffTraitsElem2Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem2)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
            swpAffTraitsElem2.clear();
            swpAffTraitsElem2Int = 0;
        }
    }

}

// 3   
void Wizard::changeElem3(QString nameElem3) {
    switch(ui->Aff_ComBox->currentIndex()) {
//    case 3:
//        if(ui->Sub_Aff_ComBox->currentIndex() == 5) {
//            if(txt_res->subCountElem3 == 0 ) {
//                chr_dat->changeSkills(swpAffSkillsElem3, -swpAffSkillsElem3Int);
//                chr_dat->clearZeroSkills();
//                swpAffSkillsElem3.clear();
//                swpAffSkillsElem3Int = 0;
//            }
//            ++txt_res->subCountElem3;

//            if(txt_res->subCountElem3 == 2) {
//                ui->ComBoxSubAff3->setDisabled(true);
//                txt_res->subCountElem3 = 0;
//            }

//            chr_dat->changeSkills(nameElem3, txt_res->affSkillsElem3); //

//            swpAdvSkillElem.append(qMakePair(nameElem3, txt_res->affSkillsElem3)); //
//            for (int i =0; i < txt_res->subAffElem3.size(); i++) {
//                if (txt_res->subAffElem3.at(i) == nameElem3) {
//                    txt_res->subAffElem3.removeAt(i);
//                    ui->ComBoxSubAff3->clear();
//                    ui->ComBoxSubAff3->addItems(txt_res->subAffElem3);
//                }
//            }
//        } else {

//            changeElem3main(nameElem3);
//        }
//        break;
    case 11:
        if(ui->Sub_Aff_ComBox->currentIndex() == 1) {
            chr_dat->charAttr[nameElem3] += txt_res->affAttrElem3;
            if (swpAffAttrElem3.isEmpty() != true ) {
                chr_dat->charAttr[swpAffAttrElem3] -= txt_res->affAttrElem3;
                swpAffAttrElem3.clear();
            }
            swpAffAttrElem3 = nameElem3;
        } else {
            changeElem3main(nameElem3);
        }
        break;
    default:
        changeElem3main(nameElem3);
        break;
    }
    change();
}

void Wizard::changeElem3main(QString nameElem3) {

    //  
    if (txt_res->affSkillsElem3 != 0) {
        chr_dat->changeSkills(nameElem3, txt_res->affSkillsElem3);
        if(swpAffSkillsElem3.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem3, -swpAffSkillsElem3Int);
            chr_dat->clearZeroSkills();
        }

        swpAffSkillsElem3 = nameElem3;
        swpAffSkillsElem3Int = txt_res->affSkillsElem3;
    } else {
        if(swpAffSkillsElem3.isEmpty() != true) {
            chr_dat->changeSkills(swpAffSkillsElem3, -swpAffSkillsElem3Int);
            chr_dat->clearZeroSkills();
            swpAffSkillsElem3.clear();
            swpAffSkillsElem3Int = 0;
        }
    }

    // 
    if (txt_res->affTraitsElem3 != 0) {
        chr_dat->changeTraits(nameElem3, txt_res->affTraitsElem3);
        if(swpAffTraitsElem3.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem3, -swpAffTraitsElem3Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem3)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
        }

        swpAffTraitsElem3 = nameElem3;
        swpAffTraitsElem3Int = txt_res->affTraitsElem3;
    } else {
        if(swpAffTraitsElem3.isEmpty() != true) {
            chr_dat->changeTraits(swpAffTraitsElem3, -swpAffTraitsElem3Int);
            int posNullLang = chr_dat->findTraits(swpAffTraitsElem3)-1;
            if (chr_dat->charTraits[posNullLang].second == 0) {
                chr_dat->charTraits.removeAt(posNullLang);
                ui->TraitsTable->clear();
            }
            swpAffTraitsElem3.clear();
            swpAffTraitsElem3Int = 0;
        }
    }

    if (txt_res->affAttrElem3 != 0) {
        chr_dat->charAttr[nameElem3] += txt_res->affAttrElem3;
        if (swpAffAttrElem3.isEmpty() != true ) {
            chr_dat->charAttr[swpAffAttrElem3] -= txt_res->affAttrElem3;
            swpAffAttrElem3.clear();
        }
        swpAffAttrElem3 = nameElem3;
    }
}

// 4   
//void Wizard::changeElem4(QString nameElem4) {
//    switch (ui->Aff_ComBox->currentIndex()) {
//    case 3:
//        if (ui->Sub_Aff_ComBox->currentIndex() == 5) {
//            hardAdvElem4(nameElem4);
//        }
//        break;
//    case 6:
//        flexXpChange(nameElem4);
//        if (txt_res->subCountElem4 == 3) {
//            ui->ComBoxSubAff4->setEnabled(false);
//            swpFXAttr.clear();
//        }
//        ++txt_res->subCountElem4;
//        break;
//    case 7:
//        flexXpChangeOther(nameElem4);
//        if (txt_res->subCountElem4 == 3) {
//            ui->ComBoxSubAff4->setEnabled(false);
//            swpFXAttr.clear();
//        }
//        ++txt_res->subCountElem4;
//        break;
//    case 8:
//        flexXpChangeOther(nameElem4);
//        if (txt_res->subCountElem4 == 2) {
//            ui->ComBoxSubAff4->setEnabled(false);
//            swpFXAttr.clear();
//        }
//        ++txt_res->subCountElem4;
//        if(ui->Sub_Aff_ComBox->currentIndex() == 3 && ui->ComBoxSubAff4->currentText() == "Combat Paralysis") {
//            QString tmpName = "Reputation";
//            int tmpXP = -10;
//            chr_dat->changeTraits("Reputation", -10);
//            swpAdvTraitElem.append(qMakePair(tmpName, tmpXP));
//        }


//        break;
//    default:
//        changeElem4main(nameElem4);
//        break;
//    }

//    change();

//}

//void Wizard::changeElem4main(QString nameElem4) {
//    //
//    if (txt_res->affSkillsElem4 != 0) {
//        chr_dat->changeSkills(nameElem4, txt_res->affSkillsElem4);
//        if(swpAffSkillsElem4.isEmpty() != true) {
//            chr_dat->changeSkills(swpAffSkillsElem4, -swpAffSkillsElem4Int);
//            chr_dat->clearZeroSkills();
//        }

//        swpAffSkillsElem4 = nameElem4;
//        swpAffSkillsElem4Int = txt_res->affSkillsElem4;
//    } else {
//        if(swpAffSkillsElem4.isEmpty() != true) {
//            chr_dat->changeSkills(swpAffSkillsElem4, -swpAffSkillsElem4Int);
//            chr_dat->clearZeroSkills();
//            swpAffSkillsElem4.clear();
//            swpAffSkillsElem4Int = 0;
//        }
//    }

//    //
//    if (txt_res->affTraitsElem4 != 0) {
//        chr_dat->changeTraits(nameElem4, txt_res->affTraitsElem4);
//        if(swpAffTraitsElem4.isEmpty() != true) {
//            chr_dat->changeTraits(swpAffTraitsElem4, -swpAffTraitsElem4Int);
//            int posNullLang = chr_dat->findTraits(swpAffTraitsElem4)-1;
//            if (chr_dat->charTraits[posNullLang].second == 0) {
//                chr_dat->charTraits.removeAt(posNullLang);
//                ui->TraitsTable->clear();
//            }
//        }

//        swpAffTraitsElem4 = nameElem4;
//        swpAffTraitsElem4Int = txt_res->affTraitsElem4;
//    } else {
//        if(swpAffTraitsElem4.isEmpty() != true) {
//            chr_dat->changeTraits(swpAffTraitsElem4, -swpAffTraitsElem4Int);
//            int posNullLang = chr_dat->findTraits(swpAffTraitsElem4)-1;
//            if (chr_dat->charTraits[posNullLang].second == 0) {
//                chr_dat->charTraits.removeAt(posNullLang);
//                ui->TraitsTable->clear();
//            }
//            swpAffTraitsElem4.clear();
//            swpAffTraitsElem4Int = 0;
//        }
//    }
//}

//    
void Wizard::clearAdvSwap() {
    if (swpAdvSkillElem.empty() != true) {
        for (int i = 0; i < swpAdvSkillElem.count(); i++ ) {
            chr_dat->changeSkills(swpAdvSkillElem[i].first, -swpAdvSkillElem[i].second);
        }
        swpAdvSkillElem.clear();
    }

    if (swpAdvTraitElem.empty() != true) {
        for (int i = 0; i < swpAdvTraitElem.count(); i++ ) {
            chr_dat->changeTraits(swpAdvTraitElem[i].first, -swpAdvTraitElem[i].second);
        }
        swpAdvSkillElem.clear();
    }

//    if (swpAffAttrElem4.isEmpty() != true ) {
//        chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affSkillsElem4;
//        swpAffAttrElem4.clear();
//    }

    if (swpAffAttrElem3.isEmpty() != true ) {
        chr_dat->charAttr[swpAffAttrElem3] -= txt_res->affAttrElem3;
        swpAffAttrElem3.clear();
    }

    if (swpFMAttr.isEmpty() != true) {
        for (int i =0; i < swpFMAttr.count(); i++) {
            if ( i == 0 ) {
                chr_dat->charAttr[swpFMAttr[i]] -= 75;
            } else {
                chr_dat->charAttr[swpFMAttr[i]] += 20;
            }
        }
        swpFMAttr.clear();
        txt_res->countFMAttr = 0;
        ui->Affl_Add_Label_2->clear();
        ui->ComBoxFor->clear();
    }

    if (swpFXAttr.isEmpty() != true) {
        QMapIterator<QString, int> i(swpFXAttr);
        while(i.hasNext()) {
            i.next();
            chr_dat->charAttr[i.key()] -= i.value();
        }
        swpFXAttr.clear();
    }
}

//    4
//void Wizard::hardAdvElem4(QString elemName) {
//    if (ui->ComBoxSubAff4->currentIndex() <= 7 ) {
//        chr_dat->charAttr[elemName] += txt_res->affSkillsElem4;
//        if (swpAffAttrElem4.isEmpty() != true ) {
//            chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affSkillsElem4;
//            swpAffAttrElem4.clear();
//        }
//        swpAffAttrElem4 = elemName;
//    }

//    if(ui->ComBoxSubAff4->currentIndex() >= 65) {
//        if(swpAffTraitsElem4.isEmpty() != true) {
//            chr_dat->changeTraits(swpAffTraitsElem4, -swpAffTraitsElem4Int);
//            chr_dat->clearZeroTraits();
//            swpAffTraitsElem4.clear();
//            swpAffTraitsElem4Int = 0;
//        }

//        if (swpAffAttrElem4.isEmpty() != true ) {
//            chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affSkillsElem4;
//            swpAffAttrElem4.clear();
//        }

//        if (txt_res->affSkillsElem4 != 0) {
//            chr_dat->changeSkills(elemName, txt_res->affSkillsElem4);
//            if(swpAffSkillsElem4.isEmpty() != true) {
//                chr_dat->changeSkills(swpAffSkillsElem4, -swpAffSkillsElem4Int);
//                chr_dat->clearZeroSkills();
//            }

//            swpAffSkillsElem4 = elemName;
//            swpAffSkillsElem4Int = txt_res->affSkillsElem4;
//        } else {
//            if(swpAffSkillsElem4.isEmpty() != true) {
//                chr_dat->changeSkills(swpAffSkillsElem4, -swpAffSkillsElem4Int);
//                chr_dat->clearZeroSkills();
//                swpAffSkillsElem4.clear();
//                swpAffSkillsElem4Int = 0;
//            }
//        }
//    }

//    if (ui->ComBoxSubAff4->currentIndex() > 7 &&  ui->ComBoxSubAff4->currentIndex() < 65 ) {
//        if(swpAffSkillsElem4.isEmpty() != true) {
//            chr_dat->changeSkills(swpAffSkillsElem4, -swpAffSkillsElem4Int);
//            chr_dat->clearZeroSkills();
//            swpAffSkillsElem4.clear();
//            swpAffSkillsElem4Int = 0;
//        }

//        if (swpAffAttrElem4.isEmpty() != true ) {
//            chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affSkillsElem4;
//            swpAffAttrElem4.clear();
//        }

//        if (txt_res->affTraitsElem4 != 0) {
//            chr_dat->changeTraits(elemName, txt_res->affTraitsElem4);
//            if(swpAffTraitsElem4.isEmpty() != true) {
//                chr_dat->changeTraits(swpAffTraitsElem4, -swpAffTraitsElem4Int);
//                chr_dat->clearZeroTraits();
//            }

//            swpAffTraitsElem4 = elemName;
//            swpAffTraitsElem4Int = txt_res->affTraitsElem4;
//        } else {
//            if(swpAffTraitsElem4.isEmpty() != true) {
//                chr_dat->changeTraits(swpAffTraitsElem4, -swpAffTraitsElem4Int);
//                chr_dat->clearZeroTraits();
//                swpAffTraitsElem4.clear();
//                swpAffTraitsElem4Int = 0;
//            }

//        }
//    }

//}

//    6 
//void Wizard::flexXpChange(QString elemName) {
//    if (ui->ComBoxSubAff4->currentIndex() <= 7) {
//        if (swpFXAttr.isEmpty() == true) {
//            chr_dat->charAttr[elemName] += txt_res->affTraitsElem4;
//            swpAffAttrElem4 = elemName;
//            swpFXAttr[elemName] += 0;
//        } else {
//            chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affTraitsElem4;
//            swpAffAttrElem4.clear();
//            swpFXAttr[elemName] += txt_res->affTraitsElem4;
//            chr_dat->charAttr[elemName] += txt_res->affTraitsElem4;
//        }
//    } else {
//        chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affTraitsElem4;
//        swpAffAttrElem4.clear();
//        chr_dat->changeTraits(elemName, txt_res->affTraitsElem4); //
//        swpAdvTraitElem.append(qMakePair(elemName, txt_res->affTraitsElem4));
//    }
//}

//   
//void Wizard::flexXpChangeOther(QString elemName) {
//    if (ui->ComBoxSubAff4->currentIndex() <= 7) {
//        if (swpFXAttr.isEmpty() == true) {
//            chr_dat->charAttr[elemName] += txt_res->affTraitsElem4;
//            swpAffAttrElem4 = elemName;
//            swpFXAttr[elemName] += 0;
//        } else {
//            chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affTraitsElem4;
//            swpAffAttrElem4.clear();
//            swpFXAttr[elemName] += txt_res->affTraitsElem4;
//            chr_dat->charAttr[elemName] += txt_res->affTraitsElem4;
//        }
//    }

//    if(ui->ComBoxSubAff4->currentIndex() >= 8 && ui->ComBoxSubAff4->currentIndex() <= 64){
//        chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affTraitsElem4;
//        swpAffAttrElem4.clear();
//        chr_dat->changeTraits(elemName, txt_res->affTraitsElem4); //
//        swpAdvTraitElem.append(qMakePair(elemName, txt_res->affTraitsElem4));
//    }

//    if(ui->ComBoxSubAff4->currentIndex() >= 65){
//        chr_dat->charAttr[swpAffAttrElem4] -= txt_res->affTraitsElem4;
//        swpAffAttrElem4.clear();
//        chr_dat->changeSkills(elemName, txt_res->affTraitsElem4); //
//        swpAdvSkillElem.append(qMakePair(elemName, txt_res->affTraitsElem4));
//    }
//}

void Wizard::changeAffSkill(QString nameElem, int a) {
    if(txt_res->subCountElem1 == 0 ) {
        chr_dat->changeSkills(swpAffSkillsElem1, -swpAffSkillsElem1Int);
        chr_dat->clearZeroSkills();
        swpAffSkillsElem1.clear();
        swpAffSkillsElem1Int = 0;
    }
    ++txt_res->subCountElem1;

    if(txt_res->subCountElem1 == a) {
        ui->ComBoxSubAff1->setDisabled(true);
        txt_res->subCountElem1 = 0;
    }
    chr_dat->changeSkills(nameElem, txt_res->affSkillsElem1); //
    swpAdvSkillElem.append(qMakePair(nameElem, txt_res->affSkillsElem1)); //

    for (int i =0; i < txt_res->subAffElem1.size(); i++) {
        if (txt_res->subAffElem1.at(i) == nameElem) {
            txt_res->subAffElem1.removeAt(i);
            ui->ComBoxSubAff1->clear();
            ui->ComBoxSubAff1->addItems(txt_res->subAffElem1);
        }
    }
}

void Wizard::changeWobComBox(QString nameElem) {
    chr_dat->changeSkills(nameElem, txt_res->comElemInt);
    if(swpComElem.isEmpty() != true) {
        chr_dat->changeSkills(swpComElem, -txt_res->comElemInt);
        chr_dat->clearZeroSkills();
    }
    swpComElem = nameElem;

    change();
}


//!!!!!!!!!!!!--------------------STAGE1--------------------!!!!!!!!!!!!//


void Wizard::Stage1Main() {
    stage1 = new Stage1;
    ui->S1LabelElem1->clear();
    ui->S1LabelElem2->clear();
    ui->S1LabelElem3->clear();
    ui->S1LabelElem4->clear();
    ui->S1ComboBoxElem1->clear();
    ui->S1ComboBoxElem2->clear();
    ui->S1ComboBoxElem3->clear();
    ui->S1ComboBoxElem4->clear();
    ui->S1ChComboBox->clear();
    stage1->careerList = careerList;
    stage1->subSkillList = subSkillList;

//    this->button(QWizard::NextButton)->setEnabled(false);


    ui->S1NameLabel->setText(chr_dat->charName); //    
    stage1->S1ShortNameAff(chr_dat->AffName.second); //    
    chr_dat->AffName.first = stage1->s1ShortNameAff;
    ui->S1AffLabel->setText(chr_dat->AffName.first); //      
    ui->S1SubAffLabel->setText(chr_dat->subAffName.first); //    
    ui->S1CasteLabel->setText(chr_dat->clanCastName.first); //    
    ui->S1ChComboBox->addItems(stage1->S1ChoiceChillHood(chr_dat->AffName.second, chr_dat->subAffName.second, chr_dat->charTraits));
    S1ChangeChilHod(ui->S1ChComboBox->currentText());
}

void Wizard::on_S1MoreButton_clicked()
{
    if(!s1moredial->s1MoreDialAttr.isEmpty()) {
        for(int i = 0; i < s1moredial->s1MoreDialAttr.count(); i++) {
            chr_dat->charAttr[s1moredial->s1MoreDialAttr[i].first] = chr_dat->charAttr[s1moredial->s1MoreDialAttr[i].first] - s1moredial->s1MoreDialAttr[i].second;
        }
    }

    if(!s1moredial->s1MoreDialSkills.isEmpty()) {
        for(int i = 0; i < s1moredial->s1MoreDialSkills.count(); i++) {
            chr_dat->changeSkills(s1moredial->s1MoreDialSkills[i].first, -s1moredial->s1MoreDialSkills[i].second);
        }
    }

    if(!s1moredial->s1MoreDialTraits.isEmpty()) {
        for(int i = 0; i < s1moredial->s1MoreDialTraits.count(); i++) {
            chr_dat->changeTraits(s1moredial->s1MoreDialTraits[i].first, -s1moredial->s1MoreDialTraits[i].second);
        }
    }


    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    S1Change();

    s1moredial->S1MoreDialogClear();

    s1moredial->s1MoreDialLabel1 = stage1->s1subAffElem1LabelMore;
    s1moredial->s1MoreDialDrop1 = stage1->s1subAffElem1More;
    s1moredial->s1Value1 = stage1->s1affSkillsElem1More;

    s1moredial->s1MoreDialLabel2 = stage1->s1subAffElem2LabelMore;
    s1moredial->s1MoreDialDrop2 = stage1->s1subAffElem2More;
    s1moredial->s1Value2 = stage1->s1affSkillsElem2More;

    s1moredial->s1MoreDialLabel3 = stage1->s1subAffElem3LabelMore;
    s1moredial->s1MoreDialDrop3 = stage1->s1subAffElem3More;
    s1moredial->s1Value3 = stage1->s1affSkillsElem3More;

    s1moredial->s1MoreDialLabel4 = stage1->s1subAffElem4LabelMore;
    s1moredial->s1MoreDialDrop4 = stage1->s1subAffElem4More;
    s1moredial->s1Value4 = stage1->s1affSkillsElem4More;

    s1moredial->s1childName = ui->S1ChComboBox->currentText();


    s1moredial->S1MoreDialogInit();

    s1moredial->show();
    s1moredial->raise();
    s1moredial->activateWindow();
}

void Wizard::S1AdvDialAccept() {

    for(int i = 0; i < s1moredial->s1MoreDialAttr.count(); i++) {
        chr_dat->charAttr[s1moredial->s1MoreDialAttr[i].first] = chr_dat->charAttr[s1moredial->s1MoreDialAttr[i].first] + s1moredial->s1MoreDialAttr[i].second;
    }

    for(int i = 0; i < s1moredial->s1MoreDialSkills.count(); i++) {
        chr_dat->changeSkills(s1moredial->s1MoreDialSkills[i].first, s1moredial->s1MoreDialSkills[i].second);
    }

    for(int i = 0; i < s1moredial->s1MoreDialTraits.count(); i++) {
        chr_dat->changeTraits(s1moredial->s1MoreDialTraits[i].first, s1moredial->s1MoreDialTraits[i].second);
    }

    S1Change();
}

void Wizard::S1AdvDialCancel() {
    s1moredial->s1MoreDialAttr.clear();
    s1moredial->s1MoreDialSkills.clear();
    s1moredial->s1MoreDialTraits.clear();
}

void Wizard::S1ConnectEvent() {
    connect(ui->S1ChComboBox, SIGNAL(activated(QString)), this, SLOT(S1ChangeChilHod(QString)));
    connect(ui->S1ComboBoxElem1, SIGNAL(activated(QString)), this, SLOT(S1ChangeElem1(QString)));
    connect(ui->S1ComboBoxElem2, SIGNAL(activated(QString)), this, SLOT(S1ChangeElem2(QString)));
    connect(ui->S1ComboBoxElem3, SIGNAL(activated(QString)), this, SLOT(S1ChangeElem3(QString)));
    connect(ui->S1ComboBoxElem4, SIGNAL(activated(QString)), this, SLOT(S1ChangeElem4(QString)));
    connect(s1moredial, SIGNAL(accepted()), this, SLOT(S1AdvDialAccept()));
    connect(s1moredial, SIGNAL(rejected()), this, SLOT(S1AdvDialCancel()));
}

void Wizard::S1ChangeChilHod(QString nameChood) {
    S1RemoveOldParam();
    stage1->s1XpCost = 0;
    stage1->s1Attr.clear();
    stage1->s1Skills.clear();
    stage1->s1Traits.clear();
    stage1->S1ChildHood(nameChood);
    ui->S1ChComboBox->setToolTip(stage1->s1toolTip);
    S1ComBoxChange();

    if (stage1->s1AffLang != 0) {
        stage1->S1AddSkills(ui->lang_ZStage_ComboBox->currentText(), stage1->s1AffLang);
    }

    if (stage1->s1AffProt != 0) {
        stage1->S1AddSkills(txt_res->affProtocol, stage1->s1AffProt);
    }

    if (stage1->s1AffStreet != 0) {
        stage1->S1AddSkills(txt_res->affStreet, stage1->s1AffStreet);
    }



//    S1ShortFlex(ui->S1ComboBoxElem4->currentText());

    S1AddAffilAttr();
    S1AddAfillSkill();
    S1AddAfillTraits();

    stage1->s1ChildHoodSkillsSwp1.clear();
    stage1->s1ChildHoodSkillsSwp1Int = 0;
    stage1->s1ChildHoodTraitsSwp1.clear();
    stage1->s1ChildHoodTraitsSwp1Int = 0;

    stage1->s1ChildHoodSkillsSwp2.clear();
    stage1->s1ChildHoodSkillsSwp2Int = 0;
    stage1->s1ChildHoodTraitsSwp2.clear();
    stage1->s1ChildHoodTraitsSwp2Int = 0;

    stage1->s1ChildHoodSkillsSwp3.clear();
    stage1->s1ChildHoodSkillsSwp3Int = 0;
    stage1->s1ChildHoodTraitsSwp3.clear();
    stage1->s1ChildHoodTraitsSwp3Int = 0;

    stage1->s1ChildHoodSkillsSwp4.clear();
    stage1->s1ChildHoodSkillsSwp4Int = 0;
    stage1->s1ChildHoodTraitsSwp4.clear();
    stage1->s1ChildHoodTraitsSwp4Int = 0;

    S1ChangeElem1Main(ui->S1ComboBoxElem1->currentText());
    S1ChangeElem2Main(ui->S1ComboBoxElem2->currentText());
    S1ChangeElem3Main(ui->S1ComboBoxElem3->currentText());
    S1Change();
    chr_dat->earlyChildName.first = ui->S1ChComboBox->currentText();
    chr_dat->earlyChildName.second = ui->S1ChComboBox->currentIndex();

}

void Wizard::S1AddAffilAttr() {
    changeXP(stage1->s1XpCost, true);
    QMapIterator <QString, int> i(stage1->s1Attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] + i.value();
    }
}

void Wizard::S1AddAfillSkill()
{
    int swapCount = stage1->s1Skills.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(stage1->s1Skills[sCount].first,stage1->s1Skills[sCount].second);
    }
}

void Wizard::S1AddAfillTraits()
{
    int swapCount = stage1->s1Traits.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeTraits(stage1->s1Traits[sCount].first,stage1->s1Traits[sCount].second);
    }
}

void Wizard::S1RemoveOldParam() {
    changeXP(stage1->s1XpCost, false);
    QMapIterator <QString, int> i(stage1->s1Attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
    }

    int swapCount = stage1->s1Skills.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(stage1->s1Skills[sCount].first, -stage1->s1Skills[sCount].second);
    }


    swapCount = stage1->s1Traits.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeTraits(stage1->s1Traits[sCount].first,-stage1->s1Traits[sCount].second);
    }

}

void Wizard::S1Change() {


    ui->S1StatusXP->setText(QString::number(chr_dat->xp));
    ui->S1StatusXP->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    // 
    ui->S1AttrStrLabel->setText("<b>STR:</b> " + QString::number(chr_dat->charAttr.value("STR")));
    ui->S1AttrBodLabel->setText("<b>BOD:</b> " + QString::number(chr_dat->charAttr.value("BOD")));
    ui->S1AttrRflLabel->setText("<b>RFL:</b> " + QString::number(chr_dat->charAttr.value("RFL")));
    ui->S1AttrDexLabel->setText("<b>DEX:</b> " + QString::number(chr_dat->charAttr.value("DEX")));
    ui->S1AttrIntLabel->setText("<b>INT:</b>  " + QString::number(chr_dat->charAttr.value("INT")));
    ui->S1AttrWilLabel->setText("<b>WIL:</b> " + QString::number(chr_dat->charAttr.value("WIL")));
    ui->S1AttrChaLabel->setText("<b>CHA:</b> " + QString::number(chr_dat->charAttr.value("CHA")));
    ui->S1AttrEdgLabel->setText("<b>EDG:</b> " + QString::number(chr_dat->charAttr.value("EDG")));
    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    // 
    S1PrintSkillsTable();
    S1PrintTraitsTable();

}

void Wizard::S1PrintSkillsTable() {
    ui->S1SkillsTable->clear();
    qSort(chr_dat->charSkills.begin(), chr_dat->charSkills.end());
    ui->S1SkillsTable->setRowCount(chr_dat->charSkills.count());

    for(int sCount = 0 ; sCount < chr_dat->charSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charSkills[sCount].first);
        newSNameItem->setToolTip(SkillDesc(chr_dat->charSkills[sCount].first));
        ui->S1SkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charSkills[sCount].second));
        ui->S1SkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S1PrintTraitsTable()
{
    ui->S1TraitsTable->clear();
    qSort(chr_dat->charTraits.begin(), chr_dat->charTraits.end());
    ui->S1TraitsTable->setRowCount(chr_dat->charTraits.count());
    for(int sCount = 0 ; sCount < chr_dat->charTraits.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charTraits[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(chr_dat->charTraits[sCount].first));
        ui->S1TraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charTraits[sCount].second));
        ui->S1TraitsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S1ComBoxChange() {
    if (stage1->s1ChildHoodSkills1 != 0 || stage1->s1ChildHoodTraits1 != 0) {
        ui->S1ComboBoxElem1->clear();
        ui->S1LabelElem1->clear();
        ui->S1ComboBoxElem1->setEnabled(true);
        ui->S1LabelElem1->setText(stage1->s1ChildHoodLabel1);
        ui->S1ComboBoxElem1->addItems(stage1->s1ChildHoodAttr1);
    } else {
        if (stage1->s1Phenotype.isEmpty() !=  true) {
            ui->S1ComboBoxElem1->clear();
            ui->S1LabelElem1->clear();
            ui->S1ComboBoxElem1->setEnabled(true);
            ui->S1LabelElem1->setText(stage1->s1ChildHoodLabel1);
            ui->S1ComboBoxElem1->addItems(stage1->s1Phenotype);
        } else {
            ui->S1ComboBoxElem1->clear();
            ui->S1LabelElem1->clear();
            ui->S1ComboBoxElem1->setEnabled(false);
            stage1->s1Phenotype.clear();
        }
    }



    if (stage1->s1ChildHoodSkills2 != 0 || stage1->s1ChildHoodTraits2 != 0) {
        ui->S1ComboBoxElem2->clear();
        ui->S1LabelElem2->clear();
        ui->S1ComboBoxElem2->setEnabled(true);
        ui->S1LabelElem2->setText(stage1->s1ChildHoodLabel2);
        ui->S1ComboBoxElem2->addItems(stage1->s1ChildHoodAttr2);
    } else {
        ui->S1ComboBoxElem2->clear();
        ui->S1LabelElem2->clear();
        ui->S1ComboBoxElem2->setEnabled(false);
        stage1->s1ChildHoodAttr2.clear();
    }

    if (stage1->s1ChildHoodSkills3 != 0 || stage1->s1ChildHoodTraits3 != 0) {
        ui->S1ComboBoxElem3->clear();
        ui->S1LabelElem3->clear();
        ui->S1ComboBoxElem3->setEnabled(true);
        ui->S1LabelElem3->setText(stage1->s1ChildHoodLabel3);
        ui->S1ComboBoxElem3->addItems(stage1->s1ChildHoodAttr3);
    } else {
        ui->S1ComboBoxElem3->clear();
        ui->S1LabelElem3->clear();
        ui->S1ComboBoxElem3->setEnabled(false);
        stage1->s1ChildHoodAttr3.clear();
    }

    if (stage1->s1ChildHoodSkills4 != 0 || stage1->s1ChildHoodTraits4 != 0) {
        ui->S1ComboBoxElem4->clear();
        ui->S1LabelElem4->clear();
        ui->S1ComboBoxElem4->setEnabled(true);
        ui->S1LabelElem4->setText(stage1->s1ChildHoodLabel4);
        ui->S1ComboBoxElem4->addItems(stage1->s1ChildHoodAttr4);
    } else {
        ui->S1ComboBoxElem4->clear();
        ui->S1LabelElem4->clear();
        ui->S1ComboBoxElem4->setEnabled(false);
        stage1->s1ChildHoodAttr4.clear();
    }
}

void Wizard::S1ChangeElem1(QString nameElem) {

     if (stage1->s1Phenotype.isEmpty() !=  true) {
         chr_dat->phenotype = nameElem;
     }

    if (ui->S1ChComboBox->currentIndex() == 2) {
        S1RemoveOldParam();
        ++stage1->s1CountElem1;
        if (stage1->s1ChildHoodSkillsSwp1.isEmpty() != true) {
            stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp1,-stage1->s1ChildHoodSkillsSwp1Int);
            stage1->s1ChildHoodSkillsSwp1.clear();
            stage1->s1ChildHoodSkillsSwp1Int = 0;
        }
        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills1);
        if (stage1->s1CountElem1 == 2) {
            ui->S1ComboBoxElem1->setEnabled(false);
            stage1->s1CountElem1 = 0;

        }
        S1AddAffilAttr();
        S1AddAfillSkill();
        S1AddAfillTraits();
        S1Change();
    } else {
        S1ChangeElem1Main(nameElem);
    }

}

void Wizard::S1ChangeElem1Main(QString nameElem) {
    S1RemoveOldParam();
    if (stage1->s1ChildHoodSkills1 != 0) {
        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills1);
        if (stage1->s1ChildHoodSkillsSwp1.isEmpty() != true) {
            stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp1,-stage1->s1ChildHoodSkillsSwp1Int);
        }
        stage1->s1ChildHoodSkillsSwp1 = nameElem;
        stage1->s1ChildHoodSkillsSwp1Int = stage1->s1ChildHoodSkills1;
    }

    if (stage1->s1ChildHoodTraits1 != 0) {
        stage1->S1AddTraits(nameElem,stage1->s1ChildHoodTraits1);
        if (stage1->s1ChildHoodTraitsSwp1.isEmpty() != true) {
            stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp1,-stage1->s1ChildHoodTraitsSwp1Int);
        }
        stage1->s1ChildHoodTraitsSwp1 = nameElem;
        stage1->s1ChildHoodTraitsSwp1Int = stage1->s1ChildHoodTraits1;
    }

    S1AddAffilAttr();
    S1AddAfillSkill();
    S1AddAfillTraits();
    S1Change();
}

void Wizard::S1ChangeElem2(QString nameElem) {

    if (ui->S1ChComboBox->currentIndex() == 1) {
        S1RemoveOldParam();
        ++stage1->s1CountElem2;
        if (stage1->s1ChildHoodSkillsSwp2.isEmpty() != true) {
            stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp2,-stage1->s1ChildHoodSkillsSwp2Int);
            stage1->s1ChildHoodSkillsSwp2.clear();
            stage1->s1ChildHoodSkillsSwp2Int = 0;
        }
        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills2);
        if (stage1->s1CountElem2 == 2) {
            ui->S1ComboBoxElem2->setEnabled(false);
            stage1->s1CountElem2 = 0;

        }
        S1AddAffilAttr();
        S1AddAfillSkill();
        S1AddAfillTraits();
        S1Change();
    } else {
        S1ChangeElem2Main(nameElem);
    }


}

void Wizard::S1ChangeElem2Main(QString nameElem) {
    S1RemoveOldParam();
    if (stage1->s1ChildHoodSkills2 != 0) {
        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills2);
        if (stage1->s1ChildHoodSkillsSwp2.isEmpty() != true) {
            stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp2,-stage1->s1ChildHoodSkillsSwp2Int);
        }
        stage1->s1ChildHoodSkillsSwp2 = nameElem;
        stage1->s1ChildHoodSkillsSwp2Int = stage1->s1ChildHoodSkills2;
    }

    if (stage1->s1ChildHoodTraits2 != 0) {
        stage1->S1AddTraits(nameElem,stage1->s1ChildHoodTraits2);
        if (stage1->s1ChildHoodTraitsSwp2.isEmpty() != true) {
            stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp2,-stage1->s1ChildHoodTraitsSwp2Int);
        }
        stage1->s1ChildHoodTraitsSwp2 = nameElem;
        stage1->s1ChildHoodTraitsSwp2Int = stage1->s1ChildHoodTraits2;
    }

    S1AddAffilAttr();
    S1AddAfillSkill();
    S1AddAfillTraits();
    S1Change();
}
void Wizard::S1ChangeElem3(QString nameElem) {
    if(stage1->s1ChildHoodNumber == 6) {
        S1ChangeElem3Main(nameElem);
        ++stage1->s1CountElem3;
        if (stage1->s1CountElem3 == 1) {
            ui->S1ComboBoxElem3->clear();
            ui->S1LabelElem3->setText(stage1->s1MoreTraitsLabel);
            ui->S1ComboBoxElem3->addItems(stage1->s1MoreTraits);
            stage1->s1ChildHoodTraits3 = stage1->s1MoreTraitsAttr;
            stage1->s1ChildHoodSkills3 = 0;
        } else {
            S1ChangeElem3Main(nameElem);
        }
    } else {
        S1ChangeElem3Main(nameElem);
    }
}

void Wizard::S1ChangeElem3Main(QString nameElem) {
    S1RemoveOldParam();
    if (stage1->s1ChildHoodSkills3 != 0) {
        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills3);
        if (stage1->s1ChildHoodSkillsSwp3.isEmpty() != true) {
            stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp3,-stage1->s1ChildHoodSkillsSwp3Int);
        }
        stage1->s1ChildHoodSkillsSwp3 = nameElem;
        stage1->s1ChildHoodSkillsSwp3Int = stage1->s1ChildHoodSkills3;
    }

    if (stage1->s1ChildHoodTraits3 != 0) {
        stage1->S1AddTraits(nameElem,stage1->s1ChildHoodTraits3);
        if (stage1->s1ChildHoodTraitsSwp3.isEmpty() != true) {
            stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp3,-stage1->s1ChildHoodTraitsSwp3Int);
        }
        stage1->s1ChildHoodTraitsSwp3 = nameElem;
        stage1->s1ChildHoodTraitsSwp3Int = stage1->s1ChildHoodTraits3;
    }

    S1AddAffilAttr();
    S1AddAfillSkill();
    S1AddAfillTraits();
    S1Change();
}

void Wizard::S1ChangeElem4(QString nameElem) {

    S1RemoveOldParam();

//    switch(stage1->s1ChildHoodNumber) {
//    case 0:
//        ++stage1->s1CountElem4;
//        S1ShortFlex(nameElem);
//        if (stage1->s1CountElem4 == 2) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 1:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 3:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 4:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 5:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 6:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 7:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 4) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 8:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 5) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 9:
//        ++stage1->s1CountElem4;
//        S1ShortFlex(nameElem);
//        if (stage1->s1CountElem4 == 3) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    case 10:
//        ++stage1->s1CountElem4;
//        S1ShortLong(nameElem);
//        if (stage1->s1CountElem4 == 3) {
//            ui->S1ComboBoxElem4->setEnabled(false);
//        }
//        break;
//    default:
//        qDebug() << "ERROR!!!!";
//        break;

//    }
//    if (stage1->s1CountElem4 == 1) {
//        stage1->s1Attr["STR"] -= stage1->s1ChildHoodSkills4;
//    }


    if(ui->S1ChComboBox->currentText() == "Slave") {
        if (stage1->s1ChildHoodTraits4 != 0) {
            stage1->S1AddTraits(nameElem,stage1->s1ChildHoodTraits4);
            if (stage1->s1ChildHoodTraitsSwp4.isEmpty() != true) {
                stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp4,-stage1->s1ChildHoodTraitsSwp4Int);
            }
            stage1->s1ChildHoodTraitsSwp4 = nameElem;
            stage1->s1ChildHoodTraitsSwp4Int = stage1->s1ChildHoodTraits4;
        }
    }

    if(ui->S1ChComboBox->currentText() == "Trueborn Creche") {
        if(ui->S1ComboBoxElem4->currentIndex() < 8) {
            if(!stage1->s1ChildHoodTraitsSwp4.isEmpty()) {
                stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp4,-stage1->s1ChildHoodTraitsSwp4Int);
                stage1->s1ChildHoodTraitsSwp4.clear();
            }

            if(!stage1->s1ChildHoodSkillsSwp4.isEmpty()) {
                stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp4,-stage1->s1ChildHoodSkillsSwp4Int);
                stage1->s1ChildHoodSkillsSwp4.clear();
            }

            if(!stage1->s1ChildHoodAttrSwp4.isEmpty()) {
                chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] = chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] - stage1->s1ChildHoodAttrSwp4Int;
                stage1->s1ChildHoodAttrSwp4.clear();
            }

            stage1->s1ChildHoodAttrSwp4 = nameElem;
            stage1->s1ChildHoodAttrSwp4Int = stage1->s1ChildHoodSkills4;

//            stage1->s1Attr[nameElem] += stage1->s1ChildHoodSkills4;
            chr_dat->charAttr[nameElem] += stage1->s1ChildHoodSkills4;
        }

        if(ui->S1ComboBoxElem4->currentIndex() > 7 && ui->S1ComboBoxElem4->currentIndex() < 65) {

            if(!stage1->s1ChildHoodTraitsSwp4.isEmpty()) {
                stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp4,-stage1->s1ChildHoodTraitsSwp4Int);
                stage1->s1ChildHoodTraitsSwp4.clear();
            }

            if(!stage1->s1ChildHoodSkillsSwp4.isEmpty()) {
                stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp4,-stage1->s1ChildHoodSkillsSwp4Int);
                stage1->s1ChildHoodSkillsSwp4.clear();
            }

            if(!stage1->s1ChildHoodAttrSwp4.isEmpty()) {
                chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] = chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] - stage1->s1ChildHoodAttrSwp4Int;
                stage1->s1ChildHoodAttrSwp4.clear();
            }

            stage1->s1ChildHoodTraitsSwp4 = nameElem;
            stage1->s1ChildHoodTraitsSwp4Int = stage1->s1ChildHoodSkills4;

            stage1->S1AddTraits(nameElem,stage1->s1ChildHoodSkills4);
        }

        if(ui->S1ComboBoxElem4->currentIndex() > 64) {
            if(!stage1->s1ChildHoodTraitsSwp4.isEmpty()) {
                stage1->S1AddTraits(stage1->s1ChildHoodTraitsSwp4,-stage1->s1ChildHoodTraitsSwp4Int);
                stage1->s1ChildHoodTraitsSwp4.clear();
            }

            if(!stage1->s1ChildHoodSkillsSwp4.isEmpty()) {
                stage1->S1AddSkills(stage1->s1ChildHoodSkillsSwp4,-stage1->s1ChildHoodSkillsSwp4Int);
                stage1->s1ChildHoodSkillsSwp4.clear();
            }

            if(!stage1->s1ChildHoodAttrSwp4.isEmpty()) {
                chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] = chr_dat->charAttr[stage1->s1ChildHoodAttrSwp4] - stage1->s1ChildHoodAttrSwp4Int;
                stage1->s1ChildHoodAttrSwp4.clear();
            }

            stage1->s1ChildHoodSkillsSwp4 = nameElem;
            stage1->s1ChildHoodSkillsSwp4Int = stage1->s1ChildHoodSkills4;

            stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills4);
        }
    }

    S1AddAffilAttr();
    S1AddAfillSkill();
    S1AddAfillTraits();
    S1Change();
}

//void Wizard::S1ShortFlex(QString nameElem) {
//    if (ui->S1ComboBoxElem4->currentIndex() < 8) {
//        stage1->s1Attr[nameElem] += stage1->s1ChildHoodSkills4;
//    } else {
//        stage1->S1AddTraits(nameElem,stage1->s1ChildHoodSkills4);
//    }
//}

//void Wizard::S1ShortLong(QString nameElem) {

//    if (ui->S1ComboBoxElem4->currentIndex() < 8) {
//        stage1->s1Attr[nameElem] += stage1->s1ChildHoodSkills4;
//    }
//    if ( ui->S1ComboBoxElem4->currentIndex() >= 8 && ui->S1ComboBoxElem4->currentIndex() < 65){
//        stage1->S1AddTraits(nameElem,stage1->s1ChildHoodSkills4);
//    }

//    if (ui->S1ComboBoxElem4->currentIndex() >= 65) {
//        stage1->S1AddSkills(nameElem,stage1->s1ChildHoodSkills4);
//    }
//}

//!!!!!!!!!!!!--------------------STAGE2--------------------!!!!!!!!!!!!//

void Wizard::S2ConnectEvent() {
    connect(ui->S2FlexXPPushButton, SIGNAL(clicked()), this, SLOT(S2FlexXpButton()));
    connect(ui->S2MorePushButton, SIGNAL(clicked()), this, SLOT(S2AdvButton()));
    connect(ui->S2ChComboBox, SIGNAL(activated(QString)), this, SLOT(S2ChangeLateChildHood(QString)));
    connect(ui->S2ComboBoxElem1, SIGNAL(activated(QString)), this, SLOT(S2ChangeElem1(QString)));
    connect(ui->S2ComboBoxElem2, SIGNAL(activated(QString)), this, SLOT(S2ChangeElem2(QString)));
    connect(ui->S2ComboBoxElem3, SIGNAL(activated(QString)), this, SLOT(S2ChangeElem3(QString)));

    connect(s2advdial, SIGNAL(accepted()), this, SLOT(S2AdvDialAcceptButton()));
    connect(s2advdial, SIGNAL(rejected()),this, SLOT(S2AdvDialCancelButton()));
    connect(s2clanfield, SIGNAL(accepted()), this, SLOT(S2AdvDialAcceptButton()));
    connect(s2fxpdialog, SIGNAL(accepted()), this, SLOT(S2FlexXpButtonAcceptButton()));
    connect(s2fxpdialog, SIGNAL(rejected()), this, SLOT(S2FlexXpButtonCancelButton()));
}

void Wizard::S2FlexXpButton() {

    switch (this->currentId()) {
    case 3:
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S2Change();
        s2fxpdialog->s2FXDFreeXPLabelInit = stage2->s2FlexXP;
        s2fxpdialog->s2FXDNameChillHood = ui->S2ChComboBox->currentText();
        break;
    case 4:
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S2Change();
        s2fxpdialog->s2FXDFreeXPLabelInit = stage3->s3FlexXP;
        s2fxpdialog->s2FXDNameChillHood = ui->S3SchoolComboBox->currentText();
        break;
    case 5:
        S2DelSkills(s2fxpdialog->s2FXDSkills);
        S2DelTraits(s2fxpdialog->s2FXDTraits);
        S2DelAttr(s2fxpdialog->s2FXDCharAttr);
        S4Change();
        s2fxpdialog->s2FXDFreeXPLabelInit = stage4->s4FlexXP;
        s2fxpdialog->s2FXDNameChillHood = ui->S4LifeComboBox->currentText();
        break;
    default:
        break;
    }

//    qDebug() << this->currentId();

//    ui->PageStage2->setDisabled(true);
//    this->button(Wizard::NextButton)->setDisabled(true);
//    this->button(Wizard::BackButton)->setDisabled(true);


    s2fxpdialog->s2FXDStr = chr_dat->charAttr["STR"];
    s2fxpdialog->s2FXDBod = chr_dat->charAttr["BOD"];
    s2fxpdialog->s2FXDRfl = chr_dat->charAttr["RFL"];
    s2fxpdialog->s2FXDDex = chr_dat->charAttr["DEX"];
    s2fxpdialog->s2FXDInt = chr_dat->charAttr["INT"];
    s2fxpdialog->s2FXDWil = chr_dat->charAttr["WIL"];
    s2fxpdialog->s2FXDCha = chr_dat->charAttr["CHA"];
    s2fxpdialog->s2FXDEdg = chr_dat->charAttr["EDG"];
    s2fxpdialog->s2FXDAllSkills = txt_res->allSkills;
    s2fxpdialog->s2FXDAllTraits = txt_res->allTraits;

    s2fxpdialog->s2FXDSkillsInit = chr_dat->charSkills;
    s2fxpdialog->s2FXDTraitsInit = chr_dat->charTraits;



    s2fxpdialog->S2FlexXPDialogInit();
    s2fxpdialog->s2FXSubSkillList = subSkillList;

    s2fxpdialog->show();
    s2fxpdialog->raise();
    s2fxpdialog->activateWindow();

    chkFlexButton = true;
    if(chkAdvButton == true) {
        this->button(Wizard::NextButton)->setDisabled(false);
    } else {
        this->button(Wizard::NextButton)->setDisabled(true);
    }
}

void Wizard::S2FlexXpButtonAcceptButton() {

    switch (this->currentId()) {
    case 3:
        AddAffilAttr(s2fxpdialog->s2FXDCharAttr);
        AddAfillSkill(s2fxpdialog->s2FXDSkills);
        AddAfillTraits(s2fxpdialog->s2FXDTraits);
        S2Change();
        break;
    case 4:
        AddAffilAttr(s2fxpdialog->s2FXDCharAttr);
        AddAfillSkill(s2fxpdialog->s2FXDSkills);
        AddAfillTraits(s2fxpdialog->s2FXDTraits);
        S3Change();
        break;
    case 5:
        AddAffilAttr(s2fxpdialog->s2FXDCharAttr);
        AddAfillSkill(s2fxpdialog->s2FXDSkills);
        AddAfillTraits(s2fxpdialog->s2FXDTraits);
        S4Change();
        break;
    default:
        break;
    }
}

void Wizard::S2FlexXpButtonCancelButton() {
    s2fxpdialog->S2FlexXPDialogInit();
}

void Wizard::S2AdvButton() {

    switch (this->currentId()) {
    case 3:
        S2RemoveOldParam();
        if(ui->S2ChComboBox->currentText() == "Freeborn Sibko" || ui->S2ChComboBox->currentText() == "Trueborn Sibko") {


            s2clanfield->s2CFDBasicList = stage2->S2ClanBasicFieldChange(ui->Sub_Aff_ComBox->currentText());
            s2clanfield->s2CFDAdvList = stage2->s2ClanAdvFieldList;

            s2clanfield->s2CFDClanBasicRebateXP = stage2->s2ClanBasicRebateXP;
            s2clanfield->s2CFDClanBasicXP = stage2->s2ClanBasicXP;
            s2clanfield->s2CFDClanBasicStepXP = stage2->s2ClanBasicStepXP;
            s2clanfield->s2CFDClanAdvRebateXP = stage2->s2ClanAdvRebateXP;
            s2clanfield->s2CFDClanAdvXP = stage2->s2ClanAdvXP;
            s2clanfield->s2CFDClanAdvStepXP = stage2->s2ClanAdvStepXP;


            s2clanfield->s2CFDClanAdvLabel = ui->S2ComboBoxElem1->currentText();

            for (int i =0; i < s2clanfield->s2CFDClanBasicSkills.count(); i++) {
                stage2->S2AddSkills(s2clanfield->s2CFDClanBasicSkills[i].first, -s2clanfield->s2CFDClanBasicSkills[i].second );
            }

            for (int i =0; i < s2clanfield->s2CFDClanAdvSkills.count(); i++) {
                stage2->S2AddSkills(s2clanfield->s2CFDClanAdvSkills[i].first, -s2clanfield->s2CFDClanAdvSkills[i].second );
            }
            s2clanfield->S2CFDInit();

            s2clanfield->show();
            s2clanfield->raise();
            s2clanfield->activateWindow();

        } else {

            if(s2advdial->s2AdvDialSkills.isEmpty() != true) {
                for (int i =0; i < s2advdial->s2AdvDialSkills.count(); i++) {
                    stage2->S2AddSkills(s2advdial->s2AdvDialSkills[i].first,-s2advdial->s2AdvDialSkills[i].second );
                }
            }
            s2advdial->S2AdvDialClearAll();

            s2advdial->s2AdvDialogAttr1 = stage2->s2ChildHoodAttrAdv1;
            s2advdial->s2AdvDialogLabel1 = stage2->s2ChildHoodLabelAdv1;
            s2advdial->s2AdvDialogSkills1 = stage2->s2ChildHoodSkillsAdv1;

            s2advdial->s2AdvDialogAttr2 = stage2->s2ChildHoodAttrAdv2;
            s2advdial->s2AdvDialogLabel2 = stage2->s2ChildHoodLabelAdv2;
            s2advdial->s2AdvDialogSkills2 = stage2->s2ChildHoodSkillsAdv2;

            s2advdial->s2AdvDialogAttr3 = stage2->s2ChildHoodAttrAdv3;
            s2advdial->s2AdvDialogLabel3 = stage2->s2ChildHoodLabelAdv3;
            s2advdial->s2AdvDialogSkills3 = stage2->s2ChildHoodSkillsAdv3;

            s2advdial->s2AdvDialogAttr4 = stage2->s2ChildHoodAttrAdv4;
            s2advdial->s2AdvDialogLabel4 = stage2->s2ChildHoodLabelAdv4;
            s2advdial->s2AdvDialogSkills4 = stage2->s2ChildHoodSkillsAdv4;

            s2advdial->S2AdvDialInit();

            s2advdial->show();
            s2advdial->raise();
            s2advdial->activateWindow();

            AddAffilAttr(stage2->s2Attr);
            changeXP(stage2->s2XpCost, true);
            AddAfillSkill(stage2->s2Skills);
            AddAfillTraits(stage2->s2Traits);
            S2Change();
            break;
    case 4:
            S3RemoveOldParam();
            if(s2advdial->s2AdvDialSkills.isEmpty() != true) {
                for (int i =0; i < s2advdial->s2AdvDialSkills.count(); i++) {
                    if(s2advdial->s2AdvDialSkills[i].first == "Equipped" || s2advdial->s2AdvDialSkills[i].first == "Vehicle") {
                        chr_dat->changeTraits(s2advdial->s2AdvDialSkills[i].first,-s2advdial->s2AdvDialSkills[i].second);
                    } else {
                        chr_dat->changeSkills(s2advdial->s2AdvDialSkills[i].first,-s2advdial->s2AdvDialSkills[i].second);
                    }

                }
            }

            if(s2advdial->s2AdvDialOther.isEmpty() != true ) {
                if(s2advdial->s2AdvDialOther[0].first.count() == 3) {
                    chr_dat->charAttr[s2advdial->s2AdvDialOther[0].first] -= s2advdial->s2AdvDialOther[0].second;
                }
            }


            s2advdial->S2AdvDialClearAll();
            s2advdial->s2AdvDialogAttr1 = stage3->s3ChildHoodAttrAdv1;
            s2advdial->s2AdvDialogLabel1 = stage3->s3ChildHoodLabelAdv1;
            s2advdial->s2AdvDialogSkills1 = stage3->s3ChildHoodSkillsAdv1;

            s2advdial->s2AdvDialogAttr2 = stage3->s3ChildHoodAttrAdv2;
            s2advdial->s2AdvDialogLabel2 = stage3->s3ChildHoodLabelAdv2;
            s2advdial->s2AdvDialogSkills2 = stage3->s3ChildHoodSkillsAdv2;

            s2advdial->s2AdvDialogAttr3 = stage3->s3ChildHoodAttrAdv3;
            s2advdial->s2AdvDialogLabel3 = stage3->s3ChildHoodLabelAdv3;
            s2advdial->s2AdvDialogSkills3 = stage3->s3ChildHoodSkillsAdv3;

            s2advdial->s2AdvDialogAttr4 = stage3->s3ChildHoodAttrAdv4;
            s2advdial->s2AdvDialogLabel4 = stage3->s3ChildHoodLabelAdv4;
            s2advdial->s2AdvDialogSkills4 = stage3->s3ChildHoodSkillsAdv4;

            s2advdial->S2AdvDialInit();

            s2advdial->show();
            s2advdial->raise();
            s2advdial->activateWindow();

            AddAffilAttr(stage3->s3Attr);
            changeXP(stage3->s3XpCost, true);
            AddAfillSkill(stage3->s3Skills);
            AddAfillTraits(stage3->s3Traits);
            S3Change();
            break;
    case 5:

            break;
    default:
            break;
        }
    }

    chkAdvButton = true;

    if(chkFlexButton == true) {
        this->button(Wizard::NextButton)->setDisabled(false);
    } else {
        this->button(Wizard::NextButton)->setDisabled(true);
    }


}

void Wizard::S2AdvDialAcceptButton() {
    this->button(Wizard::NextButton)->setDisabled(false);

    switch (this->currentId()) {
    case 3:
        S2RemoveOldParam();
        if(ui->S2ChComboBox->currentText() == "Freeborn Sibko" || ui->S2ChComboBox->currentText() == "Trueborn Sibko") {
            for (int i =0; i < s2clanfield->s2CFDClanBasicSkills.count(); i++) {
                stage2->S2AddSkills(s2clanfield->s2CFDClanBasicSkills[i].first, s2clanfield->s2CFDClanBasicSkills[i].second );
            }

            for (int i =0; i < s2clanfield->s2CFDClanAdvSkills.count(); i++) {
                stage2->S2AddSkills(s2clanfield->s2CFDClanAdvSkills[i].first, s2clanfield->s2CFDClanAdvSkills[i].second );
            }
        } else {
            for (int i =0; i < s2advdial->s2AdvDialSkills.count(); i++) {
                stage2->S2AddSkills(s2advdial->s2AdvDialSkills[i].first,s2advdial->s2AdvDialSkills[i].second );
            }
        }


        AddAffilAttr(stage2->s2Attr);
        changeXP(stage2->s2XpCost, true);
        AddAfillSkill(stage2->s2Skills);
        AddAfillTraits(stage2->s2Traits);
        S2Change();
        break;
    case 4:
        S3RemoveOldParam();


        for (int i =0; i < s2advdial->s2AdvDialSkills.count(); i++) {
            if(s2advdial->s2AdvDialSkills[i].first == "Equipped" || s2advdial->s2AdvDialSkills[i].first == "Vehicle") {
                chr_dat->changeTraits(s2advdial->s2AdvDialSkills[i].first,s2advdial->s2AdvDialSkills[i].second);
            } else {
                chr_dat->changeSkills(s2advdial->s2AdvDialSkills[i].first,s2advdial->s2AdvDialSkills[i].second);
            }

        }

        if(s2advdial->s2AdvDialOther.isEmpty() != true ) {
            if(s2advdial->s2AdvDialOther[0].first.count() == 3) {
                chr_dat->charAttr[s2advdial->s2AdvDialOther[0].first] += s2advdial->s2AdvDialOther[0].second;
            }
        }


        AddAffilAttr(stage3->s3Attr);
        changeXP(stage3->s3XpCost, true);
        AddAfillSkill(stage3->s3Skills);
        AddAfillTraits(stage3->s3Traits);
        S3Change();
        ui->S3SChoolAddButton->setEnabled(true);
        break;
    default:
        break;
    }
}

void Wizard::S2AdvDialCancelButton() {
    s2advdial->s2AdvDialSkills.clear();
    s2advdial->s2AdvDialOther.clear();
}

void Wizard::Stage2Main() {
    stage2 = new Stage2;

    stage2->subSkillList = subSkillList;

    s2fxpdialog->S2FlexXPDialogInit();
    ui->S2NameLabel->setText(chr_dat->charName); //    
    ui->S2AffLabel->setText(chr_dat->AffName.first); //      
    ui->S2SubAffLabel->setText(chr_dat->subAffName.first); //    
    ui->S2CasteLabel->setText(chr_dat->clanCastName.first); //    
    ui->S2EarlyLabel->setText(chr_dat->earlyChildName.first); //    

    ui->S2ChComboBox->clear();
    QStringList tempElem;
    tempElem = stage2->S2HardElemAffil(chr_dat->charTraits, chr_dat->AffName.second, chr_dat->subAffName.second);
//    qDebug() << tempElem << chr_dat->charTraits << chr_dat->AffName.second << chr_dat->subAffName.second;

    ui->S2ChComboBox->addItems(stage2->S2ClearListElem(tempElem, chr_dat->earlyChildName.first,chr_dat->AffName.second));
//    qDebug() << stage2->S2ClearListElem(tempElem, chr_dat->earlyChildName.first,chr_dat->AffName.second) << tempElem << chr_dat->earlyChildName.first << chr_dat->AffName.second;
    S2ChangeLateChildHood(ui->S2ChComboBox->currentText());

    S2Change();

}

void Wizard::S2ChangeLateChildHood(QString nameElem) {
    chkAdvButton = false;
    chkFlexButton = false;
    this->button(Wizard::NextButton)->setDisabled(true);
    S2RemoveOldParam();
    stage2->s2XpCost = 0;
    stage2->s2Attr.clear();
    stage2->s2Skills.clear();
    stage2->s2Traits.clear();

    stage2->S2LateChildhood(nameElem, chr_dat->clanCastName.first);
    ui->S2ChComboBox->setToolTip(stage2->s2toolTip);
    S2ComBoxChange();

    if (stage2->s2AffLang != 0) {
        stage2->S2AddSkills(ui->lang_ZStage_ComboBox->currentText(), stage2->s2AffLang);
    }

    if (stage2->s2AffProt != 0) {
        stage2->S2AddSkills(txt_res->affProtocol, stage2->s2AffProt);
    }

    if (stage2->s2AffStreet != 0) {
        stage2->S2AddSkills(txt_res->affStreet, stage2->s2AffStreet);
    }

    AddAffilAttr(stage2->s2Attr);
    changeXP(stage2->s2XpCost, true);
    AddAfillSkill(stage2->s2Skills);
    AddAfillTraits(stage2->s2Traits);

    stage2->s2ChildHoodSkillsSwp1.clear();
    stage2->s2ChildHoodSkillsSwp1Int = 0;
    stage2->s2ChildHoodTraitsSwp1.clear();
    stage2->s2ChildHoodTraitsSwp1Int = 0;

    stage2->s2ChildHoodSkillsSwp2.clear();
    stage2->s2ChildHoodSkillsSwp2Int = 0;
    stage2->s2ChildHoodTraitsSwp2.clear();
    stage2->s2ChildHoodTraitsSwp2Int = 0;

    stage2->s2ChildHoodSkillsSwp3.clear();
    stage2->s2ChildHoodSkillsSwp3Int = 0;
    stage2->s2ChildHoodTraitsSwp3.clear();
    stage2->s2ChildHoodTraitsSwp3Int = 0;

    S2ChangeElem1Main(ui->S2ComboBoxElem1->currentText());
    S2ChangeElem2Main(ui->S2ComboBoxElem2->currentText());
    S2ChangeElem3(ui->S2ComboBoxElem3->currentText());

    S2Change();


    if (stage2->s2ChildHoodLabelAdv1.isEmpty() == true) {
        if(ui->S2ChComboBox->currentText() == "Freeborn Sibko" || ui->S2ChComboBox->currentText() == "Trueborn Sibko") {
            ui->S2MorePushButton->setEnabled(true);
//            this->button(Wizard::NextButton)->setDisabled(true);
        } else {
            chkAdvButton = true;
            ui->S2MorePushButton->setEnabled(false);
//            this->button(Wizard::NextButton)->setDisabled(false);
        }
    } else {
        ui->S2MorePushButton->setEnabled(true);
//        this->button(Wizard::NextButton)->setDisabled(true);
    }

}


void Wizard::S2Change() {

    ui->S2StatusXP->setText(QString::number(chr_dat->xp));
    ui->S2StatusXP->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));
    // 
    ui->S2AttrStrLabel->setText("<b>STR:</b> " + QString::number(chr_dat->charAttr.value("STR")));
    ui->S2AttrBodLabel->setText("<b>BOD:</b> " + QString::number(chr_dat->charAttr.value("BOD")));
    ui->S2AttrRflLabel->setText("<b>RFL:</b> " + QString::number(chr_dat->charAttr.value("RFL")));
    ui->S2AttrDexLabel->setText("<b>DEX:</b> " + QString::number(chr_dat->charAttr.value("DEX")));
    ui->S2AttrIntLabel->setText("<b>INT:</b>  " + QString::number(chr_dat->charAttr.value("INT")));
    ui->S2AttrWilLabel->setText("<b>WIL:</b> " + QString::number(chr_dat->charAttr.value("WIL")));
    ui->S2AttrChaLabel->setText("<b>CHA:</b> " + QString::number(chr_dat->charAttr.value("CHA")));
    ui->S2AttrEdgLabel->setText("<b>EDG:</b> " + QString::number(chr_dat->charAttr.value("EDG")));
    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    // 
    S2PrintSkillsTable();
    S2PrintTraitsTable();

}

void Wizard::S2PrintSkillsTable() {
    ui->S2SkillsTable->clear();
    qSort(chr_dat->charSkills.begin(), chr_dat->charSkills.end());
    ui->S2SkillsTable->setRowCount(chr_dat->charSkills.count());

    for(int sCount = 0 ; sCount < chr_dat->charSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charSkills[sCount].first);
        newSNameItem->setToolTip(SkillDesc(chr_dat->charSkills[sCount].first));
        ui->S2SkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charSkills[sCount].second));
        ui->S2SkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S2PrintTraitsTable()
{
    ui->S2TraitsTable->clear();
    qSort(chr_dat->charTraits.begin(), chr_dat->charTraits.end());
    ui->S2TraitsTable->setRowCount(chr_dat->charTraits.count());
    for(int sCount = 0 ; sCount < chr_dat->charTraits.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charTraits[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(chr_dat->charTraits[sCount].first));
        ui->S2TraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charTraits[sCount].second));
        ui->S2TraitsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S2RemoveOldParam() {
    changeXP(stage2->s2XpCost, false);
    QMapIterator <QString, int> i(stage2->s2Attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
    }

    int swapCount = stage2->s2Skills.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeSkills(stage2->s2Skills[sCount].first, -stage2->s2Skills[sCount].second);
    }


    swapCount = stage2->s2Traits.count();
    for(int sCount = 0 ; sCount < swapCount ; sCount++) {
        chr_dat->changeTraits(stage2->s2Traits[sCount].first,-stage2->s2Traits[sCount].second);
    }

}

void Wizard::AddAffilAttr(QMap<QString, int>  attr) {
    QMapIterator <QString, int> i(attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] + i.value();
    }
}

void Wizard::S2DelAttr(QMap<QString, int>  attr) {
    QMapIterator <QString, int> i(attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
    }
}

void Wizard::AddAfillSkill(QList<QPair<QString, int> > skillsList)
{
    for(int sCount = 0 ; sCount < skillsList.count() ; sCount++) {
        chr_dat->changeSkills(skillsList[sCount].first, skillsList[sCount].second);
    }
}

void Wizard::S2DelSkills(QList<QPair<QString, int> > skillsList) {
    for(int sCount = 0 ; sCount < skillsList.count() ; sCount++) {
        chr_dat->changeSkills(skillsList[sCount].first, -skillsList[sCount].second);
    }
}

void Wizard::AddAfillTraits(QList<QPair<QString, int> > traitsList)
{
    for(int sCount = 0 ; sCount < traitsList.count() ; sCount++) {
        chr_dat->changeTraits(traitsList[sCount].first, traitsList[sCount].second);
    }
}

void Wizard::S2DelTraits(QList<QPair<QString, int> > traitsList) {
    for(int sCount = 0 ; sCount < traitsList.count() ; sCount++) {
        chr_dat->changeTraits(traitsList[sCount].first, -traitsList[sCount].second);
    }
}

void Wizard::S2ComBoxChange() {
    if (stage2->s2ChildHoodAttr1.isEmpty() == false) {

        ui->S2ComboBoxElem1->clear();
        ui->S2LabelElem1->clear();
        ui->S2ComboBoxElem1->setEnabled(true);
        ui->S2LabelElem1->setText(stage2->s2ChildHoodLabel1);
        ui->S2ComboBoxElem1->addItems(stage2->s2ChildHoodAttr1);
    } else {
        ui->S2ComboBoxElem1->clear();
        ui->S2LabelElem1->clear();
        ui->S2ComboBoxElem1->setEnabled(false);
        stage2->s2ChildHoodAttr1.clear();
    }

    if (stage2->s2ChildHoodSkills2 != 0 || stage2->s2ChildHoodTraits2 != 0) {
        ui->S2ComboBoxElem2->clear();
        ui->S2LabelElem2->clear();
        ui->S2ComboBoxElem2->setEnabled(true);
        ui->S2LabelElem2->setText(stage2->s2ChildHoodLabel2);
        ui->S2ComboBoxElem2->addItems(stage2->s2ChildHoodAttr2);
    } else {
        ui->S2ComboBoxElem2->clear();
        ui->S2LabelElem2->clear();
        ui->S2ComboBoxElem2->setEnabled(false);
        stage2->s2ChildHoodAttr2.clear();
    }

    if (stage2->s2ChildHoodSkills3 != 0 || stage2->s2ChildHoodTraits3 != 0) {
        ui->S2ComboBoxElem3->clear();
        ui->S2LabelElem3->clear();
        ui->S2ComboBoxElem3->setEnabled(true);
        ui->S2LabelElem3->setText(stage2->s2ChildHoodLabel3);
        ui->S2ComboBoxElem3->addItems(stage2->s2ChildHoodAttr3);
    } else {
        ui->S2ComboBoxElem3->clear();
        ui->S2LabelElem3->clear();
        ui->S2ComboBoxElem3->setEnabled(false);
        stage2->s2ChildHoodAttr3.clear();
    }


    if (ui->S2ChComboBox->currentText() == "Trueborn Sibko") {

        ui->S2ComboBoxElem1->clear();
        ui->S2LabelElem1->clear();
        ui->S2ComboBoxElem1->setEnabled(true);
        ui->S2ComboBoxElem1->addItems(stage2->S2TruebornSibko(chr_dat->subAffName.first));
        ui->S2LabelElem1->setText(stage2->s2ChildHoodLabel1);
        stage2->S2TruebornSibkoAttr(ui->S2ComboBoxElem1->currentText());
    } else {
        if (ui->S2ChComboBox->currentText() == "Freeborn Sibko") {

            ui->S2ComboBoxElem1->clear();
            ui->S2LabelElem1->clear();
            ui->S2ComboBoxElem1->setEnabled(true);
            ui->S2ComboBoxElem1->addItems(stage2->S2FreebornSibko());
            stage2->S2FreebornSibkoAttr(ui->S2ComboBoxElem1->currentText());
            ui->S2LabelElem1->setText(stage2->s2ChildHoodLabel1);
        }
    }
}

void Wizard::S2ChangeElem1(QString nameElem) {


    if (ui->S2ChComboBox->currentText() == "Freeborn Sibko") {

        S2RemoveOldParam();
        stage2->S2FreebornSibkoAttr(nameElem);

        AddAffilAttr(stage2->s2Attr);
        changeXP(stage2->s2XpCost, true);
        AddAfillSkill(stage2->s2Skills);
        AddAfillTraits(stage2->s2Traits);
        S2Change();
    } else {
        if ( ui->S2ChComboBox->currentText() == "Trueborn Sibko") {
            S2RemoveOldParam();

            stage2->S2TruebornSibkoAttr(nameElem);

            AddAffilAttr(stage2->s2Attr);
            changeXP(stage2->s2XpCost, true);
            AddAfillSkill(stage2->s2Skills);
            AddAfillTraits(stage2->s2Traits);
            S2Change();
        } else {
                S2ChangeElem1Main(nameElem);
            }
        }
}

void Wizard::S2ChangeElem1Main(QString nameElem) {
    S2RemoveOldParam();
    if (stage2->s2ChildHoodSkills1 != 0) {
        stage2->S2AddSkills(nameElem,stage2->s2ChildHoodSkills1);
        if (stage2->s2ChildHoodSkillsSwp1.isEmpty() != true) {
            stage2->S2AddSkills(stage2->s2ChildHoodSkillsSwp1,-stage2->s2ChildHoodSkillsSwp1Int);
        }
        stage2->s2ChildHoodSkillsSwp1 = nameElem;
        stage2->s2ChildHoodSkillsSwp1Int = stage2->s2ChildHoodSkills1;
    }

    if (stage2->s2ChildHoodTraits1 != 0) {
        stage2->S2AddTraits(nameElem,stage2->s2ChildHoodTraits1);
        if (stage2->s2ChildHoodTraitsSwp1.isEmpty() != true) {
            stage2->S2AddTraits(stage2->s2ChildHoodTraitsSwp1,-stage2->s2ChildHoodTraitsSwp1Int);
        }
        stage2->s2ChildHoodTraitsSwp1 = nameElem;
        stage2->s2ChildHoodTraitsSwp1Int = stage2->s2ChildHoodTraits1;
    }

    AddAffilAttr(stage2->s2Attr);
    changeXP(stage2->s2XpCost, true);
    AddAfillSkill(stage2->s2Skills);
    AddAfillTraits(stage2->s2Traits);
    S2Change();
}

void Wizard::S2ChangeElem2(QString nameElem) {
    if (ui->S2ChComboBox->currentText() == "Mercenary Brat") {
        S2RemoveOldParam();
        if (stage2->s2ChildHoodSkillsSwp2.isEmpty() != true) {
            stage2->S2AddSkills(stage2->s2ChildHoodSkillsSwp2,-stage2->s2ChildHoodSkillsSwp2Int);
            stage2->s2ChildHoodSkillsSwp2.clear();
        }

        stage2->s2CountElem2++;
        if(stage2->s2CountElem2 == 1) {
            stage2->S2AddSkills(nameElem,stage2->s2ChildHoodSkills2);
        } else {
            stage2->S2AddSkills(nameElem,20);
        }

        if(stage2->s2CountElem2 == 2) {
            ui->S2ComboBoxElem2->setEnabled(false);
            stage2->s2CountElem2 = 0;
        }
        AddAffilAttr(stage2->s2Attr);
        changeXP(stage2->s2XpCost, true);
        AddAfillSkill(stage2->s2Skills);
        AddAfillTraits(stage2->s2Traits);
        S2Change();
    } else {
        S2ChangeElem2Main(nameElem);
    }
}

void Wizard::S2ChangeElem2Main(QString nameElem) {
    S2RemoveOldParam();
    if (stage2->s2ChildHoodSkills2 != 0) {
        stage2->S2AddSkills(nameElem,stage2->s2ChildHoodSkills2);
        if (stage2->s2ChildHoodSkillsSwp2.isEmpty() != true) {
            stage2->S2AddSkills(stage2->s2ChildHoodSkillsSwp2,-stage2->s2ChildHoodSkillsSwp2Int);
        }
        stage2->s2ChildHoodSkillsSwp2 = nameElem;
        stage2->s2ChildHoodSkillsSwp2Int = stage2->s2ChildHoodSkills2;
    }

    if (stage2->s2ChildHoodTraits2 != 0) {
        stage2->S2AddTraits(nameElem,stage2->s2ChildHoodTraits2);
        if (stage2->s2ChildHoodTraitsSwp2.isEmpty() != true) {
            stage2->S2AddTraits(stage2->s2ChildHoodTraitsSwp2,-stage2->s2ChildHoodTraitsSwp2Int);
        }
        stage2->s2ChildHoodTraitsSwp2 = nameElem;
        stage2->s2ChildHoodTraitsSwp2Int = stage2->s2ChildHoodTraits2;
    }

    AddAffilAttr(stage2->s2Attr);
    changeXP(stage2->s2XpCost, true);
    AddAfillSkill(stage2->s2Skills);
    AddAfillTraits(stage2->s2Traits);
    S2Change();



}

void Wizard::S2ChangeElem3(QString nameElem) {
    S2RemoveOldParam();
    if (stage2->s2ChildHoodSkills3 != 0) {
        stage2->S2AddSkills(nameElem,stage2->s2ChildHoodSkills3);
        if (stage2->s2ChildHoodSkillsSwp3.isEmpty() != true) {
            stage2->S2AddSkills(stage2->s2ChildHoodSkillsSwp3,-stage2->s2ChildHoodSkillsSwp3Int);
        }
        stage2->s2ChildHoodSkillsSwp3 = nameElem;
        stage2->s2ChildHoodSkillsSwp3Int = stage2->s2ChildHoodSkills3;
    }

    if (stage2->s2ChildHoodTraits3 != 0) {
        stage2->S2AddTraits(nameElem,stage2->s2ChildHoodTraits3);
        if (stage2->s2ChildHoodTraitsSwp3.isEmpty() != true) {
            stage2->S2AddTraits(stage2->s2ChildHoodTraitsSwp3,-stage2->s2ChildHoodTraitsSwp3Int);
        }
        stage2->s2ChildHoodTraitsSwp3 = nameElem;
        stage2->s2ChildHoodTraitsSwp3Int = stage2->s2ChildHoodTraits3;
    }


    AddAffilAttr(stage2->s2Attr);
    changeXP(stage2->s2XpCost, true);
    AddAfillSkill(stage2->s2Skills);
    AddAfillTraits(stage2->s2Traits);
    S2Change();

}


//!!!!!!!!!!!!--------------------STAGE3--------------------!!!!!!!!!!!!//

void Wizard::Stage3Main() {
    stage3 = new Stage3;
 //   this->button(Wizard::NextButton)->setDisabled(true);
    stage3->subSkillList = subSkillList;
    s3AdvCount = 0;
    s2fxpdialog->S2FlexXPDialogInit();
    s3RebateXp = 0;
    chr_dat->schoolName.first.clear();
    chr_dat->basicSchool.first.clear();
    chr_dat->advSchool.first.clear();
    chr_dat->specSchool.first.clear();
    s2advdial->s2AdvDialSkills.clear();
    s2advdial->s2AdvDialOther.clear();

    S3SchoolComboBoxChange(0);
    chr_dat->xp += s2clanfield->s2CFDRebateSum;

    ui->PageStage3->setDisabled(false);
    chr_dat->age = 16;
    chr_dat->lateChildName.first = ui->S2ChComboBox->currentText();
    chr_dat->lateChildName.second = ui->S2ChComboBox->currentIndex();

    ui->S3NameLabel->setText(chr_dat->charName); //    
    ui->S3AffLabel->setText(chr_dat->AffName.first); //      
    ui->S3SubAffLabel->setText(chr_dat->subAffName.first); //    
    ui->S3CasteLabel->setText(chr_dat->clanCastName.first); //    
    ui->S3EarlyLabel->setText(chr_dat->earlyChildName.first); //    
    ui->S3LateLabel->setText(chr_dat->lateChildName.first); //    

    s2fxpdialog->s2FXDSkills.clear();
    s2fxpdialog->s2FXDTraits.clear();
    s2fxpdialog->s2FXDCharAttr.clear();

    if(chr_dat->AffName.second == 0 && chr_dat->lateChildName.first == "Civilian Job") {
        ui->PageStage3->setDisabled(true);
        chr_dat->age = 18;
    }

    if(chr_dat->AffName.second == 1 && chr_dat->lateChildName.first == "Civilian Job") {
        ui->PageStage3->setDisabled(true);
        chr_dat->age = 18;
    }

    if(chr_dat->subAffName.first == "Marian Hegemony") {
        bool chkName = false;
        for(int i = 0; i < chr_dat->charTraits.count(); i++) {
            if(chr_dat->charTraits[i].first == "Citizenship/Inner Sphere" || chr_dat->charTraits[i].first == "Citizenship/Clan") {
                chkName = true;
            }
        }
        if (chkName == false) {
            ui->PageStage3->setDisabled(true);
        }
    }


    ui->S3SchoolComboBox->clear();
    s3SchoolList = stage3->S3ClearAffilation(chr_dat->subAffName.first);
    ui->S3SchoolComboBox->addItems(s3SchoolList);
    S3SchoolComboBoxChange(ui->S3SchoolComboBox->currentText());

    S3Change();
}

void Wizard::S3ConnectEvent() {
    connect(ui->S3SchoolComboBox, SIGNAL(activated(QString)), this, SLOT(S3SchoolComboBoxChange(QString)));
    connect(ui->S3ComboBoxBasic, SIGNAL(activated(QString)), this, SLOT(S3ComboBoxBasicChange(QString)));
    connect(ui->S3ComboBoxAdv, SIGNAL(activated(QString)), this, SLOT(S3ComboBoxAdvChange(QString)));
    connect(ui->S3ComboBoxSpec, SIGNAL(activated(QString)), this,SLOT(S3ComboBoxSpecChange(QString)));

    connect(ui->S3SChoolAddButton, SIGNAL(clicked()), this, SLOT(S3SChoolAddButtonClick()));
    connect(ui->S3BasicAddButton, SIGNAL(clicked()), this, SLOT(S3BasicAddButtonClick()));
    connect(ui->S3AdvAddButton, SIGNAL(clicked()), this, SLOT(S3AdvAddButtonClick()));
    connect(ui->S3SpecAddButton, SIGNAL(clicked()), this, SLOT(S3SpecAddButtonClick()));

    connect(ui->S3FlexXPPushButton, SIGNAL(clicked()), this, SLOT(S2FlexXpButton()));
    connect(ui->S3MorePushButton, SIGNAL(clicked()), this, SLOT(S2AdvButton()));
    connect(s3fielddial, SIGNAL(accepted()), this,SLOT(S3FieldDialogAccept()));

}


void Wizard::S3RemoveOldParam() {
    changeXP(stage3->s3XpCost, false);
    QMapIterator <QString, int> i(stage3->s3Attr);
    while(i.hasNext()) {
        i.next();
        chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
    }

    for(int sCount = 0 ; sCount < stage3->s3Skills.count() ; sCount++) {
        chr_dat->changeSkills(stage3->s3Skills[sCount].first, -stage3->s3Skills[sCount].second);
    }



    for(int sCount = 0 ; sCount < stage3->s3Traits.count() ; sCount++) {
        chr_dat->changeTraits(stage3->s3Traits[sCount].first,-stage3->s3Traits[sCount].second);
    }

}

void Wizard::S3Change() {

    ui->S3StatusXP->setText(QString::number(chr_dat->xp));
    ui->S3StatusXP->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));

    ui->S3StatusAge->setText(QString::number(chr_dat->age));
    ui->S3StatusAge->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));

    ChangeAgeAttr(chr_dat->age);
    // 
    ui->S3AttrStrLabel->setText("<b>STR:</b> " + QString::number(chr_dat->charAttr.value("STR")));
    ui->S3AttrBodLabel->setText("<b>BOD:</b> " + QString::number(chr_dat->charAttr.value("BOD")));
    ui->S3AttrRflLabel->setText("<b>RFL:</b> " + QString::number(chr_dat->charAttr.value("RFL")));
    ui->S3AttrDexLabel->setText("<b>DEX:</b> " + QString::number(chr_dat->charAttr.value("DEX")));
    ui->S3AttrIntLabel->setText("<b>INT:</b>  " + QString::number(chr_dat->charAttr.value("INT")));
    ui->S3AttrWilLabel->setText("<b>WIL:</b> " + QString::number(chr_dat->charAttr.value("WIL")));
    ui->S3AttrChaLabel->setText("<b>CHA:</b> " + QString::number(chr_dat->charAttr.value("CHA")));
    ui->S3AttrEdgLabel->setText("<b>EDG:</b> " + QString::number(chr_dat->charAttr.value("EDG")));
    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    // 
    S3PrintSkillsTable();
    S3PrintTraitsTable();

}

void Wizard::S3PrintSkillsTable() {
    ui->S3SkillsTable->clear();
    qSort(chr_dat->charSkills.begin(), chr_dat->charSkills.end());
    ui->S3SkillsTable->setRowCount(chr_dat->charSkills.count());

    for(int sCount = 0 ; sCount < chr_dat->charSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charSkills[sCount].first);
        newSNameItem->setToolTip(SkillDesc(chr_dat->charSkills[sCount].first));
        ui->S3SkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charSkills[sCount].second));
        ui->S3SkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S3PrintTraitsTable()
{
    ui->S3TraitsTable->clear();
    qSort(chr_dat->charTraits.begin(), chr_dat->charTraits.end());
    ui->S3TraitsTable->setRowCount(chr_dat->charTraits.count());
    for(int sCount = 0 ; sCount < chr_dat->charTraits.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charTraits[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(chr_dat->charTraits[sCount].first));
        ui->S3TraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charTraits[sCount].second));
        ui->S3TraitsTable->setItem(sCount,1,newSValueItem);
    }

}


void Wizard::S3SChoolAddButtonClick() {

    stage3->S3SetSchool(ui->S3SchoolComboBox->currentText());

//    S3SchoolComboBoxChange(ui->S3SchoolComboBox->currentText());
    chr_dat->schoolName.first = ui->S3SchoolComboBox->currentText();
    chr_dat->schoolName.second = ui->S3SchoolComboBox->currentIndex();


    if(stage3->s3BasicField.isEmpty() != true) {
        ui->S3ComboBoxBasic->setEnabled(true);
        ui->S3BasicAddButton->setEnabled(true);
        ui->S3ComboBoxBasic->addItems(stage3->s3BasicField);
    } else {
        ui->S3ComboBoxBasic->setEnabled(false);
        ui->S3BasicAddButton->setEnabled(false);
    }

    QStringList tmpSchoolList;
    tmpSchoolList = s3SchoolList;
    s3SchoolList.clear();

    for(int i =0; i < tmpSchoolList.count(); i++) {
        if(tmpSchoolList[i] != ui->S3SchoolComboBox->currentText()) {
            s3SchoolList << tmpSchoolList[i];
        }
    }

    tmpSchoolList = s3SchoolList;
    s3SchoolList.clear();

    if(stage3->s3MilField == true) {
        for(int i =0; i < tmpSchoolList.count(); i++) {
            if(stage3->S3SchoolEnter(tmpSchoolList[i]) != "mil") {
                s3SchoolList << tmpSchoolList[i];
            }
        }


    }

    if(stage3->s3PolicField == true) {
        for(int i =0; i < tmpSchoolList.count(); i++) {
            if(stage3->S3SchoolEnter(tmpSchoolList[i]) != "pol") {
                s3SchoolList << tmpSchoolList[i];
            }
        }

    }

    if(stage3->s3CivField == true) {
        for(int i =0; i < tmpSchoolList.count(); i++) {
            if(stage3->S3SchoolEnter(tmpSchoolList[i]) != "civ") {
                s3SchoolList << tmpSchoolList[i];
            }
        }

    }

    if(stage3->s3PolicField == true || stage3->s3MilField == true) {
        if(stage3->s3OffField != true) {
            s3SchoolList << "Officer Candidate School";
        }
    }

    ui->S3SchoolComboBox->clear();
    ui->S3SchoolComboBox->addItems(s3SchoolList);

    stage3->s3XpCost = 0;
    stage3->s3Attr.clear();
    stage3->s3Skills.clear();
    stage3->s3Traits.clear();
    s2advdial->s2AdvDialSkills.clear();

    ui->S3SChoolAddButton->setDisabled(true);
    ui->S3FlexXPPushButton->setDisabled(true);
    ui->S3MorePushButton->setDisabled(true);

    stage3->chkAdd = true;

    if(ui->S3SchoolComboBox->count() == 0) {
        ui->S3SchoolComboBox->setDisabled(true);
    }


}


void Wizard::S3BasicAddButtonClick() {

    s3RebateXp += stage3->s3BasicFieldListSwp.count() * 6;

    stage3->S3FieldChange(ui->S3ComboBoxBasic->currentText());

    chr_dat->basicSchool.first = ui->S3ComboBoxBasic->currentText();
    chr_dat->basicSchool.second = ui->S3ComboBoxBasic->currentIndex();


    if(stage3->s3AdvField.isEmpty() != true) {
        ui->S3ComboBoxAdv->setEnabled(true);
        ui->S3AdvAddButton->setEnabled(true);
        ui->S3ComboBoxAdv->addItems(stage3->s3AdvField);
    } else {
        ui->S3ComboBoxAdv->setEnabled(false);
         ui->S3AdvAddButton->setEnabled(false);
    }

//    S3ComboBoxBasicChange(ui->S3ComboBoxBasic->currentText());
    stage3->s3BasicFieldListSwp.clear();
    stage3->s3BasicAgeSwp = 0;
    s3fielddial->s3FieldDialSkills.clear();

    ui->S3BasicAddButton->setDisabled(true);
    ui->S3ComboBoxBasic->setDisabled(true);
    this->button(Wizard::NextButton)->setDisabled(false);
}

void Wizard::S3AdvAddButtonClick() {

    s3RebateXp += stage3->s3AdvFieldListSwp.count() *6;

    stage3->S3FieldChange( ui->S3ComboBoxAdv->currentText());
    chr_dat->advSchool.first = ui->S3ComboBoxAdv->currentText();
    chr_dat->advSchool.second = ui->S3ComboBoxAdv->currentIndex();

    if(stage3->s3SpecField.isEmpty() != true) {
        ui->S3ComboBoxSpec->setEnabled(true);
        ui->S3SpecAddButton->setEnabled(true);
        ui->S3ComboBoxSpec->addItems(stage3->s3SpecField);
    } else {
        ui->S3ComboBoxSpec->setEnabled(false);
        ui->S3SpecAddButton->setEnabled(false);
    }

//    S3ComboBoxAdvChange(ui->S3ComboBoxAdv->currentText());
    stage3->s3AdvFieldListSwp.clear();
    s3fielddial->s3FieldDialSkills.clear();
    stage3->s3AdvAgeSwp = 0;

    ++s3AdvCount;
    if(s3AdvCount == 2) {
        ui->S3AdvAddButton->setDisabled(true);
        ui->S3ComboBoxAdv->setDisabled(true);
        ui->S3SpecAddButton->setDisabled(true);
        ui->S3ComboBoxSpec->setDisabled(true);
    }


}

void Wizard::S3SpecAddButtonClick() {
    s3RebateXp += stage3->s3SpecFieldListSwp.count() *6;

    stage3->S3FieldChange( ui->S3ComboBoxSpec->currentText());
    chr_dat->specSchool.first = ui->S3ComboBoxSpec->currentText();
    chr_dat->specSchool.second = ui->S3ComboBoxSpec->currentIndex();

    //    S3ComboBoxSpecChange(ui->S3ComboBoxSpec->currentText());
    stage3->s3SpecFieldListSwp.clear();
    s3fielddial->s3FieldDialSkills.clear();
    stage3->s3SpecAgeSwp = 0;

    ui->S3AdvAddButton->setDisabled(true);
    ui->S3ComboBoxAdv->setDisabled(true);
    ui->S3SpecAddButton->setDisabled(true);
    ui->S3ComboBoxSpec->setDisabled(true);
}

void Wizard::S3SchoolComboBoxChange(QString nameElem) {
    if(stage3->chkAdd == true) {
        stage3->s3Attr.clear();
        stage3->s3Skills.clear();
        stage3->s3Traits.clear();
        stage3->chkAdd = false;
    }


    ui->S3ComboBoxBasic->clear();
    ui->S3ComboBoxBasic->setEnabled(false);
    ui->S3BasicAddButton->setEnabled(false);

    ui->S3ComboBoxAdv->clear();
    ui->S3ComboBoxAdv->setEnabled(false);
    ui->S3AdvAddButton->setEnabled(false);

    ui->S3ComboBoxSpec->clear();
    ui->S3ComboBoxSpec->setEnabled(false);
    ui->S3SpecAddButton->setEnabled(false);


    S3RemoveOldParam();



    stage3->s3XpCost = 0;
    stage3->s3Attr.clear();
    stage3->s3Skills.clear();
    stage3->s3Traits.clear();
    ui->S3ComboBoxBasic->clear();
    ui->S3ComboBoxAdv->clear();
    ui->S3ComboBoxSpec->clear();

    stage3->S3SchoolChange(nameElem, chr_dat->AffName.first, chr_dat->earlyChildName.first, chr_dat->lateChildName.first);
    ui->S3SchoolComboBox->setToolTip(stage3->s3toolTip);

    if (stage3->s3AffLang != 0) {
        stage3->S3AddSkills(ui->lang_ZStage_ComboBox->currentText(), stage3->s3AffLang);
    }

    if (stage3->s3AffProt != 0) {
        stage3->S3AddSkills(txt_res->affProtocol, stage3->s3AffProt);
    }

    if (stage3->s3AffStreet != 0) {
        stage3->S3AddSkills(txt_res->affStreet, stage3->s3AffStreet);
    }

    if (stage3->s3ChildHoodLabelAdv1.isEmpty() == true && stage3->s3ChildHoodLabelAdv4.isEmpty() == true) {
        ui->S3MorePushButton->setEnabled(false);
        ui->S3SChoolAddButton->setEnabled(true);
        chkAdvButton = true;
    } else {
        ui->S3MorePushButton->setEnabled(true);
        ui->S3SChoolAddButton->setEnabled(false);
        chkAdvButton = false;

    }

    ui->S3FlexXPPushButton->setEnabled(true);

    AddAffilAttr(stage3->s3Attr);
    changeXP(stage3->s3XpCost, true);
    AddAfillSkill(stage3->s3Skills);
    AddAfillTraits(stage3->s3Traits);

    if(s2advdial->s2AdvDialSkills.isEmpty() != true) {
        for (int i =0; i < s2advdial->s2AdvDialSkills.count(); i++) {
            if(s2advdial->s2AdvDialSkills[i].first == "Equipped" || s2advdial->s2AdvDialSkills[i].first == "Vehicle") {
                chr_dat->changeTraits(s2advdial->s2AdvDialSkills[i].first,-s2advdial->s2AdvDialSkills[i].second);
            } else {
                chr_dat->changeSkills(s2advdial->s2AdvDialSkills[i].first,-s2advdial->s2AdvDialSkills[i].second);
            }

        }
    }

    if(s2advdial->s2AdvDialOther.isEmpty() != true ) {
        if(s2advdial->s2AdvDialOther[0].first.count() == 3) {
            chr_dat->charAttr[s2advdial->s2AdvDialOther[0].first] -= s2advdial->s2AdvDialOther[0].second;
        }
    }
    s2advdial->s2AdvDialSkills.clear();
    s2advdial->s2AdvDialOther.clear();

    S3Change();


}

void Wizard::S3ComboBoxBasicChange(QString nameElem) {
    S3RemoveOldParam();

    if(stage3->s3BasicFieldListSwp.isEmpty() != true) {
        for (int i = 0; i < stage3->s3BasicFieldListSwp.count(); i++ ) {
            if (stage3->s3BasicFieldListSwp[i].contains("Any") != true && stage3->s3BasicFieldListSwp[i].contains("Career/Pilot or Ship's Crew") != true) {
                stage3->S3AddSkills(stage3->s3BasicFieldListSwp[i],-30);
            }
        }


        chr_dat->age = chr_dat->age - stage3->s3BasicAgeSwp;
        changeXP(stage3->s3BasicFieldListSwp.count() * 30, false);
    }

    QStringList basicFieldList;
    basicFieldList = stage3->S3FieldChoose(nameElem);
    for (int i = 0; i < basicFieldList.count(); i++ ) {

        if (basicFieldList[i].contains("Any") != true && basicFieldList[i].contains("Career/Pilot or Ship's Crew") != true) {
            stage3->S3AddSkills(basicFieldList[i],30);
        }


    }

    chr_dat->age = chr_dat->age + stage3->s3BasicFieldAge;

    stage3->s3BasicFieldListSwp = basicFieldList;
    stage3->s3BasicAgeSwp = stage3->s3BasicFieldAge;

    S3CallFieldDial(nameElem);

    changeXP(basicFieldList.count() * 30, true);
    AddAfillSkill(stage3->s3Skills);
    S3Change();
}

void Wizard::S3ComboBoxAdvChange(QString nameElem) {
    S3RemoveOldParam();


    if(stage3->s3AdvFieldListSwp.isEmpty() != true) {
        for (int i = 0; i < stage3->s3AdvFieldListSwp.count(); i++ ) {
            if (stage3->s3AdvFieldListSwp[i].contains("Any") != true && stage3->s3AdvFieldListSwp[i].contains("Tactics/Land or Sea") != true) {
                stage3->S3AddSkills(stage3->s3AdvFieldListSwp[i],-30);
            }
        }
        chr_dat->age = chr_dat->age - stage3->s3AdvAgeSwp;
        changeXP(stage3->s3AdvFieldListSwp.count() * 30, false);
    }

    QStringList advFieldList;
    advFieldList = stage3->S3FieldChoose(nameElem);
    for (int i = 0; i < advFieldList.count(); i++ ) {
        if (advFieldList[i].contains("Any") != true && advFieldList[i].contains("Tactics/Land or Sea") != true) {
            stage3->S3AddSkills(advFieldList[i],30);
        }
    }

    chr_dat->age = chr_dat->age + stage3->s3AdvFieldAge;

    stage3->s3AdvFieldListSwp = advFieldList;
    stage3->s3AdvAgeSwp = stage3->s3AdvFieldAge;


    S3CallFieldDial(nameElem);
    changeXP(advFieldList.count() * 30, true);
    AddAfillSkill(stage3->s3Skills);
    S3Change();
}

void Wizard::S3ComboBoxSpecChange(QString nameElem) {
    S3RemoveOldParam();

    if(stage3->s3SpecFieldListSwp.isEmpty() != true) {
        for (int i = 0; i < stage3->s3SpecFieldListSwp.count(); i++ ) {
            if (stage3->s3SpecFieldListSwp[i].contains("Any") != true) {
                stage3->S3AddSkills(stage3->s3SpecFieldListSwp[i],-30);
            }
        }
        chr_dat->age = chr_dat->age - stage3->s3SpecAgeSwp;
        changeXP(stage3->s3SpecFieldListSwp.count() * 30, false);
    }

    QStringList specFieldList;
    specFieldList = stage3->S3FieldChoose(nameElem);
    for (int i = 0; i < specFieldList.count(); i++ ) {
        if (specFieldList[i].contains("Any") != true) {
            stage3->S3AddSkills(specFieldList[i],30);
        }
    }
    chr_dat->age = chr_dat->age + stage3->s3SpecFieldAge;

    stage3->s3SpecFieldListSwp = specFieldList;
    stage3->s3SpecAgeSwp = stage3->s3SpecFieldAge;


    S3CallFieldDial(nameElem);
    changeXP(specFieldList.count() * 30, true);
    AddAfillSkill(stage3->s3Skills);
    S3Change();
}

void Wizard::S3CallFieldDial(QString nameElem) {
    QStringList listSkillsField;
    listSkillsField = stage3->S3FieldChoose(nameElem);
    bool chkAny = false;

    for(int i=0; i < s3fielddial->s3FieldDialSkills.count(); i++) {
        chr_dat->changeSkills(s3fielddial->s3FieldDialSkills[i].first,-s3fielddial->s3FieldDialSkills[i].second);
    }
    s3fielddial->s3FieldDialCountSkill =0;
    s3fielddial->S3FieldDialRezet();
    for(int i = 0; i < listSkillsField.count(); i++) {
        if (listSkillsField[i].contains("Any") == true || listSkillsField[i].contains("Career/Pilot or Ship's Crew") == true || listSkillsField[i].contains("Tactics/Land or Sea") == true) {
            chkAny = true;
            s3fielddial->s3FieldDialCountSkill++;
            s3fielddial->S3FieldDialInit(listSkillsField[i], txt_res->affProtocol);
        }
    }

    if(chkAny == true) {
        s3fielddial->show();
        s3fielddial->activateWindow();
    }

}


void Wizard::S3FieldDialogAccept() {
    for(int i=0; i < s3fielddial->s3FieldDialSkills.count(); i++) {
        chr_dat->changeSkills(s3fielddial->s3FieldDialSkills[i].first,s3fielddial->s3FieldDialSkills[i].second);
    }
    S3Change();
}


//!!!!!!!!!!!!--------------------STAGE4--------------------!!!!!!!!!!!!//

void Wizard::Stage4Main() {
    stage4 = new Stage4;
    stage4->subSkillList = subSkillList;
    s2fxpdialog->S2FlexXPDialogInit();
    chr_dat->xp += s3RebateXp;

    ui->S4NameLabel->setText(chr_dat->charName); //    
    ui->S4AffLabel->setText(chr_dat->AffName.first); //      
    ui->S4SubAffLabel->setText(chr_dat->subAffName.first); //    
    ui->S4CasteLabel->setText(chr_dat->clanCastName.first); //    
    ui->S4EarlyLabel->setText(chr_dat->earlyChildName.first); //    
    ui->S4LateLabel->setText(chr_dat->lateChildName.first); //    
    ui->S4SchoolLabel->setText(chr_dat->schoolName.first); //
    ui->S4BasicSchoolLabel->setText(chr_dat->basicSchool.first); //  
    ui->S4AdvSchoolLabel->setText(chr_dat->advSchool.first); //
    ui->S4SpecSchoolLabel->setText(chr_dat->specSchool.first); //

    stage4->s4AffName = chr_dat->AffName;
    stage4->s4SubAffName = chr_dat->subAffName;
    stage4->s4clanCastName = chr_dat->clanCastName;
    stage4->s4EarlyChildName = chr_dat->earlyChildName;
    stage4->s4LateChildName = chr_dat->lateChildName;
    stage4->s4SchoolName = chr_dat->schoolName;
    stage4->s4BasicSchool = chr_dat->basicSchool;
    stage4->s4AdvSchool = chr_dat->advSchool;
    stage4->s4SpecSchool = chr_dat->specSchool;
    stage4->s4Phenotype = chr_dat->phenotype;

    stage4->clanFieldSkills.append(s2clanfield->s2CFDClanBasicSkills);
    stage4->clanFieldSkills.append(s2clanfield->s2CFDClanAdvSkills);


    stage4->s4Attr = chr_dat->charAttr;
    stage4->s4Skills = chr_dat->charSkills;
    stage4->s4Traits = chr_dat->charTraits;

    stage4->s4ComChk = chr_dat->comChk;
    stage4->s4WobChk = chr_dat->wobChk;
    if (chr_dat->lateChildName.first == "Trueborn Sibko") {
        stage4->s4MilField = "true";
    } else {
        stage4->s4MilField = stage3->s3MilField;
    }


    ui->S4LifeComboBox->clear();
    S4ClearLifeList = stage4->S4ClearModulesList();
    ui->S4LifeComboBox->addItems(S4ClearLifeList);
    ui->S4MorePushButton->setDisabled(true);
    ui->S4FlexXPPushButton->setDisabled(true);

    if(chr_dat->AffName.second == 0 && chr_dat->lateChildName.first == "Civilian Job") {
        ui->PageStage4->setDisabled(true);
        chr_dat->age = 18;
    }

    if(chr_dat->AffName.second == 1 && chr_dat->lateChildName.first == "Civilian Job") {
        ui->PageStage4->setDisabled(true);
        chr_dat->age = 18;
    }

    S4Change();
}

void Wizard::S4ConnectEvent() {
    connect(ui->S4LifeComboBox, SIGNAL(activated(QString)), this, SLOT(S4LifeComboBoxChange(QString)));
    connect(ui->S4FlexXPPushButton, SIGNAL(clicked()), this, SLOT(S2FlexXpButton()));
    connect(ui->S4MorePushButton, SIGNAL(clicked()), this, SLOT(S4AdvButton()));
    connect(s4advdial, SIGNAL(accepted()), this, SLOT(S4AdvDialAcceptButton()));
    connect(s4advdial, SIGNAL(rejected()), this, SLOT(S4AdvDialCancelButton()));
    connect(ui->S4LifeAddButton, SIGNAL(clicked()), this, SLOT(S4LifeAddButton()));
}

void Wizard::S4AdvButton() {

    if(s4advdial->s4AdvDialSkills.isEmpty() != true || s4advdial->s4AdvDialTraits.isEmpty() != true) {
        if(s4advdial->s4AdvDialAttr.isEmpty() != true) {

            for (int i=0; i < s4advdial->s4AdvDialAttr.count(); ++i) {
                chr_dat->charAttr[s4advdial->s4AdvDialAttr[i].first] = -s4advdial->s4AdvDialAttr[i].second;
            }

            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialSkills.count() ; sCount++) {
                chr_dat->changeSkills(s4advdial->s4AdvDialSkills[sCount].first, -s4advdial->s4AdvDialSkills[sCount].second);
            }



            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialTraits.count() ; sCount++) {
                chr_dat->changeTraits(s4advdial->s4AdvDialTraits[sCount].first,-s4advdial->s4AdvDialTraits[sCount].second);
            }

        } else {
            for (int i=0; i < s4advdial->s4AdvDialAttr.count(); ++i) {
                chr_dat->charAttr[s4advdial->s4AdvDialAttr[i].first] = -s4advdial->s4AdvDialAttr[i].second;
            }

            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialSkills.count() ; sCount++) {
                chr_dat->changeSkills(s4advdial->s4AdvDialSkills[sCount].first, -s4advdial->s4AdvDialSkills[sCount].second);
            }



            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialTraits.count() ; sCount++) {
                chr_dat->changeTraits(s4advdial->s4AdvDialTraits[sCount].first,-s4advdial->s4AdvDialTraits[sCount].second);
            }
        }
    }

    S4Change();

    s4advdial->S4AdvDialClearAll();

    s4advdial->s4AdvDialLabelElem1 = stage4->s4LabelElem1;
    s4advdial->s4AdvDialSkillsElem1 = stage4->s4SkillsElem1;
    s4advdial->s4AdvDialTraitsElem1 = stage4->s4TraitsElem1;
    s4advdial->s4AdvDialElem1 = stage4->s4Elem1;

    s4advdial->s4AdvDialLabelElem2 = stage4->s4LabelElem2;
    s4advdial->s4AdvDialSkillsElem2 = stage4->s4SkillsElem2;
    s4advdial->s4AdvDialTraitsElem2 = stage4->s4TraitsElem2;
    s4advdial->s4AdvDialElem2 = stage4->s4Elem2;

    s4advdial->s4AdvDialLabelElem3 = stage4->s4LabelElem3;
    s4advdial->s4AdvDialSkillsElem3 = stage4->s4SkillsElem3;
    s4advdial->s4AdvDialTraitsElem3 = stage4->s4TraitsElem3;
    s4advdial->s4AdvDialElem3 = stage4->s4Elem3;

    s4advdial->s4AdvDialLabelElem4 = stage4->s4LabelElem4;
    s4advdial->s4AdvDialSkillsElem4 = stage4->s4SkillsElem4;
    s4advdial->s4AdvDialTraitsElem4 = stage4->s4TraitsElem4;
    s4advdial->s4AdvDialElem4 = stage4->s4Elem4;

    s4advdial->s4AdvDialLabelElem5 = stage4->s4LabelElem5;
    s4advdial->s4AdvDialSkillsElem5 = stage4->s4SkillsElem5;
    s4advdial->s4AdvDialTraitsElem5 = stage4->s4TraitsElem5;
    s4advdial->s4AdvDialElem5 = stage4->s4Elem5;
    s4advdial->s4AdvDialRepit5 = stage4->s4Repit5;

    s4advdial->s4AdvDialLabelElem6 = stage4->s4LabelElem6;
    s4advdial->s4AdvDialSkillsElem6 = stage4->s4SkillsElem6;
    s4advdial->s4AdvDialTraitsElem6 = stage4->s4TraitsElem6;
    s4advdial->s4AdvDialAttrElem6 = stage4->s4AttrElem6;
    s4advdial->s4AdvDialElem6 = stage4->s4Elem6;
    s4advdial->s4AdvDialRepit6 = stage4->s4Repit6;

    s4advdial->s4AdvDialLabelElem7 = stage4->s4LabelElem7;
    s4advdial->s4AdvDialSkillsElem7 = stage4->s4SkillsElem7;
    s4advdial->s4AdvDialTraitsElem7 = stage4->s4TraitsElem7;
    s4advdial->s4AdvDialElem7 = stage4->s4Elem7;
    s4advdial->s4AdvDialRepit7 = stage4->s4Repit7;

    s4advdial->s4AdvDialLabelElem8 = stage4->s4LabelElem8;
    s4advdial->s4AdvDialSkillsElem8 = stage4->s4SkillsElem8;
    s4advdial->s4AdvDialTraitsElem8 = stage4->s4TraitsElem8;
    s4advdial->s4AdvDialElem8 = stage4->s4Elem8;

    s4advdial->s4AdvDialNameRLife = ui->S4LifeComboBox->currentText();

    s4advdial->S4AdvDialInit();

    s4advdial->show();
    s4advdial->raise();
    s4advdial->activateWindow();
}

void Wizard::S4AdvDialAcceptButton() {

    QMap<QString, int> s4AttrSwp;

    for (int i=0; i < s4advdial->s4AdvDialAttr.count(); ++i) {
        s4AttrSwp[s4advdial->s4AdvDialAttr[i].first] = s4advdial->s4AdvDialAttr[i].second;
    }

    AddAffilAttr(s4AttrSwp);
    AddAfillSkill(s4advdial->s4AdvDialSkills);
    AddAfillTraits(s4advdial->s4AdvDialTraits);
    S4Change();
}

void Wizard::S4AdvDialCancelButton() {
    s4advdial->s4AdvDialAttr.clear();
    s4advdial->s4AdvDialTraits.clear();
    s4advdial->s4AdvDialSkills.clear();
    S4Change();
}

void Wizard::S4LifeAddButton() {
    QStringList S4ClearLifeListSwp;
    if(ui->S4LifeComboBox->currentText() == "Clan Warrior Washout") {
        S4ClearLifeListSwp.clear();
        for (int i=0; i < S4ClearLifeList.count(); i++) {
            if (S4ClearLifeList[i] != "Clan Warrior Washout") {
                S4ClearLifeListSwp << S4ClearLifeList[i];
            }
        }
        S4ClearLifeList = S4ClearLifeListSwp;
    }

    if(ui->S4LifeComboBox->currentText() == "Cloister Training") {
        S4ClearLifeListSwp.clear();
        for (int i=0; i < S4ClearLifeList.count(); i++) {
            if (S4ClearLifeList[i] != "Cloister Training") {
                S4ClearLifeListSwp << S4ClearLifeList[i];
            }
        }
        S4ClearLifeList = S4ClearLifeListSwp;
        ui->S4LifeComboBox->clear();
        ui->S4LifeComboBox->addItems(S4ClearLifeList);
    }

    if(ui->S4LifeComboBox->currentText() == "Postgraduate Studies") {
        S4ClearLifeListSwp.clear();
        for (int i=0; i < S4ClearLifeList.count(); i++) {
            if (S4ClearLifeList[i] != "Postgraduate Studies") {
                S4ClearLifeListSwp << S4ClearLifeList[i];
            }
        }
        S4ClearLifeList = S4ClearLifeListSwp;
        ui->S4LifeComboBox->clear();
        ui->S4LifeComboBox->addItems(S4ClearLifeList);
    }

    if(ui->S4LifeComboBox->currentText() == "Protomech Pilot Training") {
        S4ClearLifeListSwp.clear();
        for (int i=0; i < S4ClearLifeList.count(); i++) {
            if (S4ClearLifeList[i] != "Protomech Pilot Training") {
                S4ClearLifeListSwp << S4ClearLifeList[i];
            }
        }
        S4ClearLifeList = S4ClearLifeListSwp;
        ui->S4LifeComboBox->clear();
        ui->S4LifeComboBox->addItems(S4ClearLifeList);
    }

    if(ui->S4LifeComboBox->currentText() == "Tour Of Duty") {
        bool chkSol = false;

        for (int i=0; i < S4ClearLifeList.count(); i++) {
            if (S4ClearLifeList[i] == "Solaris VII Games") {
                chkSol = true;
            }
        }

        if(!chkSol) {
            ui->S4LifeComboBox->addItem("Solaris VII Games");
        }
    }

    stage4->s4AttrMod.clear();
    stage4->s4XpCost = 0;
    stage4->s4SkillsMod.clear();
    stage4->s4TraitsMod.clear();
    chr_dat->age += stage4->s4Age;

    ui->S4MorePushButton->setDisabled(true);
    ui->S4LifeAddButton->setDisabled(true);
    ui->S4FlexXPPushButton->setDisabled(true);


    if(chr_dat->age >= 100) {
        QMessageBox::warning(this, "You are very old", "You are very old, can you ask a nurse from GameMaster?");
    }

    chr_dat->realLife = ui->S4LifeComboBox->currentText();
    S4AdvDialCancelButton();
    s2fxpdialog->S2FlexXPDialogInit();
    stage4->s4repeat = true;
}

void Wizard::S4RemoveOldParam() {
    changeXP(stage4->s4XpCost, false);
    if(stage4->s4repeat !=true ) {
        QMapIterator <QString, int> i(stage4->s4AttrMod);
        while(i.hasNext()) {
            i.next();
            chr_dat->charAttr[i.key()] = chr_dat->charAttr[i.key()] - i.value();
        }
    }
    for(int sCount = 0 ; sCount < stage4->s4SkillsMod.count() ; sCount++) {
        chr_dat->changeSkills(stage4->s4SkillsMod[sCount].first, -stage4->s4SkillsMod[sCount].second);
    }



    for(int sCount = 0 ; sCount < stage4->s4TraitsMod.count() ; sCount++) {
        chr_dat->changeTraits(stage4->s4TraitsMod[sCount].first,-stage4->s4TraitsMod[sCount].second);
    }
}

void Wizard::S4LifeComboBoxChange(QString nameElem) {
    ui->S4MorePushButton->setDisabled(false);
    ui->S4LifeAddButton->setDisabled(false);
    if(s4advdial->s4AdvDialSkills.isEmpty() != true || s4advdial->s4AdvDialTraits.isEmpty() != true) {
        if(s4advdial->s4AdvDialAttr.isEmpty() != true) {
            if(stage4->s4repeat !=true ) {
                for (int i=0; i < s4advdial->s4AdvDialAttr.count(); ++i) {
                    chr_dat->charAttr[s4advdial->s4AdvDialAttr[i].first] = -s4advdial->s4AdvDialAttr[i].second;
                }
            }
            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialSkills.count() ; sCount++) {
                chr_dat->changeSkills(s4advdial->s4AdvDialSkills[sCount].first, -s4advdial->s4AdvDialSkills[sCount].second);
            }



            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialTraits.count() ; sCount++) {
                chr_dat->changeTraits(s4advdial->s4AdvDialTraits[sCount].first,-s4advdial->s4AdvDialTraits[sCount].second);
            }

        } else {
            if(stage4->s4repeat !=true ) {
                for (int i=0; i < s4advdial->s4AdvDialAttr.count(); ++i) {
                    chr_dat->charAttr[s4advdial->s4AdvDialAttr[i].first] = -s4advdial->s4AdvDialAttr[i].second;
                }
            }

            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialSkills.count(); sCount++) {
                chr_dat->changeSkills(s4advdial->s4AdvDialSkills[sCount].first, -s4advdial->s4AdvDialSkills[sCount].second);
            }



            for(int sCount = 0 ; sCount < s4advdial->s4AdvDialTraits.count(); sCount++) {
                chr_dat->changeTraits(s4advdial->s4AdvDialTraits[sCount].first,-s4advdial->s4AdvDialTraits[sCount].second);
            }
        }
    }

//    S4Change();

    s4advdial->S4AdvDialClearAll();
    S4RemoveOldParam();

    stage4->S4ChooseLife(nameElem);
    ui->S4LifeComboBox->setToolTip(stage4->s4toolTip);

    if(stage4->s4FlexXP != 0 ) {
        ui->S4FlexXPPushButton->setDisabled(false);
    }

    if (stage4->s4AffLang != 0) {
        stage4->S4AddSkills(ui->lang_ZStage_ComboBox->currentText(), stage4->s4AffLang);
    }

    if (stage4->s4AffProt != 0) {
        stage4->S4AddSkills(txt_res->affProtocol, stage4->s4AffProt);
    }

    if (stage4->s4AffStreet != 0) {
        stage4->S4AddSkills(txt_res->affStreet, stage4->s4AffStreet);
    }

    if(stage4->s4repeat !=true ) {
        AddAffilAttr(stage4->s4AttrMod);
    }
    changeXP(stage4->s4XpCost, true);
    AddAfillSkill(stage4->s4SkillsMod);
    AddAfillTraits(stage4->s4TraitsMod);
    S4Change();
}

void Wizard::S4Change() {

    ui->S4StatusXP->setText(QString::number(chr_dat->xp));
    ui->S4StatusXP->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));

    ui->S4StatusAge->setText(QString::number(chr_dat->age + stage4->s4Age));
    ui->S4StatusAge->setFont(QFont("MS Shell Dlg 2", 14, QFont::Bold));

    ChangeAgeAttr(chr_dat->age + stage4->s4Age);
    // 
    ui->S4AttrStrLabel->setText("<b>STR:</b> " + QString::number(chr_dat->charAttr.value("STR")));
    ui->S4AttrBodLabel->setText("<b>BOD:</b> " + QString::number(chr_dat->charAttr.value("BOD")));
    ui->S4AttrRflLabel->setText("<b>RFL:</b> " + QString::number(chr_dat->charAttr.value("RFL")));
    ui->S4AttrDexLabel->setText("<b>DEX:</b> " + QString::number(chr_dat->charAttr.value("DEX")));
    ui->S4AttrIntLabel->setText("<b>INT:</b>  " + QString::number(chr_dat->charAttr.value("INT")));
    ui->S4AttrWilLabel->setText("<b>WIL:</b> " + QString::number(chr_dat->charAttr.value("WIL")));
    ui->S4AttrChaLabel->setText("<b>CHA:</b> " + QString::number(chr_dat->charAttr.value("CHA")));
    ui->S4AttrEdgLabel->setText("<b>EDG:</b> " + QString::number(chr_dat->charAttr.value("EDG")));
    chr_dat->clearZeroSkills();
    chr_dat->clearZeroTraits();
    // 
    S4PrintSkillsTable();
    S4PrintTraitsTable();

}

void Wizard::S4PrintSkillsTable() {
    ui->S4SkillsTable->clear();
    qSort(chr_dat->charSkills.begin(), chr_dat->charSkills.end());
    ui->S4SkillsTable->setRowCount(chr_dat->charSkills.count());
    for(int sCount = 0 ; sCount < chr_dat->charSkills.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charSkills[sCount].first);
        newSNameItem->setToolTip(SkillDesc(chr_dat->charSkills[sCount].first));
        ui->S4SkillsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charSkills[sCount].second));
        ui->S4SkillsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::S4PrintTraitsTable()
{
    ui->S4TraitsTable->clear();
    qSort(chr_dat->charTraits.begin(), chr_dat->charTraits.end());
    ui->S4TraitsTable->setRowCount(chr_dat->charTraits.count());
    for(int sCount = 0 ; sCount < chr_dat->charTraits.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(chr_dat->charTraits[sCount].first);
        newSNameItem->setToolTip(TraitsDesc(chr_dat->charTraits[sCount].first));
        ui->S4TraitsTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(chr_dat->charTraits[sCount].second));
        ui->S4TraitsTable->setItem(sCount,1,newSValueItem);
    }

}

void Wizard::on_HairComboBox_activated(QString nameElem)
{
    chr_dat->hair = nameElem;
}

void Wizard::on_EyeComboBox_activated(QString nameElem)
{
    chr_dat->eye = nameElem;
}

void Wizard::on_HeightSpinBox_valueChanged(int nameElem)
{
    chr_dat->height = nameElem;
}

void Wizard::on_WeightSpinBox_valueChanged(int nameElem)
{
    chr_dat->weight = nameElem;
}

void Wizard::on_SexComboBox_activated(QString nameElem)
{
    chr_dat->sex = nameElem;
}



void Wizard::on_StartXPcheckBox_toggled(bool checked)
{
    if(checked == false) {
        ui->startXPSpinBox->setEnabled(true);
    } else {
        ui->startXPSpinBox->setEnabled(false);
        ui->startXPSpinBox->setValue(5000);
    }
}

void Wizard::on_startXPSpinBox_valueChanged(int startXP)
{
    chr_dat->startXP = startXP;
}


QString Wizard::SkillDesc(QString nameSkill) {
    QString description;

    if (skillsDescList.contains(nameSkill)){
        description = skillsDescList.value(nameSkill);
    } else {
        QStringList nameSkillswp = nameSkill.split("/" ,QString::SkipEmptyParts);
        description = skillsDescList.value(nameSkillswp[0]);
    }

    return description;
}

QString Wizard::TraitsDesc(QString nameTraits) {

    QString description;

    if (traitsDescList.contains(nameTraits)){
        description = traitsDescList.value(nameTraits);
    } else {
        QStringList nameTraitswp = nameTraits.split("/" ,QString::SkipEmptyParts);
        description = traitsDescList.value(nameTraitswp[0]);
    }

    return description;
}


void Wizard::ChangeAgeAttr(int age) {
    chr_dat->charAttr["STR"] = chr_dat->charAttr["STR"] - txt_res->ageCharAttr["STR"];
    chr_dat->charAttr["BOD"] = chr_dat->charAttr["BOD"] - txt_res->ageCharAttr["BOD"];
    chr_dat->charAttr["RFL"] = chr_dat->charAttr["RFL"] - txt_res->ageCharAttr["RFL"];
    chr_dat->charAttr["DEX"] = chr_dat->charAttr["DEX"] - txt_res->ageCharAttr["DEX"];
    chr_dat->charAttr["INT"] = chr_dat->charAttr["INT"] - txt_res->ageCharAttr["INT"];
    chr_dat->charAttr["WIL"] = chr_dat->charAttr["WIL"] - txt_res->ageCharAttr["WIL"];
    chr_dat->charAttr["CHA"] = chr_dat->charAttr["CHA"] - txt_res->ageCharAttr["CHA"];
    S2DelTraits(txt_res->ageTraits);
    txt_res->AgeAttr(age, chr_dat->AffName.first);
    AddAfillTraits(txt_res->ageTraits);
    chr_dat->charAttr["STR"] = chr_dat->charAttr["STR"] + txt_res->ageCharAttr["STR"];
    chr_dat->charAttr["BOD"] = chr_dat->charAttr["BOD"] + txt_res->ageCharAttr["BOD"];
    chr_dat->charAttr["RFL"] = chr_dat->charAttr["RFL"] + txt_res->ageCharAttr["RFL"];
    chr_dat->charAttr["DEX"] = chr_dat->charAttr["DEX"] + txt_res->ageCharAttr["DEX"];
    chr_dat->charAttr["INT"] = chr_dat->charAttr["INT"] + txt_res->ageCharAttr["INT"];
    chr_dat->charAttr["WIL"] = chr_dat->charAttr["WIL"] + txt_res->ageCharAttr["WIL"];
    chr_dat->charAttr["CHA"] = chr_dat->charAttr["CHA"] + txt_res->ageCharAttr["CHA"];
}
