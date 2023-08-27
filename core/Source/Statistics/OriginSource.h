#ifndef ORIGINSOURCE_H
#define ORIGINSOURCE_H

#include <QObject>
#include <QQmlEngine>
#include <QQmlListProperty>

#include "AttributeBonusSource.h"
#include "FeatureSource.h"

class OriginSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QQmlListProperty<FeatureSource> features READ features CONSTANT)
    Q_PROPERTY(AttributeBonusSource* bonus READ bonus CONSTANT)
    QML_ELEMENT

public:
    explicit OriginSource(QObject *parent = nullptr);
    explicit OriginSource(const QString& name,
                          const QString& description,
                          AttributeBonusSource* bonus,
                          const QVector<FeatureSource *> &features,
                          QObject* parent = nullptr);

    QString name() const;
    QString description() const;
    QQmlListProperty<FeatureSource> features();

    FeatureSource* feature(qsizetype index);
    qsizetype featuresCount() const;

    AttributeBonusSource *bonus() const;

private:
    static FeatureSource* feature(QQmlListProperty<FeatureSource> *list, qsizetype index);
    static qsizetype featuresCount(QQmlListProperty<FeatureSource> *list);

private:
    QString m_name;
    QString m_description;
    AttributeBonusSource *m_bonus{nullptr};
    QVector<FeatureSource*> m_features;
};

#endif // ORIGINSOURCE_H
