#ifndef PROFESSION_H
#define PROFESSION_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/ProfessionData.h"

class Feature;

class Profession : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(Feature* feature READ feature CONSTANT)

public:
    explicit Profession(QObject *parent = nullptr);
    explicit Profession(const ProfessionData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    Feature *feature() const;

    ProfessionData data() const;

private:
    QString m_name;
    QString m_description;
    Feature* m_feature;
};

#endif // PROFESSION_H
