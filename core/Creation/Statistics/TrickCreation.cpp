#include "TrickCreation.h"

TrickCreation::TrickCreation(QObject *parent)
    : QObject{parent}
{

}

TrickCreation::TrickCreation(TrickSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{

}

TrickSource *TrickCreation::source() const
{
    return m_source;
}

RequirementSourceModel *TrickCreation::requirements() const
{
    return m_requirements;
}
