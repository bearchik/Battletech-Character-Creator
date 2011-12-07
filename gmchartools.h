#ifndef GMCHARTOOLS_H
#define GMCHARTOOLS_H

#include <QDialog>

namespace Ui {
    class GMCharTools;
}

class GMCharTools : public QDialog
{
    Q_OBJECT

public:
    explicit GMCharTools(QWidget *parent = 0);
    ~GMCharTools();

    int addCBills;
    int addXP;

private:
    Ui::GMCharTools *ui;

private slots:
    void on_XPAddGM_textEdited(QString );
    void on_FromMoneyAddGm_textEdited(QString );
    void on_ToMoneyAddGm_textEdited(QString );
};

#endif // GMCHARTOOLS_H
