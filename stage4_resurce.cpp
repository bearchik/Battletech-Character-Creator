#include "stage4_resurce.h"
#include <QtGui>

Stage4::Stage4(QWidget *parent) :
    QWidget(parent)
{
    s4ModulesList << "None" << "Agitator" << "Civilian Job" << "Clan Watch Operative" << "Clan Warrior Washout" << "Cloister Training" << "Combat Correspondent"
            << "Comstar/WoB Service" << "Covert Operations" << "Dark Caste" << "Explorer" << "Goliath Scorpion Seeker" << "Guerilla Insurgent"
            << "Merchant" << "Ne'er-Do-Well" << "Organized Crime" << "Postgraduate Studies" << "Protomech Pilot Training" << "Scientist Caste Service"
            << "Solaris Insider" << "Solaris VII Games" << "Think Tank" << "Tour Of Duty" << "To Serve And Protect" << "Travel";

    s4TraitsMod.clear();
    s4SkillsMod.clear();
    s4AttrMod.clear();
    s4XpCost = 0;
    s4FlexXP = 0;
    s4AffStreet = 0;
    s4AffLang = 0;
    s4AffProt = 0;
    s4Age = 0;
    s4repeat = false;

    carField = new CarierFields;
    clanFieldSkills.clear();
}

QStringList Stage4::CreateSubSkillList(QString nameSkill) {
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


QStringList Stage4::S4ClearModulesList() {
    QStringList clearList;
    clearList.clear();

    s4ModulesList.clear();
    s4ModulesList << "None" << "Agitator";

    if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
        if(s4clanCastName.first == "Laborer Caste" || s4clanCastName.first == "Merchant Caste") {
            s4ModulesList << "Civilian Job";
        } else{
            if(s4clanCastName.first == "Technician Caste") {
                s4ModulesList << "Civilian Job";
            }
        }
    } else {
        s4ModulesList << "Civilian Job";
    }

    if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
        if(s4clanCastName.first != "Merchant Caste" || s4clanCastName.first == "Laborer Caste") {
            s4ModulesList << "Clan Watch Operative";
        }
    }

    if(s4LateChildName.first == "Trueborn Sibko" || s4LateChildName.first == "Freeborn Sibko") {
        s4ModulesList << "Clan Warrior Washout";
    }

    if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
        if(s4clanCastName.first != "Scientist Caste") {
            if(s4clanCastName.first != "Technician Caste") {
                if(s4clanCastName.first != "Merchant Caste") {
                    if(s4clanCastName.first != "Laborer Caste") {
                        s4ModulesList << "Cloister Training";
                    }
                }
            }
        }
    }

    if(s4AffName.first != "Invading Clan" || s4AffName.first != "Homeworld Clan") {
        bool chkPrerc = false;
            if( s4AdvSchool.first == "Journalist" ) {
                for(int i = 0; i < s4Traits.count(); i++) {
                    if(s4Traits[i].first == "Combat Paralysis") {
                            chkPrerc = true;
                    }
                }
                if(chkPrerc != true) {
                    s4ModulesList << "Combat Correspondent";
                }
            }

    }

    if(s4ComChk == true || s4WobChk == true) {
        bool chkPrerc = false;

        for(int i = 0; i < s4Traits.count(); i++) {
            if(s4Traits[i].first == "Lost Limb") {
                chkPrerc = true;
            }
            if (s4Traits[i].first == "Poor Hearing") {
                chkPrerc = true;
            }
            if (s4Traits[i].first == "Poor Vision") {
                chkPrerc = true;
            }
            if (s4Traits[i].first == "Transit Disorientation Syndrome") {
                chkPrerc = true;
            }
        }

        if(chkPrerc != true) {
            s4ModulesList << "Comstar/WoB Service";
        }
    }


    if(s4AffName.first != "Invading Clan") {
        if (s4AffName.first != "Homeworld Clan") {
            if(s4SchoolName.first != "Technical College") {
                if( s4SchoolName.first != "Trade School" ) {
                    if(s4SchoolName.first != "University" || s4SchoolName.first !="Solaris Internship") {
                        bool chkPrerc = false;
                        for(int i = 0; i < s4Traits.count(); i++) {
                            if(s4Traits[i].first == "Combat Paralysis") {
                                chkPrerc = true;
                            }
                        }
                        if(chkPrerc != true) {
                            s4ModulesList << "Covert Operations";
                        }
                    }
                }
            }
        }
    }

     if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
         s4ModulesList << "Dark Caste";
     }


     if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
          if(s4clanCastName.first == "Scientist Caste") {
              s4ModulesList << "Explorer";
          }
      } else {
          s4ModulesList << "Explorer";
      }

      if(s4SubAffName.first == "Goliath Scorpion") {
          if(s4clanCastName.first != "Scientist Caste") {
              if(s4clanCastName.first != "Technician Caste") {
                  if(s4clanCastName.first != "Merchant Caste") {
                      if(s4clanCastName.first != "Laborer Caste") {
                          s4ModulesList << "Goliath Scorpion Seeker";
                      }
                  }
              }
          }
      }

      if(s4AffName.first != "Invading Clan" || s4AffName.first != "Homeworld Clan") {
          s4ModulesList << "Guerilla Insurgent";
      }

      if(s4AffName.first == "Invading Clan") {
          bool chkPrerc = false;
          for(int i = 0; i < s4Traits.count(); i++) {
              if (s4Traits[i].first == "Transit Disorientation Syndrome") {
                  chkPrerc = true;
              }
          }

          if(chkPrerc != true) {
              s4ModulesList << "Merchant";
          }
      } else {
          s4ModulesList << "Merchant";
      }

      s4ModulesList << "Ne'er-Do-Well";

      if(s4AffName.first != "Invading Clan" || s4AffName.first != "Homeworld Clan") {
          s4ModulesList << "Organized Crime";
      }

      if(s4SchoolName.first == "University") {
          s4ModulesList << "Postgraduate Studies";
      }

      if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
          bool chkPrerc = false;
          if(s4SubAffName.first == "Blood Spirit") {
              if(s4clanCastName.first != "Scientist Caste") {
                  if(s4clanCastName.first != "Technician Caste") {
                      if(s4clanCastName.first != "Merchant Caste") {
                          if(s4clanCastName.first != "Laborer Caste") {
                              if(s4Phenotype == "Phenotype/Aerospace") {
                                  for(int i = 0; i < s4Traits.count(); i++) {
                                      if(s4Traits[i].first == "Implant/EI Neural Implant") {
                                          chkPrerc = false;
                                      } else {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Combat Paralysis") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Glass Jaw") {
                                          chkPrerc = true;
                                      }
                                      if(s4Traits[i].first == "Lost Limb") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Hearing") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Vision") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Slow Learner") {
                                          chkPrerc = true;
                                      }
                                  }
                                  if(chkPrerc != true) {
                                      s4ModulesList << "Protomech Pilot Training";
                                  }
                              }
                          }
                      }
                  }
              }
          }
          if(s4SubAffName.first == "Fire Mandrill") {
              if(s4clanCastName.first != "Scientist Caste") {
                  if(s4clanCastName.first != "Technician Caste") {
                      if(s4clanCastName.first != "Merchant Caste") {
                          if(s4clanCastName.first != "Laborer Caste") {
                              if(s4Phenotype == "Phenotype/Aerospace") {
                                  for(int i = 0; i < s4Traits.count(); i++) {
                                      if(s4Traits[i].first == "Implant/EI Neural Implant") {
                                          chkPrerc = false;
                                      } else {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Combat Paralysis") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Glass Jaw") {
                                          chkPrerc = true;
                                      }
                                      if(s4Traits[i].first == "Lost Limb") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Hearing") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Vision") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Slow Learner") {
                                          chkPrerc = true;
                                      }
                                  }
                                  if(chkPrerc != true) {
                                      s4ModulesList << "Protomech Pilot Training";
                                  }
                              }
                          }
                      }
                  }
              }
          }
          if(s4SubAffName.first == "Goliath Scorpion") {
              if(s4clanCastName.first != "Scientist Caste") {
                  if(s4clanCastName.first != "Technician Caste") {
                      if(s4clanCastName.first != "Merchant Caste") {
                          if(s4clanCastName.first != "Laborer Caste") {
                              if(s4Phenotype == "Phenotype/Aerospace") {
                                  for(int i = 0; i < s4Traits.count(); i++) {
                                      if(s4Traits[i].first == "Implant/EI Neural Implant") {
                                          chkPrerc = false;
                                      } else {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Combat Paralysis") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Glass Jaw") {
                                          chkPrerc = true;
                                      }
                                      if(s4Traits[i].first == "Lost Limb") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Hearing") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Vision") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Slow Learner") {
                                          chkPrerc = true;
                                      }
                                  }
                                  if(chkPrerc != true) {
                                      s4ModulesList << "Protomech Pilot Training";
                                  }
                              }
                          }
                      }
                  }
              }
          }
          if(s4SubAffName.first == "Hell's Horses") {
              if(s4clanCastName.first != "Scientist Caste") {
                  if(s4clanCastName.first != "Technician Caste") {
                      if(s4clanCastName.first != "Merchant Caste") {
                          if(s4clanCastName.first != "Laborer Caste") {
                              if(s4Phenotype == "Phenotype/Aerospace") {
                                  for(int i = 0; i < s4Traits.count(); i++) {
                                      if(s4Traits[i].first == "Implant/EI Neural Implant") {
                                          chkPrerc = false;
                                      } else {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Combat Paralysis") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Glass Jaw") {
                                          chkPrerc = true;
                                      }
                                      if(s4Traits[i].first == "Lost Limb") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Hearing") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Vision") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Slow Learner") {
                                          chkPrerc = true;
                                      }
                                  }
                                  if(chkPrerc != true) {
                                      s4ModulesList << "Protomech Pilot Training";
                                  }
                              }
                          }
                      }
                  }
              }
          }
          if(s4SubAffName.first == "Snow Raven") {
              if(s4clanCastName.first != "Scientist Caste") {
                  if(s4clanCastName.first != "Technician Caste") {
                      if(s4clanCastName.first != "Merchant Caste") {
                          if(s4clanCastName.first != "Laborer Caste") {
                              if(s4Phenotype == "Phenotype/Aerospace") {
                                  for(int i = 0; i < s4Traits.count(); i++) {
                                      if(s4Traits[i].first == "Implant/EI Neural Implant") {
                                          chkPrerc = false;
                                      } else {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Combat Paralysis") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Glass Jaw") {
                                          chkPrerc = true;
                                      }
                                      if(s4Traits[i].first == "Lost Limb") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Hearing") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Poor Vision") {
                                          chkPrerc = true;
                                      }
                                      if (s4Traits[i].first == "Slow Learner") {
                                          chkPrerc = true;
                                      }
                                  }
                                  if(chkPrerc != true) {
                                      s4ModulesList << "Protomech Pilot Training";
                                  }
                              }
                          }
                      }
                  }
              }
          }

      }

      if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
          if(s4clanCastName.first == "Scientist Caste") {
              s4ModulesList << "Scientist Caste Service";
          }
      }

      s4ModulesList << "Solaris Insider";

      if (s4AdvSchool.first != "MechWarrior" || s4AdvSchool.first !="Cavalry") {
          if(s4AdvSchool.first == "Pilot - Battle Armor" || s4SpecSchool.first == "Pilot - Battle Armor") {
              s4ModulesList << "Solaris VII Games";
          }
      } else {
          s4ModulesList << "Solaris VII Games";
      }

      if (s4AdvSchool.first != "Analysis" || s4SpecSchool.first !="Doctor") {
          if (s4AdvSchool.first != "Engineer" || s4SpecSchool.first !="Military Scientist") {
              s4ModulesList << "Think Tank";
          }
      } else {
          s4ModulesList << "Think Tank";
      }

      if(s4MilField == true) {
          s4ModulesList << "Tour Of Duty";
      }

      if (s4AdvSchool.first != "Police Officer" || s4BasicSchool.first != "Police Officer") {
          if(s4SpecSchool.first == "Police Tactical Officer" || s4AdvSchool.first == "Detective") {
              s4ModulesList << "To Serve And Protect";
          }
      }

      bool chkPrerc = false;
      for(int i = 0; i < s4Traits.count(); i++) {
          if (s4Traits[i].first == "Transit Disorientation Syndrome") {
              chkPrerc = true;
          }
      }

      if(chkPrerc != true) {
          s4ModulesList << "Travel";
      }

    clearList = s4ModulesList;
    return clearList;
}

void Stage4::S4AddTraits(QString str , int count) {
    s4TraitsMod.append(qMakePair(str,count));
}

void Stage4::S4AddSkills(QString str , int count) {
    s4SkillsMod.append(qMakePair(str,count));
}

