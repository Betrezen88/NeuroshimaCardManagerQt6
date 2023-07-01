#ifndef SYMPTOMDATA_H
#define SYMPTOMDATA_H

#include <QString>
#include <QVector>

#include "ModifierData.h"

struct SymptomData {
    QString name;
    QString description;
    QVector<ModifierData> penalties;
};

#endif // SYMPTOMDATA_H
