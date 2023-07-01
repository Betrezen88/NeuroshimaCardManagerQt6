#include "Attribute.h"

Attribute::Attribute(QObject *parent)
    : QObject{parent}
{

}

Attribute::Attribute(const AttributeData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_value(data.value)
{
    for (const auto &skillpack: data.skillpacks) {
        m_skillpacks.append(new Skillpack(skillpack, this));
    }
}

QString Attribute::name() const
{
    return m_name;
}

int Attribute::value() const
{
    return m_value;
}

QQmlListProperty<Skillpack> Attribute::skillpacks()
{
    return QQmlListProperty<Skillpack>(this, this,
                                       &Attribute::skillpacksCount,
                                       &Attribute::skillpack);
}

qsizetype Attribute::skillpacksCount() const
{
    return m_skillpacks.count();
}

Skillpack *Attribute::skillpack(qsizetype index)
{
    return m_skillpacks.at(index);
}

AttributeData Attribute::data() const
{
    QVector<SkillpackData> skillpacks;
    for ( const auto& skillpack: m_skillpacks ) {
        skillpacks.append( skillpack->data() );
    }

    return AttributeData{
        .name = m_name,
        .value = m_value,
        .skillpacks = skillpacks
    };
}

qsizetype Attribute::skillpacksCount(QQmlListProperty<Skillpack> *list)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpacksCount();
}

Skillpack *Attribute::skillpack(QQmlListProperty<Skillpack> *list, qsizetype index)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpack(index);
}
