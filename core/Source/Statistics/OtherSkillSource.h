#ifndef OTHERSKILLSOURCE_H
#define OTHERSKILLSOURCE_H

#include <QObject>
#include <QQmlEngine>

class OtherSkillSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    QML_ELEMENT

public:
    explicit OtherSkillSource(QObject *parent = nullptr);
    explicit OtherSkillSource(const QString& name, const QString& description, const QString& attribute, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    QString attribute() const;

private:
    QString m_name;
    QString m_description;
    QString m_attribute;
};

#endif // OTHERSKILLSOURCE_H
