#include "SpecializationSource.h"

SpecializationSource::SpecializationSource(QObject *parent)
    : QObject{parent}
{

}

SpecializationSource::SpecializationSource(const QString &name, const QString &description, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
{

}

QString SpecializationSource::name() const
{
    return m_name;
}

QString SpecializationSource::description() const
{
    return m_description;
}
