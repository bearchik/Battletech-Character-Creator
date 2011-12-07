/********************************************************************************
** Form generated from reading UI file 'gmchartools.ui'
**
** Created: Tue 6. Sep 16:14:34 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GMCHARTOOLS_H
#define UI_GMCHARTOOLS_H

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
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_GMCharTools
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLineEdit *FromMoneyAddGm;
    QComboBox *FromValuteGm;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ToMoneyAddGm;
    QComboBox *ToValuteGm;
    QGroupBox *groupBox_2;
    QLineEdit *XPAddGM;

    void setupUi(QDialog *GMCharTools)
    {
        if (GMCharTools->objectName().isEmpty())
            GMCharTools->setObjectName(QString::fromUtf8("GMCharTools"));
        GMCharTools->setWindowModality(Qt::ApplicationModal);
        GMCharTools->resize(232, 226);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(232);
        sizePolicy.setVerticalStretch(226);
        sizePolicy.setHeightForWidth(GMCharTools->sizePolicy().hasHeightForWidth());
        GMCharTools->setSizePolicy(sizePolicy);
        GMCharTools->setMinimumSize(QSize(232, 226));
        GMCharTools->setMaximumSize(QSize(232, 226));
        buttonBox = new QDialogButtonBox(GMCharTools);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(60, 190, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(GMCharTools);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 211, 111));
        FromMoneyAddGm = new QLineEdit(groupBox);
        FromMoneyAddGm->setObjectName(QString::fromUtf8("FromMoneyAddGm"));
        FromMoneyAddGm->setEnabled(true);
        FromMoneyAddGm->setGeometry(QRect(130, 40, 71, 20));
        FromMoneyAddGm->setMaxLength(9);
        FromValuteGm = new QComboBox(groupBox);
        FromValuteGm->setObjectName(QString::fromUtf8("FromValuteGm"));
        FromValuteGm->setEnabled(false);
        FromValuteGm->setGeometry(QRect(10, 40, 111, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 22, 31, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 63, 31, 16));
        ToMoneyAddGm = new QLineEdit(groupBox);
        ToMoneyAddGm->setObjectName(QString::fromUtf8("ToMoneyAddGm"));
        ToMoneyAddGm->setEnabled(false);
        ToMoneyAddGm->setGeometry(QRect(130, 81, 71, 20));
        ToMoneyAddGm->setMaxLength(9);
        ToValuteGm = new QComboBox(groupBox);
        ToValuteGm->setObjectName(QString::fromUtf8("ToValuteGm"));
        ToValuteGm->setEnabled(false);
        ToValuteGm->setGeometry(QRect(10, 81, 111, 22));
        groupBox_2 = new QGroupBox(GMCharTools);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 211, 61));
        XPAddGM = new QLineEdit(groupBox_2);
        XPAddGM->setObjectName(QString::fromUtf8("XPAddGM"));
        XPAddGM->setGeometry(QRect(10, 30, 191, 20));
        XPAddGM->setMaxLength(10);

        retranslateUi(GMCharTools);
        QObject::connect(buttonBox, SIGNAL(accepted()), GMCharTools, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GMCharTools, SLOT(reject()));

        QMetaObject::connectSlotsByName(GMCharTools);
    } // setupUi

    void retranslateUi(QDialog *GMCharTools)
    {
        GMCharTools->setWindowTitle(QApplication::translate("GMCharTools", "GameMaster Tools", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GMCharTools", "Add money", 0, QApplication::UnicodeUTF8));
        FromMoneyAddGm->setText(QApplication::translate("GMCharTools", "0", 0, QApplication::UnicodeUTF8));
        FromValuteGm->clear();
        FromValuteGm->insertItems(0, QStringList()
         << QApplication::translate("GMCharTools", "C-bill", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Yuan (L-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Kroner (S-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Pound (D-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Ryu (K-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Eagle (M-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Krona (R-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Kerensky", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Taurian Bull", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Calderon Bull", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Canopian Dollar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Fronc Dollar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Escudo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Talent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Skull", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("GMCharTools", "From", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GMCharTools", "To", 0, QApplication::UnicodeUTF8));
        ToMoneyAddGm->setText(QApplication::translate("GMCharTools", "0", 0, QApplication::UnicodeUTF8));
        ToValuteGm->clear();
        ToValuteGm->insertItems(0, QStringList()
         << QApplication::translate("GMCharTools", "C-bill", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Yuan (L-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Kroner (S-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Pound (D-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Ryu (K-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Eagle (M-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Krona (R-bill)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Kerensky", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Taurian Bull", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Calderon Bull", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Canopian Dollar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Fronc Dollar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Escudo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Talent", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GMCharTools", "Skull", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("GMCharTools", "Add XP", 0, QApplication::UnicodeUTF8));
        XPAddGM->setText(QApplication::translate("GMCharTools", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GMCharTools: public Ui_GMCharTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GMCHARTOOLS_H
