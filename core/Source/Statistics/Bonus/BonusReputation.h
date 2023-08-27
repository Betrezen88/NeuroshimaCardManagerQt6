#ifndef BONUSREPUTATION_H
#define BONUSREPUTATION_H

#include "BonusSource.h"

class BonusReputation : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    QML_ELEMENT

public:
    explicit BonusReputation(QObject *parent = nullptr);
    explicit BonusReputation(const int value, const int price, QObject* parent = nullptr);

    Types::Bonus type() const;
    int value() const;
    int price() const;

private:
    Types::Bonus m_type;
    int m_value{0};
    int m_price{0};
};

#endif // BONUSREPUTATION_H