void Stage4::S4ChooseLife(QString nameElem) {

    s4LabelElem1.clear();
    s4SkillsElem1.clear();
    s4TraitsElem1.clear();
    s4Elem1 = 0;

    s4LabelElem2.clear();
    s4SkillsElem2.clear();
    s4TraitsElem2.clear();
    s4Elem2 = 0;

    s4LabelElem3.clear();
    s4SkillsElem3.clear();
    s4TraitsElem3.clear();
    s4Elem3 = 0;

    s4LabelElem4.clear();
    s4SkillsElem4.clear();
    s4TraitsElem4.clear();
    s4Elem4 = 0;

    s4LabelElem5.clear();
    s4SkillsElem5.clear();
    s4TraitsElem5.clear();
    s4Elem5 = 0;

    s4LabelElem6.clear();
    s4SkillsElem6.clear();
    s4TraitsElem6.clear();
    s4AttrElem6.clear();
    s4Elem6 = 0;

    s4LabelElem7.clear();
    s4SkillsElem7.clear();
    s4TraitsElem7.clear();
    s4Elem7 = 0;

    s4LabelElem8.clear();
    s4SkillsElem8.clear();
    s4TraitsElem8.clear();
    s4Elem8 = 0;

    s4TraitsMod.clear();
    s4SkillsMod.clear();
    s4AttrMod.clear();

    s4XpCost = 0;
    s4FlexXP = 0;
    s4AffStreet = 0;
    s4AffLang = 0;
    s4AffProt = 0;
    s4Age = 0;
    s4Repit5 = 0;
    s4Repit6 = 0;
    s4Repit7 = 0;

    s4PreAttr.clear();
    s4PreTraits.clear();
    s4PreSkills.clear();
    QString swpstr;

    if(nameElem == "None") {
        s4toolTip = "Zero life";
        s4XpCost = 0;
        s4Age = 0;
    }

    if(nameElem == "Agitator") {

        s4toolTip = "Dedicated to challenging authority by any means necessary,\nagitators seek to gather disciples and move them against their\ngovernments and leaders-whether for a noble cause or personal\ngain. Unsurprisingly, the agitator's lifestyle puts him in constant peril.\nAfter all, the last thing the monarchies and military juntas of the Inner\nSphere and the Clans need is someone who makes waves.\nPrerequisites: None";

        s4XpCost = 900;
        s4FlexXP = 125;
        s4Age = 4;

        s4AttrMod["WIL"] = 75;

        S4AddTraits("Bloodmark", -50);
        S4AddTraits("Gregarious", 80);
        S4AddTraits("Toughness", 80);
        S4AddTraits("Reputation", -150);

        S4AddSkills("Acting",50);
        S4AddSkills("Disguise",75);
//        S4AddSkills("Driving/Any",65); // SEE RULEZ

        s4LabelElem1 = "Driving/Any";
        s4SkillsElem1 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
        s4Elem1 = 65;

        S4AddSkills("Leadership",60);
        S4AddSkills("Negotiation",80);
        S4AddSkills("Perception",70);
        S4AddSkills("Prestidigitation",100);
        S4AddSkills("Small Arms",75);

        s4AffStreet = 75;

        S4AddSkills("Tactics/Infantry",40);
        S4AddSkills("Training", 50);
    }

    if(nameElem == "Civilian Job") {
        s4toolTip = "You may not carry a weapon, or hold the fate of worlds in your\nhand, but you earn a living, and it’s honest work to boot. Whether\nyou’re a career bureaucrat, a cubicle rat, a humble store clerk or\na freight loader at the local spaceport, you are part of the vast\ninfrastructure that keeps your town and your society running-\neven if you occasionally daydream about something more…\nPrerequisites:None. Clan characters from any non-warrior\ncaste except Scientist and Dark Caste use this module.";

        s4XpCost = 600;
        s4FlexXP = 85;
        s4Age = 6;

        s4AffProt = 50;

        S4AddSkills("Administration", 75);
//        S4AddSkills("Career/Any Non-Military", 40); // SEE RULEZ!!

        s4LabelElem1 = "Career/Any Non-Military";
        s4SkillsElem1 << "Career/Anthropologist" << "Career/Archaeologist" << "Career/Cartographer" << "Career/Communications" << "Career/Doctor" << "Career/Engineer" << "Career/Journalist" << "Career/Lawyer" << "Career/Management" << "Career/MedTech" << "Career/Merchant" << "Career/Merchant Marine" << "Career/Aerospace Pilot" << "Career/Aircraft Pilot" << "Career/DropShip Pilot" << "Career/Politician" << "Career/Scientist" << "Career/Technician";
        s4Elem1 = 40;

        S4AddSkills("Computers", 40);
//        S4AddSkills("Driving/Any", 60); // SEE RULEZ!!

        s4LabelElem2 = "Driving/Any";
        s4SkillsElem2 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
        s4Elem2 = 60;

//        S4AddSkills("Interests/Any", 100);
        s4LabelElem3 = "Interests/Any";
        s4SkillsElem3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem3 = 100;

        S4AddSkills("Leadership", 40);
        S4AddSkills("Negotiation", 30);
//        S4AddSkills("+80 total additional XP 20x4 skill", 20 ); // SEE RULEZ!!

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "20XP x 4 skill";
        } else {
            s4FlexXP += 80;
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 20;
        s4Repit7 = 4;
    }

    if(nameElem == "Clan Watch Operative") {
        s4toolTip = "Among the Clans, the \"honorless\" business of spycraft and\nespionage is considered anathema, but even the most hidebound\nof Kerensky's descendants know better than to completely\nignore the advantages of intelligence operations. Though\nconsidered ignoble and often assigned to operatives who\nfailed the Clans in some way within their chosen profession,\nthe operatives of the Clan Watch nevertheless strive to catch\nup to their Spheroid counterparts in the arena of covert ops.\nPrerequisites:Any Clan affiliation. Must be a member of\nthe Warrior, Scientist or Technician castes.";

        s4XpCost = 1200;
        s4FlexXP = 175;
        s4Age = 3;

        s4AttrMod["INT"] = 70;
        s4AttrMod["RFL"] = 50;
        s4AttrMod["CHA"] = -75;

        S4AddTraits("Connections", 100);
        S4AddTraits("Dark Secret", -50);
        S4AddTraits("In For Life", -100);
        S4AddTraits("Reputation", -50);

        S4AddSkills("Acting",30);
        S4AddSkills("Computers",75);
        S4AddSkills("Cryptography",50);
        S4AddSkills("Demolitions",40);
        S4AddSkills("Martial Arts",75);
        S4AddSkills("Perception",75);

        s4AffProt = 50;
        s4AffStreet = 50;

        S4AddSkills("Small Arms",80);
        S4AddSkills("Stealth",50);
//        S4AddSkills("Tracking/Any",80); // SEE RULEZ!!

        s4LabelElem1 = "Tracking/Any";
        s4SkillsElem1 = CreateSubSkillList("Tracking");// << "Tracking/Urban" << "Tracking/Wilds";;
        s4Elem1 = 80;

        if(s4AffName.first == "Homeworld Clan") {
            S4AddSkills("Career/Soldier",60);
            S4AddSkills("Interrogation",50);
            S4AddSkills("Investigation",50);
            S4AddSkills("Melee Weapons",40);
//            S4AddSkills("Protocol/Any Clan",75); // SEE RULEZ!!

            s4LabelElem2 = "Protocol/Any Clan";
            s4SkillsElem2 << "Protocol/Diamond Shark" << "Protocol/Ghost Bear" << "Protocol/Hell's Horses" << "Protocol/Jade Falcon" << "Protocol/Nova Cat" << "Protocol/Snow Raven" << "Protocol/Wolf" << "Protocol/Blood Spirit"  << "Protocol/Cloud Cobra" << "Protocol/Coyote" << "Protocol/Fire Mandrill" << "Protocol/Goliath Scorpion" << "Protocol/Ice Hellion" << "Protocol/Star Adder" << "Protocol/Steel Viper";
            s4Elem2 = 75;

            S4AddSkills("Security Systems",45);
//            S4AddSkills("Streetwise/Any Homeworld Clan",50);  // SEE RULEZ!!

            s4LabelElem3 = "Streetwise/Any Homeworld Clan";
            s4SkillsElem3 << "Streetwise/Blood Spirit"  << "Streetwise/Cloud Cobra" << "Streetwise/Coyote" << "Streetwise/Fire Mandrill" << "Streetwise/Goliath Scorpion" << "Streetwise/Ice Hellion" << "Streetwise/Star Adder" << "Streetwise/Steel Viper";
            s4Elem3 = 50;

//            S4AddSkills("Survival/Any",25);  // SEE RULEZ!!

            s4LabelElem4 = "Survival/Any";
            s4SkillsElem4 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            s4Elem4 = 25;

//            S4AddSkills("Technician/Any",40);  // SEE RULEZ!!

            s4LabelElem5 = "Technician/Any";
            s4SkillsElem5 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem4 = 40;
        }

        if(s4AffName.first == "Invading Clan") {
            S4AddTraits("Equipped", 50);
            S4AddTraits("Dark Secret", -50);

//            S4AddSkills("Computers/Any",50); // SEE RULEZ!!

            s4LabelElem2 = "Computers/Any";
            s4SkillsElem2 << "Computers/Programing" << "Computers/Hacking";
            s4Elem2 = 50;

            S4AddSkills("Disguise",35);
            S4AddSkills("Interrogation",75);
            S4AddSkills("Investigation",75);
            S4AddSkills("Negotiation",40);
            S4AddSkills("Perception",50);
//            S4AddSkills("Streetwise/Any Invader Clan or Inner Sphere",50);  // SEE RULEZ!!

            s4LabelElem3 = "Streetwise/Any Invader Clan or Inner Sphere";
            s4SkillsElem3 << "Streetwise/Diamond Shark" << "Streetwise/Ghost Bear" << "Streetwise/Hell's Horses" << "Streetwise/Jade Falcon" << "Streetwise/Nova Cat" << "Streetwise/Snow Raven" << "Streetwise/Wolf" << "Streetwise/Capellan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Free Worlds" << "Streetwise/Lyran" << "Streetwise/Rasalhague" << "Protocol/Terran";
            s4Elem3 = 50;

//            S4AddSkills("Survival/Any",50);  // SEE RULEZ!!

            s4LabelElem4 = "Survival/Any";
            s4SkillsElem4 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            s4Elem4 = 50;
        }

    }

    if(nameElem == "Clan Warrior Washout") {
        s4toolTip = "Yours was a life filled with promise and glory for the Clan-\nuntil something went wrong. Though you survived the failure\nthat led to your dismissal from the warrior training programs,\nyou have been consigned to a lesser caste and must now learn\nto accept your role in supporting the warrior brethren you\nmight otherwise have joined in battle.\nPrerequisites:Clan affiliation; prior module must be\nFreeborn Sibko or Trueborn Sibko. Player must choose\nwhich caste the washed-out warrior has joined. Do not\nchoose this module if “washing out” to ProtoMech training\n(see Notes below).";
        s4XpCost = 400;
        s4FlexXP = 185;
        s4Age = 2;

        s4AttrMod["CHA"] = -25;
        s4AttrMod["WIL"] = -50;

//        S4AddTraits("Compulsion/Any", -25); //SEE RULEZ!!!

        s4LabelElem1 = "Compulsion/Any";
        s4TraitsElem1 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality";
        s4Elem1 = -25;

        S4AddTraits("Reputation", -150);

        S4AddSkills("Career/Soldier",-30);
        S4AddSkills("Computers",25);
        S4AddSkills("Survival",75);

        s4AffProt = 80;

//        S4AddSkills("-60 total additional XP",-60); //SEE RULEZ!!!

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "-30XP x 2 skill";
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = -30;
        s4Repit7 = 2;

        if ( s4clanCastName.first == "Scientist Caste") {
            s4AttrMod["INT"] = 50;
            s4AttrMod["RFL"] = 25;

            S4AddTraits("Dark Secret", 50);

            S4AddSkills("Administration",75);
//            S4AddSkills("Interests/Any",50); //SEE RULEZ!!!

            s4LabelElem2 = "Interests/Any";
            s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem2 = 50;

            S4AddSkills("Investigation",75);
            S4AddSkills("MedTech",50);
//            S4AddSkills("Science/Any",75); //SEE RULEZ!!!

            s4LabelElem3 = "Science/Any";
            s4SkillsElem3 = CreateSubSkillList("Science");// << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
            s4Elem3 = 75;

            S4AddSkills("Surgery",25);
        }

        if ( s4clanCastName.first == "Technician Caste") {
            s4AttrMod["RFL"] = 25;
            s4AttrMod["STR"] = 50;

            S4AddTraits("Impatient", -50);

//            S4AddSkills("Communications/Any",75); //SEE RULEZ!!!

            s4LabelElem2 = "Communications/Any";
            s4SkillsElem2 = CreateSubSkillList("Communications");// << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
            s4Elem2 = 75;

//            S4AddSkills("Interests/Any",50); //SEE RULEZ!!!

            s4LabelElem3 = "Interests/Any";
            s4SkillsElem3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem3 = 50;

            S4AddSkills("Perception",75);
//            S4AddSkills("Technician/Any",75); //SEE RULEZ!!!

            s4LabelElem4 = "Technician/Any";
            s4SkillsElem4 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem4 = 75;

//            S4AddSkills("Technician/Any",50); //SEE RULEZ!!!

            s4LabelElem5 = "Technician/Any";
            s4SkillsElem5 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem5 = 50;

//            S4AddSkills("Technician/Any",25); //SEE RULEZ!!!

            s4LabelElem6 = "Technician/Any";
            s4SkillsElem6 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem6 = 25;
        }

        if ( s4clanCastName.first == "Merchant Caste") {
            s4AttrMod["WIL"] = 75;

            S4AddTraits("Thin-Skinned", -50);

            S4AddSkills("Acting",45);
            S4AddSkills("Administration",40);
            S4AddSkills("Appraisal",75);
//            S4AddSkills("Interests/Any",40); //SEE RULEZ!!!

            s4LabelElem2 = "Interests/Any";
            s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem2 = 50;

//            S4AddSkills("Interests/Any",35); //SEE RULEZ!!!

            s4LabelElem3 = "Interests/Any";
            s4SkillsElem3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem3 = 50;

            S4AddSkills("Leadership",40);
            S4AddSkills("Negotiation",50);

            s4AffStreet = 25;
        }

        if ( s4clanCastName.first == "Laborer Caste") {
            s4AttrMod["BOD"] = 75;

            S4AddTraits("Dependent", -50);

            S4AddSkills("Career/Any appropriate",75);

            s4LabelElem2 = "Career/Any appropriate";
            s4SkillsElem2 << "Career/Archaeologist" << "Career/Cartographer" << "Career/Doctor" << "Career/MedTech" << "Career/Scientist" << "Career/Military Scientist";
            s4Elem2 = 75;

            S4AddSkills("Computers",50);
//            S4AddSkills("Driving/Any",75);

            s4LabelElem3 = "Driving/Any";
            s4SkillsElem3 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
            s4Elem3 = 75;

//            S4AddSkills("Interests/Any",75); //SEE RULEZ!!!

            s4LabelElem4 = "Interests/Any";
            s4SkillsElem4 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem4 = 75;

//            S4AddSkills("Interests/Any",50); //SEE RULEZ!!!

            s4LabelElem5 = "Interests/Any";
            s4SkillsElem5 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem5 = 50;

            s4AffStreet = 25;
        }
    }

    if(nameElem == "Cloister Training") {
        s4toolTip = "The religious Cloisters fostered by Clan Cloud Cobra-a\nlegacy of the Clan's founding by a former SLDF chaplain—offer\na curious mixture of spiritual and martial pursuits. Though\nstronger in the Homeworlds, the Cloisters include members\nfrom virtually every Clan, so even a warrior in the Inner Sphere\nmay explore his faith while simultaneously demonstrating his\nfierce devotion to the Way of the Clans.\nPrerequisites:Clan(warrior caste) only, WIL 5+; eligible\ncharacters outside of Clan Cloud Cobra must also have a\nminimum +2 TP in the Connections Trait.";

        s4XpCost = 700;
        s4FlexXP = 150;
        s4Age = 3;

        s4AttrMod["WIL"] = 75;

        S4AddTraits("Connections", 50);
        S4AddTraits("In For Life", -75);

        S4AddSkills("Interests/Clan Remembrance",80);
        S4AddSkills("Interests/Theology",100);
//        S4AddSkills("Interests/Any",75); //SEE RULEZ!!!

        s4LabelElem1 = "Interests/Any";
        s4SkillsElem1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem1 = 75;

        S4AddSkills("Melee Weapons",50);
        S4AddSkills("Perception",35);
        S4AddSkills("Training",85);
//        S4AddSkills("+75 total additional XP (+25 XP each to any three of the characterâ€™s Clan Warrior Fields)",75); //SEE RULEZ!!!

        s4LabelElem7 = "+25 XP each to any three Field";
        s4SkillsElem7 << "Clan Aerospace Warrior" << "Clan Cavalry" << "Clan Elemental" << "Clan MechWarrior" << "Clan ProtoMech Warrior";
        s4Elem7 = 25;
        s4Repit7 = 3;

        s4PreAttr["WIL"] = 500;
        if(s4SubAffName.first != "Cloud Cobra") {
            swpstr = "Connections";
            s4PreTraits.append(qMakePair(swpstr,200));
        }
    }

    if(nameElem == "Combat Correspondent") {
        s4toolTip = "The spirit of front-line journalism remains alive and well\neven on the 'Mech-heavy battlefields of the thirty-first\ncentury. Only there can the combat correspondent—part\nsoldier, part journalist—truly shine. Battlefield journalism isn't\nfor the faint of heart, but it’s a lot more respectable than being\na paparazzi.\nPrerequisites: Any non-Clan affiliation. Must have Journalist\nField. Must not have Combat Paralysis Trait.";

        s4XpCost = 700;
        s4FlexXP = 90;
        s4Age = 4;

        s4AttrMod["WIL"] = 50;
        s4AttrMod["CHA"] = 75;

        S4AddTraits("Extra Income", 40);
        S4AddTraits("Reputation", 30);

        S4AddSkills("Art/Writing",35);
        S4AddSkills("Career/Journalist",50);
        S4AddSkills("Communications/Conventional",30);
        S4AddSkills("Computers",20);
        S4AddSkills("Investigation",35);

        s4AffLang = 50;

//        S4AddSkills("Language/Any",30); //SEE RULEZ!!!

        s4LabelElem1 = "Language/Any";
        s4SkillsElem1 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem1 = 30;

//        S4AddSkills("Navigation/Any",25); //SEE RULEZ!!!

        s4LabelElem2 = "Navigation/Any";
        s4SkillsElem2 = CreateSubSkillList("Navigation");// << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
        s4Elem2 = 25;

        S4AddSkills("Negotiation",40);
        S4AddSkills("Perception",30);
//        S4AddSkills("Survival/Any",35); //SEE RULEZ!!!

        s4LabelElem3 = "Survival/Any";
        s4SkillsElem3 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";;
        s4Elem3 = 35;

        S4AddSkills("Technician/Electrical",35);
    }

    if(nameElem == "Comstar/WoB Service") {
        s4toolTip = "Though technically more of an international conglomerate\nthan a sacred order, the centuries-old devotion to maintaining the\nneutrality of Terra and the interstellar communications network of\nhyperpulse generators spawned a quasi-religious fervor that gave\nrise to the modern ComStar. Post-3052 ComStar shed much of this\nmysticism in favor of playing a protector role for the Inner Sphere\nagainst the Clan threat, but the schism that resulted when the more\nfanatical members left created the dangerous and unpredictable\nWord of Blake. Both organizations, however, retained much of the\ntraining and services that made them important to the realms of\nthe Inner Sphere throughout the Succession Wars.\nBased on their training and background, members of either\norder can be tasked with anything from technical service on the\nHPGs, to local telecommunications and mail service, to planetary\nsecurity and police investigations.\nPrerequisites: ComStar or Word of Blake affiliations only.\nCannot have any of the following Traits above the lowest possible\nlevel: Lost Limb, Poor Hearing, Poor Vision, TDS.";

        s4XpCost = 900;
        s4FlexXP = 50;
        s4Age = 5;

        s4AttrMod["DEX"] = 50;
        s4AttrMod["INT"] = 50;

        S4AddTraits("Combat Sense", 75);
        S4AddTraits("In For Life", -100);
        S4AddTraits("Tech Empathy", 35);
//        S4AddTraits("Choose one: Equipped, Vehicle or Wealth", 100); //SEE RULEZ!!!

        s4LabelElem1 = "Choose one";
        s4TraitsElem1 << "Equipped" << "Vehicle" << "Wealth";
        s4Elem1 = 100;

        S4AddSkills("Administration",40);
        S4AddSkills("Communications/HPG",55);
//        S4AddSkills("Communications/Any",35); //SEE RULEZ!!!

        s4LabelElem2 = "Communications/Any";
        s4SkillsElem2 = CreateSubSkillList("Communications");// << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
        s4Elem2 = 35;

        S4AddSkills("Computers",35);
//        S4AddSkills("Language/Any",25); //SEE RULEZ!!!

        s4LabelElem3 = "Language/Any";
        s4SkillsElem3 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem3 = 25;

        S4AddSkills("Martial Arts",45);

        s4AffProt = 35;

//        S4AddSkills("Protocol/Any",20); //SEE RULEZ!!!

        s4LabelElem4 = "Protocol/Any";
        s4SkillsElem4 = CreateSubSkillList("Protocol");// << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
        s4Elem4 = 20;

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "40XP x 4 skill";
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        } else {
            s4LabelElem7 = "40XP x 4 skill";
            s4SkillsElem7 << "Acrobatics" << "Acting" << "Administration" << "Animal Handling" << "Appraisal" << "Archery" << "Art/Any" << "Artillery" << "Career" << "Climbing" << "Communications" << "Computers" << "Cryptography" << "Demolitions" << "Disguise" << "Driving" << "Escape Artist" << "Forgery" << "Gunnery" << "Interests/Any" << "Interrogation" << "Investigation" << "Language" << "Leadership" << "Martial Arts" << "MedTech" << "Melee Weapons" << "Navigation" << "Negotiation" << "Perception" << "Piloting" << "Prestidigitation" << "Protocol" << "Running" << "Science" << "Security Systems" << "Sensor Operations" << "Small Arms" << "Stealth" << "Strategy" << "Streetwise" << "Support Weapons" << "Surgery" << "Survival" << "Swimming" << "Tactics" << "Technician" << "Thrown Weapons" << "Tracking" << "Training" << "Zero-G Operations";
        }

        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 40;
        s4Repit7 = 4;

        if (s4ComChk == true) {
            s4AttrMod["WIL"] = 25;
            s4AttrMod["EDG"] = -25;

            S4AddTraits("Equipped", 80);
            S4AddTraits("Rank", 80);
            S4AddTraits("Compulsion/Hatred of Word of Blake", -50);

            S4AddSkills("Communications/HPG",15);
            S4AddSkills("Leadership",20);
            S4AddSkills("Negotiation",15);
//            S4AddSkills("Technician/Any",15); //SEE RULEZ!!!

            s4LabelElem5 = "Technician/Any";
            s4SkillsElem5 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem5 = 15;

            S4AddSkills("Training",15);
//            S4AddSkills("+160 total additional XP (+40 XP each to any four Skills in any Skill Fields the character possesses; if none, raise any four Skills by +40 XP)",160); //SEE RULEZ!!!

        }

        if (s4WobChk == true) {
            s4AttrMod["INT"] = 25;
            s4AttrMod["CHA"] = -25;

            S4AddTraits("Equipped", 70);
            S4AddTraits("Rank", 70);
            S4AddTraits("Compulsion/Hatred of ComStar", -75);
            S4AddTraits("Compulsion/Hatred of Clans", -100);

//            S4AddSkills("Communications/Any",50); //SEE RULEZ!!!

            s4LabelElem5 = "Communications/Any";
            s4SkillsElem5 = CreateSubSkillList("Communications");// << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
            s4Elem5 = 50;

            S4AddSkills("Computers",35);
            S4AddSkills("Cryptography",25);
            S4AddSkills("Interests/Writings of Jerome Blake",50);
            S4AddSkills("Interrogation",40);
            S4AddSkills("Perception",25);

//            S4AddSkills("+160 total additional XP (+40 XP each to any four Skills in any Skill Fields the character possesses; if none, raise any four Skills by +40 XP)",160); //SEE RULEZ!!!

        }

    }

    if(nameElem == "Covert Operations") {
        s4toolTip = "Spies, espionage agents, scouts, insurgents or even undercover\nofficers—all are specialists in the shadowy deeds collectively\nknown as covert operations. These operatives are most successful\nwhen their deeds are unknown, and many take to the field secure\nonly in the knowledge that—should they fail—their governments\nwill disavow all knowledge of their existence.\nPrerequisites: Inner Sphere or Periphery affiliation only. Must\nhave prior military or intelligence training in a Stage 3 module or\nat least one Tour of Duty module with a minimum +150XPs in\neither the Connections Trait or the Leadership Skill. Character also\nmust not have the Combat Paralysis Trait.";

        s4XpCost = 1000;
        s4FlexXP = 0;
        s4Age = 6;

//        s4AttrMod["BOD"] = 50; //SEE RULEZ!!!

        s4LabelElem6 = "Choose two";
        s4AttrElem6 << "BOD" << "RFL" << "WIL" << "EDG";
        s4Elem6 = 50;
        s4Repit6 = 2;

        S4AddTraits("Alternate ID", 85);
        S4AddTraits("Enemy", -25);
        S4AddTraits("In For Life", -110);
        S4AddTraits("Sixth Sense", 50);

        S4AddSkills("Acting",25);
        S4AddSkills("Perception",50);
//        S4AddSkills("Survival/Any",75); //SEE RULEZ!!!

        s4LabelElem1 = "Survival/Any";
        s4SkillsElem1 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem1 = 75;

//        S4AddSkills("+150 total additional XP (+25 XP assigned to a maximum of six Skills in the characterâ€™s Military or Intelligence/Police Skill Fields)",25); //SEE RULEZ!!!

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "25XP x 6 skill";
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 25;
        s4Repit7 = 6;

        swpstr = "Connections";
        s4PreTraits.append(qMakePair(swpstr,150));

        swpstr = "Leadership";
        s4PreSkills.append(qMakePair(swpstr,150));

        if (s4AffName.first == "Cappelan Confederation") {
            s4AttrMod["DEX"] = 25;

            S4AddTraits("Citizenship", 75);
            S4AddTraits("Dark Secret", -50);
            S4AddTraits("Fit", 25);
            S4AddTraits("Reputation", -50);

            S4AddSkills("Climbing",50);
            S4AddSkills("Demolitions",60);
            S4AddSkills("Escape Artist",35);
            S4AddSkills("Interrogation",50);
            S4AddSkills("Investigation",15);
            S4AddSkills("Martial Arts",75);
            S4AddSkills("Perception",15);
            S4AddSkills("Science/Chemistry",40);
            S4AddSkills("Stealth",50);
//            S4AddSkills("Tactics/Any",30); //SEE RULEZ!!!

            s4LabelElem2 = "Tactics/Any";
            s4SkillsElem2 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem2 = 30;

            S4AddSkills("Thrown Weapons",45);
        }

        if (s4ComChk == true || s4WobChk == true) {
            s4AttrMod["INT"] = 25;

            S4AddTraits("Combat Sense", 50);
            S4AddTraits("Fast Learner", 50);
            S4AddTraits("Impatient", -50);
            S4AddTraits("Reputation", -50);

            S4AddSkills("Administration",50);
//            S4AddSkills("Communications/Any",60); //SEE RULEZ!!!

            s4LabelElem2 = "Communications/Any";
            s4SkillsElem2 = CreateSubSkillList("Communications");//  << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
            s4Elem2 = 60;

            S4AddSkills("Computers",50);
            S4AddSkills("Cryptography",60);
            S4AddSkills("Interrogation",75);
            S4AddSkills("Small Arms",50);
            S4AddSkills("Strategy",50);
//            S4AddSkills("Tactics/Any",40); //SEE RULEZ!!!

            s4LabelElem3 = "Tactics/Any";
            s4SkillsElem3 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem3 = 40;

//            S4AddSkills("Technician/Any",50); //SEE RULEZ!!!

            s4LabelElem4 = "Technician/Any";
            s4SkillsElem4 = CreateSubSkillList("Technician");//  << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem4 = 50;
        }

        if (s4AffName.first == "Terran") {
            s4AttrMod["INT"] = 25;

            S4AddTraits("Combat Sense", 50);
            S4AddTraits("Fast Learner", 50);
            S4AddTraits("Impatient", -50);
            S4AddTraits("Reputation", -50);

            S4AddSkills("Administration",50);
//            S4AddSkills("Communications/Any",60); //SEE RULEZ!!!

            s4LabelElem2 = "Communications/Any";
            s4SkillsElem2 = CreateSubSkillList("Communications");//  << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
            s4Elem2 = 60;

            S4AddSkills("Computers",50);
            S4AddSkills("Cryptography",60);
            S4AddSkills("Interrogation",75);
            S4AddSkills("Small Arms",50);
            S4AddSkills("Strategy",50);
//            S4AddSkills("Tactics/Any",40); //SEE RULEZ!!!

            s4LabelElem3 = "Tactics/Any";
            s4SkillsElem3 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem3 = 40;

//            S4AddSkills("Technician/Any",50); //SEE RULEZ!!!

            s4LabelElem4 = "Technician/Any";
            s4SkillsElem4 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem4 = 50;
        }

        if (s4AffName.first == "Draconis Combine") {
            s4AttrMod["INT"] = 50;
            s4AttrMod["WIL"] = 50;
            s4AttrMod["CHA"] = -50;
            s4AttrMod["EDG"] = -50;

            S4AddTraits("Connections", 75);
            S4AddTraits("Enemy", -25);
            S4AddTraits("Equipped", 50);
            S4AddTraits("Reputation", -75);
//            S4AddTraits("Choose one: Compulsion/Loyalty to House Kurita or Compulsion/Loyalty to Draconis Combine", -50); //SEE RULEZ!!!

            s4LabelElem2 = "Choose one";
            s4TraitsElem2 << "Compulsion/Loyalty to House Kurita" << "Compulsion/Loyalty to Draconis Combine";
            s4Elem2 = -50;

            S4AddSkills("Acrobatics/Gymnastics",35);
            S4AddSkills("Climbing",50);
            S4AddSkills("Computers",25);
            S4AddSkills("Cryptography",40);
            S4AddSkills("Interrogation",60);
            S4AddSkills("Investigation",25);
            S4AddSkills("Leadership",40);
            S4AddSkills("Martial Arts",55);
            S4AddSkills("Melee Weapons",30);

            s4AffProt = 40;
            s4AffStreet = 35;

            S4AddSkills("Stealth",30);

//            S4AddSkills("Tactics/Any",35); //SEE RULEZ!!!

            s4LabelElem3 = "Tactics/Any";
            s4SkillsElem3 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem3 = 35;

            S4AddSkills("Training",25);
        }

        if (s4AffName.first == "Federated Suns") {

            S4AddTraits("Combat Sense", 50);
//            S4AddTraits("Compulsion/Any Addiction", -25); //SEE RULEZ!!!

            s4LabelElem2 = "Compulsion/Any Addiction";
            s4TraitsElem2 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality";
            s4Elem2 = -25;

            S4AddTraits("Connections", 40);
            S4AddTraits("Enemy", -75);
            S4AddTraits("Rank", 50);

            S4AddSkills("Acrobatics/Free-Fall",20);
            S4AddSkills("Climbing",35);
            S4AddSkills("Computers",45);
            S4AddSkills("Cryptography",30);
            S4AddSkills("Driving/Any",25);
            S4AddSkills("Interrogation",25);
            S4AddSkills("Investigation",65);
            S4AddSkills("Leadership",20);
//            S4AddSkills("Navigation/Any",40); //SEE RULEZ!!!

            s4LabelElem3 = "Navigation/Any";
            s4SkillsElem3 = CreateSubSkillList("Navigation");// << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
            s4Elem3 = 40;

            S4AddSkills("Security Systems",50);

            s4AffStreet = 35;

            S4AddSkills("Support Weapons",30);
//            S4AddSkills("Tactics/Any",30); //SEE RULEZ!!!

            s4LabelElem4 = "Tactics/Any";
            s4SkillsElem4 = CreateSubSkillList("Tactics");//  << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem4 = 30;
        }

        if (s4AffName.first == "Free Worlds League") {

            S4AddTraits("Slow Learner", -50);
            S4AddTraits("Tech Empathy", 50);
            S4AddTraits("Choose one of the following two pairs of Traits:Implant/Prosthetic (+50 XP) and Lost Limb (â€“50 XP) or Implant/Prosthetic (+50 XP) and Lost Limb (â€“50 XP)", -50); //SEE RULEZ!!!

            s4LabelElem2 = "Choose one";
            s4TraitsElem2 << "Implant/Prosthetic (+50 XP) and Lost Limb (â€“50 XP)" << "Implant/Prosthetic (+50 XP) and Lost Limb (â€“50 XP)";
            s4Elem2 = 50;


            S4AddSkills("Administration",45);
            S4AddSkills("Computers",30);
            S4AddSkills("Disguise",35);
//            S4AddSkills("Driving/Any",35); //SEE RULEZ!!!

            s4LabelElem3 = "Driving/Any";
            s4SkillsElem3 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
            s4Elem3 = 35;

            S4AddSkills("Forgery",45);
            S4AddSkills("Interrogation",35);
            S4AddSkills("Investigation",40);
            S4AddSkills("Martial Arts",25);
            S4AddSkills("MedTech",35);

            s4AffProt = 60;

            S4AddSkills("Swimming",50);
//            S4AddSkills("Tracking/Any",65);

            s4LabelElem4 = "Tracking/Any";
            s4SkillsElem4 = CreateSubSkillList("Tracking");// << "Tracking/Urban" << "Tracking/Wilds";
            s4Elem4 = 65;

        }

        if (s4AffName.first == "Free Rasalhague Republic") {
            s4AttrMod["WIL"] = 50;

            S4AddTraits("Alternate ID", 35);
            S4AddTraits("Compulsion/Rasalhague Pride", -75);
            S4AddTraits("Equipped", 35);
            S4AddTraits("Impatient", -25);

            S4AddSkills("Cryptography", 35);
            S4AddSkills("Demolitions", 50);
            S4AddSkills("Disguise", 35);
            S4AddSkills("Interrogation",25);
            S4AddSkills("MedTech",50);
            S4AddSkills("Melee Weapons",35);
            S4AddSkills("Perception",25);
            S4AddSkills("Security Systems",40);
            S4AddSkills("Small Arms",50);
            S4AddSkills("Stealth",50);
            S4AddSkills("Tactics/Infantry",35);
//            S4AddSkills("Technician/Any",25); //SEE RULEZ!!!

            s4LabelElem2 = "Technician/Any";
            s4SkillsElem2 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem2 = 25;

//            S4AddSkills("Tracking/Any",25); //SEE RULEZ!!!

            s4LabelElem3 = "Tracking/Any";
            s4SkillsElem3 = CreateSubSkillList("Tracking");// << "Tracking/Urban" << "Tracking/Wilds";
            s4Elem3 = 25;

        }

        if (s4AffName.first == "Lyran Alliance") {
            s4AttrMod["WIL"] = 30;

            S4AddTraits("Connections", 85);
            S4AddTraits("Enemy", -45);
            S4AddTraits("Introvert", -85);
            S4AddTraits("Property", 25);
            S4AddTraits("Rank", 85);
            S4AddTraits("Reputation", -20);

            S4AddSkills("Acting",30);
            S4AddSkills("Computers",50);
            S4AddSkills("Cryptography",35);
            S4AddSkills("Driving",35);
            S4AddSkills("Forgery",20);
            S4AddSkills("Investigation",50);
            S4AddSkills("Martial Arts",40);
            S4AddSkills("Negotiation",50);
            S4AddSkills("Strategy",25);
            S4AddSkills("Support Weapons",25);
//            S4AddSkills("Tactics/Any",25); //SEE RULEZ!!!

            s4LabelElem2 = "Tactics/Any";
            s4SkillsElem2 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem2 = 25;

            S4AddSkills("Training",40);
        }

        if (s4AffName.first == "Minor Periphery" || s4AffName.first == "Major Periphery State") {
            s4AttrMod["BOD"] = 25;
            s4AttrMod["WIL"] = 50;

            S4AddTraits("Alternate ID", 50);
            S4AddTraits("Compulsion/Gambling", -35);
            S4AddTraits("Connections", 25);
            S4AddTraits("Introvert", -35);

            S4AddSkills("Administration",50);
//            S4AddSkills("Driving/Any",50); //SEE RULEZ!!!

            s4LabelElem3 = "Driving/Any";
            s4SkillsElem3 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
            s4Elem3 = 50;

            S4AddSkills("Disguise",35);
            S4AddSkills("Investigation",65);
            S4AddSkills("Melee Weapons",25);
            S4AddSkills("Negotiation",25);
            S4AddSkills("Security Systems",25);
            S4AddSkills("Small Arms",60);
//            S4AddSkills("Survival/Any",50); //SEE RULEZ!!!

            s4LabelElem2 = "Survival/Any";
            s4SkillsElem2 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            s4Elem2 = 50;

            S4AddSkills("Throwing Weapons",35);
        }

        if (s4AffName.first == "Deep Periphery") {
            s4AttrMod["BOD"] = 25;
            s4AttrMod["WIL"] = 50;

            S4AddTraits("Alternate ID", 50);
            S4AddTraits("Compulsion/Gambling", -35);
            S4AddTraits("Connections", 25);
            S4AddTraits("Introvert", -35);

            S4AddSkills("Administration",50);
//            S4AddSkills("Driving/Any",50); //SEE RULEZ!!!

            s4LabelElem3 = "Driving/Any";
            s4SkillsElem3 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
            s4Elem3 = 50;

            S4AddSkills("Disguise",35);
            S4AddSkills("Investigation",65);
            S4AddSkills("Melee Weapons",25);
            S4AddSkills("Negotiation",25);
            S4AddSkills("Security Systems",25);
            S4AddSkills("Small Arms",60);
//            S4AddSkills("Survival/Any",50); //SEE RULEZ!!!

            s4LabelElem2 = "Survival/Any";
            s4SkillsElem2 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
            s4Elem2 = 50;

            S4AddSkills("Throwing Weapons",35);
        }

        if (s4AffName.first == "Independent") {
            s4AttrMod["RFL"] = 75;
            s4AttrMod["CHA"] = -50;

            S4AddTraits("Bloodmark", -50);
            S4AddTraits("Connections", 75);
            S4AddTraits("Extra Income", 25);
            S4AddTraits("Reputation", -75);
            S4AddTraits("Wealth", -50);

            S4AddSkills("Acting",50);
            S4AddSkills("Climbing",35);
            S4AddSkills("Cryptography",40);
            S4AddSkills("Escape Artist",75);
//            S4AddSkills("Interests/Any",50); //SEE RULEZ!!!

            s4LabelElem2 = "Interests/Any";
            s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem2 = 50;

//            S4AddSkills("Language/Any",75); //SEE RULEZ!!!

            s4LabelElem3 = "Language/Any";
            s4SkillsElem3 = CreateSubSkillList("Language");// << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
            s4Elem3 = 75;

            S4AddSkills("Martial Arts",35);
//            S4AddSkills("Navigation/Any",25); //SEE RULEZ!!!

            s4LabelElem4 = "Navigation/Any";
            s4SkillsElem4 = CreateSubSkillList("Navigation");//  << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
            s4Elem4 = 25;

//            S4AddSkills("Protocol/Any",45); //SEE RULEZ!!!

            s4LabelElem4 = "Protocol/Any";
            s4SkillsElem4 = CreateSubSkillList("Protocol");// << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
            s4Elem4 = 45;

            S4AddSkills("Science/Chemistry",25);
            S4AddSkills("Small Arms",25);
//            S4AddSkills("Streetwise/Any",35); //SEE RULEZ!!!

            s4LabelElem5 = "Streetwise/Any";
            s4SkillsElem5 = CreateSubSkillList("Streetwise");// << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
            s4Elem5 = 35;

//            S4AddSkills("Tactics/Any",35); //SEE RULEZ!!!

            s4LabelElem6 = "Tactics/Any";
            s4SkillsElem6 = CreateSubSkillList("Tactics");// << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem6 = 35;
        }
    }

    if(nameElem == "Dark Caste") {
        s4toolTip = "Though often referred to as the Bandit Caste as well, the\nDark Caste is more an outcast fragment of Clan society than a\npirate collective. Whether born to it or kicked out of the Clans\nfor some indiscretion, the life of the Dark Caste is that of a\ndrifter or fugitive, driven to the shadows of Clan civilization\nand often lucky to find any form of passage off world for a safer\nhaven. Resourceful Dark Casters often form the core of the\nunderworld in Clan society, a rough analog to the organized\ncrime syndicates that plague the realms of the Inner Sphere.\nPrerequisites:Any Clan affiliation, but only after leaving\nthe Clans or washing out of training. ";
        s4XpCost = 700;
        s4FlexXP = 115;
        s4Age = 4;

        s4AttrMod["BOD"] = 25;
        s4AttrMod["DEX"] = 25;

        S4AddTraits("Compulsion/Distrust of Inner Sphere", 75);
        S4AddTraits("Reputation", -100);
        S4AddTraits("Wealth", -25);

        S4AddSkills("Acting",30);
        S4AddSkills("Disguise",50);
        S4AddSkills("Escape Artist",50);
//        S4AddSkills("Gunnery/Any",75); //SEE RULEZ!!!

        s4LabelElem1 = "Gunnery/Any";
        s4SkillsElem1 = CreateSubSkillList("Gunnery");// << "Gunnery/Aerospace" << "Gunnery/Air Vehicle" << "Gunnery/Battlesuit" << "Gunnery/Ground Vehicle" << "Gunnery/'Mech" << "Gunnery/ProtoMech"  << "Gunnery/Sea Vehicle" << "Gunnery/Spacecraft" << "Gunnery/Turret";
        s4Elem1 = 75;

        S4AddSkills("Martial Arts",60);
//        S4AddSkills("Navigation/Any",50); //SEE RULEZ!!!

        s4LabelElem2 = "Navigation/Any";
        s4SkillsElem2 = CreateSubSkillList("Navigation");// << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
        s4Elem2 = 50;

        S4AddSkills("Negotiation",25);
        S4AddSkills("Perception",40);
//        S4AddSkills("Piloting/Any",20); //SEE RULEZ!!!

        s4LabelElem3 = "Piloting/Any";
        s4SkillsElem3 = CreateSubSkillList("Piloting");// << "Piloting/Aerospace" << "Piloting/Air Vehicle" << "Piloting/Battlesuit" << "Piloting/Ground Vehicle" << "Piloting/Mech" << "Piloting/ProtoMech" << "Piloting/Rail Vehicle" << "Piloting/Sea Vehicle" << "Piloting/Spacecraft";
        s4Elem3 = 20;

        S4AddSkills("Prestidigitation",25);
        S4AddSkills("Protocol/Clan",-25);
        S4AddSkills("Running",30);
        S4AddSkills("Stealth",40);
//        S4AddSkills("Survival/Any",45); //SEE RULEZ!!!

        s4LabelElem4 = "Survival/Any";
        s4SkillsElem4 = CreateSubSkillList("Survival");// << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem4 = 45;

//        S4AddSkills("Technician/Any",45); //SEE RULEZ!!!

        s4LabelElem5 = "Technician/Any";
        s4SkillsElem5 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        s4Elem5 = 45;

//        S4AddSkills("Technician/Any",25); //SEE RULEZ!!!

        s4LabelElem6 = "Technician/Any";
        s4SkillsElem6 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        s4Elem6 = 25;

    }

    if(nameElem == "Explorer") {
        s4toolTip = "For all the thousands of worlds inhabited by humankind in\nthe Inner Sphere and Clan space, there are thousands more\nwaiting to be discovered—or rediscovered, as the case may\nbe. Organizations great and small (and even well-off, thrill-\nseeking individuals and lostech prospectors) have dedicated\nthemselves to exploring these lost or untapped worlds,\nseeking everything from relics and ruins of the fallen Star\nLeague to potential new resources waiting for a colony to\nexploit them.\nPrerequisites: Inner Sphere affiliations must have at least\n150XP in Connections before finalizing character. Periphery\naffiliations have no Connections restriction. Clan affiliations\nmust be of the scientist caste only. May not have TDS Trait.";

        s4XpCost = 900;
        s4FlexXP = 170;
        s4Age = 6;

        s4AttrMod["BOD"] = 20;
        s4AttrMod["RFL"] = 30;
        s4AttrMod["INT"] = 30;
        s4AttrMod["WIL"] = 30;

        S4AddTraits("G-Tolerance", 50);
        S4AddTraits("Good Hearing", 35);
        S4AddTraits("Vehicle", 35);
        S4AddTraits("Introvert",-40);
        S4AddTraits("Wealth",-50);

        S4AddSkills("Appraisal",35);
        S4AddSkills("Climbing",25);
//        S4AddSkills("Communications/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Communications/Any";
        s4SkillsElem1 = CreateSubSkillList("Communications");//  << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
        s4Elem1 = 35;

        S4AddSkills("Computers",20);
        S4AddSkills("Investigation",35);

        s4AffLang = 25;

//        S4AddSkills("Language/Any",40); //SEE RULEZ!!!

        s4LabelElem2 = "Language/Any";
        s4SkillsElem2 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem2 = 40;

        S4AddSkills("Martial Arts",25);
        S4AddSkills("Melee Weapons",30);
        S4AddSkills("MedTech",15);
//        S4AddSkills("Navigation/Any",50); //SEE RULEZ!!!

        s4LabelElem3 = "Navigation/Any";
        s4SkillsElem3 = CreateSubSkillList("Navigation");//  << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
        s4Elem3 = 50;

//        S4AddSkills("Piloting/Any",50); //SEE RULEZ!!!

        s4LabelElem4 = "Piloting/Any";
        s4SkillsElem4 = CreateSubSkillList("Piloting");//  << "Piloting/Aerospace" << "Piloting/Air Vehicle" << "Piloting/Battlesuit" << "Piloting/Ground Vehicle" << "Piloting/Mech" << "Piloting/ProtoMech" << "Piloting/Rail Vehicle" << "Piloting/Sea Vehicle" << "Piloting/Spacecraft";
        s4Elem3 = 50;

        S4AddSkills("Sensor Operations",55);
//        S4AddSkills("Survival/Any",75); //SEE RULEZ!!!

        s4LabelElem5 = "Survival/Any";
        s4SkillsElem5 = CreateSubSkillList("Survival");//  << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem5 = 75;

//        S4AddSkills("Streetwise/Any",35); //SEE RULEZ!!!

        s4LabelElem6 = "Streetwise/Any";
        s4SkillsElem6 = CreateSubSkillList("Streetwise");// << "Streetwise/Periphery" << "Streetwise/Clan" << "Streetwise/Combine" << "Streetwise/FedSuns" << "Streetwise/Lyran" << "Streetwise/Rim Collection" << "Streetwise/Magistracy" << "Streetwise/Outworlds" << "Streetwise/Taurian" << "Streetwise/Rasalhague";
        s4Elem6 = 35;

        S4AddSkills("Tracking/Any",25); //SEE RULEZ!!!

        s4LabelElem7 = "Tracking/Any";
        s4SkillsElem7 = CreateSubSkillList("Tracking");// << "Tracking/Urban" << "Tracking/Wilds";
        s4Elem7 = 25;

        S4AddSkills("Zero-G Training",15);

        swpstr = "Connections";
        s4PreTraits.append(qMakePair(swpstr,150));
    }

    if(nameElem == "Goliath Scorpion Seeker") {
        s4toolTip = "As a general rule, Clan warriors do not practice the\nindulgence of exploration for its own sake, preferring to leave\nthat \"menial\" task to the Scientist caste. Long fascinated by\ntheir Star League roots, many warriors of Clan Goliath Scorpion\nhave become the exception that proves the rule. Devoted to\nfinding relics of the fallen Star League wherever they may be,\nthese solitary Seekers pursue private quests (with their Clan's\nblessing) as far from the Homeworlds as the Inner Sphere\nitself.\nPrerequisites:Clan Goliath Scorpion affiliation ; warrior\ncaste only ";

        s4XpCost = 700;
        s4FlexXP = 160;
        s4Age = 4;

        S4AddTraits("Connections", 75);
        S4AddTraits("In For Life", -25);

        S4AddSkills("Appraisal",50);
        S4AddSkills("Computers",65);
        S4AddSkills("Interests/Archaeology",55);
        S4AddSkills("Interests/Star League History",60);
        S4AddSkills("Interests/Pre-Star League History",35);
//        S4AddSkills("Language/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Language/Any";
        s4SkillsElem1 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem1 = 35;

        S4AddSkills("MedTech",40);
        S4AddSkills("Navigation/Space",35);
        S4AddSkills("Perception",50);
//        S4AddSkills("Survival/Any",40); //SEE RULEZ!!!

        s4LabelElem2 = "Survival/Any";
        s4SkillsElem2 = CreateSubSkillList("Survival");//  << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem2 = 40;

        S4AddSkills("Zero-G Operations",25);
    }

    if(nameElem == "Guerilla Insurgent") {
        s4toolTip = "Fighting for a cause, whether freedom from tyranny or\nto drive foreign invaders from the homeland, the guerilla\ninsurgent is an outlaw many condemn as a terrorist and many\nothers hail as a patriot. Armed and dangerous—and possibly\nbacked by a foreign government—guerillas are seen as\nenemy combatants by those they face, even though many of\nthese warriors may be little more than otherwise law-abiding\ncitizens with little formal training.\nPrerequisites:Cannot have a Clan affiliation.";

        s4XpCost = 900;
        s4FlexXP = 180;
        s4Age = 6;

        s4AttrMod["STR"] = 100;
        s4AttrMod["WIL"] = 100;

        S4AddTraits("Bloodmark", -50);
        S4AddTraits("Combat Sense", 30);
        S4AddTraits("Connections", 50);
        S4AddTraits("Equipped", 30);
        S4AddTraits("Compulsion/Hatred for Authority", -100);
        S4AddTraits("Dependent", -25);
        S4AddTraits("Unlucky", -35);

        S4AddSkills("Computers",45);
        S4AddSkills("Demolitions",65);
        S4AddSkills("Disguise",40);
        S4AddSkills("Escape Artist",25);
        S4AddSkills("Melee Weapons",20);
        S4AddSkills("Perception",25);
        S4AddSkills("Prestidigitation",50);
        S4AddSkills("Security Systems",25);
        S4AddSkills("Small Arms",35);
        S4AddSkills("Support Weapons",35);
//        S4AddSkills("Survival/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Survival/Any";
        s4SkillsElem1 = CreateSubSkillList("Survival");//   << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem1 = 35;

        if (s4AffName.first == "Free Rasalhague Republic") {
            S4AddTraits("Bloodmark", -35);
            S4AddTraits("Combat Sense", 40);
            S4AddTraits("Lost Limb", -50);
            S4AddTraits("Prosthetic", 50);

            S4AddSkills("Demolitions",40);
            S4AddSkills("Forgery",40);
            S4AddSkills("Leadership",35);
            S4AddSkills("Protocol/Rasalhague",35);
            S4AddSkills("Streetwise/Rasalhague",40);
//            S4AddSkills("Tactics/Any",25); //SEE RULEZ!!!

            s4LabelElem2 = "Tactics/Any";
            s4SkillsElem2 = CreateSubSkillList("Tactics");//  << "Tactics/Infantry" << "Tactics/Land" << "Tactics/Sea" << "Tactics/Air" << "Tactics/Space";
            s4Elem2 = 25;

        } else {
            s4AttrMod["EDG"] = -25;

            S4AddTraits("Dark Secret", -50);
            S4AddTraits("Enemy", -50);
            S4AddTraits("Reputation", 25);
            S4AddTraits("Toughness", 25);

            S4AddSkills("Climbing",40);
//            S4AddSkills("Driving/Any",50); //SEE RULEZ!!!

            s4LabelElem2 = "Driving/Any";
            s4SkillsElem2 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
            s4Elem2 = 50;

            S4AddSkills("Interrogation",50);

            s4AffLang = 35;

            S4AddSkills("Small Arms",25);
            S4AddSkills("Swimming",45);
            S4AddSkills("Tactics/Infantry",50);
        }
    }

    if(nameElem == "Merchant") {
        s4toolTip = "While most inhabited worlds in the thirty-first century are\nreasonably self-suffi cient, there does exist a need (or merely a\nfervent desire) for raw materials, manufactured goods and luxuries\nthat can only be found elsewhere. Responding to this need are\nmerchants. The trader’s life involves almost constant JumpShip\ntravel, and includes free traders (independent operators), merchant\nmasters (accomplished traders who often have a corporate\nbacking), Deep Periphery traders (those who travel well beyond\nthe relatively safer borders of the Inner Sphere) and Diamond Shark\nwarrior-merchants (inactive warriors from the Diamond Shark Clan\nwho now seek to further their Clan’s profi ts and resources through\nless brutal means). Some merchants maintain a regular route, while\nothers more daring have been known to seek their fortunes on any\nworld their vessels can reach.\nPrerequisites: Merchant Field, or a minimum of +50 XPs each\nin Negotiation and Administration; Diamond-Shark warrior-\nmerchants must have Clan/Diamond Shark affi  liation, be of either\nthe warrior or merchant caste, and must not have the TDS Trait.";
        s4XpCost = 900;
        s4FlexXP = 200;
        s4Age = 4;

        s4AttrMod["CHA"] = 50;

        S4AddTraits("Enemy", -75);
        S4AddTraits("Reputation", 50);
        S4AddTraits("Wealth", 50);

        S4AddSkills("Acting",20);
        S4AddSkills("Appraisal",20);
        S4AddSkills("Computers",15);
//        S4AddSkills("Interests/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Interests/Any";
        s4SkillsElem1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem1 = 35;

        s4AffLang = 20;

//        S4AddSkills("Language/Any",25); //SEE RULEZ!!!

        s4LabelElem2 = "Language/Any";
        s4SkillsElem2 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem2 = 25;

        S4AddSkills("Negotiation",20);
        S4AddSkills("Perception",30);
//        S4AddSkills("Protocol/Any",35); //SEE RULEZ!!!

        s4LabelElem3 = "Protocol/Any";
        s4SkillsElem3 = CreateSubSkillList("Protocol");//  << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
        s4Elem3 = 35;

//        S4AddSkills("Protocol/Any",15); //SEE RULEZ!!!

        s4LabelElem4 = "Protocol/Any";
        s4SkillsElem4 = CreateSubSkillList("Protocol");// << "Protocol/Capellan" << "Protocol/Combine" << "Protocol/FedSuns" << "Protocol/Lyran" << "Protocol/Clan" << "Protocol/Nearest state" << "Protocol/ComStar" << "Protocol/Word of Blake" << "Protocol/Free Worlds" << "Protocol/Rasalhague";
        s4Elem4 = 15;

        S4AddSkills("Zero-G Operations",10);

        swpstr = "Negotiation";
        s4PreSkills.append(qMakePair(swpstr,50));
        swpstr = "Administration";
        s4PreSkills.append(qMakePair(swpstr,50));
    }


    if(nameElem == "Ne'er-Do-Well") {
        s4toolTip = "\"Aimless\" is one way to define the lifestyle of the ne'er-do-well.\nCommitted to no one job or place for very long, this individual is\nsomething of a free spirit, either still looking for his place in the\nworld or simply determined to see all there is to see before he\nsettles down on any one course. The Ne'er-Do-Well module is a\ncatch-all category that can be applied to any character who does\nnot fi t the other modules.\nPrerequisites:Not available to Clan characters unless they\nleave the Clans and travel to the Inner Sphere";
        s4XpCost = 700;
        s4FlexXP = 145;
        s4Age = 4;

        s4AttrMod["EDG"] = 75;
//        s4AttrMod["WIL"] = 75; // SEE RULEZ!!!

        s4LabelElem6 = "+75 to any one";
        s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX" << "INT" << "WIL" << "CHA";
        s4Elem6 = 75;

        S4AddTraits("Extra Income", 75);
        S4AddTraits("Reputation", -25);
        S4AddTraits("Wealth", -50);

        S4AddSkills("Acting",25);
        S4AddSkills("Appraisal",25);
        S4AddSkills("Art/Cooking",35);
        S4AddSkills("Disguise",15);
        S4AddSkills("Escape Artist",35);
//        S4AddSkills("Interests/Any",40); //SEE RULEZ!!!

        s4LabelElem1 = "Interests/Any";
        s4SkillsElem1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem1 = 40;

//        S4AddSkills("Language/Any",25); //SEE RULEZ!!!

        s4LabelElem2 = "Language/Any";
        s4SkillsElem2 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem2 = 25;

        S4AddSkills("Martial Arts",20);
        S4AddSkills("Negotiation",35);
        S4AddSkills("Prestidigitation",25);
        S4AddSkills("Running",35);

        s4AffStreet = 25;

//        S4AddSkills("Survival/Any",35); //SEE RULEZ!!!

        s4LabelElem3 = "Survival/Any";
        s4SkillsElem3 = CreateSubSkillList("Survival");//  << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem3 = 35;

        S4AddSkills("Swimming",10);
    }

    if(nameElem == "Organized Crime") {
        s4toolTip = "In most worlds of the Inner Sphere, they're known as the mafia,\nthe mob, or (more ominously) the syndicate. In the Draconis\nCombine, they are typically known as yakuza, and on worlds in and\naround the Capellan Confederation they are the tongs or the triads.\nWhatever the name, their goals are the same: to amass wealth and\npower through any means necessary, legal or otherwise (mostly\notherwise). Most organized crime syndicates rule their unofficial\nterritories through a combination of brute force and terror, though\nmany know how to present a benevolent facade when situations\ndemand it. When their territories are threatened by rival\norganizations and police, however, the soldiers of organized\ncrime can be as lethal on the street as a MechWarrior on the\nbattlefield.\nPrerequisites: Clan-affiliated characters must take at least\none Dark Caste module before entering organized crime. When\ntaking the Organized Crime module as a Clan character, do\nnot award the module’s Attribute or Trait XP to the character\n(though its cost remains unchanged). ";

        s4XpCost = 1000;
        s4FlexXP = 100;
        s4Age = 5;

        s4AttrMod["EDG"] = 85;

        S4AddTraits("Alternate ID", 100);
        S4AddTraits("In For Life", -150);
//        S4AddTraits("Choose one: Dark Secret (-85 XP) or Compulsion/Loyalty to Crime Boss (-85 XP; see Notes below);", -85);

        s4LabelElem1 = "Choose one";
        s4TraitsElem1 << "Dark Secret" << "Compulsion/Loyalty to Crime Boss";
        s4Elem1 = -85;

        S4AddSkills("Acting",60);
        S4AddSkills("Career/Syndicate",100);
        S4AddSkills("Computers",15);
        S4AddSkills("Demolitions",50);
//        S4AddSkills("Driving/Any",30); //SEE RULEZ!!!

        s4LabelElem2 = "Driving/Any";
        s4SkillsElem2 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
        s4Elem2 = 30;

        S4AddSkills("Escape Artist",35);
        S4AddSkills("Forgery",35);
//        S4AddSkills("Interests/Any Sport",55); //SEE RULEZ!!!

        s4LabelElem3 = "Interests/Any Sport";
        s4SkillsElem3 << "Interests/Football" << "Interests/Ice Hockey" << "Interests/Soccer" << "Interests/Tennis" << "Interests/Volleyball" << "Interests/Basketball" << "Interests/Baseball";
        s4Elem3 = 55;

        S4AddSkills("Interrogation",85);
        S4AddSkills("Language/Syndicate",50);
        S4AddSkills("Leadership",25);
        S4AddSkills("Martial Arts",30);
        S4AddSkills("Melee Weapons",45);
        S4AddSkills("Negotiation",35);
        S4AddSkills("Perception",35);
        S4AddSkills("Prestidigitation",35);

        s4AffProt = 25;

        S4AddSkills("Security Systems",45);
        S4AddSkills("Small Arms",75);
        S4AddSkills("Stealth",35);

        s4AffStreet = 50;
    }

    if(nameElem == "Postgraduate Studies") {
        s4toolTip = "For some academics, the scholastic experience does not end\nwhen the degree is handed out. Through postgraduate studies,\nthe character takes his recently hard-earned knowledge into\nthe field, rounding out his expensive education with some\nhands-on experience before entering the workforce proper.\nPrerequisites:University module required.";

        s4XpCost = 700;
        s4FlexXP = 175;
        s4Age = 5;

        s4AttrMod["INT"] = 50;
        s4AttrMod["WIL"] = -50;

        S4AddTraits("Connections", 75);
        S4AddTraits("Extra Income", 25);
        S4AddTraits("Wealth", -100);

        S4AddSkills("Appraisal",50);
//        S4AddSkills("Interests/Any Academic",120); //SEE RULEZ!!!

        s4LabelElem1 = "Interests/Any Academic";
        s4SkillsElem1 << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem1 = 120;

//        S4AddSkills("Interests/Any",85); //SEE RULEZ!!!

        s4LabelElem2 = "Interests/Any";
        s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem2 = 85;

        s4AffLang = 85;

//        S4AddSkills("Language/Any",50); //SEE RULEZ!!!

        s4LabelElem3 = "Language/Any";
        s4SkillsElem3 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem3 = 50;

//        S4AddSkills("Survival/Any",35); //SEE RULEZ!!!

        s4LabelElem4 = "Survival/Any";
        s4SkillsElem4 = CreateSubSkillList("Survival");//  << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem4 = 35;

        S4AddSkills("Training",75);
        S4AddSkills("Zero-G Operations",25);
    }

    if(nameElem == "Protomech Pilot Training") {
        s4toolTip = "In some Clans, aerospace warriors who wash out of\nconventional warrior training may get a new lease on life by\nopting for retraining as a ProtoMech warrior. Though some of\nthese Clans also have conventional ProtoMech training now,\nthe relatively new ProtoMech concept and the race to fill their\nranks has prompted many Clans to maintain this “washout\nbackup” program, even though other Clans disdain it.\nPrerequisites:Clan Blood Spirit, Fire Mandrill, Goliath\nScorpion, Hell’s Horses and Snow Raven Affiliations only.\nWarrior caste only. Must have Aerospace Phenotype and\nImplant/EI Neural Implant Traits. May not have Combat\nParalysis, Glass Jaw, Lost Limb, Poor Hearing, Poor Vision or\nSlow Learner Traits.";

        s4XpCost = 600;
        s4FlexXP = 30;
        s4Age = 2;

        s4AttrMod["RFL"] = 50;

        S4AddTraits("Fast Learner", 50);
        S4AddTraits("Toughness", 80);
        S4AddTraits("Vehicle", 75);
        S4AddTraits("Compulsion/Chemical Addiction", -80);
        S4AddTraits("Implant/EI Neural Implant", 150);
        S4AddTraits("Reputation", -75);

        S4AddSkills("Career/Soldier",15);
        S4AddSkills("Escape Artist",20);
        S4AddSkills("Interests/Neural Implants",15);
        S4AddSkills("Martial Arts",30);
        S4AddSkills("Melee Weapons",15);
        S4AddSkills("Tactics/Infantry",50);
        S4AddSkills("Tactics/Land",50);
//        S4AddSkills("+125 total additional XP (+25 XP each to all Skills in the Clan ProtoMech Skill Field)",125); //SEE RULEZ!!!

        S4AddSkills("Gunnery/ProtoMech",25);
        S4AddSkills("Navigation/Ground",25);
        S4AddSkills("Piloting/ProtoMech",25);
        S4AddSkills("Sensor Operations",25);
        S4AddSkills("Tactics/Land",25);

    }

    if(nameElem == "Scientist Caste Service") {
        s4toolTip = "Second only to the warrior caste in power and prestige,\nthe Clan scientist caste has earned its due after centuries of\ndedicated work on perfecting the warrior's eugenics program\nand developing newer and more efficient weaponory to go\nwith them. Despite this, many in the other castes keep a\nwary eye on the scientists, quietly suspecting that this highly\nintelligent and resourceful segment of Clan society hides its\nown ultimate agenda.\nPrerequisites:Clan affiliation, scientist caste only";

        s4XpCost = 1200;
        s4FlexXP = 50;
        s4Age = 4;

        s4AttrMod["INT"] = 75;
        s4AttrMod["WIL"] = 50;
        s4AttrMod["BOD"] = -75;

//        S4AddTraits("Choose one of the following Trait pairs: Fast Learner (+75 XP) and Combat Paralysis (â€“75 XP) or Natural Aptitude/Any Interest or Science Skill (+75 XP) and Dark Secret (â€“75XP);", 75);

        s4LabelElem1 = "Choose one";
        s4TraitsElem1  << "Fast Learner(+75 XP)&Combat Paralysis(-75 XP)" << "Natural Aptitude/Any Interest(+75 XP)" << "Science Skill(+75 XP)&Dark Secret(-75 XP)";
        s4Elem1 = 75;

        S4AddSkills("Acting",50);
        S4AddSkills("Administration",75);
        S4AddSkills("Career/Scientist",100);
        S4AddSkills("Computers",70);
        S4AddSkills("Cryptography",50);
        S4AddSkills("Interests/Clan Genetics",85);
//        S4AddSkills("Interests/Any",75); //SEE RULEZ!!!

        s4LabelElem2 = "Interests/Any";
        s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem2 = 75;

        S4AddSkills("Investigation",95);
//        S4AddSkills("Language/Any",45); //SEE RULEZ!!!

        s4LabelElem3 = "Language/Any";
        s4SkillsElem3 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem3 = 45;

        S4AddSkills("Leadership",35);
        S4AddSkills("MedTech",65);
        S4AddSkills("Perception",85);

        s4AffProt = 65;

//        S4AddSkills("Protocol/Any Clan",35); //SEE RULEZ!!!

        s4LabelElem4 = "Protocol/Any Clan";
        s4SkillsElem4 = CreateSubSkillList("Protocol");// << "Protocol/Diamond Shark" << "Protocol/Ghost Bear" << "Protocol/Hell's Horses" << "Protocol/Jade Falcon" << "Protocol/Nova Cat" << "Protocol/Snow Raven" << "Protocol/Wolf" << "Protocol/Blood Spirit"  << "Protocol/Cloud Cobra" << "Protocol/Coyote" << "Protocol/Fire Mandrill" << "Protocol/Goliath Scorpion" << "Protocol/Ice Hellion" << "Protocol/Star Adder" << "Protocol/Steel Viper";
        s4Elem4 = 35;

//        S4AddSkills("Science/Any",85); //SEE RULEZ!!!

        s4LabelElem5 = "Science/Any";
        s4SkillsElem5 = CreateSubSkillList("Science");//  << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
        s4Elem5 = 85;

        S4AddSkills("Training",85);
    }

    if(nameElem == "Solaris Insider") {
        s4toolTip = "Solaris VII may not be the only world where 'Mech-scale\ntournaments are held, but the famed Game World in the Lyran\nAlliance is unique in the Inner Sphere for inviting  warriors\nfrom all over human-occupied space to do battle in the arenas.\nWhether for fortune, glory or revenge, gladiators clash almost\ndaily  in  their  simulated  battlefields, while warrior stables\ncompete for top slots in the Grand Tournament.\nPrerequisites: Solaris Stable Internship module required\nor a minimum of 200 XP in the Connections Trait to take this\nmodule.";

        s4XpCost = 825;
        s4FlexXP = 100;
        s4Age = 4;

        s4AttrMod["WIL"] = 50;
        s4AttrMod["CHA"] = 45;
        s4AttrMod["EDG"] = 50;

        S4AddTraits("Compulsion/Gambling", -75);
        S4AddTraits("Connections", 150);
        S4AddTraits("Enemy", 200);
        S4AddTraits("Fit", 50);
        S4AddTraits("Property", 75);
        S4AddTraits("Reputation", 100);
        S4AddTraits("Wealth", 100);

        S4AddSkills("Administration",30);
//        S4AddSkills("Computers/Any",25); //SEE RULEZ!!!

        s4LabelElem1 = "Computers/Any";
        s4SkillsElem1 << "Computers/Programing" << "Computers/Hacking";
        s4Elem1 = 25;

        S4AddSkills("Escape Artist",15);
        S4AddSkills("Forgery",15);
        S4AddSkills("Interests/Solaris Games",20);
        S4AddSkills("Interests/Solaris Night Life",25);
//        S4AddSkills("Interests/Any",15); //SEE RULEZ!!!

        s4LabelElem2 = "Interests/Any";
        s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem2 = 15;

        S4AddSkills("Prestidigitation",15);
        S4AddSkills("Security Systems/Any",25); //SEE RULEZ!!!

        s4LabelElem3 = "Security Systems/Any";
        s4SkillsElem3 = CreateSubSkillList("Security Systems");// << "Security Systems/Electronic" << "Security Systems/Mechanical";
        s4Elem3 = 25;

        S4AddSkills("Stealth",20);
        S4AddSkills("Streetwise/Solaris VII",25);


//        S4AddSkills("+150 total additional XP (+25 XP each to five Skills from the characterâ€™s Solaris Stable Internship Skill Fields; if character does not have any such Fields, choose Skills from the Communications, Manager or Politician Fields only)",150);  //SEE RULEZ!!!

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "25XP x 5 skill";
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 25;
        s4Repit7 = 5;

        swpstr = "Connections";
        s4PreTraits.append(qMakePair(swpstr,200));

    }

    if(nameElem == "Solaris VII Games") {
        s4toolTip = "Though many \"game worlds\" exist in the Inner Sphere, Solaris\nVII is by far and away the best known. Gladiators from all walks\nof life come to this world to do battle in its arenas for wealth and\nglory—but few survive Solaris VII’s seamier side, with its intrigues,\nbetrayals and Machiavellian undercurrents. Only the best can be\nchampions; the rest wallow in the mediocrity of their fake battles\nand shallow followings.\nPrerequisites:Must have taken Solaris Stable Internship, Tour\nof Duty or any module that incorporates MechWarrior, Cavalry or\nBattle Armor training.";

        s4XpCost = 900;
        s4FlexXP = 125;
        s4Age = 4;

        s4AttrMod["EDG"] = 100;
//        s4AttrMod["WIL"] = 100; //SEE RULEZ!!

        s4LabelElem6 = "Choose attribute";
        s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA";
        s4Elem6 = 100;

        S4AddTraits("Bloodmark", -25);
//        S4AddTraits("Compulsion/Gambling or any other Addiction", -25);

        s4LabelElem1 = "Choose one";
        s4TraitsElem1 << "Compulsion/Gambling" << "Compulsion/Smoking";
        s4Elem1 = 100;

        S4AddTraits("Enemy", -250);
        S4AddTraits("Reputation", 150);
//        S4AddTraits("+300 total additional XP (+100 XP each to any three of the following Traits: Custom Vehicle, Design Quirk, Equipped, Extra Income, Property, Tech Empathy or Vehicle);", 100);

        s4LabelElem5 = "+100 XP each to any three";
        s4TraitsElem5 << "Custom Vehicle" << "Design Quirk" << "Equipped" << "Extra Income" << "Property" << "Tech Empathy" << "Vehicle";
        s4Elem5 = 100;
        s4Repit5 = 3;


        S4AddSkills("Acting",25);
        S4AddSkills("Administration",10);
        S4AddSkills("Computers",10);
        S4AddSkills("Escape Artist",15);
        S4AddSkills("Interests/Solaris Games",30);
//        S4AddSkills("Interests/Any",10); //SEE RULEZ!!!

        s4LabelElem2 = "Interests/Any";
        s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem2 = 10;

        S4AddSkills("Martial Arts",20);
        S4AddSkills("Streetwise/Solaris VII",25);


//        S4AddSkills("270 total additional XP (+45 XP each to any six Skills from any Tech or Military Skill Fields the character possesses, except Officer Training)",270);

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "45XP x 6 skill";
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 45;
        s4Repit7 = 6;
    }

    if(nameElem == "Think Tank") {
        s4toolTip = "Many government, corporate and military organizations\ncommonly employ a handpicked assortment of geniuses whose\nsingular task is to identify problems, propose solutions and\nproject the strategies their employers will need to succeed. Think\ntanks may not be the most exciting or glamorous places to work,\nbut they are rewarding in many other ways.\nPrerequisites:INT 7+; At least +3TP in Connections Trait;\nCharacter must have one or more of the following Skill Fields:\nAnalysis, Doctor, Engineer or Military Scientist\nModule Cost:700XP (Periphery affiliations); 800XP (Inner\nSphere affiliations); 1000XP (Clan affiliations)";

        s4XpCost = 900;
        s4FlexXP = 190;
        s4Age = 4;

        s4AttrMod["STR"] = -75;
        s4AttrMod["BOD"] = -75;
        s4AttrMod["INT"] = 90;
        s4AttrMod["WIL"] = 75;

        S4AddTraits("Connections", 100);
        S4AddTraits("Exceptional Attribute/INT", 75);
        S4AddTraits("Rank", 75);
        S4AddTraits("Wealth", 100);
        S4AddTraits("In For Life", -100);

        S4AddSkills("Administration",50);
        S4AddSkills("Computers",50);
//        S4AddSkills("Interests/Any Academic",120); //SEE RULEZ!!!

        s4LabelElem1 = "Interests/Any Academic";
        s4SkillsElem1 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem1 = 120;

        S4AddSkills("Interests/Any",85); //SEE RULEZ!!!

        s4LabelElem2 = "Interests/Any";
        s4SkillsElem2 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem2 = 85;

        s4AffProt = 30;

//        S4AddSkills("Science/Any",30); //SEE RULEZ!!!

        s4LabelElem3 = "Science/Any";
        s4SkillsElem3 = CreateSubSkillList("Science");// << "Science/Biology" << "Science/Chemistry" << "Science/Mathematics" << "Science/Physics";
        s4Elem3 = 30;

//        S4AddSkills("Technician/Any",30); //SEE RULEZ!!!

        s4LabelElem4 = "Technician/Any";
        s4SkillsElem4 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
        s4Elem4 = 30;

        S4AddSkills("Training",50);
    }

    if(nameElem == "Tour Of Duty") {
        s4toolTip = "In the war-torn BattleTech universe, soldiers and warriors risk\ntheir lives every day on the battlefield. Whether they do so for lord\nor Clan, for country or money, their lives are often spent in long,\ndull stretches on guard—punctuated by the relentless panic that\nonly incoming fire can bring.";

        s4XpCost = 0;
        s4FlexXP = 100;
        s4Age = 3;

        S4AddTraits("Connections", 25);
//        S4AddTraits("Choose Equipped or Vehicle", 100); //SEE RULEZ!!!

        s4LabelElem1 = "Choose one";
        s4TraitsElem1 << "Equipped" << "Vehicle";
        s4Elem1 = 100;


        S4AddSkills("Career/Soldier",50);
        S4AddSkills("Martial Arts",40);
//        S4AddSkills("Navigation/Any",40); //SEE RULEZ!!!

        s4LabelElem2 = "Navigation/Any";
        s4SkillsElem2 = CreateSubSkillList("Navigation");//   << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
        s4Elem2 = 40;

        s4AffProt = 40;

        if (s4AffName.first == "Minor Periphery" || s4AffName.first == "Major Periphery State") {

            s4XpCost = 700;

            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            s4LabelElem6 = "Choose attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 50;

            S4AddTraits("Enemy", -50);
            S4AddTraits("Toughness", 50);

//            S4AddSkills("Interests/Any",20); //SEE RULEZ!!!

            s4LabelElem3 = "Interests/Any";
            s4SkillsElem3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem3 = 10;

            S4AddSkills("Leadership",15);
            S4AddSkills("MedTech",30);
            S4AddSkills("Negotiation",25);
            S4AddSkills("Perception",15);
//            S4AddSkills("+150 total additional XP (+25 XP each assigned to a maximum of six Skills the character possesses from his Military Fields)",150); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 6 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 6;
        }

        if (s4AffName.first == "Deep Periphery") {
            s4XpCost = 700;

            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            S4AddTraits("Enemy", -50);
            S4AddTraits("Toughness", 50);

//            S4AddSkills("Interests/Any",20); //SEE RULEZ!!!

            s4LabelElem3 = "Interests/Any";
            s4SkillsElem3 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem3 = 10;

            S4AddSkills("Leadership",15);
            S4AddSkills("MedTech",30);
            S4AddSkills("Negotiation",25);
            S4AddSkills("Perception",15);
//            S4AddSkills("+150 total additional XP (+25 XP each assigned to a maximum of six Skills the character possesses from his Military Fields)",150); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 6 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 6;
        }

        if (s4AffName.first == "Cappelan Confederation" || s4AffName.first == "Draconis Combine") {
            s4XpCost = 800;

//            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            s4LabelElem6 = "Choose two attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 50;
            s4Repit6 = 2;

            S4AddTraits("Rank", 50);
//            S4AddTraits("Choose Equipped or Vehicle", 50); //SEE RULEZ!!!

            s4LabelElem3 = "Choose one";
            s4TraitsElem3 << "Equipped" << "Vehicle";
            s4Elem3 = 50;

//            S4AddTraits("Choose Compulsion/Any Addiction or Unlucky", -50); //SEE RULEZ!!!

            s4LabelElem4 = "Choose one";
            s4TraitsElem4 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Unlucky";
            s4Elem4 = -50;

            s4AffLang = 15;
            S4AddSkills("Leadership",15);
            S4AddSkills("Martial Arts",10);
            S4AddSkills("MedTech",20);
            S4AddSkills("Perception",20);
//            S4AddSkills("+175 total additional XP (+25 XP each assigned to a maximum of seven Skills the character possesses from his Military Fields)",20); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 7 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 7;
        }

        if (s4AffName.first == "Federated Suns" || s4AffName.first == "Free Worlds League") {
            s4XpCost = 800;

            //            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            s4LabelElem6 = "Choose two attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 50;
            s4Repit6 = 2;

            S4AddTraits("Rank", 50);
//            S4AddTraits("Choose Equipped or Vehicle", 50); //SEE RULEZ!!!

            s4LabelElem3 = "Choose one";
            s4TraitsElem3 << "Equipped" << "Vehicle";
            s4Elem3 = 50;

            //            S4AddTraits("Choose Compulsion/Any Addiction or Unlucky", -50); //SEE RULEZ!!!

            s4LabelElem4 = "Choose one";
            s4TraitsElem4 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Unlucky";
            s4Elem4 = -50;

            s4AffLang = 15;
            S4AddSkills("Leadership",15);
            S4AddSkills("Martial Arts",10);
            S4AddSkills("MedTech",20);
            S4AddSkills("Perception",20);
//            S4AddSkills("+175 total additional XP (+25 XP each assigned to a maximum of seven Skills the character possesses from his Military Fields)",20); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 7 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 7;
        }

        if (s4AffName.first == "Lyran Alliance" || s4AffName.first == "Free Rasalhague Republic") {
            s4XpCost = 800;

            //            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            s4LabelElem6 = "Choose two attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 50;
            s4Repit6 = 2;

            S4AddTraits("Rank", 50);
//            S4AddTraits("Choose Equipped or Vehicle", 50); //SEE RULEZ!!!

            s4LabelElem3 = "Choose one";
            s4TraitsElem3 << "Equipped" << "Vehicle";
            s4Elem3 = 50;

            //            S4AddTraits("Choose Compulsion/Any Addiction or Unlucky", -50); //SEE RULEZ!!!

            s4LabelElem4 = "Choose one";
            s4TraitsElem4 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Unlucky";
            s4Elem4 = -50;

            s4AffLang = 15;
            S4AddSkills("Leadership",15);
            S4AddSkills("Martial Arts",10);
            S4AddSkills("MedTech",20);
            S4AddSkills("Perception",20);
//            S4AddSkills("+175 total additional XP (+25 XP each assigned to a maximum of seven Skills the character possesses from his Military Fields)",20); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 7 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 7;
        }

        if (s4AffName.first == "Terran" || s4AffName.first == "Independent") {
            s4XpCost = 800;
            //            s4AttrMod["INT"] = 50; //SEE RULEZ!!!

            s4LabelElem6 = "Choose two attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 50;
            s4Repit6 = 2;

            S4AddTraits("Rank", 50);
//            S4AddTraits("Choose Equipped or Vehicle", 50); //SEE RULEZ!!!

            s4LabelElem3 = "Choose one";
            s4TraitsElem3 << "Equipped" << "Vehicle";
            s4Elem3 = 50;

            //            S4AddTraits("Choose Compulsion/Any Addiction or Unlucky", -50); //SEE RULEZ!!!

            s4LabelElem4 = "Choose one";
            s4TraitsElem4 << "Compulsion/Berserker" << "Compulsion/Catatonia" << "Compulsion/Confusion" << "Compulsion/Flashbacks" << "Compulsion/Hysteria" << "Compulsion/Paranoia" << "Compulsion/Regression" << "Compulsion/Split Personality" << "Unlucky";
            s4Elem4 = -50;

            s4AffLang = 15;
            S4AddSkills("Leadership",15);
            S4AddSkills("Martial Arts",10);
            S4AddSkills("MedTech",20);
            S4AddSkills("Perception",20);
//            S4AddSkills("+175 total additional XP (+25 XP each assigned to a maximum of seven Skills the character possesses from his Military Fields)",20); //SEE RULEZ!!!

            if (s4BasicSchool.first.isEmpty() != true) {
                s4LabelElem7 = "25XP x 7 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 7;
        }

        if(s4AffName.first == "Invading Clan" || s4AffName.first == "Homeworld Clan") {
            s4XpCost = 1000;

//            s4AttrMod["INT"] = 75; //SEE RULEZ!!!

            s4LabelElem6 = "Choose two attribute";
            s4AttrElem6 << "STR" << "BOD" << "RFL" << "DEX"  << "INT" << "WIL" << "CHA" << "EDG";
            s4Elem6 = 75;
            s4Repit6 = 2;

            S4AddTraits("Bloodname", 50);
            S4AddTraits("Combat Sense", 75);
            S4AddTraits("Enemy", -75);
//            S4AddTraits("Choose Equipped or Vehicle", 75); //SEE RULEZ!!!

            s4LabelElem3 = "Choose one";
            s4TraitsElem3 << "Equipped" << "Vehicle";
            s4Elem3 = 100;

//            S4AddSkills("Communications/Any",15); //SEE RULEZ!!!

            s4LabelElem4 = "Communications/Any";
            s4SkillsElem4 = CreateSubSkillList("Communications");// << "Communications/Black Box" << "Communications/Conventional (EM)" << "Communications/Hyperpulse Generator";
            s4Elem4 = 15;

            S4AddSkills("Computers",15);
//            S4AddSkills("Interests/Any",20);  //SEE RULEZ!!!

            s4LabelElem5 = "Interests/Any";
            s4SkillsElem5 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
            s4Elem5 = 20;

            S4AddSkills("Perception",20);
//            S4AddSkills("Technician/Any",10);  //SEE RULEZ!!!

            s4LabelElem8 = "Technician/Any";
            s4SkillsElem8 = CreateSubSkillList("Technician");// << "Technician/Aeronautics" << "Technician/Cybernetics" << "Technician/Electronic" << "Technician/Jets" << "Technician/Mechanical" << "Technician/Myomer" << "Technician/Nuclear" << "Technician/Weapons";
            s4Elem8 = 10;

//            S4AddSkills("+250 total additional XP (+25 XP each assigned to a maximum of ten Skills the character possesses from his Military Fields)",250);

            if (s4BasicSchool.first.isEmpty() != true || clanFieldSkills.isEmpty() != true) {
                s4LabelElem7 = "25XP x 10 skill";
            }
            s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
            if(clanFieldSkills.isEmpty() != true) {
                for(int i=0; i < clanFieldSkills.count(); i++) {
                    s4SkillsElem7.append(clanFieldSkills[i].first);
                }
            }
            s4SkillsElem7.removeDuplicates();
            s4SkillsElem7.sort();
            s4Elem7 = 25;
            s4Repit7 = 10;
        }


    }

    if(nameElem == "To Serve And Protect") {
        s4toolTip = "Police or security  officers are a common sight on any\ncivilized world. Even when given uncommon titles—such\nas the \"Strategic Locals\" of the Lyran Alliance's federal police,\nor their “Friendly Persuader” counterparts in the Draconis\nCombine—those who wear the policeman's badge command\nthe respect of the civilian population they are sworn to serve\nand protect.\nPrerequisites: Police, Police Tactical or Detective Field\nrequired ";

        s4XpCost = 900;
        s4FlexXP = 50;
        s4Age = 4;

        s4AttrMod["BOD"] = 100;
        s4AttrMod["RFL"] = 100;
        s4AttrMod["WIL"] = 100;

        S4AddTraits("Connections", 50);
        S4AddTraits("Enemy", -75);
        S4AddTraits("Choose one of the following Trait pairs: Attractive (+50 XP) and Handicap (â€“50 XP) or Fit (+50 XP) and Dependent (â€“50 XP)", 100); //SEE RULEZ!!!

        s4LabelElem2 = "Choose one";
        s4TraitsElem2 << "Attractive(+50XP)&Handicap(-50XP)" << "Fit(+50XP) and Dependent(-50XP)";
        s4Elem2 = 50;

        S4AddSkills("Administration",25);
        S4AddSkills("Computers",35);
        S4AddSkills("Cryptography",15);
        S4AddSkills("Interrogation",25);
        S4AddSkills("Investigation",25);
        S4AddSkills("Leadership",25);
        S4AddSkills("MedTech",30);
        S4AddSkills("Melee Weapons",45);
//        S4AddSkills("Navigation/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Navigation/Any";
        s4SkillsElem1 = CreateSubSkillList("Navigation");// << "Navigation/Ground" << "Navigation/Air" << "Navigation/Sea" << "Navigation/Space" << "Navigation/K-F Jump";
        s4Elem1 = 35;

        S4AddSkills("Perception",45);

        s4AffProt = 25;

        S4AddSkills("Small Arms",50);

        s4AffStreet = 45;

        S4AddSkills("Support Weapons",15);
        S4AddSkills("Tactics/Infantry",25);
        S4AddSkills("Training",10);
//        S4AddSkills("+100 total additional XP (+25 each in four of the characterâ€™s relevant Police Officer, Police Tactical Officer or Detective Fields)",10);  //SEE RULEZ!!!

        if (s4BasicSchool.first.isEmpty() != true) {
            s4LabelElem7 = "25XP x 4 skill";
        }
        s4SkillsElem7 << S4FieldSkills(s4BasicSchool.first) << S4FieldSkills(s4AdvSchool.first) << S4FieldSkills(s4SpecSchool.first);
        s4SkillsElem7.removeDuplicates();
        s4SkillsElem7.sort();
        s4Elem7 = 25;
        s4Repit7 = 4;
    }


    if(nameElem == "Travel") {
        s4toolTip = "Sometimes, a person just needs to get away from it all. While\nnot generally an option for most denizens of the Inner Sphere,\nmany intrepid souls nevertheless manage to leave their\nhomeworlds behind and venture among the stars for little\nmore reason than to soothe their own wanderlust. Though it\ncan take years and hoards of cash, interstellar travel can be its\nown adventure.\nPrerequisites:Cannot have TDS Trait; must have at least +2\nTP or more in the Extra Income or Wealth Traits";

        s4XpCost = 900;
        s4FlexXP = 110;
        s4Age = 6;

        s4AttrMod["INT"] = 45;
        s4AttrMod["EDG"] = 45;

//        S4AddSkills("Art/Any",35); //SEE RULEZ!!!

        s4LabelElem1 = "Art/Any";
        s4SkillsElem1 = CreateSubSkillList("Art");// << "Art/Oral Tradition" << "Art/Dance" << "Art/Drawing" << "Art/Painting" << "Art/Poetry" << "Art/Sculpture" << "Art/Songwriting" << "Art/Writing";
        s4Elem1 = 35;

        S4AddSkills("Art/Cooking",30);
        S4AddSkills("Climbing",35);
//        S4AddSkills("Driving/Any",50); //SEE RULEZ!!!

        s4LabelElem2 = "Driving/Any";
        s4SkillsElem2 = CreateSubSkillList("Driving");// << "Driving/Ground Vehicles" << "Driving/Rail Vehicles" << "Driving/Sea Vehicles";
        s4Elem2 = 50;

//        S4AddSkills("Interests/Any",75); //SEE RULEZ!!!

        s4LabelElem3 = "Interests/Any";
        s4SkillsElem3 = CreateSubSkillList("Interests");//  << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem3 = 75;

//        S4AddSkills("Interests/Any",45); //SEE RULEZ!!!

        s4LabelElem4 = "Interests/Any";
        s4SkillsElem4 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem4 = 45;

//        S4AddSkills("Interests/Any",20); //SEE RULEZ!!!

        s4LabelElem5 = "Interests/Any";
        s4SkillsElem5 = CreateSubSkillList("Interests");// << "Interests/Star League History" << "Interests/Combine History" << "Interests/FedSuns History" << "Interests/Regulan History" << "Interests/Remembrance" << "Interests/Marian History" << "Interests/Roman History" << "Interests/Nova Cat Vision Quest" << "Interests/Clan History" << "Interests/Theology" << "Interests/Coyote Rituals" << "Interests/Star League History" << "Interests/Clan Remembrance" << "Interests/Terran History" << "Interests/History" << "Interests/Literature" << "Interests/Holo-Games" << "Interests/Sports Statistics" << "Interests/Writings of Jerome Blake" << "Interests/BattleMechs";
        s4Elem5 = 20;

        s4AffLang = 35;

//        S4AddSkills("Language/Any",35); //SEE RULEZ!!!

        s4LabelElem6 = "Language/Any";
        s4SkillsElem6 = CreateSubSkillList("Language");//  << "Language/English" << "Language/Mandarin Chinese" << "Language/Russian" << "Language/Cantonese" << "Language/Vietnamese" << "Language/Japanese" << "Language/Arabic" << "Language/Swedenese" << "Language/French" << "Language/German" << "Language/Hindi" << "Language/Greek" << "Language/Italian" << "Language/Mongolian" << "Language/Romanian" << "Language/Slovak" << "Language/Spanish" << "Language/Urdu" << "Language/Scots Gaelic" << "Language/Swedish";
        s4Elem6 = 35;

//        S4AddSkills("Survival/Any",25); //SEE RULEZ!!!

        s4LabelElem7 = "Survival/Any";
        s4SkillsElem7 = CreateSubSkillList("Survival");//  << "Survival/Desert" << "Survival/Forests" << "Survival/Jungle" << "Survival/Arctic" << "Survival/Steppe" << "Survival/City" << "Survival/Martian Desert";
        s4Elem7 = 35;

        S4AddSkills("Swimming",50);
        S4AddSkills("Zero-G Operations",50);

        swpstr = "Wealth";
        s4PreTraits.append(qMakePair(swpstr,200));

        swpstr = "Extra Income";
        s4PreTraits.append(qMakePair(swpstr,200));
    }

}


QStringList Stage4::S4FieldSkills(QString fieldName) {
    QStringList listField;
    QMultiMap<QString, QString>::iterator i =carField->masterFieldList.find(fieldName);
    while (i != carField->masterFieldList.end() && i.key() == fieldName) {
        if (i.value().contains("Any") == true) {
            listField << carField->FieldDialSearch(i.value());
        } else {
            listField << i.value();
        }
        ++i;
    }
    return listField;
}
