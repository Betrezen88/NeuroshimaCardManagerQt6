#ifndef RANGEWEAPONSOURCE_H
#define RANGEWEAPONSOURCE_H

#include <QQmlEngine>
#include <QQmlListProperty>

#include "ItemSource.h"
#include "WeaponRequirementSource.h"
#include "WeaponSpecialSource.h"

class RangeWeaponSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    Q_PROPERTY(QString damage READ damage CONSTANT)
    Q_PROPERTY(quint8 penetration READ penetration CONSTANT)
    Q_PROPERTY(QStringList ammunition READ ammunition CONSTANT)
    Q_PROPERTY(quint8 firerate READ firerate CONSTANT)
    Q_PROPERTY(QVector<quint32> magazine READ magazine CONSTANT)
    Q_PROPERTY(WeaponRequirementSource* requirement READ requirement CONSTANT)
    Q_PROPERTY(QQmlListProperty<WeaponSpecialSource> specials READ specials CONSTANT)
    QML_ELEMENT

public:
    explicit RangeWeaponSource(QObject *parent = nullptr);
    RangeWeaponSource(const QString& name,
                      const QString& description,
                      const quint32 price,
                      const quint8 availability,
                      const QString& category,
                      const QString& damage,
                      const quint8 penetration,
                      const QStringList& ammunition,
                      const quint8 firerate,
                      const QVector<quint32>& magazine,
                      WeaponRequirementSource* requirement,
                      const QVector<WeaponSpecialSource*>& specials,
                      QObject *parent = nullptr);

    Types::Item type() const;
    QString damage() const;
    quint8 penetration() const;
    QStringList ammunition() const;
    quint8 firerate() const;
    QVector<quint32> magazine() const;
    WeaponRequirementSource *requirement() const;

    QQmlListProperty<WeaponSpecialSource> specials();
    qsizetype specialsCount() const;
    WeaponSpecialSource* special(qsizetype index);

private:
    static qsizetype specialsCount(QQmlListProperty<WeaponSpecialSource> *list);
    static WeaponSpecialSource* special(QQmlListProperty<WeaponSpecialSource> *list, qsizetype index);

private:
    Types::Item m_type{Types::Item::RangeWeapon};
    QString m_damage;
    quint8 m_penetration{0};
    QStringList m_ammunition;
    quint8 m_firerate{0};
    QVector<quint32> m_magazine;
    WeaponRequirementSource *m_requirement{nullptr};
    QVector<WeaponSpecialSource*> m_specials;
};

#endif // RANGEWEAPONSOURCE_H
