/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SpriteEditor/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     162,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     250,  239,   11,   11, 0x08,
     274,  269,   11,   11, 0x08,
     303,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_secondaryColorButton_clicked()\0"
    "on_addFrameButton_clicked()\0"
    "on_frameButton_clicked()\0"
    "on_primaryColorButton_clicked()\0"
    "on_deleteFrameButton_clicked()\0"
    "on_brushButton_clicked()\0"
    "on_eraserButton_clicked()\0"
    "on_bucketButton_clicked()\0frameCount\0"
    "on_fileOpened(int)\0arg1\0"
    "on_spinBox_valueChanged(int)\0"
    "on_actionExport_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_secondaryColorButton_clicked(); break;
        case 1: _t->on_addFrameButton_clicked(); break;
        case 2: _t->on_frameButton_clicked(); break;
        case 3: _t->on_primaryColorButton_clicked(); break;
        case 4: _t->on_deleteFrameButton_clicked(); break;
        case 5: _t->on_brushButton_clicked(); break;
        case 6: _t->on_eraserButton_clicked(); break;
        case 7: _t->on_bucketButton_clicked(); break;
        case 8: _t->on_fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_actionExport_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
