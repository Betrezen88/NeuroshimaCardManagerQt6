#include "TrickSourceItem.h"

TrickSourceItem::TrickSourceItem(QObject *parent)
    : QObject{parent}
{

}

TrickSourceItem::TrickSourceItem(const QString &sourceName, TrickSource *source, QObject *parent)
    : QObject{parent}
    , m_sourceName{sourceName}
    , m_source{source}
{

}

QString TrickSourceItem::sourceName() const
{
    return m_sourceName;
}

TrickSource *TrickSourceItem::source() const
{
    return m_source;
}

bool TrickSourceItem::available() const
{
    return m_available;
}

void TrickSourceItem::setAvailable(bool newAvailable)
{
    if (m_available == newAvailable)
        return;
    m_available = newAvailable;
    emit availableChanged();
}

RequirementSourceModel *TrickSourceItem::requirements() const
{
    return m_requirements;
}
