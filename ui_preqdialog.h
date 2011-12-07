/********************************************************************************
** Form generated from reading UI file 'preqdialog.ui'
**
** Created: Wed 14. Sep 16:02:43 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREQDIALOG_H
#define UI_PREQDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PreqDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QFrame *line;
    QTableWidget *preqListTable;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *PreqDialog)
    {
        if (PreqDialog->objectName().isEmpty())
            PreqDialog->setObjectName(QString::fromUtf8("PreqDialog"));
        PreqDialog->setWindowModality(Qt::ApplicationModal);
        PreqDialog->resize(271, 353);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreqDialog->sizePolicy().hasHeightForWidth());
        PreqDialog->setSizePolicy(sizePolicy);
        PreqDialog->setMinimumSize(QSize(271, 353));
        PreqDialog->setMaximumSize(QSize(271, 353));
        buttonBox = new QDialogButtonBox(PreqDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 310, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        label = new QLabel(PreqDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 151, 16));
        line = new QFrame(PreqDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(30, 22, 201, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        preqListTable = new QTableWidget(PreqDialog);
        if (preqListTable->columnCount() < 2)
            preqListTable->setColumnCount(2);
        preqListTable->setObjectName(QString::fromUtf8("preqListTable"));
        preqListTable->setGeometry(QRect(20, 60, 231, 221));
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
        label_2 = new QLabel(PreqDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 40, 31, 16));
        label_3 = new QLabel(PreqDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 40, 71, 16));
        label_4 = new QLabel(PreqDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 290, 231, 16));

        retranslateUi(PreqDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreqDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreqDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreqDialog);
    } // setupUi

    void retranslateUi(QDialog *PreqDialog)
    {
        PreqDialog->setWindowTitle(QApplication::translate("PreqDialog", "Check Life Module", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreqDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Life Module demand</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PreqDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Name</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PreqDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">Demand XP</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PreqDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To use automatic fixing prerequisites?</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreqDialog: public Ui_PreqDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREQDIALOG_H
