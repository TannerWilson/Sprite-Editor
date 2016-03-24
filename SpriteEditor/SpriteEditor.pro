#-------------------------------------------------
#
# Project created by QtCreator 2016-03-24T15:30:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpriteEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    sprite.cpp \
    tool.cpp \
    image.cpp \
    layer.cpp \
    vector.cpp \
    pen.cpp \
    eraser.cpp \
    bucket.cpp \
    gifexport.cpp

HEADERS  += mainwindow.h \
    model.h \
    sprite.h \
    tool.h \
    image.h \
    layer.h \
    vector.h \
    pen.h \
    eraser.h \
    bucket.h \
    gifexport.h

FORMS    += mainwindow.ui
