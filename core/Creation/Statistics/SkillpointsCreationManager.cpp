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

quint8 SkillpointsCreationManager::generalSkillpoints() const
{
    return m_general.current;
}

quint8 SkillpointsCreationManager::specializationSkillpoints() const
{
    return m_specializations.current;
}

quint8 SkillpointsCreationManager::specializationSkillpointsMax() const
{
    return m_specializations.max;
}

void SkillpointsCreationManager::setSpecializationSkillpointsMax(quint8 newSpecializationSkillpointsMax)
{
    if (m_specializations.max == newSpecializationSkillpointsMax)
        return;
    m_specializations.max = newSpecializationSkillpointsMax;
    emit specializationSkillpointsMaxChanged();
}

quint8 SkillpointsCreationManager::tricksCount() const
{
    return m_trickCount;
}

bool SkillpointsCreationManager::canSkillpackBeBought(const QString &specialization)
{
    return availablePoints(specialization) >= 5;
}

bool SkillpointsCreationManager::canSkillBeIncreased(const QString &specialization, const quint8 value)
{
    return availablePoints(specialization) >= value;
}

bool SkillpointsCreationManager::canTrickBeBought()
{
    return m_trickCount == 0;
}

bool SkillpointsCreationManager::canReputationBeBougth()
{
    return m_availableReputationPoints > 0;
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

void SkillpointsCreationManager::onSkillBought(const QStringList &specializations, const quint8 value)
{
    const quint8 cost = buySkillCost(value);
    if ( specializations.contains(m_specialization) ) {
        const quint8 left = m_specializations.current - cost;
        setSpecializationSkillpoints( left < 0 ? 0 : m_specializations.current - cost);
        setGeneralSkillpoints( left < 0 ? m_general.current + left : m_general.current );
    }
    else {
        setGeneralSkillpoints( m_general.current - cost );
    }
}

void SkillpointsCreationManager::onSkillSold(const QStringList &specializations, const quint8 value)
{
    const quint8 cost = sellSkillCost(value);
    if ( specializations.contains(m_specialization) ) {
        const quint8 above = m_specializations.current + cost - m_specializations.max;
        setSpecializationSkillpoints( above < 0 ? m_specializations.current + cost : m_specializations.max);
        setGeneralSkillpoints( above > 0 ? m_general.current + above : m_general.current );
    }
    else {
        setGeneralSkillpoints( m_general.current + cost );
    }
}

void SkillpointsCreationManager::onTrickBought()
{
    ++m_trickCount;
    emit tricksCountChanged();
}

void SkillpointsCreationManager::onTrickSold()
{
    --m_trickCount;
    emit tricksCountChanged();
}

void SkillpointsCreationManager::onReputationBougth()
{
    --m_availableReputationPoints;
    emit availableReputationPointsChanged();
}

void SkillpointsCreationManager::onReputationSold()
{
    ++m_availableReputationPoints;
    emit availableReputationPointsChanged();
}

quint8 SkillpointsCreationManager::availablePoints(const QString &specialization)
{
    return m_specialization == specialization ? m_general.current + m_specializations.current : m_general.current;
}

quint8 SkillpointsCreationManager::buySkillCost(const quint8 level)
{
    if ( 1 == level ) {
        return 3;
    }
    return level;
}

quint8 SkillpointsCreationManager::sellSkillCost(const quint8 level)
{
    if ( 0 == level - 1 ) {
        return 3;
    }
    return level;
}

void SkillpointsCreationManager::setGeneralSkillpoints(const quint8 newGeneralSkillpoints)
{
    if ( m_general.current == newGeneralSkillpoints )
        return;

    m_general.current = newGeneralSkillpoints;
    emit generalSkillpointsChanged();
}

void SkillpointsCreationManager::setSpecializationSkillpoints(const quint8 newSpecializationSkillpoints)
{
    if ( m_specializations.current == newSpecializationSkillpoints )
        return;

    m_specializations.current = newSpecializationSkillpoints;
    emit specializationSkillpointsChanged();
}

quint8 SkillpointsCreationManager::availableReputationPoints() const
{
    return m_availableReputationPoints;
}

bool SkillpointsCreationManager::isReputationGeneralPoint() const
{
    return m_isReputationGeneralPoint;
}

void SkillpointsCreationManager::setIsReputationGeneralPoint(bool newIsReputationGeneralPoint)
{
    if (m_isReputationGeneralPoint == newIsReputationGeneralPoint)
        return;
    m_isReputationGeneralPoint = newIsReputationGeneralPoint;
    emit isReputationGeneralPointChanged();
}
