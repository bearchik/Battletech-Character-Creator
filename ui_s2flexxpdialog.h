/********************************************************************************
** Form generated from reading UI file 's2flexxpdialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S2FLEXXPDIALOG_H
#define UI_S2FLEXXPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_S2FlexXPDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *S2FlexDialComBoxSkills;
    QComboBox *S2FlexDialComBoxTraits;
    QTableWidget *S2FlexDialSkillsTable;
    QTableWidget *S2FlexDialTraitsTable;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox;
    QLabel *S2FlexDialFreeXPLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *S2FlexDialBODLabel;
    QSpinBox *S2FlexDialBODSpinBox;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLabel *S2FlexDialRFLLabel;
    QSpinBox *S2FlexDialRFLSpinBox;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QLabel *S2FlexDialDEXLabel;
    QSpinBox *S2FlexDialDEXSpinBox;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLabel *S2FlexDialINTLabel;
    QSpinBox *S2FlexDialINTSpinBox;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLabel *S2FlexDialWILLabel;
    QSpinBox *S2FlexDialWILSpinBox;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLabel *S2FlexDialCHALabel;
    QSpinBox *S2FlexDialCHASpinBox;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_18;
    QLabel *S2FlexDialEDGLabel;
    QSpinBox *S2FlexDialEDGSpinBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *S2FlexDialSTRLabel;
    QSpinBox *S2FlexDialSTRSpinBox;
    QPushButton *S2FlexDialPushButtonReset;
    QSpinBox *S2FlexDialSpinBoxTraits;
    QSpinBox *S2FlexDialSpinBoxSkills;

    void setupUi(QDialog *S2FlexXPDialog)
    {
        if (S2FlexXPDialog->objectName().isEmpty())
            S2FlexXPDialog->setObjectName(QString::fromUtf8("S2FlexXPDialog"));
        S2FlexXPDialog->setWindowModality(Qt::ApplicationModal);
        S2FlexXPDialog->resize(600, 485);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(S2FlexXPDialog->sizePolicy().hasHeightForWidth());
        S2FlexXPDialog->setSizePolicy(sizePolicy);
        S2FlexXPDialog->setMinimumSize(QSize(600, 485));
        S2FlexXPDialog->setMaximumSize(QSize(600, 485));
        QIcon icon;
        icon.addFile(QString::fromUtf8("ico1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        S2FlexXPDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(S2FlexXPDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(410, 440, 171, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S2FlexDialComBoxSkills = new QComboBox(S2FlexXPDialog);
        S2FlexDialComBoxSkills->setObjectName(QString::fromUtf8("S2FlexDialComBoxSkills"));
        S2FlexDialComBoxSkills->setGeometry(QRect(360, 70, 171, 22));
        S2FlexDialComBoxTraits = new QComboBox(S2FlexXPDialog);
        S2FlexDialComBoxTraits->setObjectName(QString::fromUtf8("S2FlexDialComBoxTraits"));
        S2FlexDialComBoxTraits->setGeometry(QRect(120, 70, 171, 22));
        S2FlexDialSkillsTable = new QTableWidget(S2FlexXPDialog);
        if (S2FlexDialSkillsTable->columnCount() < 2)
            S2FlexDialSkillsTable->setColumnCount(2);
        if (S2FlexDialSkillsTable->rowCount() < 24)
            S2FlexDialSkillsTable->setRowCount(24);
        S2FlexDialSkillsTable->setObjectName(QString::fromUtf8("S2FlexDialSkillsTable"));
        S2FlexDialSkillsTable->setGeometry(QRect(360, 100, 221, 336));
        S2FlexDialSkillsTable->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        S2FlexDialSkillsTable->setFont(font);
        S2FlexDialSkillsTable->setFrameShape(QFrame::Box);
        S2FlexDialSkillsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2FlexDialSkillsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2FlexDialSkillsTable->setAutoScroll(false);
        S2FlexDialSkillsTable->setAutoScrollMargin(0);
        S2FlexDialSkillsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S2FlexDialSkillsTable->setTabKeyNavigation(false);
        S2FlexDialSkillsTable->setProperty("showDropIndicator", QVariant(false));
        S2FlexDialSkillsTable->setDragDropOverwriteMode(false);
        S2FlexDialSkillsTable->setAlternatingRowColors(false);
        S2FlexDialSkillsTable->setSelectionMode(QAbstractItemView::NoSelection);
        S2FlexDialSkillsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        S2FlexDialSkillsTable->setShowGrid(false);
        S2FlexDialSkillsTable->setGridStyle(Qt::NoPen);
        S2FlexDialSkillsTable->setSortingEnabled(false);
        S2FlexDialSkillsTable->setWordWrap(false);
        S2FlexDialSkillsTable->setCornerButtonEnabled(false);
        S2FlexDialSkillsTable->setRowCount(24);
        S2FlexDialSkillsTable->setColumnCount(2);
        S2FlexDialSkillsTable->horizontalHeader()->setVisible(false);
        S2FlexDialSkillsTable->horizontalHeader()->setCascadingSectionResizes(true);
        S2FlexDialSkillsTable->horizontalHeader()->setDefaultSectionSize(195);
        S2FlexDialSkillsTable->horizontalHeader()->setMinimumSectionSize(62);
        S2FlexDialSkillsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        S2FlexDialSkillsTable->horizontalHeader()->setStretchLastSection(true);
        S2FlexDialSkillsTable->verticalHeader()->setVisible(false);
        S2FlexDialSkillsTable->verticalHeader()->setCascadingSectionResizes(true);
        S2FlexDialSkillsTable->verticalHeader()->setDefaultSectionSize(14);
        S2FlexDialSkillsTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        S2FlexDialSkillsTable->verticalHeader()->setStretchLastSection(false);
        S2FlexDialTraitsTable = new QTableWidget(S2FlexXPDialog);
        if (S2FlexDialTraitsTable->columnCount() < 2)
            S2FlexDialTraitsTable->setColumnCount(2);
        if (S2FlexDialTraitsTable->rowCount() < 24)
            S2FlexDialTraitsTable->setRowCount(24);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S2FlexDialTraitsTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S2FlexDialTraitsTable->setItem(0, 1, __qtablewidgetitem1);
        S2FlexDialTraitsTable->setObjectName(QString::fromUtf8("S2FlexDialTraitsTable"));
        S2FlexDialTraitsTable->setGeometry(QRect(120, 100, 221, 336));
        S2FlexDialTraitsTable->setBaseSize(QSize(0, 0));
        S2FlexDialTraitsTable->setFont(font);
        S2FlexDialTraitsTable->setFrameShape(QFrame::Box);
        S2FlexDialTraitsTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2FlexDialTraitsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2FlexDialTraitsTable->setAutoScroll(false);
        S2FlexDialTraitsTable->setAutoScrollMargin(0);
        S2FlexDialTraitsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S2FlexDialTraitsTable->setTabKeyNavigation(false);
        S2FlexDialTraitsTable->setProperty("showDropIndicator", QVariant(false));
        S2FlexDialTraitsTable->setDragDropOverwriteMode(false);
        S2FlexDialTraitsTable->setAlternatingRowColors(false);
        S2FlexDialTraitsTable->setSelectionMode(QAbstractItemView::NoSelection);
        S2FlexDialTraitsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        S2FlexDialTraitsTable->setShowGrid(false);
        S2FlexDialTraitsTable->setGridStyle(Qt::NoPen);
        S2FlexDialTraitsTable->setSortingEnabled(false);
        S2FlexDialTraitsTable->setWordWrap(false);
        S2FlexDialTraitsTable->setCornerButtonEnabled(false);
        S2FlexDialTraitsTable->setRowCount(24);
        S2FlexDialTraitsTable->setColumnCount(2);
        S2FlexDialTraitsTable->horizontalHeader()->setVisible(false);
        S2FlexDialTraitsTable->horizontalHeader()->setCascadingSectionResizes(true);
        S2FlexDialTraitsTable->horizontalHeader()->setDefaultSectionSize(185);
        S2FlexDialTraitsTable->horizontalHeader()->setMinimumSectionSize(62);
        S2FlexDialTraitsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        S2FlexDialTraitsTable->horizontalHeader()->setStretchLastSection(true);
        S2FlexDialTraitsTable->verticalHeader()->setVisible(false);
        S2FlexDialTraitsTable->verticalHeader()->setCascadingSectionResizes(true);
        S2FlexDialTraitsTable->verticalHeader()->setDefaultSectionSize(14);
        S2FlexDialTraitsTable->verticalHeader()->setMinimumSectionSize(17);
        S2FlexDialTraitsTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        S2FlexDialTraitsTable->verticalHeader()->setStretchLastSection(false);
        label = new QLabel(S2FlexXPDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 50, 46, 13));
        label_2 = new QLabel(S2FlexXPDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 50, 46, 13));
        groupBox = new QGroupBox(S2FlexXPDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(270, 0, 101, 51));
        S2FlexDialFreeXPLabel = new QLabel(groupBox);
        S2FlexDialFreeXPLabel->setObjectName(QString::fromUtf8("S2FlexDialFreeXPLabel"));
        S2FlexDialFreeXPLabel->setGeometry(QRect(30, 19, 51, 21));
        layoutWidget = new QWidget(S2FlexXPDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 104, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        S2FlexDialBODLabel = new QLabel(layoutWidget);
        S2FlexDialBODLabel->setObjectName(QString::fromUtf8("S2FlexDialBODLabel"));

        horizontalLayout_2->addWidget(S2FlexDialBODLabel);

        S2FlexDialBODSpinBox = new QSpinBox(layoutWidget);
        S2FlexDialBODSpinBox->setObjectName(QString::fromUtf8("S2FlexDialBODSpinBox"));
        S2FlexDialBODSpinBox->setAccelerated(true);
        S2FlexDialBODSpinBox->setMaximum(200);

        horizontalLayout_2->addWidget(S2FlexDialBODSpinBox);

        layoutWidget_2 = new QWidget(S2FlexXPDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 160, 103, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        S2FlexDialRFLLabel = new QLabel(layoutWidget_2);
        S2FlexDialRFLLabel->setObjectName(QString::fromUtf8("S2FlexDialRFLLabel"));

        horizontalLayout_3->addWidget(S2FlexDialRFLLabel);

        S2FlexDialRFLSpinBox = new QSpinBox(layoutWidget_2);
        S2FlexDialRFLSpinBox->setObjectName(QString::fromUtf8("S2FlexDialRFLSpinBox"));
        S2FlexDialRFLSpinBox->setAccelerated(true);
        S2FlexDialRFLSpinBox->setMaximum(200);

        horizontalLayout_3->addWidget(S2FlexDialRFLSpinBox);

        layoutWidget_3 = new QWidget(S2FlexXPDialog);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 190, 103, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        S2FlexDialDEXLabel = new QLabel(layoutWidget_3);
        S2FlexDialDEXLabel->setObjectName(QString::fromUtf8("S2FlexDialDEXLabel"));

        horizontalLayout_4->addWidget(S2FlexDialDEXLabel);

        S2FlexDialDEXSpinBox = new QSpinBox(layoutWidget_3);
        S2FlexDialDEXSpinBox->setObjectName(QString::fromUtf8("S2FlexDialDEXSpinBox"));
        S2FlexDialDEXSpinBox->setAccelerated(true);
        S2FlexDialDEXSpinBox->setMaximum(200);

        horizontalLayout_4->addWidget(S2FlexDialDEXSpinBox);

        layoutWidget_4 = new QWidget(S2FlexXPDialog);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 220, 103, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);

        S2FlexDialINTLabel = new QLabel(layoutWidget_4);
        S2FlexDialINTLabel->setObjectName(QString::fromUtf8("S2FlexDialINTLabel"));

        horizontalLayout_5->addWidget(S2FlexDialINTLabel);

        S2FlexDialINTSpinBox = new QSpinBox(layoutWidget_4);
        S2FlexDialINTSpinBox->setObjectName(QString::fromUtf8("S2FlexDialINTSpinBox"));
        S2FlexDialINTSpinBox->setAccelerated(true);
        S2FlexDialINTSpinBox->setMaximum(200);

        horizontalLayout_5->addWidget(S2FlexDialINTSpinBox);

        layoutWidget_5 = new QWidget(S2FlexXPDialog);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 250, 103, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_6->addWidget(label_14);

        S2FlexDialWILLabel = new QLabel(layoutWidget_5);
        S2FlexDialWILLabel->setObjectName(QString::fromUtf8("S2FlexDialWILLabel"));

        horizontalLayout_6->addWidget(S2FlexDialWILLabel);

        S2FlexDialWILSpinBox = new QSpinBox(layoutWidget_5);
        S2FlexDialWILSpinBox->setObjectName(QString::fromUtf8("S2FlexDialWILSpinBox"));
        S2FlexDialWILSpinBox->setAccelerated(true);
        S2FlexDialWILSpinBox->setMaximum(200);

        horizontalLayout_6->addWidget(S2FlexDialWILSpinBox);

        layoutWidget_6 = new QWidget(S2FlexXPDialog);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 280, 104, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_7->addWidget(label_16);

        S2FlexDialCHALabel = new QLabel(layoutWidget_6);
        S2FlexDialCHALabel->setObjectName(QString::fromUtf8("S2FlexDialCHALabel"));

        horizontalLayout_7->addWidget(S2FlexDialCHALabel);

        S2FlexDialCHASpinBox = new QSpinBox(layoutWidget_6);
        S2FlexDialCHASpinBox->setObjectName(QString::fromUtf8("S2FlexDialCHASpinBox"));
        S2FlexDialCHASpinBox->setAccelerated(true);
        S2FlexDialCHASpinBox->setMaximum(200);

        horizontalLayout_7->addWidget(S2FlexDialCHASpinBox);

        layoutWidget_7 = new QWidget(S2FlexXPDialog);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 310, 103, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_8->addWidget(label_18);

        S2FlexDialEDGLabel = new QLabel(layoutWidget_7);
        S2FlexDialEDGLabel->setObjectName(QString::fromUtf8("S2FlexDialEDGLabel"));

        horizontalLayout_8->addWidget(S2FlexDialEDGLabel);

        S2FlexDialEDGSpinBox = new QSpinBox(layoutWidget_7);
        S2FlexDialEDGSpinBox->setObjectName(QString::fromUtf8("S2FlexDialEDGSpinBox"));
        S2FlexDialEDGSpinBox->setAccelerated(true);
        S2FlexDialEDGSpinBox->setMaximum(200);

        horizontalLayout_8->addWidget(S2FlexDialEDGSpinBox);

        layoutWidget1 = new QWidget(S2FlexXPDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 100, 103, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        S2FlexDialSTRLabel = new QLabel(layoutWidget1);
        S2FlexDialSTRLabel->setObjectName(QString::fromUtf8("S2FlexDialSTRLabel"));

        horizontalLayout->addWidget(S2FlexDialSTRLabel);

        S2FlexDialSTRSpinBox = new QSpinBox(layoutWidget1);
        S2FlexDialSTRSpinBox->setObjectName(QString::fromUtf8("S2FlexDialSTRSpinBox"));
        S2FlexDialSTRSpinBox->setAccelerated(true);
        S2FlexDialSTRSpinBox->setMaximum(200);

        horizontalLayout->addWidget(S2FlexDialSTRSpinBox);

        S2FlexDialPushButtonReset = new QPushButton(S2FlexXPDialog);
        S2FlexDialPushButtonReset->setObjectName(QString::fromUtf8("S2FlexDialPushButtonReset"));
        S2FlexDialPushButtonReset->setGeometry(QRect(20, 450, 75, 23));
        S2FlexDialSpinBoxTraits = new QSpinBox(S2FlexXPDialog);
        S2FlexDialSpinBoxTraits->setObjectName(QString::fromUtf8("S2FlexDialSpinBoxTraits"));
        S2FlexDialSpinBoxTraits->setGeometry(QRect(300, 70, 42, 22));
        S2FlexDialSpinBoxTraits->setAccelerated(true);
        S2FlexDialSpinBoxTraits->setKeyboardTracking(true);
        S2FlexDialSpinBoxTraits->setMaximum(200);
        S2FlexDialSpinBoxSkills = new QSpinBox(S2FlexXPDialog);
        S2FlexDialSpinBoxSkills->setObjectName(QString::fromUtf8("S2FlexDialSpinBoxSkills"));
        S2FlexDialSpinBoxSkills->setGeometry(QRect(540, 70, 42, 22));
        S2FlexDialSpinBoxSkills->setAccelerated(true);
        S2FlexDialSpinBoxSkills->setMaximum(35);

        retranslateUi(S2FlexXPDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), S2FlexXPDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), S2FlexXPDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S2FlexXPDialog);
    } // setupUi

    void retranslateUi(QDialog *S2FlexXPDialog)
    {
        S2FlexXPDialog->setWindowTitle(QApplication::translate("S2FlexXPDialog", "Flexible XP Stage2", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S2FlexDialTraitsTable->isSortingEnabled();
        S2FlexDialTraitsTable->setSortingEnabled(false);
        S2FlexDialTraitsTable->setSortingEnabled(__sortingEnabled);

#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("S2FlexXPDialog", "A character's Traits define special-purpose characteristics and\n"
"abilities beyond the more quantifi able Attributes and Skills. Traits \n"
"can  aff ect  game  play  in  a  variety  of  ways,  from  a  special  rule \n"
"applicable to limited circumstances to a personal detail signifi cant \n"
"enough for its own plot hook.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label->setWhatsThis(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">A character's Traits define special-purpose</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">characteristics and abilities beyond the more</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">quantifiable Attributes and Skills. Traits </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0"
                        "px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">can  aff ect  game  play  in  a  variety  of  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">ways,  from  a  special  rule applicable to </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">limited circumstances to a personal detail </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">significant enough for its own plot hook.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Traits</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("S2FlexXPDialog", "A character\342\200\231s Skills list represents abilities he has been trained \n"
"to use eff ectively. In a typical A Time of War role-playing session, \n"
"characters generally use Skill Action Checks to resolve actions far \n"
"more often than they use Attributes or Traits.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">A character\342\200\231s Skills list represents abilities </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">he has been trained to use eff ectively. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">In a typical A Time of War role-playing </span></p>\n"
"<p style=\" margin-top:0px; margin-"
                        "bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">session, characters generally use Skill Action </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Checks to resolve actions far more often </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">than they use Attributes or Traits.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("S2FlexXPDialog", "FreeXP", 0, QApplication::UnicodeUTF8));
        S2FlexDialFreeXPLabel->setText(QApplication::translate("S2FlexXPDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">BOD:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialBODLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">RFL:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialRFLLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">DEX:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialDEXLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">INT:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialINTLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">WIL:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialWILLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">CHA:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialCHALabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">EDG:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialEDGLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("S2FlexXPDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">STR:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2FlexDialSTRLabel->setText(QApplication::translate("S2FlexXPDialog", "600", 0, QApplication::UnicodeUTF8));
        S2FlexDialPushButtonReset->setText(QApplication::translate("S2FlexXPDialog", "Reset", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S2FlexXPDialog: public Ui_S2FlexXPDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S2FLEXXPDIALOG_H
