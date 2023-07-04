#include "Statistics.h"

Statistics::Statistics(QObject *parent)
    : Page(parent)
    , m_type(Types::Page::Statistics)
{

}

Statistics::Statistics(const StatisticsData &data, QObject *parent)
    : Page(parent)
    , m_type(Types::Page::Statistics)
    , m_name(data.name)
    , m_surname(data.surname)
    , m_nickanem(data.nickname)
    , m_disease(new Disease(data.disease, this))
    , m_experience(new Experience(data.experience, this))
    , m_origin(new Origin(data.origin, this))
    , m_profession(new Profession(data.profession, this))
    , m_specialization(new Specialization(data.specialization, this))
    , m_reputation(new Reputation(data.places, this))
{
    for (const auto &attribute: data.attributes) {
        m_attributes.append(new Attribute(attribute, this));
    }

    for (const auto &otherSkill: data.otherSkills) {
        m_otherSkills.append(new OtherSkill(otherSkill, this));
    }

    for (const auto &trick: data.tricks) {
        m_tricks.append(new Trick(trick, this));
    }

    for (const auto &wound: data.wounds) {
        m_wounds.append(new Wound(wound, this));
    }
}

QString Statistics::fullname() const
{
    return m_name + (m_nickanem.isEmpty() ? " " : " '"+m_nickanem+"' ") + m_surname;
}

Types::Page Statistics::type() const
{
    return m_type;
}

Disease *Statistics::disease() const
{
    return m_disease;
}

Experience *Statistics::experience() const
{
    return m_experience;
}

Origin *Statistics::origin() const
{
    return m_origin;
}

Profession *Statistics::profession() const
{
    return m_profession;
}

Specialization *Statistics::specialization() const
{
    return m_specialization;
}

QQmlListProperty<Attribute> Statistics::attributes()
{
    return QQmlListProperty<Attribute>(this, this,
                                       &Statistics::attributesCount,
                                       &Statistics::attribute);
}

qsizetype Statistics::attributesCount() const
{
    return m_attributes.count();
}

Attribute *Statistics::attribute(qsizetype index)
{
    return m_attributes.at(index);
}

Attribute *Statistics::attribute(const QString &name)
{
    auto found = std::find_if(m_attributes.constBegin(), m_attributes.constEnd(), [&name](const Attribute* attribute){
        return attribute->name() == name;
    });

    if ( found != m_attributes.cend() ) {
        return *found;
    }
    return nullptr;
}

qsizetype Statistics::attributesCount(QQmlListProperty<Attribute> *list)
{
    return reinterpret_cast<Statistics*>(list->data)->attributesCount();
}

Attribute *Statistics::attribute(QQmlListProperty<Attribute> *list, qsizetype index)
{
    return reinterpret_cast<Statistics*>(list->data)->attribute(index);
}

QQmlListProperty<OtherSkill> Statistics::otherSkills()
{
    return QQmlListProperty<OtherSkill>(this, this,
                                        &Statistics::otherSkillsCount,
                                        &Statistics::otherSkill);
}

qsizetype Statistics::otherSkillsCount() const
{
    return m_otherSkills.count();
}

OtherSkill *Statistics::otherSkill(qsizetype index)
{
    return m_otherSkills.at(index);
}

qsizetype Statistics::otherSkillsCount(QQmlListProperty<OtherSkill> *list)
{
    return reinterpret_cast<Statistics*>(list->data)->otherSkillsCount();
}

OtherSkill *Statistics::otherSkill(QQmlListProperty<OtherSkill> *list, qsizetype index)
{
    return reinterpret_cast<Statistics*>(list->data)->otherSkill(index);
}

qsizetype Statistics::tricksCount(QQmlListProperty<Trick> *list)
{
    return reinterpret_cast<Statistics*>(list->data)->tricksCount();
}

Trick *Statistics::trick(QQmlListProperty<Trick> *list, qsizetype index)
{
    return reinterpret_cast<Statistics*>(list->data)->trick(index);
}

void Statistics::addWound(QQmlListProperty<Wound> *list, Wound *wound)
{
    return reinterpret_cast<Statistics*>(list->data)->addWound(wound);
}

qsizetype Statistics::woundsCount(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<Statistics*>(list->data)->woundsCount();
}

Wound *Statistics::wound(QQmlListProperty<Wound> *list, qsizetype index)
{
    return reinterpret_cast<Statistics*>(list->data)->wound(index);
}

void Statistics::clearWounds(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<Statistics*>(list->data)->clearWounds();
}

Reputation *Statistics::reputation() const
{
    return m_reputation;
}

QQmlListProperty<Trick> Statistics::tricks()
{
    return QQmlListProperty<Trick>(this, this,
                                   &Statistics::tricksCount,
                                   &Statistics::trick);
}

qsizetype Statistics::tricksCount() const
{
    return m_tricks.count();
}

Trick *Statistics::trick(qsizetype index)
{
    return m_tricks.at(index);
}

QQmlListProperty<Wound> Statistics::wounds()
{
    return QQmlListProperty<Wound>(this, this,
                                   &Statistics::addWound,
                                   &Statistics::woundsCount,
                                   &Statistics::wound,
                                   &Statistics::clearWounds);
}

void Statistics::addWound(Wound *wound)
{
    m_wounds.append(wound);
}

qsizetype Statistics::woundsCount() const
{
    return m_wounds.count();
}

Wound *Statistics::wound(qsizetype index)
{
    return m_wounds.at(index);
}

void Statistics::clearWounds()
{
    m_wounds.clear();
}

QString Statistics::woundsForLocation(const QString &location)
{
    QString result;
    std::for_each(m_wounds.begin(), m_wounds.end(), [&result, &location](const Wound* wound){
        if ( location == wound->location() ) {
            result.append( wound->name().first(1) + ", " );
        }
    });
    return result;
}


QStringList Statistics::locations() const
{
    return m_locations;
}

StatisticsData Statistics::data()
{
    QVector<AttributeData> attributes;
    for ( const auto& attribute: m_attributes ) {
        attributes.append(attribute->data());
    }

    QVector<OtherSkillData> otherSkills;
    for ( const auto& otherSkill: m_otherSkills ) {
        otherSkills.append( otherSkill->data() );
    }

    QVector<TrickData> tricks;
    for ( const auto& trick: m_tricks ) {
        tricks.append( trick->data() );
    }

    QVector<WoundData> wounds;
    for ( const auto& wound: m_wounds ) {
        wounds.append( wound->data() );
    }

    return StatisticsData{
        .name = m_name,
        .surname = m_surname,
        .nickname = m_nickanem,
        .origin = m_origin->data(),
        .profession = m_profession->data(),
        .specialization = m_specialization->data(),
        .disease = m_disease->data(),
        .attributes = attributes,
        .otherSkills = otherSkills,
        .tricks = tricks,
        .experience = m_experience->data(),
        .wounds = wounds,
        .places = m_reputation->data()
    };
}
