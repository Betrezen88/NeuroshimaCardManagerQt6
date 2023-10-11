#include "SkillpackCreation.h"

SkillpackCreation::SkillpackCreation(QObject *parent)
    : QObject{parent}
{

}

SkillpackCreation::SkillpackCreation(SkillpackSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{
    connect(this, &SkillpackCreation::boughtChanged, this, &SkillpackCreation::onBoughtChanged);
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

void SkillpackCreation::setBought(const bool newBougth)
{
    if ( m_bought == newBougth )
        return;

    m_bought = newBougth;
    emit boughtChanged(m_bought);
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

void SkillpackCreation::onBoughtChanged(const bool bougth)
{
    if ( bougth ) {
        increaseSkillsBy(1);
    }
    else {
        decreaseSkillsBy(1);
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
