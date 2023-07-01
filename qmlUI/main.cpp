#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "../core/Managers/MainManager.h"
#include "../core/Data/Common/Types.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableMetaObject(Types::staticMetaObject, "data.types", 1, 0, "Types", "Data enums.");

    MainManager manager{&app};

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("manager", &manager);

    const QUrl url(u"qrc:/QmlUI/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
