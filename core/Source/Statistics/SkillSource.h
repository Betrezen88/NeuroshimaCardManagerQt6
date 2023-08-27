#ifndef SKILLSOURCE_H
#define SKILLSOURCE_H

#include "qqmlintegration.h"
#include <QObject>

class SkillSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    QML_ELEMENT

public:
    explicit SkillSource(QObject *parent = nullptr);
    explicit SkillSource(const QString& name, const QString& description, QObject* parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SKILLSOURCE_H
