#include "SkillpackCreationGeneral.h"
#include "SkillCreationSingle.h"

SkillpackCreationGeneral::SkillpackCreationGeneral(QObject *parent)
    : SkillpackCreation{parent}
    , m_type{TypesCreation::Skillpack::General}
{

}

SkillpackCreationGeneral::SkillpackCreationGeneral(SkillpackSource *source, QObject *parent)
    : SkillpackCreation{source, parent}
    , m_type{TypesCreation::Skillpack::General}
{
    for ( SkillSource* skill: const_cast<const SkillpackSource*>(source)->skills() ) {
        SkillCreation* pSkill = new SkillCreationSingle(skill, this);

        connect(pSkill, &SkillCreation::increased, this, [this](const int value){
            emit skillIncreased(m_source->specializations(), value);
        });
        connect(pSkill, &SkillCreation::decreased, this, [this](const int value){
            emit skillDecreased(m_source->specializations(), value);
        });

        m_skills.append( pSkill );
    }
}

TypesCreation::Skillpack SkillpackCreationGeneral::type() const
{
    return m_type;
}
