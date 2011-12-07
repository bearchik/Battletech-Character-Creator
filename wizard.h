#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>
#include <QMap>
#include "chardata.h"
#include "stage1_resurce.h"
#include "stage2_resurce.h"
#include "stage3_resurce.h"
#include "stage4_resurce.h"
#include "s2flexxpdialog.h"
#include "s2advdialog.h"
#include "s2clanfielddialog.h"
#include "s3fielddialog.h"
#include "s4advdial.h"
#include "carierfields.h"
#include "loadresurce.h"
#include "s0moredialog.h"
#include "s1moredialog.h"


namespace Ui {
    class Wizard;
}

class Wizard : public QWizard {
    Q_OBJECT
public:
    Wizard(QWidget *parent = 0);
    ~Wizard();
    CharData *chr_dat; //  
    void PrereqStage();

protected:
    void changeEvent(QEvent *e);

private:
    int xp;
    Ui::Wizard *ui;
    Text_Resurce *txt_res; //    
//    CharData *chr_dat; //  
    Stage1 *stage1; //  Stage1
    Stage2 *stage2; //  Stage2
    Stage3 *stage3; //  Stage3
    Stage4 *stage4; //  Stage4
    LoadResurce *loadres; //  
    CarierFields *carField;

    S0MoreDialog *s0moredial;
    S1MoreDialog *s1moredial;
    S2FlexXPDialog *s2fxpdialog;
    S2AdvDialog *s2advdial;
    S2ClanFieldDialog *s2clanfield;
    S3FieldDialog *s3fielddial;
    S4AdvDial *s4advdial;


    QString swpLang; // swap  
    QString swpElem1Skills;
    QString swpElem1Traits;
    QString swpElem2Skills;
    QString swpElem2Traits;

    QMap <QString, int> swpFXAttr;

    QStringList swpFMAttr;
    QString swpComElem;

    QList<QPair<QString, int> > swpAdvSkillElem; //     
    QList<QPair<QString, int> > swpAdvTraitElem; //     

    QString swpAffSkillsElem1;
    int swpAffSkillsElem1Int;
    QString swpAffTraitsElem1;
    int swpAffTraitsElem1Int;
    void changeElem1main(QString);

    QString swpAffSkillsElem2;
    int swpAffSkillsElem2Int;
    QString swpAffTraitsElem2;
    int swpAffTraitsElem2Int;
    void changeElem2main(QString);

    QString swpAffSkillsElem3;
    int swpAffSkillsElem3Int;
    QString swpAffTraitsElem3;
    int swpAffTraitsElem3Int;
    QString swpAffAttrElem3;
    void changeElem3main(QString);

    QStringList careerList;

//    QString swpAffSkillsElem4;
//    int swpAffSkillsElem4Int;
//    QString swpAffTraitsElem4;
//    int swpAffTraitsElem4Int;
//    QString swpAffAttrElem4;
//    void changeElem4main(QString);

    QStringList S4ClearLifeList;
    QMultiMap<QString, QString> subSkillList;

    bool chkAdvButton;
    bool chkFlexButton;

    int s3RebateXp;

    void connectEvent(); //    

    void S1ConnectEvent(); //    STAGE1
    void S2ConnectEvent(); //    STAGE2
    void S3ConnectEvent(); //    STAGE3
    void S4ConnectEvent(); //    STAGE3
    void changeXP(int, bool); //   XP, int -    , bool -   
    void printSkillTable(); //   
    void printTraitsTable(); //   
    void initStartLang(QStringList); //     
    void hideGUIElem();
    void unchekRadButton();
    void changeAffSkill(QString, int);

    int calculateXP();
    void addAffilAttr();
    void addAfillSkill();
    void addAfillTraits();
    void addAffElem(int);
    void removeOldParam();
    void removeOldParamCast();
    void clearAdvSwap();
//    void hardAdvElem4(QString);
//    void flexXpChange(QString);
//    void flexXpChangeOther(QString);

