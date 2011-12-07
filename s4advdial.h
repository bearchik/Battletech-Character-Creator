#ifndef S4ADVDIAL_H
#define S4ADVDIAL_H

#include <QDialog>
#include <QMap>

namespace Ui {
    class S4AdvDial;
}

class S4AdvDial : public QDialog
{
    Q_OBJECT

private:
    void S4AdvDialConnecteEvent();
    void changeSkills(QString, int);
    void changeTraits(QString, int);
    void changeAttr(QString, int);
    int findSkill(QString, QList<QPair<QString, int> >);

public:
    explicit S4AdvDial(QWidget *parent = 0);
    ~S4AdvDial();

    void S4AdvDialInit();
    void S4AdvDialClearAll();
    void S4AddAdvDialTraits(QString, int);
    void S4AddAdvDialSkills(QString, int);
    void S4AdvDialPrintTable();
    void S4AdvDialClearZero();


    QList<QPair<QString, int> > s4AdvDialAttr; // инициализация атрибутов
    QList<QPair<QString, int> > s4AdvDialSkills; // инициализация скилов
    QList<QPair<QString, int> > s4AdvDialTraits; // инициализация трейтцов

    QString s4AdvDialNameRLife;

    QString s4AdvDialLabelElem1;
    QStringList s4AdvDialSkillsElem1;
    QStringList s4AdvDialTraitsElem1;
    int s4AdvDialElem1;
    QString s4AdvDialElemSwp1;

    QString s4AdvDialLabelElem2;
    QStringList s4AdvDialSkillsElem2;
    QStringList s4AdvDialTraitsElem2;
    int s4AdvDialElem2;
    QString s4AdvDialElemSwp2;

    QString s4AdvDialLabelElem3;
    QStringList s4AdvDialSkillsElem3;
    QStringList s4AdvDialTraitsElem3;
    int s4AdvDialElem3;
    QString s4AdvDialElemSwp3;

    QString s4AdvDialLabelElem4;
    QStringList s4AdvDialSkillsElem4;
    QStringList s4AdvDialTraitsElem4;
    int s4AdvDialElem4;
    QString s4AdvDialElemSwp4;

    QString s4AdvDialLabelElem5;
    QStringList s4AdvDialSkillsElem5;
    QStringList s4AdvDialTraitsElem5;
    int s4AdvDialElem5;
    int s4AdvDialRepit5;
    QString s4AdvDialElemSwp5;

    QString s4AdvDialLabelElem6;
    QStringList s4AdvDialSkillsElem6;
    QStringList s4AdvDialTraitsElem6;
    QStringList s4AdvDialAttrElem6;
    int s4AdvDialElem6;
    int s4AdvDialRepit6;
    QString s4AdvDialElemSwp6;

    QString s4AdvDialLabelElem7;
    QStringList s4AdvDialSkillsElem7;
    QStringList s4AdvDialTraitsElem7;
    int s4AdvDialElem7;
    int s4AdvDialRepit7;
    QString s4AdvDialElemSwp7;

    QString s4AdvDialLabelElem8;
    QStringList s4AdvDialSkillsElem8;
    QStringList s4AdvDialTraitsElem8;
    int s4AdvDialElem8;
    QString s4AdvDialElemSwp8;


private:
    Ui::S4AdvDial *ui;

private slots:
    void S4AdvDialComBoxElem1(QString);
    void S4AdvDialComBoxElem2(QString);
    void S4AdvDialComBoxElem3(QString);
    void S4AdvDialComBoxElem4(QString);
    void S4AdvDialComBoxElem5(QString);
    void S4AdvDialComBoxElem6(QString);
    void S4AdvDialComBoxElem7(QString);
    void S4AdvDialComBoxElem8(QString);
    void S4AdvDialAdd5();
    void S4AdvDialAdd6();
    void S4AdvDialAdd7();
};

#endif // S4ADVDIAL_H
