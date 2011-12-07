#include "stage1_resurce.h"
#include <QtGui>

Stage1::Stage1(QWidget *parent) :
    QWidget(parent)
{
    s1ChildHoodList << "Back Woods" << "Blue Collar" << "Born Mercenary Brat" << "Farm" << "Nobility" << "Slave" << "Street" << "Trueborn Creche" << "War Orphan" << "White Collar";
    s1Attr.clear();
    s1Traits.clear();
    s1Skills.clear();
    s1XpCost = 0;
    careerList.clear();
}

QStringList Stage1::CreateSubSkillList(QString nameSkill) {
    QStringList listSubSkills;
    QStringList listSubSkillsSwp;
    listSubSkillsSwp.clear();
    listSubSkillsSwp = subSkillList.values(nameSkill);
    for(int i=0; i < listSubSkillsSwp.count(); i++) {
        QString newName = nameSkill + "/" + listSubSkillsSwp[i];
        listSubSkills.append(newName);
    }

    listSubSkills.sort();

    return listSubSkills;
}


void Stage1::S1AddTraits(QString str , int count) {
    s1Traits.append(qMakePair(str,count));
}

void Stage1::S1AddSkills(QString str , int count) {
    s1Skills.append(qMakePair(str,count));
}


void Stage1::S1ShortNameAff(int numAff) {
    switch(numAff) {
    case 0:
        s1ShortNameAff = "Federated Suns";
        break;
    case 1:
        s1ShortNameAff = "Cappelan Confederation";
        break;
    case 2:
        s1ShortNameAff = "Draconis Combine";
        break;
    case 3:
        s1ShortNameAff = "Free Worlds League";
        break;
    case 4:
        s1ShortNameAff = "Lyran Alliance";
        break;
    case 5:
        s1ShortNameAff = "Free Rasalhague Republic";
        break;
    case 6:
        s1ShortNameAff = "Minor Periphery";
        break;
    case 7:
        s1ShortNameAff = "Major Periphery State";
        break;
    case 8:
        s1ShortNameAff = "Deep Periphery";
        break;
    case 9:
        s1ShortNameAff = "Invading Clan";
        break;
    case 10:
        s1ShortNameAff = "Homeworld Clan";
        break;
    case 11:
        s1ShortNameAff = "Terran";
        break;
    case 12:
        s1ShortNameAff = "Independent";
        break;
    default:
        s1ShortNameAff = "error!!!";
        break;
    }
}


