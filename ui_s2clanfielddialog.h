/********************************************************************************
** Form generated from reading UI file 's2clanfielddialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S2CLANFIELDDIALOG_H
#define UI_S2CLANFIELDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_S2ClanFieldDialog
{
public:
    QDialogButtonBox *S2CFDButtonBox;
    QComboBox *S2CFDBasicComboBox;
    QComboBox *S2CFDAdvComboBox;
    QGroupBox *groupBox;
    QLabel *S2CFDBasicFreeXP;
    QGroupBox *groupBox_2;
    QLabel *S2CFDBasicRebateXP;
    QTableWidget *S2CFDBasicTable;
    QTableWidget *S2CFDAdvTable;
    QLabel *label;
    QLabel *S2CFDAdvLabel;
    QGroupBox *groupBox_3;
    QLabel *S2CFDAdvRebateXP;
    QGroupBox *groupBox_4;
    QLabel *S2CFDAdvFreeXP;

    void setupUi(QDialog *S2ClanFieldDialog)
    {
        if (S2ClanFieldDialog->objectName().isEmpty())
            S2ClanFieldDialog->setObjectName(QString::fromUtf8("S2ClanFieldDialog"));
        S2ClanFieldDialog->setWindowModality(Qt::ApplicationModal);
        S2ClanFieldDialog->resize(507, 271);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(S2ClanFieldDialog->sizePolicy().hasHeightForWidth());
        S2ClanFieldDialog->setSizePolicy(sizePolicy);
        S2ClanFieldDialog->setMinimumSize(QSize(507, 271));
        S2ClanFieldDialog->setMaximumSize(QSize(507, 271));
        S2CFDButtonBox = new QDialogButtonBox(S2ClanFieldDialog);
        S2CFDButtonBox->setObjectName(QString::fromUtf8("S2CFDButtonBox"));
        S2CFDButtonBox->setGeometry(QRect(330, 230, 161, 32));
        S2CFDButtonBox->setOrientation(Qt::Horizontal);
        S2CFDButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S2CFDBasicComboBox = new QComboBox(S2ClanFieldDialog);
        S2CFDBasicComboBox->setObjectName(QString::fromUtf8("S2CFDBasicComboBox"));
        S2CFDBasicComboBox->setGeometry(QRect(20, 90, 211, 22));
        S2CFDAdvComboBox = new QComboBox(S2ClanFieldDialog);
        S2CFDAdvComboBox->setObjectName(QString::fromUtf8("S2CFDAdvComboBox"));
        S2CFDAdvComboBox->setGeometry(QRect(260, 90, 211, 22));
        groupBox = new QGroupBox(S2ClanFieldDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(140, 10, 101, 51));
        S2CFDBasicFreeXP = new QLabel(groupBox);
        S2CFDBasicFreeXP->setObjectName(QString::fromUtf8("S2CFDBasicFreeXP"));
        S2CFDBasicFreeXP->setGeometry(QRect(30, 19, 51, 21));
        groupBox_2 = new QGroupBox(S2ClanFieldDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 101, 51));
        S2CFDBasicRebateXP = new QLabel(groupBox_2);
        S2CFDBasicRebateXP->setObjectName(QString::fromUtf8("S2CFDBasicRebateXP"));
        S2CFDBasicRebateXP->setGeometry(QRect(30, 19, 51, 21));
        S2CFDBasicTable = new QTableWidget(S2ClanFieldDialog);
        if (S2CFDBasicTable->columnCount() < 2)
            S2CFDBasicTable->setColumnCount(2);
        if (S2CFDBasicTable->rowCount() < 7)
            S2CFDBasicTable->setRowCount(7);
        S2CFDBasicTable->setObjectName(QString::fromUtf8("S2CFDBasicTable"));
        S2CFDBasicTable->setGeometry(QRect(20, 120, 221, 100));
        S2CFDBasicTable->setFrameShape(QFrame::Box);
        S2CFDBasicTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2CFDBasicTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2CFDBasicTable->setAutoScroll(false);
        S2CFDBasicTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S2CFDBasicTable->setSelectionMode(QAbstractItemView::NoSelection);
        S2CFDBasicTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        S2CFDBasicTable->setShowGrid(false);
        S2CFDBasicTable->setGridStyle(Qt::NoPen);
        S2CFDBasicTable->setRowCount(7);
        S2CFDBasicTable->setColumnCount(2);
        S2CFDBasicTable->horizontalHeader()->setVisible(false);
        S2CFDBasicTable->horizontalHeader()->setDefaultSectionSize(185);
        S2CFDBasicTable->horizontalHeader()->setMinimumSectionSize(62);
        S2CFDBasicTable->verticalHeader()->setVisible(false);
        S2CFDBasicTable->verticalHeader()->setDefaultSectionSize(14);
        S2CFDBasicTable->verticalHeader()->setHighlightSections(true);
        S2CFDAdvTable = new QTableWidget(S2ClanFieldDialog);
        if (S2CFDAdvTable->columnCount() < 2)
            S2CFDAdvTable->setColumnCount(2);
        if (S2CFDAdvTable->rowCount() < 7)
            S2CFDAdvTable->setRowCount(7);
        S2CFDAdvTable->setObjectName(QString::fromUtf8("S2CFDAdvTable"));
        S2CFDAdvTable->setGeometry(QRect(260, 120, 221, 100));
        S2CFDAdvTable->setFrameShape(QFrame::Box);
        S2CFDAdvTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2CFDAdvTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2CFDAdvTable->setAutoScroll(false);
        S2CFDAdvTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S2CFDAdvTable->setSelectionMode(QAbstractItemView::NoSelection);
        S2CFDAdvTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        S2CFDAdvTable->setShowGrid(false);
        S2CFDAdvTable->setGridStyle(Qt::NoPen);
        S2CFDAdvTable->setRowCount(7);
        S2CFDAdvTable->setColumnCount(2);
        S2CFDAdvTable->horizontalHeader()->setVisible(false);
        S2CFDAdvTable->horizontalHeader()->setDefaultSectionSize(185);
        S2CFDAdvTable->horizontalHeader()->setMinimumSectionSize(62);
        S2CFDAdvTable->verticalHeader()->setVisible(false);
        S2CFDAdvTable->verticalHeader()->setDefaultSectionSize(14);
        S2CFDAdvTable->verticalHeader()->setHighlightSections(true);
        label = new QLabel(S2ClanFieldDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 70, 111, 16));
        S2CFDAdvLabel = new QLabel(S2ClanFieldDialog);
        S2CFDAdvLabel->setObjectName(QString::fromUtf8("S2CFDAdvLabel"));
        S2CFDAdvLabel->setGeometry(QRect(330, 70, 101, 16));
        groupBox_3 = new QGroupBox(S2ClanFieldDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(260, 10, 101, 51));
        S2CFDAdvRebateXP = new QLabel(groupBox_3);
        S2CFDAdvRebateXP->setObjectName(QString::fromUtf8("S2CFDAdvRebateXP"));
        S2CFDAdvRebateXP->setGeometry(QRect(30, 19, 51, 21));
        groupBox_4 = new QGroupBox(S2ClanFieldDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(380, 10, 101, 51));
        S2CFDAdvFreeXP = new QLabel(groupBox_4);
        S2CFDAdvFreeXP->setObjectName(QString::fromUtf8("S2CFDAdvFreeXP"));
        S2CFDAdvFreeXP->setGeometry(QRect(30, 19, 51, 21));

        retranslateUi(S2ClanFieldDialog);
        QObject::connect(S2CFDButtonBox, SIGNAL(accepted()), S2ClanFieldDialog, SLOT(accept()));
        QObject::connect(S2CFDButtonBox, SIGNAL(rejected()), S2ClanFieldDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S2ClanFieldDialog);
    } // setupUi

    void retranslateUi(QDialog *S2ClanFieldDialog)
    {
        S2ClanFieldDialog->setWindowTitle(QApplication::translate("S2ClanFieldDialog", "Clan Military Skills Field", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("S2ClanFieldDialog", "Free XP", 0, QApplication::UnicodeUTF8));
        S2CFDBasicFreeXP->setText(QApplication::translate("S2ClanFieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("S2ClanFieldDialog", "Rebate XP", 0, QApplication::UnicodeUTF8));
        S2CFDBasicRebateXP->setText(QApplication::translate("S2ClanFieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("S2ClanFieldDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Clan Basic Training</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2CFDAdvLabel->setText(QApplication::translate("S2ClanFieldDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Clan Elemental</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("S2ClanFieldDialog", "Rebate XP", 0, QApplication::UnicodeUTF8));
        S2CFDAdvRebateXP->setText(QApplication::translate("S2ClanFieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("S2ClanFieldDialog", "Free XP", 0, QApplication::UnicodeUTF8));
        S2CFDAdvFreeXP->setText(QApplication::translate("S2ClanFieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S2ClanFieldDialog: public Ui_S2ClanFieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S2CLANFIELDDIALOG_H
