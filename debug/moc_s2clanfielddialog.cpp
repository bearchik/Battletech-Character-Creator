/****************************************************************************
** Meta object code from reading C++ file 's2clanfielddialog.h'
**
** Created: Thu 22. Sep 12:48:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s2clanfielddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's2clanfielddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S2ClanFieldDialog[] = {

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
      19,   18,   18,   18, 0x0a,
      48,   18,   18,   18, 0x0a,
      81,   79,   18,   18, 0x0a,
     108,   79,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_S2ClanFieldDialog[] = {
    "S2ClanFieldDialog\0\0S2CFDClanAdvCombBox(QString)\0"
    "S2CFDClanBasicCombBox(QString)\0,\0"
    "S2CFDClanAdvTable(int,int)\0"
    "S2CFDClanBasicTable(int,int)\0"
};

const QMetaObject S2ClanFieldDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S2ClanFieldDialog,
      qt_meta_data_S2ClanFieldDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S2ClanFieldDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S2ClanFieldDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S2ClanFieldDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S2ClanFieldDialog))
        return static_cast<void*>(const_cast< S2ClanFieldDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int S2ClanFieldDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: S2CFDClanAdvCombBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: S2CFDClanBasicCombBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: S2CFDClanAdvTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: S2CFDClanBasicTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
