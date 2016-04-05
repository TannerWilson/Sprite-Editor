/****************************************************************************
** Meta object code from reading C++ file 'spritegraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpriteEditor/spritegraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spritegraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SpriteGraphicsView_t {
    QByteArrayData data[11];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpriteGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpriteGraphicsView_t qt_meta_stringdata_SpriteGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SpriteGraphicsView"
QT_MOC_LITERAL(1, 19, 15), // "MouseMoveSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "point"
QT_MOC_LITERAL(4, 42, 16), // "MousePressSignal"
QT_MOC_LITERAL(5, 59, 18), // "MouseReleaseSignal"
QT_MOC_LITERAL(6, 78, 15), // "mousePressEvent"
QT_MOC_LITERAL(7, 94, 12), // "QMouseEvent*"
QT_MOC_LITERAL(8, 107, 5), // "event"
QT_MOC_LITERAL(9, 113, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(10, 128, 17) // "mouseReleaseEvent"

    },
    "SpriteGraphicsView\0MouseMoveSignal\0\0"
    "point\0MousePressSignal\0MouseReleaseSignal\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseMoveEvent\0mouseReleaseEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpriteGraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x0a /* Public */,
       9,    1,   56,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void SpriteGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpriteGraphicsView *_t = static_cast<SpriteGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MouseMoveSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->MousePressSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->MouseReleaseSignal((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SpriteGraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpriteGraphicsView::MouseMoveSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (SpriteGraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpriteGraphicsView::MousePressSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (SpriteGraphicsView::*_t)(QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SpriteGraphicsView::MouseReleaseSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SpriteGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_SpriteGraphicsView.data,
      qt_meta_data_SpriteGraphicsView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SpriteGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpriteGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SpriteGraphicsView.stringdata0))
        return static_cast<void*>(const_cast< SpriteGraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int SpriteGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SpriteGraphicsView::MouseMoveSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpriteGraphicsView::MousePressSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpriteGraphicsView::MouseReleaseSignal(QPointF _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
