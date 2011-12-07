#ifndef CARIERFIELDS_H
#define CARIERFIELDS_H

#include <QWidget>
#include <QMultiMap>

class CarierFields : public QWidget
{
    Q_OBJECT
public:
    explicit CarierFields(QWidget *parent = 0);
    QStringList FieldDialSearch(QString);
    QMultiMap<QString, QString> masterFieldList;

signals:

public slots:

};

#endif // CARIERFIELDS_H
