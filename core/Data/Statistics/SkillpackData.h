#ifndef SKILLPACKDATA_H
#define SKILLPACKDATA_H

#include "SkillData.h"

#include <QStringList>
#include <QVector>

struct SkillpackData {
    QString name;
    QStringList specializations;
    QVector<SkillData> skills;
};

#endif // SKILLPACKDATA_H
