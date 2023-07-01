#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Statistics/SpecializationData.h"

class Specialization : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Specialization(QObject *parent = nullptr);
    explicit Specialization(const SpecializationData &data, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

    SpecializationData data() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATION_H
