#ifndef AVAILABLEFILTERPROXYMODEL_H
#define AVAILABLEFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QObject>

class AvailableFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit AvailableFilterProxyModel(QObject *parent = nullptr);
    explicit AvailableFilterProxyModel(QAbstractItemModel *sourceModel, QObject *parent = nullptr);

    bool filterByAvailability() const;
    void setFilterByAvailability(const bool newFilterByAvailability);

protected:
    bool filterAcceptsRow(int row, const QModelIndex& parent) const;

private:
    bool m_filterByAvailability{false};
};

#endif // AVAILABLEFILTERPROXYMODEL_H
