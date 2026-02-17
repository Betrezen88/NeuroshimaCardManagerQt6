#ifndef HANDWEAPONBONUSSOURCE_H
#define HANDWEAPONBONUSSOURCE_H

#include <QObject>
#include <QQmlEngine>

class HandWeaponBonusSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(quint8 value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit HandWeaponBonusSource(QObject *parent = nullptr);
    HandWeaponBonusSource(const QString& name, const quint8 value, QObject *parent = nullptr);

    QString name() const;
    quint8 value() const;

signals:
private:
    QString m_name;
    quint8 m_value;
};

#endif // HANDWEAPONBONUSSOURCE_H
