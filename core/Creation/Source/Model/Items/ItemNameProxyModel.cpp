#include "ItemNameProxyModel.h"
#include "ItemSourceModel.h"

ItemNameProxyModel::ItemNameProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{}

bool ItemNameProxyModel::filterByName() const
{
    return m_filterByName;
}

void ItemNameProxyModel::setFilterByName(const bool &newFilterByName)
{
    if ( m_filterByName == newFilterByName )
        return;

    m_filterByName = newFilterByName;
}

bool ItemNameProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    if ( sourceModel() == nullptr )
        return false;

    if ( !m_filterByName )
        return true;

    const QModelIndex& index = sourceModel()->index(row, 0, parent);

    if ( !index.isValid() )
        return false;

    const QString& name = qvariant_cast<ItemSource*>(index.data(ItemSourceModel::SourceRole))->name();

    QRegularExpression reg( filterRegularExpression() );
    reg.setPatternOptions( QRegularExpression::CaseInsensitiveOption );

    return reg.match( name, 0 ).hasMatch();
}
