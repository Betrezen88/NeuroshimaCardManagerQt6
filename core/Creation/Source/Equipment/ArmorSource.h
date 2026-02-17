#ifndef ARMORSOURCE_H
#define ARMORSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include <QQmlEngine>

#include "DefenceSource.h"
#include "ItemSource.h"

class ArmorSource : public ItemSource
{
    Q_OBJECT
    Q_PROPERTY(Types::Item type READ type CONSTANT)
    Q_PROPERTY(quint8 durability READ durability CONSTANT)
    Q_PROPERTY(QQmlListProperty<DefenceSource> defence READ defence CONSTANT)
    QML_ELEMENT

public:
    explicit ArmorSource(QObject *parent = nullptr);
    ArmorSource(const QString& name,
                const QString& description,
                const quint32 price,
                const quint8 availability,
                const QString& category,
                const quint8 durability,
                const QVector<DefenceSource*>& defence,
                QObject *parent = nullptr);

    Types::Item type() const;

    quint8 durability() const;

    QQmlListProperty<DefenceSource> defence();
    qsizetype defenceCount() const;
    DefenceSource* defence(qsizetype index);

private:
    static qsizetype defenceCount(QQmlListProperty<DefenceSource> *list);
    static DefenceSource* defence(QQmlListProperty<DefenceSource> *list, qsizetype index);

private:
    Types::Item m_type{Types::Item::Armor};
    quint8 m_durability{0};
    QVector<DefenceSource*> m_defence;
};

#endif // ARMORSOURCE_H
