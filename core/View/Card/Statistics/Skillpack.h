#ifndef SKILLPACK_H
#define SKILLPACK_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/SkillpackData.h"
#include "Skill.h"

class Skillpack : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList specializations READ specializations CONSTANT)
    Q_PROPERTY(QQmlListProperty<Skill> skills READ skills CONSTANT)

public:
    explicit Skillpack(QObject *parent = nullptr);
    explicit Skillpack(const SkillpackData &data, QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;

    QQmlListProperty<Skill> skills();
    qsizetype skillsCount() const;
    Skill* skill(qsizetype index);

    Q_INVOKABLE QString specializationsShort() const;

    SkillpackData data() const;

private:
    static qsizetype skillsCount(QQmlListProperty<Skill> *list);
    static Skill* skill(QQmlListProperty<Skill> *list, qsizetype index);

private:
    QString m_name;
    QStringList m_specializations;
    QVector<Skill*> m_skills;
};

#endif // SKILLPACK_H
