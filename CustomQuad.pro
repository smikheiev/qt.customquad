TEMPLATE = app

QT += qml quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += sources/main.cpp \
    sources/customquad.cpp

HEADERS += \
    sources/customquad.h

RESOURCES += \
    resources/qml/_qml.qrc \
    resources/image/_image.qrc
