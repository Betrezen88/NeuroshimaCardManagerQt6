#ifndef BONUSBEAST_H
#define BONUSBEAST_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusBeast : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit BonusBeast(QObject *parent = nullptr);

    Types::Bonus type() const;

private:
    Types::Bonus m_type;
};

#endif // BONUSBEAST_H
