/****************************************************************************
** Meta object code from reading C++ file 'graphwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GraphVisualizer/graphwidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGraphWidgetENDCLASS = QtMocHelpers::stringData(
    "GraphWidget",
    "updateGraphLayout",
    "",
    "initializeGraph",
    "applyAttractiveForces",
    "applyRepulsiveForces",
    "updateNodePositions",
    "mousePressEvent",
    "QMouseEvent*",
    "event",
    "mouseReleaseEvent",
    "mouseMoveEvent"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[22];
    char stringdata5[21];
    char stringdata6[20];
    char stringdata7[16];
    char stringdata8[13];
    char stringdata9[6];
    char stringdata10[18];
    char stringdata11[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t qt_meta_stringdata_CLASSGraphWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "GraphWidget"
        QT_MOC_LITERAL(12, 17),  // "updateGraphLayout"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 15),  // "initializeGraph"
        QT_MOC_LITERAL(47, 21),  // "applyAttractiveForces"
        QT_MOC_LITERAL(69, 20),  // "applyRepulsiveForces"
        QT_MOC_LITERAL(90, 19),  // "updateNodePositions"
        QT_MOC_LITERAL(110, 15),  // "mousePressEvent"
        QT_MOC_LITERAL(126, 12),  // "QMouseEvent*"
        QT_MOC_LITERAL(139, 5),  // "event"
        QT_MOC_LITERAL(145, 17),  // "mouseReleaseEvent"
        QT_MOC_LITERAL(163, 14)   // "mouseMoveEvent"
    },
    "GraphWidget",
    "updateGraphLayout",
    "",
    "initializeGraph",
    "applyAttractiveForces",
    "applyRepulsiveForces",
    "updateNodePositions",
    "mousePressEvent",
    "QMouseEvent*",
    "event",
    "mouseReleaseEvent",
    "mouseMoveEvent"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGraphWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    1,   67,    2, 0x08,    6 /* Private */,
      10,    1,   70,    2, 0x08,    8 /* Private */,
      11,    1,   73,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject GraphWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGraphWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGraphWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GraphWidget, std::true_type>,
        // method 'updateGraphLayout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initializeGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyAttractiveForces'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applyRepulsiveForces'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateNodePositions'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mousePressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mouseReleaseEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>,
        // method 'mouseMoveEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>
    >,
    nullptr
} };

void GraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateGraphLayout(); break;
        case 1: _t->initializeGraph(); break;
        case 2: _t->applyAttractiveForces(); break;
        case 3: _t->applyRepulsiveForces(); break;
        case 4: _t->updateNodePositions(); break;
        case 5: _t->mousePressEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 6: _t->mouseReleaseEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 7: _t->mouseMoveEvent((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *GraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGraphWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
