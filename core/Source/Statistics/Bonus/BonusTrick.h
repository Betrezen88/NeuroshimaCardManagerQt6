#ifndef BONUSTRICK_H
#define BONUSTRICK_H

#include "BonusSource.h"

class BonusTrick : public BonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Bonus type READ type CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    QML_ELEMENT

public:
    explicit BonusTrick(QObject *parent = nullptr);
    explicit BonusTrick(const QString& name, QObject* parent = nullptr);

    Types::Bonus type() const;
    QString name() const;

private:
    Types::Bonus m_type;
    QString m_name;
};

#endif // BONUSTRICK_H
