/********************************************************************************
** Form generated from reading UI file 's4advdial.ui'
**
** Created: Wed 14. Sep 16:02:45 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S4ADVDIAL_H
#define UI_S4ADVDIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_S4AdvDial
{
public:
    QDialogButtonBox *S4ButtonBox;
    QLabel *S4AdvDialLabel1;
    QLabel *S4AdvDialLabel4;
    QComboBox *S4AdvDialComBox4;
    QTableWidget *S4AdvDialTable;
    QComboBox *S4AdvDialComBox2;
    QComboBox *S4AdvDialComBox1;
    QComboBox *S4AdvDialComBox3;
    QLabel *S4AdvDialLabel3;
    QLabel *S4AdvDialLabel2;
    QComboBox *S4AdvDialComBox7;
    QComboBox *S4AdvDialComBox6;
    QLabel *S4AdvDialLabel7;
    QLabel *S4AdvDialLabel5;
    QLabel *S4AdvDialLabel6;
    QComboBox *S4AdvDialComBox5;
    QPushButton *S4AdvDialAddElem7;
    QPushButton *S4AdvDialAddElem6;
    QPushButton *S4AdvDialAddElem5;
    QComboBox *S4AdvDialComBox8;
    QLabel *S4AdvDialLabel8;

    void setupUi(QDialog *S4AdvDial)
    {
        if (S4AdvDial->objectName().isEmpty())
            S4AdvDial->setObjectName(QString::fromUtf8("S4AdvDial"));
        S4AdvDial->setWindowModality(Qt::ApplicationModal);
        S4AdvDial->resize(442, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(S4AdvDial->sizePolicy().hasHeightForWidth());
        S4AdvDial->setSizePolicy(sizePolicy);
        S4AdvDial->setMinimumSize(QSize(442, 450));
        S4AdvDial->setMaximumSize(QSize(442, 450));
        S4ButtonBox = new QDialogButtonBox(S4AdvDial);
        S4ButtonBox->setObjectName(QString::fromUtf8("S4ButtonBox"));
        S4ButtonBox->setGeometry(QRect(250, 410, 181, 32));
        S4ButtonBox->setOrientation(Qt::Horizontal);
        S4ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S4AdvDialLabel1 = new QLabel(S4AdvDial);
        S4AdvDialLabel1->setObjectName(QString::fromUtf8("S4AdvDialLabel1"));
        S4AdvDialLabel1->setGeometry(QRect(10, 13, 191, 16));
        S4AdvDialLabel4 = new QLabel(S4AdvDial);
        S4AdvDialLabel4->setObjectName(QString::fromUtf8("S4AdvDialLabel4"));
        S4AdvDialLabel4->setGeometry(QRect(10, 126, 191, 16));
        S4AdvDialComBox4 = new QComboBox(S4AdvDial);
        S4AdvDialComBox4->setObjectName(QString::fromUtf8("S4AdvDialComBox4"));
        S4AdvDialComBox4->setEnabled(false);
        S4AdvDialComBox4->setGeometry(QRect(10, 143, 191, 22));
        S4AdvDialTable = new QTableWidget(S4AdvDial);
        if (S4AdvDialTable->columnCount() < 2)
            S4AdvDialTable->setColumnCount(2);
        if (S4AdvDialTable->rowCount() < 17)
            S4AdvDialTable->setRowCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S4AdvDialTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S4AdvDialTable->setItem(0, 1, __qtablewidgetitem1);
        S4AdvDialTable->setObjectName(QString::fromUtf8("S4AdvDialTable"));
        S4AdvDialTable->setGeometry(QRect(240, 30, 191, 376));
        S4AdvDialTable->setFrameShape(QFrame::Box);
        S4AdvDialTable->setFrameShadow(QFrame::Sunken);
        S4AdvDialTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S4AdvDialTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S4AdvDialTable->setAutoScroll(false);
        S4AdvDialTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S4AdvDialTable->setTabKeyNavigation(false);
        S4AdvDialTable->setProperty("showDropIndicator", QVariant(false));
        S4AdvDialTable->setDragDropOverwriteMode(false);
        S4AdvDialTable->setSelectionMode(QAbstractItemView::NoSelection);
        S4AdvDialTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        S4AdvDialTable->setShowGrid(false);
        S4AdvDialTable->setGridStyle(Qt::NoPen);
        S4AdvDialTable->setWordWrap(false);
        S4AdvDialTable->setCornerButtonEnabled(false);
        S4AdvDialTable->setRowCount(17);
        S4AdvDialTable->setColumnCount(2);
        S4AdvDialTable->horizontalHeader()->setVisible(false);
        S4AdvDialTable->horizontalHeader()->setDefaultSectionSize(161);
        S4AdvDialTable->horizontalHeader()->setHighlightSections(true);
        S4AdvDialTable->horizontalHeader()->setMinimumSectionSize(25);
        S4AdvDialTable->verticalHeader()->setVisible(false);
        S4AdvDialTable->verticalHeader()->setDefaultSectionSize(22);
        S4AdvDialTable->verticalHeader()->setHighlightSections(false);
        S4AdvDialTable->verticalHeader()->setMinimumSectionSize(29);
        S4AdvDialComBox2 = new QComboBox(S4AdvDial);
        S4AdvDialComBox2->setObjectName(QString::fromUtf8("S4AdvDialComBox2"));
        S4AdvDialComBox2->setEnabled(false);
        S4AdvDialComBox2->setGeometry(QRect(10, 65, 191, 22));
        S4AdvDialComBox1 = new QComboBox(S4AdvDial);
        S4AdvDialComBox1->setObjectName(QString::fromUtf8("S4AdvDialComBox1"));
        S4AdvDialComBox1->setEnabled(false);
        S4AdvDialComBox1->setGeometry(QRect(10, 29, 191, 22));
        S4AdvDialComBox3 = new QComboBox(S4AdvDial);
        S4AdvDialComBox3->setObjectName(QString::fromUtf8("S4AdvDialComBox3"));
        S4AdvDialComBox3->setEnabled(false);
        S4AdvDialComBox3->setGeometry(QRect(10, 103, 191, 22));
        S4AdvDialLabel3 = new QLabel(S4AdvDial);
        S4AdvDialLabel3->setObjectName(QString::fromUtf8("S4AdvDialLabel3"));
        S4AdvDialLabel3->setGeometry(QRect(10, 87, 191, 16));
        S4AdvDialLabel2 = new QLabel(S4AdvDial);
        S4AdvDialLabel2->setObjectName(QString::fromUtf8("S4AdvDialLabel2"));
        S4AdvDialLabel2->setGeometry(QRect(10, 50, 191, 16));
        S4AdvDialComBox7 = new QComboBox(S4AdvDial);
        S4AdvDialComBox7->setObjectName(QString::fromUtf8("S4AdvDialComBox7"));
        S4AdvDialComBox7->setEnabled(false);
        S4AdvDialComBox7->setGeometry(QRect(10, 308, 191, 22));
        S4AdvDialComBox6 = new QComboBox(S4AdvDial);
        S4AdvDialComBox6->setObjectName(QString::fromUtf8("S4AdvDialComBox6"));
        S4AdvDialComBox6->setEnabled(false);
        S4AdvDialComBox6->setGeometry(QRect(10, 268, 191, 22));
        S4AdvDialLabel7 = new QLabel(S4AdvDial);
        S4AdvDialLabel7->setObjectName(QString::fromUtf8("S4AdvDialLabel7"));
        S4AdvDialLabel7->setGeometry(QRect(10, 291, 191, 16));
        S4AdvDialLabel5 = new QLabel(S4AdvDial);
        S4AdvDialLabel5->setObjectName(QString::fromUtf8("S4AdvDialLabel5"));
        S4AdvDialLabel5->setGeometry(QRect(10, 215, 191, 16));
        S4AdvDialLabel6 = new QLabel(S4AdvDial);
        S4AdvDialLabel6->setObjectName(QString::fromUtf8("S4AdvDialLabel6"));
        S4AdvDialLabel6->setGeometry(QRect(10, 252, 191, 16));
        S4AdvDialComBox5 = new QComboBox(S4AdvDial);
        S4AdvDialComBox5->setObjectName(QString::fromUtf8("S4AdvDialComBox5"));
        S4AdvDialComBox5->setEnabled(false);
        S4AdvDialComBox5->setGeometry(QRect(10, 230, 191, 22));
        S4AdvDialAddElem7 = new QPushButton(S4AdvDial);
        S4AdvDialAddElem7->setObjectName(QString::fromUtf8("S4AdvDialAddElem7"));
        S4AdvDialAddElem7->setGeometry(QRect(210, 310, 21, 21));
        S4AdvDialAddElem6 = new QPushButton(S4AdvDial);
        S4AdvDialAddElem6->setObjectName(QString::fromUtf8("S4AdvDialAddElem6"));
        S4AdvDialAddElem6->setGeometry(QRect(210, 270, 21, 21));
        S4AdvDialAddElem5 = new QPushButton(S4AdvDial);
        S4AdvDialAddElem5->setObjectName(QString::fromUtf8("S4AdvDialAddElem5"));
        S4AdvDialAddElem5->setGeometry(QRect(210, 230, 21, 21));
        S4AdvDialComBox8 = new QComboBox(S4AdvDial);
        S4AdvDialComBox8->setObjectName(QString::fromUtf8("S4AdvDialComBox8"));
        S4AdvDialComBox8->setEnabled(false);
        S4AdvDialComBox8->setGeometry(QRect(10, 187, 191, 22));
        S4AdvDialLabel8 = new QLabel(S4AdvDial);
        S4AdvDialLabel8->setObjectName(QString::fromUtf8("S4AdvDialLabel8"));
        S4AdvDialLabel8->setGeometry(QRect(10, 170, 191, 16));

        retranslateUi(S4AdvDial);
        QObject::connect(S4ButtonBox, SIGNAL(accepted()), S4AdvDial, SLOT(accept()));
        QObject::connect(S4ButtonBox, SIGNAL(rejected()), S4AdvDial, SLOT(reject()));

        QMetaObject::connectSlotsByName(S4AdvDial);
    } // setupUi

    void retranslateUi(QDialog *S4AdvDial)
    {
        S4AdvDial->setWindowTitle(QApplication::translate("S4AdvDial", "Advanced Atribute", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel1->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel4->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S4AdvDialTable->isSortingEnabled();
        S4AdvDialTable->setSortingEnabled(false);
        S4AdvDialTable->setSortingEnabled(__sortingEnabled);

        S4AdvDialLabel3->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel2->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel7->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel5->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel6->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
        S4AdvDialAddElem7->setText(QApplication::translate("S4AdvDial", ">", 0, QApplication::UnicodeUTF8));
        S4AdvDialAddElem6->setText(QApplication::translate("S4AdvDial", ">", 0, QApplication::UnicodeUTF8));
        S4AdvDialAddElem5->setText(QApplication::translate("S4AdvDial", ">", 0, QApplication::UnicodeUTF8));
        S4AdvDialLabel8->setText(QApplication::translate("S4AdvDial", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S4AdvDial: public Ui_S4AdvDial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S4ADVDIAL_H
