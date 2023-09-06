#ifndef SKILLPACKSOURCE_H
#define SKILLPACKSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "SkillSource.h"

class SkillpackSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList specializations READ specializations CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillSource> skills READ skills CONSTANT)
    QML_ELEMENT

public:
    explicit SkillpackSource(QObject *parent = nullptr);
    explicit SkillpackSource(const QString& name,
                             const QStringList& specializations,
                             const QVector<SkillSource*>& skills,
                             QObject* parent = nullptr);

    QString name() const;
    QStringList specializations() const;
    Q_INVOKABLE const QString specializationsShort() const;

    QQmlListProperty<SkillSource> skills();
    qsizetype skillsCount() const;
    SkillSource* skill(qsizetype index);

    const QVector<SkillSource *> &skills() const;

private:
    static qsizetype skillsCount(QQmlListProperty<SkillSource> *list);
    static SkillSource* skill(QQmlListProperty<SkillSource> *list, qsizetype index);

private:
    QString m_name;
    QStringList m_specializations;
    QVector<SkillSource*> m_skills;
};

#endif // SKILLPACKSOURCE_H
