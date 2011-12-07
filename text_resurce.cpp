#include "text_resurce.h"
#include <QtGui>


Text_Resurce::Text_Resurce(QWidget *parent) :
        QWidget(parent)
{

}
QStringList Text_Resurce::CreateSubSkillList(QString nameSkill) {
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

//Устанавливаем в ComboBox SUB Affilation данные
void Text_Resurce::rSubAff(int affStrNum)
{

    allSkills << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "Medtech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
    allTraits << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "TDS" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
    affProtocol.clear();;
    subAffList.clear();
    listLang.clear();
    affAttr.clear();
    affTraits.clear();
    affSkills.clear();
    primLang.clear();
    secLang.clear();
    elem1XPAttr = 0;
    elem1XPSkills = 0;
    elem1XPTraits = 0;
    elem2XPAttr = 0;
    elem2XPSkills = 0;
    elem2XPTraits = 0;
    countElem1 = 0;
    countElem2 = 0;
    countFMAttr = 0;

    subCountElem1 = 0;
    subCountElem2 = 0;
    subCountElem3 = 0;
    subCountElem4 = 0;
    affElem1.clear();
    affElem2.clear();
    subAffElem1Label.clear();
    subAffElem2Label.clear();
    subAffElem3Label.clear();
    subAffElem4Label.clear();
    subAffElem1.clear();
    subAffElem2.clear();
    subAffElem3.clear();
    subAffElem4.clear();

    s0PreAttr.clear();
    s0PreTraits.clear();
    s0PreSkills.clear();

    QString swpstr;

    switch(affStrNum) {
        //----------------------//CAPELLAN CONFEDERATION (HOUSE LIAO)----------------------------------
    case 1:
        affProtocol = "Protocol/Capellan";
        affStreet = "Streetwise/Capellan";
        //CAPELLAN CONFEDERATION (HOUSE LIAO)
        subAffList << "None" << "Capellan Commonality" << "Liao Commonality"
                << "Sian Commonality" << "St. Ives Commonality"
                << "Victoria Commonality";
        toolTipAff = "Having suffered badly at the hands of its neighbors for\ncenturies, the Capellan Confederation has become a virtual police\nstate, its people wary of enemies within and without and devoted\nto survival at any cost. Nearly destroyed by the Steiner-Davion\noff ensive in the Fourth Succession War, the determined Capellan\npeople rallied with fanatical zeal that reached its apex with the\nascent of Chancellor Sun-Tzu Liao, whose Xin Sheng (Rebirth)\nmovement revitalized the nation and marked a resurgence of the\nancient Chinese culture that now dominates the realm.\n\n[Attributes] WIL (+50 XP)\n[Traits] Exceptional Attribute/EDG (+100 XP), Compulsion/Paranoia(-100 XP)\n[Skills] Language/Any Capellan Secondary (+10 XP), Protocol/Capellan (+10XP),\nMartial Arts (+5 XP)";
        primLang << "Language/Mandarin Chinese";
        secLang << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/English";
        listLang = primLang + secLang;
        //        listLang << "Primary     : Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/English";
        ower_Affil = "  Having suffered badly at the hands of its neighbors for centuries, the Capellan Confederation has become a virtual police state, its people wary of enemies within and without and devoted to survival at any cost. Nearly destroyed by the Steiner-Davion off ensive in the Fourth Succession War, the determined Capellan people rallied with fanatical zeal that reached its apex with the ascent of Chancellor Sun-Tzu Liao, whose Xin Sheng (Rebirth) movement revitalized the nation and marked a resurgence of the ancient Chinese culture that now dominates the realm.\n[Attributes] WIL (+50 XP)\n[Traits] Exceptional Attribute/EDG (+100 XP), Compulsion/Paranoia(-100 XP)\n[Skills] Language/Any Capellan Secondary (+10 XP), Protocol/Capellan (+10XP), Martial Arts (+5 XP)";
        xpCostModule = 150;
        //Attribute
        affAttr["WIL"] = 50;
        //Traits
        addSubTraits("Except Attribute/EDG",100);
        addSubTraits("Compulsion/Paranoia",-100);
        //Skills
        //        addSubSkills("Language/Any Capellan Secondary", 10);
        addSubSkills("Protocol/Capellan", 10);
        addSubSkills("Martial Arts", 5);
        //Elem1
        affElem1 = secLang;
        elem1XPSkills = 10;
        break;
        //----------------------//DRACONIS COMBINE (HOUSE KURITA)----------------------------------
    case 2:
        //DRACONIS COMBINE (HOUSE KURITA)
        affProtocol = "Protocol/Combine";
        affStreet = "Streetwise/Combine";
        subAffList << "None" << "Azami" << "Benjamin District"
                << "Dieron District" << "New Samarkand (Galedon) District"
                << "Pesht District";
        toolTipAff = "House Kurita's rigid society is patterned strongly on the ideals\nof feudal Japan and allows for very few exceptions. An overriding\n belief in the superiority of Combine honor and the destiny of\nKurita dominion over all has produced a society that is harsh and\ndistrustful of all gaijin (outsiders), while idolizing principles of\ndecorum and personal honor.\n\n[Attributes] WIL (+50 XP)\n[Traits] Compulsion/Xenophobia (-100 XP), Wealth (-50 XP),\nchoose one: Pain Resistance or Combat Sense (+100XP)\n[Skills] Arts/Oral Tradition (+15 XP), Martial Arts (+10 XP),\nProtocol/Combine (+15 XP)";
        primLang << "Language/Japanese";
        secLang << "Language/Arabic" << "Language/English" << "Language/Swedenese";
        listLang = primLang + secLang;
        ower_Affil = "  House Kurita's rigid society is patterned strongly on the ideals of feudal Japan and allows for very few exceptions. An overriding belief in the superiority of Combine honor and the destiny of Kurita dominion over all has produced a society that is harsh and distrustful of all gaijin (outsiders), while idolizing principles of decorum and personal honor. \n[Attributes] WIL (+50 XP)\n[Traits] Compulsion/Xenophobia (-100 XP), Wealth (-50 XP), choose one: Pain Resistance or Combat Sense (+100XP)\n[Skills] Arts/Oral Tradition (+15 XP), Martial Arts (+10 XP), Protocol/Combine (+15 XP)";
        xpCostModule = 150;
        //Attribute
        affAttr["WIL"] = 50;
        //Traits
        addSubTraits("Compulsion/Xenophobia", -100);
        addSubTraits("Wealth", -50);
        //        addSubTraits("choose one: Pain Resistance or Combat Sense", 100);
        //Skills
        addSubSkills("Art/Oral Tradition", 15);
        addSubSkills("Martial Arts", 10);
        addSubSkills("Protocol/Combine", 15);
        //Elem1
        affElem1 << "Pain Resistance" << "Combat Sense";
        elem1XPTraits = 100;
        break;
    case 0:
        //FEDERATED SUNS (HOUSE DAVION)
        affProtocol = "Protocol/FedSuns";
        affStreet = "Streetwise/FedSuns";
        subAffList << "None" << "Capellan March" << "Crucis March"
                << "Draconis March" << "Outback";
        toolTipAff = "The social and cultural structure of the Federated Suns hails\nmostly from feudal England, with additional infl uences from\nFrance and other Western European societies. Ever mindful of its\npolitical and military situation, the Suns is divided into military\nsub-states called Marches, where the threat of invasion from\nnearby realms colors everyday life. This \"border culture\" is in stark\ncontrast to the realm's more sophisticated and affl uent inner\nworlds, or the oft-neglected worlds of the Periphery Outback.\n\n[Traits] Choose Natural Aptitude/Protocol or\nNatural Aptitude/Strategy (+100 XP; see Notes below)\n[Skills] Protocol/FedSuns (+10 XP)";
        primLang << "Language/English";
        secLang << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Russian";
        listLang = primLang + secLang;
        ower_Affil = "  The social and cultural structure of the Federated Suns hails mostly from feudal England, with additional infl uences from France and other\nWestern European societies. Ever mindful of its political and military situation, the Suns is divided into military sub-states called Marches,\nwhere the threat of invasion from nearby realms colors everyday life. This \"border culture\" is in stark contrast to the realm's more sophisticated\nand affl uent inner worlds, or the oft-neglected worlds of the Periphery Outback.\n[Traits] Choose Natural Aptitude/Protocol or Natural Aptitude/Strategy (+100 XP; see Notes below)\n[Skills] Protocol/FedSuns (+10 XP)";
        xpCostModule = 150;
        //Attribute
        //none
        //Traits
        //        addSubTraits("Choose Natural Aptitude/Protocol or Natural Aptitude/Strategy", 100);
        //Skills
        addSubSkills("Protocol/FedSuns", 10);
        //elem1
        affElem1 << "Natural Aptitude/Protocol" << "Natural Aptitude/Strategy";
        elem1XPTraits = 100;

        s0PreAttr["INT"] = 400;

        break;
    case 3:
        // FREE WORLDS LEAGUE (HOUSE MARIK)
        affProtocol = "Protocol/Free Worlds";
        affStreet = "Streetwise/Free Worlds";
        subAffList << "None" << "Marik Commonwealth" << "Principality of Regulus"
                << "Duchy of Oriente" << "Duchy of Andurien"
                << "Other FWL Worlds";
        toolTipAff = "A nominal confederation of smaller states long ruled by a single\nfamily, the Free Worlds League is riven with deep divisions and a\nnightmare bureaucracy only recently brought into a semblance of\nunity centered on the capital world of Atreus. Despite numerous\ninternal confl icts, however, the League is known for its open-\nmindedness and technological savvy, as well as its curiously\ncontradictory distrust of cybernetic enhancements.\n\n[Skills] Language/Any Secondary (+15 XP), Arts/Any (+10 XP)";
        primLang << "Language/English";
        secLang << "Language/Greek" << "Language/Hindi" << "Language/Italian" << "Language/Mandarin Chinese" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Spanish" << "Language/Urdu";
        listLang = primLang + secLang;
        ower_Affil = "  A nominal confederation of smaller states long ruled by a single family, the Free Worlds League is riven with deep divisions and a nightmare bureaucracy only recently brought into a semblance of unity centered on the capital world of Atreus. Despite numerous internal conflicts, however,\nthe League is known for its open-mindedness and technological savvy, as well as its curiously contradictory distrust of cybernetic enhancements.\n[Skills] Language/Any Secondary (+15 XP), Arts/Any (+10 XP)";
        xpCostModule = 150;
        //Skills
        //        addSubSkills("Language/Any Secondary", 15);
        //        addSubSkills("Art/Any",10);
        //Elem1
        affElem1 = secLang;
        elem1XPSkills = 15;
        //Elem2
        affElem2.append(CreateSubSkillList("Art"));
        //<< "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
        elem2XPSkills = 10;
        break;
    case 4:
        // LYRAN ALLIANCE (HOUSE STEINER)
        affProtocol = "Protocol/Lyran";
        affStreet = "Streetwise/Lyran";
        subAffList << "None" << "Alarion Province" << "Bolan Province"
                << "Coventry Province" << "Donegal Province"
                << "Skye Province";
        toolTipAff = "Loosely patterned on feudal Germany, with other Western\nEuropean infl uences apparent (most notably Swiss and\nScottish), the Lyran Alliance-originally known as the Lyran\nCommonwealth-is a heavily industrialized and mercantile realm.\nMany Lyrans see warfare as a dirty business and simply aspire to\ngreat wealth or high social standing. As a result, the Lyran military\nfrequently comes off as lackluster, while Lyran merchants and\npolitical leaders seem ruthlessly sharp.\n\n[Attributes] WIL (-50 XP), EDG (-50 XP)\n[Traits]Equipped (+100 XP), Extra Income (+50 XP), Wealth (+100 XP),\nChoose either Combat Paralysis or Glass Jaw (-100 XP)\n[Skills]Negotiation (+15 XP), Appraisal (+10 XP), Protocol/Lyran (+15 XP)";
        primLang << "Language/German";
        secLang << "Language/English" << "Language/Italian" << "Language/Scots Gaelic" << "Language/Swedish";
        listLang = primLang + secLang;
        ower_Affil = "  Loosely patterned on feudal Germany, with other Western European infl uences apparent (most notably Swiss and Scottish), the Lyran Alliance-originally known as the Lyran Commonwealth-is a heavily industrialized and mercantile realm. Many Lyrans see warfare as a dirty business and simply aspire to great wealth or high social standing. As a result, the Lyran military frequently comes off as lackluster, while Lyran merchants and political leaders seem ruthlessly sharp.\n[Attributes] WIL (-50 XP), EDG (-50 XP)\n[Traits]Equipped (+100 XP), Extra Income (+50 XP), Wealth (+100 XP),Choose either Combat Paralysis or Glass Jaw (-100 XP)\n[Skills]Negotiation (+15 XP), Appraisal (+10 XP), Protocol/Lyran (+15 XP)";
        xpCostModule = 150;
        //Attribute
        affAttr["WIL"] = -50;
        affAttr["EDG"] = -50;
        //Traits
        addSubTraits("Equipped", 100);
        addSubTraits("Extra Income", 50);
        addSubTraits("Wealth", 100);
        //        addSubTraits("Choose either Combat Paralysis or Glass Jaw",-100);
        //Skills
        addSubSkills("Negotiation", 15);
        addSubSkills("Appraisal", 10);
        addSubSkills("Protocol/Lyran", 15);
        //Elem1
        affElem1 << "Combat Paralysis" << "Glass Jaw";
        elem1XPTraits = -100;
        break;
    case 5:
        // FREE RASALHAGUE REPUBLIC
        affProtocol = "Protocol/Rasalhague";
        affStreet = "Streetwise/Rasalhague";
        subAffList << "None" << "Clan War Expatriate" << "Ghost Bear Dominion";
        toolTipAff = "Long ago, the predominantly Scandinavian Rasalhague\nRepublic was invaded and conquered by the Draconis\nCombine. Though they eventually won their freedom\nafter centuries of occupation, their Free Rasalhague\nRepublic was swiftly crushed mere decades later by the\ninvading Clans. Despite being down, the quasi-democratic\nRepublic is far from out, and even as foreign fl ags fl y over\ntheir native worlds, Rasalhagians still cling to their culture\nand identity.\n\n[Attributes] WIL (+25 XP), EDG (-25 XP)\n[Skills] Negotiation (+15 XP), Interests/Any (+10 XP)";
        primLang << "Language/Swedish";
        secLang << "Language/English" << "Language/Japanese" << "Language/Swedenese" << "Language/German";
        listLang = primLang + secLang;
        ower_Affil = "  Long ago, the predominantly Scandinavian Rasalhague Republic was invaded and conquered by the Draconis Combine. Though they eventually won their freedom after centuries of occupation, their Free Rasalhague Republic was swiftly crushed mere decades later by the invading Clans. Despite being down, the quasi-democratic Republic is far from out, and even as foreign fl ags fl y over their native worlds, Rasalhagians still cling to their culture and identity.\n[Attributes] WIL (+25 XP), EDG (-25 XP)\n[Skills] Negotiation (+15 XP), Interests/Any (+10 XP)";
        xpCostModule = 100;
        //Attribute
        affAttr["WIL"] = 25;
        affAttr["EDG"] = -25;
        //Skills
        addSubSkills("Negotiation", 15);
        //        addSubSkills("Interests/Any", 10);
        //Elem1
        affElem1.append(CreateSubSkillList("Interests")); //<< "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        elem1XPSkills = 10;
        break;
    case 6:
        //MINOR PERIPHERY
        affProtocol = "Protocol/Periphery";
        affStreet = "Streetwise/Periphery";
        subAffList << "None" << "Fiefdom of Randis" << "Franklin Fiefs"
                << "Mica Majority" << "Niops Association"
                << "Rim Collection";
        toolTipAff = "In addition to the larger realms, the Periphery includes an assortment\nof minor powers. Banded together for mutual protection and trade,\nsome of these realms-like the Fiefdom of Randis and the Franklin\nFiefs-are as tiny as a single (but well-armed) world, while others-like\nthe icy mining colonies of the Mica Majority and the democratic realms\nof the Niops Association and Rim Collection-encompass a handful of\nworlds.\n\n[Traits] Equipped (-150 XP)\n[Skills] Perception (+15XP), Survival (+20 XP)";
        primLang << "Language/English";
        secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        listLang = primLang + secLang;
        ower_Affil = "  In addition to the larger realms, the Periphery includes an assortment of minor powers. Banded together for mutual protection and trade, some of these realms-like the Fiefdom of Randis and the Franklin Fiefs-are as tiny as a single (but well-armed) world, while others-like the icy mining colonies of the Mica Majority and the democratic realms of the Niops Association and Rim Collection-encompass a handful of worlds.\n[Traits] Equipped (-150 XP)\n[Skills] Perception (+15XP), Survival (+20 XP)";
        xpCostModule = 75;
        //Traits
        addSubTraits("Equipped", -150);
        //Skills
        addSubSkills("Perception", 15);
        addSubSkills("Survival", 20);
        break;
    case 7:
        // MAJOR PERIPHERY STATE
        affProtocol = "Protocol/Periphery";
        affStreet = "Streetwise/Periphery";
        subAffList << "None" << "Circinus Federation" << "Magistracy of Canopus"
                << "Marian Hegemony" << "Outworlds Alliance"
                << "Taurian Concordat";
        toolTipAff = "Often overlooked and underestimated by their more powerful neighbors\nin the Inner Sphere, the major nations of the Periphery-particularly the\nMagistracy of Canopus, the Marian Hegemony, the Outworlds Alliance and\nthe Taurian Concordat-have become miniature Successor States with\nthriving cultures, governments and economies. Though their technology\nand military strength may not be enough to stand up to even the smallest\nGreat House in a straight fi ght, the fi ercely independent Periphery States\nnevertheless reign supreme in their own arena, and collectively stand\nstrong enough that they can no longer be simply ignored.\n\nEquipped (-50 XP)";
        primLang << "Language/English";
//        secLang << "use sub-Affilation";
        listLang = primLang + secLang;
        ower_Affil = "  Often overlooked and underestimated by their more powerful neighbors in the Inner Sphere, the major nations of the Periphery-particularly the Magistracy of Canopus, the Marian Hegemony, the Outworlds Alliance and the Taurian Concordat-have become miniature Successor States with thriving cultures, governments and economies. Though their technology and military strength may not be enough to stand up to even the smallest Great House in a straight fi ght, the fi ercely independent Periphery States nevertheless reign supreme in their own arena, and collectively stand strong enough that they can no longer be simply ignored.\nEquipped (-50 XP)";
        xpCostModule = 75;
        //Traits
        addSubTraits("Equipped", -50);
        break;
    case 8:
        // DEEP PERIPHERY
        affProtocol = "Protocol/Periphery";
        affStreet = "Streetwise/Periphery";
        subAffList << "None" << "Hanseatic League" << "Castilian Principalities"
                << "Umayyad Caliphate" << "JarnFolk";
        toolTipAff = "Far beyond the borders of the Inner Sphere and its neighboring\nPeriphery realms lies the aptly named Deep Periphery. While many humaninhabited\nworlds in this expanse are little more than forgotten castaways,\nat least four signifi cant realms have risen in this void: the mercantile\nHanseatic League, the Iberian-infl uenced Castilian Principalities, the\nenigmatic Umayyad Caliphate and the merchant families of the JarnFolk.\n\n[Attributes] WIL (+60 XP)\n[Traits] Equipped (-80 XP)";
        listLang << "Use sub-Affilation";
        ower_Affil = "  Far beyond the borders of the Inner Sphere and its neighboring Periphery realms lies the aptly named Deep Periphery. While many humaninhabited worlds in this expanse are little more than forgotten castaways, at least four signifi cant realms have risen in this void: the mercantile Hanseatic League, the Iberian-infl uenced Castilian Principalities, the enigmatic Umayyad Caliphate and the merchant families of the JarnFolk.\n[Attributes] WIL (+60 XP)\n[Traits] Equipped (-80 XP)";
        xpCostModule = 50;
        //Attribute
        affAttr["WIL"] = 60;
        //Traits
        addSubTraits("Equipped", -80);
        break;
    case 9:
        // INVADING CLAN
        affProtocol = "Protocol/Clan";
        affStreet = "Streetwise/Clan";
        subAffList << "None" << "Diamond Shark" << "Ghost Bear" << "Hell's Horses"
                << "Jade Falcon" << "Nova Cat" << "Snow Raven" << "Wolf";
        toolTipAff = "The warrior societies founded by Nicholas Kerensky believe in\nthe ultimate form of \"might makes right.\" Having ritualized warfare\ntominimize its devastating impact on their resource-starved\nsocieties, the Clans grew more sophisticated and lethal\nduring their centuries in exile until, in 3048, they launched an invasion of the\nInner Sphere aimed straight toward Terra. By the mid-3070s, seven\nof the originaltwenty warrior Clans laid claim to Inner Sphere worlds,\ncompeting against each other for dominance, yet united by a\ncommon culture andthe dream of one day restoring the Star League\nin their own image.\n\n[Traits] Compulsion/Arrogance (-50 XP), Compulsion/Distrust of Inner Sphere (-100 XP)\n[Skills] Interests/Clan Remembrance (+25 XP), Protocol/Clan (+25 XP)\n\nClan characters that fall into the castes (or sub-castes) described on p. 61\nreceive the following fixed XP. A Clanborn character that does not fi t in any of these listed castes\nis considered Dark Caste and must choose the Pirate subaffi liation\nunder Affiliation: Independent (see p. 63) as if using the Changing Affi liations rule (see p. 53).";
        listLang << "Language/English";
        ower_Affil = "  The warrior societies founded by Nicholas Kerensky believe in the ultimate form of \"might makes right.\" Having ritualized warfare to minimize its devastating impact on their resource-starved societies, the Clans grew more sophisticated and lethal during their centuries in exile until, in 3048, they launched an invasion of the Inner Sphere aimed straight toward Terra. By the mid-3070s, seven of the originaltwenty warrior Clans laid claim to Inner Sphere worlds, competing against each other for dominance, yet united by a common culture andthe dream of one day restoring the Star League in their own image.\n[Traits] Compulsion/Arrogance (-50 XP), Compulsion/Distrust of Inner Sphere (-100 XP)\n[Skills] Interests/Clan Remembrance (+25 XP), Protocol/Clan (+25 XP)\nClan characters that fall into the castes (or sub-castes) described on p. 61 receive the following fixed XP. A Clanborn character that does not fi t in any of these listed castes is considered Dark Caste and must choose the Pirate subaffi liation under Affiliation: Independent (see p. 63) as if using the Changing Affi liations rule (see p. 53)";
        xpCostModule = 75;
        //Traits
        addSubTraits("Compulsion/Arrogance", -50);
        addSubTraits("Compulsion/Distrust of Inner Sphere", -100);
        //Skills
        addSubSkills("Interests/Clan Remembrance", 25);
        addSubSkills("Protocol/Clan", 25);
        //Elem1
        affElem1 << "MechWarrior" << "Elemental"
                << "Elemental-Advanced" << "Aerospace" << "ProtoMech"
                << "Aerospace-Naval" << "Warrior Caste(Other)"
                << "Scientist Caste" << "Technician Caste"
                << "Merchant Caste" << "Laborer Caste";
        break;
    case 10:
        // HOMEWORLD CLAN
        affProtocol = "Protocol/Clan";
        affStreet = "Streetwise/Clan";
        subAffList << "None" << "Blood Spirit" << "Cloud Cobra" << "Coyote"
                << "Fire Mandrill" << "Goliath Scorpion"
                << "Ice Hellion" << "Star Adder" << "Steel Viper";
        toolTipAff = "With their defeat at Tukayyid in 3052 and the Great Refusal in\n3060, the Clan invasion faltered and collapsed, ending-at least for\nnow-the threat of a mass Clan migration into the Inner Sphere.\nThe invasion, however, widened the rifts between those\nClans who claimed \"Spheroid\" worlds and those who remained on the\nresource-poor planets Kerensky's descendants fi rst called home.\n Forced to watch as theirrival Clans grew ever stronger, the so-called\nHomeworld Clans console themselves with the knowledge that Inner Sphere\ncontact will onlyfurther corrupt their Invading brethren, while they\nremain free of \"barbarian\" pollution.\n\n[Traits] Compulsion/Distrust of Inner Sphere (-100 XP), Compulsion/Hate Invading Clans (-100 XP)\n[Skills] Interests/Clan Remembrance (+25 XP), Protocol/Clan (+25 XP)\n\nClan characters that fall into the castes (or sub-castes) described on p. 61\nreceive the following fixed XP. A Clanborn character that does not fi t in any of these listed castes\nis considered Dark Caste and must choose the Pirate subaffi liation\nunder Affiliation: Independent (see p. 63) as if using the Changing Affi liations rule (see p. 53).";
        listLang << "Language/English";
        ower_Affil = "  With their defeat at Tukayyid in 3052 and the Great Refusal in 3060, the Clan invasion faltered and collapsed, ending-at least for now-the threat of a mass Clan migration into the Inner Sphere. The invasion, however, widened the rifts between those Clans who claimed \"Spheroid\" worlds and those who remained on the resource-poor planets Kerensky's descendants fi rst called home. Forced to watch as theirrival Clans grew ever stronger, the so-called Homeworld Clans console themselves with the knowledge that Inner Sphere contact will onlyfurther corrupt their Invading brethren, while they remain free of \"barbarian\" pollution.\n[Traits] Compulsion/Distrust of Inner Sphere (-100 XP), Compulsion/Hate Invading Clans (-100 XP)\n[Skills] Interests/Clan Remembrance (+25 XP), Protocol/Clan (+25 XP)\n\nClan characters that fall into the castes (or sub-castes) described on p. 61 receive the following fixed XP. A Clanborn character that does not fi t in any of these listed castes is considered Dark Caste and must choose the Pirate subaffi liation under Affiliation: Independent (see p. 63) as if using the Changing Affi liations rule (see p. 53).";
        xpCostModule = 50;
        //Traits
        addSubTraits("Compulsion/Distrust of Inner Sphere", -100);
        addSubTraits("Compulsion/Hate Invading Clans", -100);
        //Skills
        addSubSkills("Interests/Clan Remembrance", 25);
        addSubSkills("Protocol/Clan", 25);
        affElem1 << "MechWarrior" << "Elemental"
                << "Elemental-Advanced" << "Aerospace" << "ProtoMech"
                << "Aerospace-Naval" << "Warrior Caste(Other)"
                << "Scientist Caste" << "Technician Caste"
                << "Merchant Caste" << "Laborer Caste";
        break;
    case 11:
        // TERRAN
        affProtocol = "Protocol/Terran";
        affStreet = "Streetwise/Terran";
        subAffList << "None" << "Belter" << "Lunar Citizen" << "Martian Citizen"
                << "Outer System Citizen" << "Terran Citizen"
                << "Venusian Citizen";
        toolTipAff = "In the centuries since humankind took to the stars, Terra has been seen\nas both benevolent mother and cruel oppressor of the hundreds of\nworlds humanity now calls home. Yet whatever their histories, every\nculture in human-settled space can trace its origins\nto Terra. Though isolated for hundreds of years under the authority\nof ComStar, Terra-the center of the Inner Sphere, the crown jewel\nof the Star League, and the most coveted world in all of known space\nto the Clans-has thrived as an island of high culture and technology.\n The people of Terra (and their solar system neighbors on\nLuna, Mars, Venus, Titan and elsewhere) owe their\nallegiance to no Great House or Clan, and were spared the\nhorrors of the Succession Wars by the grace of their ComStar\nbenefactors. This fact, coupled with Terra's place\nas humankind's ancient home, has engendered a sense\nof superiority over the \"colonials\" beyond Terran space.\n This arrogance and aloofness-born of prosperity, self-perceived\nenlightenment and a history no other world can possibly match-verges\non xenophobia. To the people of the Terran system, the universe\nhas revolved and always will revolve around them.\n\n[Attributes] INT (+100 XP), EDG (-150 XP), +50 XP each to any two other Attributes\n[Traits] Compulsion/Distrust of Non-Terrans (-75 XP),Reputation (+100 XP)\n[Skills] Language/English (+25 XP), +15 XP to any two other Language Skills";
        listLang << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        ower_Affil = "  In the centuries since humankind took to the stars, Terra has been seen as both benevolent mother and cruel oppressor of the hundreds of worlds humanity now calls home. Yet whatever their histories, every culture in human-settled space can trace its origins to Terra. Though isolated for hundreds of years under the authority of ComStar, Terra-the center of the Inner Sphere, the crown jewel of the Star League, and the most coveted world in all of known space to the Clans-has thrived as an island of high culture and technology. The people of Terra (and their solar system neighbors on Luna, Mars, Venus, Titan and elsewhere) owe their allegiance to no Great House or Clan, and were spared the horrors of the Succession Wars by the grace of their ComStar benefactors. This fact, coupled with Terra's place as humankind's ancient home, has engendered a sense of superiority over the \"colonials\" beyond Terran space. This arrogance and aloofness-born of prosperity, self-perceived enlightenment and a history no other world can possibly match-verges on xenophobia. To the people of the Terran system, the universe has revolved and always will revolve around them.\n[Attributes] INT (+100 XP), EDG (-150 XP), +50 XP each to any two other Attributes\n[Traits] Compulsion/Distrust of Non-Terrans (-75 XP),Reputation (+100 XP)\n[Skills] Language/English (+25 XP), +15 XP to any two other Language Skills";
        xpCostModule = 240;
        //Attribute
        affAttr["INT"] = 100;
        affAttr["EDG"] = -150;
        //        affAttr["EDG"] = 50; // SEE RULEZ!!!!
        //        affAttr["EDG"] = 50; // SEE RULEZ!!!!
        //Traits
        addSubTraits("Compulsion/Distrust of Non-Terrans", -75);
        addSubTraits("Reputation", 100);
        //Skills
        addSubSkills("Language/English", 25);
        //        addSubSkills("two other Language Skills", 15); // SEE RULEZ!!!!
        //Elem1
        affElem1 = listLang;
        //Elem2
        affElem2 << "STR" << "RFL" << "DEX" << "WIL" << "CHA";
        break;
    case 12:
        // INDEPENDENT
        affProtocol = "Protocol/Independent";
        affStreet = "Streetwise/Independent";
        subAffList << "None" << "Antallos" << "Astrokaszy" << "Generic"
                << "Mercenary" << "Pirate" << "Spacer"
                << "Tortuga";
        toolTipAff = "The so-called \"independents\" are those individuals and worlds that\nlie scattered throughout human-occupied space, but whose allegiance\nlies outside the major and minor states of the Inner Sphere,\nPeriphery and Clan dominions. A few noteworthy independents\ninclude the lawless worlds and pirate havens of Antallos and Tortuga,\nas well as the fractured quasi-Arabian caliphates of Astrokaszy.\nBut even mercenaries, pirates and \"spacers\"-none of whom could ever\ncall a single world \"home\"-fall into the category of independents. These\nrogue affi liations attract some of humanity's most\nadventurous souls, who may find themselves plying the\nspace lanes for trade or doing battle for causes more\npersonal than any empire's banner.\n\n[Attributes] WIL (+20 XP), EDG (+20 XP)\n[Traits] Equipped (-20 XP), Reputation (-10 XP), Wealth (-10 XP)";
        listLang << "Use sub-Affilation";
        ower_Affil = "  The so-called \"independents\" are those individuals and worlds that lie scattered throughout human-occupied space, but whose allegiance lies outside the major and minor states of the Inner Sphere, Periphery and Clan dominions. A few noteworthy independents include the lawless worlds and pirate havens of Antallos and Tortuga, as well as the fractured quasi-Arabian caliphates of Astrokaszy. But even mercenaries, pirates and \"spacers\"-none of whom could ever call a single world \"home\"-fall into the category of independents. These rogue affi liations attract some of humanity's most adventurous souls, who may find themselves plying the space lanes for trade or doing battle for causes more personal than any empire's banner.\n[Attributes] WIL (+20 XP), EDG (+20 XP)\n[Traits] Equipped (-20 XP), Reputation (-10 XP), Wealth (-10 XP)";
        xpCostModule = 50;
        //Attribute
        affAttr["WIL"] = 20;
        affAttr["EDG"] = 20;
        //Traits
        addSubTraits("Equipped", -20);
        addSubTraits("Reputation", -10);
        addSubTraits("Wealth", -10);
        break;
        //    case 13:
        //        // COMSTAR/WORD OF BLAKE
        //        subAffList << "None" << "ComStar" << "Word of Blake";
        //        toolTipAff = "Originally a neutral, interstellar pseudo-corporation that rose\nfrom the ashes of the fi rst Star League, ComStar established\nan unassailable empire based on its complete control of the\ninterstellar HPG communications network. Transforming itself\ninto a quasi-religious order, ComStar monitored and subtly\nmanipulated events across the Inner Sphere while cloaking itself\nin mystery. Fragmented in the wake of the initial Clan Invasion,\nhowever, a reformed ComStar moved to share many of its\nadvantages with the Inner Sphere in defense against the Clans-\nwhile the fanatical Word of Blake amassed the terrible forces\nunleashed in their recent Jihad against all of humankind.\n\n[Traits] Enemy (-100 XP), Equipped (+100 XP), Rank (+50 XP), Reputation (-50 XP)\n[Skills]Communications/Conventional (+10 XP),\nInterests/Writings of Jerome Blake (+10 XP),Negotiation (+10 XP)";
        //        listLang << "Primary     : English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        //        xpCostModule = 50; //SEE RULEZ!!!!
        //        //Traits
        //        addSubTraits("Enemy", -100);
        //        addSubTraits("Equipped", 100);
        //        addSubTraits("Rank", 50);
        //        addSubTraits("Reputation", -50);
        //        //Skills
        //        addSubSkills("Communications/Conventional", 10);
        //        addSubSkills("Interests/Writings of Jerome Blake", 10);
        //        addSubSkills("Negotiation", 10);
        //        break;
    default:
        subAffList << "error!";

    }
}

void Text_Resurce::addSubTraits(QString str , int count) {
    affTraits.append(qMakePair(str,count));
}

void Text_Resurce::addSubSkills(QString str , int count) {
    affSkills.append(qMakePair(str,count));
}

void Text_Resurce::addSubTraitsCast(QString str , int count) {
    affTraitsCast.append(qMakePair(str,count));
}

void Text_Resurce::addSubSkillsCast(QString str , int count) {
    affSkillsCast.append(qMakePair(str,count));
}


void Text_Resurce::swapChar()
{
    swpAffAttr = affAttr;
    swpAffTraits = affTraits;
    swpAffSkills = affSkills;
    affAttr.clear();
    affTraits.clear();
    affSkills.clear();
}

void Text_Resurce::restoreChar()
{
    affAttr = swpAffAttr;
    affTraits = swpAffTraits;
    affSkills = swpAffSkills;
}

void Text_Resurce::comstarAttr(bool chk){
    affAttr.clear();
    affTraits.clear();
    affSkills.clear();
    xpCostModule = 50;
    comElem.clear();
    comElem.append(CreateSubSkillList("Technician")); //<< "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
    comElemInt = 10;
    if(chk == true) {
        //Traits
        addSubTraits("Enemy", -100);
        addSubTraits("Equipped", 100);
        addSubTraits("Rank", 50);
        addSubTraits("Reputation", -50);
        //Skills
        addSubSkills("Communications/Conventional", 10);
        addSubSkills("Interests/Writings of Jerome Blake", 10);
        addSubSkills("Negotiation", 10);
    } else {
        xpCostModule = -50;
        //Traits
        addSubTraits("Enemy", 100);
        addSubTraits("Equipped", -100);
        addSubTraits("Rank", -50);
        addSubTraits("Reputation", 50);
        //Skills
        addSubSkills("Communications/Conventional", -10);
        addSubSkills("Interests/Writings of Jerome Blake", -10);
        addSubSkills("Negotiation", -10);
    }    
}

void Text_Resurce::comstarSub(bool chk)
{

    if ( chk == true ) {
        affAttr["INT"] = 25;
        affAttr["WIL"] = -15;
        addSubTraits("Connections",50);
        addSubTraits("Enemy/Word of Blake",-100);
        addSubTraits("Reputation",20);

        addSubSkills("Protocol/Nearest state", 15);
        addSubSkills("Protocol/ComStar", 15);
    } else {
        affAttr["INT"] = -25;
        affAttr["WIL"] = 15;
        addSubTraits("Connections",-50);
        addSubTraits("Enemy/Word of Blake",100);
        addSubTraits("Reputation",-20);

        addSubSkills("Protocol/Nearest state", -15);
        addSubSkills("Protocol/ComStar", -15);
    }
}

void Text_Resurce::WoBSub(bool chk)
{
    if ( chk == true ) {
        affAttr["WIL"] = 50;
        affAttr["CHA"] = -50;
        addSubTraits("Compulsion/Paranoid", -50);
        addSubTraits("Connections", 75);
        addSubTraits("Enemy/ComStar", -100);
        addSubTraits("Equipped", 30);

        addSubSkills("Interests/Writings of Jerome Blake", 15);
        addSubSkills("Interests/Writings of the Master", 15);
        addSubSkills("Negotiation", 10);
        addSubSkills("Protocol/Nearest state", 5);
        addSubSkills("Protocol/Word of Blake", 10);
    } else {
        affAttr["WIL"] = -50;
        affAttr["CHA"] = 50;
        addSubTraits("Compulsion/Paranoid", 50);
        addSubTraits("Connections", -75);
        addSubTraits("Enemy/ComStar", 100);
        addSubTraits("Equipped", -30);

        addSubSkills("Interests/Writings of Jerome Blake", -15);
        addSubSkills("Interests/Writings of the Master", -15);
        addSubSkills("Negotiation", -10);
        addSubSkills("Protocol/Nearest state", -5);
        addSubSkills("Protocol/Word of Blake", -10);
    }
}

void Text_Resurce::subAffAttr(int primPos, int secPos)
{
    affAttr.clear();
    affTraits.clear();
    affSkills.clear();
    subAffElem1Label.clear();
    subAffElem2Label.clear();
    subAffElem3Label.clear();
    subAffElem4Label.clear();
    subAffElem1.clear();
    subAffElem2.clear();
    subAffElem3.clear();
    subAffElem4.clear();
    affSkillsElem1 = 0;
    affTraitsElem1 = 0;

    affSkillsElem2 = 0;
    affTraitsElem2 = 0;

    affSkillsElem3 = 0;
    affTraitsElem3 = 0;

    affSkillsElem4 = 0;
    affTraitsElem4 = 0;

    subAffElem1LabelMore.clear();
    subAffElem1More.clear();
    affSkillsElem1More = 0;

    subAffElem2LabelMore.clear();
    subAffElem2More.clear();
    affSkillsElem2More = 0;

    subAffElem3LabelMore.clear();
    subAffElem3More.clear();
    affSkillsElem3More = 0;

    subAffElem4LabelMore.clear();
    subAffElem4More.clear();
    affSkillsElem4More = 0;

    switch(primPos) {
        //---------------------------------------- FEDERATED SUNS (HOUSE DAVION)
    case 0:
        switch(secPos) {
            // Capella March
        case 1:
            affAttr["WIL"] = 40;
            addSubTraits("Connections", 25);
            addSubTraits("Compulsion/Hatred of Capellan Confederation", -50);

            addSubSkills("Protocol/FedSuns", 10);
            addSubSkills("Interests/FedSuns History", 10);
//            addSubSkills("Language/Choose one from Cantonese, German, Mandarin, Spanish or Russian", 5);

            subAffElem1Label = "Language/Choose one";
            subAffElem1 << "Language/Cantonese" << "Language/German" << "Language/Mandarin Chinese" << "Language/Spanish" << "Language/Russian";
            affSkillsElem1 = 5;

            break;
            //Crucis March
        case 2:
            affAttr["WIL"] = 50;
            affAttr["EDG"] = -50;

//            addSubSkills("Art/Any", 10);
            addSubSkills("Interests/FedSuns History", 15);
            addSubSkills("Protocol/FedSuns", 15);

            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art"));// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 10;

            break;
            //Draconis March
        case 3:
            affAttr["EDG"] = 25;

            addSubTraits("Connections", 20);
            addSubTraits("Compulsion/Hatred of Draconis Combine", -30);

//            addSubSkills("Art/Any", 10);
            addSubSkills("Interests/FedSuns History", 10);
            addSubSkills("Protocol/FedSuns", 5);
            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art"));// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 10;

            break;
            // Outback
        case 4:
            affAttr["STR"] = 50;
            affAttr["BOD"] = 150;
            affAttr["WIL"] = 100;
            affAttr["INT"] = -100;

            addSubTraits("Illiterate", -50);
            addSubTraits("Reputation", -50);
            addSubTraits("Wealth", -100);

//            addSubSkills("Art/Any or Interests/Any", 10);
            addSubSkills("Streetwise/FedSuns", 10);
//            addSubSkills("Survival/Any", 20);

            subAffElem1Label = "Choose one Art or Interest";
            subAffElem1.append(CreateSubSkillList("Art"));// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            subAffElem1.append(CreateSubSkillList("Interests"));
            affSkillsElem1 = 10;

            subAffElem2Label = "Survival/Any";
            subAffElem2.append(CreateSubSkillList("Survival")); // << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2 = 20;

            break;
        }
        break;
        //---------------------------------------- CAPELLAN CONFEDERATION (HOUSE LIAO)
    case 1:
        switch(secPos){
            // Capellan Commonality
        case 1:
            affAttr["EDG"] = 50;
            addSubTraits("Wealth", +15);

//            addSubSkills("Language/Any FedSuns", 5);
            addSubSkills("Protocol/FedSuns", 5);

            subAffElem1Label = "Language/Any FedSuns";
            subAffElem1 << "Language/English" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Russian";
            affSkillsElem1 = 5;

            break;
            // Liao Commonality
        case 2:
            affAttr["INT"] = 50;
            addSubTraits("Reputation", -25);
//            addSubSkills("Language/Choose Any FedSuns or Lyran", 15);

//            addSubSkills("Protocol/Choose either FedSuns or Lyran", 10);
//            addSubSkills("Art/Any",10);
            addSubSkills("Martial Arts", 15);

            subAffElem1Label = "Language/Any FedSuns or Lyran";
            subAffElem1 << "Language/English" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Russian" << "Language/Italian" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem1 = 15;

            subAffElem2Label = "Protocol/Choose one FedSuns or Lyran";
            subAffElem2 << "Protocol/FedSuns" << "Protocol/Lyran";
            affSkillsElem2 = 10;

            subAffElem3Label = "Art/Any";
            subAffElem3.append(CreateSubSkillList("Art"));// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem3 = 10;

            break;
            // Sian Commonality
        case 3:
            affAttr["WIL"] = 75;
            addSubTraits("Compulsion/Hatred of Federated Suns", -135);
            addSubTraits("Citizenship", 50);
            addSubTraits("Connections", 50);

            addSubSkills("Interests/Capellan History", 10);
//            addSubSkills("Protocol/Choose either FedSuns or Lyran", 10);
            addSubSkills("Protocol/Capellan",15);
//            addSubSkills("Language/Any Capellan Secondary ", 10);

            subAffElem1Label = "Language/Any Capellan Secondary";
            subAffElem1 << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/English";
            affSkillsElem1 = 10;

//            subAffElem2Label = "Protocol/Choose one FedSuns or Lyran";
//            subAffElem2 << "Protocol/FedSuns" << "Protocol/Lyran";
//            affSkillsElem2 = 10;

            break;
            // St. Ives Commonality
        case 4:
            affAttr["WIL"] = 50;
            affAttr["EDG"] = 50;
            addSubTraits("Reputation ", -100);
            addSubTraits("Wealth", 50);
            addSubTraits("Connections", 50);

//            addSubSkills("Language/Any FedSuns", 15);
            addSubSkills("Protocol/Capellan",-15);
            addSubSkills("Protocol/FedSuns",10);
//            addSubSkills("Art/Any",5);
            addSubSkills("Martial Arts", 10);

            subAffElem1Label = "Language/Any FedSuns";
            subAffElem1 << "Language/English" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Russian";
            affSkillsElem1 = 15;

            subAffElem2Label = "Art/Any";
            subAffElem2.append(CreateSubSkillList("Art"));// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem2 = 5;

            break;
            //Victoria Commonality
        case 5:
            affAttr["WIL"] = 35;
            addSubTraits("Connections", 50);
            addSubTraits("Wealth", -50);

//            addSubSkills("Language/Any", 15);
            addSubSkills("Negotiation", 10);
            addSubSkills("Martial Arts", 15);

            subAffElem1Label = "Language/Any";
            subAffElem1.append(CreateSubSkillList("Language"));// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem1 = 15;
            break;
        }
        break;
        //---------------------------------------- DRACONIS COMBINE (HOUSE KURITA)
    case 2:
        switch(secPos) {
            // Azami
        case 1:
            affAttr["WIL"] = 90;
            addSubTraits("Compulsion/Xenophobia", -50);
            addSubTraits("Equipped", -50);
            addSubTraits("Thick-Skinned", 100);
            addSubTraits("Wealth", -25);

            addSubSkills("Language/Arabic", 10);
            addSubSkills("Language/Japanese", -10);
            addSubSkills("Martial Arts", 10);
            addSubSkills("Melee Weapons", 10);
            addSubSkills("Riding", 5);
//            addSubSkills("Survival/Any", 10);

            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival"));// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem3Label = "Flexible XPs";
            subAffElem3 << "Archery" << "Melee Weapons" << "Thrown Weapons";
            affSkillsElem3 = 10;

            break;
            //Benjamin District
        case 2:
            addSubTraits("Compulsion/Paranoid of Combine Government", -50);
            addSubTraits("Connections", 50);
            addSubTraits("Patient", 25);
            addSubTraits("Wealth", 35);

            addSubSkills("Art/Oral Tradition", 5);
            addSubSkills("Martial Arts", 10);
            addSubSkills("Protocol/Combine", 15);
            addSubSkills("Streetwise/Combine", 10);

            subAffElem3Label = "Flexible XPs";
            subAffElem3 << "Archery" << "Melee Weapons" << "Thrown Weapons";
            affSkillsElem3 = 10;
            break;
            //Dieron District
        case 3:
            affAttr["INT"] = 50;
            affAttr["WIL"] = -50;

            addSubTraits("Compulsion/Xenophobia", 50);
            addSubTraits("Connections", 60);
            addSubTraits("Enemy", -100);
            addSubTraits("Wealth", 50);

            addSubSkills("Interests/Star League History", 5);
//            addSubSkills("Language/Any", 15);
            addSubSkills("Negotiation", 5);
//            addSubSkills("Art/Any", 15);

            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art")); // << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 15;

            subAffElem2Label = "Language/Any";
            subAffElem2.append(CreateSubSkillList("Language")); // << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem2 = 15;

            subAffElem3Label = "Flexible XPs";
            subAffElem3 << "Archery" << "Melee Weapons" << "Thrown Weapons";
            affSkillsElem3 = 10;

            break;
            // New Samarkan(Galedon)District
        case 4:
            affAttr["WIL"] = 100;
            affAttr["CHA"] = -50;

            addSubTraits("Compulsion/Hatred of Federated Suns", -50);
            addSubTraits("Connections", 50);

            addSubSkills("Interests/Combine History", 10);
            addSubSkills("Melee Weapons", 15);
            addSubSkills("Negotiation", 5);
            addSubSkills("Protocol/Combine", 10);
            addSubSkills("Streetwise/Combine", 10);

            subAffElem3Label = "Flexible XPs";
            subAffElem3 << "Archery" << "Melee Weapons" << "Thrown Weapons";
            affSkillsElem3 = 10;
            break;
            // Pesht District
        case 5:
            affAttr["WIL"] = 100;
            affAttr["EDG"] = -25;

            addSubTraits("Compulsion/Hatred of Clans", -100);
            addSubTraits("Connections", 20);
            addSubTraits("Wealth", 50);

            addSubSkills("Martial Arts", 10);
            addSubSkills("Melee Weapons", 15);
            addSubSkills("Protocol/Combine", 20);
            addSubSkills("Streetwise/Combine", 10);

            subAffElem3Label = "Flexible XPs";
            subAffElem3 << "Archery" << "Melee Weapons" << "Thrown Weapons";
            affSkillsElem3 = 10;
            break;
        }
        break;
        //---------------------------------------- FREE WORLDS LEAGUE (HOUSE MARIK)
    case 3:
        switch(secPos) {
            // Marik Commonwealth
        case 1:
            addSubTraits("Wealth", 100);
            addSubTraits("Equipped", 100);
            addSubTraits("Reputation", -100);

            addSubSkills("Appraisal", 5);
            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Free Worlds", 10);
            break;
            //Principality of Regulus
        case 2:
            affAttr["WIL"] = 75;

            addSubTraits("Gregarious", 75);
            addSubTraits("Compulsion/Atrean Opponent", -50);
            addSubTraits("Reputation", -50);

            addSubSkills("Interests/Regulan History", 20);
            addSubSkills("Negotiation", 25);
            addSubSkills("Perception", 15);
            addSubSkills("Protocol/Free Worlds", 15);
            break;
            //Duchy of Oriente
        case 3:
            addSubTraits("Reputation", 100);

            addSubSkills("Appraisal", 5);
            addSubSkills("Negotiation", 15);
//            addSubSkills("Technician/Any", 5);


            subAffElem1Label = "Technician";
            subAffElem1.append(CreateSubSkillList("Technician")); // << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem1 = 5;

            break;
            // Duchy of Andurien
        case 4:
            affAttr["WIL"] = 50;

            addSubTraits("Combat Sense", 215);
            addSubTraits("Compulsion/Hatred of House Liao", -100);
            addSubTraits("Compulsion/Atrean Opponent", -50);
            addSubTraits("Reputation", -30);

            addSubSkills("Negotiation", 15);
            addSubSkills("Perception", 10);
            addSubSkills("Protocol/Free Worlds", 15);
            break;
            // Other Fwl Worlds
        case 5:
//            addSubTraits("Any one", 35);

            addSubSkills("Appraisal", 15);
//            addSubSkills("Language/Any", 20);
            addSubSkills("Protocol/Free Worlds", 10);
//            addSubSkills("Any two other Skills", 10);
//            addSubSkills("to any one Attribute, Trait, or Language Skill", 25);

            subAffElem1Label = "Any one Traits";
            subAffElem1 << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affTraitsElem1 = 35;

            subAffElem2Label = "Language/Any";
            subAffElem2.append(CreateSubSkillList("Language"));// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem2 = 20;

//            subAffElem3Label = "Any two other Skills";
//            subAffElem3 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affSkillsElem3 = 10;
            subAffElem1LabelMore = "Any one other Skills";
            subAffElem1More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Any one other Skills";
            subAffElem2More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;

            subAffElem4LabelMore = "to any one Attribute, Trait, or Lang Skill";
            subAffElem4More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth" << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem4More = 25;

// All skills
            //<< "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            subAffElem4Label = "to any one Attribute, Trait, or Lang Skill";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth" << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
//            affSkillsElem4 = 25;
//            affTraitsElem4 = 25;

            break;
        }
        break;
        //---------------------------------------- LYRAN ALLIANCE (HOUSE STEINER)
    case 4:
        switch(secPos) {
            // Alarion Province
        case 1:
            affAttr["CHA"] = -50;
            addSubTraits("Wealth", 70);

            addSubSkills("Administration", 10);
//            addSubSkills("Interests/Any", 10);
//            addSubSkills("Language/Any", 10);
            addSubSkills("Negotiation", 10);

            subAffElem1Label = "Interests/Any";
            subAffElem1.append(CreateSubSkillList("Interests"));// << "Interests/Battlemechs" << "Interests/Battlesuits" << "Interests/Aerospace" << "Interests/Spacecraft" << "Interests/Aircraft" << "Interests/Ground Vehicles" << "Interests/Sea Vehicles" << "Interests/Rail Vehicles" << "Interests/History (Star League)" << "Interests/History (Terran)" << "Interests/History (Clan)" << "Interests/History (Inner Sphere)" << "Interests/History (Periphery)" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports" << "Interests/Weapons" << "Interests/Martial Arts" << "Interests/GameMastering for Battletech";
            affSkillsElem1 = 10;

            subAffElem2Label = "Language";
            subAffElem2.append(CreateSubSkillList("Language")); // << "Language/English" <<"Language/Japanese" <<"Language/Russian" <<"Language/German" <<"Language/French" <<"Language/Hindi" <<"Language/Mandarin Chinese" <<"Language/Vietnamese" <<"Language/Cantonese" <<"Language/Arabic" <<"Language/Swedenese" <<"Language/Greek" <<"Language/Italian" <<"Language/Romanian" <<"Language/Slovak" << "Language/Spanish";
            affSkillsElem2 = 10;

            break;
            //Bolan Province
        case 2:

            addSubTraits("Compulsion/Hatred of House Marik", -50);
            addSubTraits("Connections", 50);
            addSubTraits("Wealth", 25);

            addSubSkills("Administration", 5);
            addSubSkills("Negotiation", 15);
            addSubSkills("Protocol/Lyran", 10);
            addSubSkills("Streetwise/Lyran", 5);
            break;
            //Coventry Province
        case 3:
            affAttr["WIL"] = 100;

            addSubTraits("Compulsion/Hatred of Clans", -95);
            addSubTraits("Wealth", 25);

            addSubSkills("Administration", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Lyran", 10);
            break;
            // Outback
        case 4:
            affAttr["WIL"] = 50;

            addSubTraits("Compulsion/Greedy", -75);
            addSubTraits("Connections", 50);
            addSubTraits("Reputation", -50);
            addSubTraits("Wealth", 50);

            addSubSkills("Appraisal", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Lyran", 15);
            break;
        case 5:
            affAttr["WIL"] = 100;

            addSubTraits("Connections", 85);
            addSubTraits("Reputation", -150);

            addSubSkills("Language/Scots Gaelic", 10);
            addSubSkills("Negotiation", 15);
            addSubSkills("Protocol/Lyran", -15);
            addSubSkills("Streetwise/Lyran", 15);
            break;
        }
        break;
        //---------------------------------------- FREE RASALHAGUE REPUBLIC
    case 5:
        switch(secPos) {
            // Clan War Expatriate
        case 1:
            affAttr["WIL"] = 125;
            affAttr["EDG"] = 100;
            addSubTraits("Compulsion/Hatred of Clans", -150);
            addSubTraits("Wealth", -50);

//            addSubSkills("Language/Choose Any Lyran or Draconis", 15);
            addSubSkills("Martial Arts", 10);
//            addSubSkills("Protocol/Choose either Lyran or Draconis", 10);
            addSubSkills("Small Arms", 15);

            subAffElem1Label = "Language";
            subAffElem1 << "Language/English" << "Language/Japanese" <<"Language/Russian" <<"Language/German" <<"Language/French" <<"Language/Hindi" <<"Language/Mandarin Chinese" <<"Language/Vietnamese" <<"Language/Cantonese" <<"Language/Arabic" <<"Language/Swedenese" <<"Language/Greek" <<"Language/Italian" <<"Language/Romanian" <<"Language/Slovak" << "Language/Spanish";
            affSkillsElem1 = 15;

            subAffElem2Label = "Protocol/Choose one Lyran or Draconis";
            subAffElem2 << "Protocol/Lyran" << "Protocol/Draconis";
            affSkillsElem2 = 10;

            break;
            //Principality of Regulus
        case 2:
            addSubTraits("Equipped", 50);
            addSubTraits("Introvert", -25);
            addSubTraits("Reputation", -25);

            addSubSkills("Protocol/Clan (Ghost Bear)", 20);
//            addSubSkills("Interests/Any", 10);
            addSubSkills("Interests/Remembrance", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Martial Arts", 15);
            addSubSkills("Melee Weapons", 10);

            subAffElem1Label = "Interests/Any";
            subAffElem1.append(CreateSubSkillList("Interests")); // << "Interests/Battlemechs" << "Interests/Battlesuits" << "Interests/Aerospace" << "Interests/Spacecraft" << "Interests/Aircraft" << "Interests/Ground Vehicles" << "Interests/Sea Vehicles" << "Interests/Rail Vehicles" << "Interests/History (Star League)" << "Interests/History (Terran)" << "Interests/History (Clan)" << "Interests/History (Inner Sphere)" << "Interests/History (Periphery)" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports" << "Interests/Weapons" << "Interests/Martial Arts" << "Interests/GameMastering for Battletech";
            affSkillsElem1 = 10;
            break;
        }
        break;
        //---------------------------------------- MINOR PERIPHERY
    case 6:
        switch(secPos) {
            // Fiefdom of Randis
        case 1:
            affAttr["BOD"] = 125;
            affAttr["EDG"] = 50;
            addSubTraits("Illiterate", -75);
            addSubTraits("Wealth", -50);

            addSubSkills("Martial Arts", 10);
            addSubSkills("Melee Weapons", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Streetwise/Periphery", 15);
//            addSubSkills("Survival/Any", 20);
            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Arctic" <<"Survival/Forests" <<"Survival/Desert" <<"Survival/Jungle" <<"Survival/Ocean" <<"Survival/Mountain" <<"Survival/Steppe" << "Survival/Martian Desert";
            affSkillsElem1 = 20;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem1More = 25;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem2More = 25;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem3More = 25;

            break;
            //Franklin Fiefs
        case 2:
            affAttr["BOD"] = 150;
            affAttr["INT"] = -100;
            affAttr["WIL"] = 50;

            addSubTraits("Equipped", -60);
            addSubTraits("Illiterate", -90);
            addSubTraits("Toughness", 100);

            addSubSkills("Martial Arts", 15);
            addSubSkills("MedTech", 10);
            addSubSkills("Protocol/Novo Franklin", 10);
            addSubSkills("Streetwise/Periphery", 10);
//            addSubSkills("Survival/Any", 10);
//            addSubSkills("+10 XP to any one of the following: Archery, Melee Weapons or Negotiation", 10);

            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Arctic" <<"Survival/Forests" <<"Survival/Desert" <<"Survival/Jungle" <<"Survival/Ocean" <<"Survival/Mountain" <<"Survival/Steppe" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Archery" << "Melee Weapons" << "Negotiation";
            affSkillsElem2 = 10;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem1More = 25;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem2More = 25;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem3More = 25;

            break;
            //Mica Majority
        case 3:
            affAttr["BOD"] = 100;
            affAttr["RFL"] = 100;
            affAttr["EDG"] = -100;

            addSubTraits("Equipped", -25);
            addSubTraits("Toughness", 100);
            addSubTraits("Wealth", -100);

            addSubSkills("Career/Mining", 10);
            addSubSkills("Language/Japanese", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Survival/Arctic", 10);

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem1More = 25;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem2More = 25;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem3More = 25;
            break;
            // Niops Association
        case 4:
            affAttr["INT"] = 125;
            affAttr["WIL"] = -110;

            addSubTraits("Equipped", 200);
            addSubTraits("Introvert", -125);

//            addSubSkills("Interests/Any", 10);
//            addSubSkills("Technician/Any", 15);

            subAffElem1Label = "Technician";
            subAffElem1.append(CreateSubSkillList("Technician")); // << "Technician/Aeronautics" <<"Technician/Cybernetics" <<"Technician/Electronic" <<"Technician/Jet" <<"Technician/Mechanical" <<"Technician/Myomer" <<"Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem1 = 15;

            subAffElem2Label = "Interests/Any";
            subAffElem2.append(CreateSubSkillList("Interests")); // << "Interests/Battlemechs" << "Interests/Battlesuits" << "Interests/Aerospace" << "Interests/Spacecraft" << "Interests/Aircraft" << "Interests/Ground Vehicles" << "Interests/Sea Vehicles" << "Interests/Rail Vehicles" << "Interests/History (Star League)" << "Interests/History (Terran)" << "Interests/History (Clan)" << "Interests/History (Inner Sphere)" << "Interests/History (Periphery)" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports" << "Interests/Weapons" << "Interests/Martial Arts" << "Interests/GameMastering for Battletech";
            affSkillsElem2 = 10;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem1More = 25;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem2More = 25;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem3More = 25;

            break;
            //Rim Collection
        case 5:
            affAttr["CHA"] = -50;
            affAttr["EDG"] = 100;

            addSubTraits("Fit", 75);
            addSubTraits("Wealth", -50);

            addSubSkills("Negotiation", 15);
            addSubSkills("Small Arms", 5);
//            addSubSkills("Choose two: Animal Handling, Archery, Martial Arts, Melee Weapons, Streetwise/Rim Collection or Survival/Any", 10);
            subAffElem1Label = "Choose one";
            subAffElem1 << "Animal Handlin" << "Archery" << "Martial Arts" << "Melee Weapons" << "Streetwise/Rim Collection" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Animal Handlin" << "Archery" << "Martial Arts" << "Melee Weapons" << "Streetwise/Rim Collection" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2 = 10;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem1More = 25;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem2More = 25;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth";
            affSkillsElem3More = 25;

            break;
        }
        break;
        //---------------------------------------- MAJOR PERIPHERY STATE
    case 7:
        switch(secPos) {
            // Circinus Federation
        case 1:
//            addSubSkills("German, Spanish", 10);
            secLang.clear();
            secLang << "Language/German" << "Language/Spanish";
            listLang = primLang + secLang;
            affAttr["STR"] = 100;
            affAttr["BOD"] = 75;
            affAttr["INT"] = -100;
            affAttr["WIL"] = 70;
            addSubTraits("Illiterate", -75);
            addSubTraits("Reputation", -200);
            addSubTraits("Toughness", 300);
            addSubTraits("Wealth", -125);

//            addSubSkills("Choose three: Animal Handling, Martial Arts, MedTech, Small Arms, Streetwise, Survival/Any or Tracking/Any", 10);
            subAffElem1Label = "Choose one";
            subAffElem1 << "Animal Handlin" << "MedTech" << "Martial Arts" << "Small Arms" << "Streetwise" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert" << "Tracking/Urban" << "Tracking/Wilds";
            affSkillsElem1 = 20;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Animal Handlin" << "MedTech" << "Martial Arts" << "Small Arms" << "Streetwise" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert" << "Tracking/Urban" << "Tracking/Wilds";
            affSkillsElem2 = 20;

            subAffElem3Label = "Choose one";
            subAffElem3 << "Animal Handlin" << "MedTech" << "Martial Arts" << "Small Arms" << "Streetwise" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert" << "Tracking/Urban" << "Tracking/Wilds";
            affSkillsElem3 = 20;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 15;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem1More.append(CreateSubSkillList("Art"));
            affSkillsElem1More = 15;

            subAffElem2LabelMore = "Flexible XPs: chose one";
//            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem2More.append(CreateSubSkillList("Art"));
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Flexible XPs: chose one";
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More.append(CreateSubSkillList("Art"));
            affSkillsElem3More = 15;



            break;
            //Magistracy of Canopus
        case 2:
//            addSubSkills("Greek, Romanian, Spanish, Urdu", 10);
            secLang.clear();
            secLang << "Language/Greek" << "Language/Romanian" << "Language/Spanish" << "Language/Urdu";
            listLang = primLang + secLang;

            affAttr["CHA"] = 100;
            affAttr["EDG"] = 50;

            addSubTraits("Gregarious", 50);
            addSubTraits("Illiterate", -25);
            addSubTraits("Reputation", -125);
            addSubTraits("Wealth", 25);

            addSubSkills("Streetwise/Magistracy", 15);
//            addSubSkills("+15 XP to either one of the following: Acting or MedTech", 15);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Acting" << "MedTech";
            affSkillsElem1 = 15;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 15;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem1More = swpList;
            subAffElem1More.append(CreateSubSkillList("Art"));
            subAffElem1More.append(CreateSubSkillList("Interests"));
//            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 15;



            subAffElem2LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem2More = swpList;
            subAffElem2More.append(CreateSubSkillList("Art"));
            subAffElem2More.append(CreateSubSkillList("Interests"));
//            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More = swpList;
            subAffElem3More.append(CreateSubSkillList("Art"));
            subAffElem3More.append(CreateSubSkillList("Interests"));
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3More = 15;

            break;
            //Marian Hegemony
        case 3:
//            addSubSkills("Latin, French, German, Greek, Spanish, Swedish", 10);
            secLang.clear();
            secLang << "Language/Latin" << "Language/French" << "Language/German" << "Language/Greek" << "Language/Spanish" << "Language/Swedish";
            listLang = primLang + secLang;

            affAttr["WIL"] = 100;

            addSubTraits("Compulsion/Paranoid", -50);
            addSubTraits("Connections", 25);
            addSubTraits("Reputation", -150);
            addSubTraits("Toughness", 125);

            addSubSkills("Interests/Marian History", 15);
            addSubSkills("Interests/Roman History", 10);
            addSubSkills("Language/Latin", 15);
            addSubSkills("Protocol/Marian", 10);
            addSubSkills("Strategy", 5);

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 15;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem1More.append(CreateSubSkillList("Art"));
//            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 15;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More.append(CreateSubSkillList("Art"));
//            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More.append(CreateSubSkillList("Art"));
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3More = 15;

            break;
            // Outworlds Alliance
        case 4:
//            addSubSkills("French, Japanese", 10);
            secLang.clear();
            secLang << "Language/French" << "Language/Japanese";
            listLang = primLang + secLang;

            affAttr["EDG"] = 75;

            addSubTraits("Equipped", -55);
            addSubTraits("G-Tolerance", 125);
            addSubTraits("Wealth", -75);

            addSubSkills("Streetwise/Outworlds", 10);
//            addSubSkills("Survival/Any", 10);
//            addSubSkills("Choose one: Martial Arts, MedTech or Small Arms", 15);
            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Martial Arts" << "MedTech" << "Small Arms";
            affSkillsElem2 = 15;

            //            subAffElem4Label = "Flexible XPs: chose any three";
            //            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            //            affTraitsElem4 = 15;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem1More.append(CreateSubSkillList("Art"));
//            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 15;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem2More.append(CreateSubSkillList("Art"));
//            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More.append(CreateSubSkillList("Art"));
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3More = 15;

            break;
            //Taurian Concordat
        case 5:
//            addSubSkills("French, Spanish", 10);
            secLang.clear();
            secLang << "Language/French" << "Language/Spanish";
            listLang = primLang + secLang;

            affAttr["WIL"] = 150;
            affAttr["EDG"] = 50;

            addSubTraits("Compulsion/Distrust FedSuns", -75);
            addSubTraits("Compulsion/Stubborn", -75);

            addSubSkills("Martial Arts", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Small Arms", 15);
            addSubSkills("Streetwise/Taurian", 15);
//            addSubSkills("Survival/Any", 5);

            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 5;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 15;

            subAffElem1LabelMore = "Flexible XPs: chose one";
            QStringList swpList;
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem1More.append(CreateSubSkillList("Art"));
//            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 15;

            subAffElem2LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem2More.append(CreateSubSkillList("Art"));
//            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Flexible XPs: chose one";
            swpList.clear();
            swpList << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            subAffElem3More.append(CreateSubSkillList("Art"));
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3More = 15;

            break;
        }
        break;
        //---------------------------------------- DEEP PERIPHERY
    case 8:
        switch(secPos) {
            // Hanseatic League
        case 1:
//            addSubSkills("German, English", 10);
            secLang.clear();
            primLang.clear();
            primLang << "Language/German";

            secLang << "Language/English" ;
            listLang = primLang + secLang;

            addSubTraits("Citizenship", 30);
            addSubTraits("Compulsion/Distrust Lyrans", -20);
//            addSubTraits("Compulsion/Distrust Lyrans", -20);

            addSubSkills("Appraisal", 10);
            addSubSkills("Negotiation", 20);
            addSubSkills("Protocol/Hanseatic", 10);
//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;

//            subAffElem3LabelMore = "Chose one";
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affSkillsElem3More = 10;

            break;
            //Castilian Principalities
        case 2:
            secLang.clear();
            primLang.clear();
            primLang << "Language/Spanish";

            secLang << "Language/German" ;
            listLang = primLang + secLang;

            affAttr["DEX"] = 25;

            addSubTraits("Compulsion/Castilian Honor Code", -20);
            addSubTraits("Compulsion/Hatred of Umayyads", -20);

            addSubSkills("Martial Arts/Basic", 15);
            addSubSkills("Melee Weapons", 15);
            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Castilian", 25);

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;

//            subAffElem3LabelMore = "Chose one";
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affSkillsElem3More = 25;

            break;
            //Umayyad Caliphate
        case 3:
//            addSubSkills("Arabic, English", 10);
            secLang.clear();
            primLang.clear();
            primLang << "Language/Arabic";

            secLang << "Language/English" ;
            listLang = primLang + secLang;
            affAttr["DEX"] = 20;

            addSubTraits("Compulsion/Xenophobic", -10);

//            addSubSkills("Art/Any", 10);
//            addSubSkills("Interests/Any", 10);
            addSubSkills("Protocol/Umayyad", 20);

            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art")); // << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 10;

            subAffElem2Label = "Interests/Any";
            subAffElem2.append(CreateSubSkillList("Interests")); // << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            affSkillsElem2 = 10;

//            subAffElem4Label = "Flexible XPs: chose any two";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;


            break;
            // JarnFolk
        case 4:
//            addSubSkills("JarnFolk Norse, Danish, English, German, Swedish", 10);
            secLang.clear();
            primLang.clear();
            primLang << "JarnFolk Norse";

            secLang << "Danish" << "Language/English" << "Language/German" << "Language/Swedish";
            listLang = primLang + secLang;
            affAttr["RFL"] = 20;

            addSubTraits("Compulsion/Xenophobic", -10);
            addSubTraits("Natural Aptitude/Martial Arts", 10);
            addSubTraits("Wealth", -10);

            addSubSkills("Negotiation", 15);
            addSubSkills("Protocol/JarnFolk Families", 15);
//            addSubSkills("Choose one: Arts/Any, Interests/Any or Technician/Any ", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem1 = 10;

//            subAffElem4Label = "Flexible XPs: chose any three";
//            subAffElem4 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affTraitsElem4 = 25;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;

//            subAffElem3LabelMore = "Chose one";
//            subAffElem3More << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG" << "Alternate ID" << "Ambidextrous" << "Animal Antipathy" << "Animal Empathy" << "Attractive" << "Bloodmark" << "Citizenship/Inner Sphere" << "Citizenship/Clan" << "Combat Paralysis" << "Combat Sense" << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of Word of Blake" << "Compulsion/Hatred of ComStar" << "Compulsion/Hatred of Clans" << "Compulsion/Hatred of Clans" << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine" << "Compulsion/Rasalhague Pride" << "Compulsion/Gambling" << "Compulsion/Distrust of Inner Sphere" << "Compulsion/Hatred for Authority" << "Compulsion/Loyalty to Crime Boss" << "Compulsion/Chemical Addiction" << "Compulsion/Smoking" << "Connections" << "Custom Vehicle" << "Dark Secret" << "Dependent" << "Design Quirk/" << "Enemy" << "Equipped" << "Exceptional Attribute" << "Extra Income" << "Fast Learner" << "Fit Trait" << "G-Tolerance" << "Glass Jaw" << "Good Hearing" << "Good Vision" << "Gregarious" << "Gremlins" << "Handicap" << "Illiterate" << "Impatient" << "Implant/Prosthetic" << "In For Life" << "Introvert" << "Lost Limb" << "Natural Aptitude" << "Pain Resistance" << "Patient" << "Phenotype" << "Poison Resistance" << "Poor Hearing" << "Poor Vision" << "Property Trait" << "Rank" << "Reputation" << "Sixth Sense" << "Tech Empathy" << "Thick-Skinned" << "Thin-Skinned" << "Thin-Skinned" << "Title/Inner Sphere" << "Title/Clan" << "Transit Disorientation Syndrome" << "Unattractive" << "Unlucky" << "Vehicle" << "Wealth"  << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affSkillsElem3More = 25;

            break;
        }
        break;
        //---------------------------------------- INVADING CLAN
    case 9:
        switch(secPos) {
            // Diamond Shark
        case 1:
            affAttr["STR"] = -45;
            affAttr["INT"] = 25;
            affAttr["EDG"] = -50;

            addSubTraits("Connections", 25);
            addSubTraits("Equipped", 25);
            addSubTraits("Wealth", 30);

            addSubSkills("Perception", 10);
            addSubSkills("Negotiation", 20);
            addSubSkills("Protocol/Diamond Shark", 10);
            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";

            break;
            //Ghost Bear
        case 2:
            affAttr["STR"] = 25;
            affAttr["BOD"] = 25;

            addSubTraits("Compulsion/Hate Hell's Horses", -25);
            addSubTraits("Exceptional Attribute/STR", 50);
            addSubTraits("Slow Learner", -50);

//            addSubSkills("Art/Any", 10);

            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art")); // << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 10;

            addSubSkills("Protocol/Ghost Bear", 10);
            addSubSkills("Streetwise/Rasalhague", 5);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Elemental-Advanced" << "ProtoMech" << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            //Hell’s Horses
        case 3:
            affAttr["STR"] = 25;
            affAttr["BOD"] = 25;

            addSubTraits("Compulsion/Hate Ghost Bears", -25);
            addSubTraits("Introvert", -30);

            addSubSkills("Melee Weapons", 10);
            addSubSkills("Navigation/Ground", 15);
            addSubSkills("Protocol/Hell`s Horses", 15);
            addSubSkills("Survival/Desert", 15);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Elemental-Advanced" << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            // Jade Falcon
        case 4:
            affAttr["WIL"] = 25;

            addSubTraits("Compulsion/Falcon Pride", -75);
            addSubTraits("Compulsion/Hate Steel Vipers", -50);
            addSubTraits("Reputation", 100);

            addSubSkills("Acting/Intimidation", 10);
            addSubSkills("Martial Arts", 15);
            addSubSkills("Protocol/Jade Falcon", 15);
            addSubSkills("Survival/Forests", 10);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            //Nova Cat
        case 5:
            affAttr["EDG"] = 120;

            addSubTraits("Enemy/The Clans", -100);
            addSubTraits("Enemy/Draconis Combine", -50);
            addSubTraits("Equipped", 50);
            addSubTraits("Reputation", -100);
            addSubTraits("Sixth Sense", 100);

            addSubSkills("Interests/Nova Cat Vision Quest", 10);
            addSubSkills("Language/Japanese", 5);
            addSubSkills("Protocol/Draconis Combine", 5);
            addSubSkills("Protocol/Nova Cat", 10);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";

            break;
            // Snow Raven
        case 6:
            affAttr["INT"] = 20;

            addSubTraits("Compulsion/Raven Pride", -50);
            addSubTraits("Connections", 50);

            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Snow Raven", 10);
            addSubSkills("Zero-G Operations", 10);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Aerospace-Naval" << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            // Wolf
        case 7:
            affAttr["INT"] = 25;
            affAttr["WIL"] = 25;

            addSubTraits("Compulsion/Wolf Pride", -50);
            addSubTraits("Equipped", 50);
            addSubTraits("Enemy", -100);
            addSubTraits("Reputation", 70);

            addSubSkills("Protocol/Wolf", 10);
//            addSubSkills("Choose two: Interests/Any, Leadership, Negotiation, Perception or Strategy", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Leadership" << "Negotiation" << "Perception" << "Strategy";
            subAffElem1.append(CreateSubSkillList("Interests")); //
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Leadership" << "Negotiation" << "Perception" << "Strategy" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            affSkillsElem2 = 10;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
        }
        break;
        //---------------------------------------- HOMEWORLD CLAN
        case 10:
        switch(secPos) {
            // Blood Spirit
        case 1:
            affAttr["BOD"] = 25;
            affAttr["WIL"] = 100;
            affAttr["CHA"] = -50;

            addSubTraits("Combat Sense", 100);
            addSubTraits("Compulsion/Blood Spirit Fanaticism", -100);
            addSubTraits("Compulsion/Hate Star Adder", -100);
            addSubTraits("Equipped", -65);
            addSubTraits("Exceptional Attribute/WIL", 200);
            addSubTraits("Introvert", -50);
            addSubTraits("Reputation", -50);

            addSubSkills("Interests/Clan History", 25);
            addSubSkills("Martial Arts", 15);
            addSubSkills("Small Arms", 15);
            addSubSkills("Protocol/Blood Spirit", 10);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";

            break;
            //Cloud Cobra
        case 2:
            affAttr["INT"] = 50;
            affAttr["WIL"] = 50;

            addSubTraits("Compulsion/Religious Faith", -75);
            addSubTraits("Equipped", -25);
            addSubTraits("Patient", 100);
            addSubTraits("Reputation", -75);

//            addSubSkills("Art/Any", 10);
            addSubSkills("Interests/Theology/Any", 20);
            addSubSkills("Protocol/Cloud Cobra", 20);
//            addSubSkills("+10 XP to any one other Skill ", 10);

            subAffElem1Label = "Art/Any";
            subAffElem1.append(CreateSubSkillList("Art")); // << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2 = 10;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            //Coyote
        case 3:
            affAttr["INT"] = 100;
            affAttr["WIL"] = -60;
            affAttr["EDG"] = 25;

            addSubTraits("Equipped", 25);
            addSubTraits("Reputation", -60);
//            addSubTraits("Choose one: Custom Vehicle, Natural Aptitude/Computers, Natural Aptitude/Technician/Any or Vehicle Level", 10);

            addSubSkills("Interests/Coyote Rituals", 15);
            addSubSkills("Protocol/Coyote", 10);
//            addSubSkills("Survival/Any", 10);

            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Custom Vehicle" << "Natural Aptitude/Computers" << "Natural Aptitude/Technician/Any" << "Vehicle Level";
            affTraitsElem2 = 10;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            // Fire Mandrill
        case 4:
            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Chinese" << "Language/French" << "Language/German" << "Language/Japanese" << "Language/Russian" << "Language/Spanish";
            listLang = primLang + secLang;
//            addSubSkills("Chinese, French, German, Japanese, Russian, Spanish", 10);

            affAttr["WIL"] = 25;
//            affAttr["WIL"] = 75; // SEE RULES!
//            affAttr["WIL"] = -25; // SEE RULES!

            addSubTraits("Compulsion/Fire Mandrill Fanaticism", -100);
            addSubTraits("Compulsion/Kindraa Fanaticism", -100);
            addSubTraits("Enemy/Rival Kindraa", -25);
            addSubTraits("Reputation", -25);
//            addSubTraits("Choose one: Combat Sense, Exceptional Attribute/Any, Fast Learner, Natural Aptitude/Any or Sixth Sense", 150);

            addSubSkills("Language/Secondary", 20);
            addSubSkills("Martial Arts", 15);
            addSubSkills("Protocol/Fire Mandrill", 15);
            addSubSkills("Protocol/Kindraa", 25);
//            addSubSkills("Choose two: Leadership, Melee Weapons, Negotiation, Perception or Tactics/Any", 10);

            subAffElem3Label = "Choose one";
            subAffElem3 << "Combat Sense" << "Exceptional Attribute/STR" << "Exceptional Attribute/BOD" << "Exceptional Attribute/RFL" << "Exceptional Attribute/DEX" << "Exceptional Attribute/INT" << "Exceptional Attribute/WIL" << "Exceptional Attribute/CHA" << "Exceptional Attribute/EDG" << "Fast Learner" << "Natural Aptitude/Any" << "Sixth Sense";
            affTraitsElem3 = 150;

            subAffElem1Label = "Choose one";
            subAffElem1 << "Leadership" << "Melee Weapons" << "Negotiation" << "Perception" << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Leadership" << "Melee Weapons" << "Negotiation" << "Perception" << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            affSkillsElem2 = 10;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            affElem2.clear();
            affElem2 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA" << "EDG";
            break;
            //Goliath Scorpion
        case 5:
            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Russian";
            listLang = primLang + secLang;
//            addSubSkills("Goliath Scorpion Battle Language (warrior caste only), Russian", 10);

            affAttr["DEX"] = 50;
            affAttr["INT"] = 50;
            affAttr["WIL"] = -50;
            affAttr["EDG"] = -50;

            addSubTraits("Compulsion/Necrosia Addiction", -50);
            addSubTraits("Compulsion/Nostalgic", -50);
            addSubTraits("Fit", 55);
            addSubTraits("Reputation", -25);
//            addSubTraits("Choose one: Exceptional Attribute/INT, Natural Aptitude/Gunnery/Any, Natural Aptitude/Melee Weapons or Natural Aptitude/Interests/Any", 100);

            addSubSkills("Interests/Star League History", 20);
            addSubSkills("Melee Weapons", 15);
            addSubSkills("Protocol/Goliath Scorpion", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Exceptional Attribute/INT" << "Natural Aptitude/Gunnery/Any" << "Natural Aptitude/Melee Weapons" << "Natural Aptitude/Interests/Any";
            affTraitsElem1 = 100;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            // Ice Hellion
        case 6:
            affAttr["DEX"] = 75;
            affAttr["RFL"] = 100;
            affAttr["WIL"] = 50;
            affAttr["CHA"] = -75;

            addSubTraits("Combat Sense", 50);
            addSubTraits("Impatient", -100);
            addSubTraits("Reputation", -95);

            addSubSkills("Interests/Clan Remembrance", 15);
            addSubSkills("Martial Arts", 10);
            addSubSkills("Negotiation", 15);
            addSubSkills("Protocol/Ice Hellion", 10);
            addSubSkills("Swimming", 10);
            addSubSkills("Survival/Arctic", 10);

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            // Star Adder
        case 7:
            affAttr["INT"] = 50;
            affAttr["WIL"] = 75;
            affAttr["CHA"] = -70;

            addSubTraits("Combat Sense", 50);
            addSubTraits("Compulsion/Clan Honor", -50);
            addSubTraits("Equipped", 25);
            addSubTraits("Reputation", 25);
//            addSubTraits("Choose one: Compulsion/Adder Arrogance or Compulsion/Burrock Forever!", 60);


            addSubSkills("Leadership", 10);
            addSubSkills("Perception", 10);
            addSubSkills("Protocol/Star Adder", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Compulsion/Adder Arrogance" << "Compulsion/Burrock Forever!";
            affTraitsElem1 = -60;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
            //Steel Viper
        case 8:
            affAttr["INT"] = 75;
            affAttr["WIL"] = 100;
            affAttr["CHA"] = -50;

            addSubTraits("Compulsion/Hate Jade Falcons", -100);
            addSubTraits("Compulsion/Clan Honor", -100);
            addSubTraits("Compulsion/Hate Snow Ravens", -50);
            addSubTraits("Connections", 50);
            addSubTraits("Equipped", 50);
            addSubTraits("Reputation", 50);

            addSubSkills("Negotiation", 15);
            addSubSkills("Survival/Any", 20);
            addSubSkills("Protocol/Steel Viper", 15);

            subAffElem1Label = "Survival/Any";
            subAffElem1.append(CreateSubSkillList("Survival")); // << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 20;

            affElem1.clear();
            affElem1 << "MechWarrior" << "Elemental"
                    << "Aerospace" << "ProtoMech"
                    << "Warrior Caste(Other)"
                    << "Scientist Caste" << "Technician Caste"
                    << "Merchant Caste" << "Laborer Caste";
            break;
        }
        break;
        //---------------------------------------- TERRAN
            case 11:
        switch(secPos) {
            // Belter
        case 1:
            affAttr["STR"] = -25;
            affAttr["BOD"] = -25;
//            affAttr["STR"] = 100; // SEE RULEZ!!!!!!

            addSubTraits("Compulsion/Xenophobia", -100);
            addSubTraits("Reputation", -50);
            addSubTraits("Wealth", 50);
//            addSubTraits("Choose two: Ambidextrous, Attractive, Exception Attribute/Any, Fast Learner, G-Tolerance, Good Hearing, Good Vision, Implant/Prosthetics, Pain Resistance or Toughness", 50);

            addSubSkills("Navigation/Space", 15);
            addSubSkills("Survival", 20);
            addSubSkills("Zero-G Operations", 15);
//            addSubSkills("Choose two: Driving, Interests/Any, Language/Any, MedTech, Piloting/Any, Sensor Operations or Technician/Any", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Ambidextrous" << "Attractive" << "Fast Learner" << "G-Tolerance" << "Good Hearing" << "Good Vision" << "Implant/Prosthetics" << "Pain Resistance" << "Toughness" << "Exception Attribute/STR" << "Exception Attribute/BOD" << "Exception Attribute/RFL" << "Exception Attribute/DEX" << "Exception Attribute/INT" << "Exception Attribute/WIL" << "Exception Attribute/CHA" << "Exception Attribute/EDG";
            affTraitsElem1 = 50;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Ambidextrous" << "Attractive" << "Fast Learner" << "G-Tolerance" << "Good Hearing" << "Good Vision" << "Implant/Prosthetics" << "Pain Resistance" << "Toughness" << "Exception Attribute/STR" << "Exception Attribute/BOD" << "Exception Attribute/RFL" << "Exception Attribute/DEX" << "Exception Attribute/INT" << "Exception Attribute/WIL" << "Exception Attribute/CHA" << "Exception Attribute/EDG";
            affTraitsElem2 = 50;

//            subAffElem2Label = "Choose two";
//            subAffElem2 << "Driving" << "MedTech" << "Sensor Operations" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Piloting/Aerospace" << "Piloting/Air Vehicle" << "Piloting/Battlesuit" << "Piloting/Ground Vehicle" << "Piloting/Mech" << "Piloting/ProtoMech" << "Piloting/Rail Vehicle" << "Piloting/Sea Vehicle" << "Piloting/Spacecraft" << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons"<< "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
//            affSkillsElem2 = 10;

            subAffElem3Label = "Choose one";
            subAffElem3 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL";
            affAttrElem3 = 100;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "Driving" << "MedTech" << "Sensor Operations" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Piloting/Aerospace" << "Piloting/Air Vehicle" << "Piloting/Battlesuit" << "Piloting/Ground Vehicle" << "Piloting/Mech" << "Piloting/ProtoMech" << "Piloting/Rail Vehicle" << "Piloting/Sea Vehicle" << "Piloting/Spacecraft" << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons"<< "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "Driving" << "MedTech" << "Sensor Operations" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Piloting/Aerospace" << "Piloting/Air Vehicle" << "Piloting/Battlesuit" << "Piloting/Ground Vehicle" << "Piloting/Mech" << "Piloting/ProtoMech" << "Piloting/Rail Vehicle" << "Piloting/Sea Vehicle" << "Piloting/Spacecraft" << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons"<< "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem2More = 10;

            break;
            //Lunar Citizen
        case 2:
            affAttr["STR"] = -20;
            affAttr["BOD"] = -20;
            affAttr["INT"] = 50;
            affAttr["WIL"] = 40;
            affAttr["EDG"] = -25;

            addSubTraits("Equipped", 25);
            addSubTraits("Poor Vision", -25);
            addSubTraits("Thick-Skinned", 25);
            addSubTraits("Wealth", 50);

//            addSubSkills("Technician/Any", 5);
//            addSubSkills("Choose one: Arts/Any, Computers, Interests/Any, Survival/Any or Zero-G Operations", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem1 = 5;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Computers" << "Zero-G Operations" << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2 = 10;

            break;
            //Martian Citizen
        case 3:
            affAttr["STR"] = -15;
            affAttr["WIL"] = 50;

            addSubTraits("Equipped", 65);
            addSubTraits("Introvert", -25);
            addSubTraits("Poor Vision", -25);
            addSubTraits("Reputation", -25);
            addSubTraits("Thick-Skinned", 25);
            addSubTraits("Wealth", 35);

//            addSubSkills("Language/Any one previously chosen secondary Language Skill", -10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Survival/Martian Desert", 10);
//            addSubSkills("Choose one: Arts/Any, Computers, Interests/Any, Martial Arts, MedTech, Melee Weapons or Small Arms", 15);

            subAffElem1Label = "secondary Language Skill";
            subAffElem1 << "Language/English";
            affSkillsElem1 = -10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Small Arms" << "Melee Weapons" << "MedTech" << "Martial Arts" << "Computers" << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            affSkillsElem2 = 15;

            break;
            // Outer System Citizen
        case 4:
            affAttr["STR"] = -15;
            affAttr["BOD"] = -15;
            affAttr["RFL"] = 20;

            addSubTraits("Equipped", 75);
            addSubTraits("Wealth", -25);
            addSubTraits("Reputation", -20);

            addSubSkills("Negotiation", 10);
//            addSubSkills("Technician/Any", 10);
//            addSubSkills("Choose two: Arts/Any, Computers, Driving, Interests/Any, Martial Arts, Survival/Any or Zero-G Operations", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Zero-G Operations" << "Martial Arts" << "Driving" << "Computers" << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Zero-G Operations" << "Martial Arts" << "Driving" << "Computers" << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2 = 10;

            subAffElem3Label = "Technician/Any";
            subAffElem3.append(CreateSubSkillList("Technician")); // << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem3 = 10;




            break;
            //Terran Citizen
        case 5:
            affAttr["EDG"] = -100;

            addSubTraits("Compulsion/Distrust of Non-Terrans", -75);
            addSubTraits("Connections", 100);
            addSubTraits("Equipped", 100);
            addSubTraits("Impatient", -50);
            addSubTraits("Wealth", 110);

            addSubSkills("Interests/Terran History", 10);
            addSubSkills("Perception", -5);
//            addSubSkills("+5 XP to any four other Skills", 5);

            subAffElem1Label = "Chose one";
            subAffElem1 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1 = 5;

            subAffElem2Label = "Chose one";
            subAffElem2 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2 = 5;

            subAffElem3Label = "Chose one";
            subAffElem3 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3 = 5;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 5;

            break;
            // Venusian Citizen
        case 6:
            affAttr["BOD"] = 35;
            affAttr["INT"] = -25;
            affAttr["WIL"] = 35;

            addSubTraits("Equipped", 25);
            addSubTraits("Introvert", -50);
            addSubTraits("Reputation", -25);
            addSubTraits("Thick-Skinned", 75);
            addSubTraits("Wealth", 15);

//            addSubSkills("Language/Any one previously chosen secondary Language Skil", -10);
//            addSubSkills("Survival/Any", 20);
//            addSubSkills("Choose one: Arts/Any, Computers, Interests/Any, Martial Arts, MedTech, Melee Weapons or Technician/Any", 15);

            subAffElem1Label = "secondary Language Skill";
            subAffElem1 << "Language/English";
            affSkillsElem1 = -10;

            subAffElem2Label = "Survival/Any";
            subAffElem2 << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2 = 20;

            subAffElem3Label = "Choose one";
            subAffElem3 << "Melee Weapons" << "MedTech" << "Martial Arts" << "Computers" << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs" << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            affSkillsElem3 = 15;
            break;
        }
        break;
        //---------------------------------------- INDEPENDENT
            case 12:
        switch(secPos) {
            // Antallos
        case 1:
//            addSubSkills("English, Any", 15);

            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

            affAttr["BOD"] = 20;
            affAttr["WIL"] = 10;
            affAttr["CHA"] = -10;

            addSubTraits("Illiterate", -20);
            addSubTraits("Pain Resistance", 10);
            addSubTraits("Reputation", -20);
            addSubTraits("Toughness", 10);

            addSubSkills("Language/Japanese", 10);
            addSubSkills("Perception", 10);
            addSubSkills("Streetwise/Periphery", 10);
//            addSubSkills("Choose two: Acting, Escape Artist, Martial Arts, Melee Weapons, Small Arms or Survival/Desert", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert";
            affSkillsElem2 = 10;

            break;
            //Astrokaszy
        case 2:
//            addSubSkills("Arabic, English, German, Greek", 10);
            secLang.clear();
            primLang.clear();
            primLang << "Language/Arabic";

            secLang << "Language/English" << "Language/German" << "Language/Greek";
            listLang = primLang + secLang;

            affAttr["BOD"] = 15;
            affAttr["WIL"] = 10;
            affAttr["EDG"] = -10;
            affAttr["CHA"] = -10;

            addSubTraits("Fit", 20);
            addSubTraits("Compulsion/Xenophobic", -20);
            addSubTraits("Illiterate", -20);
            addSubTraits("Reputation", -10);
            addSubTraits("Thick-Skinned", 15);

            addSubSkills("Perception", 10);
            addSubSkills("Protocol/Astrokaszy", 10);
            addSubSkills("Streetwise/Periphery", 10);
//            addSubSkills("Choose two: Acting, Martial Arts, Melee Weapons, Small Arms, Survival/Desert or Thrown Weapons", 15);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Acting" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Thrown Weapons";
            affSkillsElem1 = 10;

            subAffElem2Label = "Choose one";
            subAffElem2 << "Acting" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Thrown Weapons";
            affSkillsElem2 = 10;

            break;
            //Generic
        case 3:
//            addSubSkills("Any from nearest state", 10);

            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

            affAttr["STR"] = -15;
            affAttr["WIL"] = 50;

            addSubTraits("Introvert", -10);

//            addSubSkills("Interests/Any", 10);
            addSubSkills("Negotiation", 10);
//            addSubSkills("any four other Skills", 10);

//            subAffElem1Label = "any four other Skills";
//            subAffElem1 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
//            affSkillsElem1 = 10;

            subAffElem1Label = "Interests/Any";
            subAffElem1.append(CreateSubSkillList("Interests")); // << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            affSkillsElem1 = 10;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem2More = 10;

            subAffElem3LabelMore = "Chose one";
            subAffElem3More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem3More = 10;

            subAffElem4LabelMore = "Chose one";
            subAffElem4More << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem4More = 10;

            break;
            // Mercenary
        case 4:

            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

//            addSubSkills("English, Any", 10);
            affAttr["CHA"] = -20;

            addSubTraits("Equipped", 20);
            addSubTraits("Rank", 20);

            addSubSkills("Negotiation", 10);
            addSubSkills("Protocol/Mercenary", 10);
//            addSubSkills("10 XP to any one other Skill", 10);

            subAffElem1Label = "any one other Skill";
            subAffElem1 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/" << "Interrogation" << "Investigation" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Piloting" << "Prestidigitation" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
            affSkillsElem1 = 10;

            break;
            //Pirate
        case 5:

            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

//            addSubSkills("Any, Any from nearest state", 10);
            affAttr["BOD"] = 20;
            affAttr["WIL"] = 10;
            affAttr["CHA"] = -30;

            addSubTraits("Pain Resistance", 10);
            addSubTraits("Reputation", -30);
            addSubTraits("Toughness", 10);

//            addSubSkills("Language/Any", 10);
            addSubSkills("Negotiation", 5);
            addSubSkills("Perception", 15);
//            addSubSkills("Choose three: Acting, Escape Artist, Martial Arts, Melee Weapons, Small Arms or Survival/Any", 15);


//            subAffElem1Label = "Choose three";
//            subAffElem1 << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
//            affSkillsElem1 = 15;

            subAffElem1Label = "Language/Any";
            subAffElem1.append(CreateSubSkillList("Language")); // ;
            affSkillsElem1 = 10;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem1More = 15;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem2More = 15;

            subAffElem3LabelMore = "Chose one";
            subAffElem3More << "Acting" << "Escape Artist" << "Martial Arts" << "Melee Weapons" << "Small Arms" << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            affSkillsElem3More = 15;

            break;
            // Spacer
        case 6:

            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

//            addSubSkills("English, Any from nearest state", 10);
            affAttr["BOD"] = -20;
            affAttr["STR"] = -10;
            affAttr["DEX"] = 10;
            affAttr["RFL"] = 10;

            addSubTraits("Equipped", 10);
            addSubTraits("G-Tolerance", 20);
            addSubTraits("Introvert", -20);
            addSubTraits("Natural Aptitude/Zero-G Operations", 20);


            addSubSkills("Career/Ship's Crew", 10);
            addSubSkills("Zero-G Operations", 10);
//            addSubSkills("Choose one: Appraisal, Interests/Any, Navigation/Space, Negotiation or Sensor Operations", 10);

            subAffElem1Label = "Choose one";
            subAffElem1 << "Appraisal" << "Navigation/Space" << "Negotiation" << "Sensor Operations" << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            affSkillsElem1 = 10;

            break;
            // Tortuga
        case 7:
            secLang.clear();
            primLang.clear();
            primLang << "Language/English";

            secLang << "Language/French" << "Language/Spanish" << "Language/German" << "Language/Italian" << "Language/Scots Gaelic" << "Language/Swedish";
            listLang = primLang + secLang;

//            addSubSkills("English, Any Taurian or FedSuns Primary or Secondary Language", 10);

            affAttr["BOD"] = 10;
            affAttr["STR"] = 10;
            affAttr["WIL"] = 20;
            affAttr["CHA"] = -40;

            addSubTraits("Pain Resistance", 10);
            addSubTraits("Reputation", -50);
            addSubTraits("Toughness", 10);

//            addSubSkills("Language/Any", 10);
            addSubSkills("Martial Arts", 10);
            addSubSkills("Negotiation", 10);
            addSubSkills("Perception", 10);
            addSubSkills("Streetwise/Periphery", 10);
//            addSubSkills("Choose three: Acting, Escape Artist, Melee Weapons, Small Arms or Survival", 10);

//            subAffElem1Label = "Choose three";
//            subAffElem1 << "Acting" << "Escape Artist" << "Melee Weapons" << "Small Arms" << "Survival";
//            affSkillsElem1 = 10;

            subAffElem1Label = "Language/Any";
            subAffElem1.append(CreateSubSkillList("Language")); // << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            affSkillsElem1 = 10;

            subAffElem1LabelMore = "Chose one";
            subAffElem1More << "Acting" << "Escape Artist" << "Melee Weapons" << "Small Arms" << "Survival";
            affSkillsElem1More = 10;

            subAffElem2LabelMore = "Chose one";
            subAffElem2More << "Acting" << "Escape Artist" << "Melee Weapons" << "Small Arms" << "Survival";
            affSkillsElem2More = 10;

            subAffElem3LabelMore = "Chose one";
            subAffElem3More << "Acting" << "Escape Artist" << "Melee Weapons" << "Small Arms" << "Survival";
            affSkillsElem3More = 10;

            break;
        }
        break;
    }

}

void Text_Resurce::clanCaste(QString nameCaste) {
    subAffElem3Label.clear();
    subAffElem4Label.clear();
    subAffElem3.clear();
    subAffElem4.clear();
    affSkillsElem3 = 0;
    affTraitsElem3 = 0;

    affSkillsElem4 = 0;
    affTraitsElem4 = 0;

    subAffElem1LabelMore.clear();
    subAffElem1More.clear();
    affSkillsElem1More = 0;

    subAffElem2LabelMore.clear();
    subAffElem2More.clear();
    affSkillsElem2More = 0;

    subAffElem3LabelMore.clear();
    subAffElem3More.clear();
    affSkillsElem3More = 0;

    subAffElem4LabelMore.clear();
    subAffElem4More.clear();
    affSkillsElem4More = 0;

    if (nameCaste == "MechWarrior") {
        affAttrCast["DEX"] = 75;
        affAttrCast["RFL"] = 75;
        affAttrCast["WIL"] = 75;
        affAttrCast["CHA"] = -25;
        affAttrCast["EDG"] = -50;

        addSubTraitsCast("Fit", 25);
        addSubTraitsCast("Impatient", -50);

    }
    if (nameCaste == "Elemental") {
        affAttrCast["BOD"] = 125;
        affAttrCast["STR"] = 125;
        affAttrCast["DEX"] = -75;
        affAttrCast["CHA"] = -75;
        addSubSkillsCast("Martial Arts", 25);
    }

    if (nameCaste == "Elemental-Advanced") {
        affAttrCast["BOD"] = 200;
        affAttrCast["STR"] = 175;
        affAttrCast["DEX"] = -100;
        affAttrCast["RFL"] = -75;
        affAttrCast["CHA"] = -100;
        affAttrCast["EDG"] = -100;
        addSubTraitsCast("Patient", 25);
        addSubTraitsCast("Reputation", 100);
    }

    if (nameCaste == "Aerospace") {
        affAttrCast["BOD"] = -50;
        affAttrCast["STR"] = -50;
        affAttrCast["DEX"] = 150;
        affAttrCast["RFL"] = 150;
        affAttrCast["CHA"] = -25;
        affAttrCast["EDG"] = -25;
        addSubTraitsCast("Fit", 25);
        addSubTraitsCast("Impatient", -50);
    }

    if (nameCaste == "ProtoMech") {
        affAttrCast["BOD"] = -50;
        affAttrCast["STR"] = -50;
        affAttrCast["DEX"] = 150;
        affAttrCast["RFL"] = 150;
        affAttrCast["CHA"] = -25;
        affAttrCast["EDG"] = -25;
        addSubTraitsCast("Fit", 25);
        addSubTraitsCast("Impatient", -50);
    }

    if (nameCaste == "Aerospace-Naval") {
        affAttrCast["BOD"] = -50;
        affAttrCast["STR"] = -50;
        affAttrCast["DEX"] = 125;
        affAttrCast["RFL"] = 125;
        affAttrCast["INT"] = 50;
        affAttrCast["CHA"] = -25;
        affAttrCast["EDG"] = -100;
        addSubTraitsCast("Compulsion/Arrogance", -100);
        addSubTraitsCast("Patient", 75);
        addSubTraitsCast("Reputation", 75);
    }

    if (nameCaste == "Warrior Caste(Other)") {
        affAttrCast["BOD"] = 75;
        affAttrCast["STR"] = 50;
        affAttrCast["DEX"] = 50;
        affAttrCast["RFL"] = 50;
        affAttrCast["CHA"] = -25;
        addSubTraitsCast("Reputation", -75);
    }

    if (nameCaste == "Scientist Caste") {
        affAttrCast["STR"] = -50;
        affAttrCast["INT"] = 100;
        addSubTraitsCast("Compulsion/Arrogance", -25);
        addSubTraitsCast("Patient", 100);
        addSubTraitsCast("Reputation", -25);
//        addSubSkillsCast("Interests/Any", 10);
//        addSubSkillsCast("Science/Any", 15);
//        subAffElem3Label = "Interests/Any";
//        subAffElem3 << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
//        affSkillsElem3 = 10;
//        subAffElem4Label = "Science/Any";
//        subAffElem4 << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
//        affSkillsElem4 = 15;

        subAffElem1LabelMore = "Interests/Any";
        subAffElem1More.append(CreateSubSkillList("Interests")); // << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        affSkillsElem1More = 10;

        subAffElem2LabelMore = "Science/Any";
        subAffElem2More.append(CreateSubSkillList("Science")); // << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
        affSkillsElem2More = 15;

    }

    if (nameCaste == "Technician Caste") {
        affAttrCast["DEX"] = 100;
        affAttrCast["INT"] = 20;
        affAttrCast["CHA"] = -50;
        addSubTraitsCast("Patient", 100);
        addSubTraitsCast("Reputation", -75);
//        addSubSkillsCast("Interests/Any", 15);
//        addSubSkillsCast("Technician/Any", 15);
//        subAffElem3Label = "Interests/Any";
//        subAffElem3 << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
//        affSkillsElem3 = 15;
//        subAffElem4Label = "Technician/Any";
//        subAffElem4 << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
//        affSkillsElem4 = 15;

        subAffElem1LabelMore = "Interests/Any";
        subAffElem1More.append(CreateSubSkillList("Interests")); // << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        affSkillsElem1More = 15;

        subAffElem2LabelMore = "Technician/Any";
        subAffElem2More.append(CreateSubSkillList("Technician")); // << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        affSkillsElem2More = 15;
    }

    if (nameCaste == "Merchant Caste") {
        affAttrCast["BOD"] = -50;
        affAttrCast["INT"] = 25;
        affAttrCast["CHA"] = 75;
        addSubTraitsCast("Gregarious", 100);
        addSubTraitsCast("Reputation", -75);
        addSubSkillsCast("Appraisal", 10);
        addSubSkillsCast("Negotiation", 15);
//        addSubSkillsCast("Protocol/Any", 10);
        addSubSkillsCast("Streetwise/Clan", 15);
        subAffElem3Label = "Protocol/Any";
        subAffElem3.append(CreateSubSkillList("Protocol")); // << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
        affSkillsElem3 = 10;
    }

    if (nameCaste == "Laborer Caste") {
        affAttrCast["BOD"] = 100;
        affAttrCast["STR"] = 125;
        affAttrCast["DEX"] = 50;
        affAttrCast["RFL"] = 50;
        affAttrCast["INT"] = -50;
        affAttrCast["CHA"] = -50;
        addSubTraitsCast("Reputation", -125);
//        addSubSkillsCast("Career/Any", 15);
//        addSubSkillsCast("Interests/Any", 10);

//        subAffElem3Label = "Interests/Any";
//        subAffElem3 << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
//        affSkillsElem3 = 10;
//        subAffElem4Label = "Career/Any";
//        subAffElem4 << "Career/Anthropologist" << "Career/Archaeologist" << "Career/Cartographer" << "Career/Communications" << "Career/Doctor" << "Career/Engineer" << "Career/Journalist" << "Career/Lawyer" << "Career/Management" << "Career/MedTech" << "Career/Merchant" << "Career/Merchant Marine" << "Career/Aerospace Pilot" << "Career/Aircraft Pilot" << "Career/DropShip Pilot" << "Career/Politician" << "Career/Scientist" << "Career/Technician" << "Career/Detective" << "Career/Soldier" << "Career/Pilot" << "Career/Ship’s Crew" << "Career/Military Scientist";
//        affSkillsElem4 = 15;

        subAffElem1LabelMore = "Interests/Any";
        subAffElem1More.append(CreateSubSkillList("Interests")); // << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        affSkillsElem1More = 10;

        subAffElem2LabelMore = "Career/Any";
        subAffElem2More.append(CreateSubSkillList("Career")); // << "Career/Anthropologist" << "Career/Archaeologist" << "Career/Cartographer" << "Career/Communications" << "Career/Doctor" << "Career/Engineer" << "Career/Journalist" << "Career/Lawyer" << "Career/Management" << "Career/MedTech" << "Career/Merchant" << "Career/Merchant Marine" << "Career/Aerospace Pilot" << "Career/Aircraft Pilot" << "Career/DropShip Pilot" << "Career/Politician" << "Career/Scientist" << "Career/Technician" << "Career/Detective" << "Career/Soldier" << "Career/Pilot" << "Career/Ship’s Crew" << "Career/Military Scientist";
        affSkillsElem2More = 15;
    }
}

void Text_Resurce::AgeAttr(int age, QString affl) {

    ageTraits.clear();

    if (age < 25) {
        ageCharAttr["STR"] = 0;
        ageCharAttr["BOD"] = 0;
        ageCharAttr["DEX"] = 0;
        ageCharAttr["RFL"] = 0;
        ageCharAttr["INT"] = 0;
        ageCharAttr["WIL"] = 0;
        ageCharAttr["CHA"] = 0;
    }

    if (age >= 25 && age < 31) {
        ageCharAttr["STR"] = 50;
        ageCharAttr["BOD"] = 50;
        ageCharAttr["DEX"] = 0;
        ageCharAttr["RFL"] = 50;
        ageCharAttr["INT"] = 50;
        ageCharAttr["WIL"] = 50;
        ageCharAttr["CHA"] = 50;
    }
    if (age >= 31 && age < 41) {
        ageCharAttr["STR"] = 50;
        ageCharAttr["BOD"] = 50;
        ageCharAttr["DEX"] = 0;
        ageCharAttr["RFL"] = 50;
        ageCharAttr["INT"] = 50;
        ageCharAttr["WIL"] = 50;
        ageCharAttr["CHA"] = 0;
        if (affl == "Invading Clan" || affl == "Homeworld Clan") {
            QString tmptrait = "Reputations";
            ageTraits.append(qMakePair(tmptrait, -150));
        }
    }

    if (age >= 41 && age < 51) {
        ageCharAttr["STR"] = 0;
        ageCharAttr["BOD"] = 0;
        ageCharAttr["DEX"] = -50;
        ageCharAttr["RFL"] = 0;
        ageCharAttr["INT"] = 0;
        ageCharAttr["WIL"] = 25;
        ageCharAttr["CHA"] = -25;
    }

    if (age >= 51 && age < 61) {
        ageCharAttr["STR"] = 0;
        ageCharAttr["BOD"] = -100;
        ageCharAttr["DEX"] = 0;
        ageCharAttr["RFL"] = -100;
        ageCharAttr["INT"] = 0;
        ageCharAttr["WIL"] = 0;
        ageCharAttr["CHA"] = -50;
        if (affl == "Invading Clan" || affl == "Homeworld Clan") {
            QString tmptrait = "Reputations";
            ageTraits.append(qMakePair(tmptrait, -300));
        }
    }

    if (age >= 61 && age < 71) {
        ageCharAttr["STR"] = -100;
        ageCharAttr["BOD"] = -100;
        ageCharAttr["DEX"] = -100;
        ageCharAttr["RFL"] = 0;
        ageCharAttr["INT"] = 50;
        ageCharAttr["WIL"] = 0;
        ageCharAttr["CHA"] = -50;
        QString tmptrait = "Slow Learner";
        ageTraits.append(qMakePair(tmptrait, -300));

    }

    if (age >= 71 && age < 81) {
        ageCharAttr["STR"] = -100;
        ageCharAttr["BOD"] = -125;
        ageCharAttr["DEX"] = 0;
        ageCharAttr["RFL"] = -100;
        ageCharAttr["INT"] = 0;
        ageCharAttr["WIL"] = -50;
        ageCharAttr["CHA"] = -75;
        QString tmptrait = "Slow Learner";
        ageTraits.append(qMakePair(tmptrait, -300));
        tmptrait = "Glass Jaw";
        ageTraits.append(qMakePair(tmptrait, -300));

    }

    if (age >= 81 && age < 91) {
        ageCharAttr["STR"] = -150;
        ageCharAttr["BOD"] = -150;
        ageCharAttr["DEX"] = -100;
        ageCharAttr["RFL"] = -100;
        ageCharAttr["INT"] = -100;
        ageCharAttr["WIL"] = -50;
        ageCharAttr["CHA"] = -100;
        QString tmptrait = "Slow Learner";
        ageTraits.append(qMakePair(tmptrait, -300));
        tmptrait = "Glass Jaw";
        ageTraits.append(qMakePair(tmptrait, -300));

    }

    if (age >= 91 && age < 101) {
        ageCharAttr["STR"] = -150;
        ageCharAttr["BOD"] = -175;
        ageCharAttr["DEX"] = -150;
        ageCharAttr["RFL"] = -125;
        ageCharAttr["INT"] = -150;
        ageCharAttr["WIL"] = -100;
        ageCharAttr["CHA"] = -100;
        QString tmptrait = "Slow Learner";
        ageTraits.append(qMakePair(tmptrait, -300));
        tmptrait = "Glass Jaw";
        ageTraits.append(qMakePair(tmptrait, -300));

    }

    if (age >= 101) {
        ageCharAttr["STR"] = -200;
        ageCharAttr["BOD"] = -200;
        ageCharAttr["DEX"] = -200;
        ageCharAttr["RFL"] = -150;
        ageCharAttr["INT"] = -200;
        ageCharAttr["WIL"] = -100;
        ageCharAttr["CHA"] = -150;
        QString tmptrait = "Slow Learner";
        ageTraits.append(qMakePair(tmptrait, -300));
        tmptrait = "Glass Jaw";
        ageTraits.append(qMakePair(tmptrait, -300));

    }

}
