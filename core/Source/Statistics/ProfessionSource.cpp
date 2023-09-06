#include "ProfessionSource.h"

ProfessionSource::ProfessionSource(QObject *parent)
    : QObject{parent}
{

}

ProfessionSource::ProfessionSource(const QString &name,
                                   const QString &description,
                                   const QString &quote,
                                   const QVector<FeatureSource *> &features,
                                   QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_quote{quote}
    , m_features{features}
{

}

QString ProfessionSource::name() const
{
    return m_name;
}

QString ProfessionSource::description() const
{
    return m_description;
}

QString ProfessionSource::quote() const
{
    return m_quote;
}

QQmlListProperty<FeatureSource> ProfessionSource::features()
{
    return QQmlListProperty<FeatureSource>(this, this,
                                           &ProfessionSource::featuresCount,
                                           &ProfessionSource::feature);
}

qsizetype ProfessionSource::featuresCount() const
{
    return m_features.count();
}

FeatureSource *ProfessionSource::feature(qsizetype index)
{
    return m_features.at(index);
}

qsizetype ProfessionSource::featuresCount(QQmlListProperty<FeatureSource> *list)
{
    return reinterpret_cast<ProfessionSource*>(list->data)->featuresCount();
}

FeatureSource *ProfessionSource::feature(QQmlListProperty<FeatureSource> *list, qsizetype index)
{
    return reinterpret_cast<ProfessionSource*>(list->data)->feature(index);
}
