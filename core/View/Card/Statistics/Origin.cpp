#include "Origin.h"
#include "Feature.h"

Origin::Origin(QObject *parent)
    : QObject{parent}
{

}

Origin::Origin(const OriginData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
    , m_feature(new Feature(data.feature, this))
{

}

QString Origin::name() const
{
    return m_name;
}

QString Origin::description() const
{
    return m_description;
}

Feature *Origin::feature() const
{
    return m_feature.get();
}

OriginData Origin::data() const
{
    return OriginData{
        .name = m_name,
        .description = m_description,
        .feature = m_feature->data()
    };
}
