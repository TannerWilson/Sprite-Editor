/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpriteEditor/model.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Model_t {
    QByteArrayData data[11];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Model_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Model"
QT_MOC_LITERAL(1, 6, 12), // "MousePressed"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "point"
QT_MOC_LITERAL(4, 26, 9), // "MouseMove"
QT_MOC_LITERAL(5, 36, 13), // "MouseReleased"
QT_MOC_LITERAL(6, 50, 4), // "Save"
QT_MOC_LITERAL(7, 55, 4), // "Open"
QT_MOC_LITERAL(8, 60, 12), // "StartPreview"
QT_MOC_LITERAL(9, 73, 11), // "StopPreview"
QT_MOC_LITERAL(10, 85, 7) // "Preview"

    },
    "Model\0MousePressed\0\0point\0MouseMove\0"
    "MouseReleased\0Save\0Open\0StartPreview\0"
    "StopPreview\0Preview"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Model[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x0a /* Public */,
       5,    1,   60,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Model *_t = static_cast<Model *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MousePressed((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->MouseMove((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->MouseReleased((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->Save(); break;
        case 4: _t->Open(); break;
        case 5: _t->StartPreview(); break;
        case 6: _t->StopPreview(); break;
        case 7: _t->Preview(); break;
        default: ;
        }
    }
}

const QMetaObject Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model.data,
      qt_meta_data_Model,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
