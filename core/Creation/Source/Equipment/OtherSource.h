#ifndef OTHERSOURCE_H
#define OTHERSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include "ItemSource.h"

class OtherSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    QML_ELEMENT

public:
    explicit OtherSource(QObject *parent = nullptr);
    OtherSource(const QString& name,
                const QString& description,
                const quint32 price,
                const quint8 availability,
                const QString& category,
                QObject *parent = nullptr);

    Types::Item type() const;

private:
    Types::Item m_type{Types::Item::Other};
};

#endif // OTHERSOURCE_H
