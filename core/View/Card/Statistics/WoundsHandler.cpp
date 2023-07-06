#include "WoundsHandler.h"
#include "../../Data/Common/EnumConverter.h"

WoundsHandler::WoundsHandler(QObject *parent)
    : QObject{parent}
{

}

WoundsHandler::WoundsHandler(const QVector<WoundData> &wounds, QObject *parent)
{
    for (const auto &wound: wounds) {
        m_wounds.append(new Wound(wound, this));
    }
}

QQmlListProperty<Wound> WoundsHandler::wounds()
{
    return QQmlListProperty<Wound>(this, this,
                                   &WoundsHandler::addWound,
                                   &WoundsHandler::woundsCount,
                                   &WoundsHandler::wound,
                                   &WoundsHandler::clearWounds);
}

void WoundsHandler::addWound(Wound *wound)
{
    m_wounds.append(wound);
}

qsizetype WoundsHandler::woundsCount() const
{
    return m_wounds.count();
}

Wound *WoundsHandler::wound(qsizetype index)
{
    return m_wounds.at(index);
}

void WoundsHandler::clearWounds()
{
    m_wounds.clear();
}

QString WoundsHandler::woundsForLocation(const QString &location)
{
    QString result;
    std::for_each(m_wounds.begin(), m_wounds.end(), [&result, &location](const Wound* wound){
        if ( location == wound->location() ) {
            result.append( wound->name().first(1) + ", " );
        }
    });
    return result;
}

void WoundsHandler::addWound(const QString &name, const QString &location, int penalty)
{
    m_wounds.append( new Wound(
        WoundData{.type = EnumConverter::stringToWound(name),
                  .location =location,
                  .penalty{
                      ModifierData{.name = "Rana",
                                   .value = penalty,
                                   .type = Types::Modifier::Test}
                  }},
        this));
    emit woundsChanged();
}

QStringList WoundsHandler::locations() const
{
    return m_locations;
}

QStringList WoundsHandler::woundTypes() const
{
    QStringList result;
    const std::initializer_list<Types::Wound> woundTypes{
        Types::Wound::Scratch,
        Types::Wound::Light,
        Types::Wound::Heavy,
        Types::Wound::Critical
    };
    for ( auto type: woundTypes ) {
        result.append( EnumConverter::woundToString(type) );
    }
    return result;
}

QVector<WoundData> WoundsHandler::data() const
{
    QVector<WoundData> wounds;
    for ( const auto& wound: m_wounds ) {
        wounds.append( wound->data() );
    }
    return wounds;
}

void WoundsHandler::addWound(QQmlListProperty<Wound> *list, Wound *wound)
{
    return reinterpret_cast<WoundsHandler*>(list->data)->addWound(wound);
}

qsizetype WoundsHandler::woundsCount(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<WoundsHandler*>(list->data)->woundsCount();
}

Wound *WoundsHandler::wound(QQmlListProperty<Wound> *list, qsizetype index)
{
    return reinterpret_cast<WoundsHandler*>(list->data)->wound(index);
}

void WoundsHandler::clearWounds(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<WoundsHandler*>(list->data)->clearWounds();
}
