#ifndef SOURCECONVERTER_H
#define SOURCECONVERTER_H

#include <QObject>

#include "SourceDocument.h"
#include "AttributeSource.h"
#include "OriginSource.h"
#include "ProfessionSource.h"
#include "SpecializationSource.h"

class SourceConverter : public QObject
{
    Q_OBJECT
public:
    explicit SourceConverter();

signals:
    void attributesConverted(const QVector<AttributeSource*>& attributes);
    void origisConverted(const QString& name, QVector<OriginSource*>& origins);
    void professionsConverted(const QString& name, QVector<ProfessionSource*>& professions);
    void specializationsConverted(const QVector<SpecializationSource*>& specializations);

public slots:
    void convertSourceDocument(const SourceDocument& document);

private:
    void convertAttributes(const SourceDocument& document);
    void convertOrigins(const SourceDocument& document);
    void convertProfessions(const SourceDocument& document);
    void convertSpecializations(const SourceDocument& document);

    AttributeSource* attributeSource(const QJsonObject& object);
    SkillpackSource* skillpackSource(const QJsonObject& object);
    SkillSource* skillSource(const QJsonObject& object);
    OriginSource* originSource(const QJsonObject& object);
    AttributeBonusSource* attributeBonus(const QJsonObject& object);
    ProfessionSource* professionSource(const QJsonObject& object);
    FeatureSource* featureSource(const QJsonObject& object);
    BonusSource* featureBonus(const QJsonObject& object);
};

#endif // SOURCECONVERTER_H
