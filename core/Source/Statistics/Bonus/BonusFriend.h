#ifndef BONUSFRIEND_H
#define BONUSFRIEND_H

#include "BonusSource.h"

class BonusFriend : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit BonusFriend(QObject *parent = nullptr);
    explicit BonusFriend(const int value, QObject* parent = nullptr);
    Types::Bonus type() const;
    int value() const;

private:
    Types::Bonus m_type;
    int m_value{0};
};

#endif // BONUSFRIEND_H
