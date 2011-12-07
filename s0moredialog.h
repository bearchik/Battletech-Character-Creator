#ifndef S0MOREDIALOG_H
#define S0MOREDIALOG_H

#include <QDialog>

namespace Ui {
    class S0MoreDialog;
}

class S0MoreDialog : public QDialog
{
    Q_OBJECT

private:
    void changeSkills(QString, int);
    void changeTraits(QString, int);
    void changeAttr(QString, int);
    int findSkill(QString, QList<QPair<QString, int> >);

    void checkListsBox(QString nameElem1,QString nameElem2,QString nameElem3);

    QStringList listBox;

public:
    explicit S0MoreDialog(QWidget *parent = 0);
    ~S0MoreDialog();

    void S0MoreDialogClear();
    void S0MoreDialogInit();

    void S0PrintTable();

    void S0MoreDialClearZero();
    QStringList checkDifferent(QString elemLeft, QString elemRight, QStringList etalList);



    QList<QPair<QString, int> > s0MoreDialAttr;
    QList<QPair<QString, int> > s0MoreDialTraits;
    QList<QPair<QString, int> > s0MoreDialSkills;

    QString s0MoreDialLabel1;
    QStringList s0MoreDialDrop1;
    int s0Value1;
    QString swpNameSkill1;
    QString swpNameTrait1;
    QString swpNameAttr1;

    QString s0MoreDialLabel2;
    QStringList s0MoreDialDrop2;
    int s0Value2;
    QString swpNameSkill2;
    QString swpNameTrait2;
    QString swpNameAttr2;

    QString s0MoreDialLabel3;
    QStringList s0MoreDialDrop3;
    int s0Value3;
    QString swpNameSkill3;
    QString swpNameTrait3;
    QString swpNameAttr3;

    QString s0MoreDialLabel4;
    QStringList s0MoreDialDrop4;
    int s0Value4;
    QString swpNameSkill4;
    QString swpNameTrait4;
    QString swpNameAttr4;

    QString s0affName;
    QString s0subAffName;



private:
    Ui::S0MoreDialog *ui;

private slots:
    void on_S0AdvDialComBox4_activated(QString );
    void on_S0AdvDialComBox3_activated(QString );
    void on_S0AdvDialComBox2_activated(QString );
    void on_S0AdvDialComBox1_activated(QString );
};

#endif // S0MOREDIALOG_H
