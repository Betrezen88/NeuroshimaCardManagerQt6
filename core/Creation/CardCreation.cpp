#include "CardCreation.h"

#include <../Source/SourceLoader.h>
#include <../Source/SourceConverter.h>

CardCreation::CardCreation(QObject *parent)
    : QObject{parent}
    , m_statisticsSource{new StatisticsSource(this)}
{
    init();
}

void CardCreation::init()
{
    SourceLoader loader;
    SourceConverter converter;

    connect(&loader, &SourceLoader::sendSourceDocument, &converter, &SourceConverter::convertSourceDocument);

    connect(&converter, &SourceConverter::attributesConverted, m_statisticsSource, &StatisticsSource::addAttributes);
    connect(&converter, &SourceConverter::origisConverted, m_statisticsSource, &StatisticsSource::addOrigins);
    connect(&converter, &SourceConverter::professionsConverted, m_statisticsSource, &StatisticsSource::addProfessions);
    connect(&converter, &SourceConverter::specializationsConverted, m_statisticsSource, &StatisticsSource::addSpecializations);
    connect(&converter, &SourceConverter::diseasesConverted, m_statisticsSource, &StatisticsSource::addDiseases);
    connect(&converter, &SourceConverter::questionsConverted, m_statisticsSource, &StatisticsSource::addQuestions);
    connect(&converter, &SourceConverter::placesConverted, m_statisticsSource, &StatisticsSource::addPlaces);
    connect(&converter, &SourceConverter::tricksConverted, m_statisticsSource, &StatisticsSource::addTricks);

    loader.load();

    QVector<AttributeCreation*> attributes;
    for ( AttributeSource* attribute: const_cast<const StatisticsSource*>(m_statisticsSource)->attributes() ) {
        attributes.append( new AttributeCreation(attribute) );
    }

    m_statisticsCreation = new StatisticsCreation( attributes, this );
    emit statisticsCreationChanged();

    m_statisticsCreation->setOrigin( m_statisticsSource->origin(0) );
    m_statisticsCreation->setProfession( m_statisticsSource->profession(0) );
    m_statisticsCreation->setSpecialization( m_statisticsSource->specialization(0) );
}

StatisticsSource *CardCreation::statisticsSource() const
{
    return m_statisticsSource;
}

StatisticsCreation *CardCreation::statisticsCreation() const
{
    return m_statisticsCreation;
}
