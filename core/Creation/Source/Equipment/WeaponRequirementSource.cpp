#include "WeaponRequirementSource.h"

WeaponRequirementSource::WeaponRequirementSource(QObject *parent)
    : QObject{parent}
{}

WeaponRequirementSource::WeaponRequirementSource(const QString &attribute, const quint8 value, QObject *parent)
    : QObject{parent}
    , m_attribute{attribute}
    , m_value{value}
{

}

QString WeaponRequirementSource::attribute() const
{
    return m_attribute;
}

quint8 WeaponRequirementSource::value() const
{
    return m_value;
}
