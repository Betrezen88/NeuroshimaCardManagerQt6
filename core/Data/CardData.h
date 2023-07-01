#ifndef CARDDATA_H
#define CARDDATA_H

#include <QString>

#include "Pages/StatisticsData.h"

struct CardData {
    QString filename;
    StatisticsData *statistics;
};

#endif // CARDDATA_H
