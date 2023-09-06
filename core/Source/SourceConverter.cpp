#include "SourceConverter.h"

#include "AttributeBonusSingle.h"
#include "AttributeBonusList.h"

#include "BonusBeast.h"
#include "BonusFame.h"
#include "BonusFeatures.h"
#include "BonusFriend.h"
#include "BonusHealth.h"
#include "BonusReputation.h"
#include "BonusSkills.h"
#include "BonusSkillpack.h"
#include "BonusSkillpackDL.h"
#include "BonusSkillpoints.h"
#include "BonusTrick.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QDebug>

SourceConverter::SourceConverter()
{

}

void SourceConverter::convertSourceDocument(const SourceDocument &document)
{
    switch (document.type()) {
    case SourceDocument::Type::Attributes:
        convertAttributes(document);
        break;
    case SourceDocument::Type::Diseases:
        convertDiseases(document);
        break;
    case SourceDocument::Type::Origins:
        convertOrigins(document);
        break;
    case SourceDocument::Type::Places:
        convertPlaces(document);
        break;
    case SourceDocument::Type::Professions:
        convertProfessions(document);
        break;
    case SourceDocument::Type::Tricks:
        convertTricks(document);
        break;
    case SourceDocument::Type::Specializations:
        convertSpecializations(document);
        break;
    default:
        qDebug() << "Unknown type.";
        break;
    }
}

void SourceConverter::convertAttributes(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QVector<AttributeSource*> attributeSources;
    for ( const QJsonValue& attribute: data ) {
        attributeSources.append( attributeSource(attribute.toObject()) );
    }
    emit attributesConverted(attributeSources);
}

void SourceConverter::convertDiseases(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QVector<DiseaseSource*> diseaseSources;
    for ( const QJsonValue& disease: data ) {
        diseaseSources.append( diseaseSource(disease.toObject()) );
    }

    emit diseasesConverted(document.name(), diseaseSources);
}

void SourceConverter::convertOrigins(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();

    if ( data.isEmpty() ) {
        return;
    }

    QVector<OriginSource*> originSources;
    for ( const QJsonValue& origin: data ) {
        originSources.append( originSource(origin.toObject()) );
    }

    emit origisConverted(document.name(), originSources);
}

void SourceConverter::convertProfessions(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();

    if ( data.isEmpty() ) {
        return;
    }

    QVector<ProfessionSource*> professionSources;
    for ( const QJsonValue& profession: data ) {
        professionSources.append( professionSource(profession.toObject()) );
    }

    emit professionsConverted(document.name(), professionSources);
}

void SourceConverter::convertSpecializations(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QVector<SpecializationSource*> specilizationSources;
    for ( const QJsonValue& specialization: data ) {
        const QJsonObject& spec = specialization.toObject();
        specilizationSources.append( new SpecializationSource{spec.value("name").toString(), spec.value("description").toString()} );
    }

    emit specializationsConverted(specilizationSources);
}

void SourceConverter::convertTricks(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QVector<TrickSource*> trickSources;
    for ( const QJsonValue& trick: data ) {
        trickSources.append( trickSource(trick.toObject()) );
    }

    emit tricksConverted(document.name(), trickSources);
}

void SourceConverter::convertPlaces(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QStringList places;
    for ( const QJsonValue& place: data ) {
        places.append( place.toString() );
    }

    emit placesConverted( places );
}

AttributeSource *SourceConverter::attributeSource(const QJsonObject &object)
{
    QVector<SkillpackSource*> skillpackSources;
    const QJsonArray& skillpacks = object.value("skillpacks").toArray();
    for ( const QJsonValue& skillpack: skillpacks ) {
        skillpackSources.append( skillpackSource(skillpack.toObject()) );
    }

    return new AttributeSource{object.value("name").toString(),
                               object.value("description").toString(),
                               skillpackSources};
}

SkillpackSource *SourceConverter::skillpackSource(const QJsonObject &object)
{
    const QJsonArray& specializationArray = object.value("specializations").toArray();
    QStringList specializations;
    for ( const QJsonValue& specialization: specializationArray ) {
        specializations << specialization.toString();
    }

    QVector<SkillSource*> skillSources;
    const QJsonArray& skills = object.value("skills").toArray();
    for ( const QJsonValue& skill: skills ) {
        skillSources.append( skillSource(skill.toObject()) );
    }

    return new SkillpackSource{object.value("name").toString(), specializations, skillSources};
}

SkillSource *SourceConverter::skillSource(const QJsonObject &object)
{
    return new SkillSource{object.value("name").toString(), object.value("description").toString()};
}

OriginSource *SourceConverter::originSource(const QJsonObject &object)
{
    const QJsonArray& features = object.value("features").toArray();
    QVector<FeatureSource*> featureSources;
    for ( const QJsonValue& feature: features ) {
        featureSources.append( featureSource(feature.toObject()) );
    }

    return new OriginSource{object.value("name").toString(),
                            object.value("description").toString(),
                            attributeBonus(object.value("bonus").toObject()),
                            featureSources};
}

