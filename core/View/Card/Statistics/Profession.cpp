#include "Profession.h"

#include "Feature.h"

Profession::Profession(QObject *parent)
    : QObject{parent}
{

}

Profession::Profession(const ProfessionData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
    , m_feature(new Feature(data.feature, this))
{

}

QString Profession::name() const
{
    return m_name;
}

QString Profession::description() const
{
    return m_description;
}

Feature *Profession::feature() const
{
    return m_feature;
}

ProfessionData Profession::data() const
{
    return ProfessionData{
        .name = m_name,
        .description = m_description,
        .feature = m_feature->data()
    };
}
