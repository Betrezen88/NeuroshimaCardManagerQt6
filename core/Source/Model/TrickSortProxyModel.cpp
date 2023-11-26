#include "TrickSortProxyModel.h"
#include "TrickSourceModel.h"

#include <QDebug>

TrickSortProxyModel::TrickSortProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}

TrickSortProxyModel::TrickSortProxyModel(QAbstractItemModel *sourceModel, QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSourceModel(sourceModel);
}

bool TrickSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    const auto& leftName = qvariant_cast<TrickSource*>(sourceModel()->data(left, TrickSourceModel::SourceRole))->name();
    const auto& rightName = qvariant_cast<TrickSource*>(sourceModel()->data(right, TrickSourceModel::SourceRole))->name();

    return leftName < rightName;
}
