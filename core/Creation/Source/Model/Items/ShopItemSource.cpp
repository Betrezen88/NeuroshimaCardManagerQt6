#include "ShopItemSource.h"

ShopItemSource::ShopItemSource(QObject *parent)
    : QObject{parent}
{}

ShopItemSource::ShopItemSource(ItemSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
{

}

QString ShopItemSource::sourceName() const
{
    return m_sourceName;
}

ItemSource *ShopItemSource::source() const
{
    return m_source;
}

quint32 ShopItemSource::quantity() const
{
    return m_quantity;
}

void ShopItemSource::setQuantity(quint32 newQuantity)
{
    if (m_quantity == newQuantity)
        return;
    m_quantity = newQuantity;
    emit quantityChanged();
}
