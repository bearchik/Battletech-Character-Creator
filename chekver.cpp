#include "chekver.h"

#define URL "http://bthub.net/download/battletech-character-creator-2/"

ChkVer::ChkVer(QWidget *parent, QString ver):
    QWidget(parent)
{
    verApp = ver;
    verNow.clear();
    trayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/img/ico1.ico");
    trayIcon->setIcon(icon);


    if(CheckVersionNetwork() != true ) {
        ShowMessage();
        ShowMessage();
    }
}

bool ChkVer::CheckVersionNetwork() {
    bool chk = true;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QNetworkRequest request;
    request.setUrl(QUrl(URL));

    QNetworkReply *reply(manager->get(QNetworkRequest(request)));

    QEventLoop *loop = new QEventLoop;
    connect(manager, SIGNAL(finished(QNetworkReply*)),loop,SLOT(quit()));

    loop->exec();

    reply->deleteLater();

    if(!reply->readLine().isEmpty()) {
        QStringList buf;
        while(!reply->atEnd()) {
            buf << reply->readLine();
        }

        for(int i =0; i< buf.count(); i++) {
            if(buf[i].toLower().contains("last:")) {
                verNow = buf[i].split(" ")[1];
            }


        }

    }

    if(verNow != verApp) {
        chk = false;
    }

    if(verNow == "") {
        chk = true;
    }

    return chk;
}

void ChkVer::ShowMessage() {
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(1);
    trayIcon->showMessage("Battletech Character Creator","New version available! Download now! http://bthub.net", icon, 16000);
    trayIcon->show();
}
