#include "BonusFame.h"

BonusFame::BonusFame(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Fame}
{

}

BonusFame::BonusFame(const int value, const int price, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Fame}
    , m_value{value}
    , m_price{price}
{

}

int BonusFame::value() const
{
    return m_value;
}

int BonusFame::price() const
{
    return m_price;
}

Types::Bonus BonusFame::type() const
{
    return m_type;
}
