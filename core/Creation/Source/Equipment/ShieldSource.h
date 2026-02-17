#ifndef SHIELDSOURCE_H
#define SHIELDSOURCE_H

#include <QQmlListProperty>
#include <QQmlEngine>

#include "ItemSource.h"
#include "WeaponRequirementSource.h"
#include "HandWeaponBonusSource.h"
#include "HandWeaponDamageSource.h"

class ShieldSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    Q_PROPERTY(quint8 durability READ durability CONSTANT)
    Q_PROPERTY(WeaponRequirementSource* requirement READ requirement CONSTANT)
    Q_PROPERTY(QQmlListProperty<HandWeaponBonusSource> bonuses READ bonuses CONSTANT)
    Q_PROPERTY(HandWeaponDamageSource* damage READ damage CONSTANT)
    QML_ELEMENT

public:
    explicit ShieldSource(QObject *parent = nullptr);
    ShieldSource(const QString& name,
                 const QString& description,
                 const quint32 price,
                 const quint8 availability,
                 const QString& category,
                 const quint8 durability,
                 WeaponRequirementSource* requirement,
                 const QVector<HandWeaponBonusSource*>& bonuses,
                 HandWeaponDamageSource* damage,
                 QObject *parent = nullptr);

    Types::Item type() const;
    quint8 durability() const;

    WeaponRequirementSource* requirement() const;

    QQmlListProperty<HandWeaponBonusSource> bonuses();
    qsizetype bonusesCount() const;
    HandWeaponBonusSource* bonus(qsizetype index);

    HandWeaponDamageSource *damage() const;

private:
    static qsizetype bonusesCount(QQmlListProperty<HandWeaponBonusSource> *list);
    static HandWeaponBonusSource* bonus(QQmlListProperty<HandWeaponBonusSource> *list, qsizetype index);

private:
    Types::Item m_type{Types::Item::Shield};
    quint8 m_durability;
    WeaponRequirementSource* m_requirement{nullptr};
    QVector<HandWeaponBonusSource*> m_bonuses;
    HandWeaponDamageSource *m_damage{nullptr};
};

#endif // SHIELDSOURCE_H
