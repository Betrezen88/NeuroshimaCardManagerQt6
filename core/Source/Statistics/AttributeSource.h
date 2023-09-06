#ifndef ATTRIBUTESOURCE_H
#define ATTRIBUTESOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "SkillpackSource.h"

class AttributeSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillpackSource> skillpacks READ skillpacks CONSTANT)
    QML_ELEMENT
public:
    explicit AttributeSource(QObject *parent = nullptr);
    explicit AttributeSource(const QString& name,
                             const QString& description,
                             const QVector<SkillpackSource*>& skillpacks,
                             QObject* parent = nullptr);

    QString name() const;
    QString description() const;

    QQmlListProperty<SkillpackSource> skillpacks();
    qsizetype skillpacksCount() const;
    SkillpackSource* skillpack(qsizetype index);

    const QVector<SkillpackSource*>& skillpacks() const;

private:
    static qsizetype skillpacksCount(QQmlListProperty<SkillpackSource> *list);
    static SkillpackSource* skillpack(QQmlListProperty<SkillpackSource> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QVector<SkillpackSource*> m_skillpacks;
};

#endif // ATTRIBUTESOURCE_H
