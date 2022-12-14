#-------------------------------------------------
#
# Project created by QtCreator 2022-12-02T09:08:37
#
#-------------------------------------------------

QT       +=core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS     +=-lopengl32 -lglu32
LIBS += -L$$PWD/assimp/lib64/ -lassimp
INCLUDEPATH += $$PWD/assimp
DEPENDPATH += $$PWD/assimp

TARGET = Chess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myglwidget.cpp \
    chess.cpp \
    model.cpp \
    mesh.cpp \
    camera.cpp

HEADERS += \
        mainwindow.h \
    myglwidget.h \
    chess.h \
    model.h \
    mesh.h \
    camera.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    res.qrc



INCLUDEPATH += D:/QT/opencv/build/include
DEPENDPATH += D:/QT/opencv/build/include

win32:CONFIG(release, debug|release): LIBS += -LD:/QT/opencv/build/x64/vc15/lib/ -lopencv_world454
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/QT/opencv/build/x64/vc15/lib/ -lopencv_world454d
else:unix: LIBS += -LD:/QT/opencv/build/x64/vc15/lib/ -lopencv_world454

DEFINES += QT_MESSAGELOGCONTEXT
INCLUDEPATH += $$PWD/eigen-3.4
