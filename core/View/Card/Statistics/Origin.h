#ifndef ORIGIN_H
#define ORIGIN_H

#include <QObject>
#include <QPointer>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/OriginData.h"

class Feature;

class Origin : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(Feature* feature READ feature CONSTANT)

public:
    explicit Origin(QObject *parent = nullptr);
    explicit Origin(const OriginData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    Feature *feature() const;

    OriginData data() const;

private:
    QString m_name;
    QString m_description;
    QPointer<Feature> m_feature;
};

#endif // ORIGIN_H
