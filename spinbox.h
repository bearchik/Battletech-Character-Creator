#ifndef SPINBOX_H
#define SPINBOX_H

#include <QSpinBox>
#include <QKeyEvent>


class SpinBox : public QSpinBox {
     Q_OBJECT
public:
    SpinBox(QWidget *parent = 0) : QSpinBox(parent) { }
protected:
    void keyPressEvent(QKeyEvent *event);

};




#endif
