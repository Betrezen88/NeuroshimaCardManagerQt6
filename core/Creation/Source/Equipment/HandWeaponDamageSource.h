#ifndef HANDWEAPONDAMAGESOURCE_H
#define HANDWEAPONDAMAGESOURCE_H

#include <QObject>
#include <QQmlEngine>

class HandWeaponDamageSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(quint8 value READ value CONSTANT)
    Q_PROPERTY(QStringList wounds READ wounds CONSTANT)
    QML_ELEMENT

public:
    explicit HandWeaponDamageSource(QObject *parent = nullptr);
    HandWeaponDamageSource(const QString& attribute, const quint8 value, const QStringList& wounds, QObject *parent = nullptr);

    QString attribute() const;
    quint8 value() const;
    QStringList wounds() const;

private:
    QString m_attribute;
    quint8 m_value;
    QStringList m_wounds;
};

#endif // HANDWEAPONDAMAGESOURCE_H
