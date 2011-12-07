#ifndef S2ADVDIALOG_H
#define S2ADVDIALOG_H

#include <QDialog>

namespace Ui {
    class S2AdvDialog;
}

class S2AdvDialog : public QDialog {
    Q_OBJECT

private:
    void changeSkills(QString, int);
    void changeOther(QString, int);
    int findSkill(QString);

    void S2AdvDialConnectEvent();
    void S2AdvDialClearZeroSkills();
    void S2AdvDialPrintTable();

public:
    S2AdvDialog(QWidget *parent = 0);
    ~S2AdvDialog();
    void S2AdvDialInit();
    void S2AdvDialClearAll();


    QStringList s2AdvDialogAttr1;
    QString s2AdvDialogLabel1;
    int s2AdvDialogSkills1;
    int s2AdvDialogTraits1;
    QString s2AdvDialSkillsSwp1;
    QString s2AdvDialTraitsSwp1;

    QStringList s2AdvDialogAttr2;
    QString s2AdvDialogLabel2;
    int s2AdvDialogSkills2;
    int s2AdvDialogTraits2;
    QString s2AdvDialSkillsSwp2;
    QString s2AdvDialTraitsSwp2;

    QStringList s2AdvDialogAttr3;
    QString s2AdvDialogLabel3;
    int s2AdvDialogSkills3;
    int s2AdvDialogTraits3;
    QString s2AdvDialSkillsSwp3;
    QString s2AdvDialTraitsSwp3;

    QStringList s2AdvDialogAttr4;
    QString s2AdvDialogLabel4;
    int s2AdvDialogSkills4;
    int s2AdvDialogTraits4;
    QString s2AdvDialSkillsSwp4;
    QString s2AdvDialTraitsSwp4;

    QList<QPair<QString, int> > s2AdvDialSkills;
    QList<QPair<QString, int> > s2AdvDialOther;





protected:
    void changeEvent(QEvent *e);

private:
    Ui::S2AdvDialog *ui;

private slots:
    void S2AdvDialElem1(QString);
    void S2AdvDialElem2(QString);
    void S2AdvDialElem3(QString);
    void S2AdvDialElem4(QString);

};

#endif // S2ADVDIALOG_H
