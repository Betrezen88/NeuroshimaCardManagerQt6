#include "CardConverter.h"

#include <QJsonArray>

CardConverter::CardConverter(QObject *parent)
    : QObject{parent}
{

}

QJsonDocument CardConverter::toJson(const CardData &card)
{
    QJsonDocument json;

    QJsonObject cardJson;
    cardJson.insert( "statistics", statisticsToJson(*card.statistics));

    json.setObject( cardJson );

    return json;
}

CardData CardConverter::toData(const QJsonDocument &json)
{
    CardData data;

    data.statistics = new StatisticsData( statisticsData(json.object().value("statistics").toObject()) );

    return data;
}

QJsonObject CardConverter::statisticsToJson(const StatisticsData &statistics)
{
    QJsonObject object;

    QJsonObject fullname;
    fullname.insert( "name", statistics.name );
    fullname.insert( "surname", statistics.surname );
    fullname.insert( "nickname", statistics.nickname );

    object.insert( "fullname", fullname );

    object.insert( "origin", originToJson(statistics.origin) );
    object.insert( "profession", professionToJson(statistics.profession) );
    object.insert( "specialization", specializationToJson(statistics.specialization) );

    QJsonArray attributes;
    for ( const AttributeData& attribute: statistics.attributes ) {
        attributes.append( attributeToJson(attribute) );
    }
    object.insert( "attributes", attributes );

    QJsonArray tricks;
    for ( const TrickData &trick: statistics.tricks ) {
        tricks.append( trickToJson(trick) );
    }
    object.insert( "tricks", tricks );

    QJsonArray otherSkills;
    for ( const OtherSkillData &otherSkill: statistics.otherSkills ) {
        otherSkills.append( otherSkillToJson(otherSkill) );
    }
    object.insert( "otherSkills", otherSkills );

    QJsonArray wounds;
    for ( const WoundData &wound: statistics.wounds ) {
        wounds.append( woundToJson(wound) );
    }
    object.insert( "wounds", wounds );

    return object;
}

QJsonObject CardConverter::originToJson(const OriginData &origin)
{
    QJsonObject object;
    object.insert( "name", origin.name );
    object.insert( "description", origin.description );
    object.insert( "feature", featureToJson(origin.feature) );
    return object;
}

QJsonObject CardConverter::professionToJson(const ProfessionData &profession)
{
    QJsonObject object;
    object.insert( "name", profession.name );
    object.insert( "description", profession.description );
    object.insert( "feature", featureToJson(profession.feature) );
    return object;
}

QJsonObject CardConverter::featureToJson(const FeatureData &feature)
{
    QJsonObject object;
    object.insert( "name", feature.name );
    object.insert( "description", feature.description );
    return object;
}

QJsonObject CardConverter::diseaseToJson(const DiseaseData &disease)
{
    QJsonObject object;
    object.insert( "name", disease.name );
    object.insert( "description", disease.description );
    object.insert( "cure", disease.cure );

    QJsonArray symptoms;
    for ( const SymptomData &symptom: disease.symptoms ) {
        symptoms.append( symptomToJson(symptom) );
    }
    object.insert( "symptoms", symptoms );

    return object;
}

QJsonObject CardConverter::symptomToJson(const SymptomData &symptom)
{
    QJsonObject object;
    object.insert( "name", symptom.name );
    object.insert( "description", symptom.description );

    QJsonArray penalties;
    for ( const ModifierData &penalty: symptom.penalties ) {
        penalties.append( modifierToJson(penalty) );
    }
    object.insert( "penalties", penalties );

    return object;
}

QJsonObject CardConverter::attributeToJson(const AttributeData &attribute)
{
    QJsonObject object;
    object.insert( "name", attribute.name );
    object.insert( "value", attribute.value );

    QJsonArray skillpacks;
    for ( const SkillpackData& skillpack: attribute.skillpacks ) {
        skillpacks.append( skillpackToJson(skillpack) );
    }
    object.insert( "skillpacks", skillpacks );

    return object;
}

QJsonObject CardConverter::experienceToJson(const ExperienceData &experience)
{
    QJsonObject object;
    object.insert( "gathered", experience.gathered );
    object.insert( "spended", experience.spended );
    return object;
}

QJsonObject CardConverter::requiementToJson(const RequirementData &requirement)
{
    QJsonObject object;
    object.insert( "name", requirement.name );
    object.insert( "value", requirement.value );
    object.insert( "optional", requirement.optional );
    object.insert( "type", static_cast<int>(requirement.type) );
    return object;
}

