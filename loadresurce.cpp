#include "loadresurce.h"

#define SKILL_FILE "resource/allskills.dat"
#define TRAIT_FILE "resource/alltraits.dat"
#define AFF_FILE "resource/affilations.dat"
#define PHEN_FILE "resource/phenotype.dat"
#define EYE_FILE "resource/eyecolor.dat"
#define HAIR_FILE "resource/haircolor.dat"
#define PLANET_FILE "resource/planets.dat"
#define EQUIP_FILE "resource/equiplist.dat"
#define WEAPONS_FILE "resource/weaponslist.dat"
#define CAREER_FILE "resource/career.dat"
#define SUBSKILL_FILE "resource/subskill.dat"
#define SKILLSDESC_FILE "resource/skillsdesc.dat"
#define TRAITSDESC_FILE "resource/traitsdesc.dat"

LoadResurce::LoadResurce()
{

}

bool LoadResurce::loadSkills() {
    skillsList.clear();
    QStringList sBuf;
    sBuf.clear();
    QString str;
    str.clear();
    QFile file(SKILL_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            str = stream.readLine();
            sBuf = str.split(";",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                skillsList.append(qMakePair(sBuf[0],sBuf[1]));
            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadTraits() {
    traitsList.clear();
    QStringList sBuf;
    sBuf.clear();
    QString str;
    str.clear();
    QFile file(TRAIT_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            str = stream.readLine();
            sBuf = str.split(";",QString::SkipEmptyParts);
            if (sBuf.count() == 2){
                traitsList.append(qMakePair(sBuf[0],sBuf[1]));
            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadAffl() {
    afflList.clear();
    QFile file(AFF_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            afflList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadPhen() {
    phenList.clear();
    QFile file(PHEN_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            phenList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadCareer() {
    careerList.clear();
    QFile file(CAREER_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            careerList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadEye() {
    eyeList.clear();
    QFile file(EYE_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            eyeList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadHair() {
    hairList.clear();
    QFile file(HAIR_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            hairList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadPlanets() {
    planetList.clear();
    QFile file(PLANET_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            planetList << stream.readLine();
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadEquip() {
    equipList.clear();
    QStringList equipSwp;
    QString strBuf;
    QFile file(EQUIP_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            equipSwp.clear();
            strBuf = stream.readLine();
            equipSwp << strBuf.split(";",QString::SkipEmptyParts);
            if(equipSwp.count() >= 7) {
                equipList.insert(equipSwp[0], QStringList() << equipSwp[1] << equipSwp[2] << equipSwp[3] << equipSwp[4] << equipSwp[5] << equipSwp[6]);

            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadWeapons() {
    weaponsList.clear();
    QStringList weaponsSwp;
    QString strBuf;
    QFile file(WEAPONS_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            weaponsSwp.clear();
            strBuf = stream.readLine();
            weaponsSwp << strBuf.split(";",QString::SkipEmptyParts);
            if(weaponsSwp.count() >= 11) {
                weaponsList.insert(weaponsSwp[0], QStringList() << weaponsSwp[1] << weaponsSwp[2] << weaponsSwp[3] << weaponsSwp[4] << weaponsSwp[5] << weaponsSwp[6] << weaponsSwp[7] << weaponsSwp[8] << weaponsSwp[9] << weaponsSwp[10]);

            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadSubSkill() {
    subSkillList.clear();
    QStringList subSkillSwp;
    QString strBuf;
    QFile file(SUBSKILL_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            subSkillSwp.clear();
            strBuf = stream.readLine();
            subSkillSwp << strBuf.split(";",QString::SkipEmptyParts);
            if(subSkillSwp.count() >= 2) {
                subSkillList.insert(subSkillSwp[0], subSkillSwp[1]);

            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadSkillsDesc() {
    skillsDescList.clear();
    QStringList skillDescSwp;
    QString strBuf;
    QFile file(SKILLSDESC_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            skillDescSwp.clear();
            strBuf = stream.readLine();
            skillDescSwp << strBuf.split(";",QString::SkipEmptyParts);
            if(skillDescSwp.count() >= 2) {
                skillsDescList.insert(skillDescSwp[0], skillDescSwp[1]);

            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

bool LoadResurce::loadTraitsDesc() {
    traitsDescList.clear();
    QStringList traitsDescSwp;
    QString strBuf;
    QFile file(TRAITSDESC_FILE);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            traitsDescSwp.clear();
            strBuf = stream.readLine();
            traitsDescSwp << strBuf.split(";",QString::SkipEmptyParts);
            if(traitsDescSwp.count() >= 2) {
                traitsDescList.insert(traitsDescSwp[0], traitsDescSwp[1]);

            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
}
