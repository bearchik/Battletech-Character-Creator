/****************************************************************************
** Meta object code from reading C++ file 's3fielddialog.h'
**
** Created: Thu 29. Sep 17:20:26 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../s3fielddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 's3fielddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_S3FieldDialog[] = {

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
      15,   14,   14,   14, 0x0a,
      41,   14,   14,   14, 0x0a,
      67,   14,   14,   14, 0x0a,
      93,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_S3FieldDialog[] = {
    "S3FieldDialog\0\0S3FieldDialElem1(QString)\0"
    "S3FieldDialElem2(QString)\0"
    "S3FieldDialElem3(QString)\0"
    "S3FieldDialElem4(QString)\0"
};

const QMetaObject S3FieldDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_S3FieldDialog,
      qt_meta_data_S3FieldDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &S3FieldDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *S3FieldDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *S3FieldDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_S3FieldDialog))
        return static_cast<void*>(const_cast< S3FieldDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int S3FieldDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: S3FieldDialElem1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: S3FieldDialElem2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: S3FieldDialElem3((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: S3FieldDialElem4((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
