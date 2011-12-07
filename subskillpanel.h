#ifndef SUBSKILLPANEL_H
#define SUBSKILLPANEL_H

#include <QDialog>
#include <QMultiMap>

namespace Ui {
    class SubSkillPanel;
}

class SubSkillPanel : public QDialog
{
    Q_OBJECT

public:
    explicit SubSkillPanel(QWidget *parent = 0);
    ~SubSkillPanel();

    QMultiMap<QString, QString> SubSkillList;
    QStringList subSkills;
    QString sspSubSkillName;


    void SubSkillPanelInit(QString nameSkill);

private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::SubSkillPanel *ui;

};

#endif // SUBSKILLPANEL_H
