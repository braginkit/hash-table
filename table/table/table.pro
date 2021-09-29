QT += core gui
QT += widgets
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    hash_table.h \
    hash_table.inl \
    mainwindow.h \
    person.h \
    person.inl

FORMS += \
    mainwindow.ui
