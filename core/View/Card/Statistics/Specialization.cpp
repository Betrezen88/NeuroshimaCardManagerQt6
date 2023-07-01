#include "Specialization.h"

Specialization::Specialization(QObject *parent)
    : QObject{parent}
{

}

Specialization::Specialization(const SpecializationData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
{

}

QString Specialization::name() const
{
    return m_name;
}

QString Specialization::description() const
{
    return m_description;
}

SpecializationData Specialization::data() const
{
    return SpecializationData{
        .name = m_name,
        .description = m_description
    };
}
