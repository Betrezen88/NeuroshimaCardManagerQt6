#include "StatisticsCreation.h"

#include "AttributeBonusList.h"

StatisticsCreation::StatisticsCreation(QObject *parent)
    : QObject{parent}
{
    init();
}

StatisticsCreation::StatisticsCreation(const QVector<AttributeCreation *> &attributes, QObject *parent)
    : QObject{parent}
    , m_attributes{attributes}
{
    init();
    for ( AttributeCreation* attribute: m_attributes ) {
        attribute->setParent(this);
    }
}

DiseaseSource *StatisticsCreation::disease() const
{
    return m_disease;
}

void StatisticsCreation::setDisease(DiseaseSource *newDisease)
{
    if (m_disease == newDisease)
        return;
    m_disease = newDisease;
    emit diseaseChanged();
}

OriginSource *StatisticsCreation::origin() const
{
    return m_origin;
}

void StatisticsCreation::setOrigin(OriginSource *newOrigin)
{
    if (m_origin == newOrigin)
        return;

    m_origin = newOrigin;
    setAttributeBonus(m_origin->bonus());

    emit originChanged();
}

FeatureSource *StatisticsCreation::originFeature() const
{
    return m_originFeature;
}

void StatisticsCreation::setOriginFeature(FeatureSource *newOriginFeature)
{
    if (m_originFeature == newOriginFeature)
        return;

    if (m_originFeature != nullptr)
        emit removeFeatureBonus(m_originFeature->bonus());

    m_originFeature = newOriginFeature;

    if (m_originFeature != nullptr)
        emit applyFeatureBonus(m_originFeature->bonus());

    emit originFeatureChanged();
}

AttributeBonusSource *StatisticsCreation::attributeBonus() const
{
    return m_attributeBonus;
}

void StatisticsCreation::setAttributeBonus(AttributeBonusSource *newAttributeBonus)
{
    if (m_attributeBonus == newAttributeBonus)
        return;
    emit removeAttributeBonus(m_attributeBonus);
    m_attributeBonus = newAttributeBonus;
    emit applyAttributeBonus(m_attributeBonus);
    emit attributeBonusChanged();
}

ProfessionSource *StatisticsCreation::profession() const
{
    return m_profession;
}

void StatisticsCreation::setProfession(ProfessionSource *newProfession)
{
    if (m_profession == newProfession)
        return;
    m_profession = newProfession;
    emit professionChanged();
}

FeatureSource *StatisticsCreation::professionFeature() const
{
    return m_professionFeature;
}

void StatisticsCreation::setProfessionFeature(FeatureSource *newProfessionFeature)
{
    if (m_professionFeature == newProfessionFeature)
        return;
    m_professionFeature = newProfessionFeature;
    emit professionFeatureChanged();
}

SpecializationSource *StatisticsCreation::specialization() const
{
    return m_specialization;
}

void StatisticsCreation::setSpecialization(SpecializationSource *newSpecialization)
{
    if (m_specialization == newSpecialization)
        return;
    m_specialization = newSpecialization;
    emit specializationChanged();
}

QQmlListProperty<AttributeCreation> StatisticsCreation::attributes()
{
    return QQmlListProperty<AttributeCreation>(this, this,
                                               &StatisticsCreation::attributesCount,
                                               &StatisticsCreation::attribute);
}

qsizetype StatisticsCreation::attribitesCount() const
{
    return m_attributes.count();
}

AttributeCreation *StatisticsCreation::attribute(qsizetype index)
{
    return m_attributes.at(index);
}

AttributeCreation *StatisticsCreation::attribute(const QString &name)
{
    auto found = std::find_if(m_attributes.constBegin(), m_attributes.constEnd(), [&name](const AttributeCreation* attribute){
        return name == attribute->source()->name();
    });

    return *found;
}

