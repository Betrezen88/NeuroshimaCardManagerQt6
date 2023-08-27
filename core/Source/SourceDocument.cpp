#include "SourceDocument.h"

SourceDocument::SourceDocument(QObject *parent)
    : QObject{parent}
{

}

SourceDocument::SourceDocument(const QString &type, const QString &name, const QJsonDocument &document, QObject *parent)
    : QObject{parent}
    , m_type{stringToType(type)}
    , m_name{name}
    , m_document{document}
{

}

SourceDocument::Type SourceDocument::type() const
{
    return m_type;
}

QString SourceDocument::name() const
{
    return m_name;
}

QJsonDocument SourceDocument::document() const
{
    return m_document;
}

SourceDocument::Type SourceDocument::stringToType(const QString &string)
{
    if ( "Attributes" == string )
        return SourceDocument::Type::Attributes;
    if ( "Origins" == string )
        return SourceDocument::Type::Origins;
    if ( "Professions" == string )
        return SourceDocument::Type::Professions;
    if ( "Diseases" == string )
        return SourceDocument::Type::Diseases;
    if ( "Features" == string )
        return SourceDocument::Type::Features;
    if ( "Tricks" == string )
        return SourceDocument::Type::Tricks;
    if ( "Specializations" == string )
        return SourceDocument::Type::Specializations;

    return SourceDocument::Type::Unknown;
}

