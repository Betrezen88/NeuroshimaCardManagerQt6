#ifndef ENUMCONVERTER_H
#define ENUMCONVERTER_H

#include <QString>

#include "Types.h"

class EnumConverter
{
public:
    static QString woundToString(Types::Wound wound);
    static Types::Wound stringToWound(const QString &wound);
};

#endif // ENUMCONVERTER_H
