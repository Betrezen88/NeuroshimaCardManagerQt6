#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Common/Types.h"
#include "../../../Data/Statistics/RequirementData.h"

class Requirement : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool optional READ optional CONSTANT)
    Q_PROPERTY(Types::Requirement type READ type CONSTANT)

public:
    explicit Requirement(QObject *parent = nullptr);
    explicit Requirement(const RequirementData &data, QObject *parent = nullptr);

    QString name() const;
    int value() const;
    bool optional() const;
    Types::Requirement type() const;

    RequirementData data() const;

private:
    QString m_name;
    int m_value{0};
    bool m_optional{false};
    Types::Requirement m_type;
};

#endif // REQUIREMENT_H
