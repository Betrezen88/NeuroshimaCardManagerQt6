#ifndef MAINMANAGER_H
#define MAINMANAGER_H

#include <QObject>

#include "CardManager.h"

#include <../Creation/CardCreation.h>

class MainManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CardManager* cardManager READ cardManager CONSTANT)
    Q_PROPERTY(CardCreation* cardCreation READ cardCreation CONSTANT)

public:
    explicit MainManager(QObject *parent = nullptr);

    CardManager *cardManager() const;
    CardCreation *cardCreation() const;

signals:
    void createCardCreation() const;

private:
    void createResourceDirectory();
    void onCreateCardCreation();

private:
    CardManager *m_cardManager{nullptr};
    CardCreation *m_cardCreation{nullptr};
};

#endif // MAINMANAGER_H
