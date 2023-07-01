#include "Feature.h"

Feature::Feature(QObject *parent)
    : QObject{parent}
{

}

Feature::Feature(const FeatureData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
{

}

QString Feature::name() const
{
    return m_name;
}

QString Feature::description() const
{
    return m_description;
}

FeatureData Feature::data() const
{
    return FeatureData{
        .name = m_name,
        .description = m_description
    };
}
