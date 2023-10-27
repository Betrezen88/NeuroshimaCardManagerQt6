#include "OtherSkillCreation.h"

OtherSkillCreation::OtherSkillCreation(QObject *parent)
    : QObject{parent}
{

}

OtherSkillCreation::OtherSkillCreation(OtherSkillSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{
    source->setParent(this);
}

OtherSkillSource *OtherSkillCreation::source() const
{
    return m_source;
}

int OtherSkillCreation::value() const
{
    return m_value;
}

int OtherSkillCreation::min() const
{
    return m_min;
}

int OtherSkillCreation::max() const
{
    return m_max;
}

void OtherSkillCreation::increase()
{
    ++m_value;
    emit increased(m_value);
    emit valueChanged();
}

void OtherSkillCreation::decrease()
{
    emit decreased(m_value);
    --m_value;
    emit valueChanged();
}

QString OtherSkillCreation::attributeShort() const
{
    const QString& attribute = m_source->attribute();

    if ( "Budowa" == attribute )
        return "Bd";
    if ( "Zręczność" == attribute )
        return "Zr";
    if ( "Charakter" == attribute )
        return "Ch";
    if ( "Percepcja" == attribute )
        return "Pe";
    if ( "Spryt" == attribute )
        return "Sp";

    return "Un";
}
