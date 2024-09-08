#include "NameFilterProxyModel.h"
#include "TrickSourceModel.h"

NameFilterProxyModel::NameFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}

bool NameFilterProxyModel::filterByName() const
{
    return m_filterByName;
}

void NameFilterProxyModel::setFilterByName(const bool &newFilterByName)
{
    if (m_filterByName == newFilterByName)
        return;
    m_filterByName = newFilterByName;
}

bool NameFilterProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    if (sourceModel() == nullptr)
        return false;

    if (!m_filterByName)
        return true;

    const QModelIndex& index = sourceModel()->index(row, 0, parent);

    if (!index.isValid())
        return false;

    const QString& name = qvariant_cast<TrickSource*>(index.data(TrickSourceModel::SourceRole))->name();

    QRegularExpression reg(filterRegularExpression());
    reg.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    return reg.match(name, 0).hasMatch();
}
