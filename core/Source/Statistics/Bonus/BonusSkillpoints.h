#ifndef BONUSSKILLPOINTS_H
#define BONUSSKILLPOINTS_H

#include "BonusSource.h"
#include <QQmlEngine>

class BonusSkillpoints : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(QString specialization READ specialization CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit BonusSkillpoints(QObject *parent = nullptr);
    explicit BonusSkillpoints(const QString& specialization, const int value, QObject* parent = nullptr);

    Types::Bonus type() const;
    QString specialization() const;
    int value() const;

private:
    Types::Bonus m_type;
    QString m_specialization;
    int m_value;
};

#endif // BONUSSKILLPOINTS_H
