#include "HandWeaponDamageSource.h"

HandWeaponDamageSource::HandWeaponDamageSource(QObject *parent)
    : QObject{parent}
{}

HandWeaponDamageSource::HandWeaponDamageSource(const QString &attribute, const quint8 value, const QStringList &wounds, QObject *parent)
    : QObject{parent}
    , m_attribute{attribute}
    , m_value{value}
    , m_wounds{wounds}
{

}

QString HandWeaponDamageSource::attribute() const
{
    return m_attribute;
}

quint8 HandWeaponDamageSource::value() const
{
    return m_value;
}

QStringList HandWeaponDamageSource::wounds() const
{
    return m_wounds;
}
