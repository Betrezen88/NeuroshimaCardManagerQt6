#include "BonusSkillpoints.h"

BonusSkillpoints::BonusSkillpoints(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skillpoints}
{

}

BonusSkillpoints::BonusSkillpoints(const QString &specialization, const int value, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skillpoints}
    , m_specialization{specialization}
    , m_value{value}
{

}

Types::Bonus BonusSkillpoints::type() const
{
    return m_type;
}

QString BonusSkillpoints::specialization() const
{
    return m_specialization;
}

int BonusSkillpoints::value() const
{
    return m_value;
}
