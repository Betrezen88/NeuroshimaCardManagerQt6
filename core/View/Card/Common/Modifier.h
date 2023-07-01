#ifndef MODIFIER_H
#define MODIFIER_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../../../Data/Common/Types.h"
#include "../../../Data/Statistics/ModifierData.h"

class Modifier : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(Types::Modifier type READ type CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Modifier(QObject *parent = nullptr);
    explicit Modifier(const ModifierData &data, QObject *parent = nullptr);

    Types::Modifier type() const;
    QString name() const;
    int value() const;

    ModifierData data() const;

private:
    Types::Modifier m_type;
    QString m_name;
    int m_value;
};

#endif // MODIFIER_H
