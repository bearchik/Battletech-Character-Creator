#ifndef STAGE4_RESURCE_H
#define STAGE4_RESURCE_H

#include <QMap>
#include <QWidget>
#include "carierfields.h"

class Stage4 : public QWidget
{
    Q_OBJECT

private:
    QStringList S4FieldSkills(QString);

public:
    explicit Stage4(QWidget *parent = 0);

    CarierFields *carField;

    QStringList S4ClearModulesList();
    void S4AddTraits(QString, int);
    void S4AddSkills(QString, int);
    void S4ChooseLife(QString);

    int s4XpCost;
    int s4FlexXP;
    int s4AffLang;
    int s4AffProt;
    int s4AffStreet;
    bool s4repeat;
//    QMap<QString, int> s4Attr;
//    QList<QPair<QString, int> > s4Traits;
//    QList<QPair<QString, int> > s4Skills;

    QStringList s4ModulesList;

    QPair <QString, int> s4AffName; // инициализация места рождения
    QPair <QString, int> s4SubAffName; // инициализация суб места рождения
    QPair <QString, int> s4clanCastName; // инициализация касты клана
    QPair <QString, int> s4EarlyChildName; // инициализация названия ранней школоты
    QPair <QString, int> s4LateChildName; // инициализация названия поздней школоты
    QPair <QString, int> s4SchoolName; // инициализация названия школы
    QPair <QString, int> s4BasicSchool; // инициализация названия базовой подготовки
    QPair <QString, int> s4AdvSchool; // инициализация названия адв подготовки
    QPair <QString, int> s4SpecSchool; // инициализация названия спец подготовки
    QString s4Phenotype;


    QMap<QString, int> s4Attr; // инициализация атрибутов
    QList<QPair<QString, int> > s4Skills; // инициализация скилов
    QList<QPair<QString, int> > s4Traits;
    bool s4ComChk;
    bool s4WobChk;

    bool s4MilField;
    bool s4PolicField;
    bool s4CivField;

    QMap<QString, int> s4AttrMod; // инициализация атрибутов
    QList<QPair<QString, int> > s4SkillsMod; // инициализация скилов
    QList<QPair<QString, int> > s4TraitsMod;
    int s4Age;

    QString s4LabelElem1;
    QStringList s4SkillsElem1;
    QStringList s4TraitsElem1;
    int s4Elem1;

    QString s4LabelElem2;
    QStringList s4SkillsElem2;
    QStringList s4TraitsElem2;
    int s4Elem2;

    QString s4LabelElem3;
    QStringList s4SkillsElem3;
    QStringList s4TraitsElem3;
    int s4Elem3;

    QString s4LabelElem4;
    QStringList s4SkillsElem4;
    QStringList s4TraitsElem4;
    int s4Elem4;

    QString s4LabelElem5;
    QStringList s4SkillsElem5;
    QStringList s4TraitsElem5;
    int s4Elem5;
    int s4Repit5;

    QString s4LabelElem6;
    QStringList s4SkillsElem6;
    QStringList s4TraitsElem6;
    QStringList s4AttrElem6;
    int s4Elem6;
    int s4Repit6;

    QString s4LabelElem7;
    QStringList s4SkillsElem7;
    QStringList s4TraitsElem7;
    int s4Elem7;
    int s4Repit7;

    QString s4LabelElem8;
    QStringList s4SkillsElem8;
    QStringList s4TraitsElem8;
    int s4Elem8;

    QMap<QString, int> s4PreAttr;
    QList<QPair<QString, int> > s4PreTraits;
    QList<QPair<QString, int> > s4PreSkills;

    QString s4toolTip;
    QStringList CreateSubSkillList(QString nameSkill);
    QMultiMap<QString, QString> subSkillList;

    QList<QPair<QString, int> > clanFieldSkills;

signals:

public slots:

};

#endif // STAGE4_RESURCE_H
