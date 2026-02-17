#ifndef DRUGSOURCE_H
#define DRUGSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include "ItemSource.h"

class DrugSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit DrugSource(QObject *parent = nullptr);
    DrugSource(const QString& name,
               const QString& description,
               const quint32 price,
               const quint8 availability,
               const QString& category,
               QObject *parent = nullptr);

    Types::Item type() const;

private:
    Types::Item m_type{Types::Item::Drug};
};

#endif // DRUGSOURCE_H
