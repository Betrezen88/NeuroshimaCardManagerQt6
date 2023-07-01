#ifndef MODIFIERDATA_H
#define MODIFIERDATA_H

#include <QString>

#include "../Common/Types.h"

struct ModifierData {
    QString name;
    int value{0};
    Types::Modifier type;
};

#endif // MODIFIERDATA_H
