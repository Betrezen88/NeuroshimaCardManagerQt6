#ifndef REQUIREMENTDATA_H
#define REQUIREMENTDATA_H

#include <QString>

#include "../Common/Types.h"

struct RequirementData {
    QString name;
    int value{0};
    bool optional{false};
    Types::Requirement type;
};

#endif // REQUIREMENTDATA_H
