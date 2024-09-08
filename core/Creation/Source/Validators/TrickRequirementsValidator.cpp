#include "TrickRequirementsValidator.h"

TrickRequirementsValidator::TrickRequirementsValidator(QObject *parent)
    : QObject{parent}
{}

void TrickRequirementsValidator::validate(const QVector<AttributeCreation *> &attributes, const QVector<TrickSourceItem *> &tricks)
{
    for (TrickSourceItem* trick: tricks) {
        qDebug() <<  trick->source()->name();
        const auto requirements = trick->source()->requirementsVec();

        bool available{true};
        for (const auto requirement: requirements) {
            available = meetsRequirement(attributes, requirement);
            if (!available)
                break;
        }
        trick->setAvailable( available );
    }
}

bool TrickRequirementsValidator::meetsRequirement(const QVector<AttributeCreation*>& attributes,const RequirementSource *requirement)
{
    bool meetRequirement{true};
    for ( const AttributeCreation* attribute: attributes ) {
        if ( requirement->type() == Types::Requirement::Attribute ) {
            if ( requirement->name() == attribute->source()->name() )
                meetRequirement = attribute->value() >= requirement->value();
        }

        if ( requirement->type() == Types::Requirement::Skill ) {
            for ( const SkillpackCreation* skillpack: attribute->skillpacks() ) {
                for ( const SkillCreation* skill: skillpack->skills() ) {
                    if ( requirement->name() == skill->source()->name() ) {
                        meetRequirement = skill->value() >= requirement->value();
                    }
                }
            }
        }

        if (!meetRequirement) {
            return false;
        }
    }

    return true;
}
