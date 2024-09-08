#include "BougthFilterProxyModel.h"
#include "TrickSourceModel.h"

BougthFilterProxyModel::BougthFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

BougthFilterProxyModel::BougthFilterProxyModel(QAbstractItemModel *sourceModel, QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSourceModel(sourceModel);
}

bool BougthFilterProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    if ( sourceModel() == nullptr )
        return false;

    const QModelIndex& index = sourceModel()->index(row, 0, parent);

    if ( !index.isValid() )
        return false;

    return !index.data(TrickSourceModel::Bougth).toBool();
}
