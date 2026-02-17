#include "WeaponModSource.h"

WeaponModSource::WeaponModSource(QObject *parent)
    : ItemSource{parent}
{}

WeaponModSource::WeaponModSource(const QString &name,
                                 const QString &description,
                                 const quint32 price,
                                 const quint8 availability,
                                 const QString &category,
                                 QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
{

}

Types::Item WeaponModSource::type() const
{
    return m_type;
}
