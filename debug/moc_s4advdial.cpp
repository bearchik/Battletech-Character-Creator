/****************************************************************************
** Meta object code from reading C++ file 's4advdial.h'
**
** Created: Thu 22. Sep 12:48:10 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s4advdial.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's4advdial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S4AdvDial[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      41,   10,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
     101,   10,   10,   10, 0x08,
     131,   10,   10,   10, 0x08,
     161,   10,   10,   10, 0x08,
     191,   10,   10,   10, 0x08,
     221,   10,   10,   10, 0x08,
     251,   10,   10,   10, 0x08,
     267,   10,   10,   10, 0x08,
     283,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_S4AdvDial[] = {
    "S4AdvDial\0\0S4AdvDialComBoxElem1(QString)\0"
    "S4AdvDialComBoxElem2(QString)\0"
    "S4AdvDialComBoxElem3(QString)\0"
    "S4AdvDialComBoxElem4(QString)\0"
    "S4AdvDialComBoxElem5(QString)\0"
    "S4AdvDialComBoxElem6(QString)\0"
    "S4AdvDialComBoxElem7(QString)\0"
    "S4AdvDialComBoxElem8(QString)\0"
    "S4AdvDialAdd5()\0S4AdvDialAdd6()\0"
    "S4AdvDialAdd7()\0"
};

const QMetaObject S4AdvDial::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S4AdvDial,
      qt_meta_data_S4AdvDial, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S4AdvDial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S4AdvDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S4AdvDial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S4AdvDial))
        return static_cast<void*>(const_cast< S4AdvDial*>(this));
    return QDialog::qt_metacast(_clname);
}

int S4AdvDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: S4AdvDialComBoxElem1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: S4AdvDialComBoxElem2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: S4AdvDialComBoxElem3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: S4AdvDialComBoxElem4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: S4AdvDialComBoxElem5((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: S4AdvDialComBoxElem6((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: S4AdvDialComBoxElem7((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: S4AdvDialComBoxElem8((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: S4AdvDialAdd5(); break;
        case 9: S4AdvDialAdd6(); break;
        case 10: S4AdvDialAdd7(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
