#include "OtherSkillSource.h"

OtherSkillSource::OtherSkillSource(QObject *parent)
    : QObject{parent}
{

}

OtherSkillSource::OtherSkillSource(const QString &name, const QString &description, const QString &attribute, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_attribute{attribute}
{

}

QString OtherSkillSource::name() const
{
    return m_name;
}

QString OtherSkillSource::description() const
{
    return m_description;
}

QString OtherSkillSource::attribute() const
{
    return m_attribute;
}
