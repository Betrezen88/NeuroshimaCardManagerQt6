#include "SkillCreationSingle.h"

SkillCreationSingle::SkillCreationSingle(QObject *parent)
    : SkillCreation{parent}
    , m_type{TypesCreation::Skill::Single}
{

}

SkillCreationSingle::SkillCreationSingle(SkillSource *source, QObject *parent)
    : SkillCreation{source, parent}
    , m_type{TypesCreation::Skill::Single}
{

}

TypesCreation::Skill SkillCreationSingle::type() const
{
    return m_type;
}

SkillSource *SkillCreationSingle::source() const
{
    return m_source;
}
