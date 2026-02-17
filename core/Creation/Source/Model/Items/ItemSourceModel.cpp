#include "ItemSourceModel.h"

ItemSourceModel::ItemSourceModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int ItemSourceModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_items.count();
}

QVariant ItemSourceModel::data(const QModelIndex &index, int role) const
{
    if ( index.row() < 0 || index.row() >= m_items.count() )
        return QVariant();

    ShopItemSource* item = m_items.at(index.row());

    if ( role == ItemSourceModel::SourceRole )
        return QVariant::fromValue( item->source() );
    if ( role == ItemSourceModel::QuantityRole )
        return item->quantity();

    return QVariant();
}

bool ItemSourceModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return true;
}

void ItemSourceModel::addItem(const QString &name, const QVector<ItemSource *> &items)
{
    for ( const auto item : items ) {
        m_items.append( new ShopItemSource(item, this) );
    }
}

QHash<int, QByteArray> ItemSourceModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ShopItemRoles::SourceRole] = "source";
    roles[ShopItemRoles::QuantityRole] = "quantity";
    return roles;
}
