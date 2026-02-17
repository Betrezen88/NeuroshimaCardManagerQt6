#include "DrugSource.h"

DrugSource::DrugSource(QObject *parent)
    : ItemSource{parent}
{}

DrugSource::DrugSource(const QString &name,
                       const QString &description,
                       const quint32 price,
                       const quint8 availability,
                       const QString &category,
                       QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
{

}

Types::Item DrugSource::type() const
{
    return m_type;
}
