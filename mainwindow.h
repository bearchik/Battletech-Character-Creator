#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wizard.h"
#include "loadresurce.h"
#include "preqdialog.h"
#include "about.h"
#include "gmchartools.h"
#include "chekver.h"
#include "printtablewindow.h"

//class QDragEnterEvent;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void changeSkills(QString, int);
    void changeTraits(QString, int);
    int findSkill(QString, QList<QPair<QString, int> >);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Wizard *wz;
    LoadResurce *loadres;
    PreqDialog *preqdial;
    About *about;
    GMCharTools *gmchrtool;
    PrintTableWindow *ptrtablewin;
    ChkVer *chkver;

    int MainInit();
    void ChangeMain();
    void PrintSkillsTable();
    void PrintAllSkillsTable();
    void PrintTraitsTable();
    void PrintAllTraitsTable();
    void PrintAllEquipTable(QString);
    void PrintEquipTable();
    void PrintAllWeaponTable(QString);
    void PrintWeaponTable();


    void PrintAllYouEquip();
    void PrintYouWeapon();

    void SetWigetValue();
    int CheckTraitLvl(QString, int);
    int CheckSkillLvl(int);
    int CheckCBills(int);
    int SumSkillsXP();
    int SumTraitsXP();
    int scoreStattoStatvalue(int);
    int StatvaluetoLinkmod(int);
    double calcMassfromSTRscore(double);
    QStringList CreatAffList(QString);
    QStringList CreatPhenList(QString);
    QStringList CreateList(QString, QStringList);

    QStringList CreateSubAffList(QString);

    void openFile(QString);
    void saveFile(QString);
    void saveFileAs(QString);
    QStringList prepSaveFile();

    void AddEquip(QStringList);
    void DelEquip(QString);

    void AddWeapon(QStringList);
    void DelWeapon(QString);

    bool CheckPrereq();

    void PrintSheet();

    QString BodyLoc(QString);
    QString InventToolTip(QString);

    void AddInvElem(QString);
    void EraseLocation(QString);
    void closeEvent(QCloseEvent *event);
    void titleRenam(bool chk);
    void prerqPrintTable();

    QStringList AdvTried(QString elem, int lvlSkill);



    int xpMain; //   XP
    int ageMain; //  
    int Linkmod;
    int Statvalue;
    double Skillmultiplier;
    QString charNameMain; //  
    QPair <QString, int> affNameMain; //   
    QPair <QString, int> subAffNameMain; //    
    QPair <QString, int> clanCastNameMain; //   
    QPair <QString, int> earlyChildNameMain; //    
    QPair <QString, int> lateChildNameMain; //    
    QPair <QString, int> schoolNameMain; //   
    QPair <QString, int> basicSchoolMain; //    
    QPair <QString, int> advSchoolMain; //    
    QPair <QString, int> specSchoolMain; //    
    QString realLifeMain;
    QString phenotypeMain;
    QStringList planetList;
    QString namePlanetMain;
    QString sexMain;
    QString hairMain;
    QString eyeMain;
    int heightMain;
    int weightMain;
    double massChar;
    double STRscore;

    QMap<QString, int> preCharAttrMain; //
    QList<QPair<QString, int> > preCharSkillsMain; //
    QList<QPair<QString, int> > preCharTraitsMain;

    QVector<QStringList> equipChar;
    QVector<QStringList> weaponChar;
    QVector<QStringList> youWeapon;

    int wizardMod;

    QPair <QString, bool> openFileName;
    QList<QPair<QString, QString> > openFileData;


    QMap<QString, int> charAttrMain; //  
    QList<QPair<QString, int> > charSkillsMain; //  
    QList<QPair<QString, int> > charTraitsMain;
    bool chkWiz;

    int cbills;
    int countCBills;

    QPrinter printer;

    QStringList dropElem;

    QStringList cutLocList;
    QMap<QString, QString> loc;

    bool saveFlag;

    QMap<QString, QString> skillsDescList;
    QString SkillDesc(QString nameSkill);

    QMap<QString, QString> traitsDescList;
    QString TraitsDesc(QString nameSkill);

private:
    Ui::MainWindow *ui;

    void dragEnterEvent(QDragEnterEvent *event);

