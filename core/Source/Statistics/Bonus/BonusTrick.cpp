#include "BonusTrick.h"

BonusTrick::BonusTrick(QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Trick}
{

}

BonusTrick::BonusTrick(const QString &name, QObject *parent)
    : BonusSource{parent}
    , m_type{Types::Bonus::Trick}
    , m_name{name}
{

}

Types::Bonus BonusTrick::type() const
{
    return m_type;
}

QString BonusTrick::name() const
{
    return m_name;
}
