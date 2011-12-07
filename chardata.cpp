#include "chardata.h"

CharData::CharData(QWidget *parent) :
    QWidget(parent)
{
    //инициализируем начальные атрибуты
    startXP = 5000;
    clearChar();
}

void CharData::Atribute()
{
    charAttr["STR"] = 100;
    charAttr["BOD"] = 100;
    charAttr["RFL"] = 100;
    charAttr["DEX"] = 100;
    charAttr["INT"] = 100;
    charAttr["WIL"] = 100;
    charAttr["CHA"] = 100;
    charAttr["EDG"] = 100;

    comChk = false;
    wobChk = false;

    milField = false;
    policField = false;
    civField = false;

    preCharAttr.clear();
    preCharSkills.clear();
    preCharTraits.clear();
}

//изменяем скилы
void CharData::changeSkills(QString skillName, int skillXP)
{
    if (charSkills.count() == 0) {
        charSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName);
        if ( i != 100500 ) {
            i--;
            charSkills[i] = qMakePair(skillName, charSkills[i].second + skillXP );
        } else {
            charSkills.append(qMakePair(skillName, skillXP));
        }
    }
}
//ищем соответсвие скила
int CharData::findSkill(QString fSkillName) {
    int b=0;
    for (int i = 0; i < charSkills.count(); i++) {
        b++;
        if (charSkills[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

//изменяем трейтцы
void CharData::changeTraits(QString traitsName, int traitsXP)
{
    if (charTraits.count() == 0) {
        charTraits.append(qMakePair(traitsName, traitsXP));
    } else {
        int i = findTraits(traitsName);
        if ( i != 100500 ) {
            i--;
            charTraits[i] = qMakePair(traitsName, charTraits[i].second + traitsXP );
        } else {
            charTraits.append(qMakePair(traitsName, traitsXP));
        }
    }
}

//ищем соответсвие трайтца
int CharData::findTraits(QString fTraitsName) {
    int b=0;
    for (int i = 0; i < charTraits.count(); i++) {
        b++;
        if (charTraits[i].first == fTraitsName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void CharData::clearZeroSkills()
{
    QList<QPair<QString, int> > swapSkill = charSkills;
    int countSkill = charSkills.count();
    charSkills.clear();
    for (int i = 0; i < countSkill; i++) {
        if (swapSkill[i].second != 0) {
            charSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

}

void CharData::clearZeroTraits()
{
    QList<QPair<QString, int> > swapTraits = charTraits;
    int countTraits = charTraits.count();
    charTraits.clear();
    for (int i = 0; i < countTraits; i++) {
        if (swapTraits[i].second != 0) {
            charTraits.append(qMakePair(swapTraits[i].first, swapTraits[i].second));
        }
    }

}

void CharData::clearChar()
{
    charAttr.clear();
    charSkills.clear();
    charTraits.clear();
    xp = startXP; //иницализация XP
    Atribute();
    changeSkills("Language/English", 20);
    changeSkills("Perception", 10);
}
