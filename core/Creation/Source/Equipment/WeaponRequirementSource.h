#ifndef WEAPONREQUIREMENTSOURCE_H
#define WEAPONREQUIREMENTSOURCE_H

#include <QObject>
#include <QQmlEngine>

class WeaponRequirementSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(quint8 value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit WeaponRequirementSource(QObject *parent = nullptr);
    WeaponRequirementSource(const QString& attribute, const quint8 value, QObject *parent = nullptr);

    QString attribute() const;
    quint8 value() const;

private:
    QString m_attribute;
    quint8 m_value;
};

#endif // WEAPONREQUIREMENTSOURCE_H
