#include "TrickSourceSortFilterProxyModel.h"

TrickSourceSortFilterProxyModel::TrickSourceSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
    , m_nameFilter{new NameFilterProxyModel(this)}
    , m_requirementFilter{new RequirementFilterProxyModel(m_nameFilter, this)}
    , m_availableFilter{new AvailableFilterProxyModel(m_requirementFilter, this)}
    , m_sortModel{new TrickSortProxyModel(m_availableFilter, this)}
{
    connect(this, &TrickSourceSortFilterProxyModel::sourceModelChanged, this, [this](){
        m_nameFilter->setSourceModel(sourceModel());
    });

    connect(this, &TrickSourceSortFilterProxyModel::ascendingOrderChanged, this, [this](){
        m_sortModel->sort(0, m_ascendingOrder ? Qt::AscendingOrder : Qt::DescendingOrder);
    });

    connect(this, &TrickSourceSortFilterProxyModel::patternChanged, this, [this](){
        m_nameFilter->setFilterFixedString(m_pattern);
        m_requirementFilter->setFilterFixedString(m_pattern);
    });

    connect(this, &TrickSourceSortFilterProxyModel::sortByChanged, this, [this](){
        m_nameFilter->setFilterByName(m_sortByModel.at(0) == m_sortBy);
        m_requirementFilter->setFilterByRequirement(m_sortByModel.at(1) == m_sortBy);
    });

    connect(this, &TrickSourceSortFilterProxyModel::availableOnlyChanged, [this](){
        m_availableFilter->setFilterByAvailability(m_availableOnly);
        m_availableFilter->invalidate();
    });

    setSortBy(m_sortByModel.at(0));
    setAscendingOrder(true);
    setAvailableOnly(false);
}

bool TrickSourceSortFilterProxyModel::ascendingOrder() const
{
    return m_ascendingOrder;
}

void TrickSourceSortFilterProxyModel::setAscendingOrder(bool newAscendingOrder)
{
    if (m_ascendingOrder == newAscendingOrder)
        return;
    m_ascendingOrder = newAscendingOrder;
    emit ascendingOrderChanged();
}

QString TrickSourceSortFilterProxyModel::pattern() const
{
    return m_pattern;
}

void TrickSourceSortFilterProxyModel::setPattern(const QString &newPattern)
{
    if (m_pattern == newPattern)
        return;
    m_pattern = newPattern;
    emit patternChanged();
}

QString TrickSourceSortFilterProxyModel::sortBy() const
{
    return m_sortBy;
}

void TrickSourceSortFilterProxyModel::setSortBy(const QString &newSortBy)
{
    if (m_sortBy == newSortBy)
        return;
    m_sortBy = newSortBy;
    emit sortByChanged();
}

QStringList TrickSourceSortFilterProxyModel::sortByModel() const
{
    return m_sortByModel;
}

TrickSortProxyModel *TrickSourceSortFilterProxyModel::model() const
{
    return m_sortModel;
}

bool TrickSourceSortFilterProxyModel::availableOnly() const
{
    return m_availableOnly;
}

void TrickSourceSortFilterProxyModel::setAvailableOnly(bool newAvailableOnly)
{
    if (m_availableOnly == newAvailableOnly)
        return;
    m_availableOnly = newAvailableOnly;
    emit availableOnlyChanged();
}
