/********************************************************************************
** Form generated from reading UI file 's0moredialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S0MOREDIALOG_H
#define UI_S0MOREDIALOG_H

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

class Ui_S0MoreDialog
{
public:
    QDialogButtonBox *S0ButtonBox;
    QComboBox *S0AdvDialComBox4;
    QComboBox *S0AdvDialComBox3;
    QComboBox *S0AdvDialComBox1;
    QLabel *S0AdvDialLabel1;
    QLabel *S0AdvDialLabel2;
    QLabel *S0AdvDialLabel1_2;
    QComboBox *S0AdvDialComBox2;
    QLabel *S0AdvDialLabel4;
    QTableWidget *S0AdvDialogTable;
    QLabel *S0AdvDialLabel3;

    void setupUi(QDialog *S0MoreDialog)
    {
        if (S0MoreDialog->objectName().isEmpty())
            S0MoreDialog->setObjectName(QString::fromUtf8("S0MoreDialog"));
        S0MoreDialog->setWindowModality(Qt::ApplicationModal);
        S0MoreDialog->resize(433, 185);
        S0MoreDialog->setMinimumSize(QSize(433, 185));
        S0MoreDialog->setMaximumSize(QSize(433, 185));
        S0ButtonBox = new QDialogButtonBox(S0MoreDialog);
        S0ButtonBox->setObjectName(QString::fromUtf8("S0ButtonBox"));
        S0ButtonBox->setGeometry(QRect(250, 140, 161, 32));
        S0ButtonBox->setOrientation(Qt::Horizontal);
        S0ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S0AdvDialComBox4 = new QComboBox(S0MoreDialog);
        S0AdvDialComBox4->setObjectName(QString::fromUtf8("S0AdvDialComBox4"));
        S0AdvDialComBox4->setEnabled(false);
        S0AdvDialComBox4->setGeometry(QRect(10, 146, 191, 22));
        S0AdvDialComBox3 = new QComboBox(S0MoreDialog);
        S0AdvDialComBox3->setObjectName(QString::fromUtf8("S0AdvDialComBox3"));
        S0AdvDialComBox3->setEnabled(false);
        S0AdvDialComBox3->setGeometry(QRect(10, 106, 191, 22));
        S0AdvDialComBox1 = new QComboBox(S0MoreDialog);
        S0AdvDialComBox1->setObjectName(QString::fromUtf8("S0AdvDialComBox1"));
        S0AdvDialComBox1->setEnabled(false);
        S0AdvDialComBox1->setGeometry(QRect(10, 32, 191, 22));
        S0AdvDialLabel1 = new QLabel(S0MoreDialog);
        S0AdvDialLabel1->setObjectName(QString::fromUtf8("S0AdvDialLabel1"));
        S0AdvDialLabel1->setGeometry(QRect(10, 16, 191, 16));
        S0AdvDialLabel2 = new QLabel(S0MoreDialog);
        S0AdvDialLabel2->setObjectName(QString::fromUtf8("S0AdvDialLabel2"));
        S0AdvDialLabel2->setGeometry(QRect(10, 53, 191, 16));
        S0AdvDialLabel1_2 = new QLabel(S0MoreDialog);
        S0AdvDialLabel1_2->setObjectName(QString::fromUtf8("S0AdvDialLabel1_2"));
        S0AdvDialLabel1_2->setGeometry(QRect(220, 16, 191, 16));
        S0AdvDialComBox2 = new QComboBox(S0MoreDialog);
        S0AdvDialComBox2->setObjectName(QString::fromUtf8("S0AdvDialComBox2"));
        S0AdvDialComBox2->setEnabled(false);
        S0AdvDialComBox2->setGeometry(QRect(10, 68, 191, 22));
        S0AdvDialLabel4 = new QLabel(S0MoreDialog);
        S0AdvDialLabel4->setObjectName(QString::fromUtf8("S0AdvDialLabel4"));
        S0AdvDialLabel4->setGeometry(QRect(10, 129, 191, 16));
        S0AdvDialogTable = new QTableWidget(S0MoreDialog);
        if (S0AdvDialogTable->columnCount() < 2)
            S0AdvDialogTable->setColumnCount(2);
        if (S0AdvDialogTable->rowCount() < 4)
            S0AdvDialogTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S0AdvDialogTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S0AdvDialogTable->setItem(0, 1, __qtablewidgetitem1);
        S0AdvDialogTable->setObjectName(QString::fromUtf8("S0AdvDialogTable"));
        S0AdvDialogTable->setGeometry(QRect(220, 36, 191, 89));
        S0AdvDialogTable->setFrameShape(QFrame::Box);
        S0AdvDialogTable->setFrameShadow(QFrame::Sunken);
        S0AdvDialogTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S0AdvDialogTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S0AdvDialogTable->setAutoScroll(false);
        S0AdvDialogTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S0AdvDialogTable->setTabKeyNavigation(false);
        S0AdvDialogTable->setProperty("showDropIndicator", QVariant(false));
        S0AdvDialogTable->setDragDropOverwriteMode(false);
        S0AdvDialogTable->setSelectionMode(QAbstractItemView::NoSelection);
        S0AdvDialogTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        S0AdvDialogTable->setShowGrid(false);
        S0AdvDialogTable->setGridStyle(Qt::NoPen);
        S0AdvDialogTable->setWordWrap(false);
        S0AdvDialogTable->setCornerButtonEnabled(false);
        S0AdvDialogTable->setRowCount(4);
        S0AdvDialogTable->setColumnCount(2);
        S0AdvDialogTable->horizontalHeader()->setVisible(false);
        S0AdvDialogTable->horizontalHeader()->setDefaultSectionSize(161);
        S0AdvDialogTable->horizontalHeader()->setHighlightSections(true);
        S0AdvDialogTable->horizontalHeader()->setMinimumSectionSize(25);
        S0AdvDialogTable->verticalHeader()->setVisible(false);
        S0AdvDialogTable->verticalHeader()->setDefaultSectionSize(22);
        S0AdvDialogTable->verticalHeader()->setHighlightSections(false);
        S0AdvDialogTable->verticalHeader()->setMinimumSectionSize(29);
        S0AdvDialLabel3 = new QLabel(S0MoreDialog);
        S0AdvDialLabel3->setObjectName(QString::fromUtf8("S0AdvDialLabel3"));
        S0AdvDialLabel3->setGeometry(QRect(10, 90, 191, 16));

        retranslateUi(S0MoreDialog);
        QObject::connect(S0ButtonBox, SIGNAL(accepted()), S0MoreDialog, SLOT(accept()));
        QObject::connect(S0ButtonBox, SIGNAL(rejected()), S0MoreDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S0MoreDialog);
    } // setupUi

    void retranslateUi(QDialog *S0MoreDialog)
    {
        S0MoreDialog->setWindowTitle(QApplication::translate("S0MoreDialog", "Stage 0 More attributes", 0, QApplication::UnicodeUTF8));
        S0AdvDialLabel1->setText(QApplication::translate("S0MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S0AdvDialLabel2->setText(QApplication::translate("S0MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        S0AdvDialLabel1_2->setToolTip(QApplication::translate("S0MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S0AdvDialLabel1_2->setWhatsThis(QApplication::translate("S0MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S0AdvDialLabel1_2->setText(QApplication::translate("S0MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S0AdvDialLabel4->setText(QApplication::translate("S0MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S0AdvDialogTable->isSortingEnabled();
        S0AdvDialogTable->setSortingEnabled(false);
        S0AdvDialogTable->setSortingEnabled(__sortingEnabled);

        S0AdvDialLabel3->setText(QApplication::translate("S0MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S0MoreDialog: public Ui_S0MoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S0MOREDIALOG_H
