#include "AttributeCreation.h"

#include <QDebug>

AttributeCreation::AttributeCreation(QObject *parent)
    : QObject{parent}
{

}

AttributeCreation::AttributeCreation(AttributeSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{
    for ( SkillpackSource* skillpack: const_cast<const AttributeSource*>(source)->skillpacks() ) {
        m_skillpacks.append( new SkillpackCreation{skillpack, this} );
    }
}

AttributeSource *AttributeCreation::source() const
{
    return m_source;
}

const QVector<SkillpackCreation *> &AttributeCreation::skillpacks() const
{
    return m_skillpacks;
}

QQmlListProperty<SkillpackCreation> AttributeCreation::skillpacks()
{
    return QQmlListProperty<SkillpackCreation>(this, this,
                                               &AttributeCreation::skillpacksCount,
                                               &AttributeCreation::skillpack);
}

qsizetype AttributeCreation::skillpacksCount() const
{
    return m_skillpacks.count();
}

SkillpackCreation *AttributeCreation::skillpack(qsizetype index)
{
    return m_skillpacks.at(index);
}

int AttributeCreation::value() const
{
    return m_baseValue + m_bonus;
}

int AttributeCreation::baseValue() const
{
    return m_baseValue;
}

void AttributeCreation::setBaseValue(int newBaseValue)
{
    if (m_baseValue == newBaseValue)
        return;
    m_baseValue = newBaseValue;
    emit baseValueChanged();
    emit valueChanged();
}

int AttributeCreation::bonus() const
{
    return m_bonus;
}

void AttributeCreation::setBonus(int newBonus)
{
    if (m_bonus == newBonus)
        return;
    m_bonus = newBonus;
    emit bonusChanged();
}

qsizetype AttributeCreation::skillpacksCount(QQmlListProperty<SkillpackCreation> *list)
{
    return reinterpret_cast<AttributeCreation*>(list->data)->skillpacksCount();
}

SkillpackCreation *AttributeCreation::skillpack(QQmlListProperty<SkillpackCreation> *list, qsizetype index)
{
    return reinterpret_cast<AttributeCreation*>(list->data)->skillpack(index);
}
