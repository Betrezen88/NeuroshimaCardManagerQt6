#include "ShieldSource.h"

ShieldSource::ShieldSource(QObject *parent)
    : ItemSource{parent}
{}

ShieldSource::ShieldSource(const QString &name,
                           const QString &description,
                           const quint32 price,
                           const quint8 availability, const QString &category,
                           const quint8 durability,
                           WeaponRequirementSource *requirement,
                           const QVector<HandWeaponBonusSource *> &bonuses,
                           HandWeaponDamageSource *damage,
                           QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
    , m_durability{durability}
    , m_requirement{requirement}
    , m_bonuses{bonuses}
    , m_damage{damage}
{

}

Types::Item ShieldSource::type() const
{
    return m_type;
}

quint8 ShieldSource::durability() const
{
    return m_durability;
}

WeaponRequirementSource* ShieldSource::requirement() const
{
    return m_requirement;
}

QQmlListProperty<HandWeaponBonusSource> ShieldSource::bonuses()
{
    return QQmlListProperty<HandWeaponBonusSource>(this, this,
                                                    &ShieldSource::bonusesCount,
                                                    &ShieldSource::bonus);
}

qsizetype ShieldSource::bonusesCount() const
{
    return m_bonuses.count();
}

HandWeaponBonusSource *ShieldSource::bonus(qsizetype index)
{
    return m_bonuses.at(index);
}

HandWeaponDamageSource* ShieldSource::damage() const
{
    return m_damage;
}

qsizetype ShieldSource::bonusesCount(QQmlListProperty<HandWeaponBonusSource> *list)
{
    return reinterpret_cast<ShieldSource*>(list->data)->bonusesCount();
}

HandWeaponBonusSource *ShieldSource::bonus(QQmlListProperty<HandWeaponBonusSource> *list, qsizetype index)
{
    return reinterpret_cast<ShieldSource*>(list->data)->bonus(index);
}
