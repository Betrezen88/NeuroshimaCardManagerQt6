#ifndef SOURCECONVERTER_H
#define SOURCECONVERTER_H

#include <QObject>

#include "SourceDocument.h"
#include "AttributeSource.h"
#include "DiseaseSource.h"
#include "OriginSource.h"
#include "ProfessionSource.h"
#include "SpecializationSource.h"
#include "TrickSource.h"

class SourceConverter : public QObject
{
    Q_OBJECT
public:
    explicit SourceConverter();

signals:
    void attributesConverted(const QVector<AttributeSource*>& attributes);
    void diseasesConverted(const QString& name, const QVector<DiseaseSource*>& diseases);
    void origisConverted(const QString& name, QVector<OriginSource*>& origins);
    void professionsConverted(const QString& name, QVector<ProfessionSource*>& professions);
    void specializationsConverted(const QVector<SpecializationSource*>& specializations);
    void tricksConverted(const QString& name, QVector<TrickSource*>& tricks);

public slots:
    void convertSourceDocument(const SourceDocument& document);

private:
    void convertAttributes(const SourceDocument& document);
    void convertDiseases(const SourceDocument& document);
    void convertOrigins(const SourceDocument& document);
    void convertProfessions(const SourceDocument& document);
    void convertSpecializations(const SourceDocument& document);
    void convertTricks(const SourceDocument& document);

    AttributeSource* attributeSource(const QJsonObject& object);
    SkillpackSource* skillpackSource(const QJsonObject& object);
    SkillSource* skillSource(const QJsonObject& object);
    OriginSource* originSource(const QJsonObject& object);
    AttributeBonusSource* attributeBonus(const QJsonObject& object);
    ProfessionSource* professionSource(const QJsonObject& object);
    FeatureSource* featureSource(const QJsonObject& object);
    BonusSource* featureBonus(const QJsonObject& object);
    DiseaseSource* diseaseSource(const QJsonObject& object);
    SymptomSource* symptomSource(const QJsonObject& object);
    ModifierSource* modifierSource(const QJsonObject& object);
    TrickSource* trickSource(const QJsonObject& object);
    RequirementSource* requirementSource(const QJsonObject& object);
};

#endif // SOURCECONVERTER_H
