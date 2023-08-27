#ifndef BONUSSKILLS_H
#define BONUSSKILLS_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusSkills : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit BonusSkills(QObject *parent = nullptr);
    explicit BonusSkills(const int value, QObject* parent = nullptr);

    Types::Bonus type() const;
    int value() const;

private:
    Types::Bonus m_type;
    int m_value{0};
};

#endif // BONUSSKILLS_H
