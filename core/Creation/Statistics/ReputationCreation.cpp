#include "ReputationCreation.h"

ReputationCreation::ReputationCreation(QObject *parent)
    : QObject{parent}
{}

ReputationCreation::ReputationCreation(const QString &place, const quint8 min, const quint8 max, QObject *parent)
    : QObject{parent}
    , m_place{place}
    , m_min{min}
    , m_max{max}
{

}

QString ReputationCreation::place() const
{
    return m_place;
}

quint8 ReputationCreation::value() const
{
    return m_value;
}

void ReputationCreation::setValue(quint8 newValue)
{
    if (m_value == newValue)
        return;
    m_value = newValue;
    emit valueChanged();
}

quint8 ReputationCreation::min() const
{
    return m_min;
}

quint8 ReputationCreation::max() const
{
    return m_max;
}

void ReputationCreation::increase()
{
    setValue( m_value+1 );
    emit increased();
}

void ReputationCreation::decrease()
{
    setValue( m_value-1 );
    emit decreased();
}
