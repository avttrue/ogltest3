#//////////////////////////////////////////
# тестовая работа к занятию https://youtu.be/OyPlRxBRJqs
#//////////////////////////////////////////

QT       += core gui widgets

TARGET = ogltest3
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17

SOURCES += \
        group3dobjects.cpp \
        main.cpp \
        oglwidget.cpp \
        simpleobject3d.cpp \
        transformational.cpp

HEADERS += \
        group3dobjects.h \
        oglwidget.h \
        simpleobject3d.h \
        transformational.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shaders.qrc \
    textures.qrc

win32-g* {
LIBS += -lopengl32
}

win32-msvc* {
LIBS += lopengl32.lib
}
