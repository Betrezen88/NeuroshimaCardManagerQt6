#ifndef SHOPITEMSOURCE_H
#define SHOPITEMSOURCE_H

#include <QObject>
#include <QQmlEngine>

#include "../../Equipment/ItemSource.h"

class ShopItemSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceName READ sourceName CONSTANT)
    Q_PROPERTY(ItemSource* source READ source CONSTANT)
    Q_PROPERTY(quint32 quantity READ quantity WRITE setQuantity NOTIFY quantityChanged FINAL)
    QML_ELEMENT

public:
    explicit ShopItemSource(QObject *parent = nullptr);
    ShopItemSource(ItemSource* source, QObject *parent = nullptr);

    QString sourceName() const;
    ItemSource *source() const;
    quint32 quantity() const;
    void setQuantity(quint32 newQuantity);

signals:
    void quantityChanged();

private:
    QString m_sourceName;
    ItemSource *m_source{nullptr};
    quint32 m_quantity{0};
};

#endif // SHOPITEMSOURCE_H
