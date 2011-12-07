#include "carierfields.h"
#include "QtGui"

CarierFields::CarierFields(QWidget *parent) :
    QWidget(parent)
{
    ////CIVILIAN SKILL FIELDS

    // Anthropologist
    masterFieldList.insert("Anthropologist","Career/Anthropologist");
    masterFieldList.insert("Anthropologist","Interests/History (Any one culture)");
    masterFieldList.insert("Anthropologist","Investigation");
    masterFieldList.insert("Anthropologist","Language/Any");
    masterFieldList.insert("Anthropologist","Language/Any");
    masterFieldList.insert("Anthropologist","Protocol/Any");

    // Archaeologist
    masterFieldList.insert("Archaeologist","Career/Archaeologist");
    masterFieldList.insert("Archaeologist","Appraisal");
    masterFieldList.insert("Archaeologist","Interests/Geology");
    masterFieldList.insert("Archaeologist","Interests/History (any)");
    masterFieldList.insert("Archaeologist","Navigation/Ground");
    masterFieldList.insert("Archaeologist","Perception");

    // Cartographer
    masterFieldList.insert("Cartographer","Career/Cartographer");
    masterFieldList.insert("Cartographer","Computers");
    masterFieldList.insert("Cartographer","Navigation/Air");
    masterFieldList.insert("Cartographer","Navigation/Ground");
    masterFieldList.insert("Cartographer","Perception");
    masterFieldList.insert("Cartographer","Sensor Operations");

    // Communications
    masterFieldList.insert("Communications","Acting");
    masterFieldList.insert("Communications","Career/Communications");
    masterFieldList.insert("Communications","Communications/Conventional");
    masterFieldList.insert("Communications","Computers");
    masterFieldList.insert("Communications","Protocol/Any");
    masterFieldList.insert("Communications","Sensor Operations");

    // Doctor
    masterFieldList.insert("Doctor","Administration");
    masterFieldList.insert("Doctor","Career/Doctor");
    masterFieldList.insert("Doctor","MedTech");
    masterFieldList.insert("Doctor","Protocol/Affiliation");
    masterFieldList.insert("Doctor","Surgery/Any");

    // Engineer
    masterFieldList.insert("Engineer","Appraisal");
    masterFieldList.insert("Engineer","Career/Engineer");
    masterFieldList.insert("Engineer","Perception");
    masterFieldList.insert("Engineer","Technician/Nuclear");
    masterFieldList.insert("Engineer","Technician/Any");

    // General Studies
    masterFieldList.insert("General Studies","Computers");
    masterFieldList.insert("General Studies","Career/Any");
    masterFieldList.insert("General Studies","Interests/Any");
    masterFieldList.insert("General Studies","Perception");
    masterFieldList.insert("General Studies","Protocol/Affiliation");

    // HPG Technician
    masterFieldList.insert("HPG Technician","Administration");
    masterFieldList.insert("HPG Technician","Communications/Conventional");
    masterFieldList.insert("HPG Technician","Communications/HPG");
    masterFieldList.insert("HPG Technician","Computers");
    masterFieldList.insert("HPG Technician","Cryptography");

    // Journalist
    masterFieldList.insert("Journalist","Acting");
    masterFieldList.insert("Journalist","Art/Writing");
    masterFieldList.insert("Journalist","Career/Journalist");
    masterFieldList.insert("Journalist","Computers");
    masterFieldList.insert("Journalist","Investigation");
    masterFieldList.insert("Journalist","Perception");

    // Lawyer
    masterFieldList.insert("Lawyer","Acting");
    masterFieldList.insert("Lawyer","Administration");
    masterFieldList.insert("Lawyer","Career/Lawyer");
    masterFieldList.insert("Lawyer","Interests/Law");
    masterFieldList.insert("Lawyer","Negotiation");
    masterFieldList.insert("Lawyer","Protocol/Any");

    // Manager
    masterFieldList.insert("Manager","Administration");
    masterFieldList.insert("Manager","Career/Management");
    masterFieldList.insert("Manager","Leadership");
    masterFieldList.insert("Manager","Negotiation");
    masterFieldList.insert("Manager","Protocol/Affiliation");
    masterFieldList.insert("Manager","Training");

    // Medical Assistant
    masterFieldList.insert("Medical Assistant","Computers");
    masterFieldList.insert("Medical Assistant","Career/Medtech");
    masterFieldList.insert("Medical Assistant","Interests/Pharmacology");
    masterFieldList.insert("Medical Assistant","MedTech");
    masterFieldList.insert("Medical Assistant","Perception");

    // Merchant
    masterFieldList.insert("Merchant","Administration");
    masterFieldList.insert("Merchant","Appraisal");
    masterFieldList.insert("Merchant","Career/Merchant");
    masterFieldList.insert("Merchant","Negotiation");
    masterFieldList.insert("Merchant","Protocol/Any");
    masterFieldList.insert("Merchant","Streetwise/Any");

    // Merchant Marine
    masterFieldList.insert("Merchant Marine","Career/Merchant Marine");
    masterFieldList.insert("Merchant Marine","Protocol/Any");
    masterFieldList.insert("Merchant Marine","Technician/Aeronautics");
    masterFieldList.insert("Merchant Marine","Technician/Any");
    masterFieldList.insert("Merchant Marine","Zero-G Operations");

    // Pilot - Aerospace (Civilian)
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Career/Aerospace Pilot");
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Communications/Conventional");
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Navigation/Air");
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Navigation/Space");
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Piloting/Aerospace");
    masterFieldList.insert("Pilot - Aerospace (Civilian)","Sensor Operations");

    // Pilot - Aircraft (Civilian)
    masterFieldList.insert("Pilot - Aircraft (Civilian)","Career/Aircraft Pilot");
    masterFieldList.insert("Pilot - Aircraft (Civilian)","Communications/Conventional");
    masterFieldList.insert("Pilot - Aircraft (Civilian)","Navigation/Air");
    masterFieldList.insert("Pilot - Aircraft (Civilian)","Piloting/Aircraft or VTOL");
    masterFieldList.insert("Pilot - Aircraft (Civilian)","Sensor Operations");

    // Pilot - DropShip (Civilian)
    masterFieldList.insert("Pilot - DropShip (Civilian)","Career/DropShip Pilot");
    masterFieldList.insert("Pilot - DropShip (Civilian)","Communications/Conventional");
    masterFieldList.insert("Pilot - DropShip (Civilian)","Navigation/Space");
    masterFieldList.insert("Pilot - DropShip (Civilian)","Piloting/Spacecraft");
    masterFieldList.insert("Pilot - DropShip (Civilian)","Sensor Operations");
    masterFieldList.insert("Pilot - DropShip (Civilian)","Zero-G Operations");

    // Pilot - Exoskeleton
    masterFieldList.insert("Pilot - Exoskeleton","Piloting/Battlesuit");
    masterFieldList.insert("Pilot - Exoskeleton","Sensor Operations");
    masterFieldList.insert("Pilot - Exoskeleton","Technician/Electric");
    masterFieldList.insert("Pilot - Exoskeleton","Technician/Mechanical");
    masterFieldList.insert("Pilot - Exoskeleton","Technician/Myomer");

    // Pilot - IndustrialMech
    masterFieldList.insert("Pilot - IndustrialMech","Piloting/Mech");
    masterFieldList.insert("Pilot - IndustrialMech","Sensor Operations");
    masterFieldList.insert("Pilot - IndustrialMech","Technician/Electronic");
    masterFieldList.insert("Pilot - IndustrialMech","Technician/Mechanical");
    masterFieldList.insert("Pilot - IndustrialMech","Technician/Myomer");

    // Pilot - JumpShip
    masterFieldList.insert("Pilot - JumpShip","Administration");
    masterFieldList.insert("Pilot - JumpShip","Computers");
    masterFieldList.insert("Pilot - JumpShip","Navigation/K-F Jump");
    masterFieldList.insert("Pilot - JumpShip","Navigation/Space");

    // Planetary Surveyor
    masterFieldList.insert("Planetary Surveyor","Appraisal");
    masterFieldList.insert("Planetary Surveyor","Driving/Any");
    masterFieldList.insert("Planetary Surveyor","Navigation/Ground");
    masterFieldList.insert("Planetary Surveyor","Survival/Any");
    masterFieldList.insert("Planetary Surveyor","Tracking/Wilds");

    // Politician
    masterFieldList.insert("Politician","Acting");
    masterFieldList.insert("Politician","Career/Politician");
    masterFieldList.insert("Politician","Leadership");
    masterFieldList.insert("Politician","Negotiation");
    masterFieldList.insert("Politician","Protocol/Affiliation");

    // Scientist
    masterFieldList.insert("Scientist","Career/Scientist");
    masterFieldList.insert("Scientist","Computers");
    masterFieldList.insert("Scientist","Interests/Any");
    masterFieldList.insert("Scientist","Investigation");
    masterFieldList.insert("Scientist","Perception");
    masterFieldList.insert("Scientist","Science/Any");
    masterFieldList.insert("Scientist","Training");

    // Technician - Aerospace
    masterFieldList.insert("Technician - Aerospace","Computers");
    masterFieldList.insert("Technician - Aerospace","Technician/Aeronautics");
    masterFieldList.insert("Technician - Aerospace","Technician/Nuclear");
    masterFieldList.insert("Technician - Aerospace","Technician/Jets");
    masterFieldList.insert("Technician - Aerospace","Zero-G Operations");

    // Technician - Civilian
    masterFieldList.insert("Technician - Civilian","Appraisal");
    masterFieldList.insert("Technician - Civilian","Career/Technician");
    masterFieldList.insert("Technician - Civilian","Technician/Electronic");
    masterFieldList.insert("Technician - Civilian","Technician/Mechanical");
    masterFieldList.insert("Technician - Civilian","Technician/Nuclear");

    // Technician - Mech
    masterFieldList.insert("Technician - Mech","Technician/Electronic");
    masterFieldList.insert("Technician - Mech","Technician/Jets");
    masterFieldList.insert("Technician - Mech","Technician/Mechanical");
    masterFieldList.insert("Technician - Mech","Technician/Myomer");
    masterFieldList.insert("Technician - Mech","Technician/Nuclear");

    // Technician – Vehicle
    masterFieldList.insert("Technician - Vehicle","Computers");
    masterFieldList.insert("Technician - Vehicle","Technician/Electronic");
    masterFieldList.insert("Technician - Vehicle","Technician/Mechanical");
    masterFieldList.insert("Technician - Vehicle","Technician/Nuclear");

    //// INTELLIGENCE/POLICE FIELDS

    // Analysis
    masterFieldList.insert("Analysis","Computers");
    masterFieldList.insert("Analysis","Investigation");
    masterFieldList.insert("Analysis","Language/Any");
    masterFieldList.insert("Analysis","Language/Any");
    masterFieldList.insert("Analysis","Sensor Operations");
    masterFieldList.insert("Analysis","Strategy");
    masterFieldList.insert("Analysis","Tactics/Any");

    // Covert Operations
    masterFieldList.insert("Covert Operations","Acting");
    masterFieldList.insert("Covert Operations","Escape Artist");
    masterFieldList.insert("Covert Operations","Language/Any");
    masterFieldList.insert("Covert Operations","Perception");
    masterFieldList.insert("Covert Operations","Protocol/Any");
    masterFieldList.insert("Covert Operations","Streetwise/Any");
    masterFieldList.insert("Covert Operations","Tracking/Any");

    // Detective
    masterFieldList.insert("Detective","Career/Detective");
    masterFieldList.insert("Detective","Computers");
    masterFieldList.insert("Detective","Interrogation");
    masterFieldList.insert("Detective","Investigation");
    masterFieldList.insert("Detective","Perception");
    masterFieldList.insert("Detective","Security Systems");
    masterFieldList.insert("Detective","Streetwise/Affiliation");

    // Intelligence
    masterFieldList.insert("Intelligence","Communications/Conventional");
    masterFieldList.insert("Intelligence","Computers");
    masterFieldList.insert("Intelligence","Cryptography");
    masterFieldList.insert("Intelligence","Language/Any");
    masterFieldList.insert("Intelligence","Sensor Operations");

    // Police Officer
    masterFieldList.insert("Police Officer","Acting");
    masterFieldList.insert("Police Officer","Career/Police");
    masterFieldList.insert("Police Officer","Driving/Any");
    masterFieldList.insert("Police Officer","Martial Arts");
    masterFieldList.insert("Police Officer","MedTech");
    masterFieldList.insert("Police Officer","Small Arms");
    masterFieldList.insert("Police Officer","Streetwise/Affiliation");

    // Police Tactical Officer
    masterFieldList.insert("Police Tactical Officer","Climbing");
    masterFieldList.insert("Police Tactical Officer","Demolitions");
    masterFieldList.insert("Police Tactical Officer","Running");
    masterFieldList.insert("Police Tactical Officer","Support Weapons");
    masterFieldList.insert("Police Tactical Officer","Tactics/Infantry");
    masterFieldList.insert("Police Tactical Officer","Thrown Weapons");
    masterFieldList.insert("Police Tactical Officer","Tracking/Urban");

    // Basic Training
    masterFieldList.insert("Basic Training","Career/Soldier");
    masterFieldList.insert("Basic Training","Martial Arts");
    masterFieldList.insert("Basic Training","MedTech");
    masterFieldList.insert("Basic Training","Navigation/Ground");
    masterFieldList.insert("Basic Training","Small Arms");

    // Basic Training (Naval)
    masterFieldList.insert("Basic Training (Naval)","Career/Pilot or Ship's Crew");
    masterFieldList.insert("Basic Training (Naval)","Martial Arts");
    masterFieldList.insert("Basic Training (Naval)","MedTech");
    masterFieldList.insert("Basic Training (Naval)","Navigation/Space");
    masterFieldList.insert("Basic Training (Naval)","Small Arms");
    masterFieldList.insert("Basic Training (Naval)","Zero-G Operations");

    // Cavalry
    masterFieldList.insert("Cavalry","Artillery");
    masterFieldList.insert("Cavalry","Driving/Any");
    masterFieldList.insert("Cavalry","Gunnery/Any Vehicle");
    masterFieldList.insert("Cavalry","Sensor Operations");
    masterFieldList.insert("Cavalry","Tactics/Land or Sea");
    masterFieldList.insert("Cavalry","Technician/Mechanical");

    // Infantry
    masterFieldList.insert("Infantry","Acrobatics/Free-Fall");
    masterFieldList.insert("Infantry","Artillery");
    masterFieldList.insert("Infantry","Climbing");
    masterFieldList.insert("Infantry","Communications/Conventional");
    masterFieldList.insert("Infantry","Support Weapons");
    masterFieldList.insert("Infantry","Tactics/Infantry");

    // Infantry - Anti-'Mech
    masterFieldList.insert("Infantry - Anti-'Mech","Acrobatics/Gymnastics");
    masterFieldList.insert("Infantry - Anti-'Mech","Demolitions");
    masterFieldList.insert("Infantry - Anti-'Mech","Perception");
    masterFieldList.insert("Infantry - Anti-'Mech","Security Systems/Electronic");
    masterFieldList.insert("Infantry - Anti-'Mech","Technician/Mechanical");
    masterFieldList.insert("Infantry - Anti-'Mech","Technician/Myomer");

    // Marine
    masterFieldList.insert("Marine","Acrobatics/Free-Fall");
    masterFieldList.insert("Marine","Demolitions");
    masterFieldList.insert("Marine","Gunnery/Spacecraft");
    masterFieldList.insert("Marine","Communications/Conventional");
    masterFieldList.insert("Marine","Security Systems/Any");
    masterFieldList.insert("Marine","Zero-G Operations");

    // MechWarrior
    masterFieldList.insert("MechWarrior","Gunnery/`Mech");
    masterFieldList.insert("MechWarrior","Piloting/`Mech");
    masterFieldList.insert("MechWarrior","Sensor Operations");
    masterFieldList.insert("MechWarrior","Tactics/Land");
    masterFieldList.insert("MechWarrior","Technician/Any");


    // Military Scientist
    masterFieldList.insert("Military Scientist","Career/Military Scientist");
    masterFieldList.insert("Military Scientist","Computers");
    masterFieldList.insert("Military Scientist","Cryptography");
    masterFieldList.insert("Military Scientist","Interests/Military History");
    masterFieldList.insert("Military Scientist","Strategy");
    masterFieldList.insert("Military Scientist","Tactics/Any");

    // Officer
    masterFieldList.insert("Officer","Administration");
    masterFieldList.insert("Officer","Leadership");
    masterFieldList.insert("Officer","Melee Weapons");
    masterFieldList.insert("Officer","Protocol/Affiliation");
    masterFieldList.insert("Officer","Training");

    // Pilot - Aerospace (Combat)
    masterFieldList.insert("Pilot - Aerospace (Combat)","Gunnery/Aerospace");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Navigation/Air");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Navigation/Space");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Piloting/Aerospace");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Sensor Operations");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Tactics/Space");
    masterFieldList.insert("Pilot - Aerospace (Combat)","Zero-G Operations");

    // Pilot - Aircraft (Combat)
    masterFieldList.insert("Pilot - Aircraft (Combat)","Gunnery/Air Vehicle");
    masterFieldList.insert("Pilot - Aircraft (Combat)","Navigation/Air");
    masterFieldList.insert("Pilot - Aircraft (Combat)","Piloting/Air Vehicle");
    masterFieldList.insert("Pilot - Aircraft (Combat)","Sensor Operations");
    masterFieldList.insert("Pilot - Aircraft (Combat)","Tactics/Air");

    // Pilot - Battle Armor
    masterFieldList.insert("Pilot - Battle Armor","Climbing");
    masterFieldList.insert("Pilot - Battle Armor","Gunnery/Battlesuit");
    masterFieldList.insert("Pilot - Battle Armor","Martial Arts");
    masterFieldList.insert("Pilot - Battle Armor","Piloting/Battlesuit");
    masterFieldList.insert("Pilot - Battle Armor","Sensor Operations");
    masterFieldList.insert("Pilot - Battle Armor","Tactics/Land");

    // Pilot - WarShip
    masterFieldList.insert("Pilot - WarShip","Computers");
    masterFieldList.insert("Pilot - WarShip","Leadership");
    masterFieldList.insert("Pilot - WarShip","Navigation/K-F Jump");
    masterFieldList.insert("Pilot - WarShip","Navigation/Space");
    masterFieldList.insert("Pilot - WarShip","Protocol/Affiliation");
    masterFieldList.insert("Pilot - WarShip","Strategy");
    masterFieldList.insert("Pilot - WarShip","Tactics/Space");

    // Scout
    masterFieldList.insert("Scout","Communications/Conventional");
    masterFieldList.insert("Scout","Disguise");
    masterFieldList.insert("Scout","Language/Any");
    masterFieldList.insert("Scout","Security Systems/Any");
    masterFieldList.insert("Scout","Stealth");
    masterFieldList.insert("Scout","Streetwise/Any");
    masterFieldList.insert("Scout","Tracking/Any");

    // Ship's Crew
    masterFieldList.insert("Ship's Crew","Career/Ship's Crew");
    masterFieldList.insert("Ship's Crew","Computers");
    masterFieldList.insert("Ship's Crew","Gunnery/Spacecraft");
    masterFieldList.insert("Ship's Crew","Technician/Any");
    masterFieldList.insert("Ship's Crew","Zero-G Operations");

    // Special Forces
    masterFieldList.insert("Special Forces","Acrobatics/Free-Fall");
    masterFieldList.insert("Special Forces","Demolitions");
    masterFieldList.insert("Special Forces","Small Arms");
    masterFieldList.insert("Special Forces","Stealth");
    masterFieldList.insert("Special Forces","Survival/Any");
    masterFieldList.insert("Special Forces","Tracking/Any");

    // Technician - Military
    masterFieldList.insert("Technician - Military","Appraisal");
    masterFieldList.insert("Technician - Military","Career/Technician");
    masterFieldList.insert("Technician - Military","Technician/Electronics");
    masterFieldList.insert("Technician - Military","Technician/Mechanical");
    masterFieldList.insert("Technician - Military","Technician/Nuclear");
    masterFieldList.insert("Technician - Military","Technician/Weapons");


    //// CLAN MILITARY SKILL FIELDS

    // Clan Aerospace Warrior
    masterFieldList.insert("Clan Aerospace Warrior","Gunnery/Aerospace");
    masterFieldList.insert("Clan Aerospace Warrior","Navigation/Space");
    masterFieldList.insert("Clan Aerospace Warrior","Piloting/Aerospace");
    masterFieldList.insert("Clan Aerospace Warrior","Sensor Operations");
    masterFieldList.insert("Clan Aerospace Warrior","Tactics/Space");

    // Clan Basic Training
    masterFieldList.insert("Clan Basic Training","Martial Arts");
    masterFieldList.insert("Clan Basic Training","MedTech");
    masterFieldList.insert("Clan Basic Training","Melee Weapons");
    masterFieldList.insert("Clan Basic Training","Navigation/Ground");
    masterFieldList.insert("Clan Basic Training","Protocol/Affiliation");
    masterFieldList.insert("Clan Basic Training","Small Arms");

    // Clan Cavalry
    masterFieldList.insert("Clan Cavalry","Artillery");
    masterFieldList.insert("Clan Cavalry","Driving/Any (or Piloting/Air Vehicle)");
    masterFieldList.insert("Clan Cavalry","Gunnery/Land, Sea, or Air Vehicle");
    masterFieldList.insert("Clan Cavalry","Sensor Operations");
    masterFieldList.insert("Clan Cavalry","Tactics/Land (or Air)");

    // Clan Elemental
    masterFieldList.insert("Clan Elemental","Climbing");
    masterFieldList.insert("Clan Elemental","Gunnery/Battlesuit)");
    masterFieldList.insert("Clan Elemental","Melee Weapons");
    masterFieldList.insert("Clan Elemental","Piloting/Battlesuit");
    masterFieldList.insert("Clan Elemental","Sensor Operations");
    masterFieldList.insert("Clan Elemental","Small Arms");
    masterFieldList.insert("Clan Elemental","Tactics/Infantry");

    // Clan MechWarrior
    masterFieldList.insert("Clan MechWarrior","Gunnery/`Mech");
    masterFieldList.insert("Clan MechWarrior","Leadership)");
    masterFieldList.insert("Clan MechWarrior","Navigation/Ground");
    masterFieldList.insert("Clan MechWarrior","Piloting/'Mech");
    masterFieldList.insert("Clan MechWarrior","Sensor Operations");
    masterFieldList.insert("Clan MechWarrior","Tactics/Land");

    // Clan ProtoMech Warrior
    masterFieldList.insert("Clan ProtoMech Warrior","Gunnery/ProtoMech");
    masterFieldList.insert("Clan ProtoMech Warrior","Navigation/Ground)");
    masterFieldList.insert("Clan ProtoMech Warrior","Piloting/ProtoMech");
    masterFieldList.insert("Clan ProtoMech Warrior","Sensor Operations");
    masterFieldList.insert("Clan ProtoMech Warrior","Tactics/Land");
}


