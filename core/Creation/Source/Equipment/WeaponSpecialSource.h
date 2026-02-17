#ifndef WEAPONSPECIALSOURCE_H
#define WEAPONSPECIALSOURCE_H

#include <QObject>
#include <QQmlEngine>

class WeaponSpecialSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    QML_ELEMENT

public:
    explicit WeaponSpecialSource(QObject *parent = nullptr);
    WeaponSpecialSource(const QString& name, const QString& description, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // WEAPONSPECIALSOURCE_H
