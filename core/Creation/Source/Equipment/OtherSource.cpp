#include "OtherSource.h"

OtherSource::OtherSource(QObject *parent)
    : ItemSource{parent}
{}

OtherSource::OtherSource(const QString &name,
                         const QString &description,
                         const quint32 price,
                         const quint8 availability,
                         const QString &category,
                         QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
{

}

Types::Item OtherSource::type() const
{
    return m_type;
}
