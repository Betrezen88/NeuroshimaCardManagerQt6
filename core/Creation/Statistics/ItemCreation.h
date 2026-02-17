#ifndef ITEMCREATION_H
#define ITEMCREATION_H

#include <QObject>
#include <QQmlEngine>

#include <../Source/Equipment/ItemSource.h>

class ItemCreation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ItemSource* source READ source CONSTANT)
    Q_PROPERTY(quint8 quantity READ quantity NOTIFY quantityChanged FINAL)
    QML_ELEMENT
    QML_UNCREATABLE("ItemCreation is uncreatable.")
public:
    explicit ItemCreation(QObject *parent = nullptr);
    ItemCreation(ItemSource* source, QObject* parent = nullptr);

    ItemSource *source() const;

    quint8 quantity() const;
    void increase();
    void decrease();

signals:
    void quantityChanged();

private:
    ItemSource *m_source{nullptr};
    quint8 m_quantity{0};
};

#endif // ITEMCREATION_H
