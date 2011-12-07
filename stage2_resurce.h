#ifndef STAGE2_RESURCE_H
#define STAGE2_RESURCE_H

#include <QWidget>
#include <QList>
#include <QMap>

class Stage2 : public QWidget
{
Q_OBJECT
public:
    explicit Stage2(QWidget *parent = 0);

    QStringList S2ChoiceLateChildHood(int);
    QStringList S2HardElemAffil(QList<QPair<QString, int> >, int, int);
    QStringList S2ClearListElem(QStringList, QString, int);
    void S2LateChildhood(QString, QString);
    void S2AddTraits(QString, int);
    void S2AddSkills(QString, int);
    QStringList S2FreebornSibko();
    QStringList S2TruebornSibko(QString);

    void S2FreebornSibkoAttr(QString);
    void S2TruebornSibkoAttr(QString);
    QStringList S2ClanBasicFieldChange(QString);



    QMap<QString, int> s2Attr;
    QList<QPair<QString, int> > s2Traits;
    QList<QPair<QString, int> > s2Skills;

    QMap<QString, int> s2SwpAttr;
    QList<QPair<QString, int> > s2SwpTraits;
    QList<QPair<QString, int> > s2SwpSkills;

    int s2CountElem2;

    int s2XpCost;
    int s2FlexXP;

    int s2AffLang;
    int s2AffProt;
    int s2AffStreet;

    QStringList s2LateChildHoodList;

    QString ChildHoodLabel1;

    QString s2ChildHoodLabel1;
    QString s2ChildHoodLabel2;
    QString s2ChildHoodLabel3;


    QStringList s2ChildHoodAttr1;
    QString s2ChildHoodSkillsSwp1;
    QString s2ChildHoodTraitsSwp1;
    int s2ChildHoodSkillsSwp1Int;
    int s2ChildHoodTraitsSwp1Int;

    QStringList s2ChildHoodAttr2;
    QString s2ChildHoodSkillsSwp2;
    QString s2ChildHoodTraitsSwp2;
    int s2ChildHoodSkillsSwp2Int;
    int s2ChildHoodTraitsSwp2Int;

    QStringList s2ChildHoodAttr3;
    QString s2ChildHoodSkillsSwp3;
    QString s2ChildHoodTraitsSwp3;
    QString s2MoreTraitsLabel;
    int s2ChildHoodSkillsSwp3Int;
    int s2ChildHoodTraitsSwp3Int;

    QString s2ChildHoodLabelAdv1;
    QStringList s2ChildHoodAttrAdv1;
    int s2ChildHoodSkillsAdv1;
    int s2ChildHoodTraitsAdv1;


    QString s2ChildHoodLabelAdv2;
    QStringList s2ChildHoodAttrAdv2;
    int s2ChildHoodSkillsAdv2;
    int s2ChildHoodTraitsAdv2;


    QString s2ChildHoodLabelAdv3;
    QStringList s2ChildHoodAttrAdv3;
    int s2ChildHoodSkillsAdv3;
    int s2ChildHoodTraitsAdv3;

    QString s2ChildHoodLabelAdv4;
    QStringList s2ChildHoodAttrAdv4;
    int s2ChildHoodSkillsAdv4;
    int s2ChildHoodTraitsAdv4;


    QString s2AdvSwpTraits;
    int s2AdvSwpTraitsInt;
    QString s2AdvSwpSkills;
    int s2AdvSwpSkillsInt;

    int s2ChildHoodSkills1;
    int s2ChildHoodTraits1;

    int s2ChildHoodSkills2;
    int s2ChildHoodTraits2;

    int s2ChildHoodSkills3;
    int s2ChildHoodTraits3;

    int s2ClanAdvXP;
    int s2ClanAdvStepXP;
    int s2ClanAdvRebateXP;

    int s2ClanBasicXP;
    int s2ClanBasicStepXP;
    int s2ClanBasicRebateXP;

    QStringList s2ClanAdvFieldList;

    QMap<QString, int> s2PreAttr;
    QList<QPair<QString, int> > s2PreTraits;
    QList<QPair<QString, int> > s2PreSkills;

    QString s2toolTip;

    QStringList CreateSubSkillList(QString nameSkill);
    QMultiMap<QString, QString> subSkillList;

signals:

public slots:

};

#endif // STAGE2_RESURCE_H
