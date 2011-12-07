#include "stage2_resurce.h"
#include <QtGui>

Stage2::Stage2(QWidget *parent) :
    QWidget(parent)
{
    s2Attr.clear();
    s2Traits.clear();
    s2Skills.clear();
    s2XpCost = 0;
    s2FlexXP = 0;
    s2ChildHoodSkills1 = 0;
    s2ChildHoodTraits1 = 0;
    s2ChildHoodSkills2 = 0;
    s2ChildHoodTraits2 = 0;
    s2ChildHoodSkills3 = 0;
    s2ChildHoodTraits3 = 0;

    // << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation/Ground" << "Protocol/Affiliation" << "Small Arms";

}

QStringList Stage2::CreateSubSkillList(QString nameSkill) {
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

// << "Adolescent Warfare" << "Back Woods" << "Clan Apprenticeship" << "Farm" << "Freeborn Sibko" << "High School"
//         << "Mercenary Brat" << "Military School" << "Preparatory School" << "Spacer Family" << "Street" << "Trueborn Sibko"
//          << "Civilian Job";

QStringList Stage2::S2ChoiceLateChildHood(int affVar) {
    switch(affVar) {
    case 0:
        s2LateChildHoodList << "Adolescent Warfare" << "Back Woods" << "Clan Apprenticeship" << "Farm" << "Freeborn Sibko"
                << "High School" << "Mercenary Brat" << "Preparatory School" << "Spacer Family" << "Street"
                << "Trueborn Sibko" << "Civilian Job" << "Military School";
        break;
    case 1:
        s2LateChildHoodList << "Adolescent Warfare" << "Back Woods" << "Clan Apprenticeship" << "Farm" << "Freeborn Sibko"
                << "High School" << "Mercenary Brat" << "Preparatory School" << "Spacer Family" << "Street"
                << "Trueborn Sibko" << "Civilian Job" << "Military School";
        break;
    case 6:
        s2LateChildHoodList << "Adolescent Warfare" << "Back Woods" << "Clan Apprenticeship" << "Farm" << "Freeborn Sibko"
                << "High School" << "Mercenary Brat" << "Spacer Family" << "Street"
                << "Trueborn Sibko";
        break;
    default:
        s2LateChildHoodList << "Adolescent Warfare" << "Back Woods" << "Clan Apprenticeship" << "Farm" << "Freeborn Sibko"
                << "High School" << "Mercenary Brat" << "Preparatory School" << "Spacer Family" << "Street"
                << "Trueborn Sibko" << "Military School";
        break;
    }


    return s2LateChildHoodList;
}


QStringList Stage2::S2HardElemAffil(QList<QPair<QString, int> > charTraits, int affVar, int subAffVar) {
    bool tmpChek = false;
    QStringList tmpList;
    QStringList swpTmpList;
    tmpList.clear();
    switch(affVar) {
    case 1:
        for (int i =0; i < charTraits.count(); ++i) {
            if (charTraits[i].first == "Citizenship/Inner Sphere" || charTraits[i].first == "Citizenship/Clan") {
                tmpChek = true;
            }
        }

        if ( tmpChek == true) {
            tmpList << S2ChoiceLateChildHood(affVar);  
        } else {
            tmpList << S2ChoiceLateChildHood(affVar);
            tmpList.removeAt(12);
        }
        break;
    case 6:
        if(subAffVar == 1) {
            tmpList << S2ChoiceLateChildHood(affVar);
            tmpList.removeAt(12);
        } else {
            tmpList << S2ChoiceLateChildHood(affVar);
        }

        break;
    case 7:
        if (subAffVar == 3 ) {
            for (int i =0; i < charTraits.count(); ++i) {
                if (charTraits[i].first == "Citizenship/Inner Sphere" || charTraits[i].first == "Citizenship/Clan") {
                    tmpChek = true;
                }
            }

            if ( tmpChek == true) {
                tmpList << S2ChoiceLateChildHood(affVar);
            } else {
                tmpList << S2ChoiceLateChildHood(affVar);
                tmpList.removeAt(11);
                tmpList.removeAt(7);
            }
        } else {
            tmpList << S2ChoiceLateChildHood(affVar);
        }
        break;
   case 8:
        if(subAffVar == 4) {
            tmpList << S2ChoiceLateChildHood(affVar);
            tmpList.removeAt(11);
            tmpList.removeAt(7);
        } else {
            tmpList << S2ChoiceLateChildHood(affVar);
        }
        break;
    default:
        tmpList << S2ChoiceLateChildHood(affVar);
        break;
    }

    swpTmpList = tmpList;
    tmpChek = false;

    for (int i =0; i < charTraits.count(); ++i) {
        if (charTraits[i].first == "Illiterate") {
           tmpChek = true;
        }
    }


    if (tmpChek == true ) {
        tmpList.clear();
        for (int j = 0; j < swpTmpList.count(); j++) {
            if ( swpTmpList[j] != "High School" ) {
                tmpList << swpTmpList[j];
            }
        }

        swpTmpList = tmpList;
        tmpList.clear();
        for (int j = 0; j < swpTmpList.count(); j++) {
            if ( swpTmpList[j] != "Preparatory School") {
                tmpList << swpTmpList[j];
            }
        }
    }


    return  tmpList;
}

QStringList Stage2::S2ClearListElem(QStringList listElem, QString nameStage1, int affVar) {
    QStringList tmpList;
    QStringList swpTmpList;
    swpTmpList = tmpList;

    switch(affVar) {
    case 9:
        for(int i = 0; i < listElem.count(); i++) {
            if (listElem[i] != "High School") {
                tmpList << listElem[i];
            }
        }
        break;
    case 10:
        for(int i = 0; i < listElem.count(); i++) {
            if (listElem[i] != "High School") {
                tmpList << listElem[i];
            }
        }
        break;
    default:   
        for(int i = 0; i < listElem.count(); i++) {
            if (listElem[i] != "Clan Apprenticeship") {
                tmpList << listElem[i];
            }
        }
        swpTmpList = tmpList;
        tmpList.clear();

        for(int i = 0; i < swpTmpList.count(); i++) {
            if (swpTmpList[i] != "Trueborn Sibko") {
                tmpList << swpTmpList[i];
            }
        }

        swpTmpList = tmpList;
        tmpList.clear();

        for(int i = 0; i < swpTmpList.count(); i++) {
            if (swpTmpList[i] != "Freeborn Sibko") {
                tmpList << swpTmpList[i];
            }
        }

        break;
    }


    swpTmpList = tmpList;
    if (nameStage1 == "Nobility" || nameStage1 == "Trueborn Creche") {
        tmpList.clear();
        for(int i = 0; i < swpTmpList.count(); i++) {
            if (swpTmpList[i] != "Adolescent Warfare") {
                tmpList << swpTmpList[i];

            }
        }
    }

    swpTmpList = tmpList;
    if (nameStage1 == "Back Woods" || nameStage1 == "Fugitives") {
        tmpList.clear();
        for(int i = 0; i < swpTmpList.count(); i++) {
            if (swpTmpList[i] != "Preparatory School") {
                tmpList << swpTmpList[i];
            }
        }
    }

    return tmpList;
}


void Stage2::S2AddTraits(QString str , int count) {
    s2Traits.append(qMakePair(str,count));
}

void Stage2::S2AddSkills(QString str , int count) {
    s2Skills.append(qMakePair(str,count));
}

void Stage2::S2LateChildhood(QString nameLChild, QString casteName) {

    s2AffLang = 0;
    s2AffProt = 0;
    s2AffStreet = 0;

    s2CountElem2 = 0;

    s2ChildHoodSkills1 = 0;
    s2ChildHoodTraits1 = 0;
    s2ChildHoodSkills2 = 0;
    s2ChildHoodTraits2 = 0;
    s2ChildHoodSkills3 = 0;
    s2ChildHoodTraits3 = 0;
    s2ChildHoodAttr1.clear();
    s2ChildHoodAttr2.clear();
    s2ChildHoodAttr3.clear();

    s2ChildHoodLabelAdv1.clear();
    s2ChildHoodAttrAdv1.clear();
    s2ChildHoodSkillsAdv1 = 0;
    s2ChildHoodTraitsAdv1 = 0;

    s2ChildHoodLabelAdv2.clear();
    s2ChildHoodAttrAdv2.clear();
    s2ChildHoodSkillsAdv2 = 0;
    s2ChildHoodTraitsAdv2 = 0;

    s2ChildHoodLabelAdv3.clear();
    s2ChildHoodAttrAdv3.clear();
    s2ChildHoodSkillsAdv3 = 0;
    s2ChildHoodTraitsAdv3 = 0;

    s2ChildHoodLabelAdv4.clear();
    s2ChildHoodAttrAdv4.clear();
    s2ChildHoodSkillsAdv4 = 0;
    s2ChildHoodTraitsAdv4 = 0;

    s2AdvSwpTraits.clear();
    s2AdvSwpTraitsInt = 0;
    s2AdvSwpSkills.clear();
    s2AdvSwpSkillsInt = 0;

    s2SwpAttr.clear();
    s2SwpTraits.clear();
    s2SwpSkills.clear();

    s2PreAttr.clear();
    s2PreTraits.clear();
    s2PreSkills.clear();

    QString swpstr;


    if( nameLChild == "Adolescent Warfare") {

        s2toolTip = "Whether on the mean streets of a gang-ruled town or a war-\nravaged world on some Great House's front line, a character\nwho spends more teenage years carrying a gun or a knife than\nschool books lives the life of an adolescent warrior.\nPrerequisites:Any Stage 1 module except Nobility and Trueborn Creche";

        s2XpCost = 500;
        s2FlexXP = 130;

        s2Attr["BOD"] = 40;
        s2Attr["RFL"] = 40;
        s2Attr["WIL"] = 50;
        s2Attr["INT"] = -30;

        S2AddTraits("Combat Sense",80);
        S2AddTraits("Connections",30);
        S2AddTraits("Compulsion/Paranoid", -20);
        S2AddTraits("Enemy", -40);
        S2AddTraits("Wealth", -20);

        s2AffLang = -25;
        s2AffProt = -10;
        s2AffStreet = 45;

        S2AddSkills("Leadership",25);
        S2AddSkills("MedTech",25);
        S2AddSkills("Melee Weapons",25);
        S2AddSkills("Negotiation",15);
        S2AddSkills("Perception",25);
        S2AddSkills("Running",40);
        S2AddSkills("Small Arms",20);
        S2AddSkills("Stealth", 30);


//        S2AddSkills("Survival/Any", 25); // SEE RULEZ!!!

        s2ChildHoodLabel1 = "Survival/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s2ChildHoodSkills1 = 25;


    }

    if( nameLChild == "Back Woods") {
        s2toolTip = "Isolated from the conveniences of modern society, a\nback woods teenager lives a survivalist's life, but tends to\nfind interacting with so-called normal society a far greater\nchallenge than any danger on the fringes of human space.\nPrerequisites: None";

        s2XpCost = 500;
        s2FlexXP = 125;

        s2Attr["BOD"] = 60;
        s2Attr["WIL"] = 70;
        s2Attr["INT"] = -20;


        S2AddTraits("Animal Empathy",80);
        S2AddTraits("Good Hearing", 40);
        S2AddTraits("Introvert", -20);
        S2AddTraits("Wealth", -20);

        s2AffProt = -15;

        S2AddSkills("Climbing", 30);
        S2AddSkills("MedTech", 20);
        S2AddSkills("Melee Weapons", 20);
        S2AddSkills("Perception", 45);
        S2AddSkills("Small Arms", 20);
        S2AddSkills("Stealth", 40);
        S2AddSkills("Survival/Forests", 25);
        S2AddSkills("Tracking/Wilds", 30);

    }

    if( nameLChild == "Clan Apprenticeship") {
        s2toolTip = "While warriors in Clan society endure a fierce training\nprotocol almost from birth, those relegated to the lower\ncastes spend their teenage years apprenticed to masters of\ntheir designated trades.\nPrerequisites:Clan affiliation, BOD 4+(Laborer Caste), CHA 4+(Merchant  Caste),\nINT 4+(Scientist Caste), DEX 4+(Technician Caste)";

        s2XpCost = 500;
        s2FlexXP = 165;

        S2AddSkills("Administration", 35);
//        S2AddSkills("Computers/Any", 50); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Computers/Any";
        s2ChildHoodAttr1 << "Computers/Programing" << "Computers/Hacking";
        s2ChildHoodSkills1 = 50;

//        S2AddSkills("Interests/Any", 30); // SEE RULEZ!!

        s2ChildHoodLabel2 = "Interests/Any";
        s2ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills2 = 30;

        S2AddSkills("Interests/Clan History", 30);

        if (casteName == "Laborer Caste") {
            s2Attr["BOD"] = 30;

//            S2AddSkills("Career/Any", 50); // SEE RULEZ!!

            s2ChildHoodLabelAdv1 = "Career/Any";
            s2ChildHoodAttrAdv1 = CreateSubSkillList("Career");//  << "Career/Ship's Crew" << "Career/Mining" << "Career/Accountant" << "Career/Cook" << "Career/Doctor" << "Career/Soldier";
            s2ChildHoodSkillsAdv1 = 50;

//            S2AddSkills("Computers/Any", 40); // SEE RULEZ!!

            s2ChildHoodLabel3 = "Computers/Any";
            s2ChildHoodAttr3 << "Computers/Programing" << "Computers/Hacking";
            s2ChildHoodSkills3 = 40;

            S2AddSkills("Driving/Ground Vehicle", 20);
            s2PreAttr["BOD"] = 400;
        }

        if (casteName == "Merchant Caste") {
            s2Attr["CHA"] = 30;

            S2AddSkills("Administration", 50);
            S2AddSkills("Appraisal", 40);
            S2AddSkills("Negotiation", 20);

            s2PreAttr["CHA"] = 400;
        }

        if (casteName == "Scientist Caste") {
            s2Attr["INT"] = 30;

//            S2AddSkills("Computers/Any", 30); // SEE RULEZ!!

            s2ChildHoodLabel3 = "Computers/Any";
            s2ChildHoodAttr3 << "Computers/Programing" << "Computers/Hacking";
            s2ChildHoodSkills3 = 30;

//            S2AddSkills("Interests/Any", 10); // SEE RULEZ!!

            s2ChildHoodLabelAdv1 = "Interests/Any";
            s2ChildHoodAttrAdv1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s2ChildHoodSkillsAdv1 = 10;

            S2AddSkills("MedTech", 20);
//            S2AddSkills("Science/Any", 50); // SEE RULEZ!!

            s2ChildHoodLabelAdv2 = "Science/Any";
            s2ChildHoodAttrAdv2 = CreateSubSkillList("Science");// << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
            s2ChildHoodSkillsAdv2 = 50;

            s2PreAttr["INT"] = 400;
        }

        if (casteName == "Technician Caste") {
            s2Attr["DEX"] = 30;

//            S2AddSkills("Computers/Any", 30); // SEE RULEZ!!

            s2ChildHoodLabel3 = "Computers/Any";
            s2ChildHoodAttr3 << "Computers/Programing" << "Computers/Hacking";
            s2ChildHoodSkills3 = 30;

            S2AddSkills("Perception", 20);
//            S2AddSkills("Technician/Any", 60); // SEE RULEZ!!

            s2ChildHoodLabelAdv1 = "Technician/Any";
            s2ChildHoodAttrAdv1 = CreateSubSkillList("Technician");//  << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s2ChildHoodSkillsAdv1 = 30;

            s2ChildHoodLabelAdv2 = "Technician/Any";
            s2ChildHoodAttrAdv2 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s2ChildHoodSkillsAdv2 = 15;

            s2ChildHoodLabelAdv3 = "Technician/Any";
            s2ChildHoodAttrAdv3 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s2ChildHoodSkillsAdv3 = 15;

            s2PreAttr["DEX"] = 400;
        }

    }

    if( nameLChild == "Farm") {
        s2toolTip = "The character that spends his teenage years on a farm\nlearns a host of skills invaluable to one of the Inner Sphere's\nmost vaunted civilian professions.\nPrerequisites: None";

        s2XpCost = 400;
        s2FlexXP = 115;

        s2Attr["DEX"] = 40;
        s2Attr["CHA"] = -20;

        S2AddTraits("Animal Empathy", 30);

        S2AddSkills("Administration", 35);
        S2AddSkills("Animal Handling", 30);
        S2AddSkills("Career/Agriculture", 50);
        S2AddSkills("Driving/Ground Vehicle", 30);
//        S2AddSkills("Interests/Any", 60); // SEE RULEZ!!
        S2AddSkills("Small Arms", 30);

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 40;

        s2ChildHoodLabel2 = "Interests/Any";
        s2ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills2 = 20;

    }

    if( nameLChild == "Freeborn Sibko") {
        s2toolTip = "Though lacking the sophistication and intensity of the\ntrueborn military regimen, the training cycle for aspiring Clan\nwarriors born outside the iron wombs can be just as brutal in\nmany ways.\nPrerequisites:Clan affiliation; BOD 3+, DEX 4+, RFL 3+, WIL 4+;\nmust select a Clan-affiliated Stage 4 module next.";

        s2XpCost = 950;
        s2FlexXP = 0; // SEE RULEZ!!

        s2Attr["BOD"] = 50;
        s2Attr["WIL"] = 50;
        s2Attr["CHA"] = -30;

        S2AddTraits("Compulsion/Clan Honor", -30);
        S2AddTraits("Rank", 100);
        S2AddTraits("Reputation", 40);

        S2AddSkills("Career/Soldier", 50);
        S2AddSkills("Interests/Clan Remembrance", 20);
        S2AddSkills("Negotiation", 50);
//        S2AddSkills("Clan Basic Training", 50); // SEE RULEZ!!

        s2PreAttr["BOD"] = 300;
        s2PreAttr["DEX"] = 400;
        s2PreAttr["RFL"] = 300;
        s2PreAttr["WIL"] = 400;
    }

    if( nameLChild == "High School") {
        s2toolTip = "Common across the Inner Sphere and Periphery-though\nhardly universal, as different worlds and social classes face different\nneeds-the academic life is typical for most teenagers, preparing\nthem for future careers in the modern work force, military service\nor perhaps some form of higher education.\nPrerequisites: Any non-Clan affiliation; may not have Illiterate Trai";

        s2XpCost = 400;
        s2FlexXP = 185;

        s2AffLang = 10;
        s2AffStreet = 20;

        s2Attr["CHA"] = 25;
        s2Attr["INT"] = 25;

        S2AddTraits("Connections", 20);

        S2AddSkills("Computers", 20);
//        S2AddSkills("Interests/Any", 75); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 40;

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 35;

        S2AddSkills("Swimming", 20);

    }

    if( nameLChild == "Mercenary Brat") {
        s2toolTip = "While most normal kids are in high school, the teenage\nmercenary brat is seeing more of the universe and picking up the\nskills of his family’s trade along the way as an able body between\nmissions.\nPrerequisites: None";
        s2XpCost = 600;
        s2FlexXP = 150;

        s2Attr["WIL"] = 35;
        s2Attr["EDG"] = 50;
        s2Attr["INT"] = -20;
        s2Attr["CHA"] = -20;

        S2AddTraits("Connections", 40);
        S2AddTraits("Tech Empathy", 20);

        S2AddSkills("Career/Soldier", 50);
        S2AddSkills("Driving/Ground Vehicle", 15);
        S2AddSkills("Swimming", 20);
//        S2AddSkills("Interests/Any", 50); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 30;


//        S2AddSkills("Language/Any", 50); // SEE RULEZ!!

        s2ChildHoodLabel2 = "Choose two"; // SEE RULEZ!!
        s2ChildHoodAttr2 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s2ChildHoodSkills2 = 30;

        S2AddSkills("Martial Arts", 30);
        S2AddSkills("MedTech", 10);
        S2AddSkills("Negotiation", 50);
        S2AddSkills("Perception", 30);
//        S2AddSkills("Streetwise/Any", 20); // SEE RULEZ!!
        s2ChildHoodLabel3 = "Streetwise/Any";
        s2ChildHoodAttr3 = CreateSubSkillList("Streetwise");//  << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
        s2ChildHoodSkills3 = 30;

//        S2AddSkills("Tactics/Any", 10); // SEE RULEZ!!
        s2ChildHoodLabelAdv1 = "Tactics/Any";
        s2ChildHoodAttrAdv1 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
        s2ChildHoodSkillsAdv1 = 10;

//        S2AddSkills("Technician/Any", 30); // SEE RULEZ!!
        s2ChildHoodLabelAdv2 = "Technician/Any";
        s2ChildHoodAttrAdv2 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        s2ChildHoodSkillsAdv2 = 30;

        s2ChildHoodLabelAdv3 = "Interests/Any";
        s2ChildHoodAttrAdv3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkillsAdv3 = 20;

    }

    if( nameLChild == "Military School") {
        s2toolTip = "Whether by punishment or as a matter of familial pride, the\ncharacter that spends his late childhood in military school comes\naway from the experience with a host of skills and a sense of\ndiscipline that can boost any eventual military or political career.\nPrerequisites: WIL 3+";

        s2XpCost = 500;
        s2FlexXP = 40;

        s2Attr["CHA"] = 50;

        S2AddTraits("Connections", 15);
        S2AddTraits("Fit", 15);
        S2AddTraits("Rank", 20);

        s2AffProt = 30;

        S2AddSkills("Career/Soldier", 25);
        S2AddSkills("Computers", 35);
//        S2AddSkills("Interests/Any", 30); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 30;

        S2AddSkills("Interests/Military History", 40);
        S2AddSkills("Leadership", 20);
        S2AddSkills("Martial Arts", 30);
        S2AddSkills("MedTech", 10);
        S2AddSkills("Melee Weapons", 20);
        S2AddSkills("Running", 30);
        S2AddSkills("Small Arms", 50);
        S2AddSkills("Strategy", 10);
        S2AddSkills("Swimming", 30);

        s2PreAttr["WIL"] = 300;
    }

    if( nameLChild == "Preparatory School") {
        s2toolTip = "A common alternative to high school for the children of\nwealthy parents, preparatory (\"prep\") school paves a character’s\nway to many of the Inner Sphere's most prestigious colleges and\nuniversities with an eye toward eventual influential careers in\npolitics, law, medicine and corporate management.\nPrerequisites: May not have used Back Woods or Fugitive\nStage 1 modules. May not possess the Illiterate Trait.";

        s2XpCost = 500;
        s2FlexXP = 160;

        s2Attr["CHA"] = 60;

        S2AddTraits("Connections", 40);
        S2AddTraits("Extra Income", 20);
        S2AddTraits("Gregarious", 20);

        s2AffProt = 40;

        S2AddSkills("Archery", 20);
        S2AddSkills("Computers", 25);
//        S2AddSkills("Interests/Any", 90); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 30;

        s2ChildHoodLabel2 = "Interests/Any";
        s2ChildHoodAttr2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills2 = 20;

        s2ChildHoodLabel3 = "Interests/Any";
        s2ChildHoodAttr3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills3 = 20;

//        S2AddSkills("Language/Any", 20); // SEE RULEZ!!

        s2ChildHoodLabelAdv1 = "Language/Any";
        s2ChildHoodAttrAdv1 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s2ChildHoodSkillsAdv1 = 20;

        S2AddSkills("MedTech", 10);
        S2AddSkills("Melee Weapons", 15);


    }

    if( nameLChild == "Spacer Family") {
        s2toolTip = "The child of a spacer family is raised in the low-gravity and\nsterilized-atmosphere world of DropShips and JumpShips,\nrarely setting foot on planets long enough to take root.\nCharacters from this background tend to be a little more\ninsular toward outsiders, but are in their element when out in\nthe 'black sea.'.\nPrerequisites: Cannot have the TDS Trait; RFL 4+, DEX 4+, INT 4+;\nMinimum Zero-G Operations Skill +2";

        s2XpCost = 490;
        s2FlexXP = 175;

        s2Attr["RFL"] = 40;
        s2Attr["DEX"] = 30;
        s2Attr["BOD"] = -20;
        s2Attr["STR"] = -20;

        S2AddTraits("Equipped", 20);
        S2AddTraits("G-Tolerance", 40);
        S2AddTraits("Natural Aptitude/Zero-G Operations", 20);
        S2AddTraits("Introvert", -25);

        S2AddSkills("Career/Ship's Crew", 30);
        S2AddSkills("Communications/Conventional", 20);
        S2AddSkills("Computers", 20);
        S2AddSkills("Gunnery/Spacecraft", 10);
//        S2AddSkills("Interests/Any", 15); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 15;

        S2AddSkills("Language/Any", 15); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Language/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s2ChildHoodSkills1 = 15;

        S2AddSkills("Navigation/Space", 20);
        S2AddSkills("Perception", 15);
        S2AddSkills("Piloting/Spacecraft", 15);
        S2AddSkills("Sensor Operations", 15);
        S2AddSkills("Technician/Aeronautics", 20);
        S2AddSkills("Technician/Electronic", 20);
        S2AddSkills("Zero-G Operations", 15);

        s2PreAttr["RFL"] = 400;
        s2PreAttr["DEX"] = 400;
        s2PreAttr["INT"] = 400;

        swpstr = "Zero-G Operations";
        s2PreSkills.append(qMakePair(swpstr,50));
    }

    if( nameLChild == "Street") {
        s2toolTip = "Life on the streets can get downright dangerous, particularly\nfor kids in their teens. Characters coming from this background\nhave learned to survive by identifying the gangs, evading the\nauthorities and defending themselves (or just running away)\nwhen cornered.\nPrerequisites: None";

        s2XpCost = 400;
        s2FlexXP = 60;


        s2Attr["BOD"] = 20;
        s2Attr["EDG"] = 40;
        s2Attr["WIL"] = 10;
        s2Attr["CHA"] = -20;

        S2AddTraits("Combat Sense", 15);
        S2AddTraits("Connections", 20);
        S2AddTraits("Enemy", -20);
        S2AddTraits("Illiterate", -20);
        S2AddTraits("Reputation", -20);

        s2AffStreet = 40;

        S2AddSkills("Acting", 20);
        S2AddSkills("Climbing", 15);
        S2AddSkills("Disguise", 20);
        S2AddSkills("Escape Artist", 20);
//        S2AddSkills("Interests/Any", 20); // SEE RULEZ!!
        s2ChildHoodLabel1 = "Interests/Any";
        s2ChildHoodAttr1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills1 = 20;


        S2AddSkills("Interrogation", 20);
        S2AddSkills("Martial Arts", 20);
        S2AddSkills("MedTech", 10);
        S2AddSkills("Melee Weapons", 25);
        S2AddSkills("Negotiation", 20);
        S2AddSkills("Perception", 25);
        S2AddSkills("Running", 25);
//        S2AddSkills("Scrounge", 10);
        S2AddSkills("Small Arms", 20);
        S2AddSkills("Stealth", 15);
    }

    if( nameLChild == "Trueborn Sibko") {
        s2toolTip = "The intense training regimen of the trueborn Clan warrior\nhas already begun by the time the time he leaves the creche.\nBred for combat and indoctrinated into the ways of the Clans,\nyoung trueborns undergo training at this stage that can\nliterally hone them into warriors or kill them in the process.\nPrerequisites: Clan affiliation; Aerospace, Elementa l or\nMechWarrior  Phenotype; BOD 3+, DEX 4+, RFL 3+, WIL 3+;\nProtoMech warriors may not have Combat Paralysis, Glass Jaw, \nLost Limb, Poor Hearing or Poor Vision Traits.";

//        if(phenoTip == "ProtoMech") {
//            s2XpCost = 1600;
//        } else {
//            s2XpCost = 1500;
//        }
        s2FlexXP = 0;

        s2PreAttr["BOD"] = 300;
        s2PreAttr["DEX"] = 400;
        s2PreAttr["RFL"] = 300;
        s2PreAttr["WIL"] = 300;


    }

    if( nameLChild == "Civilian Job") {
        s2toolTip = "You may not carry a weapon, or hold the fate of worlds in your\nhand, but you earn a living, and it’s honest work to boot. Whether\nyou’re a career bureaucrat, a cubicle rat, a humble store clerk or\na freight loader at the local spaceport, you are part of the vast\ninfrastructure that keeps your town and your society running-\neven if you occasionally daydream about something more…";

        s2XpCost = 600;
        s2FlexXP = 85;

        s2AffProt = 50;

        S2AddSkills("Administration", 75);
//        S2AddSkills("Career/Any Non-Military", 40); // SEE RULEZ!!

        s2ChildHoodLabel1 = "Career/Any Non-Military";
        s2ChildHoodAttr1 << "Career/Anthropologist" << "Career/Archaeologist" << "Career/Cartographer" << "Career/Communications" << "Career/Doctor" << "Career/Engineer" << "Career/Journalist" << "Career/Lawyer" << "Career/Management" << "Career/MedTech" << "Career/Merchant" << "Career/Merchant Marine" << "Career/Aerospace Pilot" << "Career/Aircraft Pilot" << "Career/DropShip Pilot" << "Career/Politician" << "Career/Scientist" << "Career/Technician";
       s2ChildHoodSkills1 = 40;

        S2AddSkills("Computers", 40);
//        S2AddSkills("Driving/Any", 60); // SEE RULEZ!!
        s2ChildHoodLabel2 = "Driving/Any";
        s2ChildHoodAttr2 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
        s2ChildHoodSkills2 = 60;

//        S2AddSkills("Interests/Any", 100);
        s2ChildHoodLabel3 = "Interests/Any";
        s2ChildHoodAttr3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s2ChildHoodSkills3 = 100;

        S2AddSkills("Leadership", 40);
        S2AddSkills("Negotiation", 30);
//        S2AddSkills("+80 total additional XP 20x4 skill", 20 ); // SEE RULEZ!!

    }
}

QStringList Stage2::S2FreebornSibko() {
    s2ChildHoodLabel1 = "Branch of service";

    s2ClanBasicXP = 180;
    s2ClanBasicStepXP = 30;
    s2ClanBasicRebateXP = 6;
    QStringList tmpList ;

    tmpList << "Aerospace" << "Cavalry" << "Elemental" << "Infantry" << "MechWarrior";
    return tmpList;
}


QStringList Stage2::S2TruebornSibko(QString nameClan) {
    s2ChildHoodLabel1 = "Branch of service";

    s2ClanBasicXP = 300;
    s2ClanBasicStepXP = 50;
    s2ClanBasicRebateXP = 10;

    QStringList tmpList ;
    if (nameClan == "Ghost Bear" || nameClan == "Hell's Horses") {
        tmpList  << "Aerospace" << "Elemental" << "Elemental (Advanced)" << "ProtoMech" << "MechWarrior";
    } else {
        if (nameClan == "Blood Spirit") {
            tmpList << "Aerospace" << "Elemental"<< "ProtoMech" << "ProtoMech (Advanced)" << "MechWarrior";
        } else {
            tmpList << "Aerospace" << "Elemental" << "ProtoMech"<< "MechWarrior";
        }
    }

    return tmpList;
}


void Stage2::S2FreebornSibkoAttr(QString nameAttr) {

    s2ClanAdvFieldList.clear();


    if (s2AdvSwpTraits.isEmpty() != true) {
        S2AddTraits(s2AdvSwpTraits, -s2AdvSwpTraitsInt);
    }

    if (s2AdvSwpSkills.isEmpty() != true) {
        S2AddSkills(s2AdvSwpSkills, -s2AdvSwpSkillsInt);
    }

    int t = s2Traits.count();
    int s = s2Skills.count();


    if (nameAttr == "Aerospace") {
        s2FlexXP = 200;
        S2AddTraits("Vehicle", 100);

        s2ClanAdvXP = 250;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Gunnery/Aerospace" << "Navigation/Space" << "Piloting/Aerospace" << "Sensor Operations" << "Tactics/Space";

    }

    if (nameAttr == "Cavalry") {
        s2FlexXP = 200;
        S2AddTraits("Vehicle", 100);

        s2ClanAdvXP = 250;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Artillery" << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles" << "Piloting/Air Vehicle" << "Gunnery/Land" << "Gunnery/Sea" << "Air Vehicle" << "Sensor Operations" << "Tactics/Land" << "Tactics/Air";
    }

    if (nameAttr == "Elemental") {
        s2FlexXP = 100;
        S2AddTraits("Vehicle", 100);

        s2ClanAdvXP = 350;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Climbing" << "Gunnery/Battlesuit" << "Melee Weapons" << "Piloting/Battlesuit" << "Sensor Operations" << "Small Arms" << "Tactics/Infantry";
    }

    if (nameAttr == "Infantry") {
        s2FlexXP = 150;
        S2AddTraits("Equipped", 100);

        s2ClanAdvXP = 300;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Acrobatics/Free-Fall" << "Artillery" << "Climbing" << "Communications/Conventional" << "Support Weapons" << "Tactics/Infantry";
    }

    if (nameAttr == "MechWarrior") {
        s2FlexXP = 150;
        S2AddTraits("Vehicle", 100);

        s2ClanAdvXP = 300;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Gunnery/Mech" << "Leadership" << "Navigation/Ground" << "Piloting/Mech" << "Sensor Operations" << "Tactics/Land";
    }


    if (t < s2Traits.count()) {
        s2AdvSwpTraits = s2Traits[s2Traits.count()-1].first;
        s2AdvSwpTraitsInt = s2Traits[s2Traits.count()-1].second;
    } else {
        s2AdvSwpTraits.clear();
        s2AdvSwpTraitsInt = 0;
    }

    if(s < s2Skills.count()) {
        s2AdvSwpSkills = s2Skills[s2Skills.count()-1].first;
        s2AdvSwpSkillsInt = s2Skills[s2Skills.count()-1].second;
    } else {
        s2AdvSwpSkills.clear();
        s2AdvSwpSkillsInt = 0;
    }

}

void Stage2::S2TruebornSibkoAttr(QString nameAttr) {

    s2Attr.clear();
    s2Traits.clear();
    s2Skills.clear();
    s2ClanAdvFieldList.clear();

    if (nameAttr == "Aerospace") {

        s2XpCost = 1600;
        s2FlexXP = 150;

        S2AddTraits("Custom Vehicle", 200);

        S2AddSkills("Gunnery/Spacecraft", 20);
        S2AddSkills("Piloting/Spacecraft", 20);
        S2AddSkills("Navigation/Air", 40);

        s2ClanAdvXP = 400;
        s2ClanAdvStepXP = 80;
        s2ClanAdvRebateXP = 16;

        s2ClanAdvFieldList << "Gunnery/Aerospace" << "Navigation/Space" << "Piloting/Aerospace" << "Sensor Operations" << "Tactics/Space";
    }

    if (nameAttr == "Elemental") {

        s2XpCost =1600;
        s2FlexXP = 150;

        S2AddTraits("Vehicle", 120);

        s2ClanAdvXP = 560;
        s2ClanAdvStepXP = 80;
        s2ClanAdvRebateXP = 16;

        s2ClanAdvFieldList << "Climbing" << "Gunnery/Battlesuit" << "Melee Weapons" << "Piloting/Battlesuit" << "Sensor Operations" << "Small Arms" << "Tactics/Infantry";
    }

    if (nameAttr == "Elemental (Advanced)") {

        s2XpCost = 1600;
        s2FlexXP = 50;

        s2Attr["CHA"] = -30;
        s2Attr["EDG"] = -30;

        S2AddTraits("Equipped", 50);
        S2AddTraits("Vehicle", 185);

        S2AddSkills("Gunnery/Battlesuit", 15);
        S2AddSkills("Piloting/Battlesuit", 10);
        S2AddSkills("Swimming", 10);
        S2AddSkills("Tactics/Infantry", 10);

        s2ClanAdvXP = 560;
        s2ClanAdvStepXP = 80;
        s2ClanAdvRebateXP = 16;

        s2ClanAdvFieldList << "Climbing" << "Gunnery/Battlesuit" << "Melee Weapons" << "Piloting/Battlesuit" << "Sensor Operations" << "Small Arms" << "Tactics/Infantry";

        s2PreAttr["BOD"] = 600;
        s2PreAttr["DEX"] = 400;
        s2PreAttr["RFL"] = 400;
        s2PreAttr["WIL"] = 400;
    }

    if (nameAttr == "ProtoMech") {
        s2XpCost = 1500;
        s2FlexXP = 190;

        S2AddTraits("Compulsion/Chemical Addiction", -100);
        S2AddTraits("Implant/EI Neural Implant", 200);
        S2AddTraits("Reputation", -100);
        S2AddTraits("Toughness", 100);
        S2AddTraits("Vehicle", 100);

        S2AddSkills("Navigation/Ground", 30);
        S2AddSkills("Tactics/Infantry", 30);
        S2AddSkills("Tactics/Land", 30);

        s2ClanAdvXP = 250;
        s2ClanAdvStepXP = 50;
        s2ClanAdvRebateXP = 10;

        s2ClanAdvFieldList << "Gunnery/ProtoMech" << "Navigation/Ground" << "Piloting/ProtoMech" << "Sensor Operations" << "Tactics/Land";

    }

    if (nameAttr == "ProtoMech (Advanced)") {

        s2XpCost = 1500;
        s2FlexXP = 15;

        S2AddTraits("Compulsion/Chemical Addiction", -100);
        S2AddTraits("Implant/EI Neural Implant", 200);
        S2AddTraits("Reputation", -100);
        S2AddTraits("Toughness", 125);
        S2AddTraits("Vehicle", 125);

        S2AddSkills("Navigation/Ground", 30);
        S2AddSkills("Tactics/Infantry", 30);
        S2AddSkills("Tactics/Land", 30);

        s2ClanAdvXP = 375;
        s2ClanAdvStepXP = 75;
        s2ClanAdvRebateXP = 15;

        s2ClanAdvFieldList << "Gunnery/ProtoMech" << "Navigation/Ground" << "Piloting/ProtoMech" << "Sensor Operations" << "Tactics/Land";
    }

    if (nameAttr == "MechWarrior") {

        s2XpCost = 1600;
        s2FlexXP = 50;

        S2AddTraits("Custom Vehicle", 200);

        S2AddSkills("Gunnery/Mech", 15);
        S2AddSkills("Piloting/BattleMech", 15);

        s2ClanAdvXP = 480;
        s2ClanAdvStepXP = 80;
        s2ClanAdvRebateXP = 16;

        s2ClanAdvFieldList << "Gunnery/Mech" << "Leadership" << "Navigation/Ground" << "Piloting/Mech" << "Sensor Operations" << "Tactics/Land";
    }


}

QStringList Stage2::S2ClanBasicFieldChange(QString nameAffil) {

    QStringList swpNameAffil;
    nameAffil = "Protocol/" + nameAffil;
    swpNameAffil << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation/Ground" << nameAffil << "Small Arms";

    return swpNameAffil;
}
