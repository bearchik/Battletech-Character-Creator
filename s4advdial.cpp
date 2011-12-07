#include "s4advdial.h"
#include "ui_s4advdial.h"

#include <QtGui>

S4AdvDial::S4AdvDial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::S4AdvDial)
{
    ui->setupUi(this);

    s4AdvDialAttr.clear();
    s4AdvDialSkills.clear();
    s4AdvDialTraits.clear();

    s4AdvDialLabelElem1.clear();
    s4AdvDialSkillsElem1.clear();
    s4AdvDialTraitsElem1.clear();
    s4AdvDialElem1 = 0;
    s4AdvDialElemSwp1.clear();

    s4AdvDialLabelElem2.clear();
    s4AdvDialSkillsElem2.clear();
    s4AdvDialTraitsElem2.clear();
    s4AdvDialElem2 = 0;
    s4AdvDialElemSwp2.clear();

    s4AdvDialLabelElem3.clear();
    s4AdvDialSkillsElem3.clear();
    s4AdvDialTraitsElem3.clear();
    s4AdvDialElem3 = 0;
    s4AdvDialElemSwp3.clear();

    s4AdvDialLabelElem4.clear();
    s4AdvDialSkillsElem4.clear();
    s4AdvDialTraitsElem4.clear();
    s4AdvDialElem4 = 0;
    s4AdvDialElemSwp4.clear();

    s4AdvDialLabelElem5.clear();
    s4AdvDialSkillsElem5.clear();
    s4AdvDialTraitsElem5.clear();
    s4AdvDialElem5 = 0;
    s4AdvDialElemSwp5.clear();

    s4AdvDialLabelElem6.clear();
    s4AdvDialSkillsElem6.clear();
    s4AdvDialTraitsElem6.clear();
    s4AdvDialAttrElem6.clear();
    s4AdvDialElem6 = 0;
    s4AdvDialElemSwp6.clear();

    s4AdvDialLabelElem7.clear();
    s4AdvDialSkillsElem7.clear();
    s4AdvDialTraitsElem7.clear();
    s4AdvDialElem7 = 0;
    s4AdvDialElemSwp7.clear();

    s4AdvDialLabelElem8.clear();
    s4AdvDialSkillsElem8.clear();
    s4AdvDialTraitsElem8.clear();
    s4AdvDialElem8 = 0;
    s4AdvDialElemSwp8.clear();

    S4AdvDialConnecteEvent();


}

S4AdvDial::~S4AdvDial()
{
    delete ui;
}

void S4AdvDial::S4AdvDialClearAll() {

    S4AdvDialClearZero();

    s4AdvDialAttr.clear();
    s4AdvDialSkills.clear();
    s4AdvDialTraits.clear();

    s4AdvDialLabelElem1.clear();
    s4AdvDialSkillsElem1.clear();
    s4AdvDialTraitsElem1.clear();
    s4AdvDialElem1 = 0;
    s4AdvDialElemSwp1.clear();

    s4AdvDialLabelElem2.clear();
    s4AdvDialSkillsElem2.clear();
    s4AdvDialTraitsElem2.clear();
    s4AdvDialElem2 = 0;
    s4AdvDialElemSwp2.clear();

    s4AdvDialLabelElem3.clear();
    s4AdvDialSkillsElem3.clear();
    s4AdvDialTraitsElem3.clear();
    s4AdvDialElem3 = 0;
    s4AdvDialElemSwp3.clear();

    s4AdvDialLabelElem4.clear();
    s4AdvDialSkillsElem4.clear();
    s4AdvDialTraitsElem4.clear();
    s4AdvDialElem4 = 0;
    s4AdvDialElemSwp4.clear();

    s4AdvDialLabelElem5.clear();
    s4AdvDialSkillsElem5.clear();
    s4AdvDialTraitsElem5.clear();
    s4AdvDialElem5 = 0;
    s4AdvDialElemSwp5.clear();

    s4AdvDialLabelElem6.clear();
    s4AdvDialSkillsElem6.clear();
    s4AdvDialTraitsElem6.clear();
    s4AdvDialAttrElem6.clear();
    s4AdvDialElem6 = 0;
    s4AdvDialElemSwp6.clear();

    s4AdvDialLabelElem7.clear();
    s4AdvDialSkillsElem7.clear();
    s4AdvDialTraitsElem7.clear();
    s4AdvDialElem7 = 0;
    s4AdvDialElemSwp7.clear();

    s4AdvDialLabelElem8.clear();
    s4AdvDialSkillsElem8.clear();
    s4AdvDialTraitsElem8.clear();
    s4AdvDialElem8 = 0;
    s4AdvDialElemSwp8.clear();

    ui->S4AdvDialComBox1->clear();
    ui->S4AdvDialLabel1->clear();

    ui->S4AdvDialComBox2->clear();
    ui->S4AdvDialLabel2->clear();

    ui->S4AdvDialComBox3->clear();
    ui->S4AdvDialLabel3->clear();

    ui->S4AdvDialComBox4->clear();
    ui->S4AdvDialLabel4->clear();

    ui->S4AdvDialComBox5->clear();
    ui->S4AdvDialLabel5->clear();

    ui->S4AdvDialComBox6->clear();
    ui->S4AdvDialLabel6->clear();

    ui->S4AdvDialComBox7->clear();
    ui->S4AdvDialLabel7->clear();

    ui->S4AdvDialComBox8->clear();
    ui->S4AdvDialLabel8->clear();

    ui->S4AdvDialTable->clear();

}

