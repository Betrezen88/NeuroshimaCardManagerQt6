#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include <QString>
#include <QVector>

#include "SymptomData.h"

struct DiseaseData {
    QString name;
    QString description;
    QString cure;
    QVector<SymptomData> symptoms;
};

#endif // DISEASEDATA_H
