#include "MainManager.h"

#include "CardManager.h"

#include <QDir>

MainManager::MainManager(QObject *parent)
    : QObject{parent}
    , m_cardManager(new CardManager(this))
{
    createResourceDirectory();
}

CardManager *MainManager::cardManager() const
{
    return m_cardManager;
}

void MainManager::createResourceDirectory()
{
    const QString& resources{"../resources"};
    const QString& sources{resources+"/sources"};
    const QString& images{resources+"/images"};

    QDir directory;
    if ( !directory.exists(resources) )
        directory.mkpath(resources);

    if ( !directory.exists(sources) )
        directory.mkpath(sources);

    if ( !directory.exists(images) )
        directory.mkpath(images);
}
