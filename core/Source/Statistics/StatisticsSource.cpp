#include "StatisticsSource.h"

#include <QDebug>

StatisticsSource::StatisticsSource(QObject *parent)
    : QObject{parent}
    , m_model{new TrickSourceModel(this)}
{

}

QQmlListProperty<OriginSource> StatisticsSource::origins()
{
    return QQmlListProperty<OriginSource>(this, this,
                                          &StatisticsSource::originsCount,
                                          &StatisticsSource::origin);
}

QQmlListProperty<AttributeSource> StatisticsSource::attributes()
{
    return QQmlListProperty<AttributeSource>();
}

qsizetype StatisticsSource::attributesCount() const
{
    return m_attributes.count();
}

AttributeSource *StatisticsSource::attribute(qsizetype index)
{
    return m_attributes.at(index);
}

const QVector<AttributeSource *> &StatisticsSource::attributes() const
{
    return m_attributes;
}

QQmlListProperty<DiseaseSource> StatisticsSource::diseases()
{
    return QQmlListProperty<DiseaseSource>(this, this,
                                           &StatisticsSource::diseasesCount,
                                           &StatisticsSource::disease);
}

qsizetype StatisticsSource::diseasesCount() const
{
    return m_diseases.count();
}

DiseaseSource *StatisticsSource::disease(qsizetype index)
{
    return m_diseases.at(index);
}

qsizetype StatisticsSource::originsCount() const
{
    return m_origins.count();
}

OriginSource *StatisticsSource::origin(qsizetype index)
{
    return m_origins.at(index);
}

QQmlListProperty<ProfessionSource> StatisticsSource::professions()
{
    return QQmlListProperty<ProfessionSource>(this, this,
                                              &StatisticsSource::professionsCount,
                                              &StatisticsSource::profession);
}

qsizetype StatisticsSource::professionsCount() const
{
    return m_professions.count();
}

ProfessionSource *StatisticsSource::profession(qsizetype index)
{
    return m_professions.at(index);
}

QQmlListProperty<QuestionSource> StatisticsSource::questions()
{
    return QQmlListProperty<QuestionSource>(this, this,
                                            &StatisticsSource::questionsCount,
                                            &StatisticsSource::question);
}

qsizetype StatisticsSource::questionsCount() const
{
    return m_questions.count();
}

QuestionSource *StatisticsSource::question(qsizetype index)
{
    return m_questions.at(index);
}

QQmlListProperty<SpecializationSource> StatisticsSource::specializations()
{
    return QQmlListProperty<SpecializationSource>(this, this,
                                                  &StatisticsSource::specializationsCount,
                                                  &StatisticsSource::specialization);
}

qsizetype StatisticsSource::specializationsCount() const
{
    return m_specializations.count();
}

SpecializationSource *StatisticsSource::specialization(qsizetype index)
{
    return m_specializations.at(index);
}

TrickSourceModel *StatisticsSource::model() const
{
    return m_model;
}

QStringList StatisticsSource::places() const
{
    return m_places;
}

void StatisticsSource::addAttributes(const QVector<AttributeSource *> &attributes)
{
    m_attributes = attributes;
    emit attributesChanged();
}

void StatisticsSource::addDiseases(const QString &name, const QVector<DiseaseSource *> &diseases)
{
    m_diseaseSources.insert(name, diseases);
}

void StatisticsSource::addOrigins(const QString &name, const QVector<OriginSource *> &origins)
{
    m_originSources.insert(name, origins);

    if ( m_origins.isEmpty() ) {
        m_origins = m_originSources.value(name);
        emit originsChanged();
    }
}

void StatisticsSource::addProfessions(const QString &name, const QVector<ProfessionSource *> &professions)
{
    m_professionSource.insert(name, professions);

    if ( m_professions.isEmpty() ) {
        m_professions = m_professionSource.value(name);
        emit professionsChanged();
    }
}

void StatisticsSource::addQuestions(const QString &name, const QVector<QuestionSource *> &questions)
{
    m_questionSources.insert( name, questions );
}

void StatisticsSource::addSpecializations(const QVector<SpecializationSource *> &specializations)
{
    m_specializations = specializations;
    emit specializationsChanged();
}

void StatisticsSource::addTricks(const QString &name, const QVector<TrickSource *> &tricks)
{
    m_model->addTricks( name, tricks );
}

void StatisticsSource::addPlaces(const QStringList &places)
{
    m_places = places;
}

qsizetype StatisticsSource::attribtuesCount(QQmlListProperty<AttributeSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->attributesCount();
}

AttributeSource *StatisticsSource::attribute(QQmlListProperty<AttributeSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->attribute(index);
}

qsizetype StatisticsSource::diseasesCount(QQmlListProperty<DiseaseSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->diseasesCount();
}

DiseaseSource *StatisticsSource::disease(QQmlListProperty<DiseaseSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->disease(index);
}

qsizetype StatisticsSource::originsCount(QQmlListProperty<OriginSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->originsCount();
}

OriginSource *StatisticsSource::origin(QQmlListProperty<OriginSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->origin(index);
}

qsizetype StatisticsSource::professionsCount(QQmlListProperty<ProfessionSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->professionsCount();
}

ProfessionSource *StatisticsSource::profession(QQmlListProperty<ProfessionSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->profession(index);
}

qsizetype StatisticsSource::questionsCount(QQmlListProperty<QuestionSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->questionsCount();
}

QuestionSource *StatisticsSource::question(QQmlListProperty<QuestionSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->question(index);
}

qsizetype StatisticsSource::specializationsCount(QQmlListProperty<SpecializationSource> *list)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->specializationsCount();
}

SpecializationSource *StatisticsSource::specialization(QQmlListProperty<SpecializationSource> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsSource*>(list->data)->specialization(index);
}
