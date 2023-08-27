#include "OriginSource.h"

OriginSource::OriginSource(QObject *parent)
    : QObject{parent}
{

}

OriginSource::OriginSource(const QString &name,
                           const QString &description,
                           AttributeBonusSource* bonus,
                           const QVector<FeatureSource *>& features,
                           QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_bonus{bonus}
    , m_features{features}
{

}

QString OriginSource::name() const
{
    return m_name;
}

QString OriginSource::description() const
{
    return m_description;
}

QQmlListProperty<FeatureSource> OriginSource::features()
{
    return QQmlListProperty<FeatureSource>(this, this,
                                           &OriginSource::featuresCount,
                                           &OriginSource::feature);
}

FeatureSource *OriginSource::feature(qsizetype index)
{
    return m_features.at(index);
}

qsizetype OriginSource::featuresCount() const
{
    return m_features.count();
}

AttributeBonusSource *OriginSource::bonus() const
{
    return m_bonus;
}

FeatureSource *OriginSource::feature(QQmlListProperty<FeatureSource> *list, qsizetype index)
{
    return reinterpret_cast<OriginSource*>(list->data)->feature(index);
}

qsizetype OriginSource::featuresCount(QQmlListProperty<FeatureSource> *list)
{
    return reinterpret_cast<OriginSource*>(list->data)->featuresCount();
}
