#include "stage3_resurce.h"
#include <QtGui>
#include <QMultiMap>

Stage3::Stage3(QWidget *parent) :
        QWidget(parent)
{
    s3XpCost = 0;
    S3SChoolList << "Technical College" << "Trade School" << "University" << "Solaris Internship"  << "Police Academy" << "Intelligence Operative Training"
            << "Military Academy" << "Military Enlistment" << "Family Training";
    s3BasicFieldListSwp.clear();
    s3BasicAgeSwp = 0;

    s3AdvFieldListSwp.clear();
    s3AdvAgeSwp = 0;

    s3SpecFieldListSwp.clear();
    s3SpecAgeSwp = 0;

    carField = new CarierFields;

    chkAdd = false;

    s3MilField = false;
    s3PolicField = false;
    s3CivField = false;
    s3OffField = false;
}

QStringList Stage3::CreateSubSkillList(QString nameSkill) {
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

QStringList Stage3::S3ClearAffilation(QString affVar) {
    if (affVar == "Franklin Fiefs") {
        S3SChoolList.clear();
        S3SChoolList << "Technical College" << "Trade School" << "Solaris Internship"  << "Police Academy" << "Intelligence Operative Training"
                 << "Military Enlistment" << "Family Training";
    }
    if (affVar == "JarnFolk") {
        S3SChoolList.clear();
        S3SChoolList << "Family Training";
    }

    return S3SChoolList;
}

void Stage3::S3AddTraits(QString str , int count) {
    s3Traits.append(qMakePair(str,count));
}

void Stage3::S3AddSkills(QString str , int count) {
    s3Skills.append(qMakePair(str,count));
}

void Stage3::S3SchoolChange(QString school, QString affVar, QString earlyVar, QString lateVar) {

    s3AffLang = 0;
    s3AffProt = 0;
    s3AffStreet = 0;

    s3XpCost = 0;
    s3FlexXP = 0;

    s3BasicField.clear();
    s3BasicFieldAge = 0;

    s3AdvField.clear();
    s3AdvFieldAge = 0 ;

    s3SpecField.clear();
    s3SpecFieldAge = 0;

    s3ChildHoodLabelAdv1.clear();
    s3ChildHoodAttrAdv1.clear();
    s3ChildHoodSkillsAdv1 = 0;

    s3ChildHoodLabelAdv2.clear();
    s3ChildHoodAttrAdv2.clear();
    s3ChildHoodSkillsAdv2 = 0;

    s3ChildHoodLabelAdv3.clear();
    s3ChildHoodAttrAdv3.clear();
    s3ChildHoodSkillsAdv3 = 0;

    s3ChildHoodLabelAdv4.clear();
    s3ChildHoodAttrAdv4.clear();
    s3ChildHoodSkillsAdv4 = 0;

    s3PreAttr.clear();
    s3PreTraits.clear();
    s3PreSkills.clear();

    QString swpstr;

    if (school == "Technical College") {

        s3toolTip = "The common technical college (any reasonably populated and\nindustrialized world has dozens of these) is a place where students acquire\nthe skills to operate and maintain the infrastructure, be it by mastering\ncommunications or learning to operate or maintain the heavy machinery\nthat makes modern life possible. Technical colleges are open to students\nfrom virtually any social strata.\nPrerequisites: None";

        s3XpCost = 600;
        s3FlexXP = 200;

        s3Attr["DEX"] = 100;
        s3Attr["INT"] = 100;

        S3AddTraits("Equipped",150);

        S3AddSkills("Computers",20);
//        S3AddSkills("Interests/Any",30);  // SEE RULEZ!!!

        s3ChildHoodLabelAdv1 = "Interests/Any";
        s3ChildHoodAttrAdv1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s3ChildHoodSkillsAdv1 = 30;

        s3BasicField << "Communications" << "Pilot - Aerospace (Civilian)" << "Pilot - Aircraft (Civilian)" << "Pilot - DropShip (Civilian)" << "Pilot - Exoskeleton" << "Technician - Civilian";
        s3BasicFieldAge = 1;

        s3AdvField << "Cartographer" << "Engineer" << "Merchant Marine" << "Pilot - IndustrialMech" << "Pilot - JumpShip" << "Technician - Aerospace" << "Technician - Mech" << "Technician - Vehicle";
        s3AdvFieldAge = 2 ;

    }

    if (school == "Trade School") {
        s3toolTip = "Trade schools are more generalized equivalents to technical colleges\n(and just as common on any developed world, especially as they represent\nanything from a local community college to a correspondence school\nattended via interweb). In a trade school, students can acquire skills vital to\na range of non-technical careers, ranging from life sciences and commerce\nto journalism and management. Like technical colleges, trade schools are\nopen to students from virtually any social strata.\nPrerequisites: None";

        s3XpCost = 560;
        s3FlexXP = 200;

        s3Attr["INT"] = 50;
//        s3Attr["INT"] = 100;  // SEE RULEZ!!!


        S3AddTraits("Connections",50);
        S3AddTraits("Equipped",100);

//        S3AddSkills("Any three Skills",20); // SEE RULEZ!!!

        s3ChildHoodLabelAdv1 = "Skill/Any";
        s3ChildHoodAttrAdv1 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s3ChildHoodSkillsAdv1 = 20;

        s3ChildHoodLabelAdv2 = "Skill/Any";
        s3ChildHoodAttrAdv2 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s3ChildHoodSkillsAdv2 = 20;

        s3ChildHoodLabelAdv3 = "Skill/Any";
        s3ChildHoodAttrAdv3 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        s3ChildHoodSkillsAdv3 = 20;

        s3ChildHoodLabelAdv4 = "Attribute/Any";
        s3ChildHoodAttrAdv4 << "STR" << "BOD" << "RFL" << "DEX" << "WIL" << "CHA" << "EDG";
        s3ChildHoodSkillsAdv4 = 100;

        s3BasicField << "General Studies" << "Merchant";
        s3BasicFieldAge = 1;

        if (affVar == "Invading Clan" || affVar == "Homeworld Clan") {
            s3AdvField << "Analysis" << "Anthropologist" << "Archaeologist" << "Cartographer" << "Communications" << "HPG Technician" << "Journalist" << "Manager" << "Medical Assistant" << "Merchant Marine";
        } else {
            s3AdvField << "Analysis" << "Anthropologist" << "Archaeologist" << "Cartographer" << "Communications" << "Journalist" << "Manager" << "Medical Assistant" << "Merchant Marine";
        }
        s3AdvFieldAge = 2 ;


    }

    if (school == "University") {
        s3toolTip = "Universities represent the upper crust of higher education among\ncivilians. Many developed worlds have their own universities, but the cream\nof the crop are those that draw on students from across their native realms,\nsuch as House Davion’s prestigious New Avalon Institute of Science or the\nLyran's University of Tharkad. Universities are expensive, and most have\nstrict entry requirements, but off er students access to the skills for lucrative\ncareers in science, medicine, law and technology.\nPrerequisites: Minimum INT 4+. Also, if character did not take Preparatory\nSchool as a Stage 2 module (or Nobility or White Collar as a Stage 1 module),\napply the following: [Attributes] WIL(+100XP), EDG(–100XP);[Traits]\nConnection(+200XP), Reputation(–100XP), Wealth(–100XP)";

        if(lateVar != "Preparatory School") {
            if (earlyVar != "Nobility" || earlyVar != "White Collar") {
                s3Attr["WIL"] = 100;
                s3Attr["EDG"] = -100;

                S3AddTraits("Connections",200);
                S3AddTraits("Reputation", -100);
                S3AddTraits("Wealth", -100);
            }
        }

        s3XpCost = 710;
        s3FlexXP = 220;

        s3Attr["INT"] = 150;
        s3Attr["WIL"] = 75;
        s3Attr["CHA"] = 25;
        s3Attr["EDG"] = 25;

        S3AddTraits("Connections",200);
        S3AddTraits("Equipped",50);
        S3AddTraits("Reputation", 75);
        S3AddTraits("Wealth", -200);

        S3AddSkills("Computers",25);
//        S3AddSkills("Interests/Any",20);  // SEE RULEZ!!!

        s3ChildHoodLabelAdv1 = "Interests/Any";
        s3ChildHoodAttrAdv1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s3ChildHoodSkillsAdv1 = 20;

        S3AddSkills("Perception",25);

        s3AffProt = 20;

        s3BasicField << "Cartographer" << "Communications" << "General Studies" << "Manager" << "Scientist" << "Technician - Civilian";
        s3BasicFieldAge = 1;

        if (affVar == "Invading Clan" || affVar == "Homeworld Clan") {
            s3AdvField << "Analysis" << "Anthropologist" << "Archaeologist" << "Detective" << "Engineer"  << "HPG Technician" << "Planetary Surveyor" << "Medical Assistant" << "Politician" << "Technician - Mech" << "Technician - Military";
        } else {
            s3AdvField << "Analysis" << "Anthropologist" << "Archaeologist" << "Detective" << "Engineer"  << "Planetary Surveyor" << "Medical Assistant" << "Politician" << "Technician - Mech" << "Technician - Military";
        }
        s3AdvFieldAge = 2 ;

        s3SpecField << "Doctor" << "Lawyer" << "Military Scientist" << "Technician - Mech" << "Technician - Military";
        s3SpecFieldAge = 2;

        s3PreAttr["INT"] = 400;
    }

    if (school == "Solaris Internship") {
        s3toolTip = "The Game World of Solaris practically breaks all the rules when it comes\nto higher education. Here, anyone able to seize an opportunity-or with\nthe right connections—can find an alternative to conventional schooling by\ngetting in on the \"ground floor\" with an internship. Internships are informal,\nand most focus on the games in some aspect, whether learning the ins and\nouts of stable management, the skills of a BattleMech gladiator (without\nall that pesky martial discipline), or even the cutthroat world of modern\njournalism. Of course, the fact that these options only exist on a world rife\nwith crime, treachery and violence has kept far more from exploiting such\n“opportunities” as have pursued them.\nPrerequisites: Character must be a resident of Solaris VII\nand have at least +2 TP or more in the Connections Trait.";

        s3XpCost = 700;
        s3FlexXP = 100;

        s3Attr["CHA"] = 150;
        s3Attr["EDG"] = 50;
//        s3Attr["EDG"] = 50; // SEE RULEZ!!!!

        s3ChildHoodLabelAdv4 = "Attribute/Any";
        s3ChildHoodAttrAdv4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL";
        s3ChildHoodSkillsAdv4 = 50;

        S3AddTraits("Connections",100);
        S3AddTraits("Enemy", -50);
        S3AddTraits("Reputation", 100);
//        S3AddTraits("Choose: Equipped or Vehicle", 100);

        s3ChildHoodLabelAdv1 = "Choose one";
        s3ChildHoodAttrAdv1 << "Equipped" << "Vehicle";
        s3ChildHoodSkillsAdv1 = 100;

        S3AddSkills("Acting",25);
        S3AddSkills("Interests/Solaris Games",30);
        S3AddSkills("Perception",20);
//        S3AddSkills("Streetwise/Any",25);

        s3ChildHoodLabelAdv2 = "Streetwise/Any";
        s3ChildHoodAttrAdv2 = CreateSubSkillList("Streetwise");// << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
        s3ChildHoodSkillsAdv2 = 25;

        s3BasicField <<  "Communications"  << "Manager" << "Technician - Military";
        s3BasicFieldAge = 2;

        s3AdvField << "Cavalry" << "Journalist" << "MechWarrior" << "Pilot - Battle Armor" << "Politician" << "Technician - Mech";
        s3AdvFieldAge = 2 ;

        swpstr = "Connections";
        s3PreTraits.append(qMakePair(swpstr,200));
    }

    if (school == "Police Academy") {
        s3toolTip = "Virtually every inhabited world has a standing police or peacekeeping\nforce dedicated to maintaining order and catching criminals. The standard\npolice academy requires very little of potential law enforcers, but off ers the\nbenefits of a career that ideally fosters community stability and respect.\nPolice academies are open to students from virtually any social strata.\nPrerequisites: None";

        s3XpCost = 680;
        s3FlexXP = 140;

        s3Attr["RFL"] = 100;
        s3Attr["WIL"] = 100;

        S3AddTraits("Connections",50);
        S3AddTraits("Rank", 100);
        S3AddTraits("Reputation", 100);

        S3AddSkills("Computers",15);
        S3AddSkills("Driving",20);

        s3AffProt = 25;
        s3AffStreet = 30;

        s3BasicField <<  "Police Officer";
        s3BasicFieldAge = 0.5;

        s3AdvField << "Analysis" << "Communications" << "Detective" << "Intelligence" << "Technician - Military";
        s3AdvFieldAge = 1 ;

        s3SpecField << "Covert Operations" << "Police Tactical Officer" << "Special Forces" << "Technician - Aerospace" << "Technician - Vehicle";
        s3SpecFieldAge = 2;


    }

    if (school == "Intelligence Operative Training") {
        s3toolTip = "Intelligence agencies-whether working for a civilian government or\nattached to a military force-are by nature secretive and sophisticated\ninstitutions. Dedicated to protecting their home realms against threats\nwhere police are insufficient but a military response is too overpowering,\nintelligence groups tend to eschew public training campuses and focus\ntheir training programs where prying eyes cannot see. Intelligence\nagencies are thus very selective about who they recruit and why.\nPrerequisites: Minimum INT 4+ and WIL 5+, plus +2 TP or more in\nthe Connections Trait.";

        s3XpCost = 760;
        s3FlexXP = 150;

        s3Attr["INT"] = 100;
        s3Attr["WIL"] = 150;
//        s3Attr["WIL"] = 50; //SEE RULEZ!

        s3ChildHoodLabelAdv4 = "Attribute/Any";
        s3ChildHoodAttrAdv4 << "STR" << "BOD" << "RFL" << "DEX" << "CHA" << "EDG";
        s3ChildHoodSkillsAdv4 = 50;

        S3AddTraits("Alternate ID", 50);
        S3AddTraits("Connections",200);
        S3AddTraits("In For Life",-300);
        S3AddTraits("Rank", 250);
        S3AddTraits("Wealth", 50);

        S3AddSkills("Acting",20);
        S3AddSkills("Computers",20);
        s3AffProt = 20;

        s3BasicField <<  "Basic Training";
        s3BasicFieldAge = 1;

        s3AdvField << "Analysis" << "Covert Operations" << "Detective" << "Intelligence" << "Police Officer" << "Scout";
        s3AdvFieldAge = 1 ;

        s3SpecField << "Police Tactical Officer" << "Special Forces";
        s3SpecFieldAge = 2;

        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 500;

        swpstr = "Connections";
        s3PreTraits.append(qMakePair(swpstr,200));

    }

    if (school == "Military Academy") {
        s3toolTip = "Military academies represent the finest in training for career-\nminded characters in the military. Every major realm boasts at least\none interstellar-grade military academy like House Steiner's Nagelring\non Tharkad, or the Draconis Combine's  Sun  Zhang  MechWarrior\nAcademy. As the place where MechWarriors learn their craft and all\nrecruits are viewed as potential officer candidates, military academies\nhave stricter entry requirements than simple enlistment.\nPrerequisite:If character did not take Prep School or Military\nSchool as a Stage 2 module, apply the following:[Attributes] WIL\n(+100 XP), EDG(–100XP); [Traits]Connection(+200XP),\nReputation(–100XP), Wealth(–100XP)";

        if (lateVar != "Preparatory School") {
            if(lateVar != "Military School") {
                s3Attr["WIL"] = 100;
                s3Attr["EDG"] = -100;

                S3AddTraits("Connections",200);
                S3AddTraits("Reputation", -100);
                S3AddTraits("Wealth", -100);
            }
        }

        s3XpCost = 830;
        s3FlexXP = 100;

        s3Attr["STR"] = 50;
        s3Attr["BOD"] = 100;
        s3Attr["RFL"] = 125;
        s3Attr["WIL"] = 100;

        S3AddTraits("Equipped", 100);
        S3AddTraits("Rank", 200);

        S3AddSkills("Interests/Military History", 15);
        S3AddSkills("Leadership", 10);
        S3AddSkills("Swimming", 15);
        s3AffProt = 15;

        s3BasicField <<  "Basic Training" << "Basic Training (Naval)";
        s3BasicFieldAge = 1;

        s3AdvField << "Analysis" << "Cavalry" << "Infantry" << "Marine" << "MechWarrior" << "Pilot - Aerospace (Combat)" << "Pilot - Aircraft (Combat)" << "Pilot - DropShip (Civilian)" << "Scientist" << "Scout" << "Ship's Crew";
        s3AdvFieldAge = 1 ;

        s3SpecField << "Doctor" << "Infantry - Anti-'Mech" << "Military Scientist" << "Pilot - Battle Armor" << "Pilot - JumpShip" << "Special Forces";
        s3SpecFieldAge = 2;

    }

    if (school == "Military Enlistment") {
        s3toolTip = "Military academies represent the finest in training for career-\nminded characters in the military. Every major realm boasts at least\none interstellar-grade military academy like House Steiner's Nagelring\non Tharkad, or the Draconis Combine's  Sun  Zhang  MechWarrior\nAcademy. As the place where MechWarriors learn their craft and all\nrecruits are viewed as potential officer candidates, military academies\nhave stricter entry requirements than simple enlistment.\nPrerequisites: None";

        s3XpCost = 720;
        s3FlexXP = 200;

        s3Attr["STR"] = 125;
        s3Attr["BOD"] = 125;
        s3Attr["RFL"] = 100;
        s3Attr["WIL"] = 100;
        s3Attr["CHA"] = -100;

        S3AddTraits("Equipped", 50);
        S3AddTraits("Rank", 100);

        S3AddSkills("Swimming", 20);

        s3BasicField <<  "Basic Training" << "Basic Training (Naval)";
        s3BasicFieldAge = 0.5;

        s3AdvField << "Cavalry" << "Infantry" << "Marine" << "Medical Assistant" << "Police Officer" << "Scout" << "Ship's Crew" <<  "Technician - Military";
        s3AdvFieldAge = 1.5 ;

        s3SpecField << "Police Tactical Officer" << "Infantry - Anti-'Mech" << "Special Forces" << "Technician - Aerospace" << "Technician - Mech" << "Technician - Vehicle";
        s3SpecFieldAge = 1;
    }

    if (school == "Family Training") {

        s3toolTip = "Sufficiently powerful noble houses and affluent citizens can often\ncircumvent the requirements of academies and service to the state\nby instead performing their military training \"in-house\". This so-called\n\"family  training\" is particularly common among the minor noble\nhouses of far-flung worlds where the military forces of their nominal\nrulers are few and far between, leaving such worlds without defense.\nGiven the expense, many noble houses or wealthy families who\npursue this effort often present what amounts to a watered-down\nacademy experience due to a lack of regular, qualified instructors or\nstate of the art equipment, yet many nevertheless have turned out\nwarriors competent enough to serve in their homeworlds defense.\nPrerequisite: Character must have taken Preparatory School or\nMilitary School as a Stage 2 module, or received a Connections Trait\nof +1 TP or higher.";
        s3XpCost = 550;
        s3FlexXP = 100;

        s3Attr["STR"] = 75;
        s3Attr["BOD"] = 75;
        s3Attr["RFL"] = 50;
        s3Attr["WIL"] = -50;

        S3AddTraits("Equipped", 50);
        S3AddTraits("Rank", 100);

        S3AddSkills("Driving", 15);
        S3AddSkills("Interests/Homeworld History", 20);
        S3AddSkills("Survival", 20);

        s3AffProt = 15;

        s3BasicField <<  "Basic Training" << "Basic Training (Naval)";
        s3BasicFieldAge = 0.5;

        s3AdvField << "Cavalry" << "Infantry" << "Marine" << "MechWarrior" << "Pilot - Aerospace (Combat)" << "Pilot - Aircraft (Combat)" << "Pilot - DropShip (Civilian)" <<  "Scout" << "Ship's Crew";
        s3AdvFieldAge = 1.5 ;

        s3SpecField  << "Infantry - Anti-'Mech" << "Pilot - Battle Armor" << "Pilot - JumpShip";
        s3SpecFieldAge = 2;
    }

    if (school == "Officer Candidate School") {
        s3toolTip = "Any military, paramilitary or police force operates under a strict\nchain of command, but only the most qualifi ed can be officers. Officer\nCandidate School (OCS) is technically a branch of whatever academy\nor other institution the character is attending, but is paid for as an\noption after choosing all other Fields, with the following rules.\nPrerequisite:Character must have used the Intelligence, Police\nor Military Schools only, and possess at least one Basic and one\nAdvanced Field. Characters require this training to access the officer\nranks in the Rank Trait.";

        s3XpCost = 550;
        s3FlexXP = 115;

        s3Attr["CHA"] = 100;
        s3Attr["EDG"] = -200;

        S3AddTraits("Connections", 50);
        S3AddTraits("Equipped", 50);
        S3AddTraits("Rank", 250);
        S3AddTraits("Reputation", 50);
        S3AddTraits("Wealth", 100);

        S3AddSkills("Leadership", 10);
        s3AffProt = 25;

        s3BasicField << "Officer";
        s3BasicFieldAge = 1;
    }
}

QStringList Stage3::S3FieldChoose(QString fieldName) {
    QStringList listField;
    QMultiMap<QString, QString>::iterator i =carField->masterFieldList.find(fieldName);
    while (i != carField->masterFieldList.end() && i.key() == fieldName) {
        listField << i.value();
        ++i;
    }
    return listField;
}


void Stage3::S3FieldChange(QString nameElem) {
    if(nameElem == "Anthropologist") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Archaeologist") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Cartographer") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Communications") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Doctor") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["INT"] = 500;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Engineer") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "General Studies") {
