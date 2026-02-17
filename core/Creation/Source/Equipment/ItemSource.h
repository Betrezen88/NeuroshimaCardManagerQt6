#ifndef ITEMSOURCE_H
#define ITEMSOURCE_H

#include <QObject>
#include <QQmlEngine>

#include "../../Data/Common/Types.h"

class ItemSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(quint32 price READ price CONSTANT)
    Q_PROPERTY(quint8 availability READ availability CONSTANT)
    Q_PROPERTY(QString category READ category CONSTANT)
    QML_ELEMENT
    QML_UNCREATABLE("ItemSource is uncreatable.")

public:
    explicit ItemSource(QObject *parent = nullptr) {}
    ItemSource(const QString& name,
               const QString& description,
               const quint32 price,
               const quint8 availability,
               const QString& category,
               QObject *parent = nullptr)
        : QObject{parent}
        , m_name{name}
        , m_description{description}
        , m_price{price}
        , m_availability{availability}
        , m_category(category)
    {

    }

    virtual ~ItemSource() {}

    virtual Types::Item type() const = 0;

    inline QString name() const {
        return m_name;
    }
    inline QString description() const {
        return m_description;
    }
    inline quint32 price() const {
        return m_price;
    }
    inline quint8 availability() const {
        return m_availability;
    }
    inline QString category() const
    {
        return m_category;
    }

private:
    QString m_name;
    QString m_description;
    quint32 m_price{0};
    quint8 m_availability{0};
    QString m_category;
};

#endif // ITEMSOURCE_H
