#ifndef TRICKSOURCE_H
#define TRICKSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include <QQmlEngine>

#include "../Common/RequirementSource.h"

class TrickSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<RequirementSource> requirements READ requirements CONSTANT)
    QML_ELEMENT

public:
    explicit TrickSource(QObject *parent = nullptr);
    explicit TrickSource(const QString& name,
                         const QString& description,
                         const QString& action,
                         const QVector<RequirementSource*>& requirements,
                         QObject* parent = nullptr);

    QString name() const;
    QString description() const;
    QString action() const;

    QQmlListProperty<RequirementSource> requirements();
    qsizetype requirementsCount() const;
    RequirementSource* requirement(qsizetype index);

    QVector<RequirementSource*> requirementsVec();

private:
    static qsizetype requirementsCount(QQmlListProperty<RequirementSource> *list);
    static RequirementSource* requirement(QQmlListProperty<RequirementSource> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QString m_action;
    QVector<RequirementSource*> m_requirements;
};

#endif // TRICKSOURCE_H
