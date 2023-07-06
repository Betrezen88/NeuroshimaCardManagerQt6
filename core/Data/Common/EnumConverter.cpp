#include "EnumConverter.h"


QString EnumConverter::woundToString(Types::Wound wound)
{
    switch (wound) {
    case Types::Wound::Scratch:
        return "Draśnięcie";
    case Types::Wound::Light:
        return "Lekka";
    case Types::Wound::Heavy:
        return "Ciężka";
    case Types::Wound::Critical:
        return "Krytyczna";
    default:
        return "";
        break;
    }
}

Types::Wound EnumConverter::stringToWound(const QString &wound)
{
    if ( "Draśnięcie" == wound ) {
        return Types::Wound::Scratch;
    }
    if ( "Lekka" == wound ) {
        return Types::Wound::Light;
    }
    if ( "Ciężka" == wound ) {
        return Types::Wound::Heavy;
    }
    if ( "Krytyczna" == wound ) {
        return Types::Wound::Critical;
    }
    return Types::Wound::Scratch;
}
