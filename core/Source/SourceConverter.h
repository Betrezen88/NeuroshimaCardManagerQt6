#ifndef SOURCECONVERTER_H
#define SOURCECONVERTER_H

#include <QObject>

#include "SourceDocument.h"
#include "OriginSource.h"
#include "SpecializationSource.h"

class SourceConverter : public QObject
{
    Q_OBJECT
public:
    explicit SourceConverter();

signals:
    void origisConverted(const QString& name, QVector<OriginSource*>& origins);
    void specializationsConverted(const QVector<SpecializationSource*>& specializations);

public slots:
    void convertSourceDocument(const SourceDocument& document);

private:
    void convertOrigins(const SourceDocument& document);
    void convertSpecializations(const SourceDocument& document);
    OriginSource* originSource(const QJsonObject& object);
    AttributeBonusSource* attributeBonus(const QJsonObject& object);
    FeatureSource* featureSource(const QJsonObject& object);
    BonusSource* featureBonus(const QJsonObject& object);
};

#endif // SOURCECONVERTER_H
