#include "Disease.h"
#include "Symptom.h"

Disease::Disease(QObject *parent)
    : QObject{parent}
{

}

Disease::Disease(const DiseaseData &data, QObject *parent)
    : QObject{parent}
    , m_name(data.name)
    , m_description(data.description)
    , m_cure(data.cure)
{
    for ( const auto& symptom: data.symptoms ) {
        m_symptoms.append( new Symptom(symptom, this) );
    }
}

QString Disease::name() const
{
    return m_name;
}

QString Disease::description() const
{
    return m_description;
}

QString Disease::cure() const
{
    return m_cure;
}

QQmlListProperty<Symptom> Disease::symptoms()
{
    return QQmlListProperty<Symptom>(this, this,
                                     &Disease::symptomsCount,
                                     &Disease::symptom);
}

qsizetype Disease::symptomsCount() const
{
    return m_symptoms.count();
}

Symptom *Disease::symptom(qsizetype index)
{
    if (index < m_symptoms.count() && index >= 0)
        return m_symptoms.at(index);
    return nullptr;
}

DiseaseData Disease::data() const
{
    QVector<SymptomData> symptoms;
    for ( const auto& symptom: m_symptoms ) {
        symptoms.append( symptom->data() );
    }

    return DiseaseData{
        .name = m_name,
        .description = m_description,
        .cure = m_cure,
        .symptoms = symptoms
    };
}

qsizetype Disease::symptomsCount(QQmlListProperty<Symptom> *list)
{
    return reinterpret_cast<Disease*>(list->data)->symptomsCount();
}

Symptom *Disease::symptom(QQmlListProperty<Symptom> *list, qsizetype index)
{
    return reinterpret_cast<Disease*>(list->data)->symptom(index);
}
