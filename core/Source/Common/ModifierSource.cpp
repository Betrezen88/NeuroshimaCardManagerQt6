#include "ModifierSource.h"

ModifierSource::ModifierSource(QObject *parent)
    : QObject{parent}
{

}

ModifierSource::ModifierSource(const Types::Modifier type, const QString &name, const int value, QObject *parent)
    : QObject{parent}
    , m_type{type}
    , m_name{name}
    , m_value{value}
{

}

Types::Modifier ModifierSource::type() const
{
    return m_type;
}

QString ModifierSource::name() const
{
    return m_name;
}

int ModifierSource::value() const
{
    return m_value;
}