public slots:
    void FinishWizard();
    void CancelWizard();
    void AddGmNum();

private slots:
    void on_TraitChrTableMain_cellClicked(int row, int column);
    void on_SkillChrTableMain_cellClicked(int row, int column);
    void on_FeetsListMain_doubleClicked(QModelIndex index);
    void on_HandRightListMain_doubleClicked(QModelIndex index);
    void on_HandLeftListMain_doubleClicked(QModelIndex index);
    void on_LegsListMain_doubleClicked(QModelIndex index);
    void on_ArmRightListMain_doubleClicked(QModelIndex index);
    void on_ArmLeftListMain_doubleClicked(QModelIndex index);
    void on_BodyListMain_doubleClicked(QModelIndex index);
    void on_HeadListMain_doubleClicked(QModelIndex index);
    void on_HandRightListMain_itemChanged(QListWidgetItem* item);
    void on_HandLeftListMain_itemChanged(QListWidgetItem* item);
    void on_ItselfAllYouTable_cellDoubleClicked(int row, int column);
    void on_AllYouTable_cellDoubleClicked(int row, int column);
    void on_FeetsListMain_itemChanged(QListWidgetItem* item);
    void on_LegsListMain_itemChanged(QListWidgetItem* item);
    void on_ArmRightListMain_itemChanged(QListWidgetItem* item);
    void on_ArmLeftListMain_itemChanged(QListWidgetItem* item);
    void on_BodyListMain_itemChanged(QListWidgetItem* item);
    void on_HeadListMain_itemChanged(QListWidgetItem* item);
    void on_actionAdd_C_Bills_triggered();
    void on_DeleteTraitsMain_clicked();
    void on_DeleteSkillMain_clicked();
    void on_actionAbout_triggered();
    void on_actionCheck_Wizard_triggered();
    void on_AddAmmoMain_clicked();
    void on_WeaponChrTableMain_cellDoubleClicked(int row, int column);
    void on_WeaponAllTableMain_cellDoubleClicked(int row, int column);
    void on_WeaponType_activated(QString );
    void on_EquipChrTableMain_cellDoubleClicked(int row, int column);
    void on_EquipAllTableMain_cellDoubleClicked(int row, int column);
    void on_EquipType_activated(QString );
    void on_actionPrint_triggered();
    void on_actionNew_triggered();
    void on_TraitlDelMain_clicked();
    void on_TraitAddMain_clicked();
    void on_TraitChrTableMain_cellDoubleClicked(int row, int column);
    void on_TraitAllTableMain_cellDoubleClicked(int row, int column);
    void on_SkillDelMain_clicked();
    void on_SkillAddMain_clicked();
    void on_SkillChrTableMain_cellDoubleClicked(int row, int column);
    void on_SkillAllTableMain_cellDoubleClicked(int row, int column);
    void on_CharNameMain_editingFinished();
    void on_EyeColorMain_activated(QString );
    void on_HairColorMain_activated(QString );
    void on_WeightMain_valueChanged(int );
    void on_HeightMain_valueChanged(int );
    void on_SexMain_activated(QString );
    void on_AgeMain_valueChanged(int );
    void on_HomePlanetMain_activated(QString );
    void on_AffilationMain_activated(QString );
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionOpen_triggered();
    void on_PhenotypeMain_activated(QString );
    void on_TraitResetMain_clicked();
    void on_SkillResetMain_clicked();
    void on_EDGSpinBoxMain_valueChanged(int );
    void on_CHASpinBoxMain_valueChanged(int );
    void on_WILSpinBoxMain_valueChanged(int );
    void on_INTSpinBoxMain_valueChanged(int );
    void on_DEXSpinBoxMain_valueChanged(int );
    void on_RFLSpinBoxMain_valueChanged(int );
    void on_BODSpinBoxMain_valueChanged(int );
    void on_STRSpinBoxMain_valueChanged(int );
    void on_actionNew_Wizard_triggered();
    void on_actionQuit_triggered();
    void preqDial();

    void on_pushButton_clicked();
    void on_SkillChrTableMain_cellChanged(int row, int column);
    void on_TraitChrTableMain_cellChanged(int row, int column);
    void on_actionPrint_Tables_triggered();
};


#endif // MAINWINDOW_H
