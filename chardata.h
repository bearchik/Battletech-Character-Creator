#ifndef CHARDATA_H
#define CHARDATA_H

#include <QWidget>
#include <QMap>
#include "text_resurce.h"

class CharData : public QWidget
{
Q_OBJECT
private:


public:
    explicit CharData(QWidget *parent = 0);
    int xp; // иницализация количества XP
    int age; // годы жизни
    QString charName; // инициализация имени
    QPair <QString, int> AffName; // инициализация места рождения
    QPair <QString, int> subAffName; // инициализация суб места рождения
    QPair <QString, int> clanCastName; // инициализация касты клана
    QPair <QString, int> earlyChildName; // инициализация названия ранней школоты
    QPair <QString, int> lateChildName; // инициализация названия поздней школоты
    QPair <QString, int> schoolName; // инициализация названия школы
    QPair <QString, int> basicSchool; // инициализация названия базовой подготовки
    QPair <QString, int> advSchool; // инициализация названия адв подготовки
    QPair <QString, int> specSchool; // инициализация названия спец подготовки
    QString realLife;
    QString phenotype;
    bool milField;
    bool policField;
    bool civField;

    QString sex;
    QString hair;
    QString eye;
    int height;
    int weight;
    int startXP;


    QMap<QString, int> charAttr; // инициализация атрибутов
    QList<QPair<QString, int> > charSkills; // инициализация скилов
    QList<QPair<QString, int> > charTraits;

    QMap<QString, int> preCharAttr; // пререквезиты атрибутов
    QList<QPair<QString, int> > preCharSkills; // пререквезиты скилов
    QList<QPair<QString, int> > preCharTraits; // пререквизиты трайтцов

    bool comChk;
    bool wobChk;


    void Atribute();
    void changeSkills(QString, int);
    int findSkill(QString);
    void changeTraits(QString, int);
    int findTraits(QString);


    void clearZeroSkills();
    void clearZeroTraits();
    void clearChar();

signals:

public slots:

};

#endif // CHARDATA_H
