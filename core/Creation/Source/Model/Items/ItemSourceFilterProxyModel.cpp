#include "ItemSourceFilterProxyModel.h"

ItemSourceFilterProxyModel::ItemSourceFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
    , m_nameFilter{new ItemNameProxyModel(this)}
    , m_sortModel{new ItemsSortProxyModel(m_nameFilter, this)}
{
    connect(this, &ItemSourceFilterProxyModel::sourceModelChanged, this, [this](){
        m_nameFilter->setSourceModel( sourceModel() );
    });
}

bool ItemSourceFilterProxyModel::ascendingOrder() const
{
    return m_ascendingOrder;
}

void ItemSourceFilterProxyModel::setAscendingOrder(bool newAscendingOrder)
{
    if (m_ascendingOrder == newAscendingOrder)
        return;
    m_ascendingOrder = newAscendingOrder;
    emit ascendingOrderChanged();
}

QString ItemSourceFilterProxyModel::pattern() const
{
    return m_pattern;
}

void ItemSourceFilterProxyModel::setPattern(const QString &newPattern)
{
    if (m_pattern == newPattern)
        return;
    m_pattern = newPattern;
    emit patternChanged();
}

ItemsSortProxyModel *ItemSourceFilterProxyModel::model() const
{
    return m_sortModel;
}
