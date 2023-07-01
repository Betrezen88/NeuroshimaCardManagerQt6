#ifndef STATISTICSDATA_H
#define STATISTICSDATA_H

#include <QString>
#include <QVector>

#include "../Statistics/AttributeData.h"
#include "../Statistics/DiseaseData.h"
#include "../Statistics/ExperienceData.h"
#include "../Statistics/OriginData.h"
#include "../Statistics/OtherSkillData.h"
#include "../Statistics/PlaceData.h"
#include "../Statistics/ProfessionData.h"
#include "../Statistics/SpecializationData.h"
#include "../Statistics/TrickData.h"
#include "../Statistics/WoundData.h"

struct StatisticsData {
    QString name;
    QString surname;
    QString nickname;
    OriginData origin;
    ProfessionData profession;
    SpecializationData specialization;
    DiseaseData disease;
    QVector<AttributeData> attributes{};
    QVector<OtherSkillData> otherSkills{};
    QVector<TrickData> tricks{};
    ExperienceData experience;
    QVector<WoundData> wounds{};
    QVector<PlaceData> places{};
};

#endif // STATISTICSDATA_H