void StatisticsCreation::onRemoveAttributeBonus(const AttributeBonusSource *bonus)
{
    if ( bonus == nullptr )
        return;

    auto found = std::find_if(m_attributes.begin(), m_attributes.end(), [&bonus](const AttributeCreation* attribute){
        return bonus->name() == attribute->source()->name();
    });

    if ( found != m_attributes.end() ) {
        (*found)->setBonus(0);
    }

    if ( Types::AttributeBonus::List == bonus->type() ) {
        const AttributeBonusList* listBonus = static_cast<const AttributeBonusList*>(bonus);
        disconnect(listBonus, &AttributeBonusList::nameWasChanged, this, &StatisticsCreation::onAttributeBonusListChanged);
    }
}

void StatisticsCreation::onApplyAttributeBonus(const AttributeBonusSource *bonus)
{
    if ( bonus == nullptr )
        return;

    auto found = std::find_if(m_attributes.begin(), m_attributes.end(), [&bonus](const AttributeCreation* attribute){
        return bonus->name() == attribute->source()->name();
    });

    if ( found != m_attributes.end() ) {
        (*found)->setBonus(bonus->value());
    }

    if ( Types::AttributeBonus::List == bonus->type() ) {
        const AttributeBonusList* listBonus = static_cast<const AttributeBonusList*>(bonus);
        connect(listBonus, &AttributeBonusList::nameWasChanged, this, &StatisticsCreation::onAttributeBonusListChanged);
    }
}

void StatisticsCreation::onApplyFeatureBonus(const BonusSource *bonus)
{
    if ( bonus == nullptr )
        return;

}

void StatisticsCreation::onRemoveFeatureBonus(const BonusSource *bonus)
{
    if ( bonus == nullptr )
        return;
}

void StatisticsCreation::onAttributeBonusListChanged(const QString &from, const QString &to)
{
    auto remove = std::find_if(m_attributes.begin(), m_attributes.end(), [&from](const AttributeCreation* attribute){
        return from == attribute->source()->name();
    });

    if ( remove != m_attributes.end() ) {
        (*remove)->setBonus(0);
    }

    auto apply = std::find_if(m_attributes.begin(), m_attributes.end(), [&to](const AttributeCreation* attribute){
        return to == attribute->source()->name();
    });

    if ( apply != m_attributes.end() ) {
        (*apply)->setBonus(m_origin->bonus()->value());
    }
}

void StatisticsCreation::onSkillpackChanged(const QString &from, const QString &to, const int value)
{
    SkillpackCreation* fromSkillpack = from.isEmpty() ? nullptr : findSkillpack(from);
    SkillpackCreation* toSkillpack = to.isEmpty() ? nullptr : findSkillpack(to);

    if ( fromSkillpack != nullptr ) {
        fromSkillpack->decreaseSkillsBy(value);
    }

    if ( toSkillpack != nullptr ) {
        toSkillpack->increaseSkillsBy(value);
    }
}

void StatisticsCreation::init()
{
    connect(this, &StatisticsCreation::applyAttributeBonus, this, &StatisticsCreation::onApplyAttributeBonus);
    connect(this, &StatisticsCreation::removeAttributeBonus, this, &StatisticsCreation::onRemoveAttributeBonus);
}

SkillpackCreation *StatisticsCreation::findSkillpack(const QString &name)
{
    for ( const AttributeCreation* attribute: m_attributes ) {
        const QVector<SkillpackCreation*>& skillpacks = attribute->skillpacks();
        auto found = std::find_if(skillpacks.constBegin(), skillpacks.constEnd(), [&name](const SkillpackCreation* skillpack){
            return skillpack->source()->name() == name;
        });

        if ( found != skillpacks.constEnd() ) {
            return *found;
        }
    }
    return nullptr;
}

qsizetype StatisticsCreation::attributesCount(QQmlListProperty<AttributeCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->attribitesCount();
}

AttributeCreation *StatisticsCreation::attribute(QQmlListProperty<AttributeCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->attribute(index);
}
