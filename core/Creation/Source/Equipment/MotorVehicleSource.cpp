#include "MotorVehicleSource.h"

MotorVehicleSource::MotorVehicleSource(QObject *parent)
    : ItemSource{parent}
{}

MotorVehicleSource::MotorVehicleSource(const QString &name,
                                       const QString &description,
                                       const quint32 price,
                                       const quint8 availability,
                                       const QString &category,
                                       QObject *parent)
    : ItemSource{name, description, price, availability, category, parent}
{

}

Types::Item MotorVehicleSource::type() const
{
    return m_type;
}