void S4AdvDial::S4AdvDialClearZero() {
    QList<QPair<QString, int> > swapSkill = s4AdvDialSkills;
    s4AdvDialSkills.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s4AdvDialSkills.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s4AdvDialTraits;
    s4AdvDialTraits.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s4AdvDialTraits.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }

    swapSkill = s4AdvDialAttr;
    s4AdvDialAttr.clear();
    for (int i = 0; i < swapSkill.count(); i++) {
        if (swapSkill[i].second != 0) {
            s4AdvDialAttr.append(qMakePair(swapSkill[i].first, swapSkill[i].second));
        }
    }
}

void S4AdvDial::changeSkills(QString skillName, int skillXP)
{
    if (s4AdvDialSkills.count() == 0) {
        s4AdvDialSkills.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s4AdvDialSkills);
        if ( i != 100500 ) {
            i--;
            s4AdvDialSkills[i] = qMakePair(skillName, s4AdvDialSkills[i].second + skillXP );
        } else {
            s4AdvDialSkills.append(qMakePair(skillName, skillXP));
        }
    }
}

void S4AdvDial::changeTraits(QString skillName, int skillXP)
{
    if (s4AdvDialTraits.count() == 0) {
        s4AdvDialTraits.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s4AdvDialTraits);
        if ( i != 100500 ) {
            i--;
            s4AdvDialTraits[i] = qMakePair(skillName, s4AdvDialTraits[i].second + skillXP );
        } else {
            s4AdvDialTraits.append(qMakePair(skillName, skillXP));
        }
    }
}

void S4AdvDial::changeAttr(QString skillName, int skillXP)
{
    if (s4AdvDialAttr.count() == 0) {
        s4AdvDialAttr.append(qMakePair(skillName, skillXP));
    } else {
        int i = findSkill(skillName, s4AdvDialAttr);
        if ( i != 100500 ) {
            i--;
            s4AdvDialAttr[i] = qMakePair(skillName, s4AdvDialAttr[i].second + skillXP );
        } else {
            s4AdvDialAttr.append(qMakePair(skillName, skillXP));
        }
    }
}

int S4AdvDial::findSkill(QString fSkillName, QList<QPair<QString, int> > nameList) {
    int b=0;
    for (int i = 0; i < nameList.count(); i++) {
        b++;
        if (nameList[i].first == fSkillName ) {
            return b;
        }
    }
    return 100500; //magic number
}

void S4AdvDial::S4AdvDialConnecteEvent() {
    connect(ui->S4AdvDialComBox1, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem1(QString)));
    connect(ui->S4AdvDialComBox2, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem2(QString)));
    connect(ui->S4AdvDialComBox3, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem3(QString)));
    connect(ui->S4AdvDialComBox4, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem4(QString)));
    connect(ui->S4AdvDialComBox5, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem5(QString)));
    connect(ui->S4AdvDialComBox6, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem6(QString)));
    connect(ui->S4AdvDialComBox7, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem7(QString)));
    connect(ui->S4AdvDialComBox8, SIGNAL(activated(QString)), this, SLOT(S4AdvDialComBoxElem8(QString)));

    connect(ui->S4AdvDialAddElem5, SIGNAL(clicked()), this, SLOT(S4AdvDialAdd5()));
    connect(ui->S4AdvDialAddElem6, SIGNAL(clicked()), this, SLOT(S4AdvDialAdd6()));
    connect(ui->S4AdvDialAddElem7, SIGNAL(clicked()), this, SLOT(S4AdvDialAdd7()));
}

