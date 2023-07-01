#ifndef WOUNDDATA_H
#define WOUNDDATA_H

#include <QString>

#include "ModifierData.h"
#include "../Common/Types.h"

struct WoundData {
    Types::Wound type;
    QString location;
    ModifierData penalty;
};

#endif // WOUNDDATA_H
