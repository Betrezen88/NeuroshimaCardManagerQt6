#include "MainManager.h"

#include "CardManager.h"

MainManager::MainManager(QObject *parent)
    : QObject{parent}
    , m_cardManager(new CardManager(this))
{

}

CardManager *MainManager::cardManager() const
{
    return m_cardManager;
}