//        s3CivField = true;
        s3PreAttr["INT"] = 300;
    }

    if(nameElem == "HPG Technician") {
//        s3CivField = true;
    }

    if(nameElem == "Journalist") {
//        s3CivField = true;
        s3PreAttr["INT"] = 300;
        s3PreAttr["CHA"] = 400;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Lawyer") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["CHA"] = 400;
        s3PreAttr["WIL"] = 500;
    }

    if(nameElem == "Manager") {
//        s3CivField = true;
        s3PreAttr["INT"] = 500;
        s3PreAttr["CHA"] = 500;
    }

    if(nameElem == "Medical Assistant") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Merchant") {
//        s3CivField = true;
        s3PreAttr["CHA"] = 300;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Merchant Marine") {
//        s3CivField = true;
        s3PreAttr["RFL"] = 300;
    }

    if(nameElem == "Pilot - Aerospace (Civilian)") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 400;
        s3PreAttr["INT"] = 300;
    }

    if(nameElem == "Pilot - Aircraft (Civilian)") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 300;
    }

    if(nameElem == "Pilot - DropShip (Civilian)") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["INT"] = 300;
        s3PreAttr["WIL"] = 300;

    }

    if(nameElem == "Pilot - Exoskeleton") {
//        s3CivField = true;
        s3PreAttr["STR"] = 500;
        s3PreAttr["BOD"] = 500;
    }

    if(nameElem == "Pilot - IndustrialMech") {
//        s3CivField = true;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 300;
    }

    if(nameElem == "Pilot - JumpShip") {
//        s3CivField = true;
        s3PreAttr["INT"] = 500;
    }

    if(nameElem == "Planetary Surveyor") {
//        s3CivField = true;
        s3PreAttr["INT"] = 600;
    }

    if(nameElem == "Politician") {
//        s3CivField = true;
        s3PreAttr["CHA"] = 400;
    }

    if(nameElem == "Scientist") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Technician - Aerospace") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Technician - Civilian") {
//        s3CivField = true;
        s3PreAttr["INT"] = 300;
        s3PreAttr["DEX"] = 300;
    }

    if(nameElem == "Technician - Mech") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Technician - Vehicle") {
