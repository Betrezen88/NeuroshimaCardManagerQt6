#include "ItemCreation.h"

ItemCreation::ItemCreation(QObject *parent)
    : QObject{parent}
{}

ItemCreation::ItemCreation(ItemSource *source, QObject *parent)
    : QObject{parent}
    , m_source{source}
    ,  m_quantity{1}
{

}

ItemSource *ItemCreation::source() const
{
    return m_source;
}

quint8 ItemCreation::quantity() const
{
    return m_quantity;
}

void ItemCreation::increase()
{
    ++m_quantity;
    emit quantityChanged();
}

void ItemCreation::decrease()
{
    --m_quantity;
    emit quantityChanged();
}
