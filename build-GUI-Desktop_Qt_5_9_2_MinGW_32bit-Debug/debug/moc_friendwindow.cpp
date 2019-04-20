/****************************************************************************
** Meta object code from reading C++ file 'friendwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainClientNew/friendwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendWindow_t {
    QByteArrayData data[16];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendWindow_t qt_meta_stringdata_FriendWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FriendWindow"
QT_MOC_LITERAL(1, 13, 11), // "onNewFriend"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "id"
QT_MOC_LITERAL(4, 29, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 51, 29), // "on_groupBox_objectNameChanged"
QT_MOC_LITERAL(6, 81, 10), // "objectName"
QT_MOC_LITERAL(7, 92, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(8, 116, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(9, 140, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(10, 164, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(11, 188, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(12, 212, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(13, 236, 26), // "on_AddFriendButton_clicked"
QT_MOC_LITERAL(14, 263, 9), // "onNewChat"
QT_MOC_LITERAL(15, 273, 4) // "data"

    },
    "FriendWindow\0onNewFriend\0\0id\0"
    "on_pushButton_clicked\0"
    "on_groupBox_objectNameChanged\0objectName\0"
    "on_pushButton_6_clicked\0on_pushButton_7_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_AddFriendButton_clicked\0onNewChat\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    0,   72,    2, 0x08 /* Private */,
       5,    1,   73,    2, 0x08 /* Private */,
       7,    0,   76,    2, 0x08 /* Private */,
       8,    0,   77,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void FriendWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendWindow *_t = static_cast<FriendWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewFriend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_groupBox_objectNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_6_clicked(); break;
        case 4: _t->on_pushButton_7_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_pushButton_4_clicked(); break;
        case 8: _t->on_pushButton_5_clicked(); break;
        case 9: _t->on_AddFriendButton_clicked(); break;
        case 10: _t->onNewChat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject FriendWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FriendWindow.data,
      qt_meta_data_FriendWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FriendWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FriendWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
