#include "SkillpackCreation.h"

SkillpackCreation::SkillpackCreation(QObject *parent)
    : QObject{parent}
{

}

SkillpackCreation::SkillpackCreation(SkillpackSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{
    for ( SkillSource* skill: const_cast<const SkillpackSource*>(source)->skills() ) {
        SkillCreation* pSkill = new SkillCreation(skill, this);
        connect(pSkill, &SkillCreation::increased, this, [this](const int value){
            emit skillIncreased(m_source->specializations(), value);
        });
        connect(pSkill, &SkillCreation::decreased, this, [this](const int value){
            emit skillDecreased(m_source->specializations(), value);
        });

        m_skills.append( pSkill );
    }
}

SkillpackSource *SkillpackCreation::source() const
{
    return m_source;
}

QQmlListProperty<SkillCreation> SkillpackCreation::skills()
{
    return QQmlListProperty<SkillCreation>(this, this,
                                           &SkillpackCreation::skillsCount,
                                           &SkillpackCreation::skill);
}

qsizetype SkillpackCreation::skillsCount() const
{
    return m_skills.count();
}

SkillCreation *SkillpackCreation::skill(qsizetype index)
{
    return m_skills.at(index);
}

bool SkillpackCreation::bought() const
{
    return m_bought;
}

void SkillpackCreation::buy()
{
    m_bought = true;
    emit boughtChanged(m_bought);
    increaseSkillsBy(1);
}

void SkillpackCreation::sell()
{
    m_bought = false;
    emit boughtChanged(m_bought);
    decreaseSkillsBy(1);
}

void SkillpackCreation::increaseSkillsBy(const int value)
{
    for ( SkillCreation* skill: m_skills ) {
        skill->increasedBy(value);
    }
}

void SkillpackCreation::decreaseSkillsBy(const int value)
{
    for ( SkillCreation* skill: m_skills ) {
        skill->decreaseBy(value);
    }
}

qsizetype SkillpackCreation::skillsCount(QQmlListProperty<SkillCreation> *list)
{
    return reinterpret_cast<SkillpackCreation*>(list->data)->skillsCount();
}

SkillCreation *SkillpackCreation::skill(QQmlListProperty<SkillCreation> *list, qsizetype index)
{
    return reinterpret_cast<SkillpackCreation*>(list->data)->skill(index);
}
