#include "BonusHealth.h"

BonusHealth::BonusHealth(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Health}
{

}

Types::Bonus BonusHealth::type() const
{
    return m_type;
}
