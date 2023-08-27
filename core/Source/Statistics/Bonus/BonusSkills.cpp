#include "BonusSkills.h"

BonusSkills::BonusSkills(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skills}
{

}

BonusSkills::BonusSkills(const int value, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skills}
    , m_value{value}
{

}

Types::Bonus BonusSkills::type() const
{
    return m_type;
}

int BonusSkills::value() const
{
    return m_value;
}
