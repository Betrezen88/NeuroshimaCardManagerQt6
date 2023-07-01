#include "Reputation.h"

Reputation::Reputation(QObject *parent)
    : QObject{parent}
{

}

Reputation::Reputation(const QVector<PlaceData> &places, QObject *parent)
    : QObject{parent}
{
    for (const auto &place: places) {
        m_places.append(new Place(place, this));
    }
}

QQmlListProperty<Place> Reputation::places()
{
    return QQmlListProperty<Place>(this, this,
                                   &Reputation::placesCount,
                                   &Reputation::place);
}

qsizetype Reputation::placesCount() const
{
    return m_places.count();
}

Place *Reputation::place(qsizetype index)
{
    return m_places.at(index);
}

int Reputation::fame() const
{
    return std::count_if(m_places.constBegin(), m_places.constEnd(), [](const Place* place){
        return place->value() == 20;
    });
}

QVector<PlaceData> Reputation::data() const
{
    QVector<PlaceData> places;
    for ( const auto& place: m_places ) {
        places.append( place->data() );
    }
    return places;
}

qsizetype Reputation::placesCount(QQmlListProperty<Place> *list)
{
    return reinterpret_cast<Reputation*>(list->data)->placesCount();
}

Place *Reputation::place(QQmlListProperty<Place> *list, qsizetype index)
{
    return reinterpret_cast<Reputation*>(list->data)->place(index);
}
