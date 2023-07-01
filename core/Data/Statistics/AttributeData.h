#ifndef ATTRIBUTEDATA_H
#define ATTRIBUTEDATA_H

#include "SkillpackData.h"

struct AttributeData {
    QString name;
    int value{0};
    QVector<SkillpackData> skillpacks;
};

#endif // ATTRIBUTEDATA_H
