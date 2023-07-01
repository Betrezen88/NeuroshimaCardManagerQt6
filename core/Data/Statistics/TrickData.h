#ifndef TRICKDATA_H
#define TRICKDATA_H

#include <QString>
#include <QVector>

#include "RequirementData.h"

struct TrickData {
    QString name;
    QString description;
    QString action;
    QVector<RequirementData> requirements;
};

#endif // TRICKDATA_H
