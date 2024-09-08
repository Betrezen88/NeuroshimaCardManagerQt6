#include "AvailableFilterProxyModel.h"
#include "TrickSourceModel.h"

AvailableFilterProxyModel::AvailableFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}

AvailableFilterProxyModel::AvailableFilterProxyModel(QAbstractItemModel *sourceModel, QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSourceModel(sourceModel);
}

bool AvailableFilterProxyModel::filterByAvailability() const
{
    return m_filterByAvailability;
}

void AvailableFilterProxyModel::setFilterByAvailability(const bool newFilterByAvailability)
{
    if (m_filterByAvailability == newFilterByAvailability)
        return;
    m_filterByAvailability = newFilterByAvailability;
}

bool AvailableFilterProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    if (sourceModel() == nullptr)
        return false;

    if (!m_filterByAvailability)
        return true;

    const QModelIndex& index = sourceModel()->index(row, 0, parent);

    if (!index.isValid())
        return false;

    return index.data(TrickSourceModel::AvailableRole).toBool();
}
