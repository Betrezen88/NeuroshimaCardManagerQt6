#include "Experience.h"

Experience::Experience(QObject *parent)
    : QObject{parent}
{

}

Experience::Experience(const ExperienceData &data, QObject *parent)
    : QObject{parent}
    , m_gathered(data.gathered)
    , m_spended(data.spended)
{

}

int Experience::gathered() const
{
    return m_gathered;
}

int Experience::spended() const
{
    return m_spended;
}

int Experience::left() const
{
    return m_gathered - m_spended;
}

ExperienceData Experience::data() const
{
    return ExperienceData{
        .gathered = m_gathered,
        .spended = m_spended
    };
}
