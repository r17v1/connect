/****************************************************************************
** Meta object code from reading C++ file 'mysocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainClientNew/mysocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MySocket_t {
    QByteArrayData data[11];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySocket_t qt_meta_stringdata_MySocket = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MySocket"
QT_MOC_LITERAL(1, 9, 5), // "login"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "signup"
QT_MOC_LITERAL(4, 23, 9), // "newFriend"
QT_MOC_LITERAL(5, 33, 6), // "newMsg"
QT_MOC_LITERAL(6, 40, 10), // "fileUpload"
QT_MOC_LITERAL(7, 51, 12), // "fileUpStatus"
QT_MOC_LITERAL(8, 64, 14), // "connectionLost"
QT_MOC_LITERAL(9, 79, 9), // "readyRead"
QT_MOC_LITERAL(10, 89, 12) // "disconnected"

    },
    "MySocket\0login\0\0signup\0newFriend\0"
    "newMsg\0fileUpload\0fileUpStatus\0"
    "connectionLost\0readyRead\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,
       6,    0,   71,    2, 0x06 /* Public */,
       7,    1,   72,    2, 0x06 /* Public */,
       8,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MySocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MySocket *_t = static_cast<MySocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->login((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->newFriend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->newMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->fileUpload(); break;
        case 5: _t->fileUpStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->connectionLost(); break;
        case 7: _t->readyRead(); break;
        case 8: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MySocket::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::login)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::signup)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::newFriend)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::newMsg)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::fileUpload)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::fileUpStatus)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MySocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MySocket::connectionLost)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MySocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MySocket.data,
      qt_meta_data_MySocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MySocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MySocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MySocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MySocket::login(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MySocket::signup(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MySocket::newFriend(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MySocket::newMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MySocket::fileUpload()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MySocket::fileUpStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MySocket::connectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
