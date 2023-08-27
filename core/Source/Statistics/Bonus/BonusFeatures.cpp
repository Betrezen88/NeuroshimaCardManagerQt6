#include "BonusFeatures.h"

BonusFeatures::BonusFeatures(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Features}
{

}

Types::Bonus BonusFeatures::type() const
{
    return m_type;
}
