#include "FeatureSource.h"

FeatureSource::FeatureSource(QObject *parent)
    : QObject{parent}
{

}

FeatureSource::FeatureSource(const QString &name, const QString &description, const BonusSource *bonus, QObject *parent)
{

}

QString FeatureSource::name() const
{
    return m_name;
}

QString FeatureSource::description() const
{
    return m_description;
}

BonusSource *FeatureSource::bonus() const
{
    return m_bonus;
}
