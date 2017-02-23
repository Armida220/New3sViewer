/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainwindow_t {
    QByteArrayData data[10];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_mainwindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_mainwindow_t qt_meta_stringdata_mainwindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 3),
QT_MOC_LITERAL(4, 28, 9),
QT_MOC_LITERAL(5, 38, 17),
QT_MOC_LITERAL(6, 56, 9),
QT_MOC_LITERAL(7, 66, 8),
QT_MOC_LITERAL(8, 75, 13),
QT_MOC_LITERAL(9, 89, 19)
    },
    "mainwindow\0sendMessage\0\0str\0slot_open\0"
    "slot_tempterature\0slot_wind\0slot_Ice\0"
    "slot_zengrong\0slot_receiveMessage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainwindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x0a,
       5,    0,   53,    2, 0x0a,
       6,    0,   54,    2, 0x0a,
       7,    0,   55,    2, 0x0a,
       8,    0,   56,    2, 0x0a,
       9,    1,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void mainwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainwindow *_t = static_cast<mainwindow *>(_o);
        switch (_id) {
        case 0: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slot_open(); break;
        case 2: _t->slot_tempterature(); break;
        case 3: _t->slot_wind(); break;
        case 4: _t->slot_Ice(); break;
        case 5: _t->slot_zengrong(); break;
        case 6: _t->slot_receiveMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mainwindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mainwindow::sendMessage)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject mainwindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainwindow.data,
      qt_meta_data_mainwindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *mainwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainwindow.stringdata))
        return static_cast<void*>(const_cast< mainwindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void mainwindow::sendMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