//        s3CivField = true;
        s3PreAttr["INT"] = 400;
    }

    if(nameElem == "Analysis") {
//        s3PolicField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Covert Operations") {
//        s3PolicField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Detective") {
//        s3PolicField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 400;
    }


    if(nameElem == "Intelligence") {
//        s3PolicField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Police Officer") {
//        s3PolicField = true;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Police Tactical Officer") {
//        s3PolicField = true;
        s3PreAttr["RFL"] = 400;
    }

    if(nameElem == "Basic Training") {
//        s3MilField = true;
        s3PreAttr["INT"] = 300;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Basic Training (Naval)") {
//        s3MilField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Cavalry") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 300;
    }

    if(nameElem == "Infantry") {
//        s3MilField = true;
    }

    if(nameElem == "Infantry - Anti-'Mech") {
//        s3MilField = true;
        s3PreAttr["WIL"] = 500;
    }

    if(nameElem == "Marine") {
//        s3MilField = true;
    }

    if(nameElem == "MechWarrior") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["RFL"] = 400;
    }

    if(nameElem == "Military Scientist") {
//        s3MilField = true;
        s3PreAttr["INT"] = 500;
    }

    if(nameElem == "Officer") {
//        s3MilField = true;
    }

    if(nameElem == "Pilot - Aerospace (Combat)") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["RFL"] = 400;
    }

    if(nameElem == "Pilot - Aircraft (Combat)") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["RFL"] = 300;
    }

    if(nameElem == "Pilot - Battle Armor") {
//        s3MilField = true;
        s3PreAttr["STR"] = 600;
        s3PreAttr["BOD"] = 500;
    }

    if(nameElem == "Pilot - WarShip") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 400;
        s3PreAttr["INT"] = 600;
    }

    if(nameElem == "Scout") {
//        s3MilField = true;
        s3PreAttr["INT"] = 400;
        s3PreAttr["WIL"] = 300;
    }

    if(nameElem == "Ship's Crew") {
//        s3MilField = true;
        s3PreAttr["RFL"] = 300;
    }

    if(nameElem == "Special Forces") {
//        s3MilField = true;
        s3PreAttr["STR"] = 400;
        s3PreAttr["RFL"] = 400;
        s3PreAttr["WIL"] = 500;
    }

    if(nameElem == "Technician - Military") {
//        s3MilField = true;
        s3PreAttr["INT"] = 300;
        s3PreAttr["DEX"] = 300;
    }

    if(nameElem == "Clan Aerospace Warrior") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 500;
        s3PreAttr["RFL"] = 500;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Clan Basic Training") {
