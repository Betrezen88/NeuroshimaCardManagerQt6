#ifndef CARDCONVERTER_H
#define CARDCONVERTER_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>

#include "../Data/CardData.h"
#include "../Data/Pages/StatisticsData.h"
#include "../Data/Statistics/AttributeData.h"
#include "../Data/Statistics/DiseaseData.h"
#include "../Data/Statistics/ExperienceData.h"
#include "../Data/Statistics/FeatureData.h"
#include "../Data/Statistics/ModifierData.h"
#include "../Data/Statistics/OriginData.h"
#include "../Data/Statistics/ProfessionData.h"
#include "../Data/Statistics/RequirementData.h"
#include "../Data/Statistics/SkillData.h"
#include "../Data/Statistics/SkillpackData.h"
#include "../Data/Statistics/SpecializationData.h"
#include "../Data/Statistics/WoundData.h"
#include "../Data/Statistics/PlaceData.h"

class CardConverter : public QObject
{
    Q_OBJECT
public:
    explicit CardConverter(QObject *parent = nullptr);

    QJsonDocument toJson(const CardData &card);
    CardData toData(const QJsonDocument &json);

signals:

private:
    QJsonObject statisticsToJson(const StatisticsData &statistics);
    QJsonObject originToJson(const OriginData &origin);
    QJsonObject professionToJson(const ProfessionData &profession);
    QJsonObject featureToJson(const FeatureData &feature);
    QJsonObject diseaseToJson(const DiseaseData &disease);
    QJsonObject symptomToJson(const SymptomData &symptom);
    QJsonObject attributeToJson(const AttributeData &attribute);
    QJsonObject experienceToJson(const ExperienceData &experience);
    QJsonObject requiementToJson(const RequirementData &requirement);
    QJsonObject modifierToJson(const ModifierData &modifier);
    QJsonObject otherSkillToJson(const OtherSkillData &otherSkill);
    QJsonObject skillToJson(const SkillData &skill);
    QJsonObject skillpackToJson(const SkillpackData &skillpack);
    QJsonObject specializationToJson(const SpecializationData &specialization);
    QJsonObject trickToJson(const TrickData &trick);
    QJsonObject woundToJson(const WoundData& wound);

    StatisticsData statisticsData(const QJsonObject &object);
    OriginData originData(const QJsonObject &object);
    ProfessionData professionData(const QJsonObject &object);
    FeatureData featureData(const QJsonObject &object);
    DiseaseData diseaseData(const QJsonObject &object);
    SymptomData symptomData(const QJsonObject &object);
    AttributeData attributeData(const QJsonObject &object);
    ExperienceData experienceData(const QJsonObject &object);
    RequirementData requirementData(const QJsonObject &object);
    ModifierData modifierData(const QJsonObject &object);
    OtherSkillData otherSkillData(const QJsonObject &object);
    SkillData skillData(const QJsonObject &object);
    SkillpackData skillpackData(const QJsonObject &object);
    SpecializationData specializationData(const QJsonObject &object);
    TrickData trickData(const QJsonObject &object);
    WoundData woundData(const QJsonObject &object);
    PlaceData placeData(const QJsonObject &object);
};

#endif // CARDCONVERTER_H
