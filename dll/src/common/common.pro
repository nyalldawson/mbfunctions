TEMPLATE = lib
CONFIG = staticlib
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += /EHsc

DEFINES -= UNICODE
DEFINES += _MBCS
DEFINES += EXPORT

TARGET = common

SOURCES += \
    regex.cpp \
    stats.cpp \
    strings.cpp

HEADERS += \
    dll_header.h \
    common.h \
    mbfunctions.h