    void S1AddAffilAttr();
    void S1Change();
    void S1RemoveOldParam();
    void S1AddAfillSkill();
    void S1AddAfillTraits();
    void S1PrintSkillsTable();
    void S1PrintTraitsTable();
    void S1ComBoxChange();
    void S1ChangeElem1Main(QString);
    void S1ChangeElem2Main(QString);
    void S1ChangeElem3Main(QString);
//    void S1ShortFlex(QString);
//    void S1ShortLong(QString);

    void Stage2Main();
    void S2Change();
    void S2PrintSkillsTable();
    void S2PrintTraitsTable();
    void S2RemoveOldParam();
    void AddAffilAttr(QMap <QString, int>);
    void AddAfillSkill(QList<QPair<QString, int> >);
    void AddAfillTraits(QList<QPair<QString, int> >);
    void S2ComBoxChange();
    void S2ChangeElem1Main(QString);
    void S2ChangeElem2Main(QString);
    void S2ChangeElem3Main(QString);

    void S2DelAttr(QMap <QString, int>);
    void S2DelSkills(QList<QPair<QString, int> >);
    void S2DelTraits(QList<QPair<QString, int> >);

    void Stage3Main();
    void S3RemoveOldParam();
    void S3Change();
    void S3PrintSkillsTable();
    void S3PrintTraitsTable();
    void S3CallFieldDial(QString);

    QStringList s3SchoolList;
    int s3AdvCount;

    void Stage4Main();
    void S4Change();
    void S4PrintSkillsTable();
    void S4PrintTraitsTable();
    void S4RemoveOldParam();

    QMap<QString, QString> skillsDescList;
    QString SkillDesc(QString nameSkill);

    QMap<QString, QString> traitsDescList;
    QString TraitsDesc(QString nameSkill);


    void ChangeAgeAttr(int age);



private slots:


public slots:
//    void FinishWizard();
    void MainWizard();
    void BackChange();
    void change();
    void changeAff(int);
    void changeStartLang(QString);
    void changeComsBox(bool);
    void changeAffElem1(QString);
    void changeAffElem2(QString);
    void changeSubAffil(int);
    void changeCom(bool);
    void changeWoB(bool);
    void changeElem1(QString);
    void changeElem2(QString);
    void changeElem3(QString);
//    void changeElem4(QString);
    void changeWobComBox(QString);

    void S0AdvDialAccept();
    void S0AdvDialCancel();

    void S1ChangeElem1(QString);
    void S1ChangeElem2(QString);
    void S1ChangeElem3(QString);
    void S1ChangeElem4(QString);
    void S1AdvDialAccept();
    void S1AdvDialCancel();

    void S2ChangeElem1(QString);
    void S2ChangeElem2(QString);
    void S2ChangeElem3(QString);

    void Stage1Main();
    void S1ChangeChilHod(QString);

    void S2FlexXpButton();
    void S2AdvButton();
    void S2ChangeLateChildHood(QString);
    void S2AdvDialAcceptButton();
    void S2AdvDialCancelButton();
    void S2FlexXpButtonAcceptButton();
    void S2FlexXpButtonCancelButton();

    void S3SchoolComboBoxChange(QString);
    void S3SChoolAddButtonClick();
    void S3BasicAddButtonClick();
    void S3AdvAddButtonClick();
    void S3SpecAddButtonClick();
    void S3FieldDialogAccept();
    void S3ComboBoxBasicChange(QString);
    void S3ComboBoxAdvChange(QString);
    void S3ComboBoxSpecChange(QString);

    void S4LifeComboBoxChange(QString);
    void S4AdvButton();
    void S4AdvDialAcceptButton();
    void S4AdvDialCancelButton();
    void S4LifeAddButton();

    virtual void accept();
    virtual void back();


private slots:


private slots:
    void on_S1MoreButton_clicked();
    void on_S0MoreButton_clicked();
    void on_SexComboBox_activated(QString );
    void on_HeightSpinBox_valueChanged(int );
    void on_WeightSpinBox_valueChanged(int );
    void on_EyeComboBox_activated(QString );
    void on_HairComboBox_activated(QString );
    void on_StartXPcheckBox_toggled(bool checked);
    void on_startXPSpinBox_valueChanged(int arg1);
};



#endif // WIZARD_H
