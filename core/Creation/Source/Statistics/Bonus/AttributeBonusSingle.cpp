#include "AttributeBonusSingle.h"

AttributeBonusSingle::AttributeBonusSingle(QObject *parent)
    : AttributeBonusSource{parent}
    , m_type{Types::AttributeBonus::Single}
{

}

AttributeBonusSingle::AttributeBonusSingle(const QString &name, const int val, QObject *parent)
    : AttributeBonusSource{val, parent}
    , m_type{Types::AttributeBonus::Single}
    , m_name{name}
{

}

QString AttributeBonusSingle::name() const
{
    return m_name;
}

Types::AttributeBonus AttributeBonusSingle::type() const
{
    return m_type;
}