QJsonObject CardConverter::modifierToJson(const ModifierData &modifier)
{
    QJsonObject object;
    object.insert( "name", modifier.name );
    object.insert( "value", modifier.value );
    object.insert( "type", static_cast<int>(modifier.type) );
    return object;
}

QJsonObject CardConverter::otherSkillToJson(const OtherSkillData &otherSkill)
{
    QJsonObject object;
    object.insert( "name", otherSkill.name );
    object.insert( "value", otherSkill.value );
    object.insert( "used", otherSkill.used );
    object.insert( "attribute", otherSkill.attribute );
    return object;
}

QJsonObject CardConverter::skillToJson(const SkillData &skill)
{
    QJsonObject object;
    object.insert( "name", skill.name );
    object.insert( "value", skill.value );
    object.insert( "used", skill.used );
    return object;
}

QJsonObject CardConverter::skillpackToJson(const SkillpackData &skillpack)
{
    QJsonObject object;
    object.insert( "name", skillpack.name );

    QJsonArray specializations;
    for ( const QString &specialization: skillpack.specializations ) {
        specializations.append( specialization );
    }
    object.insert( "specializations", specializations );

    QJsonArray skills;
    for ( const SkillData &skill: skillpack.skills ) {
        skills.append( skillToJson(skill) );
    }
    object.insert( "skills", skills );

    return object;
}

QJsonObject CardConverter::specializationToJson(const SpecializationData &specialization)
{
    QJsonObject object;
    object.insert( "name", specialization.name );
    object.insert( "description", specialization.description );
    return object;
}

QJsonObject CardConverter::trickToJson(const TrickData &trick)
{
    QJsonObject object;
    object.insert( "name", trick.name );
    object.insert( "description", trick.description );
    object.insert( "action", trick.action );

    QJsonArray requirements;
    for ( const RequirementData &requirement: trick.requirements ) {
        requirements.append( requiementToJson(requirement) );
    }
    object.insert( "requirements", requirements );

    return object;
}

QJsonObject CardConverter::woundToJson(const WoundData &wound)
{
    QJsonObject object;
    object.insert( "location", wound.location );
    object.insert( "penalty", modifierToJson(wound.penalty) );
    object.insert( "type", static_cast<int>(wound.type) );
    return object;
}

StatisticsData CardConverter::statisticsData(const QJsonObject &object)
{
    StatisticsData statistics;

    QJsonObject fullname = object.value("fullname").toObject();

    statistics.name = fullname.value("name").toString();
    statistics.surname = fullname.value("surname").toString();
    statistics.nickname = fullname.value("nickname").toString();

    statistics.origin = originData(object.value("origin").toObject());
    statistics.profession = professionData(object.value("profession").toObject());
    statistics.specialization = specializationData(object.value("specialization").toObject());
    statistics.disease = diseaseData(object.value("disease").toObject());
    statistics.experience = experienceData(object.value("experience").toObject());

    const QJsonArray& attributes = object.value("attributes").toArray();
    for ( const auto& attribute: attributes ) {
        statistics.attributes.append( attributeData(attribute.toObject()) );
    }

    const QJsonArray& otherSkills = object.value("otherSkills").toArray();
    for ( const auto& otherSkill: otherSkills ) {
        statistics.otherSkills.append( otherSkillData(otherSkill.toObject()) );
    }

    const QJsonArray& places = object.value("places").toArray();
    for ( const auto& place: places ) {
        statistics.places.append( placeData(place.toObject()) );
    }

    const QJsonArray& tricks = object.value("tricks").toArray();
    for ( const auto& trick: tricks ) {
        statistics.tricks.append( trickData(trick.toObject()) );
    }

    return statistics;
}

OriginData CardConverter::originData(const QJsonObject &object)
{
    OriginData origin;
    origin.name = object.value("name").toString();
    origin.description = object.value("description").toString();
    origin.feature = featureData( object.value("feature").toObject() );
    return origin;
}

ProfessionData CardConverter::professionData(const QJsonObject &object)
{
    ProfessionData profession;
    profession.name = object.value("name").toString();
    profession.description = object.value("description").toString();
    profession.feature = featureData( object.value("feature").toObject() );
    return profession;
}

FeatureData CardConverter::featureData(const QJsonObject &object)
{
    FeatureData feature;
    feature.name = object.value("name").toString();
    feature.description = object.value("description").toString();
    return feature;
}

