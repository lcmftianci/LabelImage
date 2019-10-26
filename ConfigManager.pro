#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T16:44:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConfigManager
TEMPLATE = app

INCLUDEPATH = include/mxml/
#LIBS = $$PWD"lib/mxml"
VAR = msg
message(VAR=$$VAR)
LASTDIR = $$relative_path($$_PRO_FILE_PWD_, $$_PRO_FILE_PWD_/..)
message(VAR=$$LASTDIR)
LASTDIR += "/lib/mxml"
message(VAR=$$LASTDIR)
#LIBS += -L"./lib/mxml/" -lmxml1
LIBS += -L"E:/qtproj/ConfigManager/lib/mxml/" -lmxml1

SOURCES += main.cpp\
        mainwindow.cpp \
    xmlmanager.cpp \
    detector.cpp \
    strutils.cpp \
    graphmath.cpp \
    custommessagebox.cpp \
    configfilemanager.cpp

HEADERS  += mainwindow.h \
    xmlmanager.h \
    detector.h \
    common.h \
    strutils.h \
    graphmath.h \
    custommessagebox.h \
    configfilemanager.h

FORMS    += mainwindow.ui

RESOURCES += \
    stylesheet/image.qrc
