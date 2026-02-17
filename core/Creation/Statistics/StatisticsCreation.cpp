#include "StatisticsCreation.h"

#include "AttributeBonusList.h"
#include <Bonus/BonusSkillpack.h>

#include <../Utils/Dice.h>

#include <QDebug>

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

StatisticsCreation::StatisticsCreation(const QVector<AttributeCreation *> &attributes, const QStringList &places, QObject *parent)
    : QObject(parent)
    , m_attributes(attributes)
{
    for ( const QString& place: places ) {
        m_reputations.append( new ReputationCreation(place, 0, 1, this) );
    }
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

    if (m_origin != nullptr)
        removeReputationPoint( m_origin->name() );

    m_origin = newOrigin;

    applyReputationPoint( m_origin->name() );
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
    emit specializationChangedTo(m_specialization->name());
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

QStringList StatisticsCreation::attributesNames() const
{
    QStringList list;
    for ( auto attribute: m_attributes ) {
        list << attribute->source()->name();
    }
    return list;
}

QQmlListProperty<OtherSkillCreation> StatisticsCreation::otherSkills()
{
    return QQmlListProperty<OtherSkillCreation>(this, this,
                                                &StatisticsCreation::otherSkillsCount,
                                                &StatisticsCreation::otherSkill);
}

qsizetype StatisticsCreation::otherSkillsCount() const
{
    return m_otherSkills.count();
}

OtherSkillCreation *StatisticsCreation::otherSkill(qsizetype index)
{
    return m_otherSkills.at(index);
}

void StatisticsCreation::addOtherSkill(const QString &name, const QString &description, const QString &attribute)
{
    OtherSkillCreation* otherSkill = new OtherSkillCreation(new OtherSkillSource(name, description, attribute), this);
    m_otherSkills.append( otherSkill );
    emit otherSkillAdded( otherSkill );
    emit otherSkillsChanged();
}

void StatisticsCreation::removeOtherSkill(OtherSkillCreation *otherSkill)
{
    if ( otherSkill->value() > 0 ) {
        while (otherSkill->value() > 0) {
            otherSkill->decrease();
        }
    }

    m_otherSkills.removeOne( otherSkill );
    m_otherSkills.squeeze();
    otherSkill->deleteLater();
    emit otherSkillsChanged();
}

bool StatisticsCreation::isSkillNameTaken(const QString &name)
{
    auto otherSkillFound = std::find_if(m_otherSkills.constBegin(), m_otherSkills.constEnd(), [&name](const OtherSkillCreation* otherSkill){
        return name.toUpper() == otherSkill->source()->name().toUpper();
    });

    return otherSkillFound != m_otherSkills.constEnd();
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
    emit statsChanged( m_attributes );
}

void StatisticsCreation::onApplyFeatureBonus(const BonusSource *bonus)
{
    if ( bonus == nullptr )
        return;

    switch (bonus->type()) {
    case Types::Bonus::Pet:
        qDebug() << "Add step to create your pet.";
        break;
    case Types::Bonus::Health:
        qDebug() << "Set deases to none.";
        break;
    case Types::Bonus::Fame:
        qDebug() << "Set Fame bonus";
        break;
    case Types::Bonus::Features:
        qDebug() << "Gather all features except one with bonus type features.";
        break;
    case Types::Bonus::Connections:
        qDebug() << "Connections cash";
        break;
    case Types::Bonus::Reputation:
        qDebug() << "Set Reputation bonus";
        break;
    case Types::Bonus::Skillpoints:
        qDebug() << "Make connection to check if specialization is correct and increase skillpoints";
        break;
    case Types::Bonus::Skills:
        qDebug() << "Set all skills with value equal to 0 with highest value to 1.";
        break;
    case Types::Bonus::Skillpack: {
        connect(static_cast<const BonusSkillpack*>(bonus), &BonusSkillpack::selectedWasChanged,
                this, [this, bonus](const QString& from, const QString& to){
                    onSkillpackChanged(from, to, static_cast<const BonusSkillpack*>(bonus)->value());
        });
        auto bonusSkillpack = static_cast<const BonusSkillpack*>(bonus);
        const_cast<BonusSkillpack*>(bonusSkillpack)->setSelected(bonusSkillpack->list().constFirst());
        break;
    }
    case Types::Bonus::Trick:
        qDebug() << "Add trick to hero.";
        break;
    default:
        break;
    }
}

void StatisticsCreation::onRemoveFeatureBonus(const BonusSource *bonus)
{
    if ( bonus == nullptr )
        return;

    switch (bonus->type()) {
    case Types::Bonus::Pet:
        qDebug() << "Remove step to create your pet.";
        break;
    case Types::Bonus::Health:
        qDebug() << "Remove Health .";
        break;
    case Types::Bonus::Fame:
        qDebug() << "Remove Fame bonus";
        break;
    case Types::Bonus::Features:
        qDebug() << "Gather all features except one with bonus type features.";
        break;
    case Types::Bonus::Connections:
        qDebug() << "Connections cash";
        break;
    case Types::Bonus::Reputation:
        qDebug() << "Set Reputation bonus";
        break;
    case Types::Bonus::Skillpoints: {
        qDebug() << "Make connection to check if specialization is correct and increase skillpoints";
        // connect signal on specialization changed
        // increase specialization skillpoints if current specialization is equal from bonus
        break;
    }
    case Types::Bonus::Skills:
        qDebug() << "Set all skills with value equal to 0 with highest value to 1.";
        break;
    case Types::Bonus::Skillpack: {
        auto bonusSkillpack = static_cast<const BonusSkillpack*>(bonus);
        onSkillpackChanged(bonusSkillpack->selected(), "", bonusSkillpack->value());
        break;
    }
    case Types::Bonus::Trick:
        qDebug() << "Add trick to hero.";
        break;
    default:
        break;
    }
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
    emit statsChanged( m_attributes );
}

void StatisticsCreation::onTrickSold(TrickSource *trick)
{
    auto found = std::find_if(m_tricks.constBegin(), m_tricks.constEnd(), [&trick](const TrickCreation *trickItem){
        return trickItem->source() == trick;
    });
    m_tricks.takeAt(m_tricks.indexOf(*found))->deleteLater();
    emit tricksChanged();
}

void StatisticsCreation::removeReputationPoint(const QString &place)
{
    auto found = std::find_if(m_reputations.constBegin(), m_reputations.constEnd(), [&place](const ReputationCreation* reputation){
        return reputation->place().toLower() == place.toLower();
    });

    if ( found != m_reputations.constEnd() ) {
        (*found)->decrease();
    } else {
        found = std::find_if(m_reputations.constBegin(), m_reputations.constEnd(), [](const ReputationCreation* reputation){
            return reputation->value() > 0;
        });
        if ( found != m_reputations.constEnd() ) {
            (*found)->decrease();
        }
    }
}

void StatisticsCreation::applyReputationPoint(const QString &place)
{
    auto found = std::find_if(m_reputations.constBegin(), m_reputations.constEnd(), [&place](const ReputationCreation* reputation){
        return reputation->place().toLower() == place.toLower();
    });

    bool isReputationGeneralPoint{true};

    if ( found != m_reputations.constEnd() ) {
        (*found)->increase();
        isReputationGeneralPoint = false;
    }
    emit reputationGeneralPoint( isReputationGeneralPoint );
}

void StatisticsCreation::init()
{
    connect(this, &StatisticsCreation::trickSold, this, &StatisticsCreation::onTrickSold);
    connect(this, &StatisticsCreation::applyAttributeBonus, this, &StatisticsCreation::onApplyAttributeBonus);
    connect(this, &StatisticsCreation::removeAttributeBonus, this, &StatisticsCreation::onRemoveAttributeBonus);
    connect(this, &StatisticsCreation::applyFeatureBonus, this, &StatisticsCreation::onApplyFeatureBonus);
    connect(this, &StatisticsCreation::removeFeatureBonus, this, &StatisticsCreation::onRemoveFeatureBonus);

    for ( const AttributeCreation* attribute: m_attributes ) {
        connect(attribute, &AttributeCreation::valueChanged, this, [this](){ emit this->statsChanged(m_attributes); });
        connect(attribute, &AttributeCreation::bonusChanged, this, [this](){ emit this->statsChanged(m_attributes); });
        for ( const SkillpackCreation* skillpack: attribute->skillpacks() ) {
            connect(skillpack, &SkillpackCreation::skillIncreased, this, [this](const QStringList& specializations, const int level){
                Q_UNUSED(specializations)
                Q_UNUSED(level)
                emit this->statsChanged(m_attributes);
            });
            connect(skillpack, &SkillpackCreation::skillDecreased, this, [this](const QStringList& specializations, const int level){
                Q_UNUSED(specializations);
                Q_UNUSED(level);
                emit this->statsChanged(m_attributes);
            });
            connect(skillpack, &SkillpackCreation::boughtChanged, this, [this, skillpack](const bool bought){
                Q_UNUSED(bought);
                emit this->statsChanged(m_attributes);
            });
        }
    }
    for ( const ReputationCreation* reputation: m_reputations ) {
        connect(reputation, &ReputationCreation::increased, this, &StatisticsCreation::reputationIncreased);
        connect(reputation, &ReputationCreation::decreased, this, &StatisticsCreation::reputationDecreased);
    }
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

qsizetype StatisticsCreation::otherSkillsCount(QQmlListProperty<OtherSkillCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->otherSkillsCount();
}

OtherSkillCreation* StatisticsCreation::otherSkill(QQmlListProperty<OtherSkillCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->otherSkill(index);
}

qsizetype StatisticsCreation::tricksCount(QQmlListProperty<TrickCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->tricksCount();
}

TrickCreation *StatisticsCreation::trick(QQmlListProperty<TrickCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->trick(index);
}

qsizetype StatisticsCreation::reputationsCount(QQmlListProperty<ReputationCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->reputationsCount();
}

ReputationCreation *StatisticsCreation::reputation(QQmlListProperty<ReputationCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->reputation(index);
}

qsizetype StatisticsCreation::answersCount(QQmlListProperty<AnswerCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->answersCount();
}

AnswerCreation *StatisticsCreation::answer(QQmlListProperty<AnswerCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->answer(index);
}

qsizetype StatisticsCreation::itemsCount(QQmlListProperty<ItemCreation> *list)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->itemsCount();
}

ItemCreation *StatisticsCreation::item(QQmlListProperty<ItemCreation> *list, qsizetype index)
{
    return reinterpret_cast<StatisticsCreation*>(list->data)->item(index);
}

void StatisticsCreation::onTrickBougth(TrickSource *trick)
{
    m_tricks.append(new TrickCreation(trick, this));
    emit tricksChanged();
}

void StatisticsCreation::onItemBougth(ItemSource *source)
{
    auto found = std::find(m_items.begin(), m_items.end(), [&source](const ItemCreation *item){
        return item->source() == source;
    });

    if (found != m_items.end()) {
        (*found)->increase();
    }
    else {
        m_items.append(new ItemCreation(source));
    }
}

void StatisticsCreation::onItemSold(const quint32 index)
{
    qDebug() << "StatisticsCreation::onItemSold() " << index;

    auto item = m_items.at(index);
    if (item->quantity() > 1) {
        item->decrease();
    }
    else {
        m_items.removeAt(index);
        emit itemsChanged();
    }
}

void StatisticsCreation::setQuestionsSource(QVector<QuestionSource *> questions)
{
    m_answers.clear();
    for ( QuestionSource* question: questions ) {
        m_answers.append( new AnswerCreation(question, this) );
    }
    emit answersChanged();
}

QQmlListProperty<TrickCreation> StatisticsCreation::tricks()
{
    return QQmlListProperty<TrickCreation>(this, this,
                                           &StatisticsCreation::tricksCount,
                                           &StatisticsCreation::trick);
}

qsizetype StatisticsCreation::tricksCount() const
{
    return m_tricks.count();
}

TrickCreation *StatisticsCreation::trick(qsizetype index)
{
    return m_tricks.at(index);
}

QQmlListProperty<ReputationCreation> StatisticsCreation::reputations()
{
    return QQmlListProperty<ReputationCreation>(this, this,
                                                &StatisticsCreation::reputationsCount,
                                                &StatisticsCreation::reputation);
}

qsizetype StatisticsCreation::reputationsCount() const
{
    return m_reputations.count();
}

ReputationCreation *StatisticsCreation::reputation(qsizetype index)
{
    return m_reputations.at(index);
}

QQmlListProperty<AnswerCreation> StatisticsCreation::answers()
{
    return QQmlListProperty<AnswerCreation>(this, this,
                                            &StatisticsCreation::answersCount,
                                            &StatisticsCreation::answer);
}

qsizetype StatisticsCreation::answersCount() const
{
    return m_answers.count();
}

AnswerCreation *StatisticsCreation::answer(qsizetype index)
{
    return m_answers.at(index);
}

QQmlListProperty<ItemCreation> StatisticsCreation::items()
{
    return QQmlListProperty<ItemCreation>(this, this,
                                            &StatisticsCreation::itemsCount,
                                            &StatisticsCreation::item);
}

qsizetype StatisticsCreation::itemsCount() const
{
    return m_items.count();
}

ItemCreation *StatisticsCreation::item(qsizetype index)
{
    return m_items.at(index);
}
