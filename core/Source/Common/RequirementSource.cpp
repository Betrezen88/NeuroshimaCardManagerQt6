#include "RequirementSource.h"

RequirementSource::RequirementSource(QObject *parent)
    : QObject{parent}
{

}

RequirementSource::RequirementSource(const Types::Requirement type,
                                     const QString &name,
                                     const int value,
                                     const bool optional,
                                     QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_value{value}
    , m_optional{optional}
{

}

Types::Requirement RequirementSource::type() const
{
    return m_type;
}

QString RequirementSource::name() const
{
    return m_name;
}

int RequirementSource::value() const
{
    return m_value;
}

bool RequirementSource::optional() const
{
    return m_optional;
}
