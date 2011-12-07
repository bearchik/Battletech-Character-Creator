/********************************************************************************
** Form generated from reading UI file 'subskillpanel.ui'
**
** Created: Tue 6. Sep 16:16:20 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSKILLPANEL_H
#define UI_SUBSKILLPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SubSkillPanel
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QGroupBox *groupBox;

    void setupUi(QDialog *SubSkillPanel)
    {
        if (SubSkillPanel->objectName().isEmpty())
            SubSkillPanel->setObjectName(QString::fromUtf8("SubSkillPanel"));
        SubSkillPanel->setWindowModality(Qt::ApplicationModal);
        SubSkillPanel->resize(254, 97);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(254);
        sizePolicy.setVerticalStretch(97);
        sizePolicy.setHeightForWidth(SubSkillPanel->sizePolicy().hasHeightForWidth());
        SubSkillPanel->setSizePolicy(sizePolicy);
        SubSkillPanel->setMaximumSize(QSize(254, 97));
        buttonBox = new QDialogButtonBox(SubSkillPanel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 57, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(SubSkillPanel);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 221, 22));
        groupBox = new QGroupBox(SubSkillPanel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 9, 241, 81));
        groupBox->raise();
        buttonBox->raise();
        comboBox->raise();

        retranslateUi(SubSkillPanel);
        QObject::connect(buttonBox, SIGNAL(accepted()), SubSkillPanel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SubSkillPanel, SLOT(reject()));

        QMetaObject::connectSlotsByName(SubSkillPanel);
    } // setupUi

    void retranslateUi(QDialog *SubSkillPanel)
    {
        SubSkillPanel->setWindowTitle(QApplication::translate("SubSkillPanel", "Schoose Sub Skill", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SubSkillPanel", "Sub Skill", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SubSkillPanel: public Ui_SubSkillPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSKILLPANEL_H
