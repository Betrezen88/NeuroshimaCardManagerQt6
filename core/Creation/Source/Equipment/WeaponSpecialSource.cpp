#include "WeaponSpecialSource.h"

WeaponSpecialSource::WeaponSpecialSource(QObject *parent)
    : QObject{parent}
{}

WeaponSpecialSource::WeaponSpecialSource(const QString &name, const QString &description, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
{

}

QString WeaponSpecialSource::name() const
{
    return m_name;
}

QString WeaponSpecialSource::description() const
{
    return m_description;
}
