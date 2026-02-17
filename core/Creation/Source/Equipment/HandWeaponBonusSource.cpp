#include "HandWeaponBonusSource.h"

HandWeaponBonusSource::HandWeaponBonusSource(QObject *parent)
    : QObject{parent}
{}

HandWeaponBonusSource::HandWeaponBonusSource(const QString &name, const quint8 value, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_value{value}
{

}

QString HandWeaponBonusSource::name() const
{
    return m_name;
}

quint8 HandWeaponBonusSource::value() const
{
    return m_value;
}
