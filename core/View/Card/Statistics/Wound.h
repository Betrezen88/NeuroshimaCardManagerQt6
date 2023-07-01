#ifndef WOUND_H
#define WOUND_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "../Common/Modifier.h"
#include "../../../Data/Statistics/WoundData.h"
#include "../../../Data/Common/Types.h"

class Wound : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(Modifier* penalty READ penalty CONSTANT)
    Q_PROPERTY(Types::Wound type READ type CONSTANT)

public:
    explicit Wound(QObject *parent = nullptr);
    explicit Wound(const WoundData &data, QObject *parent = nullptr);

    QString name() const;
    QString location() const;
    Modifier *penalty() const;
    Types::Wound type() const;

    WoundData data() const;

private:
    QString m_location;
    Modifier* m_penalty{nullptr};
    Types::Wound m_type;
};

#endif // WOUND_H
