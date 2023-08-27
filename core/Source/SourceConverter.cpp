#include "SourceConverter.h"


#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include <QDebug>

SourceConverter::SourceConverter()
{

}

void SourceConverter::convertSourceDocument(const SourceDocument &document)
{
    switch (document.type()) {
    case SourceDocument::Type::Specializations:
        convertSpecializations(document);
        break;
    default:
        qDebug() << "Unknown type.";
        break;
    }
}
    }
}


void SourceConverter::convertSpecializations(const SourceDocument &document)
{
    const QJsonArray& data = document.document().array();
    if ( data.isEmpty() ) {
        return;
    }

    QVector<SpecializationSource*> specilizationSources;
    for ( const QJsonValue& specialization: data ) {
        const QJsonObject& spec = specialization.toObject();
        specilizationSources.append( new SpecializationSource{spec.value("name").toString(), spec.value("description").toString()} );
    }

    emit specializationsConverted(specilizationSources);
}

