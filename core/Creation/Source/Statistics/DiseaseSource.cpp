#include "DiseaseSource.h"

DiseaseSource::DiseaseSource(QObject *parent)
    : QObject{parent}
{

}

DiseaseSource::DiseaseSource(const QString &name,
                             const QString &description,
                             const QString &cure,
                             const QVector<SymptomSource *> &symptoms,
                             QObject *parent)
    : QObject{parent}
    , m_name{name}
    , m_description{description}
    , m_cure{cure}
    , m_symptoms{symptoms}
{
    for ( SymptomSource* symptom: m_symptoms )
        symptom->setParent(this);
}

QString DiseaseSource::name() const
{
    return m_name;
}

QString DiseaseSource::description() const
{
    return m_description;
}

QString DiseaseSource::cure() const
{
    return m_cure;
}

QQmlListProperty<SymptomSource> DiseaseSource::symptoms()
{
    return QQmlListProperty<SymptomSource>(this, this,
                                           &DiseaseSource::symptomsCount,
                                           &DiseaseSource::symptom);
}

qsizetype DiseaseSource::symptomsCount() const
{
    return m_symptoms.count();
}

SymptomSource *DiseaseSource::symptom(qsizetype index)
{
    return m_symptoms.at(index);
}

qsizetype DiseaseSource::symptomsCount(QQmlListProperty<SymptomSource> *list)
{
    return reinterpret_cast<DiseaseSource*>(list->data)->symptomsCount();
}

SymptomSource *DiseaseSource::symptom(QQmlListProperty<SymptomSource> *list, qsizetype index)
{
    return reinterpret_cast<DiseaseSource*>(list->data)->symptom(index);
}
