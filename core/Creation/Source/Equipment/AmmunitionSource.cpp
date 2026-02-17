#include "AmmunitionSource.h"

AmmunitionSource::AmmunitionSource(QObject *parent)
    : ItemSource{parent}
{}

AmmunitionSource::AmmunitionSource(const QString &name,
                                   const QString &description,
                                   const quint32 price,
                                   const quint8 availability,
                                   const QString &category,
                                   QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
{

}

Types::Item AmmunitionSource::type() const
{
    return m_type;
}
