#include "Place.h"

Place::Place(QObject *parent)
    : QObject{parent}
{

}

Place::Place(const PlaceData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_value(data.value)
{

}

QString Place::name() const
{
    return m_name;
}

int Place::value() const
{
    return m_value;
}

PlaceData Place::data() const
{
    return PlaceData{
        .name = m_name,
        .value = m_value
    };
}
