#ifndef MODIFIERSOURCE_H
#define MODIFIERSOURCE_H

#include <QObject>
#include "qqmlintegration.h"

#include "../../Data/Common/Types.h"

class ModifierSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Types::Modifier type READ type CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit ModifierSource(QObject *parent = nullptr);
    explicit ModifierSource(const Types::Modifier type, const QString& name, const int value, QObject* parent = nullptr);

    Types::Modifier type() const;
    QString name() const;
    int value() const;

private:
    Types::Modifier m_type;
    QString m_name;
    int m_value{0};
};

#endif // MODIFIERSOURCE_H
