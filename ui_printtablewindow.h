/********************************************************************************
** Form generated from reading UI file 'printtablewindow.ui'
**
** Created: Tue 13. Sep 17:47:51 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTTABLEWINDOW_H
#define UI_PRINTTABLEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PrintTableWindow
{
public:
    QGroupBox *groupBox;
    QCheckBox *CombatTable;
    QCheckBox *DamageTable;
    QCheckBox *ActionsTable;
    QCheckBox *MovementTable;
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *PrintTableWindow)
    {
        if (PrintTableWindow->objectName().isEmpty())
            PrintTableWindow->setObjectName(QString::fromUtf8("PrintTableWindow"));
        PrintTableWindow->setWindowModality(Qt::ApplicationModal);
        PrintTableWindow->resize(367, 119);
        groupBox = new QGroupBox(PrintTableWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 341, 101));
        CombatTable = new QCheckBox(groupBox);
        CombatTable->setObjectName(QString::fromUtf8("CombatTable"));
        CombatTable->setGeometry(QRect(20, 20, 101, 17));
        CombatTable->setChecked(true);
        DamageTable = new QCheckBox(groupBox);
        DamageTable->setObjectName(QString::fromUtf8("DamageTable"));
        DamageTable->setGeometry(QRect(20, 40, 91, 17));
        DamageTable->setChecked(true);
        ActionsTable = new QCheckBox(groupBox);
        ActionsTable->setObjectName(QString::fromUtf8("ActionsTable"));
        ActionsTable->setGeometry(QRect(120, 20, 81, 17));
        ActionsTable->setChecked(true);
        MovementTable = new QCheckBox(groupBox);
        MovementTable->setObjectName(QString::fromUtf8("MovementTable"));
        MovementTable->setGeometry(QRect(120, 40, 91, 17));
        MovementTable->setChecked(true);
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 12, 81, 51));
        buttonBox->setMinimumSize(QSize(81, 51));
        buttonBox->setMaximumSize(QSize(81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 321, 41));
        CombatTable->raise();
        DamageTable->raise();
        ActionsTable->raise();
        MovementTable->raise();
        label->raise();
        buttonBox->raise();

        retranslateUi(PrintTableWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), PrintTableWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PrintTableWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(PrintTableWindow);
    } // setupUi

    void retranslateUi(QDialog *PrintTableWindow)
    {
        PrintTableWindow->setWindowTitle(QApplication::translate("PrintTableWindow", "Gamemaster screen", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PrintTableWindow", "Choose table for print", 0, QApplication::UnicodeUTF8));
        CombatTable->setText(QApplication::translate("PrintTableWindow", "Combat Table", 0, QApplication::UnicodeUTF8));
        DamageTable->setText(QApplication::translate("PrintTableWindow", "Damage table", 0, QApplication::UnicodeUTF8));
        ActionsTable->setText(QApplication::translate("PrintTableWindow", "Actions Table", 0, QApplication::UnicodeUTF8));
        MovementTable->setText(QApplication::translate("PrintTableWindow", "Movment Table", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PrintTableWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">You can free download full &quot;A Time of War Gamemaster Screen&quot;</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\"> </span><a href=\"http://www.classicbattletech.com/index.php?action=products&amp;mode=full&amp;id=355\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">there.</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrintTableWindow: public Ui_PrintTableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTTABLEWINDOW_H
