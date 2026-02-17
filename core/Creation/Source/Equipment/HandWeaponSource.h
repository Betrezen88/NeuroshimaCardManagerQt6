#ifndef HANDWEAPONSOURCE_H
#define HANDWEAPONSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include <QQmlEngine>

#include "ItemSource.h"
#include "HandWeaponBonusSource.h"
#include "HandWeaponDamageSource.h"
#include "WeaponSpecialSource.h"
#include "WeaponRequirementSource.h"

class HandWeaponSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    Q_PROPERTY(QQmlListProperty<HandWeaponBonusSource> bonuses READ bonuses CONSTANT)
    Q_PROPERTY(QQmlListProperty<HandWeaponDamageSource> damages READ damages CONSTANT)
    Q_PROPERTY(QQmlListProperty<WeaponSpecialSource> specials READ specials CONSTANT)
    Q_PROPERTY(WeaponRequirementSource* requirement READ requirement CONSTANT)
    Q_PROPERTY(quint8 penetration READ penetration CONSTANT)
    QML_ELEMENT

public:
    explicit HandWeaponSource(QObject *parent = nullptr);
    HandWeaponSource(const QString& name,
                     const QString& description,
                     const quint32 price,
                     const quint8 availability,
                     const QString& category,
                     const QVector<HandWeaponBonusSource*>& bonuses,
                     const QVector<HandWeaponDamageSource*>& damages,
                     const QVector<WeaponSpecialSource*>& specials,
                     WeaponRequirementSource* requirement,
                     const quint8 penetration,
                     QObject *parent = nullptr);

    Types::Item type() const;

    quint8 penetration() const;

    QQmlListProperty<HandWeaponBonusSource> bonuses();
    qsizetype bonusesCount() const;
    HandWeaponBonusSource* bonus(qsizetype index);

    QQmlListProperty<HandWeaponDamageSource> damages();
    qsizetype damageCount() const;
    HandWeaponDamageSource* damage(qsizetype index);

    QQmlListProperty<WeaponSpecialSource> specials();
    qsizetype specialsCount() const;
    WeaponSpecialSource* special(qsizetype index);

    WeaponRequirementSource *requirement() const;

private:
    static qsizetype bonusesCount(QQmlListProperty<HandWeaponBonusSource> *list);
    static HandWeaponBonusSource* bonus(QQmlListProperty<HandWeaponBonusSource> *list, qsizetype index);

    static qsizetype damageCount(QQmlListProperty<HandWeaponDamageSource> *list);
    static HandWeaponDamageSource* damage(QQmlListProperty<HandWeaponDamageSource> *list, qsizetype index);

    static qsizetype specialsCount(QQmlListProperty<WeaponSpecialSource> *list);
    static WeaponSpecialSource* special(QQmlListProperty<WeaponSpecialSource> *list, qsizetype index);

private:
    quint8 m_penetration{0};
    QVector<HandWeaponBonusSource*> m_bonuses;
    QVector<HandWeaponDamageSource*> m_damages;
    QVector<WeaponSpecialSource*> m_specials;
    WeaponRequirementSource *m_requirement{nullptr};
    Types::Item m_type{Types::Item::HandWeapon};
};

#endif // HANDWEAPONSOURCE_H
