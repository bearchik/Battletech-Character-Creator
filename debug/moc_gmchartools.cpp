/****************************************************************************
** Meta object code from reading C++ file 'gmchartools.h'
**
** Created: Thu 22. Sep 12:47:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gmchartools.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gmchartools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GMCharTools[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      44,   12,   12,   12, 0x08,
      82,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GMCharTools[] = {
    "GMCharTools\0\0on_XPAddGM_textEdited(QString)\0"
    "on_FromMoneyAddGm_textEdited(QString)\0"
    "on_ToMoneyAddGm_textEdited(QString)\0"
};

const QMetaObject GMCharTools::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GMCharTools,
      qt_meta_data_GMCharTools, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GMCharTools::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GMCharTools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GMCharTools::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GMCharTools))
        return static_cast<void*>(const_cast< GMCharTools*>(this));
    return QDialog::qt_metacast(_clname);
}

int GMCharTools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_XPAddGM_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_FromMoneyAddGm_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: on_ToMoneyAddGm_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
