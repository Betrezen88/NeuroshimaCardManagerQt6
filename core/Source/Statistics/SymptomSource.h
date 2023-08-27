#ifndef SYMPTOMSOURCE_H
#define SYMPTOMSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"

#include "../Common/ModifierSource.h"

class SymptomSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QQmlListProperty<ModifierSource> penalties READ penalties CONSTANT)
    QML_ELEMENT

public:
    explicit SymptomSource(QObject *parent = nullptr);
    explicit SymptomSource(const QString& name,
                           const QString& description,
                           const QVector<ModifierSource*>& penalties,
                           QObject* parent = nullptr);

    QString name() const;
    QString description() const;

    QQmlListProperty<ModifierSource> penalties();
    qsizetype penaltiesCount() const;
    ModifierSource* penalty(qsizetype index);

private:
    static qsizetype penaltiesCount(QQmlListProperty<ModifierSource> *list);
    static ModifierSource* penalty(QQmlListProperty<ModifierSource> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QVector<ModifierSource*> m_penalties;
};

#endif // SYMPTOMSOURCE_H
