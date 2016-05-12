TEMPLATE = lib
CONFIG -= app_bundle
CONFIG -= qt

DEFINES -= UNICODE
DEFINES += _MBCS
DEFINES += EXPORT


TARGET = MapBasicFunctions

SOURCES += main.cpp

HEADERS += dll_header.h


SOURCES += \
    ../common/regex.cpp \
    ../common/stats.cpp \
    ../common/strings.cpp

HEADERS += \
    ../common/dll_header.h \
    ../common/common.h
	
INCLUDEPATH += ../common
LIBS += -L../common -lcommon

LIBS += shell32.lib user32.lib
