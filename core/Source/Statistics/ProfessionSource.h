#ifndef PROFESSIONSOURCE_H
#define PROFESSIONSOURCE_H

#include <QObject>
#include <QQmlListProperty>
#include "qqmlintegration.h"
#include "FeatureSource.h"

class ProfessionSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString quote READ quote CONSTANT)
    Q_PROPERTY(QQmlListProperty<FeatureSource> features READ features CONSTANT)
    QML_ELEMENT

public:
    explicit ProfessionSource(QObject *parent = nullptr);
    explicit ProfessionSource(const QString& name,
                              const QString& description,
                              const QString& quote,
                              const QVector<FeatureSource*>& features,
                              QObject* parent = nullptr);

    QString name() const;
    QString description() const;
    QString quote() const;

    QQmlListProperty<FeatureSource> features();
    qsizetype featuresCount() const;
    FeatureSource* feature(qsizetype index);

private:
    static qsizetype featuresCount(QQmlListProperty<FeatureSource> *list);
    static FeatureSource* feature(QQmlListProperty<FeatureSource> *list, qsizetype index);

private:
    QString m_name;
    QString m_description;
    QString m_quote;
    QVector<FeatureSource*> m_features;
};

#endif // PROFESSIONSOURCE_H
