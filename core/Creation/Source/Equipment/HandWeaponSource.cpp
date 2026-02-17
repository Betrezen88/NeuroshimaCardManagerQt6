#include "HandWeaponSource.h"

HandWeaponSource::HandWeaponSource(QObject *parent)
    : ItemSource{parent}
{}

HandWeaponSource::HandWeaponSource(const QString &name,
                                   const QString &description,
                                   const quint32 price,
                                   const quint8 availability, const QString &category,
                                   const QVector<HandWeaponBonusSource *> &bonuses,
                                   const QVector<HandWeaponDamageSource *> &damages,
                                   const QVector<WeaponSpecialSource *> &specials,
                                   WeaponRequirementSource *requirement,
                                   const quint8 penetration,
                                   QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
    , m_bonuses{bonuses}
    , m_damages{damages}
    , m_specials{specials}
    , m_requirement{requirement}
    , m_penetration{penetration}
{

}

Types::Item HandWeaponSource::type() const
{
    return m_type;
}

quint8 HandWeaponSource::penetration() const
{
    return m_penetration;
}

QQmlListProperty<HandWeaponBonusSource> HandWeaponSource::bonuses()
{
    return QQmlListProperty<HandWeaponBonusSource>(this, this,
                                                    &HandWeaponSource::bonusesCount,
                                                    &HandWeaponSource::bonus);
}

qsizetype HandWeaponSource::bonusesCount() const
{
    return m_bonuses.count();
}

HandWeaponBonusSource *HandWeaponSource::bonus(qsizetype index)
{
    return m_bonuses.at(index);
}

qsizetype HandWeaponSource::bonusesCount(QQmlListProperty<HandWeaponBonusSource> *list)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->bonusesCount();
}

HandWeaponBonusSource *HandWeaponSource::bonus(QQmlListProperty<HandWeaponBonusSource> *list, qsizetype index)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->bonus(index);
}

qsizetype HandWeaponSource::damageCount(QQmlListProperty<HandWeaponDamageSource> *list)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->damageCount();
}

HandWeaponDamageSource *HandWeaponSource::damage(QQmlListProperty<HandWeaponDamageSource> *list, qsizetype index)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->damage(index);
}

qsizetype HandWeaponSource::specialsCount(QQmlListProperty<WeaponSpecialSource> *list)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->specialsCount();
}

WeaponSpecialSource *HandWeaponSource::special(QQmlListProperty<WeaponSpecialSource> *list, qsizetype index)
{
    return reinterpret_cast<HandWeaponSource*>(list->data)->special(index);
}

QQmlListProperty<HandWeaponDamageSource> HandWeaponSource::damages()
{
    return QQmlListProperty<HandWeaponDamageSource>(this, this,
                                                    &HandWeaponSource::damageCount,
                                                    &HandWeaponSource::damage);
}

qsizetype HandWeaponSource::damageCount() const
{
    return m_damages.count();
}

HandWeaponDamageSource *HandWeaponSource::damage(qsizetype index)
{
    return m_damages.at(index);
}

QQmlListProperty<WeaponSpecialSource> HandWeaponSource::specials()
{
    return QQmlListProperty<WeaponSpecialSource>(this, this,
                                                 &HandWeaponSource::specialsCount,
                                                 &HandWeaponSource::special);
}

qsizetype HandWeaponSource::specialsCount() const
{
    return m_specials.count();
}

WeaponSpecialSource *HandWeaponSource::special(qsizetype index)
{
    return m_specials.at(index);
}

WeaponRequirementSource *HandWeaponSource::requirement() const
{
    return m_requirement;
}
