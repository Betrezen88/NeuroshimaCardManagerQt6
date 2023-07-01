#include "Skillpack.h"

Skillpack::Skillpack(QObject *parent)
    : QObject{parent}
{

}

Skillpack::Skillpack(const SkillpackData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_specializations(data.specializations)
{
    for (const auto &skill: data.skills) {
        m_skills.append(new Skill(skill, this));
    }
}

QString Skillpack::name() const
{
    return m_name;
}

QStringList Skillpack::specializations() const
{
    return m_specializations;
}

QQmlListProperty<Skill> Skillpack::skills()
{
    return QQmlListProperty<Skill>(this, this,
                                   &Skillpack::skillsCount,
                                   &Skillpack::skill);
}

qsizetype Skillpack::skillsCount() const
{
    return m_skills.count();
}

Skill *Skillpack::skill(qsizetype index)
{
    return m_skills.at(index);
}

QString Skillpack::specializationsShort() const
{
    QString result{"("};
    for ( const auto& specialization: m_specializations ) {
        result.append( specialization.at(0) );
        result.append( (m_specializations.last() != specialization ? ", " : "") );
    }
    result.append(")");
    return result;
}

SkillpackData Skillpack::data() const
{
    QVector<SkillData> skills;
    for ( const auto& skill: m_skills ) {
        skills.append( skill->data() );
    }

    return SkillpackData{
        .name = m_name,
        .specializations = m_specializations,
        .skills = skills
    };
}

qsizetype Skillpack::skillsCount(QQmlListProperty<Skill> *list)
{
    return reinterpret_cast<Skillpack*>(list->data)->skillsCount();
}

Skill *Skillpack::skill(QQmlListProperty<Skill> *list, qsizetype index)
{
    return reinterpret_cast<Skillpack*>(list->data)->skill(index);
}
