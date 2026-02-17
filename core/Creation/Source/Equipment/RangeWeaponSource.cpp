#include "RangeWeaponSource.h"

RangeWeaponSource::RangeWeaponSource(QObject *parent)
    : ItemSource{parent}
{}

RangeWeaponSource::RangeWeaponSource(const QString &name,
                                     const QString &description,
                                     const quint32 price,
                                     const quint8 availability,
                                     const QString &category,
                                     const QString &damage,
                                     const quint8 penetration,
                                     const QStringList &ammunition,
                                     const quint8 firerate,
                                     const QVector<quint32> &magazine,
                                     WeaponRequirementSource *requirement,
                                     const QVector<WeaponSpecialSource*>& specials,
                                     QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
    , m_damage{damage}
    , m_penetration{penetration}
    , m_ammunition{ammunition}
    , m_firerate{firerate}
    , m_magazine{magazine}
    , m_requirement{requirement}
    , m_specials{specials}
{

}

Types::Item RangeWeaponSource::type() const
{
    return m_type;
}

QString RangeWeaponSource::damage() const
{
    return m_damage;
}

quint8 RangeWeaponSource::penetration() const
{
    return m_penetration;
}

QStringList RangeWeaponSource::ammunition() const
{
    return m_ammunition;
}

quint8 RangeWeaponSource::firerate() const
{
    return m_firerate;
}

QVector<quint32> RangeWeaponSource::magazine() const
{
    return m_magazine;
}

WeaponRequirementSource *RangeWeaponSource::requirement() const
{
    return m_requirement;
}

QQmlListProperty<WeaponSpecialSource> RangeWeaponSource::specials()
{
    return QQmlListProperty<WeaponSpecialSource>(this, this,
                                                &RangeWeaponSource::specialsCount,
                                                &RangeWeaponSource::special);
}

qsizetype RangeWeaponSource::specialsCount() const
{
    return m_specials.count();
}

WeaponSpecialSource *RangeWeaponSource::special(qsizetype index)
{
    return m_specials.at(index);
}

qsizetype RangeWeaponSource::specialsCount(QQmlListProperty<WeaponSpecialSource> *list)
{
    return reinterpret_cast<RangeWeaponSource*>(list->data)->specialsCount();
}

WeaponSpecialSource *RangeWeaponSource::special(QQmlListProperty<WeaponSpecialSource> *list, qsizetype index)
{
    return reinterpret_cast<RangeWeaponSource*>(list->data)->special(index);
}
