#ifndef BONUSSOURCE_H
#define BONUSSOURCE_H

#include <QObject>
#include "qqmlintegration.h"
#include "../../../core/Data/Common/Types.h"

class BonusSource : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit BonusSource(QObject* parent = nullptr): QObject{parent} {}
    virtual ~BonusSource() {}

    virtual Types::Bonus type() const = 0;
};

#endif // BONUSSOURCE_H
