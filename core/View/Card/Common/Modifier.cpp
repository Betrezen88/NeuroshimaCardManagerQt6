#include "Modifier.h"

Modifier::Modifier(QObject *parent)
    : QObject{parent}
{

}

Modifier::Modifier(const ModifierData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_value(data.value)
    , m_type(data.type)
{

}

Types::Modifier Modifier::type() const
{
    return m_type;
}

QString Modifier::name() const
{
    return m_name;
}

int Modifier::value() const
{
    return m_value;
}

ModifierData Modifier::data() const
{
    return ModifierData{
        .name = m_name,
        .value = m_value,
        .type = m_type
    };
}
