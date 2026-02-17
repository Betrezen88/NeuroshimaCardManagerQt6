#ifndef AMMUNITIONSOURCE_H
#define AMMUNITIONSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include "ItemSource.h"

class AmmunitionSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit AmmunitionSource(QObject *parent = nullptr);
    AmmunitionSource(const QString& name,
                     const QString& description,
                     const quint32 price,
                     const quint8 availability,
                     const QString& category,
                     QObject *parent = nullptr);

    Types::Item type() const;

private:
    Types::Item m_type{Types::Item::Ammunition};
};

#endif // AMMUNITIONSOURCE_H