AttributeBonusSource *SourceConverter::attributeBonus(const QJsonObject &object)
{
    const int value = object.value("value").toInt();
    if ( !object.value("name").isArray() ) {
        return new AttributeBonusSingle{object.value("name").toString(), value};
    }
    else {
        QStringList names;
        const QJsonArray& list = object.value("name").toArray();
        for ( const QJsonValue& name: list ) {
            names << name.toString();
        }
        return new AttributeBonusList{names, value};
    }
}

ProfessionSource *SourceConverter::professionSource(const QJsonObject &object)
{
    QVector<FeatureSource*> featureSources;
    const QJsonArray& features = object.value("features").toArray();
    for ( const QJsonValue& feature: features ) {
        featureSources.append( featureSource(feature.toObject()) );
    }

    return new ProfessionSource{object.value("name").toString(),
                                object.value("description").toString(),
                                object.value("quote").toString(),
                                featureSources};
}

FeatureSource *SourceConverter::featureSource(const QJsonObject &object)
{
    return new FeatureSource{object.value("name").toString(),
                             object.value("description").toString(),
                             featureBonus(object.value("bonus").toObject())};
}

BonusSource *SourceConverter::featureBonus(const QJsonObject &object)
{
    if ( object.isEmpty() )
        return nullptr;

    const QString& type = object.value("type").toString();
    if ( "Pet" == type ) {
        return new BonusBeast{};
    }
    if ( "Health" == type ) {
        return new BonusHealth{};
    }
    if ( "Fame" == type ) {
        return new BonusFame{object.value("value").toInt(), object.value("price").toInt()};
    }
    if ( "Features" == type ) {
        return new BonusFeatures{};
    }
    if ( "Connections" == type ) {
        return new BonusFriend{object.value("value").toInt()};
    }
    if ( "Reputation" == type ) {
        return new BonusReputation{object.value("value").toInt(), object.value("price").toInt()};
    }
    if ( "Skillpoints" == type ) {
        return new BonusSkillpoints{object.value("specialization").toString(), object.value("value").toInt()};
    }
    if ( "Skills" == type ) {
        return new BonusSkills{object.value("value").toInt()};
    }
    if ( "Skillpack" == type ) {
        const QJsonArray& skillpacks = object.value("list").toArray();
        QStringList list;
        for ( const QJsonValue& skillpack: skillpacks ) {
            list << skillpack.toString();
        }
        return new BonusSkillpack{list, object.value("value").toInt()};
    }
    if ( "SkillpackDL" == type ) {
        const QJsonArray& skillpacks = object.value("list").toArray();
        QStringList list;
        for ( const QJsonValue& skillpack: skillpacks ) {
            list << skillpack.toString();
        }
        return new BonusSkillpackDL{list};
    }
    if ( "Trick" == type ) {
        return new BonusTrick{object.value("name").toString()};
    }
    return nullptr;
}

DiseaseSource *SourceConverter::diseaseSource(const QJsonObject &object)
{
    QVector<SymptomSource*> symptomSources;
    const QJsonArray& symptoms = object.value("symptoms").toArray();
    for ( const QJsonValue& symptom: symptoms ) {
        symptomSources.append( symptomSource(symptom.toObject()) );
    }

    return new DiseaseSource{object.value("name").toString(),
                             object.value("description").toString(),
                             object.value("curse").toString(),
                             symptomSources};
}

SymptomSource *SourceConverter::symptomSource(const QJsonObject &object)
{
    QVector<ModifierSource*> penaltySources;
    const QJsonArray& penalties = object.value("penalty").toArray();
    for ( const QJsonValue& penalty: penalties ) {
        penaltySources.append( modifierSource(penalty.toObject()) );
    }

    return new SymptomSource{object.value("name").toString(), object.value("description").toString(), penaltySources};
}

ModifierSource *SourceConverter::modifierSource(const QJsonObject &object)
{
    auto stringToType = [](const QString& name){
        return name == "Attribute" ? Types::Modifier::Attribute : Types::Modifier::Test;
    };

    return new ModifierSource{stringToType(object.value("type").toString()), object.value("name").toString(), object.value("value").toInt()};
}

TrickSource *SourceConverter::trickSource(const QJsonObject &object)
{
    QVector<RequirementSource*> requirementSources;
    const QJsonArray& requirements = object.value("requirements").toArray();
    for ( const QJsonValue& requirement: requirements ) {
        requirementSources.append( requirementSource(requirement.toObject()) );
    }

    return new TrickSource{object.value("name").toString(),
                           object.value("description").toString(),
                           object.value("action").toString(),
                           requirementSources};
}

RequirementSource *SourceConverter::requirementSource(const QJsonObject &object)
{
    auto stringToType = [](const QString& name){
        if ( "Attribute" == name )
            return Types::Requirement::Attribute;
        if ( "Skill" == name )
            return Types::Requirement::Skill;
        return Types::Requirement::Profession;
    };

    return new RequirementSource{stringToType(object.value("type").toString()),
                                 object.value("name").toString(),
                                 object.value("value").toInt(),
                                 object.value("optional").toBool()};
}
