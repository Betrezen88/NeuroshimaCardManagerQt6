#include "SkillpackCreationChoosable.h"
#include "SkillCreationList.h"

SkillpackCreationChoosable::SkillpackCreationChoosable(QObject *parent)
    : SkillpackCreation{parent}
    , m_type{TypesCreation::Skillpack::Choosable}
{

}

SkillpackCreationChoosable::SkillpackCreationChoosable(SkillpackSource *source, QObject *parent)
    : SkillpackCreation{source, parent}
    , m_type{TypesCreation::Skillpack::Choosable}
{
    const QVector<SkillSource*>& sources = const_cast<const SkillpackSource*>(source)->skills();

    for ( int i{0}; i<3; ++i ) {
        SkillCreationList* pSkill = new SkillCreationList{sources, this};
        pSkill->setSelected(sources.at(i)->name());

        connect(pSkill, &SkillCreation::increased, this, [this](const int value){
            emit skillIncreased(m_source->specializations(), value);
        });
        connect(pSkill, &SkillCreation::decreased, this, [this](const int value){
            emit skillDecreased(m_source->specializations(), value);
        });
        connect(pSkill, &SkillCreationList::skillChanged, this, &SkillpackCreationChoosable::onSkillChanged);

        m_skills.append( pSkill );
    }
}

TypesCreation::Skillpack SkillpackCreationChoosable::type() const
{
    return m_type;
}

void SkillpackCreationChoosable::onSkillChanged(const SkillCreationList *skill)
{
    auto found = std::find_if(m_skills.constBegin(), m_skills.constEnd(), [&skill](const SkillCreation* skillCreation){
        return skillCreation != skill && skillCreation->source()->name() == skill->selected();
    });

    if ( found != m_skills.constEnd() ) {
        const QStringList& list = skill->list();
        QStringList taken;
        std::for_each(m_skills.constBegin(), m_skills.constEnd(), [&skill, &taken](const SkillCreation* skillCreation){
            if ( skillCreation != skill ) taken << skillCreation->source()->name();
        });

        auto skillName = std::find_if(list.constBegin(), list.constEnd(), [&taken](const QString& name){
            return !taken.contains(name);
        });

        if ( skillName != list.constEnd() ) {
            static_cast<SkillCreationList*>(*found)->setSelected(*skillName);
        }
    }
}
