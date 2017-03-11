#include <QQmlApplicationEngine>
#include <QGuiApplication>

#include "customquadmaskedimage.h"
#include "customquad.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<CustomQuad>("SM.Extensions", 1, 0, "CustomQuad");
    qmlRegisterType<CustomQuadMaskedImage>("SM.Extensions", 1, 0, "CustomQuadMaskedImage");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
