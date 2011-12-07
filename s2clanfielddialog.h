#ifndef S2CLANFIELDDIALOG_H
#define S2CLANFIELDDIALOG_H

#include <QDialog>

namespace Ui {
    class S2ClanFieldDialog;
}

class S2ClanFieldDialog : public QDialog
{
    Q_OBJECT

public:
    explicit S2ClanFieldDialog(QWidget *parent = 0);
    ~S2ClanFieldDialog();

    void S2CFDInit();
    void S2CFDConnectEvent();
    void S2CFDChange();

    void S2CFDPrintSkillsAdvTable();
    void S2CFDPrintSkillsBasicTable();

    QStringList s2CFDBasicList;
    QStringList s2CFDAdvList;
    int s2CFDClanAdvXP;
    int s2CFDClanAdvStepXP;
    int s2CFDClanAdvRebateXP;

    int s2CFDClanBasicXP;
    int s2CFDClanBasicStepXP;
    int s2CFDClanBasicRebateXP;
    int s2CFDRebateSum;


    QString s2CFDClanAdvLabel;
    QList<QPair<QString, int> > s2CFDClanBasicSkills;
    QList<QPair<QString, int> > s2CFDClanAdvSkills;

    QStringList advListPart1;
    QStringList advListPart2;
    QStringList advListPart3;
    QStringList advListPart4;
    QStringList advListPart5;

private:
    Ui::S2ClanFieldDialog *ui;

public slots:
    void S2CFDClanAdvCombBox(QString);
    void S2CFDClanBasicCombBox(QString);

    void S2CFDClanAdvTable(int, int);
    void S2CFDClanBasicTable(int, int);
};

#endif // S2CLANFIELDDIALOG_H
