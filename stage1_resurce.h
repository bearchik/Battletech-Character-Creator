#ifndef STAGE1_RESURCE_H
#define STAGE1_RESURCE_H

#include <QWidget>
#include <QMap>

class Stage1 : public QWidget
{
Q_OBJECT

private:

public:
    explicit Stage1(QWidget *parent = 0);
    void S1ShortNameAff(int);
    void S1AddTraits(QString, int);
    void S1AddSkills(QString, int);


    QStringList S1ChoiceChillHood(int, int, QList<QPair<QString, int> >);
    QStringList S1HardElem(QList<QPair<QString, int> >);
    QStringList CreateSubSkillList(QString nameSkill);

    QStringList s1ChildHoodList;
    QString s1ShortNameAff;

    QMap<QString, int> s1Attr;
    QList<QPair<QString, int> > s1Traits;
    QList<QPair<QString, int> > s1Skills;

    QString s1toolTip;
    QStringList careerList;

    int s1XpCost;

    int s1AffLang;
    int s1AffProt;
    int s1AffStreet;

    QString s1ChildHoodLabel1;
    QString s1ChildHoodLabel2;
    QString s1ChildHoodLabel3;
    QString s1ChildHoodLabel4;

    QStringList s1ChildHoodAttr1;
    QString s1ChildHoodSkillsSwp1;
    QString s1ChildHoodTraitsSwp1;
    int s1ChildHoodSkillsSwp1Int;
    int s1ChildHoodTraitsSwp1Int;

    QStringList s1ChildHoodAttr2;
    QString s1ChildHoodSkillsSwp2;
    QString s1ChildHoodTraitsSwp2;
    int s1ChildHoodSkillsSwp2Int;
    int s1ChildHoodTraitsSwp2Int;

    QStringList s1ChildHoodAttr3;
    QString s1ChildHoodSkillsSwp3;
    QString s1ChildHoodTraitsSwp3;
    QString s1MoreTraitsLabel;
    int s1ChildHoodSkillsSwp3Int;
    int s1ChildHoodTraitsSwp3Int;

    QStringList s1ChildHoodAttr4;
    QString s1ChildHoodSkillsSwp4;
    QString s1ChildHoodTraitsSwp4;
    QString s1ChildHoodAttrSwp4;
    int s1ChildHoodSkillsSwp4Int;
    int s1ChildHoodTraitsSwp4Int;
    int s1ChildHoodAttrSwp4Int;

    QString s1subAffElem1LabelMore;
    QStringList s1subAffElem1More;
    int s1affSkillsElem1More;

    QString s1subAffElem2LabelMore;
    QStringList s1subAffElem2More;
    int s1affSkillsElem2More;

    QString s1subAffElem3LabelMore;
    QStringList s1subAffElem3More;
    int s1affSkillsElem3More;

    QString s1subAffElem4LabelMore;
    QStringList s1subAffElem4More;
    int s1affSkillsElem4More;

    QStringList s1Phenotype;

    QStringList s1MoreTraits;

    QMap<QString, int> s1PreAttr;
    QList<QPair<QString, int> > s1PreTraits;
    QList<QPair<QString, int> > s1PreSkills;

    int s1ChildHoodSkills1;
    int s1ChildHoodTraits1;


    int s1ChildHoodSkills2;
    int s1ChildHoodTraits2;

    int s1ChildHoodSkills3;
    int s1ChildHoodTraits3;

    int s1ChildHoodSkills4;
    int s1ChildHoodTraits4;
    int s1MoreTraitsAttr;

    int s1ChildHoodNumber;

    int s1CountElem1;
    int s1CountElem2;
    int s1CountElem3;
    int s1CountElem4;

    QMultiMap<QString, QString> subSkillList;

signals:

public slots:
    void S1ChildHood(QString);
};

#endif // STAGE1_RESURCE_H
