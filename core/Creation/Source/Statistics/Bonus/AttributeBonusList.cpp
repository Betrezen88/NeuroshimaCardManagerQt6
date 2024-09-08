#include "AttributeBonusList.h"

AttributeBonusList::AttributeBonusList(QObject *parent)
    : AttributeBonusSource{parent}
    , m_type{Types::AttributeBonus::List}
{

}

AttributeBonusList::AttributeBonusList(const QStringList &list, const int value, QObject *parent)
    : AttributeBonusSource{value, parent}
    , m_list{list}
    , m_type{Types::AttributeBonus::List}
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

QString AttributeBonusList::name() const
{
    return m_name;
}

void AttributeBonusList::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    emit nameWasChanged(m_name, newName);
    m_name = newName;
    emit nameChanged();
}
