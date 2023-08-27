#ifndef ATTRIBUTEBONUSLIST_H
#define ATTRIBUTEBONUSLIST_H

#include "AttributeBonusSource.h"
#include <QQmlEngine>

class AttributeBonusList : public AttributeBonusSource
{
    Q_OBJECT
    Q_PROPERTY(Types::AttributeBonus type READ type CONSTANT)
    Q_PROPERTY(QStringList list READ list CONSTANT)
    QML_ELEMENT

public:
    explicit AttributeBonusList(QObject *parent = nullptr);
    explicit AttributeBonusList(const QStringList& list, const int value, QObject* parent = nullptr);

    Types::AttributeBonus type() const;
    QStringList list() const;

private:
    Types::AttributeBonus m_type;
    QStringList m_list;
};

#endif // ATTRIBUTEBONUSLIST_H
