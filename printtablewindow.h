#ifndef PRINTTABLEWINDOW_H
#define PRINTTABLEWINDOW_H

#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

namespace Ui {
    class PrintTableWindow;
}

class PrintTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PrintTableWindow(QWidget *parent = 0);
    ~PrintTableWindow();

    QPrinter printer;
    QString shortver;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PrintTableWindow *ui;
};

#endif // PRINTTABLEWINDOW_H
