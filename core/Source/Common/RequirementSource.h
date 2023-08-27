#ifndef REQUIREMENTSOURCE_H
#define REQUIREMENTSOURCE_H

#include <QObject>
#include <QQmlEngine>

#include "../../Data/Common/Types.h"

class RequirementSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Types::Requirement type READ type CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool optional READ optional CONSTANT)
    QML_ELEMENT

public:
    explicit RequirementSource(QObject *parent = nullptr);
    explicit RequirementSource(const Types::Requirement type,
                               const QString& name,
                               const int value,
                               const bool optional,
                               QObject* parent = nullptr);

    Types::Requirement type() const;
    QString name() const;
    int value() const;
    bool optional() const;

private:
    Types::Requirement m_type;
    QString m_name;
    int m_value;
    bool m_optional;
};

#endif // REQUIREMENTSOURCE_H
