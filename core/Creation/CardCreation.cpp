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

    m_skillpointsManager = new SkillpointsCreationManager(this);
    QVector<AttributeCreation*> attributes;
    for (AttributeSource* attribute: const_cast<const StatisticsSource*>(m_statisticsSource)->attributes() ) {
        AttributeCreation* attributeCreation = new AttributeCreation(attribute);
        for ( const SkillpackCreation* skillpack: const_cast<const AttributeCreation*>(attributeCreation)->skillpacks() ) {
            connect(skillpack, &SkillpackCreation::skillIncreased, m_skillpointsManager, &SkillpointsCreationManager::onSkillBought);
            connect(skillpack, &SkillpackCreation::skillDecreased, m_skillpointsManager, &SkillpointsCreationManager::onSkillSold);
            connect(skillpack, &SkillpackCreation::boughtChanged, this, [this, skillpack](const bool bougth){
                if ( bougth ) {
                    this->m_skillpointsManager->onSkillpackBought(skillpack->source()->specializations());
                } else {
                    this->m_skillpointsManager->onSkillpackSold(skillpack->source()->specializations());
                }
            });
        }
        attributes.append( attributeCreation );
    }

    m_statisticsCreation = new StatisticsCreation( attributes, m_statisticsSource->places(), this );

    connect(m_statisticsSource, &StatisticsSource::diseaseDrawed, m_statisticsCreation, &StatisticsCreation::setDisease);
    connect(m_statisticsSource, &StatisticsSource::trickBougth, m_statisticsCreation, &StatisticsCreation::onTrickBougth);
    connect(m_statisticsSource, &StatisticsSource::trickBougth, m_skillpointsManager, &SkillpointsCreationManager::onTrickBought);
    connect(m_statisticsCreation, &StatisticsCreation::specializationChangedTo, m_skillpointsManager, &SkillpointsCreationManager::setSpecialization);
    connect(m_statisticsCreation, &StatisticsCreation::trickSold, m_statisticsSource, &StatisticsSource::onTrickSold);
    connect(m_statisticsCreation, &StatisticsCreation::trickSold, this, [this](TrickSource* trick){
        Q_UNUSED(trick)
        this->m_skillpointsManager->onTrickSold();
    });
    connect(m_statisticsCreation, &StatisticsCreation::otherSkillAdded, this, [this](OtherSkillCreation* otherSkill){
        connect(otherSkill, &OtherSkillCreation::increased, this, [this](const int value){
            this->m_skillpointsManager->onSkillBought({}, value);
        });
        connect(otherSkill, &OtherSkillCreation::decreased, this, [this](const int value){
            this->m_skillpointsManager->onSkillSold({}, value);
        });
    });
    connect(m_statisticsCreation, &StatisticsCreation::reputationIncreased, m_skillpointsManager, &SkillpointsCreationManager::onReputationBougth);
    connect(m_statisticsCreation, &StatisticsCreation::reputationDecreased, m_skillpointsManager, &SkillpointsCreationManager::onReputationSold);
    connect(m_statisticsCreation, &StatisticsCreation::reputationGeneralPoint, m_skillpointsManager, &SkillpointsCreationManager::setIsReputationGeneralPoint);
    connect(m_statisticsCreation, &StatisticsCreation::statsChanged, m_statisticsSource, &StatisticsSource::onStatsChanged);

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

SkillpointsCreationManager *CardCreation::skillpointsManager() const
{
    return m_skillpointsManager;
}
