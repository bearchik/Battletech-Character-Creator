/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 6. Dec 12:11:39 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "spinbox.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionNew_Wizard;
    QAction *actionCheck_Wizard;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionAdd_C_Bills;
    QAction *actionAdd_XP;
    QAction *actionNPC;
    QAction *actionPrint_Tables;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *MainTab;
    QGroupBox *MainGroupBox;
    QLineEdit *CharNameMain;
    QLabel *label;
    QComboBox *AffilationMain;
    QComboBox *PhenotypeMain;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *HomePlanetMain;
    QLabel *label_4;
    QSpinBox *AgeMain;
    QLabel *label_5;
    QComboBox *SexMain;
    QLabel *label_6;
    QSpinBox *HeightMain;
    QLabel *label_7;
    QSpinBox *WeightMain;
    QLabel *label_8;
    QComboBox *HairColorMain;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *EyeColorMain;
    QLineEdit *CBillsMain;
    QLabel *label_11;
    QGroupBox *groupBox;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *WalkMain;
    QLineEdit *RunEvadeMain;
    QLineEdit *SprintMain;
    QLineEdit *ClimbMain;
    QLineEdit *CrawlMain;
    QLineEdit *SwimMain;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *FreeXPMain;
    QLabel *label_18;
    QComboBox *SubAffilationMain;
    QLabel *label_37;
    QWidget *AttributeTab;
    QGroupBox *AttributeGroupBox;
    QGroupBox *groupBox_3;
    QLabel *statusXPAttrMain;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_24;
    SpinBox *EDGSpinBoxMain;
    QLabel *label_26;
    SpinBox *CHASpinBoxMain;
    QLabel *label_22;
    SpinBox *WILSpinBoxMain;
    QLabel *label_23;
    SpinBox *INTSpinBoxMain;
    QLabel *label_20;
    SpinBox *DEXSpinBoxMain;
    QLabel *label_25;
    SpinBox *RFLSpinBoxMain;
    QLabel *label_21;
    SpinBox *BODSpinBoxMain;
    SpinBox *STRSpinBoxMain;
    QLabel *label_19;
    QLineEdit *ScoreSTRMain;
    QLineEdit *ScoreBODMain;
    QLineEdit *ScoreRFLMain;
    QLineEdit *ScoreDEXMain;
    QLineEdit *ScoreINTMain;
    QLineEdit *ScoreWILMain;
    QLineEdit *ScoreCHAMain;
    QLineEdit *ScoreEDGMain;
    QLineEdit *LinkSTRMain;
    QLineEdit *LinkBODMain;
    QLineEdit *LinkRFLMain;
    QLineEdit *LinkDEXMain;
    QLineEdit *LinkINTMain;
    QLineEdit *LinkWILMain;
    QLineEdit *LinkCHAMain;
    QLineEdit *LinkEDGMain;
    QLabel *label_38;
    QLabel *label_39;
    QTableWidget *preqListTable;
    QFrame *line_4;
    QLabel *label_40;
    QLabel *label_41;
    QFrame *line_5;
    QPushButton *pushButton;
    QWidget *SkillsTabswp;
    QGroupBox *TraitsGroupBox;
    QPushButton *SkillResetMain;
    QPushButton *SkillAddMain;
    QTableWidget *SkillAllTableMain;
    QTableWidget *SkillChrTableMain;
    QPushButton *SkillDelMain;
    QPushButton *DeleteSkillMain;
    QFrame *line;
    QGroupBox *groupBox_8;
    QLabel *CountSkillsMain;
    QGroupBox *groupBox_5;
    QLabel *statusXPSkillsMain;
    QWidget *TraitsTab;
    QGroupBox *SkillsGroupBox;
    QGroupBox *groupBox_4;
    QLabel *statusXPTraitsMain;
    QTableWidget *TraitAllTableMain;
    QTableWidget *TraitChrTableMain;
    QPushButton *TraitResetMain;
    QPushButton *TraitAddMain;
    QPushButton *TraitlDelMain;
    QPushButton *DeleteTraitsMain;
    QFrame *line_2;
    QGroupBox *groupBox_9;
    QLabel *CountTraitsMain;
    QWidget *EquipmentTab;
    QGroupBox *EquipmentGroupBox;
    QLabel *label_31;
    QLineEdit *MassEquipMain;
    QGroupBox *groupBox_6;
    QLabel *cbillsEq;
    QPushButton *TraitResetMain_2;
    QTableWidget *EquipAllTableMain;
    QPushButton *TraitAddMain_2;
    QPushButton *TraitlDelMain_2;
    QTableWidget *EquipChrTableMain;
    QComboBox *EquipType;
    QLabel *label_34;
    QWidget *WeaponsTab;
    QGroupBox *WeaponsGroupBox;
    QGroupBox *groupBox_7;
    QLabel *cbillsWp;
    QLineEdit *MassWeaponMain;
    QLabel *label_32;
    QTableWidget *WeaponChrTableMain;
    QTableWidget *WeaponAllTableMain;
    QPushButton *AddAmmoMain;
    QComboBox *WeaponType;
    QLabel *label_33;
    QWidget *Inventory;
    QGroupBox *WeaponsGroupBox_2;
    QFrame *frame;
    QListWidget *HeadListMain;
    QListWidget *BodyListMain;
    QListWidget *ArmLeftListMain;
    QListWidget *ArmRightListMain;
    QListWidget *LegsListMain;
    QListWidget *HandLeftListMain;
    QListWidget *HandRightListMain;
    QListWidget *FeetsListMain;
    QFrame *line_3;
    QTableWidget *AllYouTable;
    QLabel *label_35;
    QLabel *label_36;
    QTableWidget *ItselfAllYouTable;
    QWidget *NotesTab;
    QGroupBox *NotesGroupBox;
    QTextEdit *NotesMain;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuWizard;
    QMenu *menuHelp;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(752, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(752, 550));
        MainWindow->setMaximumSize(QSize(752, 550));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/ico1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionNew_Wizard = new QAction(MainWindow);
        actionNew_Wizard->setObjectName(QString::fromUtf8("actionNew_Wizard"));
        actionCheck_Wizard = new QAction(MainWindow);
        actionCheck_Wizard->setObjectName(QString::fromUtf8("actionCheck_Wizard"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAdd_C_Bills = new QAction(MainWindow);
        actionAdd_C_Bills->setObjectName(QString::fromUtf8("actionAdd_C_Bills"));
        actionAdd_XP = new QAction(MainWindow);
        actionAdd_XP->setObjectName(QString::fromUtf8("actionAdd_XP"));
        actionNPC = new QAction(MainWindow);
        actionNPC->setObjectName(QString::fromUtf8("actionNPC"));
        actionPrint_Tables = new QAction(MainWindow);
        actionPrint_Tables->setObjectName(QString::fromUtf8("actionPrint_Tables"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 751, 531));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        MainTab = new QWidget();
        MainTab->setObjectName(QString::fromUtf8("MainTab"));
        MainGroupBox = new QGroupBox(MainTab);
        MainGroupBox->setObjectName(QString::fromUtf8("MainGroupBox"));
        MainGroupBox->setGeometry(QRect(10, 5, 731, 501));
        CharNameMain = new QLineEdit(MainGroupBox);
        CharNameMain->setObjectName(QString::fromUtf8("CharNameMain"));
        CharNameMain->setGeometry(QRect(120, 30, 191, 20));
        label = new QLabel(MainGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 101, 16));
        AffilationMain = new QComboBox(MainGroupBox);
        AffilationMain->setObjectName(QString::fromUtf8("AffilationMain"));
        AffilationMain->setGeometry(QRect(120, 60, 191, 22));
        PhenotypeMain = new QComboBox(MainGroupBox);
        PhenotypeMain->setObjectName(QString::fromUtf8("PhenotypeMain"));
        PhenotypeMain->setGeometry(QRect(120, 120, 191, 22));
        label_2 = new QLabel(MainGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 81, 16));
        label_3 = new QLabel(MainGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 101, 16));
        HomePlanetMain = new QComboBox(MainGroupBox);
        HomePlanetMain->setObjectName(QString::fromUtf8("HomePlanetMain"));
        HomePlanetMain->setGeometry(QRect(120, 150, 191, 22));
        label_4 = new QLabel(MainGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 101, 16));
        AgeMain = new QSpinBox(MainGroupBox);
        AgeMain->setObjectName(QString::fromUtf8("AgeMain"));
        AgeMain->setGeometry(QRect(490, 30, 81, 22));
        AgeMain->setMaximum(200);
        AgeMain->setValue(21);
        label_5 = new QLabel(MainGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(410, 30, 101, 16));
        SexMain = new QComboBox(MainGroupBox);
        SexMain->setObjectName(QString::fromUtf8("SexMain"));
        SexMain->setGeometry(QRect(490, 60, 81, 22));
        label_6 = new QLabel(MainGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 60, 101, 16));
        HeightMain = new QSpinBox(MainGroupBox);
        HeightMain->setObjectName(QString::fromUtf8("HeightMain"));
        HeightMain->setGeometry(QRect(490, 90, 81, 22));
        HeightMain->setMinimum(100);
        HeightMain->setMaximum(300);
        HeightMain->setValue(175);
        label_7 = new QLabel(MainGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(410, 90, 101, 16));
        WeightMain = new QSpinBox(MainGroupBox);
        WeightMain->setObjectName(QString::fromUtf8("WeightMain"));
        WeightMain->setGeometry(QRect(490, 120, 81, 22));
        WeightMain->setMinimum(20);
        WeightMain->setMaximum(200);
        WeightMain->setValue(80);
        label_8 = new QLabel(MainGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(410, 120, 101, 16));
        HairColorMain = new QComboBox(MainGroupBox);
        HairColorMain->setObjectName(QString::fromUtf8("HairColorMain"));
        HairColorMain->setGeometry(QRect(490, 150, 81, 22));
        label_9 = new QLabel(MainGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(410, 150, 101, 16));
        label_10 = new QLabel(MainGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(410, 180, 101, 16));
        EyeColorMain = new QComboBox(MainGroupBox);
        EyeColorMain->setObjectName(QString::fromUtf8("EyeColorMain"));
        EyeColorMain->setGeometry(QRect(490, 180, 81, 22));
        CBillsMain = new QLineEdit(MainGroupBox);
        CBillsMain->setObjectName(QString::fromUtf8("CBillsMain"));
        CBillsMain->setEnabled(false);
        CBillsMain->setGeometry(QRect(120, 180, 191, 20));
        CBillsMain->setFrame(true);
        CBillsMain->setReadOnly(true);
        label_11 = new QLabel(MainGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 180, 101, 16));
        groupBox = new QGroupBox(MainGroupBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 270, 291, 111));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 20, 46, 13));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 50, 71, 16));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 80, 46, 13));
        WalkMain = new QLineEdit(groupBox);
        WalkMain->setObjectName(QString::fromUtf8("WalkMain"));
        WalkMain->setEnabled(false);
        WalkMain->setGeometry(QRect(80, 20, 71, 20));
        WalkMain->setReadOnly(true);
        RunEvadeMain = new QLineEdit(groupBox);
        RunEvadeMain->setObjectName(QString::fromUtf8("RunEvadeMain"));
        RunEvadeMain->setEnabled(false);
        RunEvadeMain->setGeometry(QRect(80, 50, 71, 20));
        RunEvadeMain->setReadOnly(true);
        SprintMain = new QLineEdit(groupBox);
        SprintMain->setObjectName(QString::fromUtf8("SprintMain"));
        SprintMain->setEnabled(false);
        SprintMain->setGeometry(QRect(80, 80, 71, 20));
        SprintMain->setReadOnly(true);
        ClimbMain = new QLineEdit(groupBox);
        ClimbMain->setObjectName(QString::fromUtf8("ClimbMain"));
        ClimbMain->setEnabled(false);
        ClimbMain->setGeometry(QRect(210, 20, 71, 20));
        ClimbMain->setReadOnly(true);
        CrawlMain = new QLineEdit(groupBox);
        CrawlMain->setObjectName(QString::fromUtf8("CrawlMain"));
        CrawlMain->setEnabled(false);
        CrawlMain->setGeometry(QRect(210, 50, 71, 20));
        CrawlMain->setReadOnly(true);
        SwimMain = new QLineEdit(groupBox);
        SwimMain->setObjectName(QString::fromUtf8("SwimMain"));
        SwimMain->setEnabled(false);
        SwimMain->setGeometry(QRect(210, 80, 71, 20));
        SwimMain->setReadOnly(true);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(170, 20, 46, 13));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(170, 50, 46, 13));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(170, 80, 46, 13));
        FreeXPMain = new QLineEdit(MainGroupBox);
        FreeXPMain->setObjectName(QString::fromUtf8("FreeXPMain"));
        FreeXPMain->setEnabled(false);
        FreeXPMain->setGeometry(QRect(120, 210, 191, 20));
        FreeXPMain->setFrame(true);
        FreeXPMain->setReadOnly(true);
        label_18 = new QLabel(MainGroupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 210, 101, 16));
        SubAffilationMain = new QComboBox(MainGroupBox);
        SubAffilationMain->setObjectName(QString::fromUtf8("SubAffilationMain"));
        SubAffilationMain->setGeometry(QRect(120, 90, 191, 22));
        label_37 = new QLabel(MainGroupBox);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(20, 90, 81, 16));
        tabWidget->addTab(MainTab, QString());
        AttributeTab = new QWidget();
        AttributeTab->setObjectName(QString::fromUtf8("AttributeTab"));
        AttributeGroupBox = new QGroupBox(AttributeTab);
        AttributeGroupBox->setObjectName(QString::fromUtf8("AttributeGroupBox"));
        AttributeGroupBox->setGeometry(QRect(10, 5, 731, 501));
        groupBox_3 = new QGroupBox(AttributeGroupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(610, 20, 101, 53));
        statusXPAttrMain = new QLabel(groupBox_3);
        statusXPAttrMain->setObjectName(QString::fromUtf8("statusXPAttrMain"));
        statusXPAttrMain->setGeometry(QRect(25, 17, 51, 21));
        label_27 = new QLabel(AttributeGroupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 99, 71, 16));
        label_28 = new QLabel(AttributeGroupBox);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(80, 99, 41, 16));
        label_29 = new QLabel(AttributeGroupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(124, 99, 31, 16));
        label_30 = new QLabel(AttributeGroupBox);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(170, 99, 21, 16));
        label_24 = new QLabel(AttributeGroupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(21, 330, 25, 16));
        EDGSpinBoxMain = new SpinBox(AttributeGroupBox);
        EDGSpinBoxMain->setObjectName(QString::fromUtf8("EDGSpinBoxMain"));
        EDGSpinBoxMain->setGeometry(QRect(160, 330, 51, 20));
        EDGSpinBoxMain->setAccelerated(true);
        EDGSpinBoxMain->setMaximum(900);
        label_26 = new QLabel(AttributeGroupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(21, 300, 26, 16));
        CHASpinBoxMain = new SpinBox(AttributeGroupBox);
        CHASpinBoxMain->setObjectName(QString::fromUtf8("CHASpinBoxMain"));
        CHASpinBoxMain->setGeometry(QRect(160, 300, 51, 20));
        CHASpinBoxMain->setAccelerated(true);
        CHASpinBoxMain->setMaximum(900);
        label_22 = new QLabel(AttributeGroupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(21, 270, 25, 16));
        WILSpinBoxMain = new SpinBox(AttributeGroupBox);
        WILSpinBoxMain->setObjectName(QString::fromUtf8("WILSpinBoxMain"));
        WILSpinBoxMain->setGeometry(QRect(160, 270, 51, 20));
        WILSpinBoxMain->setAccelerated(true);
        WILSpinBoxMain->setMaximum(800);
        label_23 = new QLabel(AttributeGroupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(21, 240, 22, 16));
        INTSpinBoxMain = new SpinBox(AttributeGroupBox);
        INTSpinBoxMain->setObjectName(QString::fromUtf8("INTSpinBoxMain"));
        INTSpinBoxMain->setGeometry(QRect(160, 240, 51, 20));
        INTSpinBoxMain->setAccelerated(true);
        INTSpinBoxMain->setMaximum(800);
        label_20 = new QLabel(AttributeGroupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(21, 210, 24, 16));
        DEXSpinBoxMain = new SpinBox(AttributeGroupBox);
        DEXSpinBoxMain->setObjectName(QString::fromUtf8("DEXSpinBoxMain"));
        DEXSpinBoxMain->setGeometry(QRect(160, 210, 51, 20));
        DEXSpinBoxMain->setAccelerated(true);
        DEXSpinBoxMain->setMaximum(800);
        label_25 = new QLabel(AttributeGroupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(21, 180, 23, 16));
        RFLSpinBoxMain = new SpinBox(AttributeGroupBox);
        RFLSpinBoxMain->setObjectName(QString::fromUtf8("RFLSpinBoxMain"));
        RFLSpinBoxMain->setGeometry(QRect(160, 180, 51, 20));
        RFLSpinBoxMain->setAccelerated(true);
        RFLSpinBoxMain->setMaximum(800);
        label_21 = new QLabel(AttributeGroupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(21, 150, 26, 16));
        BODSpinBoxMain = new SpinBox(AttributeGroupBox);
        BODSpinBoxMain->setObjectName(QString::fromUtf8("BODSpinBoxMain"));
        BODSpinBoxMain->setGeometry(QRect(160, 150, 51, 20));
        BODSpinBoxMain->setAccelerated(true);
        BODSpinBoxMain->setMaximum(800);
        STRSpinBoxMain = new SpinBox(AttributeGroupBox);
        STRSpinBoxMain->setObjectName(QString::fromUtf8("STRSpinBoxMain"));
        STRSpinBoxMain->setGeometry(QRect(160, 120, 51, 20));
        STRSpinBoxMain->setAccelerated(true);
        STRSpinBoxMain->setMaximum(800);
        label_19 = new QLabel(AttributeGroupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(21, 120, 25, 16));
        ScoreSTRMain = new QLineEdit(AttributeGroupBox);
        ScoreSTRMain->setObjectName(QString::fromUtf8("ScoreSTRMain"));
        ScoreSTRMain->setEnabled(false);
        ScoreSTRMain->setGeometry(QRect(80, 119, 31, 20));
        ScoreSTRMain->setMaxLength(4);
        ScoreSTRMain->setReadOnly(true);
        ScoreBODMain = new QLineEdit(AttributeGroupBox);
        ScoreBODMain->setObjectName(QString::fromUtf8("ScoreBODMain"));
        ScoreBODMain->setEnabled(false);
        ScoreBODMain->setGeometry(QRect(80, 149, 31, 20));
        ScoreBODMain->setMaxLength(4);
        ScoreBODMain->setReadOnly(true);
        ScoreRFLMain = new QLineEdit(AttributeGroupBox);
        ScoreRFLMain->setObjectName(QString::fromUtf8("ScoreRFLMain"));
        ScoreRFLMain->setEnabled(false);
        ScoreRFLMain->setGeometry(QRect(80, 179, 31, 20));
        ScoreRFLMain->setMaxLength(4);
        ScoreRFLMain->setReadOnly(true);
        ScoreDEXMain = new QLineEdit(AttributeGroupBox);
        ScoreDEXMain->setObjectName(QString::fromUtf8("ScoreDEXMain"));
        ScoreDEXMain->setEnabled(false);
        ScoreDEXMain->setGeometry(QRect(80, 209, 31, 20));
        ScoreDEXMain->setMaxLength(4);
        ScoreDEXMain->setReadOnly(true);
        ScoreINTMain = new QLineEdit(AttributeGroupBox);
        ScoreINTMain->setObjectName(QString::fromUtf8("ScoreINTMain"));
        ScoreINTMain->setEnabled(false);
        ScoreINTMain->setGeometry(QRect(80, 239, 31, 20));
        ScoreINTMain->setMaxLength(4);
        ScoreINTMain->setReadOnly(true);
        ScoreWILMain = new QLineEdit(AttributeGroupBox);
        ScoreWILMain->setObjectName(QString::fromUtf8("ScoreWILMain"));
        ScoreWILMain->setEnabled(false);
        ScoreWILMain->setGeometry(QRect(80, 269, 31, 20));
        ScoreWILMain->setMaxLength(4);
        ScoreWILMain->setReadOnly(true);
        ScoreCHAMain = new QLineEdit(AttributeGroupBox);
        ScoreCHAMain->setObjectName(QString::fromUtf8("ScoreCHAMain"));
        ScoreCHAMain->setEnabled(false);
        ScoreCHAMain->setGeometry(QRect(80, 299, 31, 20));
        ScoreCHAMain->setMaxLength(4);
        ScoreCHAMain->setReadOnly(true);
        ScoreEDGMain = new QLineEdit(AttributeGroupBox);
        ScoreEDGMain->setObjectName(QString::fromUtf8("ScoreEDGMain"));
        ScoreEDGMain->setEnabled(false);
        ScoreEDGMain->setGeometry(QRect(80, 329, 31, 20));
        ScoreEDGMain->setMaxLength(4);
        ScoreEDGMain->setReadOnly(true);
        LinkSTRMain = new QLineEdit(AttributeGroupBox);
        LinkSTRMain->setObjectName(QString::fromUtf8("LinkSTRMain"));
        LinkSTRMain->setEnabled(false);
        LinkSTRMain->setGeometry(QRect(120, 119, 31, 20));
        LinkSTRMain->setMaxLength(4);
        LinkSTRMain->setReadOnly(true);
        LinkBODMain = new QLineEdit(AttributeGroupBox);
        LinkBODMain->setObjectName(QString::fromUtf8("LinkBODMain"));
        LinkBODMain->setEnabled(false);
        LinkBODMain->setGeometry(QRect(120, 149, 31, 20));
        LinkBODMain->setMaxLength(4);
        LinkBODMain->setReadOnly(true);
        LinkRFLMain = new QLineEdit(AttributeGroupBox);
        LinkRFLMain->setObjectName(QString::fromUtf8("LinkRFLMain"));
        LinkRFLMain->setEnabled(false);
        LinkRFLMain->setGeometry(QRect(120, 179, 31, 20));
        LinkRFLMain->setMaxLength(4);
        LinkRFLMain->setReadOnly(true);
        LinkDEXMain = new QLineEdit(AttributeGroupBox);
        LinkDEXMain->setObjectName(QString::fromUtf8("LinkDEXMain"));
        LinkDEXMain->setEnabled(false);
        LinkDEXMain->setGeometry(QRect(120, 209, 31, 20));
        LinkDEXMain->setMaxLength(4);
        LinkDEXMain->setReadOnly(true);
        LinkINTMain = new QLineEdit(AttributeGroupBox);
        LinkINTMain->setObjectName(QString::fromUtf8("LinkINTMain"));
        LinkINTMain->setEnabled(false);
        LinkINTMain->setGeometry(QRect(120, 239, 31, 20));
        LinkINTMain->setMaxLength(4);
        LinkINTMain->setReadOnly(true);
        LinkWILMain = new QLineEdit(AttributeGroupBox);
        LinkWILMain->setObjectName(QString::fromUtf8("LinkWILMain"));
        LinkWILMain->setEnabled(false);
        LinkWILMain->setGeometry(QRect(120, 269, 31, 20));
        LinkWILMain->setMaxLength(4);
        LinkWILMain->setReadOnly(true);
        LinkCHAMain = new QLineEdit(AttributeGroupBox);
        LinkCHAMain->setObjectName(QString::fromUtf8("LinkCHAMain"));
        LinkCHAMain->setEnabled(false);
        LinkCHAMain->setGeometry(QRect(120, 299, 31, 20));
        LinkCHAMain->setMaxLength(4);
        LinkCHAMain->setReadOnly(true);
        LinkEDGMain = new QLineEdit(AttributeGroupBox);
        LinkEDGMain->setObjectName(QString::fromUtf8("LinkEDGMain"));
        LinkEDGMain->setEnabled(false);
        LinkEDGMain->setGeometry(QRect(120, 329, 31, 20));
        LinkEDGMain->setMaxLength(4);
        LinkEDGMain->setReadOnly(true);
        label_38 = new QLabel(AttributeGroupBox);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(320, 98, 31, 16));
        label_39 = new QLabel(AttributeGroupBox);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(420, 98, 71, 16));
        preqListTable = new QTableWidget(AttributeGroupBox);
        if (preqListTable->columnCount() < 2)
            preqListTable->setColumnCount(2);
        preqListTable->setObjectName(QString::fromUtf8("preqListTable"));
        preqListTable->setGeometry(QRect(280, 118, 231, 201));
        preqListTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        preqListTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        preqListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        preqListTable->setSelectionMode(QAbstractItemView::SingleSelection);
        preqListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        preqListTable->setShowGrid(false);
        preqListTable->setGridStyle(Qt::NoPen);
        preqListTable->setColumnCount(2);
        preqListTable->horizontalHeader()->setVisible(false);
        preqListTable->horizontalHeader()->setDefaultSectionSize(113);
        preqListTable->verticalHeader()->setVisible(false);
        preqListTable->verticalHeader()->setDefaultSectionSize(16);
        preqListTable->verticalHeader()->setHighlightSections(false);
        line_4 = new QFrame(AttributeGroupBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(290, 80, 201, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_40 = new QLabel(AttributeGroupBox);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(320, 68, 151, 16));
        label_41 = new QLabel(AttributeGroupBox);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(80, 68, 81, 16));
        line_5 = new QFrame(AttributeGroupBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(20, 80, 201, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(AttributeGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 330, 75, 23));
        tabWidget->addTab(AttributeTab, QString());
        SkillsTabswp = new QWidget();
        SkillsTabswp->setObjectName(QString::fromUtf8("SkillsTabswp"));
        TraitsGroupBox = new QGroupBox(SkillsTabswp);
        TraitsGroupBox->setObjectName(QString::fromUtf8("TraitsGroupBox"));
        TraitsGroupBox->setGeometry(QRect(10, 5, 731, 501));
        SkillResetMain = new QPushButton(TraitsGroupBox);
        SkillResetMain->setObjectName(QString::fromUtf8("SkillResetMain"));
        SkillResetMain->setGeometry(QRect(270, 450, 75, 23));
        SkillAddMain = new QPushButton(TraitsGroupBox);
        SkillAddMain->setObjectName(QString::fromUtf8("SkillAddMain"));
        SkillAddMain->setGeometry(QRect(270, 230, 75, 23));
        SkillAllTableMain = new QTableWidget(TraitsGroupBox);
        if (SkillAllTableMain->columnCount() < 2)
            SkillAllTableMain->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        SkillAllTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        SkillAllTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        SkillAllTableMain->setObjectName(QString::fromUtf8("SkillAllTableMain"));
        SkillAllTableMain->setGeometry(QRect(20, 80, 241, 401));
        SkillAllTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SkillAllTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        SkillAllTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        SkillAllTableMain->setGridStyle(Qt::NoPen);
        SkillAllTableMain->setRowCount(0);
        SkillAllTableMain->verticalHeader()->setVisible(false);
        SkillAllTableMain->verticalHeader()->setDefaultSectionSize(15);
        SkillChrTableMain = new QTableWidget(TraitsGroupBox);
        if (SkillChrTableMain->columnCount() < 6)
            SkillChrTableMain->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        SkillChrTableMain->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        SkillChrTableMain->setObjectName(QString::fromUtf8("SkillChrTableMain"));
        SkillChrTableMain->setGeometry(QRect(360, 80, 351, 401));
        SkillChrTableMain->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        SkillChrTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        SkillChrTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        SkillChrTableMain->setShowGrid(false);
        SkillChrTableMain->setGridStyle(Qt::NoPen);
        SkillChrTableMain->setRowCount(0);
        SkillChrTableMain->horizontalHeader()->setCascadingSectionResizes(false);
        SkillChrTableMain->horizontalHeader()->setDefaultSectionSize(100);
        SkillChrTableMain->verticalHeader()->setVisible(false);
        SkillChrTableMain->verticalHeader()->setDefaultSectionSize(15);
        SkillChrTableMain->verticalHeader()->setHighlightSections(true);
        SkillChrTableMain->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        SkillChrTableMain->verticalHeader()->setStretchLastSection(false);
        SkillDelMain = new QPushButton(TraitsGroupBox);
        SkillDelMain->setObjectName(QString::fromUtf8("SkillDelMain"));
        SkillDelMain->setGeometry(QRect(270, 270, 75, 23));
        DeleteSkillMain = new QPushButton(TraitsGroupBox);
        DeleteSkillMain->setObjectName(QString::fromUtf8("DeleteSkillMain"));
        DeleteSkillMain->setGeometry(QRect(270, 310, 75, 23));
        line = new QFrame(TraitsGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(283, 293, 51, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_8 = new QGroupBox(TraitsGroupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(270, 101, 81, 53));
        CountSkillsMain = new QLabel(groupBox_8);
        CountSkillsMain->setObjectName(QString::fromUtf8("CountSkillsMain"));
        CountSkillsMain->setGeometry(QRect(26, 20, 31, 21));
        groupBox_5 = new QGroupBox(SkillsTabswp);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(620, 25, 101, 53));
        statusXPSkillsMain = new QLabel(groupBox_5);
        statusXPSkillsMain->setObjectName(QString::fromUtf8("statusXPSkillsMain"));
        statusXPSkillsMain->setGeometry(QRect(25, 17, 61, 21));
        tabWidget->addTab(SkillsTabswp, QString());
        TraitsTab = new QWidget();
        TraitsTab->setObjectName(QString::fromUtf8("TraitsTab"));
        SkillsGroupBox = new QGroupBox(TraitsTab);
        SkillsGroupBox->setObjectName(QString::fromUtf8("SkillsGroupBox"));
        SkillsGroupBox->setGeometry(QRect(10, 5, 731, 501));
        groupBox_4 = new QGroupBox(SkillsGroupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(610, 20, 101, 53));
        statusXPTraitsMain = new QLabel(groupBox_4);
        statusXPTraitsMain->setObjectName(QString::fromUtf8("statusXPTraitsMain"));
        statusXPTraitsMain->setGeometry(QRect(25, 17, 61, 21));
        TraitAllTableMain = new QTableWidget(SkillsGroupBox);
        if (TraitAllTableMain->columnCount() < 2)
            TraitAllTableMain->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        TraitAllTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        TraitAllTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        TraitAllTableMain->setObjectName(QString::fromUtf8("TraitAllTableMain"));
        TraitAllTableMain->setGeometry(QRect(20, 80, 241, 401));
        TraitAllTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TraitAllTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        TraitAllTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        TraitAllTableMain->setShowGrid(false);
        TraitAllTableMain->setGridStyle(Qt::NoPen);
        TraitAllTableMain->setRowCount(0);
        TraitAllTableMain->verticalHeader()->setVisible(false);
        TraitAllTableMain->verticalHeader()->setDefaultSectionSize(15);
        TraitChrTableMain = new QTableWidget(SkillsGroupBox);
        if (TraitChrTableMain->columnCount() < 4)
            TraitChrTableMain->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        TraitChrTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        TraitChrTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        TraitChrTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        TraitChrTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        TraitChrTableMain->setObjectName(QString::fromUtf8("TraitChrTableMain"));
        TraitChrTableMain->setGeometry(QRect(360, 80, 351, 401));
        TraitChrTableMain->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        TraitChrTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        TraitChrTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        TraitChrTableMain->setShowGrid(false);
        TraitChrTableMain->setGridStyle(Qt::NoPen);
        TraitChrTableMain->setRowCount(0);
        TraitChrTableMain->horizontalHeader()->setCascadingSectionResizes(false);
        TraitChrTableMain->horizontalHeader()->setDefaultSectionSize(100);
        TraitChrTableMain->verticalHeader()->setVisible(false);
        TraitChrTableMain->verticalHeader()->setDefaultSectionSize(15);
        TraitChrTableMain->verticalHeader()->setHighlightSections(true);
        TraitChrTableMain->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        TraitChrTableMain->verticalHeader()->setStretchLastSection(false);
        TraitResetMain = new QPushButton(SkillsGroupBox);
        TraitResetMain->setObjectName(QString::fromUtf8("TraitResetMain"));
        TraitResetMain->setGeometry(QRect(270, 450, 75, 23));
        TraitAddMain = new QPushButton(SkillsGroupBox);
        TraitAddMain->setObjectName(QString::fromUtf8("TraitAddMain"));
        TraitAddMain->setGeometry(QRect(270, 230, 75, 23));
        TraitlDelMain = new QPushButton(SkillsGroupBox);
        TraitlDelMain->setObjectName(QString::fromUtf8("TraitlDelMain"));
        TraitlDelMain->setGeometry(QRect(270, 270, 75, 23));
        DeleteTraitsMain = new QPushButton(SkillsGroupBox);
        DeleteTraitsMain->setObjectName(QString::fromUtf8("DeleteTraitsMain"));
        DeleteTraitsMain->setGeometry(QRect(270, 310, 75, 23));
        line_2 = new QFrame(SkillsGroupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(283, 293, 51, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        groupBox_9 = new QGroupBox(TraitsTab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(280, 106, 81, 53));
        CountTraitsMain = new QLabel(groupBox_9);
        CountTraitsMain->setObjectName(QString::fromUtf8("CountTraitsMain"));
        CountTraitsMain->setGeometry(QRect(26, 20, 31, 21));
        tabWidget->addTab(TraitsTab, QString());
        EquipmentTab = new QWidget();
        EquipmentTab->setObjectName(QString::fromUtf8("EquipmentTab"));
        EquipmentGroupBox = new QGroupBox(EquipmentTab);
        EquipmentGroupBox->setObjectName(QString::fromUtf8("EquipmentGroupBox"));
        EquipmentGroupBox->setGeometry(QRect(10, 5, 731, 501));
        label_31 = new QLabel(EquipmentGroupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(410, 50, 101, 16));
        MassEquipMain = new QLineEdit(EquipmentGroupBox);
        MassEquipMain->setObjectName(QString::fromUtf8("MassEquipMain"));
        MassEquipMain->setEnabled(false);
        MassEquipMain->setGeometry(QRect(520, 50, 51, 20));
        MassEquipMain->setReadOnly(true);
        groupBox_6 = new QGroupBox(EquipmentGroupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(610, 20, 101, 53));
        cbillsEq = new QLabel(groupBox_6);
        cbillsEq->setObjectName(QString::fromUtf8("cbillsEq"));
        cbillsEq->setGeometry(QRect(5, 17, 91, 21));
        TraitResetMain_2 = new QPushButton(EquipmentGroupBox);
        TraitResetMain_2->setObjectName(QString::fromUtf8("TraitResetMain_2"));
        TraitResetMain_2->setGeometry(QRect(340, 450, 51, 23));
        EquipAllTableMain = new QTableWidget(EquipmentGroupBox);
        if (EquipAllTableMain->columnCount() < 4)
            EquipAllTableMain->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        EquipAllTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        EquipAllTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        EquipAllTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        EquipAllTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        EquipAllTableMain->setObjectName(QString::fromUtf8("EquipAllTableMain"));
        EquipAllTableMain->setGeometry(QRect(20, 80, 311, 401));
        EquipAllTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        EquipAllTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        EquipAllTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        EquipAllTableMain->setShowGrid(false);
        EquipAllTableMain->setGridStyle(Qt::NoPen);
        EquipAllTableMain->setRowCount(0);
        EquipAllTableMain->verticalHeader()->setVisible(false);
        EquipAllTableMain->verticalHeader()->setDefaultSectionSize(15);
        TraitAddMain_2 = new QPushButton(EquipmentGroupBox);
        TraitAddMain_2->setObjectName(QString::fromUtf8("TraitAddMain_2"));
        TraitAddMain_2->setGeometry(QRect(340, 220, 51, 23));
        TraitlDelMain_2 = new QPushButton(EquipmentGroupBox);
        TraitlDelMain_2->setObjectName(QString::fromUtf8("TraitlDelMain_2"));
        TraitlDelMain_2->setGeometry(QRect(340, 250, 51, 23));
        EquipChrTableMain = new QTableWidget(EquipmentGroupBox);
        if (EquipChrTableMain->columnCount() < 6)
            EquipChrTableMain->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        EquipChrTableMain->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        EquipChrTableMain->setObjectName(QString::fromUtf8("EquipChrTableMain"));
        EquipChrTableMain->setGeometry(QRect(400, 80, 311, 401));
        EquipChrTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        EquipChrTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        EquipChrTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        EquipChrTableMain->setShowGrid(false);
        EquipChrTableMain->setGridStyle(Qt::NoPen);
        EquipChrTableMain->setRowCount(0);
        EquipChrTableMain->horizontalHeader()->setCascadingSectionResizes(false);
        EquipChrTableMain->horizontalHeader()->setDefaultSectionSize(100);
        EquipChrTableMain->verticalHeader()->setVisible(false);
        EquipChrTableMain->verticalHeader()->setDefaultSectionSize(15);
        EquipChrTableMain->verticalHeader()->setHighlightSections(true);
        EquipChrTableMain->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        EquipChrTableMain->verticalHeader()->setStretchLastSection(false);
        EquipType = new QComboBox(EquipmentGroupBox);
        EquipType->setObjectName(QString::fromUtf8("EquipType"));
        EquipType->setGeometry(QRect(110, 50, 221, 22));
        label_34 = new QLabel(EquipmentGroupBox);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 50, 81, 16));
        tabWidget->addTab(EquipmentTab, QString());
        WeaponsTab = new QWidget();
        WeaponsTab->setObjectName(QString::fromUtf8("WeaponsTab"));
        WeaponsGroupBox = new QGroupBox(WeaponsTab);
        WeaponsGroupBox->setObjectName(QString::fromUtf8("WeaponsGroupBox"));
        WeaponsGroupBox->setGeometry(QRect(10, 5, 731, 501));
        groupBox_7 = new QGroupBox(WeaponsGroupBox);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(610, 20, 101, 53));
        cbillsWp = new QLabel(groupBox_7);
        cbillsWp->setObjectName(QString::fromUtf8("cbillsWp"));
        cbillsWp->setGeometry(QRect(5, 17, 91, 21));
        MassWeaponMain = new QLineEdit(WeaponsGroupBox);
        MassWeaponMain->setObjectName(QString::fromUtf8("MassWeaponMain"));
        MassWeaponMain->setEnabled(false);
        MassWeaponMain->setGeometry(QRect(520, 50, 51, 20));
        MassWeaponMain->setReadOnly(true);
        label_32 = new QLabel(WeaponsGroupBox);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(410, 50, 101, 16));
        WeaponChrTableMain = new QTableWidget(WeaponsGroupBox);
        if (WeaponChrTableMain->columnCount() < 9)
            WeaponChrTableMain->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        WeaponChrTableMain->setHorizontalHeaderItem(8, __qtablewidgetitem32);
        WeaponChrTableMain->setObjectName(QString::fromUtf8("WeaponChrTableMain"));
        WeaponChrTableMain->setGeometry(QRect(20, 300, 691, 181));
        WeaponChrTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        WeaponChrTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        WeaponChrTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        WeaponChrTableMain->setShowGrid(false);
        WeaponChrTableMain->setGridStyle(Qt::NoPen);
        WeaponChrTableMain->setRowCount(0);
        WeaponChrTableMain->horizontalHeader()->setCascadingSectionResizes(false);
        WeaponChrTableMain->horizontalHeader()->setDefaultSectionSize(100);
        WeaponChrTableMain->verticalHeader()->setVisible(false);
        WeaponChrTableMain->verticalHeader()->setDefaultSectionSize(15);
        WeaponChrTableMain->verticalHeader()->setHighlightSections(true);
        WeaponChrTableMain->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        WeaponChrTableMain->verticalHeader()->setStretchLastSection(false);
        WeaponAllTableMain = new QTableWidget(WeaponsGroupBox);
        if (WeaponAllTableMain->columnCount() < 10)
            WeaponAllTableMain->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(4, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(5, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(6, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(7, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(8, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        WeaponAllTableMain->setHorizontalHeaderItem(9, __qtablewidgetitem42);
        WeaponAllTableMain->setObjectName(QString::fromUtf8("WeaponAllTableMain"));
        WeaponAllTableMain->setGeometry(QRect(20, 80, 691, 181));
        WeaponAllTableMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        WeaponAllTableMain->setSelectionMode(QAbstractItemView::SingleSelection);
        WeaponAllTableMain->setSelectionBehavior(QAbstractItemView::SelectRows);
        WeaponAllTableMain->setShowGrid(false);
        WeaponAllTableMain->setGridStyle(Qt::NoPen);
        WeaponAllTableMain->setRowCount(0);
        WeaponAllTableMain->verticalHeader()->setVisible(false);
        WeaponAllTableMain->verticalHeader()->setDefaultSectionSize(15);
        AddAmmoMain = new QPushButton(WeaponsGroupBox);
        AddAmmoMain->setObjectName(QString::fromUtf8("AddAmmoMain"));
        AddAmmoMain->setGeometry(QRect(320, 270, 61, 23));
        WeaponType = new QComboBox(WeaponsGroupBox);
        WeaponType->setObjectName(QString::fromUtf8("WeaponType"));
        WeaponType->setGeometry(QRect(110, 50, 221, 22));
        label_33 = new QLabel(WeaponsGroupBox);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(20, 50, 71, 16));
        tabWidget->addTab(WeaponsTab, QString());
        Inventory = new QWidget();
        Inventory->setObjectName(QString::fromUtf8("Inventory"));
        WeaponsGroupBox_2 = new QGroupBox(Inventory);
        WeaponsGroupBox_2->setObjectName(QString::fromUtf8("WeaponsGroupBox_2"));
        WeaponsGroupBox_2->setGeometry(QRect(10, 5, 731, 501));
        frame = new QFrame(WeaponsGroupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 221, 491));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/img/man.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        HeadListMain = new QListWidget(frame);
        new QListWidgetItem(HeadListMain);
        HeadListMain->setObjectName(QString::fromUtf8("HeadListMain"));
        HeadListMain->setGeometry(QRect(60, 10, 91, 21));
        HeadListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HeadListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HeadListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        HeadListMain->setDragDropMode(QAbstractItemView::DropOnly);
        HeadListMain->setDefaultDropAction(Qt::IgnoreAction);
        BodyListMain = new QListWidget(frame);
        new QListWidgetItem(BodyListMain);
        BodyListMain->setObjectName(QString::fromUtf8("BodyListMain"));
        BodyListMain->setGeometry(QRect(62, 120, 91, 21));
        BodyListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        BodyListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        BodyListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        BodyListMain->setDragDropMode(QAbstractItemView::DropOnly);
        BodyListMain->setDefaultDropAction(Qt::IgnoreAction);
        ArmLeftListMain = new QListWidget(frame);
        new QListWidgetItem(ArmLeftListMain);
        ArmLeftListMain->setObjectName(QString::fromUtf8("ArmLeftListMain"));
        ArmLeftListMain->setGeometry(QRect(0, 170, 71, 21));
        ArmLeftListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ArmLeftListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ArmLeftListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ArmLeftListMain->setDragDropMode(QAbstractItemView::DropOnly);
        ArmLeftListMain->setDefaultDropAction(Qt::IgnoreAction);
        ArmRightListMain = new QListWidget(frame);
        new QListWidgetItem(ArmRightListMain);
        ArmRightListMain->setObjectName(QString::fromUtf8("ArmRightListMain"));
        ArmRightListMain->setGeometry(QRect(148, 170, 71, 21));
        ArmRightListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ArmRightListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ArmRightListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ArmRightListMain->setDragDropMode(QAbstractItemView::DropOnly);
        ArmRightListMain->setDefaultDropAction(Qt::IgnoreAction);
        LegsListMain = new QListWidget(frame);
        new QListWidgetItem(LegsListMain);
        LegsListMain->setObjectName(QString::fromUtf8("LegsListMain"));
        LegsListMain->setGeometry(QRect(63, 240, 91, 21));
        LegsListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LegsListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LegsListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        LegsListMain->setDragDropMode(QAbstractItemView::DropOnly);
        LegsListMain->setDefaultDropAction(Qt::IgnoreAction);
        HandLeftListMain = new QListWidget(frame);
        new QListWidgetItem(HandLeftListMain);
        HandLeftListMain->setObjectName(QString::fromUtf8("HandLeftListMain"));
        HandLeftListMain->setGeometry(QRect(0, 280, 71, 21));
        HandLeftListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HandLeftListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HandLeftListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        HandLeftListMain->setDragDropMode(QAbstractItemView::DropOnly);
        HandLeftListMain->setDefaultDropAction(Qt::IgnoreAction);
        HandRightListMain = new QListWidget(frame);
        new QListWidgetItem(HandRightListMain);
        HandRightListMain->setObjectName(QString::fromUtf8("HandRightListMain"));
        HandRightListMain->setGeometry(QRect(150, 280, 71, 21));
        HandRightListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HandRightListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        HandRightListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        HandRightListMain->setDragDropMode(QAbstractItemView::DropOnly);
        HandRightListMain->setDefaultDropAction(Qt::IgnoreAction);
        FeetsListMain = new QListWidget(frame);
        new QListWidgetItem(FeetsListMain);
        FeetsListMain->setObjectName(QString::fromUtf8("FeetsListMain"));
        FeetsListMain->setGeometry(QRect(60, 460, 91, 21));
        FeetsListMain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        FeetsListMain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        FeetsListMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FeetsListMain->setDragDropMode(QAbstractItemView::DropOnly);
        FeetsListMain->setDefaultDropAction(Qt::IgnoreAction);
        line_3 = new QFrame(WeaponsGroupBox_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(230, 10, 16, 481));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        AllYouTable = new QTableWidget(WeaponsGroupBox_2);
        if (AllYouTable->columnCount() < 6)
            AllYouTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(4, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        AllYouTable->setHorizontalHeaderItem(5, __qtablewidgetitem48);
        AllYouTable->setObjectName(QString::fromUtf8("AllYouTable"));
        AllYouTable->setGeometry(QRect(250, 30, 471, 331));
        AllYouTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        AllYouTable->setDragEnabled(true);
        AllYouTable->setDragDropMode(QAbstractItemView::DragOnly);
        AllYouTable->setDefaultDropAction(Qt::CopyAction);
        AllYouTable->setSelectionMode(QAbstractItemView::SingleSelection);
        AllYouTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        AllYouTable->setShowGrid(false);
        AllYouTable->setGridStyle(Qt::NoPen);
        AllYouTable->verticalHeader()->setVisible(false);
        AllYouTable->verticalHeader()->setDefaultSectionSize(15);
        label_35 = new QLabel(WeaponsGroupBox_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(260, 12, 101, 16));
        label_36 = new QLabel(WeaponsGroupBox_2);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(260, 370, 61, 16));
        ItselfAllYouTable = new QTableWidget(WeaponsGroupBox_2);
        if (ItselfAllYouTable->columnCount() < 5)
            ItselfAllYouTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        ItselfAllYouTable->setHorizontalHeaderItem(0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        ItselfAllYouTable->setHorizontalHeaderItem(1, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        ItselfAllYouTable->setHorizontalHeaderItem(2, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        ItselfAllYouTable->setHorizontalHeaderItem(3, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        ItselfAllYouTable->setHorizontalHeaderItem(4, __qtablewidgetitem53);
        ItselfAllYouTable->setObjectName(QString::fromUtf8("ItselfAllYouTable"));
        ItselfAllYouTable->setGeometry(QRect(250, 390, 471, 101));
        ItselfAllYouTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ItselfAllYouTable->setShowGrid(false);
        ItselfAllYouTable->setGridStyle(Qt::NoPen);
        ItselfAllYouTable->setRowCount(0);
        ItselfAllYouTable->verticalHeader()->setVisible(false);
        ItselfAllYouTable->verticalHeader()->setDefaultSectionSize(15);
        ItselfAllYouTable->verticalHeader()->setMinimumSectionSize(19);
        tabWidget->addTab(Inventory, QString());
        NotesTab = new QWidget();
        NotesTab->setObjectName(QString::fromUtf8("NotesTab"));
        NotesGroupBox = new QGroupBox(NotesTab);
        NotesGroupBox->setObjectName(QString::fromUtf8("NotesGroupBox"));
        NotesGroupBox->setGeometry(QRect(10, 5, 731, 501));
        NotesMain = new QTextEdit(NotesGroupBox);
        NotesMain->setObjectName(QString::fromUtf8("NotesMain"));
        NotesMain->setGeometry(QRect(10, 20, 711, 471));
        tabWidget->addTab(NotesTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 752, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuWizard = new QMenu(menubar);
        menuWizard->setObjectName(QString::fromUtf8("menuWizard"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuWizard->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuWizard->addAction(actionNew_Wizard);
        menuWizard->addSeparator();
        menuWizard->addAction(actionCheck_Wizard);
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        menuTools->addAction(actionAdd_C_Bills);
        menuTools->addSeparator();
        menuTools->addAction(actionPrint_Tables);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BT Character Creator v0.5.18.20101114", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New Character", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open save character", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionNew_Wizard->setText(QApplication::translate("MainWindow", "New Wizard", 0, QApplication::UnicodeUTF8));
        actionNew_Wizard->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionCheck_Wizard->setText(QApplication::translate("MainWindow", "Check Wizard", 0, QApplication::UnicodeUTF8));
        actionCheck_Wizard->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAdd_C_Bills->setText(QApplication::translate("MainWindow", "Character Tools", 0, QApplication::UnicodeUTF8));
        actionAdd_XP->setText(QApplication::translate("MainWindow", "Add XP", 0, QApplication::UnicodeUTF8));
        actionNPC->setText(QApplication::translate("MainWindow", "NPC", 0, QApplication::UnicodeUTF8));
        actionPrint_Tables->setText(QApplication::translate("MainWindow", "Print Tables", 0, QApplication::UnicodeUTF8));
        MainGroupBox->setTitle(QApplication::translate("MainWindow", "Main", 0, QApplication::UnicodeUTF8));
        CharNameMain->setText(QApplication::translate("MainWindow", "Enter Charachter name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Name:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Affialtion:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Phenotype:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Home Planet:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Age:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        SexMain->clear();
        SexMain->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Male", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Female", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Sex:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        HeightMain->setSuffix(QApplication::translate("MainWindow", "cm", 0, QApplication::UnicodeUTF8));
        HeightMain->setPrefix(QString());
        label_7->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Height:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        WeightMain->setSuffix(QApplication::translate("MainWindow", "kg", 0, QApplication::UnicodeUTF8));
        WeightMain->setPrefix(QString());
        label_8->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Weight:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Hair Collor:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Eye Collor:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        CBillsMain->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">C-Bills:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Movement (Meters per Turn)", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Walk:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Run/Evade:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Sprint:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        WalkMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        RunEvadeMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        SprintMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ClimbMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        CrawlMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        SwimMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Climb:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Crawl:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Swim:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        FreeXPMain->setText(QApplication::translate("MainWindow", "5000", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">FreeXP:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Sub Affialtion:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(MainTab), QApplication::translate("MainWindow", "Main", 0, QApplication::UnicodeUTF8));
        AttributeGroupBox->setTitle(QApplication::translate("MainWindow", "Attribute", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Free XP", 0, QApplication::UnicodeUTF8));
        statusXPAttrMain->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">5000</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Attribute</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Score</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Link</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">XP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">EDG:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">CHA:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">WIL:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">INT:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">DEX:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">RFL:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">BOD:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">STR:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ScoreSTRMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreBODMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreRFLMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreDEXMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreINTMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreWILMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreCHAMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ScoreEDGMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkSTRMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkBODMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkRFLMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkDEXMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkINTMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkWILMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkCHAMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        LinkEDGMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Name</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Demand XP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Life Module demand</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Attributes</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Check Wizard", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(AttributeTab), QApplication::translate("MainWindow", "Attribute", 0, QApplication::UnicodeUTF8));
        TraitsGroupBox->setTitle(QApplication::translate("MainWindow", "Skills", 0, QApplication::UnicodeUTF8));
        SkillResetMain->setText(QApplication::translate("MainWindow", "RESET", 0, QApplication::UnicodeUTF8));
        SkillAddMain->setText(QApplication::translate("MainWindow", "ADD ->", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = SkillAllTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Skill", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = SkillAllTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Links", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = SkillChrTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Skill", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = SkillChrTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Links", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = SkillChrTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "TN/C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = SkillChrTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Level", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = SkillChrTableMain->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "XP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = SkillChrTableMain->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        SkillDelMain->setText(QApplication::translate("MainWindow", "<- DEL", 0, QApplication::UnicodeUTF8));
        DeleteSkillMain->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        CountSkillsMain->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">20</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Free XP", 0, QApplication::UnicodeUTF8));
        statusXPSkillsMain->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">5000</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(SkillsTabswp), QApplication::translate("MainWindow", "Skills", 0, QApplication::UnicodeUTF8));
        SkillsGroupBox->setTitle(QApplication::translate("MainWindow", "Traits", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Free XP", 0, QApplication::UnicodeUTF8));
        statusXPTraitsMain->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">5000</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = TraitAllTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Trait", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = TraitAllTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Page Ref.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = TraitChrTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Trait", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = TraitChrTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "TP", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = TraitChrTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Page Ref.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = TraitChrTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "XP", 0, QApplication::UnicodeUTF8));
        TraitResetMain->setText(QApplication::translate("MainWindow", "RESET", 0, QApplication::UnicodeUTF8));
        TraitAddMain->setText(QApplication::translate("MainWindow", "ADD ->", 0, QApplication::UnicodeUTF8));
        TraitlDelMain->setText(QApplication::translate("MainWindow", "<- DEL", 0, QApplication::UnicodeUTF8));
        DeleteTraitsMain->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        CountTraitsMain->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">20</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TraitsTab), QApplication::translate("MainWindow", "Traits", 0, QApplication::UnicodeUTF8));
        EquipmentGroupBox->setTitle(QApplication::translate("MainWindow", "Equipment", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Carrying capacity:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        MassEquipMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "C-Bills", 0, QApplication::UnicodeUTF8));
        cbillsEq->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">1000</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        TraitResetMain_2->setText(QApplication::translate("MainWindow", "RESET", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = EquipAllTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = EquipAllTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "BAR(M/B/E/X)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = EquipAllTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Cost", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = EquipAllTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        TraitAddMain_2->setText(QApplication::translate("MainWindow", "ADD ->", 0, QApplication::UnicodeUTF8));
        TraitlDelMain_2->setText(QApplication::translate("MainWindow", "<- DEL", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = EquipChrTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = EquipChrTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = EquipChrTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "BAR(M/B/E/X)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = EquipChrTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Cost", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = EquipChrTableMain->horizontalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = EquipChrTableMain->horizontalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        EquipType->clear();
        EquipType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ALL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Personal Armor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Combat Armor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "(F)Standart Armor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mechwarrior Kits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Special Combat Kits", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Exotic Armor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Hostile Environment", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Stealth Gear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Non-Combat Attire", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Communications", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Audio/Video/Trideo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Computers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Survellance Gear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Optics", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Remote Sensors", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Power Pack", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Rechargers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Espionage Gear & Security Systems", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Repair & Salvage", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Miscellaneous Gear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medical", 0, QApplication::UnicodeUTF8)
        );
        label_34->setText(QApplication::translate("MainWindow", "Type Equpment:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(EquipmentTab), QApplication::translate("MainWindow", "Equipment", 0, QApplication::UnicodeUTF8));
        WeaponsGroupBox->setTitle(QApplication::translate("MainWindow", "Weapons", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "C-Bills", 0, QApplication::UnicodeUTF8));
        cbillsWp->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">1000</span></p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        MassWeaponMain->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Carrying capacity:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = WeaponChrTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = WeaponChrTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem26 = WeaponChrTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "AP/BD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = WeaponChrTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "Cost", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = WeaponChrTableMain->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Range", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = WeaponChrTableMain->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = WeaponChrTableMain->horizontalHeaderItem(6);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Shots", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = WeaponChrTableMain->horizontalHeaderItem(7);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Skill", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = WeaponChrTableMain->horizontalHeaderItem(8);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = WeaponAllTableMain->horizontalHeaderItem(0);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = WeaponAllTableMain->horizontalHeaderItem(1);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "AP/BD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem35 = WeaponAllTableMain->horizontalHeaderItem(2);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Cost", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = WeaponAllTableMain->horizontalHeaderItem(3);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Range", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = WeaponAllTableMain->horizontalHeaderItem(4);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = WeaponAllTableMain->horizontalHeaderItem(5);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Shots", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = WeaponAllTableMain->horizontalHeaderItem(6);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Ammo cost", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = WeaponAllTableMain->horizontalHeaderItem(7);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Ammo mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = WeaponAllTableMain->horizontalHeaderItem(8);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "Skill", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = WeaponAllTableMain->horizontalHeaderItem(9);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        AddAmmoMain->setText(QApplication::translate("MainWindow", "ADD Ammo", 0, QApplication::UnicodeUTF8));
        WeaponType->clear();
        WeaponType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ALL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Archaic Melee", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Archaic Range", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Modern Melee", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Ballistic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Energy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Flechette", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Gauss", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Gyrojet", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Miscellaneous Ranged", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Machine Gun", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Grenade Launchers & Mortars", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Missile Launchers", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Recoilless Rifles", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Support Energy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Support Gauss", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Standard Explosives", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Demolitions", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Weapons Accessories", 0, QApplication::UnicodeUTF8)
        );
        label_33->setText(QApplication::translate("MainWindow", "Type Weapon:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(WeaponsTab), QApplication::translate("MainWindow", "Weapons", 0, QApplication::UnicodeUTF8));
        WeaponsGroupBox_2->setTitle(QApplication::translate("MainWindow", "Inventory", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = HeadListMain->isSortingEnabled();
        HeadListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = HeadListMain->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Head", 0, QApplication::UnicodeUTF8));
        HeadListMain->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = BodyListMain->isSortingEnabled();
        BodyListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = BodyListMain->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Torso", 0, QApplication::UnicodeUTF8));
        BodyListMain->setSortingEnabled(__sortingEnabled1);


        const bool __sortingEnabled2 = ArmLeftListMain->isSortingEnabled();
        ArmLeftListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = ArmLeftListMain->item(0);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Arm", 0, QApplication::UnicodeUTF8));
        ArmLeftListMain->setSortingEnabled(__sortingEnabled2);


        const bool __sortingEnabled3 = ArmRightListMain->isSortingEnabled();
        ArmRightListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = ArmRightListMain->item(0);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Arm", 0, QApplication::UnicodeUTF8));
        ArmRightListMain->setSortingEnabled(__sortingEnabled3);


        const bool __sortingEnabled4 = LegsListMain->isSortingEnabled();
        LegsListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = LegsListMain->item(0);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Legs", 0, QApplication::UnicodeUTF8));
        LegsListMain->setSortingEnabled(__sortingEnabled4);


        const bool __sortingEnabled5 = HandLeftListMain->isSortingEnabled();
        HandLeftListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = HandLeftListMain->item(0);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Hand", 0, QApplication::UnicodeUTF8));
        HandLeftListMain->setSortingEnabled(__sortingEnabled5);


        const bool __sortingEnabled6 = HandRightListMain->isSortingEnabled();
        HandRightListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem6 = HandRightListMain->item(0);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "Hand", 0, QApplication::UnicodeUTF8));
        HandRightListMain->setSortingEnabled(__sortingEnabled6);


        const bool __sortingEnabled7 = FeetsListMain->isSortingEnabled();
        FeetsListMain->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem7 = FeetsListMain->item(0);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "Feets", 0, QApplication::UnicodeUTF8));
        FeetsListMain->setSortingEnabled(__sortingEnabled7);

        QTableWidgetItem *___qtablewidgetitem43 = AllYouTable->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = AllYouTable->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "BAR or AP/BD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = AllYouTable->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = AllYouTable->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = AllYouTable->horizontalHeaderItem(4);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "Location", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = AllYouTable->horizontalHeaderItem(5);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "You have:", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "Weapons", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = ItselfAllYouTable->horizontalHeaderItem(0);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = ItselfAllYouTable->horizontalHeaderItem(1);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "AP/BD", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = ItselfAllYouTable->horizontalHeaderItem(2);
        ___qtablewidgetitem51->setText(QApplication::translate("MainWindow", "Count", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = ItselfAllYouTable->horizontalHeaderItem(3);
        ___qtablewidgetitem52->setText(QApplication::translate("MainWindow", "Mass", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = ItselfAllYouTable->horizontalHeaderItem(4);
        ___qtablewidgetitem53->setText(QApplication::translate("MainWindow", "Location", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Inventory), QApplication::translate("MainWindow", "Inventory", 0, QApplication::UnicodeUTF8));
        NotesGroupBox->setTitle(QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(NotesTab), QApplication::translate("MainWindow", "Notes", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuWizard->setTitle(QApplication::translate("MainWindow", "Wizard", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuTools->setTitle(QApplication::translate("MainWindow", "GameMaster", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
