#include "Skill.h"

Skill::Skill(QObject *parent)
    : QObject{parent}
{

}

Skill::Skill(const SkillData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_value(data.value)
    , m_used(data.used)
{

}

QString Skill::name() const
{
    return m_name;
}

int Skill::value() const
{
    return m_value;
}

bool Skill::used() const
{
    return m_used;
}

void Skill::setUsed(bool newUsed)
{
    if (m_used == newUsed)
        return;
    m_used = newUsed;
    emit usedChanged();
}

SkillData Skill::data() const
{
    return SkillData{
        .name = m_name,
        .value = m_value,
        .used = m_used
    };
}
