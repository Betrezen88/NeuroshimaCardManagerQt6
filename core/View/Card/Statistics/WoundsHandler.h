#ifndef WOUNDSHANDLER_H
#define WOUNDSHANDLER_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../Statistics/Wound.h"

class WoundsHandler : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QQmlListProperty<Wound> wounds READ wounds NOTIFY woundsChanged)
    Q_PROPERTY(QStringList locations READ locations CONSTANT)
    Q_PROPERTY(QStringList woundTypes READ woundTypes CONSTANT)

public:
    explicit WoundsHandler(QObject *parent = nullptr);
    explicit WoundsHandler(const QVector<WoundData> &wounds, QObject *parent = nullptr);

    QQmlListProperty<Wound> wounds();
    void addWound(Wound* wound);
    qsizetype woundsCount() const;
    Wound* wound(qsizetype index);
    void clearWounds();

    Q_INVOKABLE QString woundsForLocation(const QString& location);
    Q_INVOKABLE void addWound(const QString& name, const QString& location, int penalty);

    QStringList locations() const;
    QStringList woundTypes() const;

    QVector<WoundData> data() const;

signals:
    void woundsChanged();

private:
    static void addWound(QQmlListProperty<Wound> *list, Wound* wound);
    static qsizetype woundsCount(QQmlListProperty<Wound> *list);
    static Wound* wound(QQmlListProperty<Wound> *list, qsizetype index);
    static void clearWounds(QQmlListProperty<Wound> *list);

private:
    QVector<Wound*> m_wounds;
    const QStringList m_locations{ "Głowa", "Lewa ręka", "Prawa ręka", "Tors", "Lewa noga", "Prawa noga" };
};

#endif // WOUNDSHANDLER_H
