#include "AttributeBonusList.h"

AttributeBonusList::AttributeBonusList(QObject *parent)
    : AttributeBonusSource{parent}
{

}

AttributeBonusList::AttributeBonusList(const QStringList &list, const int value, QObject *parent)
    : AttributeBonusSource{value, parent}
    , m_list{list}
{

}

Types::AttributeBonus AttributeBonusList::type() const
{
    return m_type;
}

QStringList AttributeBonusList::list() const
{
    return m_list;
}
