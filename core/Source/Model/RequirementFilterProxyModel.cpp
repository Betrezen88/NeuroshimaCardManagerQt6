#include "RequirementFilterProxyModel.h"
#include "TrickSourceModel.h"

RequirementFilterProxyModel::RequirementFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}

RequirementFilterProxyModel::RequirementFilterProxyModel(QAbstractItemModel *sourceModel, QObject *parent)
    : QSortFilterProxyModel{parent}
{
    setSourceModel(sourceModel);
}

bool RequirementFilterProxyModel::filterByRequirement() const
{
    return m_filterByRequirement;
}

void RequirementFilterProxyModel::setFilterByRequirement(const bool newFilterByRequirement)
{
    if (m_filterByRequirement == newFilterByRequirement)
        return;
    m_filterByRequirement = newFilterByRequirement;
}

bool RequirementFilterProxyModel::filterAcceptsRow(int row, const QModelIndex &parent) const
{
    if (sourceModel() == nullptr)
        return false;

    if (!m_filterByRequirement)
        return true;

    const QModelIndex& index = sourceModel()->index(row, 0, parent);

    if (!index.isValid())
        return false;

    RequirementSourceModel *model = qvariant_cast<RequirementSourceModel*>(index.data(TrickSourceModel::RequirementsRole));
    QRegularExpression reg(filterRegularExpression());
    reg.setPatternOptions(QRegularExpression::CaseInsensitiveOption);

    for (int i{0}; i<model->rowCount(); ++i) {
        if (reg.match(model->data(model->index(i, 0), RequirementSourceModel::NameRole).toString(), 0).hasMatch())
            return true;
    }

    return false;
}
