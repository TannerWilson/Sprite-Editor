/****************************************************************************
** Meta object code from reading C++ file 'abstract_widget_list.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Qt-Color-Widgets-master/include/abstract_widget_list.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstract_widget_list.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AbstractWidgetList_t {
    QByteArrayData data[11];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractWidgetList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractWidgetList_t qt_meta_stringdata_AbstractWidgetList = {
    {
QT_MOC_LITERAL(0, 0, 18), // "AbstractWidgetList"
QT_MOC_LITERAL(1, 19, 7), // "removed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "i"
QT_MOC_LITERAL(4, 30, 6), // "remove"
QT_MOC_LITERAL(5, 37, 6), // "append"
QT_MOC_LITERAL(6, 44, 14), // "remove_clicked"
QT_MOC_LITERAL(7, 59, 8), // "QWidget*"
QT_MOC_LITERAL(8, 68, 1), // "w"
QT_MOC_LITERAL(9, 70, 10), // "up_clicked"
QT_MOC_LITERAL(10, 81, 12) // "down_clicked"

    },
    "AbstractWidgetList\0removed\0\0i\0remove\0"
    "append\0remove_clicked\0QWidget*\0w\0"
    "up_clicked\0down_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractWidgetList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       5,    0,   50,    2, 0x0a /* Public */,
       6,    1,   51,    2, 0x08 /* Private */,
       9,    1,   54,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void AbstractWidgetList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractWidgetList *_t = static_cast<AbstractWidgetList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->append(); break;
        case 3: _t->remove_clicked((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->up_clicked((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 5: _t->down_clicked((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractWidgetList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractWidgetList::removed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AbstractWidgetList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractWidgetList.data,
      qt_meta_data_AbstractWidgetList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AbstractWidgetList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractWidgetList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractWidgetList.stringdata0))
        return static_cast<void*>(const_cast< AbstractWidgetList*>(this));
    return QWidget::qt_metacast(_clname);
}

int AbstractWidgetList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void AbstractWidgetList::removed(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
