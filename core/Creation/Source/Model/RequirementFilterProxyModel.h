#ifndef REQUIREMENTFILTERPROXYMODEL_H
#define REQUIREMENTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class RequirementFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit RequirementFilterProxyModel(QObject *parent = nullptr);
    explicit RequirementFilterProxyModel(QAbstractItemModel* sourceModel, QObject *parent = nullptr);

    bool filterByRequirement() const;
    void setFilterByRequirement(const bool newFilterByRequirement);

protected:
    bool filterAcceptsRow(int row, const QModelIndex& parent) const;

private:
    bool m_filterByRequirement{true};
};

#endif // REQUIREMENTFILTERPROXYMODEL_H
