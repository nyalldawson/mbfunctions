TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

DEFINES -= UNICODE
DEFINES += _MBCS
DEFINES += EXPORT


TARGET = MBFunctionsTest

SOURCES += test.cpp 

HEADERS += test.h


INCLUDEPATH += ../common
LIBS += -L../common -lcommon
