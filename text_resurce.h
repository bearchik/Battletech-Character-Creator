#ifndef TEXT_RESURCE_H
#define TEXT_RESURCE_H

#include <QWidget>
#include <QMap>


class Text_Resurce : public QWidget
{
Q_OBJECT

private:
    void addSubTraits(QString, int);
    void addSubSkills(QString, int);
    void addSubTraitsCast(QString, int);
    void addSubSkillsCast(QString, int);

public:
    explicit Text_Resurce(QWidget *parent = 0);
    QStringList subAffList; // список SubAffilation
    QStringList clanCasts; // список клановы дополнений
    QString toolTipAff; // описание дома в тултипе
    QString ower_Affil;
    QStringList listLang;
    QStringList primLang;
    QStringList secLang;
    QStringList affElem1;
    QStringList affElem2;
    QStringList swpList;

    QString subAffElem1Label;
    QString subAffElem2Label;
    QString subAffElem3Label;
    QString subAffElem4Label;
    QStringList subAffElem1;
    QStringList subAffElem2;
    QStringList subAffElem3;
    QStringList subAffElem4;

    QString subAffElem1LabelMore;
    QStringList subAffElem1More;
    int affSkillsElem1More;

    QString subAffElem2LabelMore;
    QStringList subAffElem2More;
    int affSkillsElem2More;

    QString subAffElem3LabelMore;
    QStringList subAffElem3More;
    int affSkillsElem3More;

    QString subAffElem4LabelMore;
    QStringList subAffElem4More;
    int affSkillsElem4More;

    QString affProtocol;
    QString affStreet;

    QStringList comElem;
    int comElemInt;

    QStringList allSkills;
    QStringList allTraits;

    QStringList swpLang;
    QMultiMap<QString, QString> subSkillList;

    int countFMAttr;
    int xpCostModule;
    int elem1XPAttr;
    int elem1XPSkills;
    int elem1XPTraits;
    int countElem1;
    int elem2XPAttr;
    int elem2XPSkills;
    int elem2XPTraits;
    int countElem2;
    int countElem4;
    int subCountElem1;
    int subCountElem2;
    int subCountElem3;
    int subCountElem4;
    QMap<QString, int> affAttr;
    QList<QPair<QString, int> > affTraits;
    QList<QPair<QString, int> > affSkills;

    QMap<QString, int> s0PreAttr;
    QList<QPair<QString, int> > s0PreTraits;
    QList<QPair<QString, int> > s0PreSkills;

    QMap<QString, int> affAttrCast;
    QList<QPair<QString, int> > affTraitsCast;
    QList<QPair<QString, int> > affSkillsCast;

    int affSkillsElem1;
    int affTraitsElem1;
    int affAttrElem1;
    int affSkillsElem2;
    int affTraitsElem2;
    int affAttrElem2;
    int affSkillsElem3;
    int affTraitsElem3;
    int affAttrElem3;
    int affSkillsElem4;
    int affTraitsElem4;
    int affAttrElem4;

    QMap<QString, int> swpAffAttr; // инициализация своп атрибутов
    QList<QPair<QString, int> > swpAffTraits; // инициализация своп трейтцов
    QList<QPair<QString, int> > swpAffSkills; // инициализация своп скилов

    void rSubAff(int);
    void comstarAttr(bool);
    void comstarSub(bool);
    void WoBSub(bool);
    void subAffAttr(int, int);
    void swapChar(); // свопимся
    void restoreChar(); // востанавливаем чара
    void clanCaste(QString); // описание каст кланов
    QStringList CreateSubSkillList(QString nameSkill);

    QMap<QString, int> ageCharAttr;
    QList<QPair<QString, int> > ageTraits;
    void AgeAttr(int age, QString affl);

signals:

public slots:

};

#endif // TEXT_RESURCE_H
