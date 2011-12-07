#ifndef PREQDIALOG_H
#define PREQDIALOG_H

#include <QDialog>
#include <QMap>

namespace Ui {
    class PreqDialog;
}

class PreqDialog : public QDialog
{
    Q_OBJECT

private:
    void PrintTable();
    void NobChange(QString);
    void WhiteColChange(QString);
    void CovOpChange(QString);

public:
    explicit PreqDialog(QWidget *parent = 0);
    ~PreqDialog();

    void initPreDialog();


    QMap<QString, int> preAttr;
    QList<QPair<QString, int> > preSkills;
    QList<QPair<QString, int> > preTraits;
    QString earlyChild;
    QString realLife;

    QList<QPair<QString, int> > preTraitsChoose;
    QList<QPair<QString, int> > preSkillsChoose;



private:
    Ui::PreqDialog *ui;

private slots:


private slots:


private slots:
    void on_preqListTable_cellClicked(int row, int column);
};

#endif // PREQDIALOG_H
