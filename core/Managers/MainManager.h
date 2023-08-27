#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

#include "CardManager.h"

class MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager* cardManager READ cardManager CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager *cardManager() const;

signals:

private:
    void createResourceDirectory();

private:
    CardManager *m_cardManager{nullptr};
};

#endif // MAINMANAGER_H
