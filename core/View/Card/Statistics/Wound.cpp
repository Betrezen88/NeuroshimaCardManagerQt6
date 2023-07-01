#include "Wound.h"

Wound::Wound(QObject *parent)
    : QObject{parent}
{

}

QString Wound::name() const
{
    switch (m_type) {
    case Types::Wound::Scratch:
        return "Draśnięcie";
        break;
    case Types::Wound::Light:
        return "Lekka";
        break;
    case Types::Wound::Heavy:
        return "Ciężka";
        break;
    case Types::Wound::Critical:
        return "Krytyczna";
        break;
    default:
        return "";
        break;
    }
}

QString Wound::location() const
{
    return m_location;
}

Modifier *Wound::penalty() const
{
    return m_penalty;
}

Types::Wound Wound::type() const
{
    return m_type;
}

WoundData Wound::data() const
{
    return WoundData{
        .type = m_type,
        .location = m_location,
        .penalty = m_penalty->data()
    };
}
