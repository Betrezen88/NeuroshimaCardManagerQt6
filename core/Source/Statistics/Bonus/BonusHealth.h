#ifndef BONUSHEALTH_H
#define BONUSHEALTH_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusHealth : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit BonusHealth(QObject *parent = nullptr);

    Types::Bonus type() const;

private:
    Types::Bonus m_type;
};

#endif // BONUSHEALTH_H
