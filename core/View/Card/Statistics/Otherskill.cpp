#include "Otherskill.h"

OtherSkill::OtherSkill(QObject *parent)
    : Skill{parent}
{

}

OtherSkill::OtherSkill(const OtherSkillData &data, QObject *parent)
    : Skill(SkillData{data.name, data.value, data.used}, parent)
    , m_attribute(data.attribute)
{

}

QString OtherSkill::attribute() const
{
    return m_attribute;
}

QString OtherSkill::attributeShort() const
{
    if ( m_attribute == "Budowa" ) {
        return "Bd";
    }
    if ( m_attribute == "Zręczność" ) {
        return "Zr";
    }
    if ( m_attribute == "Charakter" ) {
        return "Ch";
    }
    if ( m_attribute == "Spryt" ) {
        return "Sp";
    }
    if ( m_attribute == "Percepcja" ) {
        return "Pe";
    }
    return "Un";
}

OtherSkillData OtherSkill::data() const
{
    return OtherSkillData{
        .attribute = m_attribute
    };
}
