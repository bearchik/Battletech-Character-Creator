#ifndef CHEKVER_H
#define CHEKVER_H

#include <QWidget>
#include <QtNetwork>
#include <QSystemTrayIcon>

class ChkVer : public QWidget
{
    Q_OBJECT
public:
    explicit ChkVer(QWidget *parent = 0, QString ver = "0");
    QString verNow;
    QString verApp;

    bool CheckVersionNetwork();

    void ShowMessage();

private:
    QMenu *trayIconMenu;
    QSystemTrayIcon *trayIcon;
signals:

public slots:

};

#endif // CHEKVER_H
