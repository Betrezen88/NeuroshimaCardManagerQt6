#include "ItemsSortProxyModel.h"
#include "ItemSourceModel.h"

ItemsSortProxyModel::ItemsSortProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

ItemsSortProxyModel::ItemsSortProxyModel(QAbstractItemModel *sourceModel, QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSourceModel(sourceModel);
}

bool ItemsSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    const auto& leftName = qvariant_cast<ItemSource*>(sourceModel()->data(left, ItemSourceModel::SourceRole))->name();
    const auto& rightName = qvariant_cast<ItemSource*>(sourceModel()->data(right, ItemSourceModel::SourceRole))->name();

    return leftName < rightName;
}
