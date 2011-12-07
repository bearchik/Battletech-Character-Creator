/****************************************************************************
** Meta object code from reading C++ file 's2flexxpdialog.h'
**
** Created: Thu 29. Sep 17:20:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s2flexxpdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's2flexxpdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S2FlexXPDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      37,   15,   15,   15, 0x0a,
      67,   15,   15,   15, 0x0a,
      97,   15,   15,   15, 0x0a,
     124,   15,   15,   15, 0x0a,
     151,   15,   15,   15, 0x0a,
     178,   15,   15,   15, 0x0a,
     205,   15,   15,   15, 0x0a,
     232,   15,   15,   15, 0x0a,
     259,   15,   15,   15, 0x0a,
     286,   15,   15,   15, 0x0a,
     313,   15,   15,   15, 0x0a,
     340,   15,   15,   15, 0x0a,
     368,   15,   15,   15, 0x0a,
     401,   15,   15,   15, 0x0a,
     434,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_S2FlexXPDialog[] = {
    "S2FlexXPDialog\0\0S2FlexXPDialogInit()\0"
    "S2FXDSpinBoxTraitsChange(int)\0"
    "S2FXDSpinBoxSkillsChange(int)\0"
    "S2FXDSpinBoxSTRChange(int)\0"
    "S2FXDSpinBoxBODChange(int)\0"
    "S2FXDSpinBoxRFLChange(int)\0"
    "S2FXDSpinBoxDEXChange(int)\0"
    "S2FXDSpinBoxINTChange(int)\0"
    "S2FXDSpinBoxWILChange(int)\0"
    "S2FXDSpinBoxCHAChange(int)\0"
    "S2FXDSpinBoxEDGChange(int)\0"
    "S2FXDTraitTableActing(int)\0"
    "S2FXDSkillsTableActing(int)\0"
    "S2FXDTraitsComBoxActing(QString)\0"
    "S2FXDSkillsComBoxActing(QString)\0"
    "S2FXDSubpanelAcceptButton()\0"
};

const QMetaObject S2FlexXPDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S2FlexXPDialog,
      qt_meta_data_S2FlexXPDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S2FlexXPDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S2FlexXPDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S2FlexXPDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S2FlexXPDialog))
        return static_cast<void*>(const_cast< S2FlexXPDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int S2FlexXPDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: S2FlexXPDialogInit(); break;
        case 1: S2FXDSpinBoxTraitsChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: S2FXDSpinBoxSkillsChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: S2FXDSpinBoxSTRChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: S2FXDSpinBoxBODChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: S2FXDSpinBoxRFLChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: S2FXDSpinBoxDEXChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: S2FXDSpinBoxINTChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: S2FXDSpinBoxWILChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: S2FXDSpinBoxCHAChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: S2FXDSpinBoxEDGChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: S2FXDTraitTableActing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: S2FXDSkillsTableActing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: S2FXDTraitsComBoxActing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: S2FXDSkillsComBoxActing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: S2FXDSubpanelAcceptButton(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
