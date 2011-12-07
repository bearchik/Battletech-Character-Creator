#ifndef S3FIELDDIALOG_H
#define S3FIELDDIALOG_H

#include <QDialog>
#include "carierfields.h"

namespace Ui {
    class S3FieldDialog;
}

class S3FieldDialog : public QDialog
{
    Q_OBJECT
private:
    void S3FieldDialChangeSkills(QString, int);
    int S3FieldDialFindSkill(QString);

public:
    explicit S3FieldDialog(QWidget *parent = 0);
    ~S3FieldDialog();

    CarierFields *carField;

    void S3FieldDialConnectEvent();
    void S3FieldDialPrintTable();
    void S3FieldDialInit(QString, QString);
    QStringList S3FieldDialSearch(QString);
    void S3FieldDialRezet();
    void S3FieldDialClearZeroSkills();

    QList<QPair<QString, int> > s3FieldDialSkills;
    QString s3FieldDialAffProt;
    int s3FieldDialCountSkill;

    QString s3FieldDialSkillsSwp1;
    QString s3FieldDialSkillsSwp2;
    QString s3FieldDialSkillsSwp3;
    QString s3FieldDialSkillsSwp4;



private:
    Ui::S3FieldDialog *ui;

public slots:
    void S3FieldDialElem1(QString);
    void S3FieldDialElem2(QString);
    void S3FieldDialElem3(QString);
    void S3FieldDialElem4(QString);
};

#endif // S3FIELDDIALOG_H
