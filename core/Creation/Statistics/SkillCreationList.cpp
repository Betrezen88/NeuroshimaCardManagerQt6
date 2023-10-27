#include "SkillCreationList.h"

SkillCreationList::SkillCreationList(QObject *parent)
    : SkillCreation{parent}
    , m_type{TypesCreation::Skill::List}
{
    connect(this, &SkillCreationList::selectedChanged, this, &SkillCreationList::onSelectedChanged);
}

SkillCreationList::SkillCreationList(const QVector<SkillSource*>& sources, QObject *parent)
    : SkillCreation{sources.first(), parent}
    , m_type{TypesCreation::Skill::List}
    , m_sources{sources}
{
    connect(this, &SkillCreationList::selectedChanged, this, &SkillCreationList::onSelectedChanged);
    for ( const SkillSource* source: m_sources) {
        m_list << source->name();
    }
}

TypesCreation::Skill SkillCreationList::type() const
{
    return m_type;
}

SkillSource *SkillCreationList::source() const
{
    return m_source;
}

QStringList SkillCreationList::list() const
{
    return m_list;
}

QString SkillCreationList::selected() const
{
    return m_selected;
}

void SkillCreationList::setSelected(const QString &newSelected)
{
    if (m_selected == newSelected)
        return;
    m_selected = newSelected;
    emit selectedChanged(m_selected);
    emit skillChanged(this);
}

void SkillCreationList::onSelectedChanged(const QString &selected)
{
    auto found = std::find_if(m_sources.constBegin(), m_sources.constEnd(), [&selected](const SkillSource* source){
        return selected == source->name();
    });

    if ( found != m_sources.constEnd() ) {
        m_source = *found;
        emit sourceChanged();
    }
}
