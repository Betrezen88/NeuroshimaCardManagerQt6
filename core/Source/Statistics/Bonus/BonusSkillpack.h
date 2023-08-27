#ifndef BONUSSKILLPACK_H
#define BONUSSKILLPACK_H

#include "BonusSource.h"

class BonusSkillpack : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(QStringList list READ list CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit BonusSkillpack(QObject* parent = nullptr);
    explicit BonusSkillpack(const QStringList& list, const int value, QObject* parent = nullptr);

    Types::Bonus type() const;
    QStringList list() const;
    int value() const;

private:
    Types::Bonus m_type;
    QStringList m_list;
    int m_value{0};
};

#endif // BONUSSKILLPACK_H