//        s3MilField = true;
    }

    if(nameElem == "Clan Cavalry") {
//        s3MilField = true;
    }

    if(nameElem == "Clan Elemental") {
//        s3MilField = true;
        s3PreAttr["BOD"] = 500;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 300;
        s3PreAttr["WIL"] = 400;
    }

    if(nameElem == "Clan MechWarrior") {
//        s3MilField = true;
        s3PreAttr["BOD"] = 400;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 400;
        s3PreAttr["WIL"] = 500;
    }

    if(nameElem == "Clan ProtoMech Warrior") {
//        s3MilField = true;
        s3PreAttr["DEX"] = 300;
        s3PreAttr["RFL"] = 400;
        s3PreAttr["WIL"] = 400;
    }

}


QString Stage3::S3SchoolEnter(QString nameElem) {
    QString nameField;

    if(nameElem == "Technical College") {
        nameField = "civ";
    }

    if(nameElem == "Trade School") {
        nameField = "civ";
    }

    if(nameElem == "University") {
        nameField = "civ";
    }

    if(nameElem == "Solaris Internship") {
        nameField = "civ";
    }

    if(nameElem == "Police Academy") {
        nameField = "pol";
    }

    if(nameElem == "Intelligence Operative Training") {
        nameField = "pol";
    }

    if(nameElem == "Officer Candidate School") {
        nameField = "pol";
    }

    if(nameElem == "Military Academy") {
        nameField = "mil";
    }

    if(nameElem == "Military Enlistment") {
        nameField = "mil";
    }

    if(nameElem == "Family Training") {
        nameField = "mil";
    }

//    if(nameElem == "Officer Candidate School") {
//        nameField = "none";
//    }

    return nameField;
}

void Stage3::S3SetSchool(QString nameElem) {
    if(nameElem == "Technical College") {
        s3CivField = true;
    }

    if(nameElem == "Trade School") {
        s3CivField = true;
    }

    if(nameElem == "University") {
        s3CivField = true;
    }

    if(nameElem == "Solaris Internship") {
        s3CivField = true;
    }

    if(nameElem == "Police Academy") {
        s3PolicField = true;
    }

    if(nameElem == "Intelligence Operative Training") {
        s3PolicField = true;
    }

    if(nameElem == "Officer Candidate School") {
        s3PolicField = true;
    }

    if(nameElem == "Military Academy") {
        s3MilField = true;
    }

    if(nameElem == "Military Enlistment") {
        s3MilField = true;
    }

    if(nameElem == "Family Training") {
        s3MilField = true;
    }

    if(nameElem == "Officer Candidate School") {
        s3OffField = true;
    }
}
