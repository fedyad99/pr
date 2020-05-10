include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../Desktop/lr9/IKeypad.h \
        ../../Desktop/lr9/ILatch.h \
        ../../Desktop/lr9/lockcontroller.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../../Desktop/lr9/lockcontroller.cpp \
        main.cpp
INCLUDEPATH += "C:\Users\user\Desktop\lr9"