QStringList Stage1::S1ChoiceChillHood(int affVar, int subAffVar, QList<QPair<QString, int> > tmpTrait) {
    s1ChildHoodList.clear();
    switch(affVar) {
    case 6:
        if (subAffVar == 3 || subAffVar == 5) {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Slave" << "Street" << "War Orphan" << "White Collar";
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    case 7:
        if (subAffVar == 3 ) {
            s1ChildHoodList = S1HardElem(tmpTrait);
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    case 8:
        if (subAffVar == 4 ) {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" ;
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    case 9:
        if(subAffVar >= 1) {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Slave" << "Street" << "Trueborn Creche" << "War Orphan" << "White Collar";
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    case 10:
        if(subAffVar >= 1) {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Slave" << "Street" << "Trueborn Creche" << "War Orphan" << "White Collar";
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    case 12:
        if(subAffVar == 4) {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Born Mercenary Brat" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        } else {
            s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        }
        break;
    default:
        s1ChildHoodList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
        break;
    }

    return s1ChildHoodList;
}

QStringList Stage1::S1HardElem(QList<QPair<QString, int> > tmpTrait) {
    QStringList tmpList;
    tmpList.clear();

    bool tmpChek = false;

    for (int i =0; i < tmpTrait.count(); ++i) {
        if (tmpTrait[i].first == "Citizenship/Inner Sphere" || tmpTrait[i].first == "Citizenship/Clan") {
            tmpChek = true;
        }
    }

    if ( tmpChek == true) {
        tmpList << "Back Woods" << "Blue Collar" << "Farm" << "Fugitives" << "Nobility" << "Slave" << "Street" << "War Orphan" << "White Collar";
    } else {
        tmpList << "Slave";
    }

    return tmpList;
}

void Stage1::S1ChildHood(QString nameChild) {

    QString swpstr;
    s1Attr.clear();
    s1Traits.clear();
    s1Skills.clear();
    s1AffLang = 0;
    s1AffProt = 0;
    s1AffStreet = 0;
    s1ChildHoodSkills1 = 0;
    s1ChildHoodTraits1 = 0;
    s1ChildHoodSkills2 = 0;
    s1ChildHoodTraits2 = 0;
    s1ChildHoodSkills3 = 0;
    s1ChildHoodTraits3 = 0;
    s1ChildHoodSkills4 = 0;
    s1ChildHoodTraits4 = 0;
    s1MoreTraitsAttr = 0;
    s1CountElem1 = 0;
    s1CountElem2 = 0;
    s1CountElem3 = 0;
    s1CountElem4 = 0;
    s1ChildHoodAttr1.clear();
    s1ChildHoodAttr2.clear();
    s1ChildHoodAttr3.clear();
    s1ChildHoodAttr4.clear();
    s1Phenotype.clear();

    s1PreAttr.clear();
    s1PreTraits.clear();
    s1PreSkills.clear();

    s1subAffElem1LabelMore.clear();
    s1subAffElem1More.clear();
    s1affSkillsElem1More = 0;

    s1subAffElem2LabelMore.clear();
    s1subAffElem2More.clear();
    s1affSkillsElem2More = 0;

    s1subAffElem3LabelMore.clear();
    s1subAffElem3More.clear();
    s1affSkillsElem3More = 0;

    s1subAffElem4LabelMore.clear();
    s1subAffElem4More.clear();
    s1affSkillsElem4More = 0;

    if (nameChild == "Back Woods") {
        s1toolTip = "Raised in the country (or in other remote parts of human space\nwhere amenities are few and far between), the back woods life\nleaves one hardy, but unrefi ned and uneducated.\nPrerequisites: Any affiliation; STR 4+, BOD 5+";

        s1ChildHoodNumber = 0;
        s1XpCost = 290;
        s1Attr["STR"] = 100;
        s1Attr["BOD"] = 100;
        s1Attr["RFL"] = 75;
        s1Attr["INT"] = -25;
        s1Attr["CHA"] = -50;

        S1AddTraits("Equipped", -50);
        S1AddTraits("Fit", 100);
        S1AddTraits("Illiterate", -75);
        S1AddTraits("Toughness", 75);
        S1AddTraits("Wealth", -75);

//        S1AddSkills("Language/Affiliation", -5); // SEE RULEZ!

        s1AffLang = -5;

        S1AddSkills("Martial Arts", 10);
        S1AddSkills("Melee Weapons", 10);
        S1AddSkills("Navigation/Ground", 10);
        S1AddSkills("Perception", 5);
        S1AddSkills("Running", 10);
//        S1AddSkills("Survival/Any", 15); // SEE RULEZ!
        S1AddSkills("Tracking/Wilds", 10);

        s1ChildHoodLabel1 = "Survival/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s1ChildHoodSkills1 = 15;


//        S1AddTraits("each to any two Attributes or Traits", 25); // SEE RULEZ!
//        s1ChildHoodLabel4 = "Flexible XPs: chose any two";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//        s1ChildHoodSkills4 = 25;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem1More = 25;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem2More = 25;

// prerq
        s1PreAttr["STR"] += 400;
        s1PreAttr["BOD"] += 500;
    }

    if (nameChild == "Blue Collar") {
        s1toolTip = "The common folk of most thriving commercial or industrialized\nworlds, characters from blue collar families have humble\nbeginnings, but usually receive a solid education and even\nsome vocational insights.\nPrerequisites: Any affiliation";

        s1ChildHoodNumber = 1;
        s1XpCost = 210;
        s1Attr["STR"] = 45;
        s1Attr["BOD"] = 50;
        s1Attr["DEX"] = 50;
        s1Attr["INT"] = 25;
        s1Attr["WIL"] = -10;
        s1Attr["CHA"] = -10;

//        S1AddSkills("Career/Any", 10); // SEE RULEZ!

        s1ChildHoodLabel1 = "Career/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Career");//
        s1ChildHoodSkills1 = 10;

//        S1AddSkills("Interests/Any two", 5); // SEE RULEZ!

        s1ChildHoodLabel2 = "Interests/Any two";
        s1ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s1ChildHoodSkills2 = 5;

//        S1AddTraits("each to any four Attributes, Traits or Skills", 10); // SEE RULEZ!
//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 10;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 10;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 10;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 10;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 10;
    }

    if (nameChild == "Born Mercenary Brat") {
        s1toolTip = "The child born to mercenary parents (or adopted by a\npassing mercenary command early in life) is an army brat\nof the most transient nature, whose family travels to distant\nand foreign realms with regularity, and who knows no\ntrue nationality or culture beyond the confines of military\nDropShips and field bases.\nPrerequisites: Independent/Mercenary affiliation; STR 4+, BOD 4+, WIL 4+";

        s1ChildHoodNumber = 2;
        s1XpCost = 270;

        s1Attr["STR"] = 75;
        s1Attr["BOD"] = 50;
        s1Attr["RFL"] = 100;
        s1Attr["WIL"] = 25;
        s1Attr["CHA"] = -25;
        s1Attr["EDG"] = 25;

        S1AddTraits("Equipped", 50);
        S1AddTraits("Illiterate", -50);
        S1AddTraits("Reputation", -50);

        S1AddSkills("Career/Soldier", 10);
        S1AddSkills("Interests/Military History", 5);
//        S1AddSkills("Language/Any", 10); // SEE RULEZ!
        S1AddSkills("Martial Arts", 15);
        S1AddSkills("Melee Weapons", 10);
        S1AddSkills("Negotiation", 5);
        S1AddSkills("Perception", 5);
//        S1AddSkills("Streetwise/Any", 10); // SEE RULEZ!

        s1ChildHoodLabel1 = "Language/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s1ChildHoodSkills1 = 10;

        s1ChildHoodLabel2 = "Streetwise/Any";
        s1ChildHoodAttr2 = CreateSubSkillList("Streetwise");// << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
        s1ChildHoodSkills2 = 10;

        // prerq
        s1PreAttr["STR"] = 400;
        s1PreAttr["BOD"] = 400;
        s1PreAttr["WIL"] = 400;
    }

    if (nameChild == "Farm") {
        s1toolTip = "The character raised on a farm faces a childhood of\nseemingly endless chores in a modest lifestyle. The work\nis hard, but ultimately rewarding. As not every world in the\nInner Sphere can grow its own food, farming families are often\nhighly respected.\nPrerequisites: Any affiliation";

        s1ChildHoodNumber = 3;
        s1XpCost = 275;

        s1Attr["STR"] = 100;
        s1Attr["BOD"] = 100;
        s1Attr["DEX"] = 25;
        s1Attr["CHA"] = -50;

        S1AddTraits("Animal Empathy", 25);
        S1AddTraits("Illiterate", -25);
        S1AddTraits("Toughness", 50);
        S1AddTraits("Wealth", -25);

        S1AddSkills("Career/Agriculture", 10);
        S1AddSkills("Animal Handling", 15);
//        S1AddSkills("Interests/Any two", 5); // SEE RULEZ!
        s1ChildHoodLabel1 = "Interests/Any two";
        s1ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s1ChildHoodSkills1 = 5;

//        S1AddTraits("any four Attributes, Traits or Skills", 10); // SEE RULEZ!
//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 10;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 10;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 10;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 10;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 10;
    }

    if (nameChild == "Fugitives") {
        s1toolTip = "Characters born to a fugitive lifestyle face transient\nchildhoods, constantly on the move as their parents or\nguardians—wanted for crimes against the state or hunted by\ncriminal overlords—whisk them from one world to another in a\ndesperate effort to elude capture.\nPrerequisites: Any affiliation";

        s1ChildHoodNumber = 4;
        s1XpCost = 225;

        s1Attr["STR"] = 25;
        s1Attr["RFL"] = 100;
        s1Attr["WIL"] = 100;
        s1Attr["EDG"] = 100;

        S1AddTraits("Connections", 75);
        S1AddTraits("Dark Secret", -100);
        S1AddTraits("Illiterate", -50);
        S1AddTraits("Introvert", -100);
        S1AddTraits("Wealth", -100);
//        S1AddTraits("Choose one: Combat Sense, Fit, Good Hearing, Good Vision, Patient, Thick-Skinned or Toughness", 100); // SEE RULEZ!

        s1ChildHoodLabel1 = "Choose one";
        s1ChildHoodAttr1 << "Combat Sense" << "Fit" << "Good Hearing" << "Good Vision" << "Patient" << "Thick-Skinned" << "Toughness";
        s1ChildHoodTraits1 = 100;

        S1AddSkills("Acting", 5);
//        S1AddSkills("Language/Any", 5); // SEE RULEZ!

        s1ChildHoodLabel2 = "Language/Any";
        s1ChildHoodAttr2 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s1ChildHoodSkills2 = 5;

        S1AddSkills("Perception", 10);
        S1AddSkills("Running", 10);
        S1AddSkills("Stealth", 10);
//        S1AddSkills("Streetwise/Any", 10); // SEE RULEZ!
        S1AddSkills("Zero-G Operations", 5);

        s1ChildHoodLabel3 = "Streetwise/Any";
        s1ChildHoodAttr3 = CreateSubSkillList("Streetwise");// << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
        s1ChildHoodSkills3 = 10;

//        S1AddTraits("each to any four Attributes, Traits or Skills", 5);
//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 5;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 5;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 5;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 5;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 5;
    }

    if (nameChild == "Nobility") {
        s1toolTip = "The noble-born character is blessed with the most privileged\nof upbringings, receiving upper class status, top-rate education\nand a luxurious lifestyle where every need and many desires are\nautomatically met. As a result, “bluebloods” often seem cultured,\nbut suff er from the indulgences of their soft lives.\nPrerequisites: Any non-Clan affiliation; 5+ TP(total) in Title, Wealth or Propertys ";

        s1ChildHoodNumber = 5;
        s1XpCost = 215;

        s1Attr["STR"] = -75;
        s1Attr["BOD"] = -75;
        s1Attr["RFL"] = -50;
        s1Attr["INT"] = 100;
        s1Attr["CHA"] = 100;

        S1AddTraits("Equipped", 125);
        S1AddTraits("Enemy", -200);
        S1AddTraits("Glass Jaw", -100);
        S1AddTraits("Reputation", 175);
        S1AddTraits("Wealth", 150);

        S1AddSkills("Appraisal", 5);
//        S1AddSkills("Art/Any", 10); // SEE RULEZ!
        s1ChildHoodLabel1 = "Art/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Art");//  << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
        s1ChildHoodSkills1 = 10;

//        S1AddSkills("Interests/Any", 10);  // SEE RULEZ!
        s1ChildHoodLabel2 = "Interests/Any";
        s1ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s1ChildHoodSkills2 = 10;

//        S1AddSkills("Language/Affiliation", 10); // SEE RULEZ!
        s1AffLang = 10;

//        S1AddSkills("Protocol/Affiliation", 10); // SEE RULEZ!
        s1AffProt = 10;

//        S1AddTraits("each to any four Attributes, Traits or Skills", 5);
//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 5;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned"  << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 5;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 5;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 5;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 5;

        // prerq
        swpstr = "Title";
        s1PreTraits.append(qMakePair(swpstr,500));
        swpstr = "Wealth";
        s1PreTraits.append(qMakePair(swpstr,500));
        swpstr = "Property";
        s1PreTraits.append(qMakePair(swpstr,500));
    }

    if (nameChild == "Slave") {
        s1toolTip = "Characters born to slavery are typically the children of slaves\nstill working off a debt to their masters, or were themselves\ncaptured and sold into slavery at a very young age (typically by\npirates and such). The young slave’s life can be a harsh one, with\nfew rewards.\nPrerequisites:Any affiliation; STR 4+, BOD 4+";

        s1ChildHoodNumber = 6;
        s1XpCost = 45;

        s1Attr["STR"] = 100;
        s1Attr["BOD"] = 75;
        s1Attr["DEX"] = 100;
        s1Attr["INT"] = -50;
        s1Attr["WIL"] = -50;

        S1AddTraits("Equipped", -100);
        S1AddTraits("Illiterate", -90);
        S1AddTraits("Patient", 100);
        S1AddTraits("Reputation", -100);
        S1AddTraits("Wealth", -200);
//        S1AddTraits("to either of the following Traits: Exceptional Attribute/Any or Natural Aptitude/Any", 90); // SEE RULEZ!

//        S1AddSkills("Language/Affiliation", -5); // SEE RULEZ!
        s1AffLang = -5;
//        S1AddSkills("Protocol/Affiliation", 15); // SEE RULEZ!
        s1AffProt = 15;
//                S1AddSkills("Streetwise/Affiliation", 15);
        s1AffStreet = 15;

//        S1AddSkills("Career/Any", 15); // SEE RULEZ!

        s1ChildHoodLabel1 = "Career/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Career");//  = careerList;
        s1ChildHoodSkills1 = 15;

//        S1AddSkills("Interests/Any", 10); // SEE RULEZ!
        s1ChildHoodLabel2 = "Interests/Any";
        s1ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s1ChildHoodSkills2 = 10;

        S1AddSkills("Stealth", 15);

//        S1AddSkills("Technician/Any", 5); // SEE RULEZ!

        s1ChildHoodLabel3 = "Technician/Any";
        s1ChildHoodAttr3 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        s1ChildHoodSkills3 = 5;

//        S1AddTraits("+25 XP each to any four Attributes or Traits", 25); // SEE RULEZ!

//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//        s1ChildHoodSkills4 = 25;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem1More = 25;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem2More = 25;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem3More = 25;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem4More = 25;

        s1ChildHoodLabel4 = "Choose one Traits";
        s1ChildHoodAttr4 << "Exceptional Attribute/" << "Natural Aptitude/";
        s1ChildHoodTraits4 = 90;

        // prerq
        s1PreAttr["STR"] += 400;
        s1PreAttr["BOD"] += 400;
    }

    if (nameChild == "Street") {
        s1toolTip = "The character raised on the streets lives in a dangerous world\nof lawlessness in the midst of civilization. Lacking the prosperity\nof the upper classes, such children learn quickly to rely more on\ncunning and luck than on the kindness of strangers.Prerequisites: Any affiliation";

        s1ChildHoodNumber = 7;
        s1XpCost = 250;

        s1Attr["STR"] = 25;
        s1Attr["BOD"] = -20;
        s1Attr["RFL"] = 100;
        s1Attr["INT"] = -50;
        s1Attr["WIL"] = 100;
        s1Attr["CHA"] = -25;
        s1Attr["EDG"] = 100;

        S1AddTraits("Connections", 75);
        S1AddTraits("Compulsion/Paranoid", -50);
        S1AddTraits("Enemy", -100);
        S1AddTraits("Illiterate", -75);
        S1AddTraits("Reputation", -100);
        S1AddTraits("Toughness", 200);
        S1AddTraits("Wealth", -75);

//        S1AddSkills("Language/Affiliation", -5); // SEE RULEZ!
        s1AffLang = -5;

        S1AddSkills("Martial Arts", 15);
        S1AddSkills("Melee Weapons", 5);
        S1AddSkills("Perception", 10);
        S1AddSkills("Running", 10);
        S1AddSkills("Stealth", 10);
//        S1AddSkills("Streetwise/Affiliation", 10); // SEE RULEZ!
        s1AffStreet = 10;

//        S1AddTraits("any four Attributes, Traits or Skills", 10);

//        s1ChildHoodLabel4 = "Flexible XPs: chose any four";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 10;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 10;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 10;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 10;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned"  << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 10;
    }

    if (nameChild == "Trueborn Creche") {
        s1toolTip = "The trueborn Clansman begins life in the constant company\nof his fellow genetic siblings-sibkin-while simultaneously\nlearning the arts of combat as soon as it is possible to walk. Bred\nultimately to rule their Clan as members of its warrior caste,\ntrueborns in the creche believe in the Clans’ highest law:might\nmakes right.\nPrerequisites:Clan affi liation; Phenotype and Trueborn Traits required";

        s1ChildHoodNumber = 8;
        s1XpCost = 300;

        s1Attr["STR"] = 100;
        s1Attr["BOD"] = 125;
        s1Attr["RFL"] = 125;
        s1Attr["WIL"] = 100;
        s1Attr["CHA"] = -75;

        S1AddTraits("Compulsion/Clan Honor", -100);
//        S1AddTraits("Phenotype", 0); // SEE RULEZ!

        s1ChildHoodLabel1 = "Phenotype";
        s1Phenotype << "Phenotype/Aerospace" << "Phenotype/Elemental" << "Phenotype/MechWarrior";
        s1ChildHoodSkills1 = 0;

        S1AddTraits("Slow Learner", -300);
        S1AddTraits("Trueborn", 200);

        S1AddSkills("Interests/Clan Remembrance", 10);
        S1AddSkills("Martial Arts", 10);
        S1AddSkills("Melee Weapons", 5);
        S1AddSkills("Protocol/Clan", 10);
        S1AddSkills("Small Arms", 5);
        S1AddSkills("Swimming", 10);

//        S1AddTraits("to any five Attributes, Traits or Skills", 15); // SEE RULEZ!
        s1ChildHoodLabel4 = "Flexible XPs: chose one";
        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1ChildHoodSkills4 = 15;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 15;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 15;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 15;

        s1subAffElem4LabelMore = "Flexible XPs: chose one";
        s1subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem4More = 15;

        // prerq
        swpstr = "Phenotype";
        s1PreTraits.append(qMakePair(swpstr,0));
        swpstr = "Trueborn";
        s1PreTraits.append(qMakePair(swpstr,0));
    }

    if (nameChild == "War Orphan") {
        s1toolTip = "With parents killed by foreign invaders (or friendly fire), the war\norphan begins life at a crossroads. War orphan characters often\nendure a mixture of scorn and pity in their societies, but usually\ngrow stronger and more self-reliant for it.\nPrerequisites: Any affiliation";

        s1ChildHoodNumber = 9;
        s1XpCost = 170;

        s1Attr["INT"] = 50;
        s1Attr["WIL"] = 100;
        s1Attr["EDG"] = 100;

        S1AddTraits("Compulsion/Traumatic Memories", -100);
        S1AddTraits("Illiterate", -25);
        S1AddTraits("Introvert", -50);
        S1AddTraits("Reputation", -50);
        S1AddTraits("Sixth Sense", 150);
        S1AddTraits("Wealth", -100);

//        S1AddSkills("Language/Affiliation", -5); // SEE RULEZ!
        s1AffLang = -5;
        S1AddSkills("Perception", 10);
        S1AddSkills("Stealth", 5);
//        S1AddSkills("Streetwise/Affiliation", 10); // SEE RULEZ!
        s1AffStreet = 10;

//        S1AddTraits("any three Attributes or Traits", 25);
//        s1ChildHoodLabel4 = "Flexible XPs: chose any three";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//        s1ChildHoodSkills4 = 25;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem1More = 25;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem2More = 25;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
        s1affSkillsElem3More = 25;
    }

    if (nameChild == "White Collar") {
        s1toolTip = "Above the middle class, but still a far cry from nobility, characters\nhailing from white collar families enjoy a relatively pampered\nlifestyle and sheltered existence, but hopefully realize this means\nsociety will expect more from them in return.\nPrerequisites: Any affiliation; 3+TP(total) in Wealth or Propertys";

        s1ChildHoodNumber = 10;
        s1XpCost = 170;

        s1Attr["STR"] = -50;
        s1Attr["BOD"] = -50;
        s1Attr["INT"] = 75;;
        s1Attr["WIL"] = -50;
        s1Attr["CHA"] = 75;

        S1AddTraits("Equipped", 75);
        S1AddTraits("Enemy", -100);
        S1AddTraits("Extra Income", 50);
        S1AddTraits("Glass Jaw", -50);
        S1AddTraits("Reputation", 50);
        S1AddTraits("Wealth", 100);

//        S1AddSkills("Art/Any", 10); // SEE RULEZ!
        s1ChildHoodLabel1 = "Art/Any";
        s1ChildHoodAttr1 = CreateSubSkillList("Art");// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
        s1ChildHoodSkills1 = 10;

//        S1AddSkills("Interests/Any", 10); // SEE RULEZ!

        s1ChildHoodLabel2 = "Interests/Any";
        s1ChildHoodAttr2 = CreateSubSkillList("Interests");
        s1ChildHoodSkills2 = 10;

//        S1AddSkills("Language/Affiliation", 5); // SEE RULEZ!
        s1AffLang = 5;
//        S1AddSkills("Protocol/Affiliation", 5); // SEE RULEZ!
        s1AffProt = 5;

//        S1AddTraits("any three Attributes, Traits or Skills", 5);
//        s1ChildHoodLabel4 = "Flexible XPs: chose any three";
//        s1ChildHoodAttr4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//        s1ChildHoodSkills4 = 5;

        s1subAffElem1LabelMore = "Flexible XPs: chose one";
        s1subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem1More = 5;

        s1subAffElem2LabelMore = "Flexible XPs: chose one";
        s1subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem2More = 5;

        s1subAffElem3LabelMore = "Flexible XPs: chose one";
        s1subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s1affSkillsElem3More = 5;

        // prerq
        swpstr = "Property";
        s1PreTraits.append(qMakePair(swpstr,300));
        swpstr = "Wealth";
        s1PreTraits.append(qMakePair(swpstr,300));
    }
}
