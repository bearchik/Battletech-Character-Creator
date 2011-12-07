/****************************************************************************
** Meta object code from reading C++ file 's0moredialog.h'
**
** Created: Thu 22. Sep 12:47:53 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s0moredialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's0moredialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S0MoreDialog[] = {

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
      14,   13,   13,   13, 0x08,
      53,   13,   13,   13, 0x08,
      92,   13,   13,   13, 0x08,
     131,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_S0MoreDialog[] = {
    "S0MoreDialog\0\0on_S0AdvDialComBox4_activated(QString)\0"
    "on_S0AdvDialComBox3_activated(QString)\0"
    "on_S0AdvDialComBox2_activated(QString)\0"
    "on_S0AdvDialComBox1_activated(QString)\0"
};

const QMetaObject S0MoreDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S0MoreDialog,
      qt_meta_data_S0MoreDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S0MoreDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S0MoreDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S0MoreDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S0MoreDialog))
        return static_cast<void*>(const_cast< S0MoreDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int S0MoreDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_S0AdvDialComBox4_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_S0AdvDialComBox3_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: on_S0AdvDialComBox2_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_S0AdvDialComBox1_activated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
