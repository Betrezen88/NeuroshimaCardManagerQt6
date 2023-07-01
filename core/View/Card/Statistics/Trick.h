#ifndef TRICK_H
#define TRICK_H

#include <QObject>
#include <QQmlListProperty>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/TrickData.h"
#include "Requirement.h"

class Trick : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)

public:
    explicit Trick(QObject *parent = nullptr);
    explicit Trick(const TrickData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    QString action() const;

    QQmlListProperty<Requirement> requirements();
    qsizetype requirementsCount() const;
    Requirement* requirement(qsizetype index);

    Q_INVOKABLE QString requirementsString() const;

    TrickData data() const;

private:
    static qsizetype requirementsCount(QQmlListProperty<Requirement> *list);
    static Requirement* requirement(QQmlListProperty<Requirement> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QString m_action;
    QVector<Requirement*> m_requirements;
};

#endif // TRICK_H
