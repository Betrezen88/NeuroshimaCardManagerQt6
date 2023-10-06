#include "SkillpointsCreationManager.h"

SkillpointsCreationManager::SkillpointsCreationManager(QObject *parent)
    : QObject{parent}
{

}

QString SkillpointsCreationManager::specialization() const
{
    return m_specialization;
}

void SkillpointsCreationManager::setSpecialization(const QString &newSpecialization)
{
    if (m_specialization == newSpecialization)
        return;
    m_specialization = newSpecialization;
    emit specializationChanged();
}

int SkillpointsCreationManager::generalSkillpoints() const
{
    return m_general.current;
}

int SkillpointsCreationManager::specializationSkillpoints() const
{
    return m_specializations.current;
}

int SkillpointsCreationManager::specializationSkillpointsMax() const
{
    return m_specializations.max;
}

void SkillpointsCreationManager::setSpecializationSkillpointsMax(int newSpecializationSkillpointsMax)
{
    if (m_specializations.max == newSpecializationSkillpointsMax)
        return;
    m_specializations.max = newSpecializationSkillpointsMax;
    emit specializationSkillpointsMaxChanged();
}

bool SkillpointsCreationManager::canSkillpackBeBought(const QString &specialization)
{
    return availablePoints(specialization) >= 5;
}

bool SkillpointsCreationManager::canSkillBeIncreased(const QString &specialization, const int value)
{
    return availablePoints(specialization) >= value;
}

void SkillpointsCreationManager::onSkillpackBought(const QStringList &specializations)
{
    if ( specializations.contains(m_specialization) ) {
        const int left = m_specializations.current - m_skillpackCost;
        setSpecializationSkillpoints( left < 0 ? 0 : m_specializations.current - m_skillpackCost );
        setGeneralSkillpoints( left < 0 ? m_general.current + left : m_general.current );
    }
    else {
        setGeneralSkillpoints( m_general.current - m_skillpackCost );
    }
}

void SkillpointsCreationManager::onSkillpackSold(const QStringList &specializations)
{
    if ( specializations.contains(m_specialization) ) {
        const int above = m_specializations.current + 5 - m_specializations.max;
        setSpecializationSkillpoints( above < 0 ? m_specializations.current + 5 : m_specializations.max);
        setGeneralSkillpoints( above < 0 ? m_general.current + qAbs(above) : m_general.current);
    }
    else {
        setGeneralSkillpoints( m_general.current + 5 );
    }
}

void SkillpointsCreationManager::onSkillBought(const QStringList &specializations, const int value)
{
    const int cost = buySkillCost(value);
    if ( specializations.contains(m_specialization) ) {
        const int left = m_specializations.current - cost;
        setSpecializationSkillpoints( left < 0 ? 0 : m_specializations.current - cost);
        setGeneralSkillpoints( left < 0 ? m_general.current + left : m_general.current );
    }
    else {
        setGeneralSkillpoints( m_general.current - cost );
    }
}

void SkillpointsCreationManager::onSkillSold(const QStringList &specializations, const int value)
{
    const int cost = sellSkillCost(value);
    if ( specializations.contains(m_specialization) ) {
        const int above = m_specializations.current + cost - m_specializations.max;
        setSpecializationSkillpoints( above < 0 ? m_specializations.current + cost : m_specializations.max);
        setGeneralSkillpoints( above > 0 ? m_general.current + above : m_general.current );
    }
    else {
        setGeneralSkillpoints( m_general.current + cost );
    }
}

int SkillpointsCreationManager::availablePoints(const QString &specialization)
{
    return m_specialization == specialization ? m_general.current + m_specializations.current : m_general.current;
}

int SkillpointsCreationManager::buySkillCost(const int level)
{
    if ( 1 == level ) {
        return 3;
    }
    return level;
}

int SkillpointsCreationManager::sellSkillCost(const int level)
{
    if ( 0 == level - 1 ) {
        return 3;
    }
    return level;
}

void SkillpointsCreationManager::setGeneralSkillpoints(const int newGeneralSkillpoints)
{
    if ( m_general.current == newGeneralSkillpoints )
        return;

    m_general.current = newGeneralSkillpoints;
    emit generalSkillpointsChanged();
}

void SkillpointsCreationManager::setSpecializationSkillpoints(const int newSpecializationSkillpoints)
{
    if ( m_specializations.current == newSpecializationSkillpoints )
        return;

    m_specializations.current = newSpecializationSkillpoints;
    emit specializationSkillpointsChanged();
}
