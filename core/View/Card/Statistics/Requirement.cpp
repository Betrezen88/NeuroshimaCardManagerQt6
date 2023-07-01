#include "Requirement.h"

Requirement::Requirement(QObject *parent)
    : QObject{parent}
{

}

Requirement::Requirement(const RequirementData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_value(data.value)
    , m_optional(data.optional)
    , m_type(data.type)
{

}

QString Requirement::name() const
{
    return m_name;
}

int Requirement::value() const
{
    return m_value;
}

bool Requirement::optional() const
{
    return m_optional;
}

Types::Requirement Requirement::type() const
{
    return m_type;
}

RequirementData Requirement::data() const
{
    return RequirementData{
        .name = m_name,
        .value = m_value,
        .optional = m_optional,
        .type = m_type
    };
}
