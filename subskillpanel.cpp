#include "subskillpanel.h"
#include "ui_subskillpanel.h"
#include <QtGui>

SubSkillPanel::SubSkillPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubSkillPanel)
{
    ui->setupUi(this);
}

SubSkillPanel::~SubSkillPanel()
{
    delete ui;
}

void SubSkillPanel::SubSkillPanelInit(QString nameSkill) {
    subSkills.clear();
    subSkills = SubSkillList.values(nameSkill);
    ui->comboBox->addItems(subSkills);
    on_comboBox_activated(ui->comboBox->currentText());
}

void SubSkillPanel::on_comboBox_activated(const QString &subSkillName)
{
    sspSubSkillName = subSkillName;
}
