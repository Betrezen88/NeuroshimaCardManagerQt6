#include "Symptom.h"

#include "../Common/Modifier.h"

Symptom::Symptom(QObject *parent)
    : QObject{parent}
{

}

Symptom::Symptom(const SymptomData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
{
    for (const auto& penalty: data.penalties) {
        m_penalties.append(new Modifier(penalty, this));
    }
}

QString Symptom::name() const
{
    return m_name;
}

QString Symptom::description() const
{
    return m_description;
}

QQmlListProperty<Modifier> Symptom::penalties()
{
    return QQmlListProperty<Modifier>(this, this,
                                      &Symptom::penaltiesCount,
                                      &Symptom::penalty);
}

qsizetype Symptom::penaltiesCount() const
{
    return m_penalties.count();
}

Modifier *Symptom::penalty(qsizetype index)
{
    if (index < m_penalties.count() && index >= 0)
        return m_penalties.at(index);
    return nullptr;
}

SymptomData Symptom::data() const
{
    QVector<ModifierData> penalties;
    for ( const auto& penalty: m_penalties ) {
        penalties.append( penalty->data() );
    }

    return SymptomData{
        .name = m_name,
        .description = m_description,
        .penalties = penalties
    };
}

qsizetype Symptom::penaltiesCount(QQmlListProperty<Modifier> *list)
{
    return reinterpret_cast<Symptom*>(list->data)->penaltiesCount();
}

Modifier *Symptom::penalty(QQmlListProperty<Modifier> *list, qsizetype index)
{
    return reinterpret_cast<Symptom*>(list->data)->penalty(index);
}
