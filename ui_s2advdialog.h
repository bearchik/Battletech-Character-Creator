/********************************************************************************
** Form generated from reading UI file 's2advdialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S2ADVDIALOG_H
#define UI_S2ADVDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_S2AdvDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *S2AdvDialogTable;
    QComboBox *S2AdvDialComBox1;
    QComboBox *S2AdvDialComBox2;
    QComboBox *S2AdvDialComBox3;
    QLabel *S2AdvDialLabel1;
    QLabel *S2AdvDialLabel2;
    QLabel *S2AdvDialLabel3;
    QLabel *S2AdvDialLabel1_2;
    QComboBox *S2AdvDialComBox4;
    QLabel *S2AdvDialLabel4;

    void setupUi(QDialog *S2AdvDialog)
    {
        if (S2AdvDialog->objectName().isEmpty())
            S2AdvDialog->setObjectName(QString::fromUtf8("S2AdvDialog"));
        S2AdvDialog->setWindowModality(Qt::ApplicationModal);
        S2AdvDialog->resize(442, 177);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(S2AdvDialog->sizePolicy().hasHeightForWidth());
        S2AdvDialog->setSizePolicy(sizePolicy);
        S2AdvDialog->setMinimumSize(QSize(442, 177));
        S2AdvDialog->setMaximumSize(QSize(442, 177));
        buttonBox = new QDialogButtonBox(S2AdvDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 132, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S2AdvDialogTable = new QTableWidget(S2AdvDialog);
        if (S2AdvDialogTable->columnCount() < 2)
            S2AdvDialogTable->setColumnCount(2);
        if (S2AdvDialogTable->rowCount() < 4)
            S2AdvDialogTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S2AdvDialogTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S2AdvDialogTable->setItem(0, 1, __qtablewidgetitem1);
        S2AdvDialogTable->setObjectName(QString::fromUtf8("S2AdvDialogTable"));
        S2AdvDialogTable->setGeometry(QRect(230, 30, 191, 89));
        S2AdvDialogTable->setFrameShape(QFrame::Box);
        S2AdvDialogTable->setFrameShadow(QFrame::Sunken);
        S2AdvDialogTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2AdvDialogTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S2AdvDialogTable->setAutoScroll(false);
        S2AdvDialogTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S2AdvDialogTable->setTabKeyNavigation(false);
        S2AdvDialogTable->setProperty("showDropIndicator", QVariant(false));
        S2AdvDialogTable->setDragDropOverwriteMode(false);
        S2AdvDialogTable->setSelectionMode(QAbstractItemView::NoSelection);
        S2AdvDialogTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        S2AdvDialogTable->setShowGrid(false);
        S2AdvDialogTable->setGridStyle(Qt::NoPen);
        S2AdvDialogTable->setWordWrap(false);
        S2AdvDialogTable->setCornerButtonEnabled(false);
        S2AdvDialogTable->setRowCount(4);
        S2AdvDialogTable->setColumnCount(2);
        S2AdvDialogTable->horizontalHeader()->setVisible(false);
        S2AdvDialogTable->horizontalHeader()->setDefaultSectionSize(161);
        S2AdvDialogTable->horizontalHeader()->setHighlightSections(true);
        S2AdvDialogTable->horizontalHeader()->setMinimumSectionSize(25);
        S2AdvDialogTable->verticalHeader()->setVisible(false);
        S2AdvDialogTable->verticalHeader()->setDefaultSectionSize(22);
        S2AdvDialogTable->verticalHeader()->setHighlightSections(false);
        S2AdvDialogTable->verticalHeader()->setMinimumSectionSize(29);
        S2AdvDialComBox1 = new QComboBox(S2AdvDialog);
        S2AdvDialComBox1->setObjectName(QString::fromUtf8("S2AdvDialComBox1"));
        S2AdvDialComBox1->setEnabled(false);
        S2AdvDialComBox1->setGeometry(QRect(20, 26, 191, 22));
        S2AdvDialComBox2 = new QComboBox(S2AdvDialog);
        S2AdvDialComBox2->setObjectName(QString::fromUtf8("S2AdvDialComBox2"));
        S2AdvDialComBox2->setEnabled(false);
        S2AdvDialComBox2->setGeometry(QRect(20, 62, 191, 22));
        S2AdvDialComBox3 = new QComboBox(S2AdvDialog);
        S2AdvDialComBox3->setObjectName(QString::fromUtf8("S2AdvDialComBox3"));
        S2AdvDialComBox3->setEnabled(false);
        S2AdvDialComBox3->setGeometry(QRect(20, 100, 191, 22));
        S2AdvDialLabel1 = new QLabel(S2AdvDialog);
        S2AdvDialLabel1->setObjectName(QString::fromUtf8("S2AdvDialLabel1"));
        S2AdvDialLabel1->setGeometry(QRect(20, 10, 191, 16));
        S2AdvDialLabel2 = new QLabel(S2AdvDialog);
        S2AdvDialLabel2->setObjectName(QString::fromUtf8("S2AdvDialLabel2"));
        S2AdvDialLabel2->setGeometry(QRect(20, 47, 191, 16));
        S2AdvDialLabel3 = new QLabel(S2AdvDialog);
        S2AdvDialLabel3->setObjectName(QString::fromUtf8("S2AdvDialLabel3"));
        S2AdvDialLabel3->setGeometry(QRect(20, 84, 191, 16));
        S2AdvDialLabel1_2 = new QLabel(S2AdvDialog);
        S2AdvDialLabel1_2->setObjectName(QString::fromUtf8("S2AdvDialLabel1_2"));
        S2AdvDialLabel1_2->setGeometry(QRect(230, 10, 191, 16));
        S2AdvDialComBox4 = new QComboBox(S2AdvDialog);
        S2AdvDialComBox4->setObjectName(QString::fromUtf8("S2AdvDialComBox4"));
        S2AdvDialComBox4->setEnabled(false);
        S2AdvDialComBox4->setGeometry(QRect(20, 140, 191, 22));
        S2AdvDialLabel4 = new QLabel(S2AdvDialog);
        S2AdvDialLabel4->setObjectName(QString::fromUtf8("S2AdvDialLabel4"));
        S2AdvDialLabel4->setGeometry(QRect(20, 123, 191, 16));

        retranslateUi(S2AdvDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), S2AdvDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), S2AdvDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S2AdvDialog);
    } // setupUi

    void retranslateUi(QDialog *S2AdvDialog)
    {
        S2AdvDialog->setWindowTitle(QApplication::translate("S2AdvDialog", "Advanced Attribute", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S2AdvDialogTable->isSortingEnabled();
        S2AdvDialogTable->setSortingEnabled(false);
        S2AdvDialogTable->setSortingEnabled(__sortingEnabled);

        S2AdvDialLabel1->setText(QApplication::translate("S2AdvDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S2AdvDialLabel2->setText(QApplication::translate("S2AdvDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S2AdvDialLabel3->setText(QApplication::translate("S2AdvDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        S2AdvDialLabel1_2->setToolTip(QApplication::translate("S2AdvDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">A character\342\200\231s Skills list represents abilities he has been trained </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">to use eff ectively. In a typical A Time of War role-playing session, </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">characters generally use Skill Action Chec"
                        "ks to resolve actions far </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">more often than they use Attributes or Traits.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        S2AdvDialLabel1_2->setWhatsThis(QApplication::translate("S2AdvDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S2AdvDialLabel1_2->setText(QApplication::translate("S2AdvDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S2AdvDialLabel4->setText(QApplication::translate("S2AdvDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S2AdvDialog: public Ui_S2AdvDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S2ADVDIALOG_H
