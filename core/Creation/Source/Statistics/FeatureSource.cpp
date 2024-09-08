#include "FeatureSource.h"

FeatureSource::FeatureSource(QObject *parent)
    : QObject{parent}
{

}

FeatureSource::FeatureSource(const QString &name, const QString &description, BonusSource *bonus, QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_bonus{bonus}
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
