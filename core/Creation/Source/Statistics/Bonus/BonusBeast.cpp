#include "BonusBeast.h"

BonusBeast::BonusBeast(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Pet}
{

}

Types::Bonus BonusBeast::type() const
{
    return m_type;
}
