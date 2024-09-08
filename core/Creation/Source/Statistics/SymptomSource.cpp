#include "SymptomSource.h"

SymptomSource::SymptomSource(QObject *parent)
    : QObject{parent}
{

}

SymptomSource::SymptomSource(const QString &name,
                             const QString &description,
                             const QVector<ModifierSource*>& penalties,
                             QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_penalties{penalties}
{
    for ( ModifierSource* penalty: m_penalties )
        penalty->setParent(this);
}

QString SymptomSource::name() const
{
    return m_name;
}

QString SymptomSource::description() const
{
    return m_description;
}

QQmlListProperty<ModifierSource> SymptomSource::penalties()
{
    return QQmlListProperty<ModifierSource>(this, this,
                                            &SymptomSource::penaltiesCount,
                                            &SymptomSource::penalty);
}

qsizetype SymptomSource::penaltiesCount() const
{
    return m_penalties.count();
}

ModifierSource *SymptomSource::penalty(qsizetype index)
{
    return m_penalties.at(index);
}

qsizetype SymptomSource::penaltiesCount(QQmlListProperty<ModifierSource> *list)
{
    return reinterpret_cast<SymptomSource*>(list->data)->penaltiesCount();
}

ModifierSource *SymptomSource::penalty(QQmlListProperty<ModifierSource> *list, qsizetype index)
{
    return reinterpret_cast<SymptomSource*>(list->data)->penalty(index);
}