QStringList CarierFields::FieldDialSearch(QString nameAny) {

    QStringList listAnySkills;

    if (nameAny.contains("Interests/History (Any one culture)") == true) {
        listAnySkills << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Clan History" << "Interests/Star League History" << "Interests/Terran History";
    }

    if (nameAny.contains("Language/Any") == true) {
        listAnySkills << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
    }

    if (nameAny.contains("Protocol/Any") == true) {
        listAnySkills << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
    }

    if (nameAny.contains("Interests/History (any)") == true) {
        listAnySkills << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Clan History" << "Interests/Star League History" << "Interests/Terran History" << "Interests/History";
    }

    if (nameAny.contains("Surgery/Any") == true) {
        listAnySkills << "General" << "Veterinary";
    }

    if (nameAny.contains("Technician/Any") == true) {
        listAnySkills << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
    }

    if (nameAny.contains("Career/Any") == true) {
        listAnySkills << "Career/Anthropologist" << "Career/Archaeologist" << "Career/Cartographer" << "Career/Communications" << "Career/Doctor" << "Career/Engineer" << "Career/Journalist" << "Career/Lawyer" << "Career/Management" << "Career/Medtech" << "Career/Merchant" << "Career/Merchant Marine" << "Career/Aerospace Pilot" << "Career/Aircraft Pilot" << "Career/DropShip Pilot" << "Career/Politician" << "Career/Scientist" << "Career/Technician" << "Career/Detective" << "Career/Soldier" << "Career/Pilot" << "Career/Ship’s Crew" << "Career/Military Scientist";
    }

    if (nameAny.contains("Streetwise/Any") == true) {
        listAnySkills << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
    }

    if (nameAny.contains("Driving/Any") == true) {
        listAnySkills << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
    }

    if (nameAny.contains("Survival/Any") == true) {
        listAnySkills << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
    }

    if (nameAny.contains("Tracking/Any") == true) {
        listAnySkills << "Tracking/Urban" << "Tracking/Wilds";
    }

    if (nameAny.contains("Career/Pilot or Ship's Crew") == true) {
        listAnySkills << "Career/Pilot" << "Career/Ship's Crew";
    }

    if (nameAny.contains("Tactics/Land or Sea") == true) {
        listAnySkills << "Tactics/Land" << "Tactics/Sea";
    }

    if (nameAny.contains("Gunnery/Any Vehicle") == true) {
        listAnySkills << "Gunnery/Air Vehicle" << "Gunnery/Ground Vehicle" << "Gunnery/Sea Vehicle";
    }

    if (nameAny.contains("Security Systems/Any") == true) {
        listAnySkills << "Security Systems/Electronic" << "Security Systems/Mechanical";
    }

    if (nameAny.contains("Tactics/Any") == true) {
        listAnySkills << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
    }

    if (nameAny.contains("Interests/Any") == true) {
        listAnySkills << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
    }

    if (nameAny.contains("Science/Any") == true) {
        listAnySkills << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
    }


    return listAnySkills;
}
