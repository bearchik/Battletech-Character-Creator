#ifndef LOADRESURCE_H
#define LOADRESURCE_H
#include <QPair>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QtGui>
#include <QMessageBox>

class LoadResurce
{
public:
    LoadResurce();

    QList<QPair<QString, QString> > skillsList;
    QList<QPair<QString, QString> > traitsList;
    QStringList afflList;
    QStringList phenList;
    QStringList eyeList;
    QStringList hairList;
    QStringList planetList;
    QStringList careerList;
    QMultiMap<QString, QStringList> equipList;
    QMultiMap<QString, QStringList> weaponsList;
    QMultiMap<QString, QString> subSkillList;
    QMap<QString, QString> skillsDescList;
    QMap<QString, QString> traitsDescList;

    bool loadSkills();
    bool loadTraits();
    bool loadAffl();
    bool loadPhen();
    bool loadEye();
    bool loadHair();
    bool loadPlanets();
    bool loadEquip();
    bool loadWeapons();
    bool loadCareer();
    bool loadSubSkill();
    bool loadSkillsDesc();
    bool loadTraitsDesc();

};

#endif // LOADRESURCE_H
