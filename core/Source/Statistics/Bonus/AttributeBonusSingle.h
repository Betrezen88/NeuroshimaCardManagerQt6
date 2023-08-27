#ifndef ATTRIBUTEBONUSSINGLE_H
#define ATTRIBUTEBONUSSINGLE_H

#include "AttributeBonusSource.h"

class AttributeBonusSingle : public AttributeBonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::AttributeBonus type READ type CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    QML_ELEMENT

public:
    explicit AttributeBonusSingle(QObject *parent = nullptr);
    explicit AttributeBonusSingle(const QString& name, const int val, QObject* parent = nullptr);

    QString name() const;
    Types::AttributeBonus type() const;

private:
    QString m_name;
    Types::AttributeBonus m_type;
};

#endif // ATTRIBUTEBONUSSINGLE_H
