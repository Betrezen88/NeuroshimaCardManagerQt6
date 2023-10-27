#include "SkillCreation.h"

SkillCreation::SkillCreation(QObject *parent)
    : QObject{parent}
{

}

SkillCreation::SkillCreation(SkillSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{

}

int SkillCreation::value() const
{
    return m_value;
}

int SkillCreation::min() const
{
    return m_min;
}

int SkillCreation::max() const
{
    return m_max;
}

void SkillCreation::increase()
{
    ++m_value;
    emit increased(m_value);
    emit valueChanged();
}

void SkillCreation::decrease()
{
    emit decreased(m_value);
    --m_value;
    emit valueChanged();
}

void SkillCreation::increasedBy(const int value)
{
    m_min += value;
    emit minChanged();

    m_value += value;
    emit valueChanged();
}

void SkillCreation::decreaseBy(const int value)
{
    m_min = m_min-value < 0 ? 0 : m_min-value;
    emit minChanged();

    m_value -= value;
    emit valueChanged();
}
