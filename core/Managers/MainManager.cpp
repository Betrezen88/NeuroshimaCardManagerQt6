#include "MainManager.h"

#include "CardManager.h"

#include <QDir>

MainManager::MainManager(QObject *parent)
    : QObject{parent}
    , m_cardManager(new CardManager(this))
{
    connect(this, &MainManager::createCardCreation, this, &MainManager::onCreateCardCreation);
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

void MainManager::onCreateCardCreation()
{
    if ( m_cardCreation == nullptr ) {
        m_cardCreation = new CardCreation(this);
    }
}

CardCreation *MainManager::cardCreation() const
{
    emit createCardCreation();
    return m_cardCreation;
}
