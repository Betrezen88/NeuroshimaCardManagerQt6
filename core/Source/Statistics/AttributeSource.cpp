#include "AttributeSource.h"

AttributeSource::AttributeSource(QObject *parent)
    : QObject{parent}
{

}

AttributeSource::AttributeSource(const QString &name,
                                 const QString &description,
                                 const QVector<SkillpackSource *>&skillpacks,
                                 QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_skillpacks{skillpacks}
{
    for ( auto skillpack: m_skillpacks )
        skillpack->setParent(this);
}

QString AttributeSource::name() const
{
    return m_name;
}

QString AttributeSource::description() const
{
    return m_description;
}

QQmlListProperty<SkillpackSource> AttributeSource::skillpacks()
{
    return QQmlListProperty<SkillpackSource>(this, this,
                                             &AttributeSource::skillpacksCount,
                                             &AttributeSource::skillpack);
}

qsizetype AttributeSource::skillpacksCount() const
{
    return m_skillpacks.count();
}

SkillpackSource *AttributeSource::skillpack(qsizetype index)
{
    return m_skillpacks.at(index);
}

qsizetype AttributeSource::skillpacksCount(QQmlListProperty<SkillpackSource> *list)
{
    return reinterpret_cast<AttributeSource*>(list->data)->skillpacksCount();
}

SkillpackSource *AttributeSource::skillpack(QQmlListProperty<SkillpackSource> *list, qsizetype index)
{
    return reinterpret_cast<AttributeSource*>(list->data)->skillpack(index);
}
