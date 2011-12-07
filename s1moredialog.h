#ifndef S1MOREDIALOG_H
#define S1MOREDIALOG_H

#include <QDialog>

namespace Ui {
    class S1MoreDialog;
}

class S1MoreDialog : public QDialog
{
    Q_OBJECT

private:
    void changeSkills(QString, int);
    void changeTraits(QString, int);
    void changeAttr(QString, int);
    int findSkill(QString, QList<QPair<QString, int> >);

public:
    explicit S1MoreDialog(QWidget *parent = 0);
    ~S1MoreDialog();

    void S1MoreDialogClear();
    void S1MoreDialogInit();
    void S1PrintTable();

    void S1MoreDialClearZero();

    QString s1childName;

    QList<QPair<QString, int> > s1MoreDialAttr;
    QList<QPair<QString, int> > s1MoreDialTraits;
    QList<QPair<QString, int> > s1MoreDialSkills;

    QString s1MoreDialLabel1;
    QStringList s1MoreDialDrop1;
    int s1Value1;
    QString swpNameSkill1;
    QString swpNameTrait1;
    QString swpNameAttr1;

    QString s1MoreDialLabel2;
    QStringList s1MoreDialDrop2;
    int s1Value2;
    QString swpNameSkill2;
    QString swpNameTrait2;
    QString swpNameAttr2;

    QString s1MoreDialLabel3;
    QStringList s1MoreDialDrop3;
    int s1Value3;
    QString swpNameSkill3;
    QString swpNameTrait3;
    QString swpNameAttr3;

    QString s1MoreDialLabel4;
    QStringList s1MoreDialDrop4;
    int s1Value4;
    QString swpNameSkill4;
    QString swpNameTrait4;
    QString swpNameAttr4;

private:
    Ui::S1MoreDialog *ui;

private slots:
    void on_S1AdvDialComBox4_activated(QString );
    void on_S1AdvDialComBox3_activated(QString );
    void on_S1AdvDialComBox2_activated(QString );
    void on_S1AdvDialComBox1_activated(QString );
};

#endif // S1MOREDIALOG_H
