#ifndef S2FLEXXPDIALOG_H
#define S2FLEXXPDIALOG_H

#include <QMap>
#include <QDialog>
#include "subskillpanel.h"

namespace Ui {
    class S2FlexXPDialog;
}

class S2FlexXPDialog : public QDialog {
    Q_OBJECT
public:
    S2FlexXPDialog(QWidget *parent = 0);
    ~S2FlexXPDialog();

    SubSkillPanel *subpanel;

    void S2FXDConnectEvent();
    void S2FXDChange();
    void S2FXDDisableAll();

    void S2FXDPrintTraitsTable();
    void S2FXDAddTraits(QString, int);
    void S2FXDAddTraitsFinal(QString, int);

    void S2FXDPrintSkillsTable();
    void S2FXDAddSkills(QString, int);
    void S2FXDAddSkillsFinal(QString, int);

    void S2FXDDisableElem(QString);

    QList<QPair<QString, int> > S2FXDClearZero(QList<QPair<QString, int> >);
    int S2FXDFind(QString, QList<QPair<QString, int> >);


    int s2FXDFreeXPLabel;
    int s2FXDFreeXPLabelInit;

    int s2FXDStr;
    int s2FXDBod;
    int s2FXDRfl;
    int s2FXDDex;
    int s2FXDInt;
    int s2FXDWil;
    int s2FXDCha;
    int s2FXDEdg;
    QList<QPair<QString, int> > s2FXDTraits;
    QList<QPair<QString, int> > s2FXDTraitsInit;
    QList<QPair<QString, int> >s2FXDTraitsSwp;
    QList<QPair<QString, int> > s2FXDSkills;
    QList<QPair<QString, int> > s2FXDSkillsInit;
    QList<QPair<QString, int> > s2FXDSkillsSwp;
    QStringList s2FXDAllSkills;
    QStringList s2FXDAllSkillsSwp;
    QStringList s2FXDAllTraits;
    QStringList s2FXDAllTraitsSwp;

    QMap<QString, int> s2FXDCharAttr;

    QMultiMap<QString, QString> s2FXSubSkillList;

    int s2FXDTraitsXPSwpInt;
    QString s2FXDTraitsXPSwp;

    int s2FXDSkillsXPSwpInt;
    QString s2FXDSkillsXPSwp;

    QString s2FXDNameChillHood;

    QMap<QString, QString> skillsDescList;
    QString SkillDesc(QString nameSkill);

    QMap<QString, QString> traitsDescList;
    QString TraitsDesc(QString nameSkill);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::S2FlexXPDialog *ui;

public slots:
    void S2FlexXPDialogInit();
    void S2FXDSpinBoxTraitsChange(int);
    void S2FXDSpinBoxSkillsChange(int);
    void S2FXDSpinBoxSTRChange(int);
    void S2FXDSpinBoxBODChange(int);
    void S2FXDSpinBoxRFLChange(int);
    void S2FXDSpinBoxDEXChange(int);
    void S2FXDSpinBoxINTChange(int);
    void S2FXDSpinBoxWILChange(int);
    void S2FXDSpinBoxCHAChange(int);
    void S2FXDSpinBoxEDGChange(int);

    void S2FXDTraitTableActing(int);
    void S2FXDSkillsTableActing(int);

    void S2FXDTraitsComBoxActing(QString);
    void S2FXDSkillsComBoxActing(QString);

    void S2FXDSubpanelAcceptButton();

};

#endif // S2FLEXXPDIALOG_H





