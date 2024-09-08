#include "BonusFriend.h"

BonusFriend::BonusFriend(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Connections}
{

}

BonusFriend::BonusFriend(const int value, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Connections}
    , m_value{value}
{

}

Types::Bonus BonusFriend::type() const
{
    return m_type;
}

int BonusFriend::value() const
{
    return m_value;
}
