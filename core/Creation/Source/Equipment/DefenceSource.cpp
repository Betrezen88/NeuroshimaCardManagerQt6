#include "DefenceSource.h"

DefenceSource::DefenceSource(QObject *parent)
    : QObject{parent}
{}

DefenceSource::DefenceSource(const QString &location, const quint8 value, const quint8 cutting, QObject *parent)
    : QObject{parent}
    , m_location{location}
    , m_value{value}
    , m_cutting{cutting}
{

}

QString DefenceSource::location() const
{
    return m_location;
}

quint8 DefenceSource::value() const
{
    return m_value;
}

quint8 DefenceSource::cutting() const
{
    return m_cutting;
}
