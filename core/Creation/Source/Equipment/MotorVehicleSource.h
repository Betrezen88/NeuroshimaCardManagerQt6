#ifndef MOTORVEHICLESOURCE_H
#define MOTORVEHICLESOURCE_H

#include <QQmlEngine>
#include "ItemSource.h"

class MotorVehicleSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit MotorVehicleSource(QObject *parent = nullptr);
    MotorVehicleSource(const QString &name,
                       const QString &description,
                       const quint32 price,
                       const quint8 availability,
                       const QString &category,
                       QObject *parent = nullptr);

    Types::Item type() const;

private:
    Types::Item m_type{Types::Item::MotorVehicle};
};

#endif // MOTORVEHICLESOURCE_H
