#include "SkillpackSource.h"

SkillpackSource::SkillpackSource(QObject *parent)
    : QObject{parent}
{

}

SkillpackSource::SkillpackSource(const QString &name,
                                 const QStringList &specializations,
                                 const QVector<SkillSource *> &skills,
                                 QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_specializations{specializations}
    , m_skills{skills}
{
    for ( auto skill: m_skills )
        skill->setParent(this);
}

QString SkillpackSource::name() const
{
    return m_name;
}

QStringList SkillpackSource::specializations() const
{
    return m_specializations;
}

const QString SkillpackSource::specializationsShort() const
{
    QString result{"("};
    for ( const QString& specialization: m_specializations ) {
        result.append(specialization.front());
        if (m_specializations.last() != specialization)
            result.append(", ");
    }
    result.append(")");
    return result;
}

QQmlListProperty<SkillSource> SkillpackSource::skills()
{
    return QQmlListProperty<SkillSource>(this, this,
                                         &SkillpackSource::skillsCount,
                                         &SkillpackSource::skill);
}

qsizetype SkillpackSource::skillsCount() const
{
    return m_skills.count();
}

SkillSource *SkillpackSource::skill(qsizetype index)
{
    return m_skills.at(index);
}

const QVector<SkillSource *> &SkillpackSource::skills() const
{
    return m_skills;
}

qsizetype SkillpackSource::skillsCount(QQmlListProperty<SkillSource> *list)
{
    return reinterpret_cast<SkillpackSource*>(list->data)->skillsCount();
}

SkillSource *SkillpackSource::skill(QQmlListProperty<SkillSource> *list, qsizetype index)
{
    return reinterpret_cast<SkillpackSource*>(list->data)->skill(index);
}
