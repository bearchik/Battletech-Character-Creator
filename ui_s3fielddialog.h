/********************************************************************************
** Form generated from reading UI file 's3fielddialog.ui'
**
** Created: Wed 14. Sep 16:02:44 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S3FIELDDIALOG_H
#define UI_S3FIELDDIALOG_H

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

class Ui_S3FieldDialog
{
public:
    QDialogButtonBox *S3FieldDialButtonBox;
    QLabel *S3FieldDialLabel2;
    QLabel *S3FieldDialLabel1;
    QComboBox *S3FieldDialComBox2;
    QTableWidget *S3FieldDialTable;
    QComboBox *S3FieldDialComBox4;
    QLabel *S3FieldDialLabel3;
    QLabel *S3FieldDialLabel_Skills;
    QComboBox *S3FieldDialComBox3;
    QLabel *S3FieldDialLabel4;
    QComboBox *S3FieldDialComBox1;

    void setupUi(QDialog *S3FieldDialog)
    {
        if (S3FieldDialog->objectName().isEmpty())
            S3FieldDialog->setObjectName(QString::fromUtf8("S3FieldDialog"));
        S3FieldDialog->setWindowModality(Qt::ApplicationModal);
        S3FieldDialog->resize(427, 185);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(S3FieldDialog->sizePolicy().hasHeightForWidth());
        S3FieldDialog->setSizePolicy(sizePolicy);
        S3FieldDialog->setMinimumSize(QSize(427, 185));
        S3FieldDialog->setMaximumSize(QSize(427, 185));
        S3FieldDialButtonBox = new QDialogButtonBox(S3FieldDialog);
        S3FieldDialButtonBox->setObjectName(QString::fromUtf8("S3FieldDialButtonBox"));
        S3FieldDialButtonBox->setGeometry(QRect(240, 140, 171, 32));
        S3FieldDialButtonBox->setOrientation(Qt::Horizontal);
        S3FieldDialButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        S3FieldDialLabel2 = new QLabel(S3FieldDialog);
        S3FieldDialLabel2->setObjectName(QString::fromUtf8("S3FieldDialLabel2"));
        S3FieldDialLabel2->setGeometry(QRect(10, 51, 191, 16));
        S3FieldDialLabel1 = new QLabel(S3FieldDialog);
        S3FieldDialLabel1->setObjectName(QString::fromUtf8("S3FieldDialLabel1"));
        S3FieldDialLabel1->setGeometry(QRect(10, 14, 191, 16));
        S3FieldDialComBox2 = new QComboBox(S3FieldDialog);
        S3FieldDialComBox2->setObjectName(QString::fromUtf8("S3FieldDialComBox2"));
        S3FieldDialComBox2->setEnabled(false);
        S3FieldDialComBox2->setGeometry(QRect(10, 66, 191, 22));
        S3FieldDialTable = new QTableWidget(S3FieldDialog);
        if (S3FieldDialTable->columnCount() < 2)
            S3FieldDialTable->setColumnCount(2);
        if (S3FieldDialTable->rowCount() < 4)
            S3FieldDialTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        S3FieldDialTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        S3FieldDialTable->setItem(0, 1, __qtablewidgetitem1);
        S3FieldDialTable->setObjectName(QString::fromUtf8("S3FieldDialTable"));
        S3FieldDialTable->setGeometry(QRect(220, 34, 191, 89));
        S3FieldDialTable->setFrameShape(QFrame::Box);
        S3FieldDialTable->setFrameShadow(QFrame::Sunken);
        S3FieldDialTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S3FieldDialTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        S3FieldDialTable->setAutoScroll(false);
        S3FieldDialTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        S3FieldDialTable->setTabKeyNavigation(false);
        S3FieldDialTable->setProperty("showDropIndicator", QVariant(false));
        S3FieldDialTable->setDragDropOverwriteMode(false);
        S3FieldDialTable->setSelectionMode(QAbstractItemView::NoSelection);
        S3FieldDialTable->setSelectionBehavior(QAbstractItemView::SelectItems);
        S3FieldDialTable->setShowGrid(false);
        S3FieldDialTable->setGridStyle(Qt::NoPen);
        S3FieldDialTable->setWordWrap(false);
        S3FieldDialTable->setCornerButtonEnabled(false);
        S3FieldDialTable->setRowCount(4);
        S3FieldDialTable->setColumnCount(2);
        S3FieldDialTable->horizontalHeader()->setVisible(false);
        S3FieldDialTable->horizontalHeader()->setDefaultSectionSize(161);
        S3FieldDialTable->horizontalHeader()->setHighlightSections(true);
        S3FieldDialTable->horizontalHeader()->setMinimumSectionSize(25);
        S3FieldDialTable->verticalHeader()->setVisible(false);
        S3FieldDialTable->verticalHeader()->setDefaultSectionSize(22);
        S3FieldDialTable->verticalHeader()->setHighlightSections(false);
        S3FieldDialTable->verticalHeader()->setMinimumSectionSize(29);
        S3FieldDialComBox4 = new QComboBox(S3FieldDialog);
        S3FieldDialComBox4->setObjectName(QString::fromUtf8("S3FieldDialComBox4"));
        S3FieldDialComBox4->setEnabled(false);
        S3FieldDialComBox4->setGeometry(QRect(10, 144, 191, 22));
        S3FieldDialLabel3 = new QLabel(S3FieldDialog);
        S3FieldDialLabel3->setObjectName(QString::fromUtf8("S3FieldDialLabel3"));
        S3FieldDialLabel3->setGeometry(QRect(10, 88, 191, 16));
        S3FieldDialLabel_Skills = new QLabel(S3FieldDialog);
        S3FieldDialLabel_Skills->setObjectName(QString::fromUtf8("S3FieldDialLabel_Skills"));
        S3FieldDialLabel_Skills->setGeometry(QRect(220, 14, 191, 16));
        S3FieldDialComBox3 = new QComboBox(S3FieldDialog);
        S3FieldDialComBox3->setObjectName(QString::fromUtf8("S3FieldDialComBox3"));
        S3FieldDialComBox3->setEnabled(false);
        S3FieldDialComBox3->setGeometry(QRect(10, 104, 191, 22));
        S3FieldDialLabel4 = new QLabel(S3FieldDialog);
        S3FieldDialLabel4->setObjectName(QString::fromUtf8("S3FieldDialLabel4"));
        S3FieldDialLabel4->setGeometry(QRect(10, 127, 191, 16));
        S3FieldDialComBox1 = new QComboBox(S3FieldDialog);
        S3FieldDialComBox1->setObjectName(QString::fromUtf8("S3FieldDialComBox1"));
        S3FieldDialComBox1->setEnabled(false);
        S3FieldDialComBox1->setGeometry(QRect(10, 30, 191, 22));

        retranslateUi(S3FieldDialog);
        QObject::connect(S3FieldDialButtonBox, SIGNAL(accepted()), S3FieldDialog, SLOT(accept()));
        QObject::connect(S3FieldDialButtonBox, SIGNAL(rejected()), S3FieldDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(S3FieldDialog);
    } // setupUi

    void retranslateUi(QDialog *S3FieldDialog)
    {
        S3FieldDialog->setWindowTitle(QApplication::translate("S3FieldDialog", "Field Attribute", 0, QApplication::UnicodeUTF8));
        S3FieldDialLabel2->setText(QApplication::translate("S3FieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        S3FieldDialLabel1->setText(QApplication::translate("S3FieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = S3FieldDialTable->isSortingEnabled();
        S3FieldDialTable->setSortingEnabled(false);
        S3FieldDialTable->setSortingEnabled(__sortingEnabled);

        S3FieldDialLabel3->setText(QApplication::translate("S3FieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        S3FieldDialLabel_Skills->setWhatsThis(QApplication::translate("S3FieldDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        S3FieldDialLabel_Skills->setText(QApplication::translate("S3FieldDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; text-decoration: underline;\">Skills</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        S3FieldDialLabel4->setText(QApplication::translate("S3FieldDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class S3FieldDialog: public Ui_S3FieldDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S3FIELDDIALOG_H
