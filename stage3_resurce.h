#ifndef STAGE3_RESURCE_H
#define STAGE3_RESURCE_H

#include <QWidget>
#include <QMultiMap>
#include "carierfields.h"

class Stage3 : public QWidget
{
    Q_OBJECT
public:
    explicit Stage3(QWidget *parent = 0);

    CarierFields *carField;

//    void S3Dictionary();
    QStringList S3ClearAffilation(QString);
    void S3SchoolChange(QString, QString, QString, QString);
    void S3AddTraits(QString, int);
    void S3AddSkills(QString, int);
    void S3FieldChange(QString);
    void S3SetSchool(QString nameElem);
    QString S3SchoolEnter(QString);
    QStringList S3FieldChoose(QString);

    QMap<QString, int> s3Attr;
    QList<QPair<QString, int> > s3Traits;
    QList<QPair<QString, int> > s3Skills;


    QStringList s3BasicField;
    int s3BasicFieldAge;

    QStringList s3AdvField;
    int s3AdvFieldAge;

    QStringList s3SpecField;
    int s3SpecFieldAge;


    int s3XpCost;
    int s3FlexXP;

    int s3AffLang;
    int s3AffProt;
    int s3AffStreet;

    QStringList S3SChoolList;
//    QMultiMap<QString, QString> masterFieldList;

    QStringList s3BasicFieldListSwp;
    int s3BasicAgeSwp;

    QStringList s3AdvFieldListSwp;
    int s3AdvAgeSwp;

    QStringList s3SpecFieldListSwp;
    int s3SpecAgeSwp;

    QString s3ChildHoodLabelAdv1;
    QStringList s3ChildHoodAttrAdv1;
    int s3ChildHoodSkillsAdv1;

    QString s3ChildHoodLabelAdv2;
    QStringList s3ChildHoodAttrAdv2;
    int s3ChildHoodSkillsAdv2;

    QString s3ChildHoodLabelAdv3;
    QStringList s3ChildHoodAttrAdv3;
    int s3ChildHoodSkillsAdv3;

    QString s3ChildHoodLabelAdv4;
    QStringList s3ChildHoodAttrAdv4;
    int s3ChildHoodSkillsAdv4;

    bool s3MilField;
    bool s3PolicField;
    bool s3CivField;
    bool s3OffField;

    QMap<QString, int> s3PreAttr;
    QList<QPair<QString, int> > s3PreTraits;
    QList<QPair<QString, int> > s3PreSkills;

    QString s3toolTip;

    bool chkAdd;

    QStringList CreateSubSkillList(QString nameSkill);
    QMultiMap<QString, QString> subSkillList;

signals:

public slots:

};

#endif // STAGE3_RESURCE_H