DiseaseData CardConverter::diseaseData(const QJsonObject &object)
{
    DiseaseData disease;
    disease.name = object.value("name").toString();
    disease.description = object.value("description").toString();
    disease.cure = object.value("cure").toString();

    const QJsonArray &symptoms = object.value("symptoms").toArray();
    for ( const QJsonValue& symptom: symptoms ) {
        disease.symptoms.push_back( symptomData(symptom.toObject()) );
    }

    return disease;
}

SymptomData CardConverter::symptomData(const QJsonObject &object)
{
    SymptomData symptom;
    symptom.name = object.value("name").toString();
    symptom.description = object.value("description").toString();

    const QJsonArray &penalties = object.value("penalties").toArray();
    for ( const QJsonValue &penalty: penalties ) {
        symptom.penalties.emplaceBack(modifierData(penalty.toObject()));
    }

    return symptom;
}

AttributeData CardConverter::attributeData(const QJsonObject &object)
{
    AttributeData attribute;
    attribute.name = object.value("name").toString();
    attribute.value = object.value("value").toInt();

    const QJsonArray &skillpacks = object.value("skillpacks").toArray();
    for ( const QJsonValue &skillpack: skillpacks ) {
        attribute.skillpacks.emplaceBack( skillpackData(skillpack.toObject()) );
    }

    return attribute;
}

ExperienceData CardConverter::experienceData(const QJsonObject &object)
{
    ExperienceData experience;
    experience.gathered = object.value("gathered").toInt();
    experience.spended = object.value("spended").toInt();
    return experience;
}

RequirementData CardConverter::requirementData(const QJsonObject &object)
{
    RequirementData requirement;
    requirement.name = object.value("name").toString();
    requirement.value = object.value("value").toInt();
    requirement.optional = object.value("optional").toBool();
    requirement.type = static_cast<Types::Requirement>(object.value("type").toInt());
    return requirement;
}

ModifierData CardConverter::modifierData(const QJsonObject &object)
{
    ModifierData modified;
    modified.name = object.value("name").toString();
    modified.value = object.value("value").toInt();
    modified.type = static_cast<Types::Modifier>(object.value("type").toInt());
    return modified;
}

OtherSkillData CardConverter::otherSkillData(const QJsonObject &object)
{
    OtherSkillData otherSkill;
    otherSkill.name = object.value("name").toString();
    otherSkill.value = object.value("value").toInt();
    otherSkill.attribute = object.value("attribute").toString();
    otherSkill.used = object.value("used").toBool();
    return otherSkill;
}

SkillData CardConverter::skillData(const QJsonObject &object)
{
    SkillData skill;
    skill.name = object.value("name").toString();
    skill.value = object.value("value").toInt();
    skill.used = object.value("used").toBool();
    return skill;
}

SkillpackData CardConverter::skillpackData(const QJsonObject &object)
{
    SkillpackData skillpack;
    skillpack.name = object.value("name").toString();

    const QJsonArray &specializations = object.value("specializations").toArray();
    for ( const QJsonValue &specialization: specializations ) {
        skillpack.specializations.append( specialization.toString() );
    }

    const QJsonArray &skills = object.value("skills").toArray();
    for ( const QJsonValue &skill: skills ) {
        skillpack.skills.emplaceBack( skillData(skill.toObject()) );
    }

    return skillpack;
}

SpecializationData CardConverter::specializationData(const QJsonObject &object)
{
    SpecializationData specialization;
    specialization.name = object.value("name").toString();
    specialization.description = object.value("description").toString();
    return specialization;
}

TrickData CardConverter::trickData(const QJsonObject &object)
{
    TrickData trick;
    trick.name = object.value("name").toString();
    trick.description = object.value("description").toString();
    trick.action = object.value("action").toString();

    const QJsonArray &requirements = object.value("requirements").toArray();
    for ( const QJsonValue &requirement: requirements ) {
        trick.requirements.emplaceBack( requirementData(requirement.toObject()) );
    }

    return trick;
}

WoundData CardConverter::woundData(const QJsonObject &object)
{
    WoundData wound;
    wound.location = object.value("location").toString();
    wound.penalty = modifierData( object.value("penalty").toObject() );
    wound.type = static_cast<Types::Wound>(object.value("type").toInt());
    return wound;
}

PlaceData CardConverter::placeData(const QJsonObject &object)
{
    PlaceData place;
    place.name = object.value("name").toString();
    place.value = object.value("value").toInt();
    return place;
}
