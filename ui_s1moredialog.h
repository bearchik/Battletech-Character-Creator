/********************************************************************************
** Form generated from reading UI file 's1moredialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S1MOREDIALOG_H
#define UI_S1MOREDIALOG_H

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

class Ui_S1MoreDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *S1AdvDialComBox3;
    QLabel *S1AdvDialLabel3;
    QLabel *S1AdvDialLabel1;
    QComboBox *S1AdvDialComBox4;
    QLabel *S1AdvDialLabel4;
    QLabel *S1AdvDialLabel2;
    QComboBox *S1AdvDialComBox1;
    QLabel *S1AdvDialLabelTable;
    QTableWidget *S1AdvDialogTable;
    QComboBox *S1AdvDialComBox2;

    void setupUi(QDialog *S1MoreDialog)
    {
        if (S1MoreDialog->objectName().isEmpty())
            S1MoreDialog->setObjectName(QString::fromUtf8("S1MoreDialog"));
        S1MoreDialog->setWindowModality(Qt::ApplicationModal);
        S1MoreDialog->resize(433, 185);
        S1MoreDialog->setMinimumSize(QSize(433, 185));
        S1MoreDialog->setMaximumSize(QSize(433, 185));
        buttonBox = new QDialogButtonBox(S1MoreDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(250, 140, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S1AdvDialComBox3 = new QComboBox(S1MoreDialog);
        S1AdvDialComBox3->setObjectName(QString::fromUtf8("S1AdvDialComBox3"));
        S1AdvDialComBox3->setEnabled(false);
        S1AdvDialComBox3->setGeometry(QRect(10, 100, 191, 22));
        S1AdvDialLabel3 = new QLabel(S1MoreDialog);
        S1AdvDialLabel3->setObjectName(QString::fromUtf8("S1AdvDialLabel3"));
        S1AdvDialLabel3->setGeometry(QRect(10, 84, 191, 16));
        S1AdvDialLabel1 = new QLabel(S1MoreDialog);
        S1AdvDialLabel1->setObjectName(QString::fromUtf8("S1AdvDialLabel1"));
        S1AdvDialLabel1->setGeometry(QRect(10, 10, 191, 16));
        S1AdvDialComBox4 = new QComboBox(S1MoreDialog);
        S1AdvDialComBox4->setObjectName(QString::fromUtf8("S1AdvDialComBox4"));
        S1AdvDialComBox4->setEnabled(false);
        S1AdvDialComBox4->setGeometry(QRect(10, 140, 191, 22));
        S1AdvDialLabel4 = new QLabel(S1MoreDialog);
        S1AdvDialLabel4->setObjectName(QString::fromUtf8("S1AdvDialLabel4"));
        S1AdvDialLabel4->setGeometry(QRect(10, 123, 191, 16));
        S1AdvDialLabel2 = new QLabel(S1MoreDialog);
        S1AdvDialLabel2->setObjectName(QString::fromUtf8("S1AdvDialLabel2"));
        S1AdvDialLabel2->setGeometry(QRect(10, 47, 191, 16));
        S1AdvDialComBox1 = new QComboBox(S1MoreDialog);
        S1AdvDialComBox1->setObjectName(QString::fromUtf8("S1AdvDialComBox1"));
        S1AdvDialComBox1->setEnabled(false);
        S1AdvDialComBox1->setGeometry(QRect(10, 26, 191, 22));
        S1AdvDialLabelTable = new QLabel(S1MoreDialog);
        S1AdvDialLabelTable->setObjectName(QString::fromUtf8("S1AdvDialLabelTable"));
        S1AdvDialLabelTable->setGeometry(QRect(220, 10, 191, 16));
        S1AdvDialogTable = new QTableWidget(S1MoreDialog);
        if (S1AdvDialogTable->columnCount() < 2)
            S1AdvDialogTable->setColumnCount(2);
        if (S1AdvDialogTable->rowCount() < 4)
            S1AdvDialogTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S1AdvDialogTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S1AdvDialogTable->setItem(0, 1, __qtablewidgetitem1);
        S1AdvDialogTable->setObjectName(QString::fromUtf8("S1AdvDialogTable"));
        S1AdvDialogTable->setGeometry(QRect(220, 30, 191, 89));
        S1AdvDialogTable->setFrameShape(QFrame::Box);
        S1AdvDialogTable->setFrameShadow(QFrame::Sunken);
        S1AdvDialogTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S1AdvDialogTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S1AdvDialogTable->setAutoScroll(false);
        S1AdvDialogTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S1AdvDialogTable->setTabKeyNavigation(false);
        S1AdvDialogTable->setProperty("showDropIndicator", QVariant(false));
        S1AdvDialogTable->setDragDropOverwriteMode(false);
        S1AdvDialogTable->setSelectionMode(QAbstractItemView::NoSelection);
        S1AdvDialogTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        S1AdvDialogTable->setShowGrid(false);
        S1AdvDialogTable->setGridStyle(Qt::NoPen);
        S1AdvDialogTable->setWordWrap(false);
        S1AdvDialogTable->setCornerButtonEnabled(false);
        S1AdvDialogTable->setRowCount(4);
        S1AdvDialogTable->setColumnCount(2);
        S1AdvDialogTable->horizontalHeader()->setVisible(false);
        S1AdvDialogTable->horizontalHeader()->setDefaultSectionSize(161);
        S1AdvDialogTable->horizontalHeader()->setHighlightSections(true);
        S1AdvDialogTable->horizontalHeader()->setMinimumSectionSize(25);
        S1AdvDialogTable->verticalHeader()->setVisible(false);
        S1AdvDialogTable->verticalHeader()->setDefaultSectionSize(22);
        S1AdvDialogTable->verticalHeader()->setHighlightSections(false);
        S1AdvDialogTable->verticalHeader()->setMinimumSectionSize(29);
        S1AdvDialComBox2 = new QComboBox(S1MoreDialog);
        S1AdvDialComBox2->setObjectName(QString::fromUtf8("S1AdvDialComBox2"));
        S1AdvDialComBox2->setEnabled(false);
        S1AdvDialComBox2->setGeometry(QRect(10, 62, 191, 22));

        retranslateUi(S1MoreDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), S1MoreDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), S1MoreDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S1MoreDialog);
    } // setupUi

    void retranslateUi(QDialog *S1MoreDialog)
    {
        S1MoreDialog->setWindowTitle(QApplication::translate("S1MoreDialog", "Stage 1 More attributes", 0, QApplication::UnicodeUTF8));
        S1AdvDialLabel3->setText(QApplication::translate("S1MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S1AdvDialLabel1->setText(QApplication::translate("S1MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S1AdvDialLabel4->setText(QApplication::translate("S1MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S1AdvDialLabel2->setText(QApplication::translate("S1MoreDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        S1AdvDialLabelTable->setToolTip(QApplication::translate("S1MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S1AdvDialLabelTable->setWhatsThis(QApplication::translate("S1MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S1AdvDialLabelTable->setText(QApplication::translate("S1MoreDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S1AdvDialogTable->isSortingEnabled();
        S1AdvDialogTable->setSortingEnabled(false);
        S1AdvDialogTable->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class S1MoreDialog: public Ui_S1MoreDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S1MOREDIALOG_H
