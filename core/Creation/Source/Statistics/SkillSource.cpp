#include "SkillSource.h"

SkillSource::SkillSource(QObject *parent)
    : QObject{parent}
{

}

SkillSource::SkillSource(const QString &name, const QString &description, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
{

}

QString SkillSource::name() const
{
    return m_name;
}

QString SkillSource::description() const
{
    return m_description;
}
