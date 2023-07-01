#ifndef FEATURE_H
#define FEATURE_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/FeatureData.h"

class Feature : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Feature(QObject *parent = nullptr);
    explicit Feature(const FeatureData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

    FeatureData data() const;

private:
    QString m_name;
    QString m_description;
};

#endif // FEATURE_H