void S4AdvDial::S4AdvDialInit() {

    if(s4AdvDialLabelElem1.isEmpty() != true) {
        ui->S4AdvDialComBox1->setDisabled(false);
        ui->S4AdvDialLabel1->setText(s4AdvDialLabelElem1);
        if(s4AdvDialSkillsElem1.isEmpty() != true) {
            ui->S4AdvDialComBox1->addItems(s4AdvDialSkillsElem1);
        } else {
            ui->S4AdvDialComBox1->addItems(s4AdvDialTraitsElem1);
        }
    } else {
        ui->S4AdvDialComBox1->setDisabled(true);
    }

    if(s4AdvDialLabelElem2.isEmpty() != true) {
        ui->S4AdvDialComBox2->setDisabled(false);
        ui->S4AdvDialLabel2->setText(s4AdvDialLabelElem2);
        if(s4AdvDialSkillsElem2.isEmpty() != true) {
            ui->S4AdvDialComBox2->addItems(s4AdvDialSkillsElem2);
        } else {
            ui->S4AdvDialComBox2->addItems(s4AdvDialTraitsElem2);
        }
    } else {
        ui->S4AdvDialComBox2->setDisabled(true);
    }

    if(s4AdvDialLabelElem3.isEmpty() != true) {
        ui->S4AdvDialComBox3->setDisabled(false);
        ui->S4AdvDialLabel3->setText(s4AdvDialLabelElem3);
        if(s4AdvDialSkillsElem3.isEmpty() != true) {
            ui->S4AdvDialComBox3->addItems(s4AdvDialSkillsElem3);
        } else {
            ui->S4AdvDialComBox3->addItems(s4AdvDialTraitsElem3);
        }
    } else {
        ui->S4AdvDialComBox3->setDisabled(true);
    }

    if(s4AdvDialLabelElem4.isEmpty() != true) {
        ui->S4AdvDialComBox4->setDisabled(false);
        ui->S4AdvDialLabel4->setText(s4AdvDialLabelElem4);
        if(s4AdvDialSkillsElem4.isEmpty() != true) {
            ui->S4AdvDialComBox4->addItems(s4AdvDialSkillsElem4);
        } else {
            ui->S4AdvDialComBox4->addItems(s4AdvDialTraitsElem4);
        }
    } else {
        ui->S4AdvDialComBox4->setDisabled(true);
    }

    if(s4AdvDialLabelElem5.isEmpty() != true) {
        ui->S4AdvDialComBox5->setDisabled(false);
        if(s4AdvDialRepit5 !=0) {
            ui->S4AdvDialAddElem5->setDisabled(false);
        } else {
           ui->S4AdvDialAddElem5->setDisabled(true);
        }
        ui->S4AdvDialLabel5->setText(s4AdvDialLabelElem5);
        if(s4AdvDialSkillsElem5.isEmpty() != true) {
            ui->S4AdvDialComBox5->addItems(s4AdvDialSkillsElem5);
        } else {
            ui->S4AdvDialComBox5->addItems(s4AdvDialTraitsElem5);
        }
    } else {
        ui->S4AdvDialComBox5->setDisabled(true);
        ui->S4AdvDialAddElem5->setDisabled(true);
    }

    if(s4AdvDialLabelElem6.isEmpty() != true) {
        ui->S4AdvDialComBox6->setDisabled(false);
        if(s4AdvDialRepit6 !=0) {
            ui->S4AdvDialAddElem6->setDisabled(false);
        } else {
           ui->S4AdvDialAddElem6->setDisabled(true);
        }
        ui->S4AdvDialLabel6->setText(s4AdvDialLabelElem6);
        if(s4AdvDialSkillsElem6.isEmpty() != true) {
            ui->S4AdvDialComBox6->addItems(s4AdvDialSkillsElem6);
        }
        if(s4AdvDialTraitsElem6.isEmpty() != true) {
            ui->S4AdvDialComBox6->addItems(s4AdvDialTraitsElem6);
        }

        if(s4AdvDialAttrElem6.isEmpty() != true) {
            ui->S4AdvDialComBox6->addItems(s4AdvDialAttrElem6);
        }

    } else {
        ui->S4AdvDialComBox6->setDisabled(true);
        ui->S4AdvDialAddElem6->setDisabled(true);
    }

    if(s4AdvDialLabelElem7.isEmpty() != true) {
        ui->S4AdvDialComBox7->setDisabled(false);
        if(s4AdvDialRepit7 !=0) {
            ui->S4AdvDialAddElem7->setDisabled(false);
        } else {
           ui->S4AdvDialAddElem7->setDisabled(true);
        }
        ui->S4AdvDialLabel7->setText(s4AdvDialLabelElem7);
        if(s4AdvDialSkillsElem7.isEmpty() != true) {
            ui->S4AdvDialComBox7->addItems(s4AdvDialSkillsElem7);
        } else {
            ui->S4AdvDialComBox7->addItems(s4AdvDialTraitsElem7);
        }
    } else {
        ui->S4AdvDialComBox7->setDisabled(true);
        ui->S4AdvDialAddElem7->setDisabled(true);
    }

    if(s4AdvDialLabelElem8.isEmpty() != true) {
        ui->S4AdvDialComBox8->setDisabled(false);
        ui->S4AdvDialLabel8->setText(s4AdvDialLabelElem8);
        if(s4AdvDialSkillsElem8.isEmpty() != true) {
            ui->S4AdvDialComBox8->addItems(s4AdvDialSkillsElem8);
        } else {
            ui->S4AdvDialComBox8->addItems(s4AdvDialTraitsElem8);
        }
    } else {
        ui->S4AdvDialComBox8->setDisabled(true);
    }

    S4AdvDialComBoxElem1(ui->S4AdvDialComBox1->currentText());
    S4AdvDialComBoxElem2(ui->S4AdvDialComBox2->currentText());
    S4AdvDialComBoxElem3(ui->S4AdvDialComBox3->currentText());
    S4AdvDialComBoxElem4(ui->S4AdvDialComBox4->currentText());
    S4AdvDialComBoxElem5(ui->S4AdvDialComBox5->currentText());
    S4AdvDialComBoxElem6(ui->S4AdvDialComBox6->currentText());
    S4AdvDialComBoxElem7(ui->S4AdvDialComBox7->currentText());
    S4AdvDialComBoxElem8(ui->S4AdvDialComBox8->currentText());

}

