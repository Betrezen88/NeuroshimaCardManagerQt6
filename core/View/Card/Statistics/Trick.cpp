#include "Trick.h"

Trick::Trick(QObject *parent)
    : QObject{parent}
{

}

Trick::Trick(const TrickData &data,
             QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
    , m_action(data.action)
{
    for (const auto &requirement: data.requirements) {
        m_requirements.append(new Requirement(requirement, this));
    }
}

QString Trick::name() const
{
    return m_name;
}

QString Trick::description() const
{
    return m_description;
}

QString Trick::action() const
{
    return m_action;
}

QQmlListProperty<Requirement> Trick::requirements()
{
    return QQmlListProperty<Requirement>(this, this,
                                         &Trick::requirementsCount,
                                         &Trick::requirement);
}

qsizetype Trick::requirementsCount() const
{
    return m_requirements.count();
}

Requirement *Trick::requirement(qsizetype index)
{
    return m_requirements.at(index);
}

QString Trick::requirementsString() const
{
    QString result;
    for ( const auto& requirement: m_requirements) {
        result += requirement->name() + " " + QString::number(requirement->value()) ;
        if ( requirement != m_requirements.last() ) {
            result += ", ";
        }
    }
    return result;
}

TrickData Trick::data() const
{
    QVector<RequirementData> requirements;
    for ( const auto& requirement: m_requirements ) {
        requirements.append( requirement->data() );
    }

    return TrickData{
        .name = m_name,
        .description = m_description,
        .action = m_action,
        .requirements = requirements
    };
}

qsizetype Trick::requirementsCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<Trick*>(list->data)->requirementsCount();
}

Requirement *Trick::requirement(QQmlListProperty<Requirement> *list, qsizetype index)
{
    return reinterpret_cast<Trick*>(list->data)->requirement(index);
}
