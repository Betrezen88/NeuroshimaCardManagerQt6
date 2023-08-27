#include "SourceConverter.h"

#include "AttributeBonusSingle.h"
#include "AttributeBonusList.h"

#include "BonusBeast.h"
#include "BonusFame.h"
#include "BonusFeatures.h"
#include "BonusFriend.h"
#include "BonusHealth.h"
#include "BonusReputation.h"
#include "BonusSkills.h"
#include "BonusSkillpack.h"
#include "BonusSkillpackDL.h"
#include "BonusSkillpoints.h"
#include "BonusTrick.h"

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


AttributeBonusSource *SourceConverter::attributeBonus(const QJsonObject &object)
{
    const int value = object.value("value").toInt();
    if ( !object.value("name").isArray() ) {
        return new AttributeBonusSingle{object.value("name").toString(), value};
    }
    else {
        QStringList names;
        const QJsonArray& list = object.value("name").toArray();
        for ( const QJsonValue& name: list ) {
            names << name.toString();
        }
        return new AttributeBonusList{names, value};
    }
}

BonusSource *SourceConverter::featureBonus(const QJsonObject &object)
{
    if ( object.isEmpty() )
        return nullptr;

    const QString& type = object.value("type").toString();
    if ( "Pet" == type ) {
        return new BonusBeast{};
    }
    if ( "Health" == type ) {
        return new BonusHealth{};
    }
    if ( "Fame" == type ) {
        return new BonusFame{object.value("value").toInt(), object.value("price").toInt()};
    }
    if ( "Features" == type ) {
        return new BonusFeatures{};
    }
    if ( "Connections" == type ) {
        return new BonusFriend{object.value("value").toInt()};
    }
    if ( "Reputation" == type ) {
        return new BonusReputation{object.value("value").toInt(), object.value("price").toInt()};
    }
    if ( "Skillpoints" == type ) {
        return new BonusSkillpoints{object.value("specialization").toString(), object.value("value").toInt()};
    }
    if ( "Skills" == type ) {
        return new BonusSkills{object.value("value").toInt()};
    }
    if ( "Skillpack" == type ) {
        const QJsonArray& skillpacks = object.value("list").toArray();
        QStringList list;
        for ( const QJsonValue& skillpack: skillpacks ) {
            list << skillpack.toString();
        }
        return new BonusSkillpack{list, object.value("value").toInt()};
    }
    if ( "SkillpackDL" == type ) {
        const QJsonArray& skillpacks = object.value("list").toArray();
        QStringList list;
        for ( const QJsonValue& skillpack: skillpacks ) {
            list << skillpack.toString();
        }
        return new BonusSkillpackDL{list};
    }
    if ( "Trick" == type ) {
        return new BonusTrick{object.value("name").toString()};
    }
    return nullptr;
}
