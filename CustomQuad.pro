TEMPLATE = app

QT += qml quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += sources/main.cpp \
    sources/customquad.cpp \
    sources/customquadmaskedimage.cpp

HEADERS += \
    sources/customquad.h \
    sources/customquadmaskedimage.h

RESOURCES += \
    resources/qml/_qml.qrc \
    resources/image/_image.qrc
