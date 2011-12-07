/****************************************************************************
** Meta object code from reading C++ file 's2advdialog.h'
**
** Created: Thu 22. Sep 12:47:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s2advdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's2advdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S2AdvDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      37,   12,   12,   12, 0x08,
      61,   12,   12,   12, 0x08,
      85,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_S2AdvDialog[] = {
    "S2AdvDialog\0\0S2AdvDialElem1(QString)\0"
    "S2AdvDialElem2(QString)\0S2AdvDialElem3(QString)\0"
    "S2AdvDialElem4(QString)\0"
};

const QMetaObject S2AdvDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S2AdvDialog,
      qt_meta_data_S2AdvDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S2AdvDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S2AdvDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S2AdvDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S2AdvDialog))
        return static_cast<void*>(const_cast< S2AdvDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int S2AdvDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: S2AdvDialElem1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: S2AdvDialElem2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: S2AdvDialElem3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: S2AdvDialElem4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
