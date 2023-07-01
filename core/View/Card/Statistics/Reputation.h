#ifndef REPUTATION_H
#define REPUTATION_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/PlaceData.h"
#include "Place.h"

class Reputation : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QQmlListProperty<Place> places READ places CONSTANT)

public:
    explicit Reputation(QObject *parent = nullptr);
    explicit Reputation(const QVector<PlaceData> &places, QObject *parent = nullptr);

    QQmlListProperty<Place> places();
    qsizetype placesCount() const;
    Place* place(qsizetype index);

    Q_INVOKABLE int fame() const;

    QVector<PlaceData> data() const;

private:
    static qsizetype placesCount(QQmlListProperty<Place> *list);
    static Place* place(QQmlListProperty<Place> *list, qsizetype index);

private:
    QVector<Place*> m_places;
};

#endif // REPUTATION_H
