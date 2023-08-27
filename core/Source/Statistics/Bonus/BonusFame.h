#ifndef BONUSFAME_H
#define BONUSFAME_H

#include "BonusSource.h"

class BonusFame : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    QML_ELEMENT

public:
    explicit BonusFame(QObject *parent = nullptr);
    explicit BonusFame(const int value, const int price, QObject* parent = nullptr);

    int value() const;
    int price() const;
    Types::Bonus type() const;

private:
    Types::Bonus m_type;
    int m_value{0};
    int m_price{0};
};

#endif // BONUSFAME_H
