#ifndef PLACE_H
#define PLACE_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/PlaceData.h"

class Place : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Place(QObject *parent = nullptr);
    explicit Place(const PlaceData &data, QObject *parent = nullptr);

    QString name() const;
    int value() const;

    PlaceData data() const;

private:
    QString m_name;
    int m_value;
};

#endif // PLACE_H
