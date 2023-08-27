#ifndef SOURCECONVERTER_H
#define SOURCECONVERTER_H

#include <QObject>

#include "SourceDocument.h"
#include "SpecializationSource.h"

class SourceConverter : public QObject
{
    Q_OBJECT
public:
    explicit SourceConverter();

signals:
    void specializationsConverted(const QVector<SpecializationSource*>& specializations);

public slots:
    void convertSourceDocument(const SourceDocument& document);

private:
    void convertSpecializations(const SourceDocument& document);
    AttributeBonusSource* attributeBonus(const QJsonObject& object);
    BonusSource* featureBonus(const QJsonObject& object);
};

#endif // SOURCECONVERTER_H
