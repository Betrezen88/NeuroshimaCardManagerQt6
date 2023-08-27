#include "SourceLoader.h"

#include "../Utils/JsonLoader.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QDebug>

SourceLoader::SourceLoader(QObject *parent)
    : QObject{parent}
{

}

void SourceLoader::load()
{
    const QString& sources{"../resources/sources"};
    QDir directory;
    if ( !directory.exists(sources) ) {
        qDebug() << "Sources folder does not exist!";
        return;
    }

    if ( !directory.cd(sources) ) {
        qDebug() << "Failed to enter \"" + sources + "\" folder.";
        return;
    }

    const QStringList& files = directory.entryList(QStringList("*.json"), QDir::Files);
    const QString& absolutePath{directory.absolutePath() + "/"};

    for ( const QString& file: files ) {
        JsonLoader loader;

        QObject::connect(&loader, &JsonLoader::error, this, &SourceLoader::onError);

        QJsonDocument json = loader.load( absolutePath + file );
        QJsonObject object = json.object();
        QJsonDocument data{object.value("data").toArray()};

        emit sendSourceDocument(SourceDocument{object.value("type").toString(),
                                               object.value("source").toString(),
                                               data} );
    }
}

