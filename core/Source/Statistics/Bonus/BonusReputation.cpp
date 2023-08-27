#include "BonusReputation.h"

BonusReputation::BonusReputation(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Reputation}
{

}

BonusReputation::BonusReputation(const int value, const int price, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Reputation}
    , m_value{value}
    , m_price{price}
{

}

Types::Bonus BonusReputation::type() const
{
    return m_type;
}

int BonusReputation::value() const
{
    return m_value;
}

int BonusReputation::price() const
{
    return m_price;
}
