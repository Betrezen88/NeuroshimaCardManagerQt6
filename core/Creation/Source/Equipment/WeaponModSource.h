#ifndef WEAPONMODSOURCE_H
#define WEAPONMODSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include "ItemSource.h"

class WeaponModSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit WeaponModSource(QObject *parent = nullptr);
    WeaponModSource(const QString& name,
                    const QString& description,
                    const quint32 price,
                    const quint8 availability,
                    const QString& category,
                    QObject *parent = nullptr);

    Types::Item type() const;
private:
    Types::Item m_type;
};

#endif // WEAPONMODSOURCE_H
