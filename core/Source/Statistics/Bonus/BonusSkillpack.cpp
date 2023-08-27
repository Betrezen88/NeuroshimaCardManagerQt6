#include "BonusSkillpack.h"

BonusSkillpack::BonusSkillpack(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skillpack}
{

}

BonusSkillpack::BonusSkillpack(const QStringList& list, const int value, QObject* parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Skillpack}
    , m_list{list}
    , m_value{value}
{

}

Types::Bonus BonusSkillpack::type() const
{
    return m_type;
}

QStringList BonusSkillpack::list() const
{
    return m_list;
}

int BonusSkillpack::value() const
{
    return m_value;
}
