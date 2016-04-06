/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpriteEditor/model.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Model[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   34,    6,    6, 0x0a,
      62,   34,    6,    6, 0x0a,
      81,   34,    6,    6, 0x0a,
     104,    6,    6,    6, 0x0a,
     111,    6,    6,    6, 0x0a,
     118,    6,    6,    6, 0x0a,
     133,    6,    6,    6, 0x0a,
     147,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Model[] = {
    "Model\0\0frameCount\0fileOpened(int)\0"
    "point\0mousePressed(QPointF)\0"
    "mouseMove(QPointF)\0mouseReleased(QPointF)\0"
    "save()\0open()\0startPreview()\0stopPreview()\0"
    "preview()\0"
};

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Model *_t = static_cast<Model *>(_o);
        switch (_id) {
        case 0: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->mousePressed((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 2: _t->mouseMove((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 3: _t->mouseReleased((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 4: _t->save(); break;
        case 5: _t->open(); break;
        case 6: _t->startPreview(); break;
        case 7: _t->stopPreview(); break;
        case 8: _t->preview(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Model::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Model::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Model,
      qt_meta_data_Model, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Model::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Model))
        return static_cast<void*>(const_cast< Model*>(this));
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Model::fileOpened(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
