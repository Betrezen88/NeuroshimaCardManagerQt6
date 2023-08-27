#ifndef FEATURESOURCE_H
#define FEATURESOURCE_H

#include <QObject>
#include "qqmlintegration.h"
#include "BonusSource.h"

class FeatureSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(BonusSource* bonus READ bonus CONSTANT)
    QML_ELEMENT

public:
    explicit FeatureSource(QObject *parent = nullptr);
    explicit FeatureSource(const QString& name, const QString& description, const BonusSource* bonus, QObject* parent = nullptr);

    QString name() const;
    QString description() const;
    BonusSource *bonus() const;

signals:

private:
    QString m_name;
    QString m_description;
    BonusSource* m_bonus{nullptr};
};

#endif // FEATURESOURCE_H
