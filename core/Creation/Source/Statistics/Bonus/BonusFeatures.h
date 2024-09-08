#ifndef BONUSFEATURES_H
#define BONUSFEATURES_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusFeatures : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    QML_ELEMENT
    QML_UNCREATABLE("BonusFeatures is uncreatable.")

public:
    explicit BonusFeatures(QObject *parent = nullptr);
    Types::Bonus type() const;
private:
    Types::Bonus m_type;
};

#endif // BONUSFEATURES_H