void S4AdvDial::S4AdvDialComBoxElem1(QString nameElem) {

    if (s4AdvDialNameRLife == "Scientist Caste Service") {
        if (nameElem == "Fast Learner(+75 XP)&Combat Paralysis(-75 XP)") {
            changeTraits("Fast Learner",75);
            changeTraits("Combat Paralysis", -75);
        }

        if (nameElem == "Natural Aptitude/Any Interest(+75 XP)") {
            changeTraits("Natural Aptitude/Any Interest",75);
        }

        if (nameElem == "Science Skill(+75 XP)&Dark Secret(-75 XP)") {
            changeTraits("Dark Secret",-75);
            changeSkills("Science",75);
        }

        if (s4AdvDialElemSwp1.isEmpty() != true) {
            if (s4AdvDialElemSwp1 == "Fast Learner(+75 XP)&Combat Paralysis(-75 XP)") {
                changeTraits("Fast Learner",-75);
                changeTraits("Combat Paralysis", 75);
            }

            if (s4AdvDialElemSwp1 == "Natural Aptitude/Any Interest(+75 XP)") {
                changeTraits("Natural Aptitude/Any Interest",-75);
            }

            if (s4AdvDialElemSwp1 == "Science Skill(+75 XP)&Dark Secret(-75 XP)") {
                changeTraits("Dark Secret",75);
                changeSkills("Science",-75);
            }
        }
        s4AdvDialElemSwp1 = nameElem;

    } else {

        if (s4AdvDialSkillsElem1.isEmpty() != true) {
            if (s4AdvDialElemSwp1.isEmpty() != true) {
                changeSkills(s4AdvDialElemSwp1,-s4AdvDialElem1);
            }
            changeSkills(nameElem,s4AdvDialElem1);
            s4AdvDialElemSwp1 = nameElem;
        }

        if (s4AdvDialTraitsElem1.isEmpty() != true) {
            if (s4AdvDialElemSwp1.isEmpty() != true) {
                changeTraits(s4AdvDialElemSwp1,-s4AdvDialElem1);
            }
            changeTraits(nameElem,s4AdvDialElem1);
            s4AdvDialElemSwp1 = nameElem;
        }
    }
    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem2(QString nameElem) {

    if (s4AdvDialNameRLife == "To Serve And Protect") {
        if (nameElem == "Attractive(+50XP)&Handicap(-50XP)") {
            changeTraits("Attractive",50);
            changeTraits("Handicap", -50);
        }

        if (nameElem == "Fit(+50XP) and Dependent(-50XP)") {
            changeTraits("Fit",50);
            changeTraits("Dependent", -50);
        }


        if (s4AdvDialElemSwp2.isEmpty() != true) {
            if (s4AdvDialElemSwp2 == "Attractive(+50XP)&Handicap(-50XP)") {
                changeTraits("Attractive", -50);
                changeTraits("Handicap", 50);
            }

            if (s4AdvDialElemSwp2 == "Fit(+50XP) and Dependent(-50XP)") {
                changeTraits("Fit", -50);
                changeTraits("Dependent", 50);
            }
        }

        s4AdvDialElemSwp2 = nameElem;

    } else {
        if (s4AdvDialSkillsElem2.isEmpty() != true) {
            if (s4AdvDialElemSwp2.isEmpty() != true) {
                changeSkills(s4AdvDialElemSwp2,-s4AdvDialElem2);
            }
            changeSkills(nameElem,s4AdvDialElem2);
            s4AdvDialElemSwp2 = nameElem;
        }


        if (s4AdvDialTraitsElem2.isEmpty() != true) {
            if (s4AdvDialElemSwp2.isEmpty() != true) {
                changeTraits(s4AdvDialElemSwp2,-s4AdvDialElem2);
            }
            changeTraits(nameElem,s4AdvDialElem2);
            s4AdvDialElemSwp2 = nameElem;
        }

    }
    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem3(QString nameElem) {
    if (s4AdvDialSkillsElem3.isEmpty() != true) {
        if (s4AdvDialElemSwp3.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp3,-s4AdvDialElem3);
        }
        changeSkills(nameElem,s4AdvDialElem3);
        s4AdvDialElemSwp3 = nameElem;
    }

    if (s4AdvDialTraitsElem3.isEmpty() != true) {
        if (s4AdvDialElemSwp3.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp3,-s4AdvDialElem3);
        }
        changeTraits(nameElem,s4AdvDialElem3);
        s4AdvDialElemSwp3 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem4(QString nameElem) {
    if (s4AdvDialSkillsElem4.isEmpty() != true) {
        if (s4AdvDialElemSwp4.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp4,-s4AdvDialElem4);
        }
        changeSkills(nameElem,s4AdvDialElem4);
        s4AdvDialElemSwp4 = nameElem;
    }

    if (s4AdvDialTraitsElem4.isEmpty() != true) {
        if (s4AdvDialElemSwp4.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp4,-s4AdvDialElem4);
        }
        changeTraits(nameElem,s4AdvDialElem4);
        s4AdvDialElemSwp4 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem5(QString nameElem) {
    if (s4AdvDialSkillsElem5.isEmpty() != true) {
        if (s4AdvDialElemSwp5.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp5,-s4AdvDialElem5);
        }
        changeSkills(nameElem,s4AdvDialElem5);
        s4AdvDialElemSwp5 = nameElem;
    }

    if (s4AdvDialTraitsElem5.isEmpty() != true) {
        if (s4AdvDialElemSwp5.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp5,-s4AdvDialElem5);
        }
        changeTraits(nameElem,s4AdvDialElem5);
        s4AdvDialElemSwp5 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem6(QString nameElem) {
    if (s4AdvDialSkillsElem6.isEmpty() != true) {
        if (s4AdvDialElemSwp6.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp6,-s4AdvDialElem6);
        }
        changeSkills(nameElem,s4AdvDialElem6);
        s4AdvDialElemSwp6 = nameElem;
    }

    if (s4AdvDialTraitsElem6.isEmpty() != true) {
        if (s4AdvDialElemSwp6.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp6,-s4AdvDialElem6);
        }
        changeTraits(nameElem,s4AdvDialElem6);
        s4AdvDialElemSwp6 = nameElem;
    }

    if (s4AdvDialAttrElem6.isEmpty() != true) {
        if (s4AdvDialElemSwp6.isEmpty() != true) {
            changeAttr(s4AdvDialElemSwp6,-s4AdvDialElem6);
        }
        changeAttr(nameElem,s4AdvDialElem6);
        s4AdvDialElemSwp6 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem7(QString nameElem) {
    if (s4AdvDialSkillsElem7.isEmpty() != true) {
        if (s4AdvDialElemSwp7.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp7,-s4AdvDialElem7);
        }
        changeSkills(nameElem,s4AdvDialElem7);
        s4AdvDialElemSwp7 = nameElem;
    }

    if (s4AdvDialTraitsElem7.isEmpty() != true) {
        if (s4AdvDialElemSwp7.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp7,-s4AdvDialElem7);
        }
        changeTraits(nameElem,s4AdvDialElem7);
        s4AdvDialElemSwp7 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialComBoxElem8(QString nameElem) {
    if (s4AdvDialSkillsElem8.isEmpty() != true) {
        if (s4AdvDialElemSwp8.isEmpty() != true) {
            changeSkills(s4AdvDialElemSwp8,-s4AdvDialElem8);
        }
        changeSkills(nameElem,s4AdvDialElem8);
        s4AdvDialElemSwp8 = nameElem;
    }

    if (s4AdvDialTraitsElem8.isEmpty() != true) {
        if (s4AdvDialElemSwp8.isEmpty() != true) {
            changeTraits(s4AdvDialElemSwp8,-s4AdvDialElem8);
        }
        changeTraits(nameElem,s4AdvDialElem8);
        s4AdvDialElemSwp8 = nameElem;
    }

    S4AdvDialPrintTable();
}

void S4AdvDial::S4AdvDialAdd5() {
    s4AdvDialRepit5--;

    if (s4AdvDialRepit5 == 0) {
        ui->S4AdvDialAddElem5->setDisabled(true);
    } else {
        s4AdvDialElemSwp5.clear();
    }

    S4AdvDialComBoxElem5(ui->S4AdvDialComBox5->currentText());
}

void S4AdvDial::S4AdvDialAdd6() {
    s4AdvDialRepit6--;

    if (s4AdvDialRepit6 == 0) {
        ui->S4AdvDialAddElem6->setDisabled(true);
    } else {
        s4AdvDialElemSwp6.clear();
    }
    S4AdvDialComBoxElem6(ui->S4AdvDialComBox6->currentText());
}

void S4AdvDial::S4AdvDialAdd7() {
    s4AdvDialRepit7--;

    QString textLabel;
    textLabel = QString::number(s4AdvDialElem7) + "XP x " + QString::number(s4AdvDialRepit7) + " skill";
    ui->S4AdvDialLabel7->setText(textLabel);

    if (s4AdvDialRepit7 == 0) {
        ui->S4AdvDialAddElem7->setDisabled(true);
    } else {
        s4AdvDialElemSwp7.clear();
    }
    S4AdvDialComBoxElem7(ui->S4AdvDialComBox7->currentText());
}

void S4AdvDial::S4AdvDialPrintTable() {
    S4AdvDialClearZero();
    ui->S4AdvDialTable->clear();

    QList<QPair<QString, int> > printList;

    printList = s4AdvDialAttr + s4AdvDialSkills + s4AdvDialTraits;

    for(int sCount = 0 ; sCount < printList.count() ; sCount++) {
        QTableWidgetItem *newSNameItem = new QTableWidgetItem(printList[sCount].first);
        ui->S4AdvDialTable->setItem(sCount,0,newSNameItem);
        QTableWidgetItem *newSValueItem = new QTableWidgetItem(QString::number(printList[sCount].second));
        ui->S4AdvDialTable->setItem(sCount,1,newSValueItem);
    }
}

