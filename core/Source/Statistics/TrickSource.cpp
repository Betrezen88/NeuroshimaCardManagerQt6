#include "TrickSource.h"

TrickSource::TrickSource(QObject *parent)
    : QObject{parent}
{

}

TrickSource::TrickSource(const QString &name,
                         const QString &description,
                         const QString &action,
                         const QVector<RequirementSource *> &requirements,
                         QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_action{action}
    , m_requirements{requirements}
{

}

QString TrickSource::name() const
{
    return m_name;
}

QString TrickSource::description() const
{
    return m_description;
}

QString TrickSource::action() const
{
    return m_action;
}

QQmlListProperty<RequirementSource> TrickSource::requirements()
{
    return QQmlListProperty<RequirementSource>(this, this,
                                               &TrickSource::requirementsCount,
                                               &TrickSource::requirement);
}

qsizetype TrickSource::requirementsCount() const
{
    return m_requirements.count();
}

RequirementSource *TrickSource::requirement(qsizetype index)
{
    return m_requirements.at(index);
}

qsizetype TrickSource::requirementsCount(QQmlListProperty<RequirementSource> *list)
{
    return reinterpret_cast<TrickSource*>(list->data)->requirementsCount();
}

RequirementSource *TrickSource::requirement(QQmlListProperty<RequirementSource> *list, qsizetype index)
{
    return reinterpret_cast<TrickSource*>(list->data)->requirement(index);
}

