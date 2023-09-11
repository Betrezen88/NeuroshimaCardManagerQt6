#ifndef ATTRIBUTEBONUSSOURCE_H
#define ATTRIBUTEBONUSSOURCE_H

#include <QObject>
#include "qqmlintegration.h"
#include "../../../core/Data/Common/Types.h"

class AttributeBonusSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value CONSTANT)
    QML_ELEMENT

public:
    explicit AttributeBonusSource(QObject* parent = nullptr) : QObject{parent} {}
    explicit AttributeBonusSource(const int value, QObject* parent = nullptr)
        : QObject{parent}
        , m_value(value)
    {}
    virtual ~AttributeBonusSource() {}

    virtual Types::AttributeBonus type() const = 0;
    virtual QString name() const = 0;

    inline int value() const {
        return m_value;
    }

private:
    int m_value{0};
};

#endif // ATTRIBUTEBONUSSOURCE_H
